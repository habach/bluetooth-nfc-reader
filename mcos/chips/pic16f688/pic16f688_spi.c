/*
 * File:   pic24fj256gb106_spi_spi.c
 * Author: Administrator PC
 *
 * Created on July 15, 2016, 5:59 PM
 */


#include <xc.h>
#include "pic24fj256gb106_spi.h"
#include <stdlib.h>

low_iofuncs SPI_LOW_IOF[SPI_MODULES] = {
    {SPI1_Power,SPI1_Read,SPI1_Write}, 
    {SPI2_Power,SPI2_Read,SPI2_Write}, 
    {SPI3_Power,SPI3_Read,SPI3_Write},
    {SPI4_Power,SPI4_Read,SPI4_Write}
};
uart_cfgfunc SPI_LOW_CONFIG[SPI_MODULES] = {{SPI1_Config},{SPI2_Config},{SPI3_Config},{SPI4_Config}};


long spi_brrCalculate(long bitrate) {
    return ((_XTAL_FREQ / (bitrate << 2)) - 1);
}

long spi_bitRateCalculate(long brr) {
    return (_XTAL_FREQ / ((brr + 1) << 2));
}

long spi_bitRateErrorCalculate(long bitrate, long brr) {
    return labs((spi_bitRateCalculate(brr) - bitrate));
}

error_code_t pic24fj256gb106_spi_bitRateConfig(long bitrate) {
    long brr, error, error1;
//    TXSTA = 0; RCSTA = 0; // Reset USART registers to POR state    
//    CREN = 1; //Enables continuous reception
//    BRGH = 1; //Enables hi-speed bitrate (almost nowadays application use hi-speed bitrate)
//    BRG16 = 1; //Enables 16-bit (SPBRG register)
    brr = spi_brrCalculate(bitrate);
    if (brr < 0) return PIC24FJ256GB106_BITRATE_EXCEED_MAXIMUM_RATE_RET;
    if (brr > 255) return PIC24FJ256GB106_BITRATE_EXCEED_MINIMUM_RATE_RET;
    error = spi_bitRateErrorCalculate(bitrate, brr);
    error1 = spi_bitRateErrorCalculate(bitrate, brr + 1);
    if ( error1 < error) brr++;
    PR2 = brr;       // Write brr value to PR2
    return 0;
}
