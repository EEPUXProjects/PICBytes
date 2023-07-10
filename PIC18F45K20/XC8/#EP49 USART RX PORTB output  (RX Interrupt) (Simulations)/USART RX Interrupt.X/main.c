/* Exercise : USART Interrupt Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise demonstrates how you can use the USART Rx interrupt feature.
 * We will see while the PORT B register increments from 0 to 255 and then resets back to 0, and continues this in a cycle. 
 * The moment a user enters a character in the serial terminal. That characters binary equivalent will be shown on the bargraph display.
 * Demonstrating that the normal routine of the PIC is taking place and only when an Rx interrupt it generated that the PIC displays the binary equivalent of the character.
 * 
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h"

// Define Variables
unsigned char A = 0x00;	  // Assign a hex value of 0x00 to variable A 

//Functions
void MyPORTBISR (void); // My interrupt service routine
// Main Program
void main(void)
{
    SYSTEM_Initialize();  // Initialize the device parameters
    EUSART_SetRxInterruptHandler(MyPORTBISR); //Assign function o interrupt routine
    PIN_MANAGER_IOC(); 
    INTERRUPT_GlobalInterruptEnable();// Enable the Global Interrupts
    INTERRUPT_PeripheralInterruptEnable(); // Enable the Peripheral Interrupts
    LATB=A;               // Load value of variable A into LATB
    while (1)
    {                             
        LATB = A;         // Increment LATB directly.
        __delay_ms(100);  // Short time delay
        A++;              //Post increment variable A by 1

    }                          
}

void MyPORTBISR  (void){
    __delay_ms(10);      // short delay. 
    LATB = RCREG;        // Load value of USART RX register , directly into LATB register.
    EUSART_Write(RCREG);   //Transmit character via USART Transmission.
    __delay_ms(1000);    // 1 second delay. 
}

/*
 End of File
*/