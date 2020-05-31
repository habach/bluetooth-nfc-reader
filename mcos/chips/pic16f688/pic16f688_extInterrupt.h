/**
  EXT_INT Generated Driver API Header File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    ext_int.h

  @Summary:
    This is the generated header file for the EXT_INT driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description:
    This header file provides APIs for driver for EXT_INT. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - pic24-dspic-pic32mm : v1.45
        Device            :  PIC24FJ256GB106
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.32
        MPLAB             :  MPLAB X 3.61
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _EXT_INTERRUPT_H
#define _EXT_INTERRUPT_H

/**
    Section: Includes
*/
#include <xc.h>
#include "../../application.h"

// Provide C++ Compatibility
#ifdef __cplusplus  

extern "C" {

#endif

/**
    Section: Macros
*/
/**
  @Summary
    Clears the interrupt flag for INT0

  @Description
    This routine clears the interrupt flag for the external interrupt, INT0.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void __attribute__ ( ( interrupt, no_auto_psv ) ) _INT0Interrupt(void)
    {
        // User Area Begin->code: INT0 - External Interrupt 0

        // User Area End->code: INT0 - External Interrupt 0
        EXT_INT0_InterruptFlagClear();
    }
    </code>

*/
//#define EXT_INT1_InterruptFlagClear()       (IFS1bits.INT1IF = 0)
//#define EXT_INT2_InterruptFlagClear()       (IFS1bits.INT2IF = 0)
//#define EXT_INT3_InterruptFlagClear()       (IFS3bits.INT3IF = 0)
//#define EXT_INT4_InterruptFlagClear()       (IFS3bits.INT4IF = 0)    
/**
  @Summary
    Clears the interrupt enable for INT0

  @Description
    This routine clears the interrupt enable for the external interrupt, INT0.
    After calling this routine, external interrupts on this pin will not be serviced by the 
    interrupt handler, _INT0Interrupt.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Changing the external interrupt edge detect from negative to positive
    <code>
    // clear the interrupt enable
    EXT_INT0_InterruptDisable();
    // change the edge
    EXT_INT0_PositiveEdgeSet();
    // clear the interrupt flag and re-enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
#define EXT_INT1_InterruptDisable()     (CNEN2bits.CN28IE = 0)
#define EXT_INT2_InterruptDisable()     (CNEN2bits.CN29IE = 0)
#define EXT_INT3_InterruptDisable()     (CNEN2bits.CN30IE = 0)
#define EXT_INT4_InterruptDisable()     (CNEN2bits.CN31IE = 0)   
#define EXT_INT5_InterruptDisable()     (CNEN1bits.CN6IE = 0)   
#define EXT_INT6_InterruptDisable()     (CNEN3bits.CN32IE = 0)    
#if (DEV_BOARD == AKS1708A)
#define EXT_INT7_InterruptDisable()     (CNEN1bits.CN15IE = 0)   
#endif
#define EXT_INT8_InterruptDisable()     (CNEN2bits.CN16IE = 0)
    
  
    
/**
  @Summary
    Clears the interrupt enable for INT0

  @Description
    This routine clears the interrupt enable for the external interrupt, INT0.
    After calling this routine, external interrupts on this pin will be serviced by the 
    interrupt handler, _INT0Interrupt.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT0_PositiveEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
#define EXT_INT1_InterruptEnable()       (CNEN2bits.CN28IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)
#define EXT_INT2_InterruptEnable()       (CNEN2bits.CN29IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)
#define EXT_INT3_InterruptEnable()       (CNEN2bits.CN30IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)
#define EXT_INT4_InterruptEnable()       (CNEN2bits.CN31IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)
#define EXT_INT5_InterruptEnable()       (CNEN1bits.CN6IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)
#define EXT_INT6_InterruptEnable()       (CNEN3bits.CN32IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)
#if (DEV_BOARD == AKS1708A)
#define EXT_INT7_InterruptEnable()       (CNEN1bits.CN15IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)
#endif
#define EXT_INT8_InterruptEnable()       (CNEN2bits.CN16IE = 1,IPC4bits.CNIP = 3, IEC1bits.CNIE = 1)

    
/**
  @Summary
    Sets the edge detect of the external interrupt to negative edge.

  @Description
    This routine set the edge detect of the extern interrupt to negative edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a high to low level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle negative edge interrupts
    <code>
    // set the edge
    EXT_INT0_NegativeEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
//#define EXT_INT1_NegativeEdgeSet()          (INTCON2bits.INT1EP = 1)
//#define EXT_INT2_NegativeEdgeSet()          (INTCON2bits.INT2EP = 1)
//#define EXT_INT3_NegativeEdgeSet()          (INTCON2bits.INT3EP = 1)
//#define EXT_INT4_NegativeEdgeSet()          (INTCON2bits.INT4EP = 1)    
/**
  @Summary
    Sets the edge detect of the external interrupt to positive edge.

  @Description
    This routine set the edge detect of the extern interrupt to positive edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a low to high level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT0_PositiveEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
//#define EXT_INT1_PositiveEdgeSet()          (INTCON2bits.INT1EP = 0)
//#define EXT_INT2_PositiveEdgeSet()          (INTCON2bits.INT2EP = 0)
//#define EXT_INT3_PositiveEdgeSet()          (INTCON2bits.INT3EP = 0)
//#define EXT_INT4_PositiveEdgeSet()          (INTCON2bits.INT4EP = 0)    

/**
    Section: External Interrupt Initializers
 */
/**
  @Summary
    Initializes the external interrupt pins

  @Description
    This routine initializes the EXT_INT driver to detect the configured edge, clear
    the interrupt flag and enable the interrupt.

    The following external interrupts will be initialized:
    INT0 - EXT_INT0
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Initialize the external interrupt pins
    <code>
    // 
    EXT_INT_Initialize();
    </code>

*/
//void EXT_INT_Initialize(void);

// Provide C++ Compatibility
#ifdef __cplusplus  

}

#endif
#endif
