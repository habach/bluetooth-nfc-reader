/* 
 * File:   mystream.h
 * Author: bnh
 *
 * Created on July 15, 2015, 5:10 PM
 */

#ifndef MYSTREAM_H
#define	MYSTREAM_H

//#include "mcos.h"
#include "fifo.h"
#include "myuart.h"
#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
//#include <stdint.h>
//#include "key.h"

#ifndef ERROR_CLASS_ID_IOSTREAM
#define ERROR_CLASS_ID_IOSTREAM 2
#endif

#ifndef STDERR_SIZE
#define STDERR_SIZE 64
#endif

#ifndef IOSTREAM_STDIN_BUFFER_LENGTH
#define IOSTREAM_STDIN_BUFFER_LENGTH 32
#endif

#ifndef STDUART_BAUDRATE
#define STDUART_BAUDRATE 230400
#endif

#ifndef FILE
typedef struct _myfiletype{
    char	*buf;		/* buffer pointer */
	unsigned char unget;	/* ungetc() buffer */
	uint8_t	flags;		/* flags, see below */
#define __SRD	0x0001		/* OK to read */
#define __SWR	0x0002		/* OK to write */
#define __SSTR	0x0004		/* this is an sprintf/snprintf string */
#define __SPGM	0x0008		/* fmt string is in progmem */
#define __SERR	0x0010		/* found error */
#define __SEOF	0x0020		/* found EOF */
#define __SUNGET 0x040		/* ungetc() happened */
#define __SMALLOC 0x80		/* handle is malloc()ed */
#if 0
/* possible future extensions, will require uint16_t flags */
#define __SRW	0x0100		/* open for reading & writing */
#define __SLBF	0x0200		/* line buffered */
#define __SNBF	0x0400		/* unbuffered */
#define __SMBF	0x0800		/* buf is from malloc */
#endif
	int	size;		/* size of buffer */
	int	len;		/* characters read or written so far */
	int	(*put)(char, struct _myfiletype *);	/* function to write one char to device */
	int	(*get)(struct _myfiletype *);	/* function to read one char from device */
	void	*udata;		/* User defined and accessible data. */
}myfiletype;
#define FILE myfiletype
#endif

typedef enum{
    fifo_overwrite_off=0,fifo_overwrite_on=1
}fifo_stuff;

// typedef struct {
//            char (*method)(void*);
//            void *Handler;
////            VOLATILE bool ready;//:1;
//    }Input;
//    
//    typedef  struct {
//            void (*method)(void *, char);
//            void *Handler;
////            VOLATILE bool ready;//:1;
//    }Output;
    
//    typedef     struct {
//        void (*method)(int e, bool fatal, char *msg);
//        void *Handler;
//    } ErrorMan;
    
    

typedef struct {
    InputDev *stdi;
    OutputDev *stdo;
    OutputDev *stde;
    
    struct {
        char stdin_ready:1;
        char stdout_ready:1;
        char stderr_ready:1;
    };
    
    struct {
        char input_buffer[IOSTREAM_STDIN_BUFFER_LENGTH];
        fifo_t stdin_fifo;
    }data;
    
}StdIostream;

typedef enum {unknown_devtype=0, inputdev=1, outputdev=2} iostream_stuff;

// extern fifo_t STDERR_STREAM;
// extern char MYSTDERR[STDERR_SIZE];
 extern  StdIostream STDIOSTREAM;
//
// extern FILE mystdoutstream;
// extern FILE mystdinstream;

//
//void (*outMethod)() = (void*)MAIN_DEFAULT_PRINTING_METHOD;
//void *Screen = MAIN_DEFAULT_PRINTER;
//char (*readFrom)();
//void *Keyboard;

//#define getche() getch()

error_code_t iostream_init(StdIostream *io, InputDev *stdin_dev, OutputDev *stdout_dev, OutputDev *stderr_dev);
error_code_t stdout_init(OutputDev *stdo);
error_code_t stdin_init(InputDev *stdi);
error_code_t stderr_init(OutputDev *stde);
//error_code_t stdout_switch(void (*func)(void *, char), void *obj/*, void(*dosomething)()*/);
error_code_t stdout_switchTo(OutputDev *dev/*, void(*dosomething)()*/);
//signed char stdin_switch(char (*func)(void*), void *obj/*, void(*dosomething)()*/);
error_code_t stdin_switchTo(InputDev *dev/*, void(*dosomething)()*/);
error_code_t stderr_switchTo(OutputDev *dev);
//int iostream_putch(char data, FILE *stream);
//int iostream_getch(FILE *stream);
error_code_t printfTo(OutputDev *dev, const char *fmt, ...);
error_code_t printfToFifo(fifo_t *given_ff, bool reset, const char *fmt,...);
error_code_t putsTo(void *dev, const char *st, ...);
void mc_putch(char ch);
//void write(int handle, char *buf, unsigned len);
//char getche();
void donothing();

#ifndef MAIN_DEFAULT_PRINTING_METHOD
#define MAIN_DEFAULT_PRINTING_METHOD uart_putch
#endif
#ifndef MAIN_DEFAULT_SCREEN
#define MAIN_DEFAULT_SCREEN &STDUART
#endif
#ifndef MAIN_DEFAULT_INPUT_METHOD
#define MAIN_DEFAULT_INPUT_METHOD uart_getch
#endif
#ifndef MAIN_DEFAULT_KEYBOARD
#define MAIN_DEFAULT_KEYBOARD &STDUART
#endif

#define IO_STREAM_NAME "IOSTREAM"
#define IOSTREAM_VERSION "1.0"

#define STREAM_NULL_INPUT_DEVICE_ERROR -1
#define STREAM_NULL_OUTPUT_POINTER_ERROR -2
#define IOSTREAM_SUCCESS_RET 0
#define IOSTREAM_STDERR_INIT_FAILED_RET -3
#define IOSTREAM_STDOUT_INIT_FAILED_RET -4 //stdin_init informs a null output method has been assigned to mystdin
#define IOSTREAM_STDIN_INIT_FAILED_RET -5 //stdout_init informs a null output method has been assigned to mystdout
#define IOSTREAM_TARGET_OUTPUT_METHOD_NULL_RET -6 //stdout_switch informs a null output method has been assigned to mystdout
#define IOSTREAM_TARGET_OUTPUT_OBJECT_NULL_RET -7
#define IOSTREAM_TARGET_INPUT_METHOD_NULL_RET -8
#define IOSTREAM_TARGET_INPUT_OBJECT_NULL_RET -9
#define IOSTREAM_NULL_POINTER_RET -10
#define IOSTREAM_NULL_DEV_RET -11
#define IOSTREAM_DEV_NOT_READY_RET -12
#define IOSTREAM_TARGET_DEVICE_NOT_READY_RET -13
#define IOSTREAM_STDOUT_REINIT_FAILED_RET -14
#define IOSTREAM_STDOUT_SWITCH_FAILED_RET -15
#define IOSTREAM_INVALID_OUTPUT_RET -16
#define IOSTREAM_INVALID_INPUT_RET -17
#define IOSTREAM_STDIN_TARGET_DEVICE_INIT_FAILED_RET -18
#define IOSTREAM_STDOUT_TARGET_DEVICE_INIT_FAILED_RET -19
#define IOSTREAM_STDERR_TARGET_DEVICE_INIT_FAILED_RET -20
#define IOSTREAM_NULL_IO_FUNCTION_RET -21
#define IOSTREAM_GIVEN_FIFO_NOT_READY_RET -22
#define IOSTREAM_INIT_STDIN_FIFO_FAILED_RET -23

// extern fifo_t STDERR_STREAM;
// extern char MYSTDERR[STDERR_SIZE];

// extern FILE mystdoutstream;
// extern FILE mystdinstream;
 
// extern bool abc;
 
// #define mc_putch(x) iostream_putch(&STDIOSTREAM, (x))
//#define getch() iostream_getch(&STDIOSTREAM)

#endif	/* MYSTREAM_H */
