/* Exercise : Potentiometer controlled Bargraph display via ADC.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be interfacing a Bargraph display and a 10K potentiometer. To have a visual of the 10 bit and 8 bit analogue to digital conversion taken from the potentiometer  
 *               input at port pin RA0. This demonstration will show the difference between the right justified and left justified conversion results concerning the ADC ADRESL & ADRESH registers.
 *		Set system to be right / left justified with MCC configutator.
 */

//Header Files
#include "mcc_generated_files/mcc.h" // Include neccesary header files.


/*Main application*/
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        ADC_GetConversion(0);
        LATD = ADRESL; // Display contents of ADRESL in Port D 
        LATB = ADRESH; // Display contents of ADRESH in Port B 
        //Left Justified = 8 bit result in ADRESH , ignore 2 LSB in ADRESL.
        //Right Justified = 10 bit result with 8 bits in ADRESL and 2 MSB in ADRESH.
    }
}
/**
 End of File
*/