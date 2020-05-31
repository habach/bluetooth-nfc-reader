/* 
 * File:   io_port.h
 * Author: bnh
 *
 * Created on May 4, 2014, 12:32 PM
 */

#ifndef IO_PORT_H
#define	IO_PORT_H

//#include "mychips.h"
//#include "mcos.h"
#include "application.h"
//#include <stdint.h>
//#include <stdbool.h>
#include "error.h"
#include "register.h"


typedef reg8_t ioPort8_t;
typedef reg16_t ioPort16_t;

//#ifndef int8_t
//#define int8_t signed char
//#endif

#ifndef OUTPUT
#define OUTPUT 0x00
#endif

#ifndef INPUT
#define INPUT 0xff
#endif

#ifndef VOLATILE
#define VOLATILE volatile
#endif

#ifndef INLINE
#define INLINE
#endif

#ifndef POOR_DEVICE
#define POOR_DEVICE 0
#endif


#if (CHIP_SIZE==8)
#define ioports io_reg8
#define ioport_t ioPort8_t
#define  portsize_t unsigned char
#define PORT_MAX_VAL 0xFF
#elif (CHIP_SIZE==16)
#define ioports io_reg16
#define ioport_t ioPort16_t
#define  portsize_t unsigned
#define PORT_MAX_VAL 0xFFFF
#else
#error "No CHIP_SIZE declaration in mychips.h"
#endif

#define IO_PORT8_SUCCESS_RET 0
#define IO_PORT8_NULL_POINTER_RET -1
#define IO_PORT8_PORT_NULL_POINTER_RET -2
#define IO_PORT8_PORT_DIR_NULL_POINTER_RET -3

//#ifdef STATIC_ON
//#define STATIC static
//#else
//#define STATIC
//#endif

//#ifdef _ON
//#define  inline
//#else
//#define 
//#endif

//typedef union {
//
//	struct {
//        unsigned  p0 : 1;
//        unsigned  p1 : 1;
//        unsigned  p2 : 1;
//        unsigned  p3 : 1;
//        unsigned  p4 : 1;
//        unsigned  p5 : 1;
//        unsigned  p6 : 1;
//        unsigned  p7 : 1;
//	};
//
//	struct {
//        unsigned bits_2_0 : 2;
//	};
//
//	struct {
//        unsigned : 1;
//        unsigned bits_2_1 : 2;
//	};
//
//	struct {
//        unsigned : 2;
//        unsigned bits_2_2 : 2;
//	};
//
//	struct {
//        unsigned : 3;
//        unsigned bits_2_3 : 2;
//	};
//
//	struct {
//        unsigned : 4;
//        unsigned bits_2_4 : 2;
//	};
//
//	struct {
//        unsigned : 5;
//        unsigned bits_2_5 : 2;
//	};
//
//	struct {
//        unsigned : 6;
//        unsigned bits_2_6 : 2;
//	};
//
//	struct {
//        unsigned bits_3_0 : 3;
//	};
//
//	struct {
//        unsigned : 1;
//        unsigned bits_3_1 : 3;
//	};
//
//	struct {
//        unsigned : 2;
//        unsigned bits_3_2 : 3;
//	};
//
//	struct {
//        unsigned : 3;
//        unsigned bits_3_3 : 3;
//	};
//
//	struct {
//        unsigned : 4;
//        unsigned bits_3_4 : 3;
//	};
//
//	struct {
//        unsigned : 5;
//        unsigned bits_3_5 : 3;
//	};
//
//	struct {
//        unsigned : 4;
//        unsigned bits_4_H : 4;
//	};
//
//	struct {
//        unsigned bits_4_L : 4;
//	};
//
//	struct {
//        unsigned bits_4_0 : 4;
//	};
//
//	struct {
//        unsigned : 1;
//        unsigned bits_4_1 : 4;
//	};
//
//	struct {
//        unsigned : 2;
//        unsigned bits_4_2 : 4;
//	};
//
//	struct {
//        unsigned : 3;
//        unsigned bits_4_3 : 4;
//	};
//
//	struct {
//        unsigned : 4;
//        unsigned bits_4_4 : 4;
//	};
//
//	struct {
//		unsigned bits_5_0 :5;
//	};
//
//	struct {
//		unsigned :1;
//		unsigned bits_5_1 :5;
//	};
//
//	struct {
//		unsigned :2;
//		unsigned bits_5_2 :5;
//	};
//
//	struct {
//		unsigned :3;
//		unsigned bits_5_3 :5;
//	};
//
//
//	struct {
//		unsigned bits_6 :6;
//	};
//
//	struct {
//		unsigned bits_6_0 :6;
//	};
//
//	struct {
//		unsigned :1;
//		unsigned bits_6_1 :6;
//	};
//
//	struct {
//		unsigned :2;
//		unsigned bits_6_2 :6;
//	};
//
//	struct {
//		unsigned bits_7_0 :7;
//	};
//
//	struct {
//		unsigned :1;
//		unsigned bits_7_1 :7;
//	};
//
//	struct {
//		unsigned char all;
//	};
//} ioPort8_t;

