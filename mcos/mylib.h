/* 
 * File:   mylib.h
 * Author: bnh
 *
 * Created on July 16, 2015, 10:33 PM
 */

#ifndef MYLIB_H
#define	MYLIB_H
//#include "msos.h"
#include "mcos.h"
//#include "error.h"
#include "fifo.h"

#define MYLIB_SUCCESS_RET 0
#define MYLIB_BUFFER_NULL_P_RET -1
#define MYLIB_MEM_NULL_P_RET -2

typedef enum {
    dir_lef = 0, dir_right = 1
}mem_stuff;

typedef union {
    unsigned long long whole;
    struct {
        unsigned char byte0;
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
        unsigned char byte5;
        unsigned char byte6;
        unsigned char byte7;
    };
}longest_int;

//#ifndef min
//#define	min(a,b)	(((a) < (b)) ? (a) : (b))
//#endif
//
//#ifndef max
//#define	max(a,b)	(((a) > (b)) ? (a) : (b))
//#endif

//extern char *utoa(char * buf, unsigned val, int base);
//
//extern char *itoa(char * buf, int val, int base);
//extern char *ltoa(char * buf, long val, int base) ;
//char *ultoa(char * buf, unsigned long val, int base);

signed char mylib_memx_getsNum(char *res_buf, unsigned res_size, char *mem_pos, bool dir);
char *mylib_memx_testNum(char *mem_pos, bool dir);
unsigned long power(unsigned char x, unsigned char y);
void printDataTypeInfo();
int mylib_countChar(char *s, char c);
void *int_byte_rotate(void *var, size_t bytes);
fifo_t *ull2Fifo(fifo_t *ff, unsigned long long n, unsigned char n_base);
fifo_t *ll2Fifo(fifo_t *ff, long long n, unsigned char n_base);
char *ulltoa (char *buf, size_t buf_size, unsigned long long n, unsigned char n_base);
char *lltoa (char *buf, size_t buf_size, long long n, unsigned char n_base);

#endif	/* MYLIB_H */

