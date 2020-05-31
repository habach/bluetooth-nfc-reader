/**
  System Interrupts Generated Driver File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the MPLAB(c) Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLAB(c) Code Configurator interrupts.
    Generation Information : 
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC24FJ256GB106
    The generated drivers are tested against the following:
        Compiler          :  XC16 1.32
        MPLAB             :  MPLAB X 3.61

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


/**
    Section: Includes
*/
#include <xc.h>

//#pragma config WPFP = WPFP511    // Write Protection Flash Page Segment Boundary->Highest Page (same as page 170)
//#pragma config WPDIS = WPDIS    // Segment Write Protection Disable bit->Segmented code protection disabled
//#pragma config WPCFG = WPCFGDIS    // Configuration Word Code Page Protection Select bit->Last page(at the top of program memory) and Flash configuration words are not protected
//#pragma config WPEND = WPENDMEM    // Segment Write Protection End Page Select bit->Write Protect from WPFP to the last page of memory
//
//// CONFIG2
//#pragma config POSCMOD = NONE    // Primary Oscillator Select->Primary oscillator disabled
//#pragma config DISUVREG = OFF    // Internal USB 3.3V Regulator Disable bit->Regulator is disabled
//#pragma config IOL1WAY = ON    // IOLOCK One-Way Set Enable bit->Write RP Registers Once
//#pragma config OSCIOFNC = ON    // Primary Oscillator Output Function->OSCO functions as port I/O (RC15)
//#pragma config FCKSM = CSDCMD    // Clock Switching and Monitor->Both Clock Switching and Fail-safe Clock Monitor are disabled
//#pragma config FNOSC = FRCPLL    // Oscillator Select->Fast RC oscillator with Postscaler and PLL module (FRCPLL)
//#pragma config PLL_96MHZ = ON    // 96MHz PLL Disable->Enabled
//#pragma config PLLDIV = DIV2    // USB 96 MHz PLL Prescaler Select bits->Oscillator input divided by 2 (8MHz input)
//#pragma config IESO = ON    // Internal External Switch Over Mode->IESO mode (Two-speed start-up) enabled
//
//// CONFIG1
//#pragma config WDTPS = PS32768    // Watchdog Timer Postscaler->1:32768
//#pragma config FWPSA = PR128    // WDT Prescaler->Prescaler ratio of 1:128
//#pragma config WINDIS = OFF    // Watchdog Timer Window->Standard Watchdog Timer enabled,(Windowed-mode is disabled)
//#pragma config FWDTEN = OFF    // Watchdog Timer Enable->Watchdog Timer is disabled
//#pragma config ICS = PGx2    // Comm Channel Select->Emulator functions are shared with PGEC2/PGED2
//#pragma config BKBUG = OFF    // Background Debug->Device resets into Operational mode
//#pragma config GWRP = OFF    // General Code Segment Write Protect->Writes to program memory are allowed
//#pragma config GCP = OFF    // General Code Segment Code Protect->Code protection is disabled
//#pragma config JTAGEN = OFF    // JTAG Port Enable->JTAG port is disabled

//#ifndef EZBL_BOOT_PROJECT 
#if defined __PIC24FJ1024GB606__
#pragma config BWRP = OFF    //Boot Segment Write-Protect bit->Boot Segment may be written
#pragma config BSS = DISABLED    //Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
#pragma config BSEN = OFF    //Boot Segment Control bit->No Boot Segment
#pragma config GWRP = OFF    //General Segment Write-Protect bit->General Segment may be written
#pragma config GSS = DISABLED    //General Segment Code-Protect Level bits->No Protection (other than GWRP)
#pragma config CWRP = OFF    //Configuration Segment Write-Protect bit->Configuration Segment may be written
#pragma config CSS = DISABLED    //Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
#pragma config AIVTDIS = OFF    //Alternate Interrupt Vector Table bit->Disabled AIVT

// FBSLIM
#pragma config BSLIM = 8191    //Boot Segment Flash Page Address Limit bits->8191

// FOSCSEL
#pragma config FNOSC = FRC    //Oscillator Source Selection->FRC
#pragma config PLLMODE = PLL96DIV2    //PLL Mode Selection->96 MHz PLL. (8 MHz input)
#pragma config IESO = ON    //Two-speed Oscillator Start-up Enable bit->Start up device with FRC, then switch to user-selected oscillator source

