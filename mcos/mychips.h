/* 
 * File:   mychip.h
 * Author: bnh
 *
 * Created on April 30, 2014, 11:19 AM
 */

#ifndef MYCHIP_H
#define	MYCHIP_H

//#include "application.h"

typedef enum {
    NO = 0, TURN_OFF = 0, digital = 0,
    YES = 1, TURN_ON = 1, analog = 1
} mychip_stuff;

#define MICROCHIP   0
#define ATMEL       1

#define MICROCHIP_PIC18 0
#define MICROCHIP_PIC24 10
#define ATMEGA_8BIT     20

#define PIC18F46K22 1
#define ATMEGA328 21
#define PIC24FJ256GB106 11
#define PIC24FJ1024GB606 12
#define PIC16F688 2

#ifdef _PIC12F675_H_
#define MYCHIP "12F675"
#define PORT_A GPIO
#define TRIS_A TRISIO
#define LED_TRIS TRIS_A
#define ANSELBITS_ANS ANSELbits.ANS
#define ANSELBITS_ADCS ANSELbits.ADCS
#define INTCON_GPIF INTCONbits.GPIF
#define IOC_CON IOC
#define INTCON_GPIE INTCONbits.GPIE
#define INTCON_GIE INTCONbits.GIE
#define ADCONBITS_ADFM ADCON0bits.ADFM
#define ADCONBITS_VCFG ADCON0bits.VCFG
#define  ADCONBITS_ADON ADCON0bits.ADON
#define ADCONBITS_CHS ADCON0bits.CHS
#define ADCONBITS_GO ADCON0bits.GO
#define ADRES_H ADRESH
#define ADRES_L ADRESL
#define INTCON_IOCIF INTCONbits.GPIF
#define COMPARATOR_CON CMCON
#define ANSEL_CON ANSEL
#define VREF_CON VRCON
#define OSCCON_SPLLEN OSCCAL
#define OSCCON_SCS OSCCAL
#define OSCCON_IRCF OSCCAL
#define OSCTUNE OSCCAL

//ADC
#define _2AN_Vref_POSITIVE 5
#define _1AN_0_Vref 0
#define ADC_MAX 1023
#define ADC_10BITS_MIDDLE 512
#define ADC_8BITS 256

#elif defined (_PIC16F1823_H_)
#define MYCHIP "16F1823"
#define PORT_A PORTA
#define TRIS_A TRISA
#define LED_TRIS TRIS_A
#define ANSELBITS_ANS ANSELAbits.ANSELA
#define ANSELBITS_ADCS ADCON1bits.ADCS
#define INTCON_GPIF INTCONbits.IOCIF
#define IOC_CON IOCAN
#define INTCON_GPIE INTCONbits.IOCIE
#define INTCON_GIE INTCONbits.GIE
#define ADCONBITS_ADFM ADCON1bits.ADFM
#define ADCONBITS_VCFG ADCON1bits.ADPREF
#define  ADCONBITS_ADON ADCON0bits.ADON
#define ADCONBITS_CHS ADCON0bits.CHS
#define ADCONBITS_GO ADCON0bits.GO
#define ADRES_H ADRESH
#define ADRES_L ADRESL
#define INTCON_IOCIF INTCONbits.IOCIF
#define COMPARATOR_CON CM1CON0
#define COMPARATOR_CON_1 CM1CON1
#define ANSEL_CON ANSELA
#define ANSEL_CON_2 ANSELC
#define VREF_CON FVRCON
#define OSCCON_SPLLEN OSCCONbits.SPLLEN
#define OSCCON_SCS OSCCONbits.SCS
#define OSCCON_IRCF OSCCONbits.IRCF
#define OSCTUNE OSCTUNEbits.TUN

//UART PIN ASSIGNMENTS
#define TRIS_TX TRISC4
#define TX RC4
#define TRIS_RX TRISC5
#define RX RC5
#define TRIS_DI_RO TRISC3
#define DI_RO RC3

