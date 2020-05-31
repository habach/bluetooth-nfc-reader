/*
 * atmega2560_interrupt.h
 *
 *  Created on: Jun 23, 2016
 *      Author: Administrator PC
 */

#include "../../register.h"
#include "../../ioPort.h"
#ifndef PIC24FJ256GB106_INTERRUPT_H_
#define PIC24FJ256GB106_INTERRUPT_H_

//#include "application.h"

//INTERRUPTS
#ifndef UART0_isr
#define UART0_isr ISR(USART0_RX_vect)
#endif
#ifndef UART1_isr
#define UART1_isr ISR(USART1_RX_vect)
#endif
#ifndef UART2_isr
#define UART2_isr ISR(USART2_RX_vect)
#endif
#ifndef UART3_isr
#define UART3_isr ISR(USART3_RX_vect)
#endif

#define UART_RECEPT_INTERRUPT RCIE
#define UART_TRANSMISSION_INTERRUPT TXIE
#define IOC_IE RBIE
#define GLOBAL_IE_SWITCH(x) GIE=(x)
#define IOC_IF RBIF
#define IOCB_IE IOCB
#define IOCB_SETUP(x)  do{IOCB=(x)?255:0;}while(0)
#define IOC_INTERRUPT_SWITCH(x) do{GLOBAL_IE=x;IOC_IE=x;IOC_IF=0;}while(0)
#define ADC_IE_SWITCH(x) ADIE
#define ADC_IF_SWITCH(x) ADIF
#define TIMER0_IE_SWITCH(x) TMR0IE
#define TIMER0_IF_SWITCH(x) TMR0IF
#define PE_IE_SWITCH(x) NOP()

//typedef struct {
//    void (*init)(unsigned char);
//    void (*start)();
//    void (*restart)();
//    void (*stop)();
//    ioport_t *stat_reg;
//    unsigned char bitN;
//}tmr_funcs;

void __attribute__ ( ( interrupt, no_auto_psv ) ) _U1RXInterrupt();

#endif /* PIC24FJ256GB106_INTERRUPT_H_ */
