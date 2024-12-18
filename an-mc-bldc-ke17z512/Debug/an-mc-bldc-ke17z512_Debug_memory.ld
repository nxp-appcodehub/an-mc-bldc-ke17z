/*
 * GENERATED FILE - DO NOT EDIT
 * Copyright 2008-2013 Code Red Technologies Ltd,
 * Copyright 2013-2024 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 * Generated linker script file for MKE17Z512xxx9
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.30
 * MCUXpresso IDE v24.9 [Build 25] [2024-09-26] on Dec 13, 2024, 4:31:01 PM
 */

MEMORY
{
  /* Define each memory region */
  PROGRAM_FLASH (rx) : ORIGIN = 0x0, LENGTH = 0x80000 /* 512K bytes (alias Flash) */  
  SRAM (rwx) : ORIGIN = 0x1fff8000, LENGTH = 0x18000 /* 96K bytes (alias RAM) */  
}

  /* Define a symbol for the top of each memory region */
  __base_PROGRAM_FLASH = 0x0  ; /* PROGRAM_FLASH */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_PROGRAM_FLASH = 0x0 + 0x80000 ; /* 512K bytes */  
  __top_Flash = 0x0 + 0x80000 ; /* 512K bytes */  
  __base_SRAM = 0x1fff8000  ; /* SRAM */  
  __base_RAM = 0x1fff8000 ; /* RAM */  
  __top_SRAM = 0x1fff8000 + 0x18000 ; /* 96K bytes */  
  __top_RAM = 0x1fff8000 + 0x18000 ; /* 96K bytes */  
