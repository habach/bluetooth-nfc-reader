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
#ifndef FIFO_TYPE_H
#define	FIFO_TYPE_H
#include <stdbool.h>
#include <stdint.h>

#include <xc.h> // include processor files - each processor file is guarded.  

typedef struct {
    /*VOLATILE*/ char *buffer;
    /*VOLATILE*/ uint16_t buffer_size;
    /*VOLATILE*/ char *pr;
    /*VOLATILE*/ char *pw;
    /*VOLATILE*/ char *pmax;
    struct {
//        unsigned :2;
         /*VOLATILE*/ bool overwrite_en:1; //Enable/disable overwriting the oldest unread data when fifo is full;
       /*VOLATILE*/ bool full:1;
        /*VOLATILE*/ bool emptied:1;
        /*VOLATILE*/ bool overwrite_flag:1; //Will be set when 'overwriting' orccured.
        /*VOLATILE*/ bool wr_protection:1;
        /*VOLATILE*/ bool ready:1;
    };
} fifo_t;

#endif	/* XC_HEADER_TEMPLATE_H */

