/* Exercise : Hardware PWM Servo Motor Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : To control servo via Hardware PWM.
 */

// Library Files
#include "mcc_generated_files/mcc.h" // Include MCC generated header files.

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        EPWM1_LoadDutyValue(31); //-90 Degrees. 
        __delay_ms(1000);        // 1000 millisecond delay.
        EPWM1_LoadDutyValue(47); //0 Degrees.
        __delay_ms(1000);        // 1000 millisecond delay.
        EPWM1_LoadDutyValue(63); //+90 Degrees.
        __delay_ms(1000);        // 1000 millisecond delay.
    }
 
}
/**
 End of File
*/