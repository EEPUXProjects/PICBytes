/* Exercise : Transmit a message through USART.
 * Author : Usmaan H
 * Version : 1.0
 * Description: This tutorial is to demonstrate on how to send strings through the USART. 
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header Files.
#include <stdio.h> //  Standard Input Output handling Functions.
#include <string.h> // String Handing Functions.

//Define Functions
void USART_String_Transmit(char *string); // Transmit String using USART.

/*Main application*/
void main(void)
{
    SYSTEM_Initialize();// Initialize the device.

    USART_String_Transmit("\r\nHello World\r\n"); //USART welcome message.
    USART_String_Transmit("Im Using The USART Interface"); //USART welcome message.  
    while (1); // Remain in loop until processor reset.
}

//Function that will send string data
void USART_String_Transmit(char *string)
{   
    while(!EUSART_is_tx_ready()); //wait for transmitter to be ready.
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.
    while (!EUSART_is_tx_done()); // wait until TX is done.
}

/**
 End of File
*/