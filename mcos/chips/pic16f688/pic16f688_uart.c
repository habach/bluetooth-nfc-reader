/*
 * File:   pic24fj256gb106_uart.c
 * Author: Administrator PC
 *
 * Created on July 15, 2016, 5:59 PM
 */


#include <xc.h>
#include "../../application.h"
//#include <pic16f688.h>
//#include "../../error.h"
#include "pic16f688_uart.h"
//#if (DEV_BOARD == AKS1708A)
////#include "../../../mcc_generated_files/board_manager_aks1708a.h"
//#elif (DEV_BOARD == AKS1708A_BT)
//#include "../../../mcc_generated_files/board_manager_aks1708a_bt.h"
//#elif (DEV_BORD == GENERIC_DEV_BOARD)
//#include "../../board_manager_generic.h"
//#else
//#error "No board declaration!"
//#endif
#include <stdlib.h>

low_iofuncs UART_LOW_IOF[UART_MODULES] = {
    {UART1_Power,UART1_Read,UART1_Write} 
#if( UART_MODULES > 1)    
    ,{UART2_Power,UART2_Read,UART2_Write} 
    ,{UART3_Power,UART3_Read,UART3_Write}
    ,{UART4_Power,UART4_Read,UART4_Write}
#endif
};
uart_cfgfunc UART_LOW_CONFIG[UART_MODULES] = {{UART1_Config}};

long uart_brr_calculate(long baudrate) {
//    return ((FCY / (baudrate * 4)) - 1);
    return ((_XTAL_FREQ/baudrate)/(BRGH?16:64))-1;
}

long uart_baud_calculate(long brr) {
    return (FCY / ((brr + 1) * 4));
}

long uart_baudErrorCalculate(long baudrate, long brr) {
    return labs((uart_baud_calculate(brr) - baudrate));
}

error_code_t UART1_BAUDCONFIG(long baudrate) {
    long brr, error, error1;
//    CREN1 = 1; //Enables continuous reception
    BRGH = 1; //Enables hi-speed baudrate (almost nowadays application use hi-speed baudrate)
    BRG16 = 0;
    SYNC = 0; //Asynchronous Mode
    brr = uart_brr_calculate(baudrate);
    if (brr < 0) {
        return BAUDCONFIG_FAILED_RET;
    }
    error = uart_baudErrorCalculate(baudrate, brr);
    error1 = uart_baudErrorCalculate(baudrate, brr + 1);
    if ( error1 < error) brr++;
    SPBRG = brr;
    return 0;
}

#if (UART_MODULES > 1)
error_code_t UART2_BAUDCONFIG(long baudrate) {
    long brr, error, error1;
    U2STA = 0; // Reset USART registers to POR state    
//    CREN1 = 1; //Enables continuous reception
    U2MODEbits.BRGH = 1; //Enables hi-speed baudrate (almost nowadays application use hi-speed baudrate)
//    BRG161 = 1; //Enables 16-bit (SPBRG register)
    brr = uart_brr_calculate(baudrate);
    if (brr < 0) {
        return PIC16F688_BAUDCONFIG_FAILED_RET;
    }
    error = uart_baudErrorCalculate(baudrate, brr);
    error1 = uart_baudErrorCalculate(baudrate, brr + 1);
    if ( error1 < error) brr++;
    U2BRG = brr;
    return 0;
}

error_code_t UART3_BAUDCONFIG(long baudrate) {
    long brr, error, error1;
    U3STA = 0; // Reset USART registers to POR state    
//    CREN1 = 1; //Enables continuous reception
    U3MODEbits.BRGH = 1; //Enables hi-speed baudrate (almost nowadays application use hi-speed baudrate)
//    BRG161 = 1; //Enables 16-bit (SPBRG register)
    brr = uart_brr_calculate(baudrate);
    if (brr < 0) {
        return PIC16F688_BAUDCONFIG_FAILED_RET;
    }
    error = uart_baudErrorCalculate(baudrate, brr);
    error1 = uart_baudErrorCalculate(baudrate, brr + 1);
    if ( error1 < error) brr++;
    U3BRG = brr;
    return 0;
}

