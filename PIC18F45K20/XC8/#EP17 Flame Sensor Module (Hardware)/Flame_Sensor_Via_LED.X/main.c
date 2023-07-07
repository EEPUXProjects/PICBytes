/* Exercise : Flame sensor output via LED.
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to simulate the flame sensor module when it detects a fire.
 *               Essentially it provides a digital output. Logic Low for a fire being detected and Logic HIGH for no detection.
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

    while (1)
    {   
        LED_Out_LAT = Flame_Sensor_PORT;// Reflect state of Flame Sensor on LED_Out pin. On or off.           
    }
}

/*
 End of File
*/
