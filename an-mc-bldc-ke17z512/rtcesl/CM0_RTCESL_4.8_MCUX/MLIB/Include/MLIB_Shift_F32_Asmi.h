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
* @brief  Shift
* 
*******************************************************************************/
#ifndef _MLIB_SHIFT_F32_ASM_H_
#define _MLIB_SHIFT_F32_ASM_H_

#if defined(__cplusplus)
extern "C" {
#endif

/*******************************************************************************
* Includes
*******************************************************************************/
#include "mlib_types.h"

/*******************************************************************************
* Macros
*******************************************************************************/  
#define MLIB_Sh1LSat_F32_Asmi(f32Val)       MLIB_Sh1LSat_F32_FAsmi(f32Val)
#define MLIB_ShLSat_F32_Asmi(f32Val, u16Sh) MLIB_ShLSat_F32_FAsmi(f32Val, u16Sh)

/***************************************************************************//*!
*
* This function returns the f32Val input shifted by 1 to the left. 
* The function saturates the output.
*              
*******************************************************************************/ 
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_suppress=Pe549                /* Suppresses the Pe549 warning for IAR compiler*/
#endif
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac32_t MLIB_Sh1LSat_F32_FAsmi(register frac32_t f32Val)
{
    register frac32_t f32TestVal=0, f32Out=0;

    #if defined(__CC_ARM)                                  /* For ARM Compiler */
        __asm volatile{ mov f32TestVal, f32Val             /* f32TestVal = f32Val */
                        lsls f32Out, f32Val, #1            /* f32Out = f32Val << 1 */
                        eors f32Val, f32Val, f32Out        /* f32Val = f32Val ^ f32Out */
                        bpl SatEnd                         /* If f32Val >= 0, then goes to SatEnd*/
                        movs f32Out, #128                  /* f32Out = 0x80 */
                        rev f32Out, f32Out                 /* f32Out = 0x80000000 */
                        cmp f32TestVal, #0                 /* Compares input value with 0 */
                        blt SatEnd                         /* If f32TestVal < 0, then goes to SatEnd */
                        subs f32Out, f32Out, #1           /* Else f32Out = 0x00007FFF*/
                    SatEnd: }
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "mov %2, %1 \n\t"                  /* f32TestVal = f32Val */
                        "lsls %0, %1, #1 \n\t"             /* f32Out = f32Val << 1 */
                        "eors %1, %1, %0 \n\t"             /* f32Val = f32Val ^ f32Out */
                        "bpl MLIB_Sh1LSat_F32_SatEnd%= \n\t" /* If f32Val >= 0, then jumps to the end of function*/
                        "movs %0, #128 \n\t"               /* f32Out = 0x80 */
                        "rev %0, %0 \n\t"                  /* f32Out = 0x80000000 */
                        "cmp %2, #0 \n\t"                  /* Compares input value with 0 */
                        "blt MLIB_Sh1LSat_F32_SatEnd%= \n\t" /* If f32TestVal < 0, then jumps through next command */
                        "subs %0, %0, #1 \n\t"
					"MLIB_Sh1LSat_F32_SatEnd%=: \n\t" 
                        : "=l"(f32Out), "+l"(f32Val), "+l"(f32TestVal):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax unified \n"           /* Using unified asm syntax */
                        #endif
                        "mov %2, %1 \n"                    /* f32TestVal = f32Val */
                        "lsls %0, %1, #1 \n"               /* f32Out = f32Val << 1 */
                        "eors %1, %1, %0 \n"               /* f32Val = f32Val ^ f32Out */
                        "bpl .+12 \n"                      /* If f32Val >= 0, then jumps to the end of function*/
                        "movs %0, #128 \n"                 /* f32Out = 0x80 */
                        "rev %0, %0 \n"                    /* f32Out = 0x80000000 */
                        "cmp %2, #0 \n"                    /* Compares input value with 0 */
                        "blt .+4 \n"                       /* If f32TestVal < 0, then jumps through next command */
                        "subs %0, %0, #1 \n"   
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax divided \n"           /* Else f32Out = 0x00007FFF*/
                        #endif
                        : "=l"(f32Out), "+l"(f32Val), "+l"(f32TestVal):);
    #endif

    return f32Out;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_default=Pe549
#endif

/***************************************************************************//*!
*
* This function returns the f32Val input shifted by the number of u16Sh to the left. 
* The function saturates the output.
*             
*******************************************************************************/  
#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_suppress=Pe549                /* Suppresses the Pe549 warning for IAR compiler*/
#endif
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_SAVE
RTCESL_INLINE_OPTIM_SET
static inline frac32_t MLIB_ShLSat_F32_FAsmi(register frac32_t f32Val, register uint16_t u16Sh)
{
    register frac32_t f32SatVal=0, f32CmpVal=0;

    #if defined(__CC_ARM)                                  /* For ARM Compiler */
        __asm volatile{ movs f32SatVal, #128               /* f32SatVal = 0x80 */
                        rev f32SatVal, f32SatVal           /* f32SatVal = 0x80000000 */
                        subs f32CmpVal, f32SatVal, #1      /* f32CmpVal = 0x7FFFFFFF */
                        asrs f32CmpVal, f32CmpVal, u16Sh   /* f32CmpVal = f32CmpVal >> u16Sh */
  
                        cmp f32Val, f32CmpVal              /* Compares f32Val with (0x7FFFFFFF >> u16Sh) */
                        ble NegTest                        /* If f32Val <= f32CmpVal, then goes to NegTest */
                        subs f32Val, f32SatVal, #1         /* f32Val = 0x7FFFFFFF */
                        b SatEnd  
                    NegTest:  
                        mov f32CmpVal, f32SatVal           /* f32CmpVal = 0x80000000 */
                        asrs f32CmpVal, f32CmpVal, u16Sh   /* f32CmpVal = f32CmpVal >> u16Sh */
  
                        cmp f32Val, f32CmpVal              /* Compares f32Val with (0x80000000 >> u16Sh) */
                        bgt NotSat                         /* If f32Val <= f32CmpVal, then goes to NotSat */
                        mov f32Val, f32SatVal              /* f32Val = 0x80000000 */
                        b SatEnd  
                    NotSat:  
                        lsls f32Val, f32Val, u16Sh         /* f32CmpVal = f32CmpVal << u16Sh */
                    SatEnd: }
    #elif defined(__GNUC__) && defined(__ARMCC_VERSION) 
        __asm volatile(
                        "movs %3, #128 \n\t"               /* f32SatVal = 0x80 */
                        "rev %3, %3 \n\t"                  /* f32SatVal = 0x80000000 */
                        "subs %2, %3, #1 \n\t"             /* f32CmpVal = 0x7FFFFFFF */
                        "asrs %2, %2, %1 \n\t"             /* f32CmpVal = f32CmpVal >> u16Sh */
  
                        "cmp %0, %2 \n\t"                  /* Compares f32Val with (0x7FFFFFFF >> u16Sh) */
                        "ble MLIB_ShLSat_F32_NegTest%= \n\t" /* If f32Val <= f32CmpVal, then jumps through two commands */
                        "subs %0, %3, #1 \n\t"             /* f32Val = 0x7FFF */
                        "b MLIB_ShLSat_F32_SatEnd%= \n\t"  
                    "MLIB_ShLSat_F32_NegTest%=: \n\t"  
                        "mov %2, %3 \n\t"                  /* f32CmpVal = 0x80000000 */
                        "asrs %2, %2, %1 \n\t"             /* f32CmpVal = f32CmpVal >> u16Sh */
  
                        "cmp %0, %2 \n\t"                  /* Compares f32Val with (0x80000000 >> u16Sh) */
                        "bgt MLIB_ShLSat_F32_NotSat%= \n\t"  /* If f32Val < f32CmpVal, then jumps through two commands */
                        "mov %0, %3 \n\t"                  /* f32Val = 0x80000000 */
                        "b MLIB_ShLSat_F32_SatEnd%= \n\t"  
                    "MLIB_ShLSat_F32_NotSat%=: \n\t"  
                        "lsls %0, %0, %1 \n\t"             /* f32CmpVal = f32CmpVal << u16Sh */
                    "MLIB_ShLSat_F32_SatEnd%=: \n\t"
                        : "+l"(f32Val), "+l"(u16Sh), "+l"(f32CmpVal), "+l"(f32SatVal):);
    #else
        __asm volatile(
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax unified \n"           /* Using unified asm syntax */
                        #endif  
                        "movs %3, #128 \n"                 /* f32SatVal = 0x80 */
                        "rev %3, %3 \n"                    /* f32SatVal = 0x80000000 */
                        "subs %2, %3, #1 \n"               /* f32CmpVal = 0x7FFFFFFF */
                        "asrs %2, %2, %1 \n"               /* f32CmpVal = f32CmpVal >> u16Sh */
  
                        "cmp %0, %2 \n"                    /* Compares f32Val with (0x7FFFFFFF >> u16Sh) */
                        "ble .+6 \n"                       /* If f32Val <= f32CmpVal, then jumps through two commands */
                        "subs %0, %3, #1 \n"               /* f32Val = 0x7FFF */
                        "b .+16 \n"  
  
                        "mov %2, %3 \n"                    /* f32CmpVal = 0x80000000 */
                        "asrs %2, %2, %1 \n"               /* f32CmpVal = f32CmpVal >> u16Sh */
  
                        "cmp %0, %2 \n"                    /* Compares f32Val with (0x80000000 >> u16Sh) */
                        "bgt .+6 \n"                       /* If f32Val < f32CmpVal, then jumps through two commands */
                        "mov %0, %3 \n"                    /* f32Val = 0x80000000 */
                        "b .+4 \n"  
                        "lsls %0, %0, %1 \n"               /* f32CmpVal = f32CmpVal << u16Sh */
                        #if defined(__GNUC__)              /* For GCC compiler */
                            ".syntax divided \n"
                        #endif
                        : "+l"(f32Val), "+l"(u16Sh), "+l"(f32CmpVal), "+l"(f32SatVal):);
    #endif

    return f32Val;
}
/* inline function without any optimization (compilation issue) */ 
RTCESL_INLINE_OPTIM_RESTORE 

#if defined(__IAR_SYSTEMS_ICC__)           /* IAR compiler */
#pragma diag_default=Pe549
#endif

#if defined(__cplusplus)
}
#endif

#endif /* _MLIB_SHIFT_F32_ASM_H_ */