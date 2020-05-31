/* 
 * File:   mytimers.h
 * Author: bnh
 *
 * Created on March 2, 2014, 6:54 PM
 */

#ifndef MYTIMERS_H
#define	MYTIMERS_H

//#include "application.h"
#include "ioPort.h"
//#include <stdint.h>
#include <stdbool.h>
//#include <plib/timers.h>
//#include "ioPort.h"

//typedef enum {
//            timer0 = 0,
//            internal_clock = 0,
//            falling_edge = 0,
//            operation_disabled = 0,
//            timer_8bit = 0, timer_16bit = 1, timer_32bit = 2,
//                    
//            timer1 = 1,
//            external_clock = 1,
//            rising_edge = 1,
//            operation_enabled = 1,
//            timer2 = 2,
//            timer3 = 3,
//            timer4 = 4
//}timer_stuff;
//
//typedef struct {
//    unsigned cntsize:2;         //0=8bit, 1=16bit, 2=32bit...?
//    unsigned clock_source:1;    //1-external clock, 0-internal clock
//    unsigned trigger_edge:1;    //1-Rising edge, 0-falling edge
//    unsigned prescaler:3;       //In case of using external clk, specifies scale of clk (1:1, 1:2, 1:4, 1:8...))
//    unsigned ready:1;
//}timer_info;
//
//typedef union {
//    unsigned all_bytes;
//    struct{
//        unsigned lo_byte:8;
//        unsigned hi_byte:8;
//    };
//}cnt16bit;
//
//typedef struct {    
//    timer_info info;
//    unsigned init_number;
//    volatile cnt16bit *CNT;
//}timer16bit_t;
//
//typedef struct {    
//    timer_info info;
//    unsigned char init_number;
//    volatile unsigned char *CNT;
//}timer8bit_t;
//
//typedef struct {
//    unsigned cntsize:2;         //0=8bit, 1=16bit, 2=32bit...?
//    unsigned clock_source:1;    //1-external clock, 0-internal clock
//    unsigned trigger_edge:1;    //1-Rising edge, 0-falling edge
//    unsigned prescaler:3;       //In case of using external clk, specifies scale of clk (1:1, 1:2, 1:4, 1:8...))
//    unsigned ready:1;
//    unsigned init_value;
////    bool use_interrupt;
//    volatile void *CNT;
//    volatile reg8_t *TMR_CTRL;
//    unsigned tmrON_bitN:3; //TMRxON bit position (0 to 7))
//}timer_t;
//
//
////timer16bit_t TMR_1 @ (unsigned)&TMR1L;
//
//#ifdef USE_TIMER0
//    #define USING_TIMER0 1
//    #define INTERNAL_CLOCK 0
//    #define EXTERNAL_CLOCK 1
//    #define EDGE_FALLING    0
//    #define EDGE_RISING    1
//    #define GLOBAL_INTERRUPT_ENABLED 1
//    #define GLOBAL_INTERRUPT_DISABLED 0
//    #define T0_INTERRUPT_ENABLED 1
//    #define T0_INTERRUPT_DISABLED 0
//    #define PRESCALER_2 0
//    #define PRESCALER_4 1
//    #define PRESCALER_8 2
//    #define PRESCALER_16 3
//    #define PRESCALER_32 4
//    #define PRESCALER_64 5
//    #define PRESCALER_128 6
//    #define PRESCALER_256 7
//
//#else
//#define USING_TIMER0 0
//#endif
//
//bool TIMER0_POWERED=false;
//long TMR0_VALUE = 0;
//
//void timer_setup(timer_t *mytimer);
//void timer0_switch(timer_t *mytimer, bool state);

typedef struct {
    void (*init)(unsigned char);
    void (*start)();
    void (*restart)();
    void (*stop)();
    bool (*isUnderFlowed)();
    volatile unsigned *tmr_val;
    bool ready;
//    ioport_t *stat_reg;
//    unsigned char bitN;
}tmr_funcs;


#endif	/* MYTIMERS_H */