// FOSC
#pragma config POSCMD = NONE    //Primary Oscillator Mode Select bits->Primary Oscillator disabled
#pragma config OSCIOFCN = ON    //OSC2 Pin Function bit->OSC2 is general purpose digital I/O pin
#pragma config SOSCSEL = ON    //SOSC Power Selection Configuration bits->SOSC is used in crystal (SOSCI/SOSCO) mode
#pragma config PLLSS = PLL_FRC    //PLL Secondary Selection Configuration bit->PLL is fed by the on-chip Fast RC (FRC) oscillator
#pragma config IOL1WAY = ON    //Peripheral pin select configuration bit->Allow only one reconfiguration
#pragma config FCKSM = CSECME    //Clock Switching Mode bits->Both Clock switching and Fail-safe Clock Monitor are enabled

// FWDT
#pragma config WDTPS = PS32768    //Watchdog Timer Postscaler bits->1:32768
#pragma config FWPSA = PR128    //Watchdog Timer Prescaler bit->1:128
#pragma config FWDTEN = OFF    //Watchdog Timer Enable bits->WDT and SWDTEN disabled
#pragma config WINDIS = OFF    //Watchdog Timer Window Enable bit->Watchdog Timer in Non-Window mode
#pragma config WDTWIN = WIN25    //Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
#pragma config WDTCMX = WDTCLK    //WDT MUX Source Select bits->WDT clock source is determined by the WDTCLK Configuration bits
#pragma config WDTCLK = LPRC    //WDT Clock Source Select bits->WDT uses LPRC

// FPOR
#pragma config BOREN = ON    //Brown Out Enable bit->Brown Out Enable Bit
#pragma config LPCFG = OFF    //Low power regulator control->No Retention Sleep
#pragma config DNVPEN = ENABLE    //Downside Voltage Protection Enable bit->Downside protection enabled using ZPBOR when BOR is inactive

// FICD
#pragma config ICS = PGD2    //ICD Communication Channel Select bits->Communicate on PGEC2 and PGED2
#pragma config JTAGEN = OFF    //JTAG Enable bit->JTAG is disabled
#pragma config BTSWP = OFF    //BOOTSWP Disable->BOOTSWP instruction disabled

// FDEVOPT1
#pragma config ALTCMPI = DISABLE    //Alternate Comparator Input Enable bit->C1INC, C2INC, and C3INC are on their standard pin locations
#pragma config TMPRPIN = OFF    //Tamper Pin Enable bit->TMPRN pin function is disabled
#pragma config SOSCHP = ON    //SOSC High Power Enable bit (valid only when SOSCSEL = 1->Enable SOSC high power mode (default)
#pragma config ALTVREF = ALTVREFDIS    //Alternate Voltage Reference Location Enable bit->VREF+ and CVREF+ on RB0, VREF- and CVREF- on RB1

// FBOOT
#pragma config BTMODE = SINGLE    //Boot Mode Configuration bits->Device is in Single Boot (legacy) mode
#elif defined __PIC24FJ256GB106__
#pragma config WPFP = WPFP511    // Write Protection Flash Page Segment Boundary->Highest Page (same as page 170)
#pragma config WPDIS = WPDIS    // Segment Write Protection Disable bit->Segmented code protection disabled
#pragma config WPCFG = WPCFGDIS    // Configuration Word Code Page Protection Select bit->Last page(at the top of program memory) and Flash configuration words are not protected
#pragma config WPEND = WPENDMEM    // Segment Write Protection End Page Select bit->Write Protect from WPFP to the last page of memory

// CONFIG2
#pragma config POSCMOD = NONE    // Primary Oscillator Select->Primary oscillator disabled
#pragma config DISUVREG = OFF    // Internal USB 3.3V Regulator Disable bit->Regulator is disabled
#pragma config IOL1WAY = ON    // IOLOCK One-Way Set Enable bit->Write RP Registers Once
#pragma config OSCIOFNC = ON    // Primary Oscillator Output Function->OSCO functions as port I/O (RC15)
#pragma config FCKSM = CSDCMD    // Clock Switching and Monitor->Both Clock Switching and Fail-safe Clock Monitor are disabled
#pragma config FNOSC = FRCPLL    // Oscillator Select->Fast RC oscillator with Postscaler and PLL module (FRCPLL)
#pragma config PLL_96MHZ = ON    // 96MHz PLL Disable->Enabled
#pragma config PLLDIV = DIV2    // USB 96 MHz PLL Prescaler Select bits->Oscillator input divided by 2 (8MHz input)
#pragma config IESO = ON    // Internal External Switch Over Mode->IESO mode (Two-speed start-up) enabled

