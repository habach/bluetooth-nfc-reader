/* 
 * File:   error.h
 * Author: habach
 *
 * Created on July 12, 2015, 2:55 PM
 */

#ifndef ERROR_H
#define	ERROR_H
//#include "application.h"
//#include <stdint.h>
//#include <stdbool.h>
//#include "fifo.h"
#include <stdbool.h>

#ifndef MCOS_ERROR_CODE_RANGE
#define MCOS_ERROR_CODE_RANGE -10000
#endif
#ifndef MCOS_ERROR_CODE_ID_RANGE
#define MCOS_ERROR_CODE_ID_RANGE 100
#endif
#ifndef CLASS_ERROR_CODE_BASE
#define CLASS_ERROR_CODE_BASE 100
#endif

#ifndef ERROR_MSG_LENGTH
#define ERROR_MSG_LENGTH 64
#endif

#ifndef error_code_t
#define error_code_t signed char
#endif

#ifndef ERROR_REPORT_HEADER
#define ERROR_REPORT_HEADER "E:"
#endif

#define ERROR_REPORTER_NAME "ERR REP"
#define ERROR_LFCR "\n"
#define ERROR_FATAL_EXCEPTION_MSG "\nFatal exception. Halted."

/*DEVICE CODE TABLE*/
//#define MSOS_OBJECT_ID_UART -8278 //T9-code of "UART"
//#define MSOS_OBJECT_ID_MSOS -6767

#define ERROR_SUCCESS_RET 0
#define ERROR_REPORTER_NULL_ERR_STREAM_RET -1
#define ERROR_EXPORT_FAILED_RET -2
#define ERROR_PRINT_FAILED_RET -3
#define ERROR_ERRSTREAM_NULL_POINTER_RET -4
#define ERROR_CLEAR_FAILED_RET -5

//#include "fifo.h"

//error_code_t error_reportTo(char *devicename, error_code_t error, fifo_t *err_stream);
//error_code_t error_export(void(*func)(void*, char), void *obj); //Exports STDERR to device (lcd,uart,printer...)
//error_code_t error_print();
//int error_any(); //Check for error if any
//error_code_t error_clear(fifo_t *err_stream);
//int errorReport(int e, bool fatal, const char *emsg);
error_code_t errorReport(error_code_t e, unsigned char class_id, bool fatal, const char *emsg, ...);
error_code_t error_nop(error_code_t e);
//void error_fatal_exception_ledShow( int code);

#endif	/* ERROR_H */
