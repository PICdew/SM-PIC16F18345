/**
  CWG1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    cwg1.c

  @Summary
    This is the generated driver implementation file for the CWG1 driver using MPLAB(c) Code Configurator

  @Description
    This header file provides implementations for driver APIs for CWG1.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - v3.00
        Device            :  PIC16F18345
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.20
*/

/*
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
  Section: Included Files
*/

#include <xc.h>
#include "cwg1.h"

/**
  Section: CWG1 APIs
*/

void CWG1_Initialize(void)
{
    // Set the CWG1 to the options selected in MPLAB(c) Code Configurator

    // Writing to CWGxCON0, CWGxCON1, CWGxCON2, CWGxDBR & CWGxDBF registers

    // CWG1IN 0; CWG1POLA non inverted; CWG1POLC non inverted; CWG1POLB inverted; CWG1POLD non inverted; 
    CWG1CON1 = 0x02;

    // CWG1DBR 0; 
    CWG1DBR = 0x00;

    // CWG1DBF 0; 
    CWG1DBF = 0x00;

    // CWG1SHUTDOWN No Auto-shutdown; CWG1REN disabled; CWG1LSBD inactive; CWG1LSAC inactive; 
    CWG1AS0 = 0x00;

    // AS3E disabled; AS4E disabled; AS0E disabled; AS2E disabled; AS1E disabled; 
    CWG1AS1 = 0x00;

    // CWG1CS FOSC; 
    CWG1CLKCON = 0x00;

    // CWG1STRD disabled; CWG1STRB enabled; CWG1STRC disabled; CWG1STRA enabled; CWG1OVRD low; CWG1OVRA high; CWG1OVRB high; CWG1OVRC low; 
    CWG1STR = 0x33;

    // IS PWM5_OUT; 
    CWG1DAT = 0x07;
    
    // CWG1LD Buffer_not_loaded; CWG1EN enabled; CWG1MODE Steering mode; 
    CWG1CON0 = 0x80;
}


void CWG1_AutoShutdownEventSet()
{
    // Setting the SHUTDOWN bit of CWGxAS0 register
    CWG1AS0bits.CWG1SHUTDOWN = 1;
}

void CWG1_AutoShutdownEventClear()
{
    // Clearing the SHUTDOWN bit of CWGxAS0 register
    CWG1AS0bits.CWG1SHUTDOWN = 0;
}

/**
 End of File
*/
