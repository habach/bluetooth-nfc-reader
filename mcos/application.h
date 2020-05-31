/* 
 * File:   main.h
 * Author: habach
 *
 * Created on March 15, 2014, 11:08 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
#include <xc.h>

/*******SELECT MCU & BOARD**********/
#include "boards.h"
#include "myboard.h"
/***************************/

//#define FIRMWARE_VERSION "19.03.30.1"
/***************************/

#define TEST_BOARD 0
#define DIGITAL_MODE 0
#define ANALOG_MODE 1

#define BEEP RC2
#define BEEP_DDR TRISCbits.TRISC2
#define RF_nEN RA0
#define RF_nEN_DDR TRISAbits.TRISA0
//#define RF_nEN_DIGITAL_EN() do{ANSELbits.ANS0 = DIGITAL_MODE;CMCON0bits.CM = 7;}while(0);
#define MAX485_TX_EN RC3
#define MAX485_TX_EN_DDR TRISCbits.TRISC3

#define INPUT1 RA2
#define INPUT1_DDR TRISAbits.TRISA2
#define INPUT1_INTERRUPT_EN() do{nRAPU=0;WPUAbits.WPU2=1;IOCAbits.IOCA2=1;TRISAbits.TRISA2=1;}while(0);



/********MCOS CONFIG*************/
#define SYSTEM_CLOCK_AUTOSTART 1
#define STDERR_BUFFER_SIZE 1
/////////////////////////////////

/********UART CONFIG*************/
#define UART_DEFAULT_BAUDRATE 9600
/********************************/

#define FIFO_DEBUGGING_EN 0
//#define UNFINISH_CONDITION_ALERT() do{printf("Fatal: Fifo emptied infinitive loop");}while(0)
//#define UNFINISH_CONDITION_ALERT_OFF BUSY_LED=1
/************************************/

#define RIGID_MODE 0

#define ADC_GET_VALUE_CMD "AR"
#define ADC_INVALID_CHANNEL_MSG "bad pin"
#define IOSTREAM_STDIN_BUFFER_LENGTH 8
#define STDUART_BAUDRATE 9600
#define STDERR_SIZE 4
#define INLINE
#define STATIC 
#define DEBUG_MODE 0
#define VOLATILE 

#define EEPROM_POOR_DEVICE_FORCE_ENALED 0

/******LOAD BOARD LIST******/
//#include "boards.h"
#include "mychips.h"
/***************************/

#if (MYCHIP==PIC24FJ256GB106)
#define ESP8266_DATA_BUFFER_SIZE 1536
#define ESP8266_CMD_BUFFER_SIZE 1536
#elif (MYCHIP==PIC24FJ1024GB606)
#define ESP8266_DATA_BUFFER_SIZE 2048
#define ESP8266_CMD_BUFFER_SIZE 2048
#endif

typedef union {
    struct {
        unsigned : 2;
        unsigned myleds : 4;
    };
    struct {
        unsigned : 4;
        unsigned directional_bits : 2;
    };
    struct {
        unsigned : 2; //TODO: TEMPORARILY SHIFT ALARM BIT TO ANOTHER PIN
        unsigned alarm : 1;
    };
    struct {
        unsigned : 4;
        unsigned status_report: 2;
    };
} led_port;

typedef struct {
    unsigned ADDRESS;
//    unsigned INPUT1_ID;    
    unsigned char edge;
} params_t;

typedef union {
    struct {
        unsigned char rom_error:1;
    };
    unsigned char whole;
} error_t;

#define MODBUS_BUFFER_SIZE 16
#define MASTER_ADDRRESS 1
#define ID_HEADER "\r\nID:"
#define END_ST "\r\n"

extern char MODBUS_BUFFER[];
//extern fifo_t MB_QUEUE;

void application_setup();
void setup();
void loop();

#endif	/* MAIN_H */
