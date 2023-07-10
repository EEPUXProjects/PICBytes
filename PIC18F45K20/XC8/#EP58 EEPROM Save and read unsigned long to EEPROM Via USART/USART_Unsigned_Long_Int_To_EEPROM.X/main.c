/* Exercise : Save a unsigned long integer value in the EEPROM Register via the serial USART terminal.
 * Author : Usmaan H  
 * Version : 1.0
 * Description : In this exercise we will be able to save a unsigned long integer value into the EEPROM via the serial terminal. Then being able to read it back and see it as it was typed in.
 * Value Range 4294967295 to 0.
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.
#include <stdlib.h> // Standard library files.
#include <stdio.h> //  Standard Input Output handling Functions.
#include <string.h> // String Handing Functions.

//Definition
#define ADDRESS_1 0x00 // First Address Location.
#define ADDRESS_4 0x04 // Fifth Address Location.

// Variables
long Entered_Value; // Store value of written and read contents from USART.
char ASCII_Conversion [50] ; // Store string data taken from and read by USART.
unsigned long number; // Store unsigned long values in variable number.

//Function Definitions
void USART_String_Transmit(char *string); // Transmit String Via USART.
void USART_String_Receive(char *buffer, unsigned char len); // Receive String Via USART.
unsigned long  writeLongIntoEEPROM(int address, long number); // Write Long integer to EEPROM.
unsigned long  readLongFromEEPROM(int address);// Read Long integer to EEPROM.
 
/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device
    
    while(1){
    USART_String_Transmit("\r\n Enter EEPROM Data Number : ");// Output welcome message on USART.
    USART_String_Receive(ASCII_Conversion,10); // Enter up to 10 digits with zeros filling in unused integers.E.g value 23. Enter 0000000023.
    Entered_Value = atol(ASCII_Conversion);//Convert number variable into string and concatenate with existing text.
    writeLongIntoEEPROM(ADDRESS_1, Entered_Value);//Write Long integer value. 
    number = readLongFromEEPROM(ADDRESS_1);//Read EEPROM Addresses with long integer and save in number variable as long integer.
    sprintf(ASCII_Conversion,"%s %lu","\r\n EEPROM Value : ", number); //Convert number variable into string and concatenate with existing text.
    USART_String_Transmit(ASCII_Conversion);// Output string from variable ASCII_Conversion on USART.
    __delay_ms(500);// Half Second Delay. 
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
 
unsigned long  writeLongIntoEEPROM(int address, long number)
{ 
  DATAEE_WriteByte(address, (number >> 24) & 0xFF); //Store upper byte. 
  DATAEE_WriteByte(address + 1, (number >> 16) & 0xFF); //Store second upper byte.
  DATAEE_WriteByte(address + 2, (number >> 8) & 0xFF); //Store third upper byte.
  DATAEE_WriteByte(address + 3, number & 0xFF); //Store lower byte.
}

unsigned long  readLongFromEEPROM(int address)
{
  return ((long)DATAEE_ReadByte(address) << 24) + //Retrieve upper byte.
         ((long)DATAEE_ReadByte(address + 1) << 16) + //Retrieve second upper byte.
         ((long)DATAEE_ReadByte(address + 2) << 8) + //Retrieve  third  upper byte.
         (long)DATAEE_ReadByte(address + 3);//Retrieve lower byte.
}

/**
 End of File
*/
