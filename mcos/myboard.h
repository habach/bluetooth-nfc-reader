/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: Ha Bach
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MY_BOARD_H
#define	MY_BOARD_H

/************SELECT BOARD************/
#ifdef __PIC24FJ1024GB606__
#define DEV_BOARD AKS1708A_BT
#elif defined __PIC24FJ256GB106__
#define DEV_BOARD AKS1708A
#elif defined __PIC16F688__
#define DEV_BOARD XMODBUS
#else
#define DEV_BOARD XMODBUS_V1

#endif
/************************************/

/************************************/
#if (DEV_BOARD==AKS1708A || DEV_BOARD==AKS1708A_BT)
#define BUSY_LED LATFbits.LATF0
#define BUSY_LED_READ PORTFbits.RF0;
#define BUSY_LED_DIR TRISFbits.TRISF0
#define BUSY_ON 1
#define BUSY_OFF 0
#define CC1101_DEFAULT_SETTING_RXDATA_PIN 21
#define CC1101_DEFAULT_SETTING_LED_PIN 11
#if (DEV_BOARD == AKS1708A)
#include "../mcc_generated_files/board_manager_aks1708a.h"
#else
#include "../mcc_generated_files/board_manager_aks1708a_bt.h"
#endif
#elif (DEV_BOARD == GENERICBOARD)
#include "board_manager_generic.h"
#elif (DEV_BOARD == XMODBUS_V1)
#if defined _PIC16F688_H_
#include "chips/pic16f688/board_manager_generic.h"
#elif defined _PIC18F46K22_H_
#include "chips/pic18f46k22/mcc.h"
#endif
#else
#error "No board manager!"
#endif

#endif	/* XC_HEADER_TEMPLATE_H */

