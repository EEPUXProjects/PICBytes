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

// get/set LM35_IN aliases
#define LM35_IN_TRIS                 TRISAbits.TRISA0
#define LM35_IN_LAT                  LATAbits.LATA0
#define LM35_IN_PORT                 PORTAbits.RA0
#define LM35_IN_ANS                  ANSELbits.ANS0
#define LM35_IN_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LM35_IN_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LM35_IN_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LM35_IN_GetValue()           PORTAbits.RA0
#define LM35_IN_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LM35_IN_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LM35_IN_SetAnalogMode()      do { ANSELbits.ANS0 = 1; } while(0)
#define LM35_IN_SetDigitalMode()     do { ANSELbits.ANS0 = 0; } while(0)

// get/set L293D_IN1 aliases
#define L293D_IN1_TRIS                 TRISCbits.TRISC0
#define L293D_IN1_LAT                  LATCbits.LATC0
#define L293D_IN1_PORT                 PORTCbits.RC0
#define L293D_IN1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define L293D_IN1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define L293D_IN1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define L293D_IN1_GetValue()           PORTCbits.RC0
#define L293D_IN1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define L293D_IN1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set L293D_IN2 aliases
#define L293D_IN2_TRIS                 TRISCbits.TRISC2
#define L293D_IN2_LAT                  LATCbits.LATC2
#define L293D_IN2_PORT                 PORTCbits.RC2
#define L293D_IN2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define L293D_IN2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define L293D_IN2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define L293D_IN2_GetValue()           PORTCbits.RC2
#define L293D_IN2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define L293D_IN2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

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