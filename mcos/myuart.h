/* 
 * File:   myuart.h
 * Author: bnh
 *
 * Created on May 8, 2014, 2:36 PM
 */
#ifndef MYUART_H
#define MYUART_H

#include "mcos.h"
#include <stdint.h>
#include <stdbool.h>
#include "iodev.h"
//#include <stdlib.h>
//#include <stdio.h>
//#include "atmega2560_uart.h"
#ifdef _PIC18_H_
#include <plib/usart.h>
#endif
#include "fifo.h"
#include "error.h"

#ifndef ERROR_CLASS_ID_UART
#define ERROR_CLASS_ID_UART 3
#endif


#ifndef UART_DEFAULT_BAUDRATE
#define UART_DEFAULT_BAUDRATE 9600L
#endif

#ifndef UART_RX_BUFFER_SIZE
#define UART_RX_BUFFER_SIZE 8
#endif
#ifndef TX_BUFFER_SIZE
#define TX_BUFFER_SIZE UART_RX_BUFFER_SIZE
#endif

#ifndef RIGID_MODE
#define RIGID_MODE 1
#endif

#ifndef UART_NAME
#define UART_NAME "UART"
#endif

#ifndef UART_SENDING_TIMEOUT
#define UART_SENDING_TIMEOUT 1000
#endif

#define UART_LF_CR_CHAR '\n'

#define UART_RX_BUFFER_FULL_RET -1
#define UART_SUCCESS_RET 0
#define UART_RX_FERR_RET -2
#define UART_RX_OERR_RET -3
//#define UART_NULL_RXBUFFER_RET 1
#define UART_INIT_RXFIFO_FAILED_RET -4
#define UART_INIT_BRR_FAILED_RET -5
#define UART_NULL_POINTER_RET -6
#define UART_NULL_DATA_RET -7
#define UART_NOT_READY_RET -8
#define UART_INVALID_UARTNO_RET -9
#define UART_ZERO_DATASIZE_RET -10
#define UART_NULL_INPUT_POINTER_RET -11
#define UART_INPUT_NOT_READY_RET -12

//#define UART_BRR_FACTOR 2

typedef enum {
	databit8=0, databit9=1, databit5=2,databit6=3,databit7=4,
    rx_int_off=0,rx_int_on=1,tx_int_off=0,tx_int_on=1,
    standard_baud_calculation=0,optimized_baud_calculation=1,
    cut_matched_st=0, keep_matched_st = 1, cut_nothing = 2,
    MC_UART0=0,MC_UART1=0, MC_UART2=1,MC_UART3=2, MC_UART4=3,
    INT_TX_RX_OFF_OFF=0, ADDEN_OFF = 0, MODE_9BIT_OFF = 0,
    DIR_RECEIVER = 0, DIR_TRANSMITTER = 1,
    BRG16_NO = 0, BRG16_YES = 1, BRG16_DEFAULT = 2,
    BRGH_NO = 0, BRGH_YES = 1, BRGH_DEFAULT = 2,
    ASYNC_MODE = 0, SYNC_MODE = 1,
    INT_TX_RX_OFF_ON = 1, ADDEN_ON = 1, MODE_9BIT_ON = 1,
    INT_TX_RX_ON_OFF = 2,
    INT_TX_RX_ON_ON = 3,
    INT_RX_OFF=4,
    INT_TX_OFF=5,
    INT_RX_ON=6,
    INT_TX_ON=7,
    INT_RX_UNCHANGED = 255, INT_TX_UNCHANGED = 255, INT_UNCHANGED = 255
} uart_stuff;

//typedef struct {
//    char (*getch)();
//    void (*putch)(char));
//} uart_io_funcs;

typedef struct _uart_t{
    
    IoDev stdiofuncs; //Std. I/O interface for STDIO. Must be at top of class declaration

    struct{
    	unsigned long baudrate;
        struct {
        unsigned char uartNo: 2;    //UART module number: 0,1,2,3. Which one is used?
//        struct {
//            bool :1; //preserved
            bool rxint:1; //Enable/disable RX interrupt
//            unsigned char databit_size;//:3; //See the enum codes declared above
//            bool  mode9bit;//:1; //Enable/disable 9-bit transferring (once enabled, only 9-bit incoming data to be received. Once disabled, any incoming data is welcome.)
//            bool  txint;//:1; //Enable/disable TX interrupt
//            bool  adden;//:1; //Enable/disable Address Detection mode which is often in RS485 network with multi devices working together
//            bool shared;
//        };
        };
    }params;

#if (!POOR_DEVICE)
    char *name;
#endif

    struct {
        fifo_t *rxfifo;            //to be pointed to memory location which stores incoming data from RX
        fifo_t _rx_fifo;
        char rxbuffer[UART_RX_BUFFER_SIZE];
    }data;

//    device_code devid;

    struct{
        error_code_t e;
//        VOLATILE bool rxint_enabled;//:1;
//        VOLATILE bool txint_enabled;//:1;
        VOLATILE bool ready;//:1;
    }status;
    
//    stdiodev_t stdiofuncs;

}uart_t;


