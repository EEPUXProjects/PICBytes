/* Exercise : 8 bit LED Sequence 1
 * Author : Usmaan H
 * Version : 1.0
 * Description : LED Collision Explosion Sequence. 
 * 
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h"

//Variables
#define Delay 300 // Define LED delay value.

// Main Program
void main(void)
{
    SYSTEM_Initialize();  // Initialize the device parameters
    while (1)
    {   LATC = 0b10000001;  // Enable bits 0 and 7. All others are disabled.
        __delay_ms(Delay);  // Short time delay
        LATC = 0b01000010;  // Enable bits 1 and 6. All others are disabled.
        __delay_ms(Delay);  // Short time delay 
        LATC = 0b00100100;  // Enable bits 5 and 2. All others are disabled.  
        __delay_ms(Delay);  // Short time delay 
        LATC = 0b00011000;  // Enable bits 4 and 3. All others are disabled.
        __delay_ms(Delay);  // Short time delay 
        LATC = 0b00100100;  // Enable bits 5 and 2. All others are disabled. 
        __delay_ms(Delay);  // Short time delay 
        LATC = 0b01000010;  // Enable bits 1 and 6. All others are disabled.
        __delay_ms(Delay);  // Short time delay
    }                          
}

/*
 End of File
*/