/* Exercise : Controlling the speed and direction of a DC motor.
 * Author : Usmaan H
 * Description: Controlling the speed of a DC motor via a 10k potentiometer connected to RA0 using the adc 
 *              and toggling two switches to control the direction.
 * Version : 1.0
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.


unsigned int ADC_Result;    //value to store ADC Conversion.

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
   
    while (1)
    {   
        ADC_Result = ADC_GetConversion(0); // Obtain 10 bit ADC value from channel 0.
        PWM2_LoadDutyValue(ADC_Result); // Write ADC value to Port RC1. "CCP2 Register". To adjust the speed.
        __delay_ms(50); // 50 millisecond delay.
        
        OUT_1_LAT  = IN_1_PORT; //Reflect state of port IN_1 on port OUT_1.
        OUT_2_LAT  = IN_2_PORT; //Reflect state of port IN_2 on port OUT_2.      
    }
}
/**
 End of File
*/