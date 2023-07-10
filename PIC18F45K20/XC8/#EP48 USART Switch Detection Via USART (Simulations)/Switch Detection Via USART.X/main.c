/* Exercise : Switch Detection Via USART.
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you how to detect a switch press and see it output on USART.
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.
#include <stdio.h> //  Standard Input Output handling Functions.
#include <string.h> // String Handing Functions.

//Define Functions
void USART_String_Transmit(char *string); // Transmit String using USART.

// Main Program
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {   
        if(SW0_PORT == LOW){
            __delay_ms(100);      //Debounce delay part 1.
            USART_String_Transmit("\r\nSwitch Press Detected : )\r\n"); //USART message.
        }
        else {
            USART_String_Transmit("\r\nSwitch Press Not Detected\r\n"); //USART message.         
        }
    }
}

//Function that will send string data
void USART_String_Transmit(char *string)
{   
    while(!EUSART_is_tx_ready()); //wait for transmitter to be ready.
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.
    while (!EUSART_is_tx_done()); // wait until TX is done.
}


/*
 End of File
*/