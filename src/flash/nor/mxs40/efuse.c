/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2019 by Bohdan Tymkiv, Mykola Tuzyak                    *
 *   bohdan.tymkiv@cypress.com bohdan200@gmail.com                         *
 *   mykola.tyzyak@cypress.com                                             *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 ***************************************************************************/

#include "flash/nor/mxs40/mxs40.h"
#include "target/image.h"
#include "flash/nor/imp.h"

#define MXS40_EFUSE_IGNORE                           0xFF
#define MXS40_EFUSE_NOT_BLOWN                        0x00
#define MXS40_EFUSE_BLOWN                            0x01

#define MXS40_EFUSE_HASH_SIZE                        16u
#define MXS40_EFUSE_HASH_RESPONSE_SIZE               24u
#define MXS40_EFUSE_HASH_ZEROS_OFSET                 0x14u
#define MXS40_EFUSE_HASH_OFFSET                      0x14
#define MXS40_EFUSE_HASH_ZEROS_OFFSET                0x26
#define MXS40_EFUSE_FACTORY_HASH_OFFSET              0x2Cu
#define MXS40_EFUSE_FACTORY_HASH_SIZE                0x10u

#define P6_EFUSE_LIFE_CYCLE_NORMAL_BIT            0
#define P6_EFUSE_LIFE_CYCLE_SECURE_DEBUG_BIT      1
#define P6_EFUSE_LIFE_CYCLE_SECURE_BIT            2
#define P6_EFUSE_LIFE_CYCLE_RMA_BIT               3
#define P6_EFUSE_LIFE_CYCLE_NORMAL                      (1 << P6_EFUSE_LIFE_CYCLE_NORMAL_BIT)
#define P6_EFUSE_LIFE_CYCLE_SECURE_DEBUG                (1 << P6_EFUSE_LIFE_CYCLE_SECURE_DEBUG_BIT)
#define P6_EFUSE_LIFE_CYCLE_SECURE                      (1 << P6_EFUSE_LIFE_CYCLE_SECURE_BIT)
#define P6_EFUSE_LIFE_CYCLE_RMA                         (1 << P6_EFUSE_LIFE_CYCLE_RMA_BIT)

#define TVII_EFUSE_KEY_START_BIT                      0
#define TVII_EFUSE_KEY_SIZE_BITS                      6

#define TVII_EFUSE_LIFE_CYCLE_MASK                 0x0000FFFF
#define TVII_EFUSE_MAGIC_KEY_MASK                  0x29
#define TVII_EFUSE_LIFE_CYCLE_PROV_OFFSET          6
#define TVII_EFUSE_LIFE_CYCLE_SECURE_OFFSET        8
#define TVII_EFUSE_LIFE_CYCLE_SECURE_DEBUG_OFFSET  10
#define TVII_EFUSE_LIFE_CYCLE_RMA_OFFSET           12
#define TVII_EFUSE_LIFE_CYCLE_NORMAL_OFFSET        14
#define TVII_EFUSE_LIFE_CYCLE_PROV                  (3 << TVII_EFUSE_LIFE_CYCLE_PROV_OFFSET)
#define TVII_EFUSE_LIFE_CYCLE_NORMAL                (3 << TVII_EFUSE_LIFE_CYCLE_NORMAL_OFFSET)
#define TVII_EFUSE_LIFE_CYCLE_SECURE_DEBUG          (3 << TVII_EFUSE_LIFE_CYCLE_SECURE_DEBUG_OFFSET)
#define TVII_EFUSE_LIFE_CYCLE_SECURE                (3 << TVII_EFUSE_LIFE_CYCLE_SECURE_OFFSET)
#define TVII_EFUSE_LIFE_CYCLE_RMA                   (3 << TVII_EFUSE_LIFE_CYCLE_RMA_OFFSET)

#define MXS40_LIFE_CYCLE_VIRGIN               0
#define MXS40_LIFE_CYCLE_NORMAL               1
#define MXS40_LIFE_CYCLE_SECURE_DEBUG         2
#define MXS40_LIFE_CYCLE_SECURE               3
#define MXS40_LIFE_CYCLE_RMA                  4
#define MXS40_LIFE_CYCLE_SORT                 5
#define MXS40_LIFE_CYCLE_PROV                 6
#define MXS40_LIFE_CYCLE_NORMAL_PROV          7
#define MXS40_LIFE_CYCLE_NORMAL_RMA           8
#define MXS40_LIFE_CYCLE_CORRUPTED            9

static const char *MXS40_LIFE_CYCLE_STR[] = {
	"Virgin",
	"Normal",
	"Secure with Debug",
	"Secure",
	"RMA",
	"Sort",
	"Provisioned",
	"Normal Provisioned",
	"Normal RMA",
	"Corrupted",
};

#define P6_EFUSE_DEAD_ACCESS_RESTR_OFFSET         0x27
#define P6_EFUSE_DEAD_ACCESS_RESTR_SIZE           0x02
#define P6_EFUSE_SECURE_ACCESS_RESTR_OFFSET       0x29
#define P6_EFUSE_SECURE_ACCESS_RESTR_SIZE         0x02
#define P6_EFUSE_LIFECYCLE_OFFSET                 0x2B
#define P6_EFUSE_LIFECYCLE_SIZE                   0x01

#define TVII_EFUSE_DEAD_ACCESS_RESTR_OFFSET         0x40
#define TVII_EFUSE_DEAD_ACCESS_RESTR_SIZE           0x03
#define TVII_EFUSE_SECURE_ACCESS_RESTR_OFFSET       0x3C
#define TVII_EFUSE_SECURE_ACCESS_RESTR_SIZE         0x03
#define TVII_EFUSE_LIFECYCLE_OFFSET                 0x00
#define TVII_EFUSE_LIFECYCLE_SIZE                   0x02


#define SROMAPI_BLOW_FUSE_MACROPERADDR               32
#define SROMAPI_BLOW_FUSE_CODE_ROL                   24
#define SROMAPI_BLOW_FUSE_CODE                       1
#define SROMAPI_BLOW_FUSE_ADDR_ROL                   16
#define SROMAPI_BLOW_FUSE_ADDR_MASK                  0x00FF0000
#define SROMAPI_BLOW_FUSE_MACRO_ROL                  12
#define SROMAPI_BLOW_FUSE_MACRO_MASK                 0x0000F000
#define SROMAPI_BLOW_FUSE_BIT_ROL                    8
#define SROMAPI_BLOW_FUSE_BIT_MASK                   0x00000700

