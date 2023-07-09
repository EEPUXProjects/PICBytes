/* Exercise : Displaying serial USART character data via Bargraph display.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise the user inputs a character via USART and the received data is output on the Bargraph .
                 The user will be able to see the chracter in binary form.
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.

/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device.
    while (1)
    {       
        while(EUSART_is_rx_ready());// Waiting for user input.     
        LATB = EUSART_Read(); // Load value of EUSART register , directly into OUTPUT.
        __delay_ms(50);         // short delay of 50 milliseconds.       
    }
}


/**
 End of File
*/