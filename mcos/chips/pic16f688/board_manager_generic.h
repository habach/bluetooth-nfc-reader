/**
  System Interrupts Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC24FJ256GB106
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.32
        MPLAB             :  MPLAB X 3.61

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#ifndef _BOARD_MANAGER_GENERIC_BT_H
#define _BOARD_MANAGER_GENERIC_BT_H
/**
    Section: Includes
*/
#include <xc.h>

#include <xc.h>
//#include "board_manager_aks1708a.h"
#include <stdint.h>
#include <stdbool.h>
#ifndef SPI_SLAVE
//#include "spi1_master.h"
#else
#include "spi1_slave.h"
#endif
//#include "uart1.h"
//#include "uart2.h"
//#include "uart3.h"
//#include "ic1.h"
//#include "adc1.h"
//#include "interrupt_manager.h"
//#include "tmr1.h"
//#include "tmr2.h"
//#include "tmr3.h"
//#include "rtcc.h"
#if (MYCHIP == PIC24FJ1024GB606)
//#include "i2c3.h"
#endif

#define _XTAL_FREQ  8000000l
#define FCY 2000000l

#define CMCON_SETUP 7
//#define LED_TRIS_SETUP 0b001011 //TODO TEMPORARILY SET RA2 = input
#define ANSEL_SETUP ANSELBITS_ANS=0b000000000 //RC0 work in analog mode
#define ANSEL_C_SETUP ANSELBITS_ANS_C=0b00010000 //identical as ANSELA because there is only one ANSEL reg for both configuring analog port A & C
#define ADC_CLOCK_SETUP 0
#define IOC_SETUP 0b000100 //RA2 IOC interrupt enabled
#define VREF_VDD 0 //Vref for ADC set to Vdd
#define OSCCON_IRCF_SETUP
#define OSCCON_FREQUENCY_SETUP OSCCONbits.IOSCF=7

void SYSTEM_Initialize(void);
void OSCILLATOR_Initialize(void);
void BOARD_Initialize(void);
void ADC1_Initialize();
void INTERRUPT_Initialize();

#endif