#define SROMAPI_TRANSITION_TO_SECURE                 0x2F000000
#define SROMAPI_TRANSITION_TO_SECURE_SIZE            12

#define EFUSE_REGIONS_P6_BLE2  0
#define EFUSE_REGIONS_P6A_2M    1
#define EFUSE_REGIONS_TVII     2

static struct efuse_regions EFUSE_REGIONS_LIST[] = {
	/* EFUSE_SKIP_P6_BLE2 */
	{
		.lifecycle_offset       = P6_EFUSE_LIFECYCLE_OFFSET,
		.lifecycle_size         = P6_EFUSE_LIFECYCLE_SIZE,
		.dead_access_offset     = 0,	/* Do not skip */
		.dead_access_size       = 0,	/* Do not skip */
		.secure_access_offset   = 0,	/* Do not skip */
		.secure_access_size     = 0	/* Do not skip */
	},
	/* EFUSE_SKIP_P6A_2M */
	{
		.lifecycle_offset       = P6_EFUSE_LIFECYCLE_OFFSET,
		.lifecycle_size         = P6_EFUSE_LIFECYCLE_SIZE,
		.dead_access_offset     = P6_EFUSE_DEAD_ACCESS_RESTR_OFFSET,
		.dead_access_size       = P6_EFUSE_DEAD_ACCESS_RESTR_SIZE,
		.secure_access_offset   = P6_EFUSE_SECURE_ACCESS_RESTR_OFFSET,
		.secure_access_size     = P6_EFUSE_SECURE_ACCESS_RESTR_SIZE
	},
	/* EFUSE_SKIP_TVII */
	{
		.lifecycle_offset       = TVII_EFUSE_LIFECYCLE_OFFSET,
		.lifecycle_size         = TVII_EFUSE_LIFECYCLE_SIZE,
		.dead_access_offset     = TVII_EFUSE_DEAD_ACCESS_RESTR_OFFSET,
		.dead_access_size       = TVII_EFUSE_DEAD_ACCESS_RESTR_SIZE,
		.secure_access_offset   = TVII_EFUSE_SECURE_ACCESS_RESTR_OFFSET,
		.secure_access_size     = TVII_EFUSE_SECURE_ACCESS_RESTR_SIZE
	},
};


static const char EFUSE_P6_VOLTAGES[] = "2.5 Volts +/-5 %";
static const char EFUSE_TVII_VOLTAGES[] = "3.0 - 5.5 Volts";
static const char EFUSE_MSG1[] =
	"is required to blow efuse bits. Check the supplied voltage is within";
static const char EFUSE_MSG2[] =
	"the required range and pay attend to the precision of power supply and power meter";

static bool g_allow_efuse_programming;


