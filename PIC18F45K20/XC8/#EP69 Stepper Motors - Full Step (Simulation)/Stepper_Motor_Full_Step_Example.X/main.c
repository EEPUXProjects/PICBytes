/* Exercise : Full step mode stepper motor example.
 * Author : Usmaan H
 * Description : Demonstrating stepper motor sequences in full step mode.
 * Version : 1.0
 */

// Include Necessary Header Files.
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.

//Motor Step Definitions
#define Step_Change_Speed 500 // Delay value for motor step change. 
#define Port LATB // Define LATB as Port for motor connections.
#define Step_2 0x03 // Turn Clockwise 90 degrees.
#define Step_4 0x06 // Turn Clockwise 180 degrees.
#define Step_6 0x0C // Turn Clockwise 270 degrees.
#define Step_8 0x09 // Turn Clockwise 360 degrees.

//Motor step sequence array
unsigned char Full_Step_Sequence_Clockwise[4] = {Step_2,Step_4,Step_6,Step_8}; // Full step array.

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    PIN_MANAGER_IOC();// Enable / Disable interrupts
    
    while (1)
    {  
        // Full Step Sequence
        for (int i = 0; i < 5; i++) 
        {
            Port = Full_Step_Sequence_Clockwise[i]; //Run through full step sequence
            __delay_ms(Step_Change_Speed);          // Execute step delay
        }             
    }
}


/**
 End of File
*/