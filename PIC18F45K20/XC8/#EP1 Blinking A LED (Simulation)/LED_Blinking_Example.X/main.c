/* Exercise : LED_Blinking_Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to blink an LED 
 */

//Things to Remember
//Goto pin_manager.h for more info on using defined pins

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files

// Main Program
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    //Incomplete
    while (1)
    {   
        LED_1_LAT= HIGH;// Enable LED 
        __delay_ms(250);// short delay
        LED_1_LAT= LOW; // Disable LED 
        __delay_ms(250);// short delay                
    }
}

/*
 End of File
*/