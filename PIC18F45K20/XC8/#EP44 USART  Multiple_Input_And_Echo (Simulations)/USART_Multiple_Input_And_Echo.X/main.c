/* Exercise : USART Multi Input Multi Output.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise the user input's 5 characters in the serial terminal
 * and then those character are stored and then echoed back in the Terminal via the serial USART interface. 
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.
#include <stdio.h> //  Standard Input Output handling Functions.
#include <string.h> // String Handing Functions.

// Variables
char User_Input[5];          // Character array to store user inputs.  
char ASCII_Conversion [50] ; // Store string for USART transmition.

//Define Functions
void USART_String_Transmit(char *string); // Transmit String using USART.
void USART_String_Receive(char *buffer, unsigned char len); // Receive String using USART.

/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device
    USART_String_Transmit("\r\nWelcome to the RS232 Interface");//USART Welcome message.  
    while (1)
    {
    USART_String_Transmit("\r\nInput 5 characters: ");  //USART instruction message.   
    USART_String_Receive(User_Input,6); //Enter up to 5 characters and store in variable User_Input. 
    sprintf(ASCII_Conversion,"%s %c %c %c %c %c","\r\nCharacter Input: ",User_Input[0],User_Input[1],User_Input[2],User_Input[3],User_Input[4]); //Convert User_Input[] variable's into strings and concatenate with responce text.
    USART_String_Transmit(ASCII_Conversion);// Output string from variable ASCII_Conversion on USART.
    __delay_ms(50);                            // Short delay.      
    }
}

void USART_String_Transmit(char *string)
{   //Function that will send string data
    while(!EUSART_is_tx_ready()); //wait for transmitter to be ready.
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.
    while (!EUSART_is_tx_done()); // wait until TX is done.    
}


 void USART_String_Receive(char *buffer, unsigned char len)
	{ //Function that processes incoming string data
	  char i;    // Length counter.
	  unsigned char data; // Store incoming USART data.
	
	  for(i=0;i<len;i++)  // Only retrieve length of characters
	  {
	    data = EUSART_Read();    // Get a character from the USART.
	                           // and save in the string.
	    *buffer = data;
	    buffer++;              // Increment the string pointer.
	  }
	}

/**
 End of File
*/