//setup UART module
#define ANSEL_DI_RO_SETUP ANSELCbits.ANSC3=0
#define ALTERNATE_PIN_FUNCTION_RX_SETUP APFCONbits.RXDTSEL=0
#define ALTERNATE_PIN_FUNCTION_TX_SETUP APFCONbits.TXDTSEL=0
#define SPBRG_LENGTH_SETUP BAUDCONbits.BRG16=0
#define BAUDRATE_HISPEED_SETUP TXSTAbits.BRGH=1 //High speed (baudrate = Fosc/[16(n+1)]), BRGH = 1 used for lowspeed: baudrate = Fosc/[64(n+1)]
#define BAUDRATE_CALCULATION SPBRGL=((_XTAL_FREQ/baudrate)/ (TXSTAbits.BRGH?16:64))-1
#define RETURN_IDDLE_STATE return(BAUDCONbits.RCIDL)

//UART part specs
#define RX_FIFO_DEPTH 2
#elif defined _PIC16F688_H_
#define MYCHIP PIC16F688
#define CHIP_SIZE 8
#define POOR_DEVICE 1
#define PORT_A PORTA
#define TRIS_A TRISA
#define LED_TRIS TRIS_A
#define ANSELBITS_ANS ANSEL
#define ANSELBITS_ANS_C ANSEL
#define ANSELBITS_ADCS ADCON1bits.ADCS
#define INTCON_GPIF INTCONbits.RAIF
#define IOC_CON IOC
#define INTCON_GPIE INTCONbits.RAIE
#define INTCON_GIE INTCONbits.GIE
#define ADCONBITS_ADFM ADCON0bits.ADFM
#define ADCONBITS_VCFG ADCON0bits.VCFG
#define  ADCONBITS_ADON ADCON0bits.ADON
#define ADCONBITS_CHS ADCON0bits.CHS
#define ADCONBITS_GO ADCON0bits.GO
#define ADRES_H ADRESH
#define ADRES_L ADRESL
#define INTCON_IOCIF INTCONbits.RAIF
#define COMPARATOR_CON CMCON0
#define COMPARATOR_CON_1 CM1CON1
#define ANSEL_CON ANSELA
#define ANSEL_CON_2 ANSELC
#define VREF_CON FVRCON
#define OSCCON_SPLLEN_ON
#define OSCCON_SCS OSCCONbits.SCS
//#define OSCCON_IRCF_SETUP
#define OSCTUN OSCTUNEbits.TUN

//INTERRUPTS
#define GLOBAL_IE GIE
#define UART_RECEPT_INTERRUPT RCIE
#define UART_RECEPT_INTERRUPT_FLAG RCIF
#define UART_TRANSMISSION_INTERRUPT TXIE
#define PE_IE PEIE

//UART PIN ASSIGNMENTS
#define TRIS_TX TRISC4
#define TX RC4
#define TRIS_RX TRISC5
#define RX RC5
#define TRIS_DI_RO TRISC3
#define DI_RO RC3 //control DI_RO pins of MAX485
#define UART_DI_RO_PIN_DIGITAL_ANALOG_MODE ANSELbits.ANS3 //must define digital mode for DI_RO control pin
#define UART_SYNC_SELECTION_bit SYNC
#define UART_RX_EN CREN
#define UART_TX_EN TXEN
#define UART_ADDRESS_BIT_EN ADDEN
#define UART_EN SPEN
#define UART_RX9_bit RX9
#define UART_TX9_bit TX9
#define UART_FRAMING_ERROR_BIT FERR
#define UART_OVERFLOW_ERROR_BIT OERR
#define UART_RECEPT_FLAG_BIT RCIF
#define UART_RECEIVER_REG RCREG
#define UART_TRANSMITTER_REG TXREG
#define UART_RX_9TH_DATA_BIT RX9D
#define UART_TX_9TH_DATA_BIT TX9D
#define UART_TRANSMITTER_REG_EMPTIED TRMT

