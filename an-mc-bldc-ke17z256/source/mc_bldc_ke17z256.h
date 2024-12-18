/*
 * Copyright 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _MKE17Z7_MC_BLDC_H_
#define _MKE17Z7_MC_BLDC_H_

#include "freemaster.h"
#include "pin_mux.h"
#include "peripherals.h"
#include "fsl_lpuart.h"
#include "m1_sm_ref_sol.h"
#include "mcdrv_frdmke17z.h"

#include "freemaster_serial_lpuart.h"
#include "board.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Macro for correct Cortex CM0 / CM4 end of interrupt */
#define M1_END_OF_ISR \
    {                 \
        __DSB();      \
        __ISB();      \
    }

/* CPU load measurement SysTick START / STOP macros */
#define SYSTICK_START_COUNT() (SysTick->VAL = SysTick->LOAD)
#define SYSTICK_STOP_COUNT(par1)   \
    uint32_t val  = SysTick->VAL;  \
    uint32_t load = SysTick->LOAD; \
    par1          = load - val

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 * API
 ******************************************************************************/

void DemoSpeedStimulator(void);

/* Init HW */
void BOARD_Init(void);
void BOARD_InitSysTick(void);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* _MKE17Z7_MC_BLDC_H_ */
