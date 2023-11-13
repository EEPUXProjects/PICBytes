/* Exercise : Bargraph alternating Example 
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to find the complement of the register with 
 * a built in delay function to visually see the two resulting outputs on Port C.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files    

// Main Program
void main(void)
{
    SYSTEM_Initialize();// Initialise the device parameters
    
    LATC = 0x55; // Load hex value of 0x55 into LATC.
    while (1)
    {
        LATC = ~LATC;		    // Load value of complemented LATC
        __delay_ms(300);	    // Short time delay
    }
}

/*
 End of File
*/