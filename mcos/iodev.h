/* 
 * File:   device.h
 * Author: habach
 *
 * Created on July 12, 2015, 3:03 PM
 */

#ifndef DEVICE_H
#define	DEVICE_H
//#include "mcos.h" 
//#include "application.h"
#include "error.h"
#include <stdbool.h>
#include <stdint.h>
#include "fifo_type.h"
//#include "application.h"
//#include "myclock.h"
//#include "libs/mysocket.h"

#ifndef _ATTRIBUTE_WEAK_
#define _ATTRIBUTE_WEAK_
#endif

#ifndef CHAR_VAR_LIST_MAX
#define CHAR_VAR_LIST_MAX 16
#endif

#define DEV_SUCCESS_RET 0
#define DEV_NULL_POINTER_RET -1
#define DEV_NOT_READY_RET -2
#define DEV_NOT_OUTPUT_DEVICE_RET -3
#define DEV_ZERO_DATASIZE_RET -4
#define DEV_OUTPUT_FIFO_EMPTIED_RET -5
#define DEV_OUTPUT_FIFO_NOT_READY_RET -6
#define DEV_NULL_OUTPUT_METHOD_RET -7
#define DEV_NULL_OUTPUT_FIFO_RET -8
#define IODEV_GIVEN_FIFO_NOT_READY_RET -9
#define IODEBV_NULL_SENDFIFO_METHOD_RET -10


typedef enum {
    iodev_uart=0x00,
    iodev_lcd=0x01,
    iodev_led7=0x02,
    iodev_rgb_led = 0x03,
    iodev_single_led=0x04,
            iodev_gsm = 0x05,
            iodev_other=255
} io_device_code_t;

typedef enum {
    devtype_unidentified = 0,
    devtype_input = 1,
            devtype_output = 2,
            devtype_input_output = 3
}iodev_stuff;

typedef struct {
    char (*readByte)(void *);
    error_code_t (*gets)(void *, char *);
}input_t;

typedef struct {
    void (*writeByte)(void *, char);
    error_code_t (*writeSt)(void *, char *, unsigned);
    error_code_t (*sendFifo)(void*, fifo_t*);
}output_t;

typedef struct {
    void (*power)(bool);
    char (*getch)();
    void (*putch)(char);
}low_iofuncs;

typedef struct {
/******************************************************************************/
//STANDARD I/O DEVICE WITH STRICT STRUCTURE IN ORDER TO BE CONVERTABLE
//THUS, PLEASE DONT CHANGE THE ORDER OF FOLLOWING CODES WITHOUT WELL-KNOWN
/******************************************************************************/    
    void *obj; //CAUTION! THIS OBJECT POINTER MUST BE AT THE TOP.
//#if (!POOR_DEVICE)
//    if (!(io->name)) io->name = (char*) IO_STREAM_NAME;
//#endif
    io_device_code_t devcode; //iodev_lcd=1, iodev_led7=2, iodev_single_led=4, iodev_uart=8, iodev_other=255
    error_code_t(*init)(void *);
    bool (*isReady)(void *);
    struct {
        unsigned char iotype;// : 2; //0: devtype_unidentified, 1: devtype_input, 2: devtype_output, 3: devtype_input_output (both input & output)
        bool shared;// : 1;
        bool ready;// : 1;
    };
}dev_t;

typedef struct {
/******************************************************************************/
//STANDARD I/O DEVICE WITH STRICT STRUCTURE IN ORDER TO BE CONVERTABLE
//THUS, PLEASE DONT CHANGE THE ORDER OF FOLLOWING CODES UNLESS WELL-KNOWN
/******************************************************************************/    
    dev_t dev;
    input_t input;
} InputDev;

typedef struct {
/******************************************************************************/
//STANDARD I/O DEVICE WITH STRICT STRUCTURE IN ORDER TO BE CONVERTABLE
//THUS, PLEASE DONT CHANGE THE ORDER OF FOLLOWING CODES UNLESS WELL-KNOWN
/******************************************************************************/    
    dev_t dev;
    output_t output;
//    fifo_t fifo;
} OutputDev;

typedef struct {
/******************************************************************************/
//STANDARD I/O DEVICE WITH STRICT STRUCTURE IN ORDER TO BE CONVERTABLE
//THUS, PLEASE DONT CHANGE THE ORDER OF FOLLOWING CODES UNLESS WELL-KNOWN
/******************************************************************************/
    dev_t dev;    
//    void *obj; //CAUTION! THIS OBJECT POINTER MUST BE AT THE TOP.
////#if (!POOR_DEVICE)
////    if (!(io->name)) io->name = (char*) IO_STREAM_NAME;
////#endif
//    io_device_code_t devcode; //iodev_lcd=1, iodev_led7=2, iodev_single_led=4, iodev_uart=8, iodev_other=255
//    error_code_t(*init)(void *);
//    bool (*isReady)(void *);
//    struct {
//        unsigned char iotype;// : 2; //0: devtype_unidentified, 1: devtype_input, 2: devtype_output, 3: devtype_input_output (both input & output)
//        bool shared;// : 1;
//        bool ready;// : 1;
//    };
    output_t output;
//    void (*writeByte)(void *, char);
//    error_code_t (*writeSt)(void *, char *, unsigned);
//    error_code_t (*sendFifo)(void*, fifo_t*);
    input_t input;
//    char (*readByte)(void *);
//    error_code_t (*gets)(void *, char *);
//    error_code_t (*getsFifo)(void*, fifo_t*);
    
    /*CAUTION: input_ff is a pointer to a pointer to a fifo*/
    /*This requires senior dev to handle*/
    fifo_t **input_ff;
    /*********************BE CAREFUL*************************/
    
    fifo_t *output_ff;
} IoDev;