// CONFIG1
#pragma config WDTPS = PS32768    // Watchdog Timer Postscaler->1:32768
#pragma config FWPSA = PR128    // WDT Prescaler->Prescaler ratio of 1:128
#pragma config WINDIS = OFF    // Watchdog Timer Window->Standard Watchdog Timer enabled,(Windowed-mode is disabled)
#pragma config FWDTEN = OFF    // Watchdog Timer Enable->Watchdog Timer is disabled
#pragma config ICS = PGx2    // Comm Channel Select->Emulator functions are shared with PGEC2/PGED2
#pragma config BKBUG = OFF    // Background Debug->Device resets into Operational mode
#pragma config GWRP = OFF    // General Code Segment Write Protect->Writes to program memory are allowed
#pragma config GCP = OFF    // General Code Segment Code Protect->Code protection is disabled
#pragma config JTAGEN = OFF    // JTAG Port Enable->JTAG port is disabled
#elif defined _PIC16F688_H_
#pragma config FOSC = INTOSCIO   // Oscillator Selection bits (EXTRCIO oscillator: External RC on RA5/OSC1/CLKIN, I/O function on RA4/OSC2/CLKOUT pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON      // MCLR Pin Function Select bit (MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF       // Brown Out Detect (BOR enabled)
#pragma config IESO = OFF        // Internal External Switchover bit (Internal External Switchover mode is enabled)
#pragma config FCMEN = OFF       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
//#pragma config SCS = 1       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
//#define _XTAL_FREQ 4000000
//#define FCY 1000000
#endif
//#endif

//#include "mcc.h"
#include "board_manager_generic.h"
#include "../../mychips.h"
//#include "../../global_var.h"


void SYSTEM_Initialize(void)
{
    OSCILLATOR_Initialize();
    BOARD_Initialize();
    INTERRUPT_Initialize();    
    ADC1_Initialize();
//#if (!RTCC_AVAILABLE || !RTCC_ENABLED)
//    TMR1_Initialize();
//#else
//    RTCC_Initialize();
//#endif
//    TMR2_Initialize(3);
//    TMR3_Initialize(3);
////    SPI1_Initialize();
//#if (MYCHIP == PIC24FJ1024GB606)
//    I2C3_Initialize();
//#endif

}

