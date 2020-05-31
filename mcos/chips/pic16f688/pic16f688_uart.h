/* 
 * File:   pic24fj256gb106_uart.h
 * Author: Administrator PC
 *
 * Created on July 14, 2016, 9:19 PM
 */

#ifndef PIC16F688_UART_H
#define	PIC16F688_UART_H
//#include "../../application.h"
//#include <pic24fj256gb106.h>
//#include <plib/usart.h>
//#include "../../../mcc_generated_files/uart1.h"

//#include "application.h"
//#include "../../ioPort.h"
#include "../../iodev.h"


#define BAUDCONFIG_FAILED_RET -8

#define UART_MODULES 1

//UART PIN ASSIGNMENTS
//MC_UART0
//#define UART0_PORT ((VOLATILE ioPort8_t*)&PORTC)
//#define UART0_TRIS ((VOLATILE ioPort8_t*)&TRISC)
//#define TRIS_TX0 UART0_TRIS->p6
//#define TRIS_RX0 UART0_TRIS->p7
//#define TX0 UART0_PORT->p6
//#define RX0 UART0_PORT->p7
//
//#define TRIS_DI_RO TRISC5
//#define DI_RO LATC5
//#define UART_DI_RO_PIN_DIGITAL_ANALOG_MODE //must define digital mode for DI_RO control pin
//#define UART_SPBRG_16BIT 1
//
//#define UART_SYNC_SELECTION_bit SYNC
//#define UART_RX_EN RCEN
//#define UART_TX_EN TXEN
//#define UART_ADDRESS_BIT_EN ADDEN1
//#define UART_ADDRESS_BIT_EN_1 ADDEN1
//#define UART_ADDRESS_BIT_EN_2 ADDEN2
//#define UART_ADDRESS_BIT_EN_3 
//#define UART_EN SPEN
//#define UART_RX9_bit RX9
//#define UART_TX9_bit TX9
//#define UART_FRAMING_ERROR_BIT FERR1
//#define UART_FRAMING_ERROR_BIT_1 FERR1
//#define UART_FRAMING_ERROR_BIT_2 FERR2
//#define UART_FRAMING_ERROR_BIT_3 0
//
//#define UART_OVERFLOW_ERROR_BIT OERR1
//#define UART_OVERFLOW_ERROR_BIT_1 OERR1
//#define UART_OVERFLOW_ERROR_BIT_2 OERR2
//#define UART_OVERFLOW_ERROR_BIT_3 0
//#define UART_RECEPT_FLAG_BIT RCIF
//#define UART_RECEPT_FLAG_BIT_1 RC1IF
//#define UART_RECEPT_FLAG_BIT_2 RC2IF
//#define UART_RECEPT_FLAG_BIT_3 0
//#define UART_RECEIVER_REG RCREG
//#define UART_TRANSMITTER_REG TXREG
//#define UART_RX_9TH_DATA_BIT RX9D
//#define UART_TX_9TH_DATA_BIT TX9D
//#define UART_TRANSMITTER_REG_EMPTIED TRMT
//#define UART_BRR_FACTOR 2

