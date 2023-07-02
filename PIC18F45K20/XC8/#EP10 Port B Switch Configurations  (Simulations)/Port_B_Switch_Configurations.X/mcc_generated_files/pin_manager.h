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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.3
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

// get/set SW0 aliases
#define SW0_TRIS                 TRISBbits.TRISB0
#define SW0_LAT                  LATBbits.LATB0
#define SW0_PORT                 PORTBbits.RB0
#define SW0_WPU                  WPUBbits.WPUB0
#define SW0_ANS                  ANSELHbits.ANS12
#define SW0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define SW0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define SW0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define SW0_GetValue()           PORTBbits.RB0
#define SW0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define SW0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define SW0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define SW0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define SW0_SetAnalogMode()      do { ANSELHbits.ANS12 = 1; } while(0)
#define SW0_SetDigitalMode()     do { ANSELHbits.ANS12 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISBbits.TRISB1
#define SW1_LAT                  LATBbits.LATB1
#define SW1_PORT                 PORTBbits.RB1
#define SW1_WPU                  WPUBbits.WPUB1
#define SW1_ANS                  ANSELHbits.ANS10
#define SW1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SW1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SW1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SW1_GetValue()           PORTBbits.RB1
#define SW1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SW1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SW1_SetAnalogMode()      do { ANSELHbits.ANS10 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELHbits.ANS10 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISBbits.TRISB2
#define SW2_LAT                  LATBbits.LATB2
#define SW2_PORT                 PORTBbits.RB2
#define SW2_WPU                  WPUBbits.WPUB2
#define SW2_ANS                  ANSELHbits.ANS8
#define SW2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SW2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SW2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SW2_GetValue()           PORTBbits.RB2
#define SW2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SW2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SW2_SetAnalogMode()      do { ANSELHbits.ANS8 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELHbits.ANS8 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISDbits.TRISD0
#define LED_LAT                  LATDbits.LATD0
#define LED_PORT                 PORTDbits.RD0
#define LED_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LED_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LED_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LED_GetValue()           PORTDbits.RD0
#define LED_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)

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