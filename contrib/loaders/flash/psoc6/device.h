#include <stdint.h>
#include <stdbool.h>

#define MXS40_VARIANT_PSOC6A_BLE        1
#define MXS40_VARIANT_PSOC6A_2M         2
#define MXS40_VARIANT_TRAVEO_II         3

#ifndef MXS40_VARIANT
  #error "MXS40_VARIANT not defined"
#endif

#if (MXS40_VARIANT == MXS40_VARIANT_PSOC6A_BLE)
  #define MEM_BASE_IPC                    0x40230000u
  #define MEM_BASE_IPC_INTR               0x40231000u
  #define IPC_LOCK_STATUS_OFFSET          0x10u
  #define MXS40_CPUSS_IDENTITY            0x40210400
#elif (MXS40_VARIANT == MXS40_VARIANT_PSOC6A_2M || MXS40_VARIANT == MXS40_VARIANT_TRAVEO_II)
  #define MEM_BASE_IPC                    0x40220000u
  #define MEM_BASE_IPC_INTR               0x40221000u
  #define IPC_LOCK_STATUS_OFFSET          0x1Cu
  #define MXS40_CPUSS_IDENTITY            0x40200000
#else
  #error "MXS40_VARIANT unknown"
#endif

#define MXS40_CPUSS_IDENTITY_MS_MSK       0x00000F00
#define MXS40_CPUSS_IDENTITY_MS_M0        0x000
#define IPC_INTR_ID                       0

#define IPC_STRUCT_SIZE                 0x20u
#define IPC_INTR_STRUCT_SIZE            0x20u

#define MEM_IPC(n)                      (MEM_BASE_IPC + (n) * IPC_STRUCT_SIZE)
#define MEM_IPC_INTR(n)                 (MEM_BASE_IPC_INTR + (n) * IPC_INTR_STRUCT_SIZE)

#define REG_IPC_ACQUIRE(n)              (MEM_IPC(n) + 0x00u)
#define REG_IPC_NOTIFY(n)               (MEM_IPC(n) + 0x08u)
#define REG_IPC_DATA(n)                 (MEM_IPC(n) + 0x0Cu)
#define REG_IPC_LOCK_STATUS(n)          (MEM_IPC(n) + IPC_LOCK_STATUS_OFFSET)
#define REG_IPC_INTR_MASK(n)            (MEM_IPC_INTR(n) + 0x08u)

#define IPC_ACQUIRE_SUCCESS_MSK         0x80000000u
#define IPC_LOCK_ACQUIRED_MSK           0x80000000u

#define SROMAPI_PROGRAMROW_REQ          0x06000100u
#define SROMAPI_PROGRAMWORK_BULK_REQ    0x30000100u

#define SROMAPI_STATUS_MSK              0xF0000000u
#define SROMAPI_STAT_SUCCESS            0xA0000000u

#define read_io(addr)                  (*((volatile uint32_t *)(addr)))
#define write_io(addr, value)          (*((volatile uint32_t *)(addr)) = (uint32_t)(value))

__inline __attribute__((always_inline))
static int get_ipc_id(void)
{
	int is_cm0;
	uint32_t id = read_io(MXS40_CPUSS_IDENTITY);
	is_cm0 = (id & MXS40_CPUSS_IDENTITY_MS_MSK) == MXS40_CPUSS_IDENTITY_MS_M0;
	return is_cm0 ? 0 : 1;
}
