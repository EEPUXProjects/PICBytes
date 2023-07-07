/* Exercise : LDR_Digital_Interfacing_Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be seeing how a LDR can be interfaced with the PIC to turn a LED on or off depending on the lighting conditions.
 */

// Things to Remember
//Goto pin_manager.h for more info on using defined pins

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files

// Main Program
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {   
        LED_LAT=LDR_PORT; //The logic state of the comparator output is directly reflected on the LED 0n port C0.
        
    }
}

/*
 End of File
*/