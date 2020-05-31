/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef REGISTER_H
#define	REGISTER_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 
    
typedef union {

	struct {
        unsigned char  p0 : 1;
        unsigned char  p1 : 1;
        unsigned char  p2 : 1;
        unsigned char  p3 : 1;
        unsigned char  p4 : 1;
        unsigned char  p5 : 1;
        unsigned char  p6 : 1;
        unsigned char  p7 : 1;
	};

	struct {
        unsigned char bits_2_0 : 2;
	};

	struct {
        unsigned char : 1;
        unsigned char bits_2_1 : 2;
	};

	struct {
        unsigned char : 2;
        unsigned char bits_2_2 : 2;
	};

	struct {
        unsigned char : 3;
        unsigned char bits_2_3 : 2;
	};

	struct {
        unsigned char : 4;
        unsigned char bits_2_4 : 2;
	};

	struct {
        unsigned char : 5;
        unsigned char bits_2_5 : 2;
	};

	struct {
        unsigned char : 6;
        unsigned char bits_2_6 : 2;
	};

	struct {
        unsigned char bits_3_0 : 3;
	};

	struct {
        unsigned char : 1;
        unsigned char bits_3_1 : 3;
	};

	struct {
        unsigned char : 2;
        unsigned char bits_3_2 : 3;
	};

	struct {
        unsigned char : 3;
        unsigned char bits_3_3 : 3;
	};

	struct {
        unsigned char : 4;
        unsigned char bits_3_4 : 3;
	};

	struct {
        unsigned char : 5;
        unsigned char bits_3_5 : 3;
	};

	struct {
        unsigned char : 4;
        unsigned char bits_4_H : 4;
	};

	struct {
        unsigned char bits_4_L : 4;
	};

	struct {
        unsigned char bits_4_0 : 4;
	};

	struct {
        unsigned char : 1;
        unsigned char bits_4_1 : 4;
	};

	struct {
        unsigned char : 2;
        unsigned char bits_4_2 : 4;
	};

	struct {
        unsigned char : 3;
        unsigned char bits_4_3 : 4;
	};

	struct {
        unsigned char : 4;
        unsigned char bits_4_4 : 4;
	};

	struct {
		unsigned char bits_5_0 :5;
	};

	struct {
		unsigned char :1;
		unsigned char bits_5_1 :5;
	};

	struct {
		unsigned char :2;
		unsigned char bits_5_2 :5;
	};

	struct {
		unsigned char :3;
		unsigned char bits_5_3 :5;
	};


	struct {
		unsigned char bits_6 :6;
	};

	struct {
		unsigned char bits_6_0 :6;
	};

	struct {
		unsigned char :1;
		unsigned char bits_6_1 :6;
	};

	struct {
		unsigned char :2;
		unsigned char bits_6_2 :6;
	};

	struct {
		unsigned char bits_7_0 :7;
	};

	struct {
		unsigned char :1;
		unsigned char bits_7_1 :7;
	};
    
    unsigned char all;
    
} reg8_t;

typedef union {    
    struct {
        unsigned p0 : 1;
        unsigned p1 : 1;
        unsigned p2 : 1;
        unsigned p3 : 1;
        unsigned p4 : 1;
        unsigned p5 : 1;
        unsigned p6 : 1;
        unsigned p7 : 1;
        unsigned p8 : 1;
        unsigned p9 : 1;
        unsigned p10: 1;
        unsigned p11: 1;
        unsigned p12: 1;
        unsigned p13: 1;
        unsigned p14: 1;
        unsigned p15: 1;
    };
    
	struct {
        unsigned bits_2_0 : 2;
	};

	struct {
        unsigned : 1;
        unsigned bits_2_1 : 2;
	};

	struct {
        unsigned : 2;
        unsigned bits_2_2 : 2;
	};

	struct {
        unsigned : 3;
        unsigned bits_2_3 : 2;
	};

	struct {
        unsigned : 4;
        unsigned bits_2_4 : 2;
	};

	struct {
        unsigned : 5;
        unsigned bits_2_5 : 2;
	};

	struct {
        unsigned : 6;
        unsigned bits_2_6 : 2;
	};
    
    struct {
        unsigned : 7;
        unsigned bits_2_7 : 2;
	};
    
    struct {
        unsigned : 8;
        unsigned bits_2_8 : 2;
	};

	struct {
        unsigned bits_3_0 : 3;
	};

	struct {
        unsigned : 1;
        unsigned bits_3_1 : 3;
	};

	struct {
        unsigned : 2;
        unsigned bits_3_2 : 3;
	};

	struct {
        unsigned : 3;
        unsigned bits_3_3 : 3;
	};

	struct {
        unsigned : 4;
        unsigned bits_3_4 : 3;
	};

	struct {
        unsigned : 5;
        unsigned bits_3_5 : 3;
	};

	struct {
        unsigned : 4;
        unsigned bits_4_H : 4;
	};

	struct {
        unsigned bits_4_L : 4;
	};

	struct {
        unsigned bits_4_0 : 4;
	};

	struct {
        unsigned : 1;
        unsigned bits_4_1 : 4;
	};

	struct {
        unsigned : 2;
        unsigned bits_4_2 : 4;
	};

	struct {
        unsigned : 3;
        unsigned bits_4_3 : 4;
	};

	struct {
        unsigned : 4;
        unsigned bits_4_4 : 4;
	};

	struct {
		unsigned bits_5_0 :5;
	};

	struct {
		unsigned :1;
		unsigned bits_5_1 :5;
	};

	struct {
		unsigned :2;
		unsigned bits_5_2 :5;
	};

	struct {
		unsigned :3;
		unsigned bits_5_3 :5;
	};


	struct {
		unsigned bits_6 :6;
	};

	struct {
		unsigned bits_6_0 :6;
	};

	struct {
		unsigned :1;
		unsigned bits_6_1 :6;
	};

	struct {
		unsigned :2;
		unsigned bits_6_2 :6;
	};

	struct {
		unsigned bits_7_0 :7;
	};

	struct {
		unsigned :1;
		unsigned bits_7_1 :7;
	};
    
    unsigned all;    
    
    struct {
        reg8_t byteL;
        reg8_t byteH;
    };
    uint16_t whole;
} reg16_t;   

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

