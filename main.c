 /*
 * File:   main.c
 * Author: hiclab
 *
 * Created on April 14, 2019, 12:13 PM
 */

#include <xc.h>
#include <stdbool.h>
#include <string.h>
#include "mcos/application.h"
#include "mcos/mydelay.h"
#include "mcos/myuart.h"
#include "mcos/ioPort.h"
#include "mcos/myeeprom.h"
#include "mcos/fifo.h"

void RFID_nEN(bool state);
void publishEvent(fifo_t *f);
void halt(unsigned char s);

extern uart_t STDUART;

bool input_old = 1;
//error_t Error;
char buf[6];
extern params_t Params;
extern fifo_t MB_QUEUE;

#define EE_PARAMS_ID "Para"

#define onBUS() do{MAX485_TX_EN=1;}while(0);
#define offBUS() do{__delay_ms(1);MAX485_TX_EN=0;}while(0);
#define onRF() do{RFID_nEN(0);}while(0);
#define offRF() do{RFID_nEN(1);}while(0);

void main(void) {
    char c;
//    int pos;
    char *p;
    unsigned sz;
    fifo_t tmp;
    
    SYSTEM_Initialize();
    
    BEEP_DDR = 0; 
    
    offBUS();

    RF_nEN = 1;
    RF_nEN_DDR = 0;

    MAX485_TX_EN_DDR = 0;
    INPUT1_DDR = INPUT;
    INPUT1_INTERRUPT_EN();
    //    setup();    
    BEEP = 1;
    MB_QUEUE = _fifo_make(MODBUS_BUFFER, MODBUS_BUFFER_SIZE, false, false, false);
    STDUART.data.rxfifo = &MB_QUEUE;
    STDUART.params.rxint = 1;
    uart_init(&STDUART);
    __delay_ms(100);
    
    
    eeprom_init(&STDEEPROM_INFO);
    if (STDEEPROM_INFO.usage_status <= eeprom_usage_emptied) {
        eeprom_alloc(&STDEEPROM_INFO, EE_PARAMS_ID, sizeof (Params));
        eeprom_putData(&STDEEPROM_INFO, EE_PARAMS_ID, 0, sizeof(Params), (char*)&Params);
    }
    eeprom_getData(&STDEEPROM_INFO, EE_PARAMS_ID, 0, sizeof(Params), (char*)&Params);    
    BEEP = 0;

    while (1) {
        if (!MB_QUEUE.emptied) {
            fifo_waitForReceive(&MB_QUEUE, 5);
            tmp = MB_QUEUE;
            if ( 0 < fifo_trims(&tmp, (char*) "+TAG:", 0)) {   
            } else {
                tmp=MB_QUEUE; 
                if (0 < fifo_trims(&tmp, (char*) "cfg", 0)) {
                    while (!tmp.emptied && (c=fifo_getch(&tmp)) != '-' && c != '?');
                    if (c == '-') {
                        switch(*tmp.pr) {
                            case 'a': case 'i':
                                if (0<fifo_getsNum(&tmp, buf, sizeof(buf), 0)) {
                                    if (*tmp.pr == 'a') {
                                        Params.ADDRESS = atoi(buf);
                                        p = (char*)&Params.ADDRESS;
                                        sz = sizeof(Params.ADDRESS);
                                    } else if (*tmp.pr == 'i') {
                                        Params.edge = atoi(buf);
                                        p = (char*)&Params.edge;
                                        sz = sizeof(Params.edge);
                                    }                                    
//                                    eeprom_putData(&STDEEPROM_INFO, EE_PARAMS_ID, p - (char*)&Params, sz, p);
                                    uart_puts(&STDUART, buf, 0);
                                }    
                                break;
                            case 'R':
//                                eeprom_factoryReset(&STDEEPROM_INFO);
                                return;
                            case 'r':
                                return;
                        }
                    } else if (c == '?') {
//                        uart_putsX(&STDUART, utoa(buf, Params.ADDRESS, 10), ",", NULL);
//                        uart_puts(&STDUART, utoa(buf, Params.edge, 10), 0);
                    }
                } 
            }
            _fifo_trash(&MB_QUEUE);            
        }
        if (INPUT1 != input_old) {
            if (Params.edge == 2 || INPUT1 == Params.edge) {
                BEEP = 1;
                __delay_ms(400);
                if (INPUT1 != input_old) {
                    publishEvent(NULL);
                }
            }
            input_old = INPUT1;
        }
        BEEP = 0;
    }
}

//void RFID_nEN(bool state) {
//    RF_nEN = state;
//    __delay_ms(1);
//}

void publishEvent(fifo_t *f) {
    char header[10] = {'X', 'B', 'U', 'S', '\0', '\0', '\0', '\0', '\0', '\0'};
    char c;
    uint16_t *len_p = (uint16_t *) &header[6];
    uint16_t buf_len;
    itoa(buf, Params.ADDRESS, 16);
    onBUS();
    header[4] = MASTER_ADDRRESS;
    header[5] = Params.ADDRESS;
    buf_len = strlen(buf);
    *len_p = strlen(ID_HEADER) + ((f) ? fifo_dataBytes(f) : buf_len) + buf_len + 1;
    uart_puts(&STDUART, header, 8);
    uart_putsX(&STDUART, (char*) ID_HEADER, (!f) ? buf : NULL, NULL);
    if (f) {
        while (!f->emptied && 47 < ((c = fifo_getch(f)))) {
            uart_putch(&STDUART, c);
        }
    }
    uart_putsX(&STDUART, (char*) "@", buf, (char*) END_ST, NULL);
    offBUS();
}

//void halt(unsigned char s) {
//    unsigned char _s = s;
//    while (!s || _s--) {
//        uart_putsX(&STDUART, (char*)"Halted on error: "
//                , itoa(buf, Error.whole, 10), (char*)"\r\n"
//                , NULL);
//        BEEP = ~BEEP;
//        __delay_ms(1000);
//    }
//}