void OSCILLATOR_Initialize(void) {
#if (MYCHIP == PIC24FJ256GB106)
    // NOSC FRCPLL; SOSCEN disabled; POSCEN disabled; OSWEN Switch is Complete; 
    __builtin_write_OSCCONL((uint8_t) (0x0100 & 0x00FF));
    // CPDIV 1:1; RCDIV FRC/1; DOZE 1:8; DOZEN disabled; ROI disabled; 
    CLKDIV = 0x3000;
    // TUN Center frequency; 
    OSCTUN = 0x0000;
    // ROEN disabled; ROSEL disabled; RODIV Base clock value; ROSSLP disabled; 
    REFOCON = 0x0000;
#elif (MYCHIP == PIC24FJ1024GB606)
//     // ROEN disabled; ROSEL FOSC; ROSIDL disabled; ROSWEN disabled; ROOUT disabled; ROSLP disabled; 
//    REFOCONL = 0x0000;
//    // RODIV 0; 
//    REFOCONH = 0x0000;
//    // ROTRIM 0; 
//    REFOTRIML = 0x0000;
//    // DCOTUN 0; 
//    DCOTUN = 0x0000;
//    // DCOFSEL 8; DCOEN disabled; 
//    DCOCON = 0x0700;
//    // DIV 0; 
//    OSCDIV = 0x0000;
//    // TRIM 0; 
//    OSCFDIV = 0x0000;
//    // CF no clock failure; NOSC FRCPLL; SOSCEN enabled; POSCEN disabled; CLKLOCK unlocked; OSWEN Switch is Complete; IOLOCK not-active; 
//    __builtin_write_OSCCONH((uint8_t) ((0x0102 >> _OSCCON_NOSC_POSITION) & 0x00FF));
//    __builtin_write_OSCCONL((uint8_t) ((0x0102 | _OSCCON_OSWEN_MASK) & 0xFF));
    CLKDIV = 0x3000;
    // STOR disabled; STORPOL Interrupt when STOR is 1; STSIDL disabled; STLPOL Interrupt when STLOCK is 1; STLOCK disabled; STSRC SOSC; STEN disabled; TUN Center frequency; 
    OSCTUN = 0x00;
    // ROEN disabled; ROSEL FOSC; ROSIDL disabled; ROSWEN disabled; ROOUT disabled; ROSLP disabled; 
    REFOCONL = 0x00;
    // RODIV 0; 
    REFOCONH = 0x00;
    // ROTRIM 0; 
//    REFOTRIML = 0x00;
    // DCOTUN 0; 
    DCOTUN = 0x00;
    // DCOFSEL 8; DCOEN disabled; 
    DCOCON = 0x700;
    // DIV 0; 
    OSCDIV = 0x00;
    // TRIM 0; 
    OSCFDIV = 0x00;
    // AD1MD enabled; T3MD enabled; T4MD enabled; T1MD enabled; U2MD enabled; T2MD enabled; U1MD enabled; SPI2MD enabled; SPI1MD enabled; T5MD enabled; I2C1MD enabled; 
    PMD1 = 0x00;
    // OC5MD enabled; OC6MD enabled; OC7MD enabled; OC8MD enabled; OC1MD enabled; IC2MD enabled; OC2MD enabled; IC1MD enabled; OC3MD enabled; OC4MD enabled; IC6MD enabled; IC7MD enabled; IC5MD enabled; IC8MD enabled; IC4MD enabled; IC3MD enabled; 
    PMD2 = 0x00;
    // I2C3MD enabled; PMPMD enabled; U3MD enabled; RTCCMD enabled; CMPMD enabled; CRCMD enabled; I2C2MD enabled; 
    PMD3 = 0x00;
    // U4MD enabled; USB1MD enabled; CTMUMD enabled; REFOMD enabled; LVDMD enabled; 
    PMD4 = 0x00;
    // IC9MD enabled; OC9MD enabled; 
    PMD5 = 0x00;
    // SPI3MD enabled; 
    PMD6 = 0x00;
    // DMA1MD enabled; DMA0MD enabled; 
    PMD7 = 0x00;
    // U5MD enabled; CLC3MD enabled; CLC4MD enabled; CLC1MD enabled; CLC2MD enabled; U6MD enabled; 
    PMD8 = 0x00;
    // CF no clock failure; NOSC FRCPLL; SOSCEN disabled; POSCEN disabled; CLKLOCK unlocked; OSWEN Switch is Complete; IOLOCK not-active; 
    __builtin_write_OSCCONH((uint8_t) ((0x100 >> _OSCCON_NOSC_POSITION) & 0x00FF));
    __builtin_write_OSCCONL((uint8_t) ((0x100 | _OSCCON_OSWEN_MASK) & 0xFF));
    // Wait for Clock switch to occur
    while (OSCCONbits.OSWEN != 0);
    while (OSCCONbits.LOCK != 1);
#elif (MYCHIP == PIC16F688)
    OSCCONbits.SCS = 1;
    OSCCON_FREQUENCY_SETUP;
    OSCTUNE = 0;
#endif
}


/**
    void PIN_MANAGER_Initialize(void)
*/
void BOARD_Initialize(void) {
    

//    ANSEL_C_SETUP; //set digital mode for RC0-RC3
//    ANSEL_SETUP; //set digital mode for RA0-RA3
//    COMPARATOR_CON = CMCON_SETUP;

    //Read device address set by 8-bit DIP swich 
    //read_DIP_switch();

//    LED_TRIS = LED_TRIS_SETUP; //Sets direction for PORTA bits
//    if (LOCAL_RELAY_EN) LED_TRIS &= 0b11111011;
//    else LED_TRIS |= 0b00000100;
    
//    ANSELBITS_ADCS = ADC_CLOCK_SETUP;
//    my_led_port.myleds = ALARM_CLEAR;
//    if (MODE == 0) {
//        //Setup interrupt-on-change of GP3 only
//        INTCON_GPIF = 0;
//        IOC_CON = IOC_SETUP;
//        INTCON_GPIE = 1;
//        INTCON_GIE = 1;
//    }
} 

void ADC1_Initialize() {
    ANSEL_C_SETUP; //set digital mode for RC0-RC3
//    ANSEL_SETUP; //set digital mode for RA0-RA3
    COMPARATOR_CON = CMCON_SETUP;
    
    ANSELBITS_ADCS = ADC_CLOCK_SETUP;
}

void INTERRUPT_Initialize() {
//    INTCON_GPIF = 0;
        IOC_CON = IOC_SETUP;
//        INTCON_GPIE = 1;
        INTCON_GIE = 1;
}