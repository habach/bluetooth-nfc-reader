/* 
 * File:   myeeprom.h
 * Author: bnh
 *
 * Created on June 22, 2014, 5:53 PM
 */

#ifndef MYEEPROM_H
#define	MYEEPROM_H

//#include <xc.h>
//#include "mcos.h"
#include <stdbool.h>
#include "ioPort.h"
//#include "mcc_generated_files/memory.h"
#include "error.h"
#include "mychips.h"
#include "application.h"

#ifndef eeprom_index_t
#define eeprom_index_t uint16_t
#endif

#ifndef EEPROM_DEBUGGING
#define EEPROM_DEBUGGING 0
#endif
#ifndef EEPROM_POOR_DEVICE_FORCE_ENALED
#define EEPROM_POOR_DEVICE_FORCE_ENALED 0
#endif


/********* AUTO CALCULATION FOR EEPROM MANAGEMENT CONFIGS. *********/
/*   DO NOT EDIT FOLLOWING CODES UNLESS YOU KNOW WELL WHAT TO DO   */
/*******************************************************************/
//The last byte which locates at the end of eeprom is used as FORMAT_FLAG
#define EEPROM_FORMAT_FLAG_INDEX (EEPROM_SIZE_IN_BYTES-1)
#if (EEPROM_SIZE_IN_BYTES <= 256)
    typedef unsigned char eeprom_addr_t;
    #define EEPROM_SIZE_LE256
    #define EEPROM_ADDR_POINTER_MAX 65535
    #define BYTES_USED_FOR_MANAGEMENT 2    
    //The first byte which locates at the start of eeprom is used as address pointer
    #define EEPROM_ADDR_POINTER_INDEX 0    
#elif (EEPROM_SIZE_IN_BYTES <= 65536)
    typedef uint16_t eeprom_addr_t;
    #define EEPROM_SIZE_LE65K    
    #define EEPROM_ADDR_POINTER_MAX 16777215L
    #define BYTES_USED_FOR_MANAGEMENT 3
    //The first two bytes locate at the start of eeprom are used as address pointer
    #define EEPROM_ADDR_POINTER_L_INDEX 0
    #define EEPROM_ADDR_POINTER_H_INDEX (EEPROM_ADDR_POINTER_L_INDEX+1)
#endif
#define EEPROM_VALID_START_INDEX (BYTES_USED_FOR_MANAGEMENT-1)
#define EEPROM_VALID_END_INDEX (EEPROM_SIZE_IN_BYTES-2)
#if (EEPROM_DATA_WIDTH_BITS == 8)
#define EEPROM_DATA_MAX 0xFF
#elif (EEPROM_DATA_WIDTH_BITS == 16)
#define EEPROM_DATA_MAX 0xFFFF
#endif
/*********************************************************************/

#define EEPROM_SUCCESS_RET 0
#define EEPROM_NOT_ALLOCATED_RET -1    
#define EEPROM_INVALID_BLOCK_RET -2
#define EEPROM_ALLOCATED_LOCATION_NAME_NOT_FOUND_RET -3
    
typedef enum {
    eeprom_format_unknown = 0, eeprom_not_formatted = 1, eeprom_formatted = 2,
    eeprom_usage_unknown = 0, eeprom_usage_emptied = 1, eeprom_usage_full = 2, eeprom_usage_inuse = 3
} eeprom_stuff;

typedef struct {
	eeprom_index_t block_address;
    eeprom_addr_t block_size;
}eeprom_data_block;

typedef struct {    
    eeprom_addr_t used_bytes;
    eeprom_addr_t available_bytes;
    float used_percent;
    eeprom_index_t wr_cursor;
    struct {
        unsigned char format_status:2;
        unsigned char usage_status:3;
    };
} eeprom_info;

typedef struct {
    unsigned *address_reg;
    unsigned *data_reg;
    ioport_t *control_reg1;
    ioport_t *buffer;
}eeprom_controller;

//extern const mc_eeprom_size_t MC_Eeprom_Size;

eeprom_addr_t eeprom_alloc(eeprom_info *romstat, const char *block_id, eeprom_addr_t size);
eeprom_addr_t eeprom_calloc(eeprom_info *romstat, const char *block_id, eeprom_addr_t size);
//eeprom_addr_t eeprom_realloc(eeprom_addr_t size);
eeprom_addr_t eeprom_delete(eeprom_info *romstat, const char *block_id, eeprom_index_t pos, eeprom_addr_t sz);
void eeprom_getInfo(eeprom_info *romstat);
error_code_t eeprom_putData(eeprom_info *romstat, const char *block_id, eeprom_index_t pos, eeprom_addr_t sz, char *data);
error_code_t eeprom_getData(eeprom_info *romstat, const char *block_id, eeprom_index_t pos, eeprom_addr_t sz, char *buffer);
void eeprom_factoryReset(eeprom_info *romstat);
void eeprom_quickFormat(eeprom_info *romstat);
void eeprom_updateAddrPointer(eeprom_info *romstat, eeprom_addr_t index);
bool eeprom_isBlockValid(eeprom_info *romstat, eeprom_index_t loc, eeprom_addr_t sz);
bool eeprom_isBlockAllocated(eeprom_info *romstat, eeprom_index_t loc, eeprom_addr_t sz);
void eeprom_init(eeprom_info *romstat);
void eeprom_printInfo(eeprom_info *romstat);
eeprom_index_t eeprom_search(eeprom_info *romstat, const char *block_id);
eeprom_index_t eeprom_dataLocation(eeprom_info *romstat, const char *block_id, eeprom_index_t pos);
void eeprom_test(eeprom_info *eep);
void eeprom_dump();

#ifndef eeprom_writeByte 
bool eeprom_writeByte(eeprom_addr_t address, char data);
#endif
#ifndef eeprom_readByte
bool eeprom_readByte(char *buffer, eeprom_addr_t address);
#endif

extern eeprom_info STDEEPROM_INFO;

#endif	/* MYEEPROM_H */