//setup UART module
#define UART_TX_RX_DI_RO_TRIS_SETUP TRIS_TX=0,TRIS_RX=1,TRIS_DI_RO=0
#define UART_TX_RX_DI_RO_PORT_DIGITAL_SETUP ANSELbits.ANS3=0
#define UART_SPBRG_LENGTH_SETUP(x) BRG16=(x)
#define UART_BAUDRATE_HISPEED_SETUP(x) BRGH=(x) //High speed (baudrate = Fosc/[16(n+1)]), BRGH = 1 used for lowspeed: baudrate = Fosc/[64(n+1)]
#define UART_BAUDRATE_CALCULATION(x) SPBRG=((_XTAL_FREQ/x)/(BRGH?16:64))-1
#define UART_RETURN_IDDLE_STATE return(RCIDL)
#define RX_IDLE RCIDL


//UART part specs
#define RX_FIFO_DEPTH 2

//EEPROM
#define EEPROM_SIZE_IN_BYTES 256    
//#define EEPROM_ADDRESS_MAX (EEPROM_SIZE_IN_BYTES-1)
#define EEPROM_DATA_WIDTH_BITS 8
//#define EEPROM_DATA_MAX 255

#define EEPGD_SELECTION_BIT EEPGD
#define EEPROM_LOCATION_DATA 0
#define EEPROM_LOCATION_PROGRAM 1
#define EEPROM_RD EECON1bits.RD
#define RD_ACTIVE 1
#define EEPROM_WREN EECON1bits.WREN
#define WREN_ACTIVE 1
#define EEPROM_WR EECON1bits.WR
#define WR_ACTIVE 1
#define EEADR_L EEADR
#define EEADR_H EEADRH
#define EEDAT_L EEDATA
#define EEDAT_H EEDATH
#define EEPROM_FUNCTIONAL_REG EECON2
#define ROM_LOCATION_SELECTOR CFGS
#define EEP_V2
#define EEPROM_MEMORY_LOCATION_SELECT(x) EEPGD_SELECTION_BIT=(x)
//#define EEPROM_DATA_MAX 255
#define eeprom_writeByte eeprom_write //EEPROM_WRITE //eeprom_write
#define eeprom_readByte eeprom_read //EEPROM_READ //eeprom_read
#define eeprom_initialize NOP
#include "chips/pic16f688/pic16f688_uart.h"
#elif defined (_PIC16F877A_H_) || defined (_PIC16F887_H_)
#define MYCHIP "16f877a"
//UART PIN ASSIGNMENTS
#define TRIS_TX TRISC6
#define TX RC6
#define TRIS_RX TRISC7
#define RX RC7
#define TRIS_DI_RO TRISC5
#define DI_RO RC5

//setup UART module
#define ANSEL_DI_RO_SETUP
#define ALTERNATE_PIN_FUNCTION_TX_SETUP
#define ALTERNATE_PIN_FUNCTION_RX_SETUP
#define SPBRG_LENGTH_SETUP
#define BAUDRATE_HISPEED_SETUP TXSTAbits.BRGH=1 //High speed (baudrate = Fosc/[16(n+1)]), BRGH = 1 used for lowspeed: baudrate = Fosc/[64(n+1)]
#define BAUDRATE_CALCULATION SPBRG=((_XTAL_FREQ/baudrate)/ (BRGH?16:64))-1
#define RETURN_IDDLE_STATE return(1)
//baudrate = _XTAL_FREQ/((SPBRG+1)*16)
//UART part specs
#define RX_FIFO_DEPTH 2

