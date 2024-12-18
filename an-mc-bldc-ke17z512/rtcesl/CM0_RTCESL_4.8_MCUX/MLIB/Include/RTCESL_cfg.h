/*******************************************************************************
*
* Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
* Copyright 2016-2021, 2024 NXP
*
* NXP Proprietary. This software is owned or controlled by NXP and may
* only be used strictly in accordance with the applicable license terms. 
* By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that
* you have read, and that you agree to comply with and are bound by,
* such license terms.  If you do not agree to be bound by the applicable
* license terms, then you may not retain, install, activate or otherwise
* use the software.
* 
*
****************************************************************************//*!
*
* @brief  RTCESL configuration file
* 
*******************************************************************************/
#ifndef _RTCESL_CFG_H_
#define _RTCESL_CFG_H_

#if defined(__cplusplus)
extern "C" {
#endif

    
/*******************************************************************************
* RTCESL vesion 
*******************************************************************************/  
/* RTCESL version is 4.7 */  
#define RTCESL_VERSION 4.7

    
/*******************************************************************************
* Macros 
*******************************************************************************/  
#define RTCESL_ON 1
#define RTCESL_OFF 0    
    
/*******************************************************************************
* User Modified Macros 
*******************************************************************************/     
/* Memory-Mapped Divide and Square Root Module (MMDVSQ) RTCESL_ON/RTCESL_OFF   
*  configuration. It is recommended to use MMDVSQ for KV1x devices, because Div,  
*  Rcp and Sqrt operations are quicker. */
    
/* The MMDVSQ can be enabled or disabled by the definition of the symbol in IDE
*  preprocessor setting.
*  To enable MMDVSQ module please define symbol: RTCESL_MMDVSQ_ON, to disable the MMDVSQ please
*  define RTCESL_MMDVSQ_OFF (Div,Rcp of Sqrt functions which use them  will be
*  calculated by core).
*  If no symbol RTCESL_MMDVSQ_XXX is defined the RTCESL_MMDVSQ setting will be taken from 
*  this header file, see next paragraph. */
    
#if (defined (RTCESL_MMDVSQ_ON))   
    #define RTCESL_MMDVSQ RTCESL_ON
#elif (defined (RTCESL_MMDVSQ_OFF))
    #define RTCESL_MMDVSQ RTCESL_OFF
#else    
    /* User option to enable or disable MMDVSQ module when IDE preprocessor setting 
    *  was not used. Set the following define as RTCESL_ON or RTCESL_OFF to enable or  
    *  disable hardware MMDVSQ support. */  
    
    /* Next line can be modified by user */
    #define RTCESL_MMDVSQ RTCESL_OFF     
    
    /* Independent function call can be used as well, for example
    *  MLIB_Div_F16 ... depend on setting
    *  MLIB_DivHw_F16_C always make calculation in MMDVSQ module
    *  MLIB_Div_F16_Ci always make calculation in core */ 
#endif     

/* Warning if RTCESL_MMDVSQ was not correctly defined */   
#ifndef RTCESL_MMDVSQ 
    #warning "RTCESL_MMDVSQ was not defined !" 
#endif    
/* Warning if RTCESL_MMDVSQ_ON and RTCESL_MMDVSQ_OFF are defined in IDE */       
#if defined(RTCESL_MMDVSQ_ON) && defined(RTCESL_MMDVSQ_OFF)    
    #warning "RTCESL_MMDVSQ_ON and RTCESL_MMDVSQ_OFF are defined !" 
#endif       
    
/* Inline assembler function optimization setting */  
/* Only for functions written as inline assembler. The setting can be changed, but the RTCESL was tested
   with following original setting. In case of any change the functionality is not guaranteed.  */ 
   
#if defined(__IAR_SYSTEMS_ICC__)                         /* For IAR compiler   */
    #define RTCESL_INLINE_OPTIM_SAVE                     /* Save original level - no value */
    #define RTCESL_INLINE_OPTIM_SET                      /* Set specific level */
    #define RTCESL_INLINE_OPTIM_RESTORE                  /* Restore original level - no value*/
#elif defined(__CC_ARM)                                  /* For ARM(KEIL) version < 6 compiler */
    #define RTCESL_INLINE_OPTIM_SAVE                     /* Save original level - no value */
    #define RTCESL_INLINE_OPTIM_SET                      /* Set specific level */
    #define RTCESL_INLINE_OPTIM_RESTORE                  /* Restore original level - no value*/
#elif defined(__GNUC__) && defined(__ARMCC_VERSION)            /* For ARM(KEIL) version >= 6 compiler */ 
    #define RTCESL_INLINE_OPTIM_SAVE                     /* Save original level - no value */
    #define RTCESL_INLINE_OPTIM_SET                      /* Set specific level */
    #define RTCESL_INLINE_OPTIM_RESTORE                  /* Restore original level - no value*/
#elif defined(__GNUC__)                                             /* For GCC compiler */ 
    #define RTCESL_INLINE_OPTIM_SAVE                     /* Save original level - no value */
    #define RTCESL_INLINE_OPTIM_SET                      /* Set specific level */
    #define RTCESL_INLINE_OPTIM_RESTORE                  /* Restore original level - no value*/
#else                                                    /* Other compiler used */
    #warning "Unsupported compiler/IDE used !"    
#endif         

#define RAM_FUNC_LIB                              /* function executed from ROM */

#if defined(__cplusplus)
}
#endif

#endif  /*_RTCESL_CFG_H_*/
