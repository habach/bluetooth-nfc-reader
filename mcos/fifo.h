/* 
 * File:   buffer.h
 * Author: bnh
 *
 * Created on July 11, 2015, 10:35 PM
 */

#ifndef FIFO_H
#define	FIFO_H
//#include "main.h"
//#include "mcos.h"
//#include "application.h"

#include "fifo_type.h"
#include "error.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include "application.h"
//#include "iodev.h"

#ifndef ERROR_CLASS_ID_FIFO
#define ERROR_CLASS_ID_FIFO 1
#endif

#ifndef FIFO_DEFAULT_BUFFER_SIZE
#define FIFO_DEFAULT_BUFFER_SIZE 32
#endif
#ifndef FIFO_CLEAR_VALUE
#define FIFO_CLEAR_VALUE '\0'
#endif
#ifndef RIGID_MODE
#define RIGID_MODE 1
#endif


//#ifndef FIFO_DEBUGGING_EN
//#define FIFO_DEBUGGING_EN 0
//#endif
#if (FIFO_DEBUGGING_EN)
#ifndef UNFINISH_CONDITION_ALERT()
#define UNFINISH_CONDITION_ALERT() do{puts("FIFO_GETCH() EMPTY!");}while(0)
#endif
//#ifndef UNFINISH_CONDITION_ALERT_OFF
//#define UNFINISH_CONDITION_ALERT_OFF puts("FIFO_GETCH() OK.")
//#endif
#endif

#ifndef VOLATILE
//#define VOLATILE volatile
#endif

#ifndef INLINE
#define INLINE
#endif

#define FIFO_FULL_RET -1
#define FIFO_SUCCESS_RET 0
#define FIFO_NULL_POINTER_RET -2
#define FIFO_NULL_DATA_RET -3
#define FIFO_NULL_BUFFER_RET -4
#define FIFO_ZERO_DATA_SIZE_RET -5
#define FIFO_INVALID_P_RET -6
#define FIFO_INSUFFICIENT_SPACE_RET -7
#define FIFO_NOT_READY_RET -8
#define FIFO_STRING_NOT_FOUND -9
#define FIFO_WAIT_FOR_DATA_TIMEOUT_RET -10
#define FIFO_NULL_STRING_RET -11
#define FIFO_NULL_FUNC_OR_OBJ_RET -12
#define FIFO_SOURCE_NULL_POINTER_RET -13
#define FIFO_DEST_NULL_POINTER_RET -14
#define FIFO_SOURCE_NOT_READY_RET -15
#define FIFO_DEST_NOT_READY_RET -16
#define FIFO_SOURCE_EMPTIED_RET -17
#define FIFO_INVALID_RET -18
#define FIFO_EMPTIED_RET -19
#define FIFO_CUTS_SEPARATOR_CHAR_NOT_FOUND_RET -20
#define FIFO_WRITE_PROTECTION_RET -21
#define FIFO_EXPORT_TO_NULL_RET -22
#define FIFO_INVALID_BUFFER_RET -23
#define FIFO_OFFSET_OVER_RET -24
#define FIFO_OFFSET_FAILED_RET -25
#define FIFO_WAIT_FOR_CHAR_FAILED_RET -26
#define FIFO_NUMBER_OF_ST_GREATER_THAN_BITS_OF_RES_BUF_RET -27
#define FIFO_MATCHED_POS_RUNNING_OUT_RET -28;
#define FIFO_INVALID_INPUT_RET -29
#define FIFO_DELETE_CHAR_FAILURE_RET -30
#define FIFO_BYPASS_DATA_FAILURE_RET -31
#define FIFO_NULL_POINTER_OR_NOT_READY_RET -32
#define FIFO_CHAR_NOT_FOUND_RET -33
#define FIFO_INSERT_CHAR_FAILED_RET -34
#define FIFO_DELETEX_NULL_STRING_RET -35
#define FIFO_DETECT_BEGIN_END_CHAR_FAILED_RET -36

//#define VOLATILE

//typedef struct {
//    /*VOLATILE*/ char *buffer;
//    /*VOLATILE*/ unsigned buffer_size;
//    /*VOLATILE*/ char *pr;
//    /*VOLATILE*/ char *pw;
//    /*VOLATILE*/ char *pmax;
//    struct {
////        unsigned :2;
//         /*VOLATILE*/ bool overwrite_en:1; //Enable/disable overwriting the oldest unread data when fifo is full;
//       /*VOLATILE*/ bool full:1;
//        /*VOLATILE*/ bool emptied:1;
//        /*VOLATILE*/ bool overwrite_flag:1; //Will be set when 'overwriting' orccured.
//        /*VOLATILE*/ bool wr_protection:1;
//        /*VOLATILE*/ bool ready:1;
//    };
//} fifo_t;

