/* Exercise : USART EEPROM Calculator
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be using the serial USART to enter 5 values into the EEPROM Register . Then we will read back those results and
 * see the calculated total of those inputs on USART. As they were stored in the EEPROM registers. 
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.
#include <stdlib.h> // Standard library files.
#include <stdio.h> //  Standard Input Output handling Functions.


//Definition
#define ADDRESS_1 0x00 // First Address Location.
#define ADDRESS_4 0x04 // Fifth Address Location.

// Variables
unsigned char RAM; // Temporarily Store values while operations are being done.
unsigned int Calculated_Value; // Store final values of written and read contents.
char ASCII_Conversion [50]; // Store strings to and from USART.

//Function Definitions
void USART_String_Transmit(char *string); // Transmit String Via USART.
 
/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device
    
    while(1){
    
    for (int Counter = ADDRESS_1 ; Counter <= ADDRESS_4; Counter++)
    {       
        sprintf(ASCII_Conversion,"%s %u %s","\r\n Enter EEPROM Data Number ", Counter,": " );//Convert counter variable into string and concatenate with existing text.
        USART_String_Transmit(ASCII_Conversion);// Output string on UART.
        while(EUSART_is_rx_ready()); // Wait for user input.
        RAM = EUSART_Read()-0x30; //Convert ASCII integer representation to actual integer value.
        DATAEE_WriteByte(Counter,RAM) ; // Store value of RAM variable into the EEPROM address that is in Counter. 
    } 
    
    for (int Counter = ADDRESS_1 ; Counter <= ADDRESS_4; Counter++)
    {        
        Calculated_Value = DATAEE_ReadByte(Counter) + Calculated_Value ; // Calculate the total value of a specific  EEPROM Address range.
    }
    
    sprintf(ASCII_Conversion,"%s %u","\r\n EEPROM Calculated Value : ", Calculated_Value); //Convert counter variable into string and concatenate with existing text.
    USART_String_Transmit(ASCII_Conversion);// Output string on UART.
    __delay_ms(500);                   // Half Second Delay. 
    
    Calculated_Value=0; // Clear Previous Entries.
    
    }
 }


 void USART_String_Transmit(char *string){  //Function that will send string data.
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.
       
  }
/**
 End of File
*/