#ifndef ADDRESS_WITHOUT_RX9D
#define ADDRESS_WITHOUT_RX9D 0
#endif

//#ifndef UART_BAUDRATE
//#define UART_BAUDRATE 9600L
//#endif

//#define uart_reset uart_switch(0),delay_ms(1),uart_switch(1)

#define uart_addressDetection(x) UART_ADDRESS_BIT_EN=(x)
//#define uart_switch(x) UART_EN=(x)
//#define uart_direction(x) DI_RO=(x)
//#define uart_resetBuffer RX_BUFFER_CURSOR=RX_BUFFER
//#define uart_rxSwitch(x) UART_RX_EN=(x)
//#define uart_rx9bit_mode(x) UART_RX9_bit=(x)
//#define uart_rxCancel uart_addressDetection(1),uart_rxReset(),uart_resetBuffer
//#define uart_rxBufferFull (RX_BUFFER_CURSOR>=(RX_BUFFER+RX_BUFFER_SIZE-1))

#define uart_txSwitch(x) do{if(x)uart_direction(DIR_TRANSMITTER);UART_TX_EN=(x);if(!x)uart_direction(DIR_RECEIVER);}while(0)
#define uart_txReset uart_txSwitch(0),delay_ms(1),uart_txSwitch(1)
#define uart_tx9bit_mode(x) UART_TX9_bit=(x)

// char UART_RX_BUFFER[UART_RX_BUFFER_SIZE];
// fifo_t UART_RX_FIFO;
//extern low_iofuncs UART_IOF[UART_MODULES]; 
extern uart_t STDUART;
// uart_t uart_esp;

//void uart_init(uart_stuff spbrg_length, uart_stuff brgH, unsigned short long baudrate, bool sync_mode, void (*extra_setup)());
error_code_t uart_init(void *_u);
error_code_t uart_config (uart_t *u);
error_code_t uart_close(uart_t *u);
error_code_t uart_open(uart_t *u);
bool uart_rxIdle();
//void uart_rxSetup(bool address_detection, bool mode9bit, uart_stuff interrupt_option);
//void uart_interruptSwitch(uart_stuff request);
void uart_rxReset(uart_t *u);
void uart_rxCancel(uart_t *u);
error_code_t uart_puts(void *_u, char *data, unsigned size);
void uart_getInterrupt(uart_t *u);
//unsigned char uart_gets(char *buf);
error_code_t uart_gets(void *_u, char *s);
bool uart_rxBufferFull(uart_t *u);
char uart_read(uart_t *u);

void uart_clearBuffer(uart_t *u);
error_code_t uart_errorReport(uart_t *u, error_code_t error);
void uart_putch(void *_u, char ch);
//bool uart_busy(uart_t *u);
//long uart_brr_calculate(uart_t *u);
//long uart_baud_calculate(unsigned brr);
//long uart_baudErrorCalculate(uart_t *u, unsigned brr);
void uart_power(uart_t* u, unsigned char s);
//void uart_config(uart_t *u);
char uart_getch(void *_u);
bool uart_dataArrival(uart_t *u);
void uart_printInfo(uart_t *u);
bool uart_isReady(void *_u);
//#define uart_isReady(x) (((x)->status).ready)
INLINE void _uart_fifoSwitch(uart_t *u, fifo_t *fifo);
INLINE unsigned uart_unreadData(uart_t *u);
void uart_initStdioFuncs(uart_t *u);
//unsigned char uart_gets (uart_t *u, char *buf);
void uart_setParams(uart_t *u, long baudrate, bool rxint, bool txint);
error_code_t uart_putsX (uart_t *u, char *st,... ) ;
fifo_t uart_putsAndWaitFor(uart_t *u, char *data, unsigned data_size, fifo_t *wait_ff, unsigned waiting_time_ms, /*bool trim_en,*/ char* expected_st, signed char cut_mode);
error_code_t uart_sendFifo(uart_t *u, fifo_t *given_ff);
//int uart_checkForMsg(uart_t *u, fifo_t *redirect_ff, unsigned timeout_ms, int pos, const char *st, ...);

#endif	/* MYUART_H */
