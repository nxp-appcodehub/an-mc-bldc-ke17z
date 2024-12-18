/*
 * Copyright 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v10.0
processor: MKE17Z256xxx7
package_id: MKE17Z256VLL7
mcu_data: ksdk2_0
processor_version: 0.10.1
board: FRDM-KE17Z
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: cf8d3c5e-f8bd-4672-a3b4-b13ff2362e09
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
    - interrupts:
      - 0:
        - channelId: 'int_0'
        - interrupt_t:
          - IRQn: 'PORTBCD_IRQn'
          - enable_interrrupt: 'enabled'
          - enable_priority: 'true'
          - priority: '4'
          - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * FreeMASTER initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'FreeMASTER'
- type: 'freemaster'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'freemaster_14894d49d87e02d0dca5f799e22554da'
- functional_group: 'BOARD_InitPeripherals'
- config_sets:
  - freemaster_config:
    - FMSTR_DISABLE: 'false'
    - initFreemaster: 'true'
    - generalConfig:
      - commInterface: 'serial'
      - interruptMode: 'polling'
      - initType: 'false'
      - serialConfig:
        - peripheralUART: 'LPUART0'
        - clockSource: 'genericUartClockSource'
        - clockSourceFreq: 'BOARD_BootClockRUN'
        - baudRate_Bps: '19200'
        - parityMode_lpuart: 'kLPUART_ParityDisabled'
        - stopBitCount_lpuart: 'kLPUART_OneStopBit'
        - dataBitsCount: 'kLPUART_EightDataBits'
        - enable_rx_tx_irq: 'true'
        - interrupt_rx_tx:
          - IRQn: 'LPUART0_IRQn'
          - enable_interrrupt: 'enabled'
          - enable_priority: 'false'
          - priority: '0'
          - useDefaultISR: 'true'
      - FMSTR_COMM_BUFFER_SIZE: 'autoSize'
      - FMSTR_COMM_RQUEUE_SIZE: '32'
      - FMSTR_USE_SCOPE: '2'
      - FMSTR_MAX_SCOPE_VARS: '8'
      - FMSTR_REC_FLOAT_TRIG: 'false'
      - recorders:
        - 0:
          - recID:
            - enableCustomID: 'false'
          - nameRec: 'Default Recorder'
          - recBuff:
            - customBuffer: 'false'
            - bufferSize: '4096'
          - basePeriod_ns: '100000'
          - recInit: 'true'
      - FMSTR_USE_TSA: 'true'
      - FMSTR_USE_TSA_INROM: 'true'
      - FMSTR_USE_TSA_SAFETY: 'true'
      - FMSTR_USE_TSA_DYNAMIC: 'false'
      - pipes: []
      - FMSTR_USE_READMEM: 'true'
      - FMSTR_USE_WRITEMEM: 'true'
      - FMSTR_USE_WRITEMEMMASK: 'true'
      - passR: ''
      - passRW: ''
      - passRWF: ''
      - FMSTR_USE_HASHED_PASSWORDS: 'false'
      - FMSTR_USE_APPCMD: 'true'
      - FMSTR_APPCMD_BUFF_SIZE: '32'
      - FMSTR_MAX_APPCMD_CALLS: '4'
      - FMSTR_DEBUG_LEVEL: '0'
      - FMSTR_DEBUG_PRINTF: 'debug_console'
      - FMSTR_DEBUG_TX: 'false'
      - FMSTR_CUSTOM_INCLUDES: ''
      - FMSTR_CUSTOM_OPTIONS: ''
    - freemaster_codegenerator: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
/* LPUART configuration structure */
lpuart_config_t FreeMASTER_serial_config;
/* Recorder0 configuration */
FMSTR_U8 FreeMASTER_RecBuffer0[FREEMASTER_REC_0_SIZE];
FMSTR_REC_BUFF FreeMASTER_Recorder_0 = {
  .name = "Default Recorder",
  .addr = (FMSTR_ADDR)FreeMASTER_RecBuffer0,
  .size = FREEMASTER_REC_0_SIZE,
  .basePeriod_ns = 100000UL
};

static void FreeMASTER_init(void) {
  /* Serial communication peripheral initialization */

  /* Get LPUART default configuration and modify it */
  LPUART_GetDefaultConfig(&FreeMASTER_serial_config);

  FreeMASTER_serial_config.baudRate_Bps = FREEMASTER_SERIAL_PERIPHERAL_BAUDRATE;
  FreeMASTER_serial_config.parityMode = kLPUART_ParityDisabled;
  FreeMASTER_serial_config.stopBitCount = kLPUART_OneStopBit;
  FreeMASTER_serial_config.dataBitsCount = kLPUART_EightDataBits;

  /* Initialize LPUART module. */
  LPUART_Init(FREEMASTER_SERIAL_PERIPHERAL, &FreeMASTER_serial_config, FREEMASTER_SERIAL_PERIPHERAL_CLK_FREQ);
  /* FreeMASTER middleware initialization */
  FMSTR_Init();
  /* FreeMASTER recorder 0 configuration initialization  */
  FMSTR_RecorderCreate(0, &FreeMASTER_Recorder_0);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
static void BOARD_InitPeripherals_CommonPostInit(void)
{
  /* Interrupt vector PORTBCD_IRQn priority settings in the NVIC. */
  NVIC_SetPriority(INT_0_IRQN, INT_0_IRQ_PRIORITY);
  /* Enable interrupt PORTBCD_IRQn request in the NVIC. */
  EnableIRQ(INT_0_IRQN);
}

void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  FreeMASTER_init();
  /* Common post-initialization */
  BOARD_InitPeripherals_CommonPostInit();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}