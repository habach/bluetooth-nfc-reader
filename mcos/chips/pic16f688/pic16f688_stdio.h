/* 
 * File:   pic24fj256gb106_stdio.h
 * Author: Administrator PC
 *
 * Created on July 16, 2016, 11:11 AM
 */

#ifndef PIC24FJ256GB106_STDIO_H
#define	PIC24FJ256GB106_STDIO_H
#include <stdarg.h>
#include <stdio.h>
//#include <conio.h>
//#include "application.h"
//#include <stdio.h>
//#include <conio.h>
//#include "myiostream.h"

#define iostream_loadStdioDriver pic24fj256gb106_stdioInit
#define iostream_loadStdoutDriver pic24fj256gb106_stdoutInit
#define iostream_loadStdinDriver pic24fj256gb106_stdinInit

#define DOPRINTF(x,y) do{\
struct	__prbuf	pb;\
pb.ptr = 0;\
pb.func = mc_putch;\
_doprnt(&pb, (x), (y));\
}while(0)



#ifdef	__cplusplus
extern "C" {
#endif
    
    extern struct __prbuf Pic18_Stdout;
    extern struct __prbuf Pic18_Stdin;
    
    void pic24fj256gb106_stdioInit();
    void pic24fj256gb106_stdoutInit();
    void pic24fj256gb106_stdinInit();
//    void write(int handle, char *buf, unsigned len);
//    void read(int handle, char *buf, unsigned len);
//#define stdout Pic18_Stdout.func
    
//#define mc_putch(x) iostream_putch((x), NULL)
//#define getch() iostream_getch(NULL)
//#define getche() getch()

#ifdef	__cplusplus
}
#endif

#endif	/* PIC24FJ256GB106_STDIO_H */