//EEPROM
#define EEPROM_ADDRESS_MAX 255
#define EEPGD_SELECTION_BIT EEPGD
#define EEPROM_LOCATION_DATA 0
#define EEPROM_LOCATION_PROGRAM 1
#define EEPROM_RD EECON1bits.RD
#define RD_ACTIVE 1
#define EEPROM_WREN EECON1bits.WREN
#define WREN_ACTIVE 1
#define EEPROM_WR EECON1bits.WR
#define WR_ACTIVE 1
#define EEADR_L EEADR
#define EEADR_H EEADRH
#define EEDAT_L EEDATA
#define EEDAT_H EEDATH
#define EEPROM_FUNCTIONAL_REG EECON2

//INTERRUPTS

#define UART_RECEPT_INTERRUPT RCIE
#define UART_TRANSMISSION_INTERRUPT TXIE
#define IOC_IE RBIE
#define IOC_IF RBIF
#define GLOBAL_IE GIE


//#define IOCB_IE IOCB
#define IOCB_SETUP(x)
#define IOC_INTERRUPT_SWITCH(x) do{GLOBAL_IE=(x);IOC_IE=(x);IOC_IF=0;}while(0)
#define ADC_IE ADIE
#define ADC_IF ADIF
#define TIMER0_IE TMR0IE
#define TIMER0_IF TMR0IF
#define PE_IE PEIE

//BUTTONS, KEYS
#define PULL_UP_RESISTOR_ON OPTION_REGbits.nRBPU=0

//TIMERS
#define T0_PRESCALER OPTION_REGbits.PS

//ADC

#define ANSEL_CONFIG(x) do{ADCON1bits.PCFG=(x);}while(0)

#define ADC_CLOCK_SOURCE_SETUP(x) do {ADCON0bits.ADCS = x;} while(0)
#define _2_AN_1_Vref_P 5
#define _1_AN_0_Vref 14
#define _3_AN 4

#elif defined (_PIC18F4550_H_) || defined (_PIC18F46K20_H_)
#ifdef _PIC18F4550_H_
#define MYCHIP "18f4550"
#else
#define MYCHIP "18f46k20"
#endif

#include <pic18.h>

#define POOR_DEVICE 0
#define CLOCKS_PER_INSTRUCTION 4

//Define whether chips' compiler supports
#include "/chips/pic18f46k20/pic18f46k20_msos.h"
#define VOLATILE_BIT
#define VOLATILE volatile

//STDIO
#include "/chips/pic18f46k20/pic18f46k20_stdio.h"

//UART ACTIVITIES
#include "/chips/pic18f46k20/pic18f46k20_uart.h"

//SPI DRIVER
#include "/chips/pic18f46k20/pic18f46k20_spi.h"



//EEPROM
#ifdef _PIC18F46K20_H_
#define EEPROM_SIZE_IN_BYTES 1024
#else
#define EEPROM_SIZE_IN_BYTES 256    
#endif
#define EEPROM_DATA_WIDTH_BITS 8
#define eeprom_index_t uint8_t

#define EEPGD_SELECTION_BIT EEPGD
#define EEPROM_LOCATION_DATA 0
#define EEPROM_LOCATION_PROGRAM 1
#define EEPROM_RD EECON1bits.RD
#define RD_ACTIVE 1
#define EEPROM_WREN EECON1bits.WREN 
#define WREN_ACTIVE 1
#define EEPROM_WR EECON1bits.WR
#define WR_ACTIVE 1
#define EEADR_L EEADR
#define EEADR_H EEADRH
#define EEDAT_L EEDATA
#define EEDAT_H EEDATA
#define EEPROM_FUNCTIONAL_REG EECON2
#define MEMORY_LOCATION_SELECT CFGS

#define EEPROM_MEMORY_LOCATION_SELECT(x) EEPGD_SELECTION_BIT=(x)
#define eeprom_writeByte DATAEE_WriteByte
#define eeprom_readByte DATAEE_ReadByte

//INTERRUPTS
#include "pic18f46k20/pic18f46k20_interrupt.h"
#include "pic18f46k20/pic18f46k20_timer.h"

