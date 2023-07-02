/* Exercise : Left Shifting Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to use the left shift operator. 
 *               In this case we will see how the contents of the LATC register will be left shifted by a value of one 
 *               and then observe the results on a Bargraph display. Thereby , understanding the purpose of this operator.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files

// Main Program
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    LATC = 0x01;               // Load LATC with hex value 01.
    __delay_ms(100);           // Short delay of 100 milli seconds.
    while (1)
    {                           
        __delay_ms(100);           // Short delay of 100 milli seconds. 
        LATC = LATC << 1;          // Left shift the value of the LATC register by one.
        if(LATC == 0x80)           // If LATC is equal to hex value of 80, so the last LED on bargraph is illuminated.
            {
                __delay_ms(100);      // Short delay of 100 milli seconds.
                LATC = 0x01;          // Load hex value of 01 into LATC, to restart the sequence and return to the initial LED segment.
            }
    }
}
    
/*
 End of File
*/