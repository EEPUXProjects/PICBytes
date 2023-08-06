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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F45K20
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

// get/set RED aliases
#define RED_TRIS                 TRISCbits.TRISC0
#define RED_LAT                  LATCbits.LATC0
#define RED_PORT                 PORTCbits.RC0
#define RED_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RED_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RED_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RED_GetValue()           PORTCbits.RC0
#define RED_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RED_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set GREEN aliases
#define GREEN_TRIS                 TRISCbits.TRISC1
#define GREEN_LAT                  LATCbits.LATC1
#define GREEN_PORT                 PORTCbits.RC1
#define GREEN_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define GREEN_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define GREEN_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define GREEN_GetValue()           PORTCbits.RC1
#define GREEN_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define GREEN_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set BLUE aliases
#define BLUE_TRIS                 TRISCbits.TRISC2
#define BLUE_LAT                  LATCbits.LATC2
#define BLUE_PORT                 PORTCbits.RC2
#define BLUE_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define BLUE_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define BLUE_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define BLUE_GetValue()           PORTCbits.RC2
#define BLUE_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define BLUE_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

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