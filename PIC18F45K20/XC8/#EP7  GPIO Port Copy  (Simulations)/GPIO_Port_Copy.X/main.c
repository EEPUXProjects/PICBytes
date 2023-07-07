/* Exercise : GPIO Port Copy.
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to copy contents of one 8 bit register to another. 
 *               In this example we will copy from PORT C into PORT D.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files

// Main Program
void main(void)
{
    
    SYSTEM_Initialize(); // Initialize the device
    LATC = 0x00; // Load value 0x00 to LAT C.  
    while(1)
        {
            __delay_ms(250);    // Short delay of 250 milliseconds.   
            LATC++;             // Post increment contents of PORTC. 
            __delay_ms(250);    // Short delay of 250 milliseconds.
            LATD = LATC;        // Copy contents of PORTC into LATD.
        }
}

/*
 End of File
*/