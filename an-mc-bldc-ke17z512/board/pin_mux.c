/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v15.0
processor: MKE17Z512xxx9
package_id: MKE17Z512VLL9
mcu_data: ksdk2_0
processor_version: 0.15.4
pin_labels:
- {pin_num: '20', pin_signal: PTD17/FTM0_FLT2/LPUART2_RX/TRGMUX_OUT2, label: 'J1[2]/Arduino_D0', identifier: J1_2}
- {pin_num: '82', pin_signal: PTA16/FTM1_CH3/LPSPI1_PCS2/LPI2C0_SDA, label: 'J2[18]/U11[3]/FXOS_SDA/Arduino_D14', identifier: FXOS_SDA;J2_18}
- {pin_num: '77', pin_signal: PTB8/LPI2C0_SCL/FXIO_D4, label: 'J2[20]/U11[2]/Arduino_D15/FXOS_SCL', identifier: FXOS_SCL;J20;J2_20}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_trgmux.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitBUTTONSPins();
    BOARD_InitLEDsPins();
    BOARD_InitDEBUG_UARTPins();
    BOARD_InitFTM();
    BOARD_InitMISC();
    BOARD_InitLPIT();
    BOARD_InitADC();
    BOARD_InitTRGMUX();
    BOARD_InitCMP();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: cm0plus, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBUTTONSPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {pin_num: '70', peripheral: GPIOD, signal: 'GPIO, 3', pin_signal: PTD3/LPSPI1_PCS0/FXIO_D5/LPI2C0_SCL/TRGMUX_IN4/NMI_b, direction: INPUT, gpio_interrupt: kPORT_InterruptRisingEdge,
    drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable, digital_filter: disable}
  - {pin_num: '17', peripheral: GPIOE, signal: 'GPIO, 14', pin_signal: PTE14/FTM0_FLT1/TRGMUX_OUT4, direction: INPUT, gpio_interrupt: no_init}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONSPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBUTTONSPins(void)
{
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t gpiod_pin70_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD3 (pin 70)  */
    GPIO_PinInit(GPIOD, 3U, &gpiod_pin70_config);

    gpio_pin_config_t gpioe_pin17_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE14 (pin 17)  */
    GPIO_PinInit(GPIOE, 14U, &gpioe_pin17_config);
    /* Configure digital filter */
    PORT_EnablePinsDigitalFilter(
        /* Digital filter is configured on port D */
        PORTD,
        /* Digital filter is configured for PORTD0 */
        PORT_DFER_DFE_3_MASK,
        /* Disable digital filter */
        false);

    const port_pin_config_t portd3_pin70_config = {/* Internal pull-up/down resistor is disabled */
                                                   kPORT_PullDisable,
                                                   /* Passive filter is disabled */
                                                   kPORT_PassiveFilterDisable,
                                                   /* Low drive strength is configured */
                                                   kPORT_LowDriveStrength,
                                                   /* Pin is configured as PTD3 */
                                                   kPORT_MuxAsGpio,
                                                   /* Pin Control Register fields [15:0] are not locked */
                                                   kPORT_UnlockRegister};
    /* PORTD3 (pin 70) is configured as PTD3 */
    PORT_SetPinConfig(PORTD, 3U, &portd3_pin70_config);

    /* Interrupt configuration on PORTD3 (pin 70): Interrupt on rising edge */
    PORT_SetPinInterruptConfig(PORTD, 3U, kPORT_InterruptRisingEdge);

    /* PORTE14 (pin 17) is configured as PTE14 */
    PORT_SetPinMux(PORTE, 14U, kPORT_MuxAsGpio);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {pin_num: '34', peripheral: GPIOD, signal: 'GPIO, 12', pin_signal: PTD12/FTM2_CH2/LPI2C1_HREQ/LPUART2_RTS, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '35', peripheral: GPIOD, signal: 'GPIO, 11', pin_signal: PTD11/FTM2_CH1/LPUART2_CTS, direction: OUTPUT}
  - {pin_num: '36', peripheral: GPIOD, signal: 'GPIO, 10', pin_signal: PTD10/FTM2_CH0, direction: OUTPUT}
  - {pin_num: '33', peripheral: GPIOD, signal: 'GPIO, 5', pin_signal: ADC0_SE9/PTD5/FTM2_CH3/LPTMR0_ALT2/FXIO_D3/PWT_IN2/TRGMUX_IN7/LPUART2_CTS, direction: OUTPUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitLEDsPins(void)
{
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortD);

    gpio_pin_config_t gpiod_pin33_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD5 (pin 33)  */
    GPIO_PinInit(GPIOD, 5U, &gpiod_pin33_config);

    gpio_pin_config_t gpiod_pin36_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD10 (pin 36)  */
    GPIO_PinInit(GPIOD, 10U, &gpiod_pin36_config);

    gpio_pin_config_t gpiod_pin35_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD11 (pin 35)  */
    GPIO_PinInit(GPIOD, 11U, &gpiod_pin35_config);

    gpio_pin_config_t gpiod_pin34_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PTD12 (pin 34)  */
    GPIO_PinInit(GPIOD, 12U, &gpiod_pin34_config);

    /* PORTD10 (pin 36) is configured as PTD10 */
    PORT_SetPinMux(PORTD, 10U, kPORT_MuxAsGpio);

    /* PORTD11 (pin 35) is configured as PTD11 */
    PORT_SetPinMux(PORTD, 11U, kPORT_MuxAsGpio);

    /* PORTD12 (pin 34) is configured as PTD12 */
    PORT_SetPinMux(PORTD, 12U, kPORT_MuxAsGpio);

    /* PORTD5 (pin 33) is configured as PTD5 */
    PORT_SetPinMux(PORTD, 5U, kPORT_MuxAsGpio);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', prefix: BOARD_, coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {pin_num: '20', peripheral: LPUART2, signal: RX, pin_signal: PTD17/FTM0_FLT2/LPUART2_RX/TRGMUX_OUT2}
  - {pin_num: '19', peripheral: LPUART2, signal: TX, pin_signal: PTE12/FTM0_FLT3/LPUART2_TX/TRGMUX_OUT3}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitDEBUG_UARTPins(void)
{
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTD17 (pin 20) is configured as LPUART2_RX */
    PORT_SetPinMux(BOARD_J1_2_PORT, BOARD_J1_2_PIN, kPORT_MuxAlt3);

    /* PORTE12 (pin 19) is configured as LPUART2_TX */
    PORT_SetPinMux(PORTE, 12U, kPORT_MuxAlt3);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitFTM:
- options: {callFromInitBoot: 'true', coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {pin_num: '68', peripheral: FTM0, signal: 'CH, 0', pin_signal: TSI1_CH8/PTB12/FTM0_CH0/SCI1_RX}
  - {pin_num: '67', peripheral: FTM0, signal: 'CH, 1', pin_signal: TSI1_CH9/PTB13/FTM0_CH1/SCI1_TX}
  - {pin_num: '66', peripheral: FTM0, signal: 'CH, 2', pin_signal: PTB14/FTM0_CH2/LPSPI1_SCK}
  - {pin_num: '65', peripheral: FTM0, signal: 'CH, 3', pin_signal: PTB15/FTM0_CH3/LPSPI1_SIN}
  - {pin_num: '64', peripheral: FTM0, signal: 'CH, 4', pin_signal: PTB16/FTM0_CH4/LPSPI1_SOUT}
  - {pin_num: '63', peripheral: FTM0, signal: 'CH, 5', pin_signal: PTB17/FTM0_CH5/LPSPI1_PCS3}
  - {peripheral: FTM0, signal: 'FLT, 1', pin_signal: CMP0_OUT}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitFTM
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitFTM(void)
{
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortB);

    /* PORTB12 (pin 68) is configured as FTM0_CH0 */
    PORT_SetPinMux(PORTB, 12U, kPORT_MuxAlt2);

    /* PORTB13 (pin 67) is configured as FTM0_CH1 */
    PORT_SetPinMux(PORTB, 13U, kPORT_MuxAlt2);

    /* PORTB14 (pin 66) is configured as FTM0_CH2 */
    PORT_SetPinMux(PORTB, 14U, kPORT_MuxAlt2);

    /* PORTB15 (pin 65) is configured as FTM0_CH3 */
    PORT_SetPinMux(PORTB, 15U, kPORT_MuxAlt2);

    /* PORTB16 (pin 64) is configured as FTM0_CH4 */
    PORT_SetPinMux(PORTB, 16U, kPORT_MuxAlt2);

    /* PORTB17 (pin 63) is configured as FTM0_CH5 */
    PORT_SetPinMux(PORTB, 17U, kPORT_MuxAlt2);

    SIM->FTMOPT0 = ((SIM->FTMOPT0 &
                     /* Mask bits to zero which are setting */
                     (~(SIM_FTMOPT0_FTM0FLTxSEL_MASK)))

                    /* FTM0 Fault x Select: 0x02u. */
                    | SIM_FTMOPT0_FTM0FLTxSEL(0x02u));
    /* CMP0 Output is selected as FTM0 device trigger input 2 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Ftm0, kTRGMUX_TriggerInput2, kTRGMUX_SourceCmp0Output);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitMISC:
- options: {callFromInitBoot: 'true', coreID: cm0plus, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitMISC
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitMISC(void)
{
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLPIT:
- options: {callFromInitBoot: 'true', coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {peripheral: LPIT0, signal: 'TRG_CH, 0', pin_signal: FTM0_Trigger}
  - {peripheral: LPIT0, signal: 'TRG_CH, 1', pin_signal: ADC0_COCOA}
  - {peripheral: LPIT0, signal: 'TRG_CH, 2', pin_signal: ADC0_COCOB}
  - {peripheral: LPIT0, signal: 'TRG_CH, 3', pin_signal: ADC0_COCOC}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLPIT
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitLPIT(void)
{
    /* FTM0 is selected as LPIT device trigger input 0 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Lpit, kTRGMUX_TriggerInput0, kTRGMUX_SourceFtm0);
    /* ADC0 COCOA is selected as LPIT device trigger input 1 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Lpit, kTRGMUX_TriggerInput1, kTRGMUX_SourceAdc0CocoA);
    /* ADC0 COCOB is selected as LPIT device trigger input 2 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Lpit, kTRGMUX_TriggerInput2, kTRGMUX_SourceAdc0CocoB);
    /* ADC0 COCOC is selected as LPIT device trigger input 3 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Lpit, kTRGMUX_TriggerInput3, kTRGMUX_SourceAdc0CocoC);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitADC:
- options: {callFromInitBoot: 'true', coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {pin_num: '31', peripheral: ADC0, signal: 'SE, 13', pin_signal: ADC0_SE13/PTD7/LPUART2_TX}
  - {pin_num: '26', peripheral: ADC0, signal: 'SE, 1', pin_signal: ACMP0_IN3/ADC0_SE1/TSI0_CH22/PTE8/FTM0_CH6}
  - {pin_num: '29', peripheral: ADC0, signal: 'SE, 7', pin_signal: ADC0_SE7/ACMP0_IN4/PTC3/FTM0_CH3/FXIO_D7}
  - {pin_num: '32', peripheral: ADC0, signal: 'SE, 11', pin_signal: ADC0_SE11/PTD6/LPUART2_RX}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitADC
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitADC(void)
{
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTC3 (pin 29) is configured as ADC0_SE7 */
    PORT_SetPinMux(PORTC, 3U, kPORT_PinDisabledOrAnalog);

    /* PORTD6 (pin 32) is configured as ADC0_SE11 */
    PORT_SetPinMux(PORTD, 6U, kPORT_PinDisabledOrAnalog);

    /* PORTD7 (pin 31) is configured as ADC0_SE13 */
    PORT_SetPinMux(PORTD, 7U, kPORT_PinDisabledOrAnalog);

    /* PORTE8 (pin 26) is configured as ADC0_SE1 */
    PORT_SetPinMux(PORTE, 8U, kPORT_PinDisabledOrAnalog);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitTRGMUX:
- options: {callFromInitBoot: 'true', coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {peripheral: ADC0, signal: 'TRG, A', pin_signal: LPIT0_CH0}
  - {peripheral: ADC0, signal: 'TRG, B', pin_signal: LPIT0_CH1}
  - {peripheral: ADC0, signal: 'TRG, C', pin_signal: LPIT0_CH2}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitTRGMUX
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitTRGMUX(void)
{

    SIM->ADCOPT = ((SIM->ADCOPT &
                    /* Mask bits to zero which are setting */
                    (~(SIM_ADCOPT_ADC0TRGSEL_MASK | SIM_ADCOPT_ADC0PRETRGSEL_MASK)))

                   /* ADC0 trigger source select: TRGMUX output. */
                   | SIM_ADCOPT_ADC0TRGSEL(ADCOPT_ADC0TRGSEL_TRGMUX)

                   /* ADC0 pre-trigger source select: TRGMUX output. */
                   | SIM_ADCOPT_ADC0PRETRGSEL(ADCOPT_ADC0PRETRGSEL_TRGMUX));
    /* LPIT0 Channel0 is selected as ADC0 device trigger input 0 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Adc0, kTRGMUX_TriggerInput0, kTRGMUX_SourceLpit0Ch0);
    /* LPIT0 Channel1 is selected as ADC0 device trigger input 1 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Adc0, kTRGMUX_TriggerInput1, kTRGMUX_SourceLpit0Ch1);
    /* LPIT0 Channel2 is selected as ADC0 device trigger input 2 */
    TRGMUX_SetTriggerSource(TRGMUX0, kTRGMUX_Adc0, kTRGMUX_TriggerInput2, kTRGMUX_SourceLpit0Ch2);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitCMP:
- options: {callFromInitBoot: 'true', coreID: cm0plus, enableClock: 'true'}
- pin_list:
  - {pin_num: '30', peripheral: CMP0, signal: 'IN, 5', pin_signal: ADC0_SE15/ACMP0_IN5/PTC2/FTM0_CH2/FXIO_D6}
  - {pin_num: '11', peripheral: CMP0, signal: DAC_8bit_VIN1, pin_signal: VDDA}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitCMP
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitCMP(void)
{
    /* Clock Gate Control: Enables the clock. The current clock selection and divider options are locked and cannot be modified. */
    CLOCK_EnableClock(kCLOCK_PortC);

    /* PORTC2 (pin 30) is configured as ACMP0_IN5 */
    PORT_SetPinMux(PORTC, 2U, kPORT_PinDisabledOrAnalog);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
