/* Exercise : Interfacing Switches Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you three different ways of interfacing a push button on Port B. External pull up, pull down and internal pull up.
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
    {   // External Pull up
//        if(SW0_PORT == LOW) { // If switch pressed and logic changed from high to low.
//            __delay_ms(100);      //Debounce delay part 1.
//            LED_LAT = HIGH;   // LED Enabled.
//        }                     // If switch released and logic changed from low to high.
//        else {LED_LAT = LOW;} // LED Disabled.
        
//        //External Pull  down       
//        if(SW1_PORT == HIGH) {    //If switch pressed and logic changed from low to high.
//            __delay_ms(100);      //Debounce delay part 1.          
//            LED_LAT = HIGH;    // LED Enabled.
//        }                      // If switch released and logic changed from high to low.
//        else {LED_LAT = LOW;}  // LED Disabled.
//        
        // Internal Pull up
        if(SW2_PORT == LOW) { // If switch pressed and logic changed from high to low.
            __delay_ms(100);      //Debounce delay part 1.   
            LED_LAT = HIGH;   // LED Enabled.
        }                     // If switch released and logic changed from low to high.
        else {LED_LAT = LOW;} // LED Disabled.
    }
}

/*
 End of File
*/