COMMAND_HANDLER(handle_allow_efuse_program)
{
	if (CMD_ARGC != 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	COMMAND_PARSE_ON_OFF(CMD_ARGV[0], g_allow_efuse_programming);

	if (g_allow_efuse_programming)
		LOG_WARNING("Programming of efuses now ALLOWED");

	return ERROR_OK;
}


/** ***********************************************************************************************
 * @brief Displays information why lifecycle transition is not allowed
 * @param chip_lc current chip lifecycle returned by SROM API
 * @param file_lc lifecycle read from programming file
 *************************************************************************************************/
static void efuse_transition_forbidden(uint8_t chip_lc, uint8_t file_lc)
{
	const size_t max_num_life_cycle = sizeof(MXS40_LIFE_CYCLE_STR)/ sizeof(char *);

	if (chip_lc >= max_num_life_cycle) {
		LOG_ERROR("The target is in unknown Life Cycle stage");
		return;
	}

	if (file_lc >= max_num_life_cycle) {
		LOG_ERROR("The programming file contains an invalid Life Cycle stage");
		return;
	}

	const char *file_lc_str = MXS40_LIFE_CYCLE_STR[file_lc];
	const char *chip_lc_str = MXS40_LIFE_CYCLE_STR[chip_lc];

	if (strcmp(chip_lc_str, file_lc_str) == 0)
		LOG_WARNING("The target is already in the '%s' Life Cycle stage", chip_lc_str);
	else
		LOG_ERROR("Transaction to '%s' Life Cycle from '%s' Life Cycle is not allowed",
			file_lc_str, chip_lc_str);
}

/** ***********************************************************************************************
 * @brief Checks if Efuse byte with specific offset is present in programming file
 * @param buffer contains whole efuse region
 * @param offset address of efuse byte to be checked
 * @return true if requesed efuse byte is present
 *************************************************************************************************/
static uint8_t efuse_is_byte_in_file(const uint8_t *buffer, uint16_t offset)
{
	const size_t pos_start = offset * 8;
	const size_t pos_end = pos_start + 8;

	for (size_t i = pos_start; i < pos_end; i++)
		if (buffer[i] != MXS40_EFUSE_IGNORE)
			return true;

	return false;
}

/** ***********************************************************************************************
 * @brief returns efuse byte with specific offset from programming file
 * @param buffer contains whole efuse region
 * @param offset address of efuse byte to be checked
 * @return efuse byte with specific offset from programming file
 *************************************************************************************************/
static uint8_t efuse_get_byte_from_file(const uint8_t *buffer, uint16_t offset)
{
	size_t pos_start = (size_t)(offset * 8);
	size_t pos_end = (size_t)(offset * 8 + 8);

	uint8_t bitPos = 0;
	uint8_t read_efuse_byte = 0;
	for (size_t i = pos_start; i < pos_end; i++) {
		if (buffer[i] == MXS40_EFUSE_BLOWN)
			read_efuse_byte |= 1 << bitPos;

		bitPos++;
	}
	return read_efuse_byte;
}

/** ***********************************************************************************************
 * @brief Returns array of efuse bits from programming file
 * @param file whole efuse region
 * @param offset offset of first interested bit
 * @param dest_buff return buffer with efuse bits
 * @param dest_buff_size size of return buffer
 *************************************************************************************************/
static void efuse_get_array_from_file(const uint8_t *file,
	size_t offset,
	uint8_t *dest_buff,
	const size_t dest_buff_size)
{
	size_t i = 0;
	size_t file_offset = offset * 8;
	size_t byte_offset = 0;
	size_t bit_offset = 0;

	for (i = 0; i < dest_buff_size * 8; i++) {
		uint8_t efuse_value = file[file_offset + i];
		if (efuse_value == 1) {
			byte_offset = i / 8;
			bit_offset = i % 8;
			dest_buff[byte_offset] |= 1 << bit_offset;
		}
	}
}

/** ***********************************************************************************************
 * @brief returns lifycycle included into programming file
 * @param buffer contains whole efuse region
 * @return lifycycle from programming file
 *************************************************************************************************/
static uint8_t efuse_p6_get_life_cycle_from_file(const uint8_t *buffer)
{
	uint8_t ret_life_cycle = 0;

	/* Get lifecycle efuse if present */
	if (efuse_is_byte_in_file(buffer, P6_EFUSE_LIFECYCLE_OFFSET)) {
		/* Read LifeCycle from programming file */
		uint8_t life_cycle_byte = efuse_get_byte_from_file(buffer,
				P6_EFUSE_LIFECYCLE_OFFSET);

		/* if RMA bit is set all other bits are ignored */
		if (life_cycle_byte & P6_EFUSE_LIFE_CYCLE_RMA)
			ret_life_cycle = MXS40_LIFE_CYCLE_RMA;
		/* if SECURE bit is set all other bits are ignored */
		else if (life_cycle_byte & P6_EFUSE_LIFE_CYCLE_SECURE)
			ret_life_cycle = MXS40_LIFE_CYCLE_SECURE;
		/* if SECURE_WITH_DEBUG bit is set all other bits are ignored */
		else if (life_cycle_byte & P6_EFUSE_LIFE_CYCLE_SECURE_DEBUG)
			ret_life_cycle = MXS40_LIFE_CYCLE_SECURE_DEBUG;
		/* if NORMAL bit is set all other bits are ignored */
		else if (life_cycle_byte & P6_EFUSE_LIFE_CYCLE_NORMAL)
			ret_life_cycle = MXS40_LIFE_CYCLE_NORMAL;

	}
	return ret_life_cycle;
}

/** ***********************************************************************************************
 * @brief returns lifycycle included into programming file
 * @param buffer contains whole efuse region
 * @return lifycycle from programming file
 *************************************************************************************************/
static uint8_t efuse_tv2_get_life_cycle_from_file(const uint8_t *buffer)
{
	uint8_t ret_life_cycle = 0;

	uint32_t life_cycle = 0;
	/* Read LifeCycle from programming file */
	efuse_get_array_from_file(buffer, 0, (uint8_t *)&life_cycle, sizeof(life_cycle));

	/* Analyze lifecycle from file */
	if (life_cycle & TVII_EFUSE_LIFE_CYCLE_MASK) {
		/* if RMA bit is set all other bits are ignored */
		if ((life_cycle & TVII_EFUSE_LIFE_CYCLE_RMA) == TVII_EFUSE_LIFE_CYCLE_RMA)
			ret_life_cycle = MXS40_LIFE_CYCLE_RMA;
		/* if SECURE bit is set all other bits are ignored */
		else if ((life_cycle & TVII_EFUSE_LIFE_CYCLE_SECURE) ==
			TVII_EFUSE_LIFE_CYCLE_SECURE)
			ret_life_cycle = MXS40_LIFE_CYCLE_SECURE;
		/* if SECURE_WITH_DEBUG bit is set all other bits are ignored */
		else if ((life_cycle & TVII_EFUSE_LIFE_CYCLE_SECURE_DEBUG) ==
			TVII_EFUSE_LIFE_CYCLE_SECURE_DEBUG)
			ret_life_cycle = MXS40_LIFE_CYCLE_SECURE_DEBUG;

		/* lifecycle wasn't detected */
		if (!ret_life_cycle) {
			bool is_normal = false;
			bool is_prov = false;

			if ((life_cycle & TVII_EFUSE_LIFE_CYCLE_NORMAL) ==
				TVII_EFUSE_LIFE_CYCLE_NORMAL)
				is_normal = true;

			if ((life_cycle & TVII_EFUSE_LIFE_CYCLE_PROV) == TVII_EFUSE_LIFE_CYCLE_PROV)
				is_prov = true;

			if (is_normal && is_prov)
				ret_life_cycle = MXS40_LIFE_CYCLE_NORMAL_PROV;
			else if (is_normal)
				ret_life_cycle = MXS40_LIFE_CYCLE_NORMAL;
			else if (is_prov)
				ret_life_cycle = MXS40_LIFE_CYCLE_PROV;
			else if ((life_cycle & TVII_EFUSE_MAGIC_KEY_MASK) ==
				TVII_EFUSE_MAGIC_KEY_MASK)
				ret_life_cycle = MXS40_LIFE_CYCLE_SORT;
		}
	}
	return ret_life_cycle;
}

/** ***********************************************************************************************
 * @brief returns lifycycle included into programming file
 * @param bank current flash bank
 * @param buffer contains whole efuse region
 * @return lifycycle from programming file
 *************************************************************************************************/
static uint8_t efuse_get_life_cycle_from_file(struct flash_bank *bank, const uint8_t *buffer)
{
	uint8_t ret_life_cycle = 0;
	struct mxs40_bank_info *info = bank->driver_priv;
	uint32_t variant = info->regs->variant;
	switch (variant) {
		case MXS40_VARIANT_PSOC6_BLE2:
		case MXS40_VARIANT_PSOC6A_2M:
			ret_life_cycle = efuse_p6_get_life_cycle_from_file(buffer);
			break;
		case MXS40_VARIANT_TRAVEO_II:
		case MXS40_VARIANT_TRAVEO_II_8M:
			ret_life_cycle = efuse_tv2_get_life_cycle_from_file(buffer);
			break;
		default:
			LOG_ERROR("Get life cycle from file. Unkown MXS40 variant. ");
	}
	return ret_life_cycle;
}


/** ***********************************************************************************************
 * @brief Checks the Factory HASH of the FLASH boot programmed in SFLASH
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_check_factory_hash(struct flash_bank *bank)
{
	struct target *target = bank->target;
	struct working_area *wa;

	int hr = target_alloc_working_area(target, sizeof(uint32_t), &wa);
	if (hr != ERROR_OK)
		goto exit;

	uint32_t sromapi_req = SROMAPI_CHECK_FACTORY_HASH;

	hr = target_write_u32(target, wa->address, sromapi_req);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	uint32_t data_out;
	hr = mxs40_call_sromapi(bank, sromapi_req, wa->address, &data_out);

exit_free_wa:
	target_free_working_area(target, wa);

exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Generates hash and hash zero
 * @param bank current flash bank
 * @param hash_arr address of array for generated hash value
 * @param hash_arr_size size of hash_arr
 * @param hash_zeros generated hash zero value
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_p6_generate_hash(struct flash_bank *bank, uint8_t *hash_arr, size_t hash_arr_size,
	uint8_t *hash_zeros)
{
	/* todo : correct response code, e.g. invalid argument */
	if (hash_arr_size <  MXS40_EFUSE_HASH_SIZE)
		return ERROR_FLASH_OPERATION_FAILED;

	struct target *target = bank->target;

	struct working_area *wa;

	int hr = target_alloc_working_area(target,
			sizeof(uint32_t) * MXS40_EFUSE_HASH_RESPONSE_SIZE,
			&wa);
	if (hr != ERROR_OK)
		goto exit;

	uint32_t sromapi_req = SROMAPI_GENERATE_HASH_CODE;

	hr = target_write_u32(target, wa->address, sromapi_req);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	uint32_t data_out;
	hr = mxs40_call_sromapi(bank, sromapi_req, wa->address, &data_out);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	for (size_t i = 0; i < MXS40_EFUSE_HASH_SIZE / sizeof(uint32_t); i++) {
		hr = target_read_u32(target, wa->address + 4 * (i + 1), &data_out);
		if (hr != ERROR_OK)
			goto exit_free_wa;

		hash_arr[4 * i + 0] = (data_out >> 0) & 0xFF;
		hash_arr[4 * i + 1] = (data_out >> 8) & 0xFF;
		hash_arr[4 * i + 2] = (data_out >> 16) & 0xFF;
		hash_arr[4 * i + 3] = (data_out >> 24) & 0xFF;
	}

	hr = target_read_u32(target,
			wa->address + MXS40_EFUSE_HASH_ZEROS_OFSET,
			&data_out);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	*hash_zeros = data_out;

exit_free_wa:
	target_free_working_area(target, wa);

exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Reads single Efuse byte
 *
 * @param bank The bank to read
 * @param addr The address of efuse byte to read
 * @param efuse_byte_value The read value of efuse byte
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_read_byte(struct flash_bank *bank, uint16_t addr, uint8_t *efuse_byte_value)
{
	uint32_t data_out = 0;

	int hr = mxs40_call_sromapi(bank, SROMAPI_READ_FUSE_BYTE + (addr << 8), 0, &data_out);
	if (hr != ERROR_OK)
		return hr;

	*efuse_byte_value = (uint8_t)data_out;

	return hr;
}

/** ***********************************************************************************************
 * @brief Returns specific bit of efuse byte
 * @param bank current flash bank
 * @param addr address of efuse byte
 * @param bit_addr bit address of efuse bit inside of the efuse byte
 * @param bit_value returns 1 if read efuse bit with specific address is not empty
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_get_bit(struct flash_bank *bank, uint8_t addr, uint8_t bit_addr,
	uint8_t *bit_value)
{

	uint8_t readByte = 0;
	int hr = efuse_read_byte(bank, addr, &readByte);
	if (hr == ERROR_OK)
		*bit_value = (readByte & (1 << bit_addr)) != 0;
	return hr;
}

/** ***********************************************************************************************
 * @brief Blows the addressed eFuse bit and checks if efuse was blown correctly
 * @param bank current flash bank
 * @param addr address of efuse byte
 * @param bit_addr bit address of efuse bit inside of the efuse byte
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_blow_bit(struct flash_bank *bank, uint8_t addr, uint8_t bit_addr)
{
	struct mxs40_bank_info *info = bank->driver_priv;
	uint32_t variant = info->regs->variant;

	uint8_t bitValue = 0;
	int hr = efuse_get_bit(bank, addr, bit_addr, &bitValue);
	if (hr != ERROR_OK)
		return hr;

	if (bitValue == 1) {
		LOG_WARNING("The efuse bit at address 0x%X[%X] has already been blown",
			addr, bit_addr);
		return ERROR_OK;
	}

	uint8_t macro_addr = 0;
	uint8_t byte_addr = 0;


   bool is_tv2 = variant == MXS40_VARIANT_TRAVEO_II || variant == MXS40_VARIANT_TRAVEO_II_8M;

   if (is_tv2){
	   byte_addr = addr / 4;
	   macro_addr = addr % 4;
   }

   else {// PSoC6
	   byte_addr = addr;
	   while (byte_addr >= SROMAPI_BLOW_FUSE_MACROPERADDR) {
		   byte_addr -= SROMAPI_BLOW_FUSE_MACROPERADDR;
		   macro_addr++;
	   }
   }

	uint32_t params = (SROMAPI_BLOW_FUSE_CODE << SROMAPI_BLOW_FUSE_CODE_ROL) +
		(SROMAPI_BLOW_FUSE_ADDR_MASK & (byte_addr << SROMAPI_BLOW_FUSE_ADDR_ROL)) +
		(SROMAPI_BLOW_FUSE_MACRO_MASK & (macro_addr << SROMAPI_BLOW_FUSE_MACRO_ROL)) +
		(SROMAPI_BLOW_FUSE_BIT_MASK & (bit_addr << SROMAPI_BLOW_FUSE_BIT_ROL)) + 1;

	uint32_t data = 0;
	hr = mxs40_call_sromapi(bank, params, 0, &data);

	if (hr != ERROR_OK) {
		LOG_ERROR("Error of BlowFuseBit Addr = %X[%X]", addr, bit_addr);
		return hr;
	}

	hr = efuse_get_bit(bank, addr, bit_addr, &bitValue);
	if (hr != ERROR_OK)
		return hr;

	if (bitValue == 0) {

		const char *EFUSE_MSG = "";

		switch (variant) {
			case MXS40_VARIANT_PSOC6_BLE2:
			case MXS40_VARIANT_PSOC6A_2M:
				EFUSE_MSG = EFUSE_P6_VOLTAGES;
				break;
			case MXS40_VARIANT_TRAVEO_II:
			case MXS40_VARIANT_TRAVEO_II_8M:
				EFUSE_MSG = EFUSE_TVII_VOLTAGES;
				break;
			default:
				LOG_ERROR("efuse_blow_bit. Unknown variant");
		}

		LOG_ERROR("The efuse bit at address 0x%X[%X] was not blown. %s %s %s",
			addr,
			bit_addr,
			EFUSE_MSG,
			EFUSE_MSG1,
			EFUSE_MSG2);
		return ERROR_FLASH_OPERATION_FAILED;
	}
	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Blows whole efuse byte and checks if the efuses were blown correctly
 * @param bank current flash bank
 * @param addr the address of efuse byte
 * @param data the value to be blown
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_blow_byte(struct flash_bank *bank, uint8_t addr, uint8_t data)
{
	int hr = ERROR_OK;

	for (uint8_t bitAddr = 0; bitAddr < 8; bitAddr++) {
		if (((data >> bitAddr) & 0x01) == 0x01) {
			hr = efuse_blow_bit(bank, addr, bitAddr);
			if (hr != ERROR_OK)
				break;
		}
	}
	return hr;
}

/** ***********************************************************************************************
 * @brief Converts PSoC6BLE2 from Normal to Secure
 * @param bank current flash bank
 * @param is_debug if true then transsfer to Secure with Sebug
 * @param file whole efuse region
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_p6_ble2_to_secure(struct flash_bank *bank, bool is_debug, const uint8_t *file)
{
	(void)file;

	int hr = efuse_check_factory_hash(bank);
	if (hr != ERROR_OK)
		goto exit;

	uint8_t hash[MXS40_EFUSE_HASH_SIZE];
	uint8_t hash_zeros = 0;
	hr = efuse_p6_generate_hash(bank, hash, MXS40_EFUSE_HASH_SIZE, &hash_zeros);
	if (hr != ERROR_OK)
		goto exit;

	/* Program FLASH_BOOT_HASH */
	for (uint8_t i = 0; i < MXS40_EFUSE_HASH_SIZE; i++) {
		hr = efuse_blow_byte(bank, MXS40_EFUSE_HASH_OFFSET + i, hash[i]);
		if (hr != ERROR_OK)
			goto exit;
	}

	/* Program FLASH_BOOT_HASH_ZEROS */
	hr = efuse_blow_byte(bank, MXS40_EFUSE_HASH_ZEROS_OFFSET, hash_zeros);
	if (hr != ERROR_OK)
		goto exit;

	uint8_t secure_bit_addr = 0;
	if (is_debug)
		secure_bit_addr = P6_EFUSE_LIFE_CYCLE_SECURE_DEBUG_BIT;
	else
		secure_bit_addr = P6_EFUSE_LIFE_CYCLE_SECURE_BIT;

	hr = efuse_blow_bit(bank, P6_EFUSE_LIFECYCLE_OFFSET, secure_bit_addr);
	if (hr != ERROR_OK)
		goto exit;
exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Sets ENABLE_FLASH_BOOT_CHECK_IN_NORMAL bits - least significant bits (four in total)
 *        in FACTORY_HASH[12-15] bytes just before TransitionToSecure API call.
 *        Applicable for PSoC6A-512K and PSoC6A-2M starting at A1
 * @param bank current flash bank
 * @param die Device Family/Die enum identificator
 * @param silicon_id Silicon ID of the following format:
 *  [31:24]       | [23:16]       | [15:12]       | [11:8]        | [7:0]
 *  Silicon Id Hi | Silicon ID Lo | Major Rev. Id | Minor Rev. Id | Family Id Lo
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_blow_enable_fbcheck_in_normal(struct flash_bank *bank, uint32_t silicon_id)
{
	int hr = ERROR_OK;	
	enum mxs40_die die;
	hr = mxs40_identify_die_from_silicon_id(silicon_id, &die);
	if (hr != ERROR_OK)
		goto exit;
	
	uint8_t revision_id = (silicon_id & 0x0000FF00) >> 8;

	if ((die == die_psoc6_512k) || ((die == die_psoc6_2m) && (revision_id >= 0x12 /* A1 (*A) and later*/))) {
		uint8_t byteAddr;
		uint8_t bitValue;
		uint8_t bitAddr = 0;
		
		for (int i = 1; i <= 4; i++) {
			byteAddr = MXS40_EFUSE_FACTORY_HASH_OFFSET + MXS40_EFUSE_FACTORY_HASH_SIZE - i;			
			
			/* Check current state of eFuse bit */
			hr = efuse_get_bit(bank, byteAddr, bitAddr, &bitValue);
			if (hr != ERROR_OK)
				goto exit;

			/* Blow eFuse bit if not blown yet */
			if (bitValue == 0) {
				hr = efuse_blow_bit(bank, byteAddr, bitAddr);
				if (hr != ERROR_OK)
					goto exit;
			}
		}
	}
	
exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Converts:
 *          PSoC6A-2M from Normal to Secure
 *          Traveo II from Normal Provisioned to Secure
 * @param bank current flash bank
 * @param is_debug if true then transsfer to Secure with Sebug
 * @param file whole efuse region
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_transition_to_secure(struct flash_bank *bank, bool is_debug, const uint8_t *file)
{
	struct mxs40_bank_info *info = bank->driver_priv;
	const struct efuse_regions *regions = info->efuse_regions;

	uint32_t dead_access_restr = 0;
	uint32_t secure_access_restr = 0;

	uint8_t dead_buff[4] = {0};
	efuse_get_array_from_file(file,
		regions->dead_access_offset,
		dead_buff,
		regions->dead_access_size);
	dead_access_restr = dead_buff[0] | (dead_buff[1] << 8) | (dead_buff[2] << 16) |
		(dead_buff[3] << 24);

	uint8_t secure_buff[4] = {0};
	efuse_get_array_from_file(file,
		regions->secure_access_offset,
		secure_buff,
		regions->secure_access_size);
	secure_access_restr = secure_buff[0] | (secure_buff[1] << 8) | (secure_buff[2] << 16) |
		(secure_buff[3] << 24);

	struct target *target = bank->target;

	struct working_area *wa;

	int hr = target_alloc_working_area(target,
			sizeof(uint32_t) * SROMAPI_TRANSITION_TO_SECURE_SIZE,
			&wa);
	if (hr != ERROR_OK)
		goto exit;

	uint32_t sromapi_req = SROMAPI_TRANSITION_TO_SECURE;
	if (is_debug)
		sromapi_req |= 1 << 8;

	hr = target_write_u32(target, wa->address, sromapi_req);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	hr = target_write_u32(target, wa->address + 4, secure_access_restr);
	if (hr != ERROR_OK)
		goto exit_free_wa;

	hr = target_write_u32(target, wa->address + 8, dead_access_restr);
	if (hr != ERROR_OK)
		goto exit_free_wa;


	uint32_t data_out;
	hr = mxs40_call_sromapi(bank, sromapi_req, wa->address, &data_out);
	if (hr != ERROR_OK)
		goto exit_free_wa;

exit_free_wa:
	target_free_working_area(target, wa);

exit:
	return hr;
}

/** ***********************************************************************************************
 * @brief Defines if efuse should not be blown
 * @param bank current flash bank
 * @param offset efuse address to check
 * @return true if efuse should not be blown, true otherwise
 *************************************************************************************************/
static bool efuse_blow_skip(struct flash_bank *bank, size_t offset)
{
	bool skip = false;
	struct mxs40_bank_info *info = bank->driver_priv;
	const struct efuse_regions *regions = info->efuse_regions;

	size_t lifecycle_offset = regions->lifecycle_offset * 8;
	size_t lifecycle_size = regions->lifecycle_size * 8;

	size_t dead_access_rest_offset = regions->dead_access_offset * 8;
	size_t dead_access_rest_size = regions->dead_access_size * 8;

	size_t secure_access_rest_offset = regions->secure_access_offset * 8;
	size_t secure_access_rest_size = regions->secure_access_size * 8;


	if (offset >= lifecycle_offset && offset < lifecycle_offset + lifecycle_size)
		/* do not program lifecycle */
		skip = true;
	else if (offset >= dead_access_rest_offset &&
		offset < dead_access_rest_offset + dead_access_rest_size)
		/* do not program DEAD_ACCESS restrictions */
		skip = true;
	else if (offset >= secure_access_rest_offset &&
		offset < secure_access_rest_offset + secure_access_rest_size)
		/* do not program SECCURE_ACCESS restrictions */
		skip = true;

	return skip;
}

/** ***********************************************************************************************
 * @brief Performs lifecycle transitions
 * @param bank current flash bank
 * @param buffer pointer to the buffer with program data
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
static int efuse_lifecycle_transitions(struct flash_bank *bank, const uint8_t *buffer)
{
	int hr = ERROR_OK;

	struct mxs40_bank_info *info = bank->driver_priv;
	uint32_t variant = info->regs->variant;
	/*const struct efuse_regions* regions = info->efuse_regions; */

	bool is_p6_ble2 = variant == MXS40_VARIANT_PSOC6_BLE2;
	bool is_p6a_2m = variant == MXS40_VARIANT_PSOC6A_2M;
	bool is_tv2 = variant == MXS40_VARIANT_TRAVEO_II || variant == MXS40_VARIANT_TRAVEO_II_8M;

	/* Get lifecycle from file if present */
	uint8_t pgm_file_life_cycle = efuse_get_life_cycle_from_file(bank, buffer);

	/* exit if no lifecycle in programming file */
	if (pgm_file_life_cycle) {

		/* Get chip lifecycle */
		uint32_t silicon_id = 0;
		uint8_t chip_protection = 0;
		uint8_t chip_lifecycle = 0;

		/* get_silicon_id contains sromalgo_prepare, so release it here */
		mxs40_sromalgo_release(bank->target);

		hr = mxs40_get_silicon_id(bank, &silicon_id, &chip_protection, &chip_lifecycle);
		if (hr != ERROR_OK)
			goto exit;

		hr = mxs40_sromalgo_prepare(bank);
		if (hr != ERROR_OK)
			goto exit;

		bool perform_transition = false;
		bool is_debug = false;

		if (is_p6_ble2 || is_p6a_2m) {
			/* OOCD for PSoC6 supports only Normal to Secure (Secure with Debug)
			 * transition */
			if (chip_lifecycle == MXS40_LIFE_CYCLE_NORMAL) {
				if (pgm_file_life_cycle == MXS40_LIFE_CYCLE_SECURE_DEBUG) {
					perform_transition = true;
					is_debug = true;
				} else if (pgm_file_life_cycle == MXS40_LIFE_CYCLE_SECURE) {
					perform_transition = true;
					is_debug = false;
				}

				if (perform_transition) {
					if (is_p6_ble2)
						hr = efuse_p6_ble2_to_secure(bank, is_debug, buffer);
					else {	/* is_p6a_2m */
					    /* Blow ENABLE_FLASH_BOOT_CHECK_IN_NORMAL bits for 512K and newer 2M devices */
						hr = efuse_blow_enable_fbcheck_in_normal(bank, silicon_id);
						if (hr != ERROR_OK)
							goto exit;
						hr = efuse_transition_to_secure(bank, is_debug, buffer);
					}
				}
			}
		} else if (is_tv2) {
			/* OOCD for TV2 supports:
			 * - Normal to Normal Provisioned transition
			 * - Normal Provisioned to Secure (Secure with Debug) transition */
			if (chip_lifecycle == MXS40_LIFE_CYCLE_NORMAL) {
				if (pgm_file_life_cycle == MXS40_LIFE_CYCLE_NORMAL_PROV) {
					perform_transition = true;
					/* Normal to Normal Provisioned */
				}
			} else if (chip_lifecycle == MXS40_LIFE_CYCLE_NORMAL_PROV) {
				if (pgm_file_life_cycle == MXS40_LIFE_CYCLE_SECURE_DEBUG) {
					perform_transition = true;
					is_debug = true;
				} else if (pgm_file_life_cycle == MXS40_LIFE_CYCLE_SECURE) {
					perform_transition = true;
					is_debug = false;
				}
				if (perform_transition)
					hr = efuse_transition_to_secure(bank, is_debug, buffer);
			}
		}

		if (!perform_transition)
			efuse_transition_forbidden(chip_lifecycle, pgm_file_life_cycle);

	} else
		LOG_INFO("The Life Cycle stage is not present in the programming file");

exit:
	return hr;

}

/** ***********************************************************************************************
 * @brief Checks if passed bank belongs to TVII device
 * @param bank current flash bank
 * @return true if passed bank belongs to TVII, false - otherwise
 *************************************************************************************************/
static bool efuse_is_tv2 (struct flash_bank *bank){
	bool ret = false;
	struct mxs40_bank_info *info = bank->driver_priv;
	if(info->regs->variant == MXS40_VARIANT_TRAVEO_II || info->regs->variant == MXS40_VARIANT_TRAVEO_II_8M)
		ret = true;

	return ret;
}

/** ***********************************************************************************************
 * @brief Programs EFuse region
 * @param bank current flash bank
 * @param buffer pointer to the buffer with program data
 * @param offset the offset in the bank to program
 * @param count number of bytes in buffer
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
int efuse_program_bank(struct flash_bank *bank, const uint8_t *buffer, uint32_t offset,
	uint32_t count)
{
	bool is_tv2 = efuse_is_tv2(bank);

	if (!g_allow_efuse_programming) {
		const char* dev_type = is_tv2 ? "traveo2" : "psoc 6";
		LOG_WARNING("Programming of eFuse bank is skipped. Use '%s allow_efuse_program on|off'"
			" command to enable|disable programming of efuse bank", dev_type);
		return ERROR_OK;
	}

	if (is_tv2){
		int hr = mxs40_traveo_setup(bank);
		if (hr != ERROR_OK)
			return hr;
	}

	/* Verify if efuse data in programming file is correct */
	for (size_t i = 0; i < count; i++) {
		if (buffer[i] != MXS40_EFUSE_NOT_BLOWN &&
			buffer[i] != MXS40_EFUSE_BLOWN &&
			buffer[i] != MXS40_EFUSE_IGNORE) {
			LOG_ERROR("The eFuse bit value is out of the range. Allowed values are:"
				"0x00, 0x01 and 0xFF, but found 0x%X", buffer[i]);
			return ERROR_IMAGE_FORMAT_ERROR;
		}
	}

	int hr = mxs40_sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	for (size_t i = 0; i < count; i++) {
		/* Program all efuses from programming file except lifecycle related data */

		if (efuse_blow_skip(bank, i))
			continue;

		if (buffer[i] == MXS40_EFUSE_IGNORE)
			continue;

		uint8_t byte_addr = (uint8_t)(i / 8);
		uint8_t bit_addr = (uint8_t)(i % 8);

		/* check if efuse is not blown if has to be */
		if (buffer[i] == MXS40_EFUSE_NOT_BLOWN) {
			uint8_t efuse_bit_value = 0;
			hr = efuse_get_bit(bank, byte_addr, bit_addr, &efuse_bit_value);
			if (hr != ERROR_OK) {
				LOG_ERROR("Cannot read Efuse byte at Addr = 0x%X", byte_addr);
				goto exit_release;
			}
			if (efuse_bit_value == 1) {
				LOG_ERROR("The eFuse bit at address 0x%X[%d] has been blown "
					"but didn't have to be", byte_addr, bit_addr);
				goto exit_release;
			}
		} else {
			/* if (buffer[i] == MXS40_EFUSE_BLOWN) */
			hr = efuse_blow_bit(bank, byte_addr, bit_addr);
			if (hr != ERROR_OK)
				goto exit_release;
		}

	}

	/* Program lifecycle efuses if present */
	efuse_lifecycle_transitions(bank, buffer);

exit_release:
	mxs40_sromalgo_release(bank->target);
exit:
	return hr;
}


