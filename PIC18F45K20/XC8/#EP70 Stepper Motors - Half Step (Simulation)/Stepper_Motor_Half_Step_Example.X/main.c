/* Exercise : Half step mode stepper motor example.
 * Author : Usmaan H
 * Description : Demonstrating stepper motor sequences in half step mode.
 * Version : 1.0
 */

// Include Necessary Header Files.
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.

//Motor Step Definitions
#define Step_Change_Speed 500 // Delay value for motor step change. 
#define Port LATB // Define LATB as Port for motor connections.
#define Step_1 0x01 // Turn Clockwise 45 degrees.
#define Step_2 0x03 // Turn Clockwise 90 degrees.
#define Step_3 0x02 // Turn Clockwise 135 degrees.
#define Step_4 0x06 // Turn Clockwise 180 degrees.
#define Step_5 0x04 // Turn Clockwise 225 degrees.
#define Step_6 0x0C // Turn Clockwise 270 degrees.
#define Step_7 0x08 // Turn Clockwise 315 degrees.
#define Step_8 0x09 // Turn Clockwise 360 degrees.

//Motor step sequence array.
unsigned char Half_Step_Sequence_Clockwise[8] = {Step_1,Step_2,Step_3,Step_4,Step_5,Step_6,Step_7,Step_8}; // Half step array.

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    PIN_MANAGER_IOC();// Disable/Enable interrupts.
    while (1)
    {
        // Half Step Sequence
        for (int i = 0; i < 8; i++) 
        {
            Port = Half_Step_Sequence_Clockwise[i]; //Run through half step sequence
            __delay_ms(Step_Change_Speed);          // Execute step delay
        }                 
    }
}


/**
 End of File
*/