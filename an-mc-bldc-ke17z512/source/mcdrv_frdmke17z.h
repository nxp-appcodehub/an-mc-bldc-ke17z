/*
 * Copyright 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _MCDRV_FRDM_KE17Z_H_
#define _MCDRV_FRDM_KE17Z_H_

#include "fsl_device_registers.h"
#include "mcdrv_pwm3ph_ftm.h"
#include "mcdrv_ftm_cmt.h"
#include "mcdrv_adc_adc16.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Version info */
#define MCRSP_VER "2.0.0" /* motor control package version */

/* Application info */
typedef struct _app_ver
{
    char cBoardID[15];
    char cMotorType[4];
    char cAppVer[5];
} app_ver_t;

/* Structure used during clocks and modulo calculations */
typedef struct _clock_setup
{
    uint32_t ui32SystemClock;
    uint32_t ui32SysOscAsyncDiv2;
    uint16_t ui16PwmFreq;
    uint16_t ui16PwmModulo;
    uint16_t ui16PwmDeadTime;
    uint32_t ui32CmtTimerFreq;
    uint16_t ui16CtrlLoopFreq;
} clock_setup_t;

/* define motor 1 ADC periphery (ADC16) */
#define M1_MCDRV_ADC (MCDRV_ADC16)

/* define motor 1 3-ph PWM periphery */
#define M1_MCDRV_PWM3PH (MCDRV_FTM0)

/* define motor 1 asynchronous time event*/
#define M1_MCDRV_TMR_CMT (MCDRV_FTM1)

/* define motor 1 slow control loop timer */
#define M1_MCDRV_TMR_SLOWLOOP (MCDRV_FTM2)

/* define motor 1 ADC trigger PDB */
#define M1_MCDRV_PDB (MCDRV_PDB0)

/* define motor 1 ADC trigger LPIT */
#define M1_MCDRV_LPIT (MCDRV_LPIT0)

/******************************************************************************
 * Clock & PWM definition
 ******************************************************************************/
#define CPU_CLOCK (DEFAULT_SYSTEM_CLOCK) /* 72 MHz, CLOCK_SETUP = 1 */
#define CTRL_LOOP_FREQ (1000)            /* Frequency of control loop in Hz */
#define PWM_FREQ (20000)                 /* PWM frequency - 20kHz */
#define PWM_DEADTIME (500)               /* Output PWM deadtime value in nanoseconds */

/* assignment of FTM channels to motor phases
 * 0 - FTM channels 0&1
 * 2 - FTM channels 2&3
 * 4 - FTM channels 4&5
 */
#define M1_PWM_PAIR_PHA (0)
#define M1_PWM_PAIR_PHB (2)
#define M1_PWM_PAIR_PHC (4)

/* array with swap and mask constants */
extern const char bldcCommutationTableComp[16];

/* FTM channel number for asynchronous time event */
#define M1_FTM_CMT_CHAN (0)

/******************************************************************************
 * ADC measurement definition
 ******************************************************************************/
/* predefined values of ADC channels */
#define ADC_TEMPERATURE (26)
#define ADC_NO_CHAN (31)

/* Configuration table of ADC channels according to the input pin signals:
 * Valid for Kinetis KE150 Freedom board (FRDM-KE15Z) together with FRDM-MC-LVPMSM
 *
 * Proper ADC channel assignment needs to follow these rules:
 *   - only one ADC module can be assigned to sense required variable
 *   - auxiliary quantity must be assigned to last free ADC module
 *   --------------------------------------------------------------------------
 *   BEMF_A           | ADC0_CH11
 *   BEMF_B           | ADC0_CH7
 *   BEMF_C           | ADC0_CH1
 *   U_dcb            | ADC0_CH3
 *   I_dcb            | ADC0_CH15
 */
/* BEMF phase A assigned to ADC0 only */
#define M1_ADC0_PH_A (11)
/* BEMF phase B assigned to ADC0 only */
#define M1_ADC0_PH_B (7)
/* BEMF phase C assigned to ADC0 only */
#define M1_ADC0_PH_C (1)
/* DC-bus voltage is assigned to ADC0 only */
#define M1_ADC0_UDCB (13)
/* DC-bus current is assigned to ADC1 only */
#define M1_ADC0_IDCB (15)
/* Aux channel is assigned to ADC1 only */
#define M1_ADC0_AUX ADC_NO_CHAN

/* offset measurement filter window */
#define ADC_OFFSET_WINDOW (3)

/******************************************************************************
 * MC driver macro definition and check - do not change this part
 ******************************************************************************/
/******************************************************************************
 * define motor 1 ADC control functions
 ******************************************************************************/
#ifdef M1_MCDRV_ADC
#if (M1_MCDRV_ADC == MCDRV_ADC16)
#define M1_MCDRV_ADC_PERIPH_INIT() InitADC16()
#define M1_MCDRV_ADC_GET(par)  \
    MCDRV_BemfVoltageGet(par); \
    MCDRV_VoltDcBusGet(par);   \
    MCDRV_CurrDcBusGet(par);
#define M1_MCDRV_ADC_ASSIGN_BEMF(par) MCDRV_AssignBemfChannel(par)
#define M1_MCDRV_CURR_CALIB_INIT(par) MCDRV_CurrOffsetCalibInit(par)
#define M1_MCDRV_CURR_CALIB(par) MCDRV_CurrOffsetCalib(par)
#define M1_MCDRV_CURR_CALIB_SET(par) MCDRV_CurrOffsetCalibSet(par)
#else
#error MCDRV: Unsupported ADC periphery!
#endif
#else
#error MCDRV: ADC periphery was not specified!
#endif

/******************************************************************************
 * define motor 1 3-ph PWM control functions                                  *
 ******************************************************************************/

#ifdef M1_MCDRV_PWM3PH
#if (M1_MCDRV_PWM3PH == MCDRV_FTM0)
#define M1_MCDRV_PWM_PERIPH_INIT() InitFTM0()
#define M1_MCDRV_PWM3PH_SET_PWM_OUTPUT(par1, par2) MCDRV_FtmSetPwmOutput(par1, par2)
#define M1_MCDRV_PWM3PH_SET_DUTY(par1, par2) MCDRV_FtmSetDutyCycle(par1, par2)
#else
#error MCDRV: Unsupported PWM periphery!
#endif
#else
#error MCDRV: PWM periphery was not specified!
#endif

/******************************************************************************
 * define motor 1 asynchronous time event functions                           *
 ******************************************************************************/
#ifdef M1_MCDRV_TMR_CMT
#if (M1_MCDRV_TMR_CMT == MCDRV_FTM1)
#define M1_MCDRV_TMR_CMT_PERIPH_INIT() InitFTM1()
#define M1_MCDRV_TMR_CMT_SET(par1, par2) MCDRV_FtmCmtSet(par1, par2)
#define M1_MCDRV_TMR_CMT_GET(par) MCDRV_FtmCmtGet(par)
#else
#error MCDRV: Unsupported Timer periphery!
#endif
#else
#error MCDRV: Timer periphery was not specified!
#endif

/******************************************************************************
 * define motor 1 slow control loop timer
 ******************************************************************************/
#ifdef M1_MCDRV_TMR_SLOWLOOP
#if (M1_MCDRV_TMR_SLOWLOOP == MCDRV_FTM2)
#define M1_MCDRV_TMR_SLOWLOOP_INIT() InitFTM2()
#else
#error MCDRV: Unsupported Timer periphery!
#endif
#else
#error MCDRV: Timer periphery was not specified!
#endif

/******************************************************************************
 * define motor 1 ADC trigger PDB
 ******************************************************************************/
#ifdef M1_MCDRV_PDB
#if (M1_MCDRV_PDB == MCDRV_PDB0)
#define M1_MCDRV_PDB_INIT() InitPDB()
#else
#error MCDRV: Unsupported PDB periphery!
#endif
#else
#error MCDRV: PDB periphery was not specified!
#endif

/******************************************************************************
 * define motor 1 ADC trigger LPIT
 ******************************************************************************/
#ifdef M1_MCDRV_LPIT
#if (M1_MCDRV_LPIT == MCDRV_LPIT0)
#define M1_MCDRV_LPIT_INIT() InitLPIT()
#else
#error MCDRV: Unsupported LPIT periphery!
#endif
#else
#error MCDRV: LPIT periphery was not specified!
#endif

/******************************************************************************
 * global variable definitions
 ******************************************************************************/
extern mcdrv_pwm3ph_ftm_t g_sM1Pwm3ph;
extern mcdrv_ftm_cmt_t g_sM1CmtTmr;
extern mcdrv_adc16_t g_sM1AdcSensor;
extern clock_setup_t g_sClockSetup;

/*******************************************************************************
 * API
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

void MCDRV_Init_M1(void);
void InitFTM0(void);
void InitFTM2(void);
void InitFTM1(void);
void InitPDB(void);
void InitLPIT(void);
void InitADC16(void);
void InitClock(void);

#ifdef __cplusplus
}
#endif
#endif /* _MCDRV_FRDM_KE15Z_H_  */