/** ***********************************************************************************************
 * @brief Performs Erase operation. Currently not supported.
 *
 * @param bank current flash bank
 * @param first first sector to erase
 * @param last last sector to erase
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
int efuse_erase(struct flash_bank *bank, int first, int last)
{
	(void) bank; (void) first; (void) last;
	LOG_INFO("Erase operation for EFuse bank is not supported, skipping");
	return ERROR_OK;
}

/** ***********************************************************************************************
 * @brief Performs Read operation of EFuse region.
 *
 * @param bank The bank to read
 * @param buffer The data bytes read
 * @param offset The offset into the chip to read
 * @param count The number of bits to read. Note: single efuse bit is represented by bye in a
 * programming file
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
int efuse_read_bank(struct flash_bank *bank, uint8_t *buffer,
	uint32_t offset, uint32_t count)
{
	if (efuse_is_tv2(bank)){
		int hr = mxs40_traveo_setup(bank);
		if (hr != ERROR_OK)
			return hr;
	}

	memset(buffer, 0, count);

	uint32_t cur_addr = offset;
	uint32_t end_addr = offset + count;
	uint32_t start_byte_addr = cur_addr / 8 * 8;

	uint8_t byte_addr = 0;
	uint8_t efuse = 0;
	uint8_t bit_counter = 0;

	int hr = mxs40_sromalgo_prepare(bank);
	if (hr != ERROR_OK)
		goto exit;

	/* calculate number of bits to read */
	size_t num_bits_to_read = 0;
	/* check if need to read from middle of efuse byte */
	if (cur_addr > start_byte_addr) {
		byte_addr = (uint8_t)(cur_addr / 8);

		hr = efuse_read_byte(bank, byte_addr, &efuse);
		if (hr != ERROR_OK)
			goto exit;

		size_t skip_bits_start = (uint8_t)(cur_addr - start_byte_addr);
		if ((8 - skip_bits_start) > count)
			num_bits_to_read = (size_t)count;
		else
			num_bits_to_read = 8 - skip_bits_start;

		bit_counter = 0;
		for (size_t bit_addr = skip_bits_start;
			bit_addr < skip_bits_start + num_bits_to_read; bit_addr++) {
			if (efuse & (1 << bit_addr))
				buffer[bit_counter] = 1;

			bit_counter++;
		}
		cur_addr += num_bits_to_read;
	}

	num_bits_to_read = 8;
	while (cur_addr < end_addr) {
		if (cur_addr + 8 > end_addr) {
			/* last efuse byte to read */
			num_bits_to_read = (size_t)(end_addr - cur_addr);
		}

		byte_addr = (uint8_t)(cur_addr / 8);
		hr = efuse_read_byte(bank, byte_addr, &efuse);
		if (hr != ERROR_OK)
			goto exit;
		bit_counter = 0;
		for (uint8_t bit_addr = 0; bit_addr < num_bits_to_read; bit_addr++) {
			if (efuse & (1 << bit_addr))
				buffer[cur_addr + bit_counter - offset] = 1;
			bit_counter++;
		}
		cur_addr += num_bits_to_read;
	}