typedef fifo_t lilo_t;

//typedef struct {
//    IoDev io;
//    fifo_t *fifo;
//}FiFo;

typedef struct _fifo_10_t {
    fifo_t ff10;
    char buf[10];
}fifo_10_t;

//#include "error.h"

error_code_t fifo_init (fifo_t *f);
error_code_t fifo_setup(fifo_t *f, char *buffer, unsigned buffer_size, bool write_protection, bool overwrite_en);
INLINE error_code_t _fifo_reset(fifo_t *f);
//INLINE bool fifo_isValid(fifo_t *f);
//INLINE bool fifo_isFull(fifo_t *f);
//INLINE bool fifo_isEmptied(fifo_t *f);
 
#if (!POOR_DEVICE)
INLINE
__attribute__((__always_inline__, optimize(1))) 
#endif
void fifo_putch(fifo_t *f, char ch);
 
#if (!POOR_DEVICE)
INLINE
__attribute__((__always_inline__, optimize(1))) 
#endif
void/*error_code_t*/ fifo_putch_safe(fifo_t *f, char ch);
 
#if (!POOR_DEVICE)
INLINE
__attribute__((__always_inline__, optimize(1))) 
#endif
char fifo_getch(fifo_t *f);
 
#if (!POOR_DEVICE)
INLINE
__attribute__((__always_inline__, optimize(1))) 
#endif
char fifo_getch_safe(fifo_t *f);
error_code_t fifo_gets(fifo_t *f, char *s);
INLINE unsigned fifo_bytesLeft(fifo_t *f);
INLINE unsigned fifo_bytesUsed(fifo_t *f);
error_code_t fifo_puts(fifo_t *f, char *data, unsigned datasize);
//INLINE bool fifo_isReady(fifo_t *f);
INLINE int fifo_trims(fifo_t *f, char *st, unsigned ms);
error_code_t fifo_trimc(fifo_t *f, char c, unsigned index);
error_code_t fifo_print(fifo_t *f);
error_code_t fifo_export(fifo_t *f, void(*func)(void*, char), void *obj);
error_code_t fifo_copy(fifo_t *fs, fifo_t *fd);
error_code_t fifo_move(fifo_t *fs, fifo_t *fd, unsigned len);
error_code_t fifo_moveUntil(fifo_t *fs, fifo_t *fd, char c);
fifo_t *fifo_lend(fifo_t *source_ff, fifo_t *dest_ff);
error_code_t fifo_gets_until(fifo_t *f, char *s, char c, unsigned char index);
error_code_t fifo_cutc(fifo_t *f, char *s, unsigned s_size, char c, unsigned index);
error_code_t fifo_deleteUntil(fifo_t *f, char c);
 
#if (!POOR_DEVICE)
INLINE
__attribute__((__always_inline__, optimize(1))) 
#endif
int fifo_search(fifo_t *f, int matched_pos, unsigned ms, char *st);
int fifo_waitForMsg(fifo_t *f, unsigned ms, bool newonly, const char *start_string, ...);
unsigned char fifo_checkForMsg(fifo_t *fifo, unsigned ms, int matched_pos, const char *st, ...);
INLINE void buffer_clear(char *buf, unsigned size);
INLINE error_code_t fifo_clear(fifo_t *f);
char *buffer_copy(char *to, const char *from, unsigned size);
void buffer_putsX(char *buf, const unsigned bufsize, const char *st,... );
void buffer_import (char *dest, unsigned dest_len, char *src);
INLINE unsigned fifo_freeBytes (fifo_t *f);
INLINE unsigned fifo_dataBytes (fifo_t *f);
INLINE error_code_t fifo_writeProtection(fifo_t *f, int state);
signed char fifo_checkNextUnreadFor(fifo_t *f, unsigned char number_of_chars, char ch, ... );
INLINE char *_fifo_prOffset(fifo_t *f, unsigned offset);
INLINE char *_fifo_pwOffset(fifo_t *f, unsigned offset);
error_code_t fifo_getsNum(fifo_t *f, char *res, unsigned char res_size, unsigned offset);
error_code_t _fifo_insertChar(fifo_t *ff, char ch, unsigned pos);
error_code_t _fifo_deleteX(fifo_t *ff, char *st, unsigned len, bool kill);
//int fifo_waitForCh(fifo_t *f, unsigned time, unsigned char number_of_chars_waiting_for, char start_ch, ...);
//INLINE bool fifo_isWrProtected(fifo_t *f);
//bool fifo_isOverwritten(fifo_t *f);

