/* Exercise : Storing a Unsigned 16 Bit integer in internal EEPROM via USART
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we are using the serial terminal to save a Unsigned 16 Bit integer value in two EEPROM Registers and 
 * see it read back in decimal form on the USART Terminal.
 * Value Range : 0 to 65535. 
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.
#include <stdlib.h> // Standard library files.
#include <stdio.h> //  Standard Input Output handling Functions.
#include <string.h> // String Handing Functions.

//Definition
#define ADDRESS_1 0x00 // First Address Location.
#define ADDRESS_2 0x01 // Second Address Location.

// Variables
unsigned int Entered_Value; // Store value of written and read contents.
char ASCII_Conversion [50] ; // Store string for USART.

//Function Definitions
void USART_String_Transmit(char *string); // Transmit String Via USART.
void USART_String_Receive(char *buffer, unsigned char len); // Receive String Via USART.
unsigned int  Write_Int_To_EEPROM(int address, unsigned int number);// Write single integer to EEPROM.
unsigned int Read_Int_From_EEPROM(int address);// Read single integer from EEPROM.
 
/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device
    
    while(1){
    USART_String_Transmit("\r\n Enter EEPROM 5 Digit Number: ");// Output welcome string on UART.(Fill in zeros where not needed). e.g value 23. Enter 00023.
    USART_String_Receive(ASCII_Conversion,5); // Enter a 5 digit number with zeros filling in unused integers. Max value of upto 65535.
    Entered_Value = atoi(ASCII_Conversion); // Convert input string to integer.
    Write_Int_To_EEPROM(ADDRESS_1,Entered_Value);//Write integer value to EEPROM Address_1.
    Entered_Value = Read_Int_From_EEPROM(ADDRESS_1);//Read EEPROM Addresses with stored integer and copy in Entered_Value variable.
    sprintf(ASCII_Conversion,"%s %u","\r\n EEPROM Value : ", Entered_Value); //Convert Entered_Value variable into string and concatenate with existing text.
    USART_String_Transmit(ASCII_Conversion);// Output string on UART.
    __delay_ms(500);                   // Half Second Delay.  
    }
 }


 void USART_String_Transmit(char *string){  //Function that will send string data.
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.
       
  }
 
 void USART_String_Receive(char *buffer, unsigned char len)
	{
	  char i;    // Length counter.
	  unsigned char data; // Store incoming USART data.
	
	  for(i=0;i<len;i++)  // Only retrieve length of characters.
	  {
	    while(EUSART_is_rx_ready()); // Wait for User to enter character.
	
	    data = EUSART_Read();    // Get a character from the USART.
	                           // and save in the string.
	    *buffer = data;
	    buffer++;              // Increment the string pointer.
	  }
	}
 
 unsigned int Write_Int_To_EEPROM(int address, unsigned int number)
{ 
    DATAEE_WriteByte(address, number >> 8); //Store upper byte. 
    DATAEE_WriteByte(address + 1, number & 0xFF); //Store lower byte.
}
 
unsigned int Read_Int_From_EEPROM(int address)
{ 
  return (DATAEE_ReadByte(address) << 8) //Retrieve upper byte.
          + DATAEE_ReadByte(address + 1);//Retrieve lower byte.
}

/**
 End of File
*/
