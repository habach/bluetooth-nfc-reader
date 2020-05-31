/* 
 * File:   pic24fj256gb106_spi_spi.h
 * Author: Administrator PC
 *
 * Created on July 14, 2016, 9:19 PM
 */

#ifndef PIC24FJ256GB106_SPI_H
#define	PIC24FJ256GB106_SPI_H

//#include "application.h"
//#include <pic24fj256gb106.h>

//#define SPI_SLAVE

//#include <spi.h>
#ifndef SPI_SLAVE
#include "../../../mcc_generated_files/spi1_master.h"
#else
#include "../../../mcc_generated_files/spi1_slave.h"
#endif
#if (DEV_BOARD == AKS1708A)
#include "../../../mcc_generated_files/board_manager_aks1708a.h"
#elif (DEV_BOARD == AKS1708A_BT)
#include "../../../mcc_generated_files/board_manager_aks1708a_bt.h"
#else
#error "No board declaration!"
#endif

//#include "application.h"
//#include "../../ioPort.h"
#include "../../error.h"

#define SPI_MODULES 3

#define PIC24FJ256GB106_BITRATECONFIG_FAILED_RET -1
#define PIC24FJ256GB106_BITRATE_EXCEED_MAXIMUM_RATE_RET -2
#define PIC24FJ256GB106_BITRATE_EXCEED_MINIMUM_RATE_RET -3

//SPI PIN ASSIGNMENTS
//MC_SPI0
//#define SPI0_PORT ((VOLATILE ioPort8_t*)&PORTC)
//#define SPI0_TRIS ((VOLATILE ioPort8_t*)&TRISC)

//#define SDO_PORT_PIN ((VOLATILE ioPort8_t*)&PORTC)->p5
//#define SDO_TRIS_PIN ((VOLATILE ioPort8_t*)&TRISC)->p5
//#define SDI_PORT_PIN ((VOLATILE ioPort8_t*)&PORTC)->p4
//#define SDI_TRIS_PIN ((VOLATILE ioPort8_t*)&TRISC)->p4
//#define SS0_PORT_PIN ((VOLATILE ioPort8_t*)&PORTA)->p5
//#define SS0_TRIS_PIN ((VOLATILE ioPort8_t*)&TRISA)->p5
//#define SCK_PORT_PIN ((VOLATILE ioPort8_t*)&PORTC)->p3
//#define SCK_TRIS_PIN ((VOLATILE ioPort8_t*)&TRISC)->p3

//MC_SPI1
//#define SPI1_PORT ((VOLATILE ioPort8_t*)&PORTD)
//#define SPI1_TRIS ((VOLATILE ioPort8_t*)&DDRD)
//#define TRIS_TX1 SPI1_TRIS->p3
//#define TRIS_RX1 SPI1_TRIS->2
//#define TX1 SPI1_PORT->p3
//#define RX1 SPI1_PORT->p2
////MC_SPI2
//#define SPI2_PORT ((VOLATILE ioPort8_t*)&PORTH)
//#define SPI2_TRIS ((VOLATILE ioPort8_t*)&DDRH)
//#define TRIS_TX2 SPI2_TRIS->p1
//#define TRIS_RX2 SPI0_TRIS->p0
//#define TX2 SPI2_PORT->p1
//#define RX2 SPI2_PORT->p0
////SPI3
//#define SPI3_PORT ((VOLATILE ioPort8_t*)&PORTJ)
//#define SPI3_TRIS ((VOLATILE ioPort8_t*)&DDRJ)
//#define TRIS_TX3 SPI3_TRIS->p1
//#define TRIS_RX3 SPI0_TRIS->p0
//#define TX3 SPI3_PORT->p1
//#define RX3 SPI3_PORT->p0

//#define TRIS_DI_RO TRISC5
//#define DI_RO LATC5
//#define SPI_DI_RO_PIN_DIGITAL_ANALOG_MODE //must define digital mode for DI_RO control pin
//#define SPI_SPBRG_16BIT 1

//#define SPI_SYNC_SELECTION_bit SYNC
//#define SPI_RX_EN RCEN
//#define SPI_TX_EN TXEN
//#define SPI_ADDRESS_BIT_EN ADDEN
//#define SPI_ADDRESS_BIT_EN_1 
//#define SPI_ADDRESS_BIT_EN_2 
//#define SPI_ADDRESS_BIT_EN_3 
#define SPI_EN SPEN

#define SPI_BUFFER_FULL_FLAG_BIT_0 SSPSTATbits.BF
#define SPI_BUFFER_FULL_FLAG_BIT_1 0
#define SPI_BUFFER_FULL_FLAG_BIT_2 0
#define SPI_BUFFER_FULL_FLAG_BIT_3 0
#define SPI_BUFFER_REG_0 SSPBUF
//#define SPI_BUFFER_REG_1 SSPBUF
//#define SPI_BUFFER_REG_2 SSPBUF
//#define SPI_BUFFER_REG_3 SSPBUF
//#define SPI_BRR_FACTOR 2