//setup UART module
//#define ANSEL_DI_RO_SETUP
//#define ALTERNATE_PIN_FUNCTION_TX_SETUP
//#define ALTERNATE_PIN_FUNCTION_RX_SETUP
//#define BAUDRATE_HISPEED_SETUP do{BRGH=1;}while(0) //High speed (baudrate = Fosc/[16(n+1)]), BRGH = 1 used for lowspeed: baudrate = Fosc/[64(n+1)]
//#define BAUDRATE_CALCULATION do{SPBRG=((_XTAL_FREQ/baudrate)/(BRGH?16:64))-1;}while(0)
////#define UART_RETURN_IDDLE_STATE return(RCIDL)
//#define UART_RX_IDLE_FLAG RCIDL1
//#define UART_RX_IDLE_1_FLAG RCIDL1
//#define UART_RX_IDLE_2_FLAG RCIDL2
//#define UART_RX_IDLE_3_FLAG 0
//#define UART_RX_IDLE_4_FLAG 0
//#define UART_DATABITSIZE_0_SETUP(x) NOP()
//#define UART_DATABITSIZE_1_SETUP(x) NOP()
//#define UART_DATABITSIZE_2_SETUP(x) NOP()
//#define UART_DATABITSIZE_3_SETUP(x) NOP()
//
//#define UART_RX_IDDLE_STATE UART_RX_IDDLE_FLAG
//
#define UART_RX_INTERRUPT_1_SWITCH(x) do{UART_RECEPT_INTERRUPT_FLAG=0;UART_RECEPT_INTERRUPT=(x);if((x)){PEIE=1;GLOBAL_IE=1;}}while(0)
//#define UART_RX_INTERRUPT_2_SWITCH(x) do{IFS1bits.U2RXIF=0;IEC1bits.U2RXIE=(x);if((x))IPC7bits.U2RXIP=7;IFS4bits.U2ERIF=0;if((x))IPC16bits.U2ERIP=7;IEC4bits.U2ERIE=(x);}while(0)
//#define UART_RX_INTERRUPT_3_SWITCH(x) do{IFS5bits.U3RXIF=0;IEC5bits.U3RXIE=(x);if((x))IPC20bits.U3RXIP=7;IFS5bits.U3ERIF=0;if((x))IPC20bits.U3ERIP=7;IEC5bits.U3ERIE=(x);}while(0)
//#define UART_RX_INTERRUPT_4_SWITCH(x) do{IFS5bits.U4RXIF=0;IEC5bits.U4RXIE=(x);if((x))IPC22bits.U4RXIP=7;IFS5bits.U4ERIF=0;if((x))IPC21bits.U4ERIP=7;IEC5bits.U4ERIE=(x);}while(0)

//#define UART_TX_INTERRUPT_1_SWITCH(x) do{IFS0bits.U1TXIF=0;IEC0bits.U1TXIE=(x);if((x))PEIE=1;}while(0)
//#define UART_TX_INTERRUPT_2_SWITCH(x) NOP()
//#define UART_TX_INTERRUPT_3_SWITCH(x) NOP()
//#define UART_TX_INTERRUPT_4_SWITCH(x) NOP()
//
//#define UART_9BIT_MODE_0_SWITCH(x) do{TXSTAbits.TX9 = (x);RCSTAbits.RX9 = (x);}while(0)
//#define UART_9BIT_MODE_1_SWITCH(x) do{TXSTAbits.TX9 = (x);RCSTAbits.RX9 = (x);}while(0)
//#define UART_9BIT_MODE_2_SWITCH(x) do{TXSTA2bits.TX9 = (x);RCSTA2bits.RX9 = (x);}while(0)
//#define UART_9BIT_MODE_3_SWITCH(x) NOP()
//
//#define UART_ADDRESS_DETECTION_0_SWITCH(x) RCSTAbits.ADEN=(x)
//#define UART_ADDRESS_DETECTION_1_SWITCH(x) RCSTAbits.ADEN=(x)
//#define UART_ADDRESS_DETECTION_2_SWITCH(x) RCSTA2bits.ADEN=(x)
//#define UART_ADDRESS_DETECTION_3_SWITCH(x) NOP()
#define UART_BAUDRATE_1_SETUP(x) UART1_BAUDCONFIG((x)) //NOP()
//#define UART_BAUDRATE_2_SETUP(x) PIC16F688_UART2_BAUDCONFIG((x))
//#define UART_BAUDRATE_3_SETUP(x) PIC16F688_UART3_BAUDCONFIG((x))
//#define UART_BAUDRATE_4_SETUP(x) PIC16F688_UART4_BAUDCONFIG((x))
//#define UART_RX_0_SWITCH(x) do{PIR1bits.RC1IF=0;PIE1bits.RC1IE=(x);}while(0)
//#define UART_RX_1_SWITCH(x) do{PIR1bits.RC1IF=0;PIE1bits.RC1IE=(x);}while(0)
//#define UART_RX_2_SWITCH(x) do{RC2IF=0;RC2IE=(x);}while(0)
//#define UART_RX_3_SWITCH(x) NOP()
//
////UART part specs
//#define RX_FIFO_DEPTH 2
//
//#define UART_TX_RX_DI_RO_TRIS_SETUP do{TRIS_TX=1;TRIS_RX=1;TRIS_DI_RO=0;}while(0)
//#define UART_TX_RX_DI_RO_PORT_DIGITAL_SETUP
//#define UART_SPBRG_LENGTH_SETUP(x) BRG16=(x)
//#define UART_BAUDRATE_HISPEED_SETUP(x) do{BRGH=(x);}while(0)


