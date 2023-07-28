/* Exercise : Simplest Switch controlled LED Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to control a LED with a switch connected via a pull up configuration.
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
        LED_CURRENT_SOURCE_LAT=SW_PORT; //The logic state of the switch is directly reflected on the LED 0n port C0.
        
    }
}

/*
 End of File
*/