typedef enum {
	output_mode = 0,
	input_mode = 1,
	p0 = 0,	port_bits = 0,	twoway_pins = 0,
	p1 = 1,	port_dir_bits = 1,	input_pins = 1,
	p2 = 2,	output_pins = 2,
	p3 = 3,
	p4 = 4,
	p5 = 5,
	p6 = 6,
	p7 = 7,
	p8 = 8,
	p9 = 9,
	p10 = 10,
	p11 = 11,
	p12 = 12,
	p13 = 13,
	p14 = 14,
	p15 = 15,

	p_2_0 = 16, unoP0_1 = 16,
	p_2_1 = 17, unoP1_2 = 17,
	p_2_2 = 18, unoP2_3 = 18,
	p_2_3 = 19, unoP3_4 = 19,
	p_2_4 = 20, unoP4_5 = 20,
	p_2_5 = 21, unoP5_6 = 21,
	p_2_6 = 22, unoP6_7 = 22,

	p_3_0 = 23, unoP0_2 = 23,
	p_3_1 = 24, unoP1_3 = 24,
	p_3_2 = 25, unoP2_4 = 25,
	p_3_3 = 26, unoP3_5 = 26,
	p_3_4 = 27, unoP4_6 = 27,
	p_3_5 = 28, unoP5_7 = 28,

	p_4_0 = 29, unoP0_3 = 29,
	p_4_L = 30,
	p_4_1 = 31, unoP1_4 = 31,
	p_4_2 = 32, unoP2_5 = 32,
	p_4_3 = 33, unoP3_6 = 33,
	p_4_4 = 34, unoP4_7 = 34,
	p_4_H = 35,

	p_5_0 = 36, unoP0_4 = 36,
	p_5_1 = 37, unoP1_5 = 37,
	p_5_2 = 38, unoP2_6 = 38,
	p_5_3 = 39, unoP3_7 = 39,

	p_6_0 = 40, unoP0_5 = 40,
	p_6_1 = 41, unoP1_6 = 41,
	p_6_2 = 42, unoP2_7 = 42,

	p_7_0 = 43, unoP0_6 = 43,
	p_7_1 = 44, unoP1_7 = 44,

	p_8 = 45, p_all = 45, unoP0_7 = 45,

	unoP8_9 = 46,
	unoP9_10 = 47,
	unoP10_11 = 48,
	unoP11_12 = 49,
	unoP12_13 = 50,

	unoP8_10 = 51,
	unoP9_11 = 52,
	unoP10_12 = 53,
	unoP11_13 = 54,

	unoP8_11 = 55,
	unoP9_12 = 56,
	unoP10_13 = 57,

	unoP8_12 = 58,
	unoP9_13 = 59,

	unoP8_13 = 60,
            
    p_2_7 = 61,
    p_2_8 = 62,

	p_null = 0xFF, //for floating pins

		all_pins = 0xFE
} pin_position;

