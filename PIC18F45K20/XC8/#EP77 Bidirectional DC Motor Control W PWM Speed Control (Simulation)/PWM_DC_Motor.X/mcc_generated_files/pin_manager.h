/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F45K20
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20 and above
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_ANS                  ANSELbits.ANS0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELbits.ANS0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELbits.ANS0 = 0; } while(0)

// get/set OUT_1 aliases
#define OUT_1_TRIS                 TRISBbits.TRISB0
#define OUT_1_LAT                  LATBbits.LATB0
#define OUT_1_PORT                 PORTBbits.RB0
#define OUT_1_WPU                  WPUBbits.WPUB0
#define OUT_1_ANS                  ANSELHbits.ANS12
#define OUT_1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define OUT_1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define OUT_1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define OUT_1_GetValue()           PORTBbits.RB0
#define OUT_1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define OUT_1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define OUT_1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define OUT_1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define OUT_1_SetAnalogMode()      do { ANSELHbits.ANS12 = 1; } while(0)
#define OUT_1_SetDigitalMode()     do { ANSELHbits.ANS12 = 0; } while(0)

// get/set OUT_2 aliases
#define OUT_2_TRIS                 TRISBbits.TRISB1
#define OUT_2_LAT                  LATBbits.LATB1
#define OUT_2_PORT                 PORTBbits.RB1
#define OUT_2_WPU                  WPUBbits.WPUB1
#define OUT_2_ANS                  ANSELHbits.ANS10
#define OUT_2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define OUT_2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define OUT_2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define OUT_2_GetValue()           PORTBbits.RB1
#define OUT_2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define OUT_2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define OUT_2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define OUT_2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define OUT_2_SetAnalogMode()      do { ANSELHbits.ANS10 = 1; } while(0)
#define OUT_2_SetDigitalMode()     do { ANSELHbits.ANS10 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set IN_1 aliases
#define IN_1_TRIS                 TRISDbits.TRISD0
#define IN_1_LAT                  LATDbits.LATD0
#define IN_1_PORT                 PORTDbits.RD0
#define IN_1_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IN_1_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IN_1_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IN_1_GetValue()           PORTDbits.RD0
#define IN_1_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IN_1_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

// get/set IN_2 aliases
#define IN_2_TRIS                 TRISDbits.TRISD1
#define IN_2_LAT                  LATDbits.LATD1
#define IN_2_PORT                 PORTDbits.RD1
#define IN_2_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IN_2_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IN_2_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IN_2_GetValue()           PORTDbits.RD1
#define IN_2_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IN_2_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/