exit:
	mxs40_sromalgo_release(bank->target);
	return hr;
}

/** ***********************************************************************************************
 * @brief Probes the device and populates related data structures with target flash geometry data.
 * This is done in non-intrusive way, no SROM API calls are involved so GDB can safely attach to a
 * running target. Function assumes that size of Work Flash is 32kB (true for all current part numbers)
 *
 * @param bank current flash bank
 * @return ERROR_OK in case of success, ERROR_XXX code otherwise
 *************************************************************************************************/
int efuse_probe(struct flash_bank *bank)
{
	assert(bank->size != 0);
	struct mxs40_bank_info *info = bank->driver_priv;

	bank->chip_width = 1;
	bank->bus_width = 1;
	bank->erased_value = 0;
	bank->default_padded_value = 0xFF;

	bank->num_sectors = 1;
	bank->sectors = calloc(1, sizeof(struct flash_sector));
	bank->sectors[0].size = bank->size;
	bank->sectors[0].is_erased = -1;
	bank->sectors[0].is_protected = -1;

	bank->write_start_alignment = bank->size;
	bank->write_end_alignment = bank->size;
	bank->minimal_write_gap = bank->size;

	info->page_size = bank->size;
	info->is_probed = true;

	return ERROR_OK;
}

FLASH_BANK_COMMAND_HANDLER(psoc6_ble2_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t p6_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/psoc6_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = p6_program_algo;
	info->program_algo_size = sizeof(p6_program_algo);
	info->regs = &psoc6_ble2_regs;
	info->efuse_regions = &EFUSE_REGIONS_LIST[EFUSE_REGIONS_P6_BLE2];
	bank->driver_priv = info;

	return ERROR_OK;
}

FLASH_BANK_COMMAND_HANDLER(psoc6a_2m_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t p6_2m_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/psoc62m_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = p6_2m_program_algo;
	info->program_algo_size = sizeof(p6_2m_program_algo);
	info->regs = &psoc6_2m_regs;
	info->efuse_regions = &EFUSE_REGIONS_LIST[EFUSE_REGIONS_P6A_2M];
	bank->driver_priv = info;

	return ERROR_OK;
}

FLASH_BANK_COMMAND_HANDLER(traveo2_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t traveo2_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/tv2_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = traveo2_program_algo;
	info->program_algo_size = sizeof(traveo2_program_algo);
	info->regs = &traveo2_regs;
	info->size_override = bank->size;
	info->efuse_regions = &EFUSE_REGIONS_LIST[EFUSE_REGIONS_TVII];
	bank->driver_priv = info;

	return ERROR_OK;
}

FLASH_BANK_COMMAND_HANDLER(traveo2_8m_flash_bank_command)
{
	if (CMD_ARGC < 6)
		return ERROR_COMMAND_SYNTAX_ERROR;

	static const uint8_t traveo2_program_algo[] = {
		#include "../../../../contrib/loaders/flash/psoc6/tv2_write.inc"
	};

	struct mxs40_bank_info *info = calloc(1, sizeof(struct mxs40_bank_info));
	info->is_probed = false;
	info->program_algo_p = traveo2_program_algo;
	info->program_algo_size = sizeof(traveo2_program_algo);
	info->regs = &traveo2_8m_regs;
	info->size_override = bank->size;
	info->efuse_regions = &EFUSE_REGIONS_LIST[EFUSE_REGIONS_TVII];
	bank->driver_priv = info;

	return ERROR_OK;
}

static const struct command_registration efuse_exec_command_handlers[] = {
	{
		.name = "allow_efuse_program",
		.handler = handle_allow_efuse_program,
		.mode = COMMAND_ANY,
		.usage = "on|off",
		.help = "Enables programming of efuse region",
	},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration efuse_p6_command_handlers[] = {
	{
		.name = "psoc6",
		.mode = COMMAND_ANY,
		.help = "PSoC 6 flash command group",
		.usage = "",
		.chain = efuse_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration efuse_tv2_command_handlers[] = {
	{
		.name = "traveo2",
		.mode = COMMAND_ANY,
		.help = "Traveo2 flash command group",
		.usage = "",
		.chain = efuse_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE
};

struct flash_driver psoc6_efuse = {
	.name = "psoc6_efuse",
	.commands = efuse_p6_command_handlers,
	.flash_bank_command = psoc6_ble2_flash_bank_command,
	.erase = efuse_erase,
	.protect = mxs40_protect,
	.write = efuse_program_bank,
	.read = efuse_read_bank,
	.probe = efuse_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};

struct flash_driver psoc6_2m_efuse = {
	.name = "psoc6_2m_efuse",
	.commands = efuse_p6_command_handlers,
	.flash_bank_command = psoc6a_2m_flash_bank_command,
	.erase = efuse_erase,
	.protect = mxs40_protect,
	.write = efuse_program_bank,
	.read = efuse_read_bank,
	.probe = efuse_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};

struct flash_driver traveo21_efuse = {
	.name = "traveo21_efuse",
	.commands = efuse_tv2_command_handlers,
	.flash_bank_command = traveo2_flash_bank_command,
	.erase = efuse_erase,
	.protect = mxs40_protect,
	.write = efuse_program_bank,
	.read = efuse_read_bank,
	.probe = efuse_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};

struct flash_driver traveo22_efuse = {
	.name = "traveo22_efuse",
	.commands = efuse_tv2_command_handlers,
	.flash_bank_command = traveo2_8m_flash_bank_command,
	.erase = efuse_erase,
	.protect = mxs40_protect,
	.write = efuse_program_bank,
	.read = efuse_read_bank,
	.probe = efuse_probe,
	.auto_probe = mxs40_auto_probe,
	.erase_check = default_flash_blank_check,
	.protect_check = mxs40_protect_check,
	.info = mxs40_get_info,
	.free_driver_priv = default_flash_free_driver_priv,
};
