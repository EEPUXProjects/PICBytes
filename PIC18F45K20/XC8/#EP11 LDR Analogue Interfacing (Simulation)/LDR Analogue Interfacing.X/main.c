/* Exercise : LDR_Analogue_Interfacing_Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be seeing how a LDR can be interfaced with the PIC to turn a LED on or off depending on the lighting conditions.
 */

//Header Files
#include "mcc_generated_files/mcc.h" // Include neccesary header files.

//Variables
unsigned int Light_Calibration =300;// Threshold value for switching LED on or off.
unsigned int result=0; // Store the 10 bit ADC result from channel RA0.

/*Main application*/
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        result = ADC_GetConversion(0); //Get Conversion Result From Channel 0.
        if ( result <= Light_Calibration) {
            LED_LAT= HIGH; // Turn LED ON.           
        }
        else if ( result > Light_Calibration) {
            LED_LAT= LOW; // Turn LED OFF.           
        }
    }
}
/**
 End of File
*/