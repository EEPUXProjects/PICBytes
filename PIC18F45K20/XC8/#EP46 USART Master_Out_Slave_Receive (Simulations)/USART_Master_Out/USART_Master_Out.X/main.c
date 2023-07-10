/* Exercise : Master Receiver Example Part 1 of 2.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this combined exercise the Master sends out the value of 0xAA and its 
 *               compliment via USART.
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.

//Define Functions
void USART_Character_Transmit(char Character); // Transmit character using USART.

//Variables
char RAM= 0xAA; // Variable "RAM" to store value 0xAA.

/*Main application*/
void main(void)
{
    SYSTEM_Initialize();// Initialize the device       
    while (1)
    {
    RAM = ~ RAM;  //Save complementary value of variable RAM into RAM. 
    USART_Character_Transmit(RAM);// Transmit character via USART, following correct procedures. "Wait until Transmitting register is available." 
    __delay_ms(500);  // half second delay.
    }
}

void USART_Character_Transmit(char character)
{  //Function that will send character data.
    while(!EUSART_is_tx_ready()); //wait for transmitter to be ready.
    EUSART_Write(character);  // send the character element in the array to the terminal.
    while (!EUSART_is_tx_done()); // wait until TX is done.    
}

/**
 End of File
*/