//#define fifo_isReady(x) (/*((x) && (x)->buffer && (x)->buffer_size) && */(x)->ready)
#define fifo_isEmptied(x) (fifo_isReady((x)) && (x)->emptied)
#define fifo_isOverwritten(x) ((x)->overwrite_flag)
#define fifo_isFull(x) (!fifo_isReady((x)) || (x)->full)
#define fifo_isWrProtected(x) (!fifo_isReady((x)) || ((x)->wr_protection))
#define fifo_isValid(x) ((x) && ((x)->buffer) && ((x)->buffer_size))
#define lilo_getch _fifo_backspace
#define lilo_init fifo_init
#define lilo_putch fifo_putch

void fifo_putN_msb_lsb(fifo_t *f, unsigned n);
int fifo_waitForCh(fifo_t *f, unsigned time, unsigned char number_of_chars, char start_ch, ...);
fifo_t _fifo_getDataFrom(fifo_t *source_ff, unsigned offset, unsigned datasize);
fifo_t _fifo_getDataFromUntil(fifo_t *source_ff, unsigned offset, signed char ch);
fifo_t _fifo_cloneDataFrom(fifo_t *source_ff, unsigned offset, unsigned clone_size);
fifo_t _fifo_cloneDataFromUntil(fifo_t *source_ff, unsigned offset, signed char ch);
fifo_t _fifo_make(char *buf, unsigned buf_size, bool takedata, bool write_protection, bool overwrite_en);
char _fifo_backspace(fifo_t *f);
void _fifo_destroy(fifo_t *f);
void _fifo_killData (fifo_t *f);
int _fifo_findAndKill(fifo_t *ff, int matched_pos, unsigned ms, char *st, unsigned st_size);
error_code_t fifo_scanForMsgs(fifo_t *f, char *res_buf, unsigned char bufsize, const char *st,...);
//void _fifo_backup(fifo_t *src_ff, fifo_t *dest_ff);
void _fifo_killUntil(fifo_t *ff, unsigned pos, char c);
int _fifo_search2KillSt(fifo_t *ff, int matched_pos, unsigned ms, char *st, unsigned st_size);
void _fifo_flush(fifo_t *ff);
void _fifo_trash(fifo_t *ff);
error_code_t _fifo_deleteChar(fifo_t *ff, char c, bool killolddata);
error_code_t fifo_putsX(fifo_t *f, const char *st,...);
error_code_t _fifo_deleteBlock(fifo_t *ff, unsigned blocksize);
error_code_t _fifo_backspaceBlock(fifo_t *ff, unsigned blocksize);
void _fifo_replaceCharWith(fifo_t *ff, char c, char with_c, int index);
fifo_t _fifo_cutX(fifo_t *ff, unsigned ms, const char *begin_st, const char *end_st);
fifo_t _fifo_cutC(fifo_t *f, char c, unsigned index);
bool fifo_isReady(fifo_t *f);
unsigned char fifo_checkForMsg_valist(fifo_t *fifo, unsigned ms, int matched_pos, va_list ap, const char *start_st_of_valist);
bool _fifo_anyNew(fifo_t *ff, char **last_pw);
error_code_t fifo_showData(fifo_t *ff);
INLINE int _fifo_checkForChar(fifo_t *ff, char ch);
void fifo_waitForReceive(fifo_t *ff, unsigned ms);
fifo_t *_fifo_rotate(fifo_t *ff);
void _fifo_toUpperCase(fifo_t *ff);
void _fifo_toLowerCase(fifo_t *ff);
error_code_t _fifo_getsSz(fifo_t *ff, char *s, unsigned sz);
error_code_t _fifo_detectBeginEndChar(fifo_t *ff, unsigned pos, char *begin_ch, char *end_ch);
unsigned _fifo_countForChar(fifo_t *ff, char ch);
fifo_t _fifo_getProgram(fifo_t *given_ff, int pos, char open_ch, char close_ch);



//#define fifo_nextCharIs(ff, ch) (!((ff)->emptied) && ((ff)->pr == (ch)))
//#define fifo_nextCharIsNot(ff, ch) (!((ff)->emptied) && ((ff)->pr != (ch)))
//#define _fifo_reset(x) do{(x)->pr = (x)->buffer; (x)->pw = (x)->buffer;(x)->emptied = 1;(x)->full = 0;(x)->overwrite_flag = 0;}while(0)

#ifdef MALLOC_READY
#endif
#endif	/* FIFO_H */
