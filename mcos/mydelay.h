/* 
 * File:   mydelay.h
 * Author: bnh
 *
 * Created on February 27, 2014, 12:54 PM
 */

#ifndef MYDELAY_H
#define	MYDELAY_H

#include "application.h"
#include "mychips.h"
#include <stdint.h>

#ifndef DELAY_MS
    #define DELAY_MS delay_ms
#endif
#ifndef DELAY_US
    #define DELAY_US delay_us
#endif
#ifndef CYCLES_FOR_DELAY_MS
    #define CYCLES_FOR_DELAY_MS 67 // Default value @4Mhz CLK
#endif
#ifndef CLOCKS_PER_INSTRUCTION
    #define CLOCKS_PER_INSTRUCTION 4
#endif

#define CYCLES_PER_US (_XTAL_FREQ/1000000L)
#define DIVS_PER_US (CYCLES_PER_US/CLOCKS_PER_INSTRUCTION)

//unsigned dl_us_input;
unsigned dl_ms_input;
//unsigned dl_us_cyc;
//unsigned dl_ms_cyc;

#ifndef delay_us
//	unsigned dl_us_input;
    #ifdef __Delay_us
        #define delay_us __Delay_us
    #elif defined __delay_us

        #define delay_us(x) do{unsigned us;for(us=(x);us--;)__delay_us(1);}while(0)
    #elif defined Delay1TCYx_EXISTS
        extern void Delay1TCYx(unsigned char);
        unsigned dl_us_input;
        #if (CYCLES_PER_US<10)
            #define TAKE_1_US Delay1TCYx(CYCLES_PER_US)
        #elif (CYCLES_PER_US<100)
            #define TENS_DIG CYCLES_PER_US/10
            #define UNITS_DIG CYCLES_PER_US%10
            #define TAKE_1_US Delay10TCYx(TENS_DIG),Delay1TCYx(UNITS_DIG)
        #endif
        #define delay_us(x) for(dl_us_input=(x);dl_us_input;dl_us_input--)TAKE_1_US
#elif defined ARDUINO_UNO || defined ARDUINO_MEGA2560
#define delay_us(x) delayMicroseconds((x))
    #else
//        unsigned dl_us_cyc;        
//        #define delay_us(x) do{unsigned dl_us_input,dl_us_cyc;for(dl_us_input=((x)/CLOCKS_PER_INSTRUCTION)>>1;dl_us_input;dl_us_input--)for(dl_us_cyc=DIVS_PER_US>>1;dl_us_cyc;dl_us_cyc--);}while(0)
#define delay_us(x) { __delay32( (unsigned long) (((unsigned long long) x)*(FCY)/1000000ULL)); }
        
    #endif
#endif

#ifndef delay_ms
//    unsigned dl_ms_input;
    //#define delay_ms(x) for(dl_input=(x);dl_input>0;dl_input--)for(dl_cyc=0;dl_cyc<CYCLES_FOR_DELAY_MS;dl_cyc++)
    #ifdef __Delay_ms
       #define delay_ms __Delay_ms        
    #elif defined __delay_ms
//        unsigned dl_ms_input;
        #define delay_ms(x) for(dl_ms_input=(x);dl_ms_input;dl_ms_input--)__delay_ms(1)
//#define delay_ms(x) __delay_ms((x))
    #elif defined __delay_us
        unsigned char dl_ms_temp;        
#define delay_ms(x) for(dl_ms_input=(x);dl_ms_input;dl_ms_input--)for(dl_ms_temp=100;dl_ms_temp;dl_ms_temp--)__delay_us(10)
#elif defined ARDUINO_UNO || defined ARDUINO_MEGA2560
#define delay_ms delay
    #else
        #define delay_ms(x) do{unsigned dl_ms_input; for(dl_ms_input=(x);dl_ms_input;dl_ms_input--)delay_us(1000);}while(0)
        //#define delay_ms(x) for(dl_ms_input=(x/CLOCKS_PER_INSTRUCTION)>>1;dl_us_input;dl_us_input--)for(dl_us_cyc=DIVS_PER_US>>1;dl_us_cyc;dl_us_cyc--)
    #endif
#endif

#ifndef delay_s    
    #if defined __Delay_s
       #define delay_s __Delay_s        
//    #elif defined __delay_ms
//        unsigned dl_s_input;
//        unsigned char dl_s_temp;
//        #define delay_s(x) for(dl_s_input=(x);dl_s_input;dl_s_input--)for(dl_s_temp=100;dl_s_temp;dl_s_temp--)__delay_ms(10)
    #else
               
        #define delay_s(x) do{unsigned __dl_s; for(__dl_s=(x);__dl_s--;)delay_ms(1000);}while(0)
    #endif
#endif

//void delay_ms(unsigned t);
//void delay_us(unsigned t);

#endif	/* MYDELAY_H */
