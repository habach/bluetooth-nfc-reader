/*
 * msos.h
 *
 *  Created on: Jun 24, 2016
 *      Author: habach
 */

#ifndef MSOS_H_
#define MSOS_H_

/*Define compiler*/
//#include <xc.h>
#include "application.h"


///*Define chipset*/
////#include <pic18f46k20.h>
//#include <pic18f46k22.h>
//#include <pic18.h>
////#define ARDUINO
////#define ARDUINO_MEGA2560
////#define _XTAL_FREQ 16000000L
/********************/

//#define DEV_BOARD MUALINHKIEN_KITPIC_BASIC
//#define DEV_BOARD BANLINHKIEN_KITPIC_V1


/*Define std libs*/
#include <stdio.h>
#include <stdint.h>

//#include "myclock.h"

/*Setup basic parameters for MSOS*/
#ifndef UART_DEFAULT_BAUDRATE
#define UART_DEFAULT_BAUDRATE 9600
#endif
#ifndef STDERR_BUFFER_SIZE
#define STDERR_BUFFER_SIZE 64
#endif
#ifndef UART_RX_BUFFER_SIZE
#define UART_RX_BUFFER_SIZE 8
#endif
#ifndef CHAR_VAR_LIST_MAX
#define CHAR_VAR_LIST_MAX 16
#endif

//#define error_code_t signed char

//#define ESP8266_CMD_BUFFER_SIZE 1000
//#define ESP8266_DATA_BUFFER_SIZE 1000

//#define COUT Serial

//Override keypad.h
#define KEYPAD_ENTER 13
#define KEYPAD_DEL 127
//#define KEYPAD_FORWARD 6
//#define KEYPAD_BACKWARD 4
#define KEYPAD_ESCAPE 27

//Override IP_STRING_LENGTH in mysocket.h
//#define IP_STRING_LENGTH 30

//#include "ioPort.h"
#ifndef INLINE_ON
#define INLINE_ON
#endif
#ifndef VOLATILE_BIT
#define VOLATILE_BIT
#endif
#ifndef VOLATILE
#define VOLATILE volatile
#endif


//#if (CHIP_SIZE==8)
//#define ioports ioports
//#define ioport_t ioPort8_t
//#elif (CHIP_SIZE==16)
//#define ioports io_reg16
//#define ioport_t ioPort16_t
//#else
//#error "No CHIP_SIZE declaration in mychips.h"
//#endif

#include "error.h"
#include "fifo_type.h"
#include "iodev.h"
#include "myiostream.h"
//#include "ioPort.h"

///*********************************/
//
///*Load chipset configurations*/
//#include "mychips.h"
//#ifdef _PIC18_H
//#include "../mcc_generated_files/mcc.h"
//#endif
///*****************************/

/*Define application*/
//#include "application.h"
/********************************/

/***Load parts of MSOS***/
//#include "error.h"
//#include "mydelay.h"
//#include "myiostream.h"
//#include "ioPort.h"

/************************/

//typedef struct {
//    struct {
//        void (*alert)(int e, char *msg);
//        led_t ERROR_LED;
//    }error;
//    
//}MCOS;

#define ERROR_CLASS_ID_MCOS 0
#define ERROR_CLASS_ID_FIFO 1
#define ERROR_CLASS_ID_IOSTREAM 2
#define ERROR_CLASS_ID_UART 3
#define ERROR_CLASS_ID_SPI 4


#define MSOS_INIT_FAILED_RET -1

//extern netfuncs_t *StdNetOperator;

//extern MCOS OS;
//#include "global_var.h"

error_code_t msos_init();
void mcos_setupTimer(unsigned long intervals);
void mcos_timerSwitch(bool state);
IoDev fifo_makeIoDev(fifo_t *ff, bool reset);
OutputDev fifo_makeOutputDev(fifo_t *ff, bool reset);

#endif /* MSOS_H_ */