error_code_t UART4_BAUDCONFIG(long baudrate) {
    long brr, error, error1;
    U4STA = 0; // Reset USART registers to POR state    
//    CREN1 = 1; //Enables continuous reception
    U4MODEbits.BRGH = 1; //Enables hi-speed baudrate (almost nowadays application use hi-speed baudrate)
//    BRG161 = 1; //Enables 16-bit (SPBRG register)
    brr = uart_brr_calculate(baudrate);
    if (brr < 0) {
        return PIC16F688_BAUDCONFIG_FAILED_RET;
    }
    error = uart_baudErrorCalculate(baudrate, brr);
    error1 = uart_baudErrorCalculate(baudrate, brr + 1);
    if ( error1 < error) brr++;
    U4BRG = brr;
    return 0;
}
#endif

//void UART1_Close() {UART1_CLOSE();}
//void UART2_Close() {UART2_CLOSE();}
//void UART3_Close() {UART3_CLOSE();}
//void UART4_Close() {UART4_CLOSE();}
//void UART1_Open() {UART1_OPEN();}
//void UART2Open() {UART2_OPEN();}
//void UART3Open() {UART3_OPEN();}
//void UART4Open() {UART4_OPEN();}

void UART1_Power(bool s) {
    if (s) UART1_OPEN(); else UART1_CLOSE();
}
#if( UART_MODULES > 1)
void UART2_Power(bool s) {
    if (s) UART2_OPEN(); else UART2_CLOSE();
}

void UART3_Power(bool s) {
    if (s) UART3_OPEN(); else UART3_CLOSE();
}

void UART4_Power(bool s) {
    if (s) UART4_OPEN(); else UART4_CLOSE();
}
#endif

error_code_t UART1_Config(long baudrate, bool rxint) {
    UART_RX_INTERRUPT_1_SWITCH(rxint);
    return UART1_BAUDCONFIG(baudrate);
}
#if( UART_MODULES > 1)
error_code_t UART2_Config(long baudrate, bool rxint) {
    UART_RX_INTERRUPT_2_SWITCH(rxint);
    return UART2_BAUDCONFIG(baudrate);
}

error_code_t UART3_Config(long baudrate, bool rxint) {
    UART_RX_INTERRUPT_3_SWITCH(rxint);
    return UART3_BAUDCONFIG(baudrate);
}

error_code_t UART4_Config(long baudrate, bool rxint) {
    UART_RX_INTERRUPT_4_SWITCH(rxint);
    return UART4_BAUDCONFIG(baudrate);
}
#endif
char UART1_Read() {
//    while(!U1STAbits.URXDA);
//    return U1RXREG;
    return UART_RECEIVER_REG;
}
#if( UART_MODULES > 1)
char UART2_Read() {
    while(!U2STAbits.URXDA);
    return U2RXREG;
}

char UART3_Read() {
    while(!U3STAbits.URXDA);
    return U3RXREG;
}

char UART4_Read() {
    while(!U4STAbits.URXDA);
    return U4RXREG;
}
#endif
void UART1_Write(char byte) {
//    while(U1STAbits.UTXBF);
//    U1TXREG = byte;
    while (!UART_TRANSMITTER_REG_EMPTIED); //TX buffer is full
    UART_TRANSMITTER_REG = byte;
}
#if( UART_MODULES > 1)
void UART2_Write(char byte) {
    while(U2STAbits.UTXBF);
    U2TXREG = byte;
}

void UART3_Write(char byte) {
    while(U3STAbits.UTXBF);
//    if (U3STAbits.UTXBF) return;
    U3TXREG = byte;
}

void UART4_Write(char byte) {
    while(U4STAbits.UTXBF);
    U4TXREG = byte;
}
#endif