//setup SPI module
//#define ANSEL_DI_RO_SETUP
//#define ALTERNATE_PIN_FUNCTION_TX_SETUP
//#define ALTERNATE_PIN_FUNCTION_RX_SETUP
//#define BITRATE_HISPEED_SETUP do{BRGH=1;}while(0) //High speed (baudrate = Fosc/[16(n+1)]), BRGH = 1 used for lowspeed: baudrate = Fosc/[64(n+1)]
//#define BITRATE_CALCULATION do{SPBRG=((_XTAL_FREQ/baudrate)/(BRGH?16:64))-1;}while(0)
//#define SPI_RETURN_IDDLE_STATE return(RCIDL)
//#define RX_IDLE RCIDL
#define SPI_CLOCK_POLARITY_0_SETUP(x) do{CKP1 = (x);} while(0)
#define SPI_CLOCK_POLARITY_1_SETUP(x) do{CKP2 = (x);} while(0)
#define SPI_CLOCK_POLARITY_2_SETUP(x) NOP()
#define SPI_CLOCK_POLARITY_3_SETUP(x) NOP()

#define SPI_INTERRUPT_0_SWITCH(x) do{SSPIF=0;SSPIE=(x);if((x))PEIE=1;}while(0)
#define SPI_INTERRUPT_1_SWITCH(x) NOP()
#define SPI_INTERRUPT_2_SWITCH(x) NOP()
#define SPI_INTERRUPT_3_SWITCH(x) NOP()

//#define SPI_TX_INTERRUPT_0_SWITCH(x) do{SSPIF=0;SSPIE=(x);if((x))PEIE=1;}while(0)
//#define SPI_TX_INTERRUPT_1_SWITCH(x) NOP()
//#define SPI_TX_INTERRUPT_2_SWITCH(x) NOP()
//#define SPI_TX_INTERRUPT_3_SWITCH(x) NOP()

#define SPI_CLOCK_EDGE_0_SWITCH(x) do{CKE1 = (x);}while(0)
#define SPI_CLOCK_EDGE_1_SWITCH(x) NOP()
#define SPI_CLOCK_EDGE_2_SWITCH(x) NOP()
#define SPI_CLOCK_EDGE_3_SWITCH(x) NOP()

#define SPI_SAMPLE_PHASE_0_SWITCH(x) do{SMP1 = (x);}while(0)
#define SPI_SAMPLE_PHASE_1_SWITCH(x) do{SMP2 = (x);}while(0)
#define SPI_SAMPLE_PHASE_2_SWITCH(x) NOP()
#define SPI_SAMPLE_PHASE_3_SWITCH(x) NOP()
#define SPI_BITRATE_0_SETUP(x) pic24fj256gb106_spi_bitRateConfig((x)) //NOP()
#define SPI_BITRATE_1_SETUP(x) error_nop(SPI_INVALID_SPINO_RET)
#define SPI_BITRATE_2_SETUP(x) error_nop(SPI_INVALID_SPINO_RET)
#define SPI_BITRATE_3_SETUP(x) error_nop(SPI_INVALID_SPINO_RET)
#define SPI_RX_0_SWITCH(x) do{SSPEN1=(x);}while(0)
#define SPI_RX_1_SWITCH(x) do{SSPEN2=(x);}while(0)
#define SPI_RX_2_SWITCH(x) NOP()
#define SPI_RX_3_SWITCH(x) NOP()

//SPI part specs
#define SPI_RX_FIFO_DEPTH 2

//#define SPI_TX_RX_DI_RO_TRIS_SETUP do{TRIS_TX=1;TRIS_RX=1;TRIS_DI_RO=0;}while(0)
//#define SPI_TX_RX_DI_RO_PORT_DIGITAL_SETUP
//#define SPI_SPBRG_LENGTH_SETUP(x) BRG16=(x)
//#define SPI_BITRATE_HISPEED_SETUP(x) do{BRGH=(x);}while(0) //High speed (baudrate = Fosc/[16(n+1)]), BRGH = 1 used for lowspeed: baudrate = Fosc/[64(n+1)]
//#define SPI_BITRATE_CALCULATION(x) do{SPBRG=((_XTAL_FREQ/(x))/(BRGH?16:64))-1;}while(0)
//#define SPI_BITRATE_CALCULATION(x) (((_XTAL_FREQ/(x))/(BRGH?16:64))-1)

//#define SPI_BITRATE_CALCULATION(x) ((_XTAL_FREQ/((x)<<4))-1)


//SPI ACTIVITIES
#define SPI0_open() SPI1_Initialize()
#define SPI1_open() NOP()
#define SPI2_open() NOP()
#define SPI3_open() NOP()
#define SPI0_close() NOP()
#define SPI1_close() NOP()
#define SPI2_close() NOP()
#define SPI3_close() NOP()
#define SPI0_read() SPI1_Exchange8bit(0)
#define SPI1_read() '\0'
#define SPI2_read() '\0'
#define SPI3_read() '\0'
#define SPI0_write(x) SPI1_Exchange8bit((x))
#define SPI1_write(x) NOP()
#define SPI2_write(x) NOP()
#define SPI3_write(x) NOP()
#define SPI0_busy() !SSPSTATbits.BF
#define SPI1_busy() 0
#define SPI2_busy() 0
#define SPI3_busy() 0
#define SPI0_dataReady() SPI_BUFFER_FULL_FLAG_BIT_0
#define SPI1_dataReady() SPI_BUFFER_FULL_FLAG_BIT_1
#define SPI2_dataReady() SPI_BUFFER_FULL_FLAG_BIT_2
#define SPI3_dataReady() SPI_BUFFER_FULL_FLAG_BIT_3

//error_code_t pic24fj256gb106_spi_baudconfig(unsigned char spiNo, unsigned long baud);
long spi_brrCalculate(long bitrate);
long spi_bitRateCalculate(long brr);
long spi_bitRateErrorCalculate(long bitrate, long brr);
error_code_t pic24fj256gb106_spi_bitRateConfig(long bitrate);

#endif	/* PIC24FJ256GB106_SPI_H */