//BUTTONS, KEYS
#define PULL_UP_RESISTOR_ON  do{nRBPU=0;}while(0)

//TIMERS
#define T0_PRESCALER T0CONbits.T0PS
#define TIMER0_CLOCK_SOURCE_SELECT T0CS
#define TIMER0_CLOCK_SOURCE_EDGE_SELECT(x) T0SE=(x)
#define TIMER0_PRESCALER_ASSIGN_SETUP PSA=0

#define T1_PRESCALER T1CONbits.T1CKPS
#define TIMER1_CLOCK_SOURCE_SELECT TMR1CS
#define TIMER1_CLOCK_SOURCE_EDGE_SELECT(x)
#define TIMER1_PRESCALER_ASSIGN_SETUP


//ADC
#define ANSEL_CONFIG(x) do{ANS5=0;ANS6=0;ANS7=0;ANSELH=0;}while(0)
#define ADC_CLOCK_SOURCE_SETUP(x) do{ADCON2bits.ADCS=(x);}while(0)
#define ADC_MAX 1023
#define ADC_10BITS_MIDDLE 512
#define ADC_8BITS 256


//DELAY FUNCTIONS DEFINITIONS
//#define DELAY_MS _Delay_ms
#define Delay1TCYx_EXISTS

#elif defined _PIC18F46K22_H_
#define POOR_DEVICE 0
#define CHIP_SIZE 8
#define CLOCKS_PER_INSTRUCTION 4

//Define whether chips' compiler supports
#include "chips/pic18f46k22/pic18f46k22_mcos.h"


//#define VOLATILE_BIT
//#define VOLATILE volatile

//STDIO
#include "chips/pic18f46k22/pic18f46k22_stdio.h"
#include "chips/pic18f46k22/pic18f46k22_uart.h"
#include "chips/pic18f46k22/pic18f46k22_spi.h"

//EEPROM
#include "chips/pic18f46k22/pic18f46k22_eeprom.h"

//INTERRUPTS
#include "chips/pic18f46k22/pic18f46k22_interrupt.h"
#include "chips/pic18f46k22/pic18f46k22_timer.h"
//#include "chips/pic18f46k22/pinmap.h"

//BUTTONS, KEYS
#define PULL_UP_RESISTOR_ON  do{nRBPU=0;}while(0)

//TIMERS
#define T0_PRESCALER T0CONbits.T0PS
#define TIMER0_CLOCK_SOURCE_SELECT T0CS
#define TIMER0_CLOCK_SOURCE_EDGE_SELECT(x) T0SE=(x)
#define TIMER0_PRESCALER_ASSIGN_SETUP PSA=0

#define T1_PRESCALER T1CONbits.T1CKPS
#define TIMER1_CLOCK_SOURCE_SELECT TMR1CS
#define TIMER1_CLOCK_SOURCE_EDGE_SELECT(x)
#define TIMER1_PRESCALER_ASSIGN_SETUP


//ADC
#define ANSEL_CONFIG(x) do{ANS5=0;ANS6=0;ANS7=0;ANSELH=0;}while(0)
#define ADC_CLOCK_SOURCE_SETUP(x) do{ADCON2bits.ADCS=(x);}while(0)
#define ADC_MAX 1023
#define ADC_10BITS_MIDDLE 512
#define ADC_8BITS 256


//DELAY FUNCTIONS DEFINITIONS
//#define DELAY_MS _Delay_ms
#define Delay1TCYx_EXISTS

#elif defined __PIC24FJ256GB106__ || defined __PIC24FJ1024GB606__
#ifndef __PIC24F__
#define __PIC24F__
#endif
#define POOR_DEVICE 0
#define CHIP_SIZE 16
#define CLOCKS_PER_INSTRUCTION 2
//
//#if (CHIP_SIZE==8)
//#define ioports ioports
//#define ioport_t ioPort8_t
//#elif (CHIP_SIZE==16)
//#define ioports io_reg16
//#define ioport_t ioPort16_t
//#else
//#error "No CHIP_SIZE declaration in mychips.h"
//#endif

