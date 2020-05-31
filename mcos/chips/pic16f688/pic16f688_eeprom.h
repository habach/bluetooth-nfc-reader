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
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PIC24FJ256GB106_EEPROM_H
#define	PIC24FJ256GB106_EEPROM_H
#include "../../../Microchip_Solutions/Microchip/Include/DEE_Emulation_16-bit/DEE_Emulation_16-bit.h"
//#include "../i2c3_pic24.h"
/*
 *This device lack built-in EEPROM, hence an alternative solution for non-volatile
 * storage called Emulating Data EEPROM For PIC18/PIC24  (AN1095) implemented
 * and provided by Microchip which is available at:
 * http://www.microchip.com/wwwAppNotes/AppNotes.aspx?appnote=en530593
 * 
 * MCOS has its own EEPROM interface as following headers should be compatible
 * with this solution
 */

#define EEPROM_DATA_WIDTH_BITS 8
#define EEPROM_UNFORMATTED_DATA_VALUE 0xFF
#define eeprom_index_t uint16_t

#ifdef I2C_EEPROM
#define EEPROM_BLOCK_WRITE_SUPPORT 1
#define EEPROM_BLOCK_READ_SUPPORT 1
#define EEPROM_SIZE_IN_BYTES 8192
#else
#define EEPROM_SIZE_IN_BYTES DATA_EE_TOTAL_SIZE //This is provided by MCP lib mentioned above
#endif
//#define EEPGD_SELECTION_BIT EEPGD
#define EEPROM_LOCATION_DATA 0
#define EEPROM_LOCATION_PROGRAM 1
//#define EEPROM_RD EECON1bits.RD
#define RD_ACTIVE 1
//#define EEPROM_WREN EECON1bits.WREN 
#define WREN_ACTIVE 1
//#define EEPROM_WR EECON1bits.WR
#define WR_ACTIVE 1
//#define EEADR_L EEADR
//#define EEADR_H EEADRH
//#define EEDAT_L EEDATA
//#define EEDAT_H EEDATA
//#define EEPROM_FUNCTIONAL_REG EECON2
//#define MEMORY_LOCATION_SELECT CFGS

//#define EEPROM_MEMORY_LOCATION_SELECT(x) EEPGD_SELECTION_BIT=(x)
#ifdef I2C_EEPROM
#define eeprom_writeByte EEPROM_WriteByte //Emulated EEPROM lib from Microchip
#define eeprom_readByte EEPROM_ReadByte
#define eeprom_initialize EEPROM_do_nothing
#else
#define eeprom_writeByte DataEEWrite //Emulated EEPROM lib from Microchip
#define eeprom_readByte DataEERead
#define eeprom_initialize DataEEInit
#endif
#if (EEPROM_BLOCK_WRITE_SUPPORT)
#define eeprom_writeBlock EEPROM_WriteBlock
#endif
#if (EEPROM_BLOCK_READ_SUPPORT)
#define eeprom_readBlock EEPROM_ReadBlock
#endif

typedef unsigned mc_eeprom_size_t;

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

