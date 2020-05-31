#include "../../application.h"
#include "../../myuart.h"

extern uart_t STDUART;

void interrupt isr() {
    if (UART_RECEPT_FLAG_BIT) {
        fifo_putch_safe(/*&MB_QUEUE*/STDUART.data.rxfifo, UART_RECEIVER_REG);
        UART_RECEPT_FLAG_BIT = 0;
    }
    if (RAIF) {
//        BEEP = 1;
//        __delay_ms(500);
//        BEEP = 0;
        RAIF=0;
    }
}