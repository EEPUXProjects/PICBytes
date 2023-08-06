/* Exercise : USART Single Character Echo Program.
 * Author : Usmaan H
 * Version : 1.0
 * Description: In this exercise the user inputs a character and then that character is echoed in the Terminal.
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.

/*Main application*/
void main(void)
{
    SYSTEM_Initialize();// Initialize the device
    while (1)
    {
        while(!EUSART_is_rx_ready());// Waiting for user input.
        EUSART_Write(EUSART_Read());// Read user's input from the (RXREG) and write directly to the (TXREG).           
        __delay_ms(50);             // short delay.
    }
}
/**
 End of File
*/