/*
 * internal_flash.h
 *
 *  Created on: Jul 23, 2020
 *      Author: calebkang
 */

#ifndef SRC_INTERNAL_FLASH_H_
#define SRC_INTERNAL_FLASH_H_

#include "stm32l4xx_hal.h"

#define FLASH_START_BANK1             ((uint32_t)0x08000000)
#define FLASH_START_BANK2             ((uint32_t)0x08080000)
#define USER_FLASH_END_ADDRESS        ((uint32_t)0x08100000)
#define FLASH_PAGE_NB                 (64U)

/* Error code */
typedef enum
{
  FLASHIF_OK = 0,
  FLASHIF_ERASEKO,
  FLASHIF_WRITINGCTRL_ERROR,
  FLASHIF_WRITING_ERROR,
  FLASHIF_CRCKO,
  FLASHIF_RECORD_ERROR,
  FLASHIF_EMPTY,
  FLASHIF_PROTECTION_ERRROR
} FLASHIF_StatusTypeDef;

/* Exported functions ------------------------------------------------------- */
FLASHIF_StatusTypeDef FLASH_If_Erase(uint32_t bank_active);
FLASHIF_StatusTypeDef FLASH_If_Check(uint32_t start);
FLASHIF_StatusTypeDef FLASH_If_Write(uint32_t destination, uint32_t *p_source, uint32_t length);
FLASHIF_StatusTypeDef FLASH_If_WriteProtectionClear( void );
HAL_StatusTypeDef FLASH_If_BankSwitch( void );
HAL_StatusTypeDef FLASH_If_Copy( void );
#endif /* SRC_INTERNAL_FLASH_H_ */