#if defined __PIC24FJ256GB106__
#define DDRA TRISA
#endif
#define DDRB TRISB
#define DDRC TRISC
#define DDRD TRISD
#define DDRE TRISE
#define DDRF TRISF

#include <libpic30.h>
#define MYCHIP_MANUFACTURER MICROCHIP
#define MYCHIPS MICROCHIP_PIC24
#if defined __PIC24FJ256GB106__
#define MYCHIP PIC24FJ256GB106
#elif defined __PIC24FJ1024GB606__
#define MYCHIP PIC24FJ1024GB606
#endif
#define RTCC_AVAILABLE 1
#if defined __PIC24FJ256GB106__
#include "chips/pic24fj256gb106/pic24fj256gb105_delay.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_eeprom.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_interrupt.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_timer.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_mcos.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_spi.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_stdio.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_timer.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_uart.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_extInterrupt.h"
#include "chips/pic24fj256gb106/pic24fj256gb106_adc.h"
#include "chips/pic24_interrupt.h"
//#include "chips/pic24fj256gb106/pinmap.h"
//#include "chips/pic24fj256gb106/pinmap.h"
#elif defined __PIC24FJ1024GB606__
#include "chips/pic24fj1024gb606/pic24fj1024gb606_delay.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_eeprom.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_interrupt.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_timer.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_mcos.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_spi.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_stdio.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_timer.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_uart.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_extInterrupt.h"
#include "chips/pic24fj1024gb606/pic24fj1024gb606_adc.h"
#include "chips/pic24_interrupt.h"
#endif
//#include "../Microchip Solutions/Microchip/DEE Emulation 16-bit/../Include/DEE Emulation 16-bit/DEE Emulation 16-bit.h"

#elif defined ARDUINO

#ifdef ARDUINO_MEGA2560
#define MYCHIP "ATMEGA2560"
#endif

#define POOR_DEVICE 0
#define CLOCKS_PER_INSTRUCTION 1

//BUTTONS, KEYS
#define PULL_UP_RESISTOR_ON  do{nRBPU=0;}while(0)

//TIMERS
#define T0_PRESCALER T0CONbits.T0PS
#define TIMER0_CLOCK_SOURCE_SELECT T0CS
#define TIMER0_CLOCK_SOURCE_EDGE_SELECT(x) T0SE=(x)
#define TIMER0_PRESCALER_ASSIGN_SETUP PSA=0

#define T1_PRESCALER T1CONbits.T1CKPS
#define TIMER1_CLOCK_SOURCE_SELECT TMR1CS
#define TIMER1_CLOCK_SOURCE_EDGE_SELECT(x)
#define TIMER1_PRESCALER_ASSIGN_SETUP

//ADC
#define ANSEL_CONFIG(x) do{ANS5=0;ANS6=0;ANS7=0;ANSELH=0;}while(0)
#define ADC_CLOCK_SOURCE_SETUP(x) do{ADCON2bits.ADCS=(x);}while(0)
#define ADC_MAX 1023
#define ADC_10BITS_MIDDLE 512
#define ADC_8BITS 256


//DELAY FUNCTIONS DEFINITIONS
//#ifndef delay_ms
//#define delay_ms delay
//#endif
//#define DELAY_MS _Delay_ms
//#define Delay1TCYx_EXISTS

#include "myarduino.h"

#endif

#define SWITCH_ON 1
#define SWITCH_OFF 0
//#ifdef INPUT
//#undef INPUT
//#endif
//#define INPUT 0xff
//
//#ifdef OUTPUT
//#undef OUTPUT
//#endif
//#define OUTPUT 0x00

//uOS BASIC
#define uos_uint16 UINT16

#endif	/* MYCHIP_H */