//UART ACTIVITIES
#define UART1_OPEN() do{UART_EN=1;UART_RX_EN = 1;UART_TX_EN = 1;UART_TX_RX_DI_RO_TRIS_SETUP;UART_TX_RX_DI_RO_PORT_DIGITAL_SETUP;}while(0)
//#define UART2_OPEN() do{U2MODE=(0x8008 & ~(1<<15));U2STA = 0x0000;U2MODEbits.UARTEN = 1;U2STAbits.UTXEN = 1;}while(0)
//#define UART3_OPEN() do{U3MODE=(0x8008 & ~(1<<15));U3STA = 0x0000;U3MODEbits.UARTEN = 1;U3STAbits.UTXEN = 1;}while(0)
//#define UART4_OPEN() do{U4MODE=(0x8008 & ~(1<<15));U4STA = 0x0000;U4MODEbits.UARTEN = 1;U4STAbits.UTXEN = 1;}while(0)
#define UART1_CLOSE() do{UART_EN=0;UART_RX_EN = 0;UART_TX_EN = 0;}while(0)
//#define UART2_CLOSE() do{IEC1bits.U2TXIE = 0;IEC1bits.U2RXIE = 0;U2MODEbits.UARTEN = 0;U2STAbits.UTXEN = 0;}while(0)
//#define UART3_CLOSE() do{IEC5bits.U3TXIE = 0;IEC5bits.U3RXIE = 0;U3MODEbits.UARTEN = 0;U3STAbits.UTXEN = 0;}while(0)
//#define UART4_CLOSE() do{IEC5bits.U4TXIE = 0;IEC5bits.U4RXIE = 0;U4MODEbits.UARTEN = 0;U4STAbits.UTXEN = 0;}while(0)
//#define UART1_READ UART1_Read
//#define UART2_READ UART2_read
//#define UART3_READ UART3_read
//#define UART4_READ UART4_read
//#define UART1_write(x) UART1_Write((x))
//#define UART2_write(x) UART2_Write((x)) 
//#define UART3_write(x) UART3_Write((x)) 
//#define UART4_write(x) UART4_Write((x)) 
//#define PIC16F688_UART1_LOAD_BRG(x) do{U1BRG=(x);}while(0)
//#define UART0_busy() !TXSTAbits.TRMT
//#define UART1_busy() TRMT1
//#define UART2_busy() TRMT2
//#define UART3_busy() 0
//#define UART0_dataReady() UART_RECEPT_FLAG_BIT
//#define UART1_dataReady() UART_RECEPT_FLAG_BIT_1
//#define UART2_dataReady() UART_RECEPT_FLAG_BIT_2
//#define UART3_dataReady() UART_RECEPT_FLAG_BIT_3

//error_code_t pic24fj256gb106_baudconfig(unsigned char uartNo, unsigned long baud);

typedef struct {
    error_code_t (*config)(long baudrate, bool rxint);
}uart_cfgfunc;

extern low_iofuncs UART_LOW_IOF[UART_MODULES];
extern uart_cfgfunc UART_LOW_CONFIG[UART_MODULES];

long uart_brr_calculate(long baudrate);
long uart_baud_calculate(long brr);
long uart_baudErrorCalculate(long baudrate, long brr);
error_code_t UART1_BAUDCONFIG(long baudrate);
//error_code_t PIC16F688_UART2_BAUDCONFIG(long baudrate);
//error_code_t PIC16F688_UART3_BAUDCONFIG(long baudrate);
//error_code_t PIC16F688_UART4_BAUDCONFIG(long baudrate);
//void UART1_Close();
//void UART2_Close();
//void UART3_Close();
//void UART4_Close();
void UART1_Power(bool s);
//void UART2_Power(bool s);
//void UART3_Power(bool s);
//void UART4_Power(bool s);
error_code_t UART1_Config(long baudrate, bool rxint);
//error_code_t UART2_Config(long baudrate, bool rxint);
//error_code_t UART3_Config(long baudrate, bool rxint);
//error_code_t UART4_Config(long baudrate, bool rxint);
char UART1_Read();
//char UART2_Read();
//char UART3_Read();
//char UART4_Read();
void UART1_Write(char byte);
//void UART2_Write(char byte);
//void UART3_Write(char byte);
//void UART4_Write(char byte);

#endif	/* PIC16F688_UART_H */

