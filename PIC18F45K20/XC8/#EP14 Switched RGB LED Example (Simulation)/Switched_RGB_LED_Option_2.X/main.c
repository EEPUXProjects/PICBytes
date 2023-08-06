/* Exercise : Switched RGB LED Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : Cycling the colour of the common cathode RGB LED with a switch. 
 * This code can be used if you have the first three pins of the port available. This will only work with these conditions. 
 */

// Include Libraries
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {  
    // Condition for pressing switch SW0.    
    if(SW0_PORT == LOW){
        __delay_ms(500); // Switch debounce delay. Adjust as needed.
        while(SW0_PORT == LOW); // Wait for switch to be released.
        LATC++; // Increment LATC register by one.
    }
 
    }
}
/**
 End of File
*/