typedef struct {
/******************************************************************************/
//STANDARD I/O DEVICE WITH STRICT STRUCTURE IN ORDER TO BE CONVERTABLE
//THUS, PLEASE DONT CHANGE THE ORDER OF FOLLOWING CODES UNLESS WELL-KNOWN
/******************************************************************************/
    void *obj; //CAUTION! THIS OBJECT POINTER MUST BE AT THE TOP.
//#if (!POOR_DEVICE)
//    if (!(io->name)) io->name = (char*) IO_STREAM_NAME;
//#endif
    io_device_code_t devcode; //iodev_lcd=1, iodev_led7=2, iodev_single_led=4, iodev_uart=8, iodev_other=255
    error_code_t(*init)(void *);
    bool (*isReady)(void *);
    struct {
        unsigned char iotype;// : 2; //0: devtype_unidentified, 1: devtype_input, 2: devtype_output, 3: devtype_input_output (both input & output)
        bool shared;// : 1;
        bool ready;// : 1;
    };  
    output_t output;
    input_t input;
    
    /*CAUTION: input_ff is a pointer to a pointer to a fifo*/
    /*This requires a "pointer expert" 2b able to handle well*/
    fifo_t **input_ff;
    /*********************BE CAREFUL*************************/
    
    fifo_t *output_ff;
} Stream;


typedef struct {
    void *obj;
    struct {
        char *mac;
    }info;
    
    struct {
        bool net_ok; //for case of checking net status
        bool ready; // for case of check device status
    } status;
    
    error_code_t (*init)(void *_obj);
    bool (*isReady)(void *_obj)_ATTRIBUTE_WEAK_;
    error_code_t (*open)(void *_obj)_ATTRIBUTE_WEAK_;
    error_code_t (*close)(void *_obj)_ATTRIBUTE_WEAK_;
    error_code_t (*openSocket)(void *_obj, void *_sk)_ATTRIBUTE_WEAK_;
    error_code_t (*closeSocket)(void *_obj, void *_sk)_ATTRIBUTE_WEAK_;
    bool (*isSocketConnected)(void *_obj, void *_sk)_ATTRIBUTE_WEAK_;
    bool (*isSocketAlive)(void *_obj, void *_sk)_ATTRIBUTE_WEAK_;
    bool (*isSocketOpened)(void *_obj, void *_sk)_ATTRIBUTE_WEAK_;
    error_code_t (*serverSwitch)(void *_obj, unsigned port, bool state);
//#include "myclock.h"    
    fifo_t (*deliverIpData)(void *_obj, signed char given_id, unsigned timeout, fifo_t *given_fifo)_ATTRIBUTE_WEAK_;
//    void (*socketPutch)(void*, char ch);
//    char (*socketGetch)(void*);
    int (*sendData)(void *_obj, void *socket, char *data, unsigned data_size, unsigned waitreply_t)_ATTRIBUTE_WEAK_;
//    int (*sendDataX)(void *obj, void *socket, bool waitreply, unsigned waitreply_t, char *data,...)_ATTRIBUTE_WEAK_;
    bool (*isNetworkAvailable)(void *_obj, bool surely);
    error_code_t (*getInternetTime)(void *_obj, int timezone, void *_tm);
}netfuncs_t;

error_code_t iodev_puts(void *_dev, char* data, unsigned size);
error_code_t iodev_putsX (void *_dev, char *st,... );
//fifo_t iodev_putsAndWaitFor(void *_dev, char *data, unsigned waiting_time_ms, bool trim_en, char* expected_st);
fifo_t iodev_putsAndWaitFor(IoDev *dev, char *data, unsigned data_size, fifo_t *wait_ff, unsigned waiting_time_ms, signed char cut_mode, char *expected_st);
int iodev_checkForMsg(IoDev *dev, fifo_t *redirect_ff, unsigned timeout_ms, int pos, const char *st, ...);

void device_declareNetworkFuncs(netfuncs_t *netdev);
//void device_declareFuncs(iofuncs_t *iodevice);

void iodev_NOP0();
error_code_t iodev_NOP1(void *o1, void *o2);
error_code_t iodev_NOP2(void *o, char *d, unsigned sz);
bool iodev_NOP3(void*);
void iodev_NOP4(void*, char);
error_code_t iodev_NOP5(void *o1, void *o2, char *d, unsigned sz);
error_code_t iodev_NOP6(void *o);
char iodev_NOP7(void *o);
error_code_t iodev_NOP8(void *o1, char *o2);

void iodev_declareNOPs();
OutputDev iodev_makeOutputDev(void *obj, error_code_t (*init)(void*), bool (*isReady)(void*), void (*wr)(void*, char), error_code_t (*writeSt)(void*, char*, unsigned));

#endif	/* DEVICE_H */

