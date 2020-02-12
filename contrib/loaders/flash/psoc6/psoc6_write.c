#include "device.h"
#include "flashboot.h"

/** *************************************************************************************
 * @brief Represents Circular Buffer structure passed to this loader by the OpenOCD
 ***************************************************************************************/
struct circular_buffer {
	uint32_t wp;
	uint32_t rp;
	uint8_t data[];
};

/** *************************************************************************************
 * @brief Equivalent for the CLZ assembly instruction for Cortex-M0 (no Thumb2 support)
 * @param data Value to count leading zeros
 * @return number of leading zeros in 'data'
 ***************************************************************************************/
__inline __attribute__((always_inline))
static uint32_t soft_clz(uint32_t data)
{
	uint32_t count = 0u;
	uint32_t mask = 0x80000000u;

	while((data & mask) == 0) {
		count += 1u;
		mask = mask >> 1u;
	}

	return count;
}

/** *************************************************************************************
 * @brief Invoke SROM API Function
 * @param req_buf Address of the buffer with SROM API Request and parameters
 ***************************************************************************************/
__inline __attribute__((always_inline))
static void call_sromapi(uint32_t req_buf)
{
	int ipc_id = get_ipc_id();

	/* Acquire the IPC structure */
	for (;;) {
		uint32_t val = read_io(REG_IPC_ACQUIRE(ipc_id));
		bool is_acquired = (val & IPC_ACQUIRE_SUCCESS_MSK) != 0;
		if (is_acquired)
			break;
	}

	/* Invoke SROM API by posting an NMI via IPC */
	write_io(REG_IPC_DATA(ipc_id), req_buf);
	write_io(REG_IPC_INTR_MASK(IPC_INTR_ID), 1u << (16 + ipc_id));
	write_io(REG_IPC_NOTIFY(ipc_id), 1);

	/* Poll the IPC structure for release */
	for (;;) {
		uint32_t lock_stat = read_io(REG_IPC_LOCK_STATUS(ipc_id));
		bool is_locked = (lock_stat & IPC_LOCK_ACQUIRED_MSK) != 0;
		if (!is_locked)
			break;
	}
}

/** *************************************************************************************
 * @brief Performs programming of a single Flash Row
 * @param src Address of the RAM buffer to be programmed
 * @param dst Target Flash address
 ***************************************************************************************/
__inline __attribute__((always_inline))
static uint32_t program_row(uint32_t src, uint32_t dst, uint32_t write_param)
{
	uint32_t req[4];
#if (MXS40_VARIANT == MXS40_VARIANT_TRAVEO_II)
	if ((dst & 0xFF000000) == 0x14000000 && write_param != 0x102) {
		/* Use bulk request only for Work Flash and only if program page
		 * size is larger than 32 bits (write_param != 0x102) */
		req[0] = SROMAPI_PROGRAMWORK_BULK_REQ;
	} else {
		/* Use regular request for Main Flash and for 32-bit writes to Work Flash */
		req[0] = SROMAPI_PROGRAMROW_REQ;
	}
#else
	/* Always use regular request for PSoC6 targets */
	req[0] = SROMAPI_PROGRAMROW_REQ;
#endif
	req[1] = write_param;
	req[2] = dst;
	req[3] = src;

	call_sromapi((uint32_t)&req[0]);

	return req[0];
}


/** *************************************************************************************
 * @brief Returns largest possible programming page size
 ***************************************************************************************/
__inline __attribute__((always_inline))
static uint32_t get_page_size(uint32_t address)
{
#if (MXS40_VARIANT == MXS40_VARIANT_TRAVEO_II)
	if ((address & 0xFF000000) == 0x14000000) {
		uint32_t fb_ver_major = read_io(FLASHBOOT_VER_HI_ADDR) >> 28u;
		if(fb_ver_major < 2)
			return 4;

		uint32_t fb_build = read_io(FLASHBOOT_VER_LO_ADDR) & 0xFFFFu;
		return (fb_build < FLASHBOOT_BUILD_BULK_SUPPORTED) ? 4 : 512;
	}
#endif
	(void)address;
	return 512;
}

__attribute__((flatten, noreturn))
void write(volatile struct circular_buffer *work_area, uint32_t fifo_end,
	uint32_t target_address, uint32_t count)
{
	__asm volatile ("cpsie i" : : : "memory");
	const uint32_t page_size = get_page_size(target_address);
	const uint32_t write_param = 0x100 | (31 - soft_clz(page_size));

	while (count) {
		/* Wait for some data in the FIFO */
		while (work_area->rp == work_area->wp);

		uint32_t result = program_row(work_area->rp, target_address, write_param);
		if ((result & SROMAPI_STATUS_MSK) != SROMAPI_STAT_SUCCESS) {
			work_area->rp = 0;
			__asm volatile ("mov r0, %[value]\n\t"
			"bkpt 0"  :  : [value] "r" (result) : );
		}

		target_address += page_size;

		uint32_t read_ptr = work_area->rp;
		read_ptr += page_size;
		if (read_ptr >= fifo_end)
			read_ptr = ((uint32_t)&work_area->data);

		work_area->rp = read_ptr;

		count--;
	}

	for (;;)
		__asm("bkpt 0");
}
