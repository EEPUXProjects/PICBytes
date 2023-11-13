/* Exercise : Right Shifting Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to right shift the value of the LATC register
 * by 1.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files

// Main Program
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
   
    LATC = 0x80;               // Load LATC with hex value 80 
    __delay_ms(100);           // Short delay of 100 milliseconds
    while (1)
    {                           
        LATC = LATC >> 1;          // Right shift the value of LATC by one
        __delay_ms(100);           // Short delay of 100 milliseconds
        
        if(LATC == 0x01)           // If LATC is equal to hex value of 01
            {
                LATC = 0x80;          // Load hex value of 80 into LATC
                __delay_ms(100);      // Short delay of 100 milliseconds               
            }
    }
 
}
/*
 End of File
*/