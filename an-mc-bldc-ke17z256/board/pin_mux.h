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

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

#define PORT_DFER_DFE_3_MASK 0x08u /*!<@brief Digital Filter Enable Mask for item 3. */

/*! @name PORTD3 (number 70), SW2/BUTTON_0
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW2_FGPIO FGPIOD             /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW2_GPIO GPIOD               /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW2_GPIO_PIN_MASK (1U << 3U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW2_PORT PORTD               /*!<@brief PORT peripheral base pointer */
#define BOARD_SW2_PIN 3U                   /*!<@brief PORT pin number */
#define BOARD_SW2_PIN_MASK (1U << 3U)      /*!<@brief PORT pin mask */
                                           /* @} */

/*! @name PORTE14 (number 17), SW3/BUTTON_1
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_SW3_FGPIO FGPIOE              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_SW3_GPIO GPIOE                /*!<@brief GPIO peripheral base pointer */
#define BOARD_SW3_GPIO_PIN_MASK (1U << 14U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_SW3_PORT PORTE                /*!<@brief PORT peripheral base pointer */
#define BOARD_SW3_PIN 14U                   /*!<@brief PORT pin number */
#define BOARD_SW3_PIN_MASK (1U << 14U)      /*!<@brief PORT pin mask */
                                            /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitBUTTONSPins(void);

/*! @name PORTD12 (number 34), D3[3]/RGB_BLUE
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_BLUE_FGPIO FGPIOD              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_BLUE_GPIO GPIOD                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_BLUE_GPIO_PIN_MASK (1U << 12U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_BLUE_PORT PORTD                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_BLUE_PIN 12U                   /*!<@brief PORT pin number */
#define BOARD_LED_BLUE_PIN_MASK (1U << 12U)      /*!<@brief PORT pin mask */
                                                 /* @} */

/*! @name PORTD11 (number 35), D3[4]/RGB_GREEN
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_GREEN_FGPIO FGPIOD              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_GREEN_GPIO GPIOD                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_GREEN_GPIO_PIN_MASK (1U << 11U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_GREEN_PORT PORTD                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_GREEN_PIN 11U                   /*!<@brief PORT pin number */
#define BOARD_LED_GREEN_PIN_MASK (1U << 11U)      /*!<@brief PORT pin mask */
                                                  /* @} */

/*! @name PORTD10 (number 36), D3[1]/RGB_RED
  @{ */

/* Symbols to be used with GPIO driver */
#define BOARD_LED_RED_FGPIO FGPIOD              /*!<@brief FGPIO peripheral base pointer */
#define BOARD_LED_RED_GPIO GPIOD                /*!<@brief GPIO peripheral base pointer */
#define BOARD_LED_RED_GPIO_PIN_MASK (1U << 10U) /*!<@brief GPIO pin mask */

/* Symbols to be used with PORT driver */
#define BOARD_LED_RED_PORT PORTD                /*!<@brief PORT peripheral base pointer */
#define BOARD_LED_RED_PIN 10U                   /*!<@brief PORT pin number */
#define BOARD_LED_RED_PIN_MASK (1U << 10U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLEDsPins(void);

/*! @name PORTB1 (number 53), UART0_TX_TGTMCU
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_UART0_TX_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_UART0_TX_PIN 1U                   /*!<@brief PORT pin number */
#define BOARD_UART0_TX_PIN_MASK (1U << 1U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*! @name PORTB0 (number 54), UART0_RX_TGTMCU
  @{ */

/* Symbols to be used with PORT driver */
#define BOARD_UART0_RX_PORT PORTB               /*!<@brief PORT peripheral base pointer */
#define BOARD_UART0_RX_PIN 0U                   /*!<@brief PORT pin number */
#define BOARD_UART0_RX_PIN_MASK (1U << 0U)      /*!<@brief PORT pin mask */
                                                /* @} */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UARTPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitFTM(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitMISC(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLPIT(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitADC(void);

#define ADCOPT_ADC0PRETRGSEL_TRGMUX 0x01u /*!<@brief ADC0 pre-trigger source select: TRGMUX output */
#define ADCOPT_ADC0TRGSEL_TRGMUX 0x01u    /*!<@brief ADC0 trigger source select: TRGMUX output */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitTRGMUX(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitCMP(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/