//typedef enum {
//	output_mode = 0,
//	input_mode = 1,
//	p0 = 70,	port_bits = 0,	twoway_pins = 0,
//	p1 = 61,	port_dir_bits = 1,	input_pins = 1,
//	p2 = 52,	output_pins = 2,
//	p3 = 43,
//	p4 = 34,
//	p5 = 25,
//	p6 = 16,
//	p7 = 7
//            ,
////	p8 = 8,
////	p9 = 9,
////	p10 = 10,
////	p11 = 11,
////	p12 = 12,
////	p13 = 13,
////	p14 = 14,
////	p15 = 15,
//
//	p_2_0 = 60, unoP0_1 = 16,
//	p_2_1 = 51, unoP1_2 = 17,
//	p_2_2 = 42, unoP2_3 = 18,
//	p_2_3 = 33, unoP3_4 = 19,
//	p_2_4 = 24, unoP4_5 = 20,
//	p_2_5 = 15, unoP5_6 = 21,
//	p_2_6 = 6, unoP6_7 = 22,
//
//	p_3_0 = 50, unoP0_2 = 23,
//	p_3_1 = 41, unoP1_3 = 24,
//	p_3_2 = 32, unoP2_4 = 25,
//	p_3_3 = 23, unoP3_5 = 26,
//	p_3_4 = 14, unoP4_6 = 27,
//	p_3_5 = 5, unoP5_7 = 28,
//
//	p_4_0 = 40, unoP0_3 = 29,
//	p_4_L = 40,
//	p_4_1 = 31, unoP1_4 = 31,
//	p_4_2 = 22, unoP2_5 = 32,
//	p_4_3 = 13, unoP3_6 = 33,
//	p_4_4 = 4, unoP4_7 = 34,
//	p_4_H = 4,
//
//	p_5_0 = 30, unoP0_4 = 36,
//	p_5_1 = 21, unoP1_5 = 37,
//	p_5_2 = 12, unoP2_6 = 38,
//	p_5_3 = 3, unoP3_7 = 39,
//
//	p_6_0 = 20, unoP0_5 = 40,
//	p_6_1 = 11, unoP1_6 = 41,
//	p_6_2 = 2, unoP2_7 = 42,
//
//	p_7_0 = 10, unoP0_6 = 43,
//	p_7_1 = 1, unoP1_7 = 44,
//
//	p_8 = 0, p_all = 0, unoP0_7 = 0,
//
////	unoP8_9 = 46,
////	unoP9_10 = 47,
////	unoP10_11 = 48,
////	unoP11_12 = 49,
////	unoP12_13 = 50,
////
////	unoP8_10 = 51,
////	unoP9_11 = 52,
////	unoP10_12 = 53,
////	unoP11_13 = 54,
////
////	unoP8_11 = 55,
////	unoP9_12 = 56,
////	unoP10_13 = 57,
////
////	unoP8_12 = 58,
////	unoP9_13 = 59,
////
////	unoP8_13 = 60,
//
//	p_null = 0xFF, //for floating pins
//
//		all_pins = 0xFE
//} pin_position;

typedef struct {
	volatile ioPort8_t *port;
	volatile ioPort8_t *port_dir;
} io_reg8;

typedef struct {
	volatile ioPort16_t *port;
	volatile ioPort16_t *port_dir;
} io_reg16;

typedef struct {
	ioports *ports;
	unsigned char pinN;
} port_n_pin;

typedef struct {
	VOLATILE ioport_t *reg;
	unsigned char bitN;
} reg_n_bit;

typedef struct {
    volatile ioport_t *port;
	volatile ioport_t *port_dir;
    unsigned char pinN;
}ports_n_pin;

 error_code_t ioPort8_init(ioports*, pin_position, unsigned char);
 void ioPort8_write(volatile ioport_t *port, unsigned char pinN, unsigned char data);
inline unsigned char ioPort8_read(volatile ioport_t* port, unsigned char pinN);
void ioPort8_toggle(volatile ioport_t* port, unsigned char pinN);
void ioPort16_write(volatile ioPort16_t *port, unsigned char pinN, unsigned char data);
error_code_t ioPort8_pinMode(port_n_pin *pnp, unsigned char mode);
void ioPort8_pinWrite(port_n_pin *pnp, unsigned char data);
unsigned char ioPort8_pinRead(port_n_pin *pnp);
void ioPort8_pinToggle(port_n_pin *pnp);



#endif	/* IO_PORT_H */
