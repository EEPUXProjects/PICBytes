/* Exercise : Entire EEPROM register value.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be able to calculate the value of the entire contents of the EEPROM.
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.
#include <stdlib.h> // Standard library files.
#include <stdio.h> //  Standard Input Output handling Functions.
#include <string.h> // String Handing Functions.

//Definition
#define ADDRESS_1 0x00 // First Address Location is hexadecimal value of 0x00.
#define ADDRESS_Last 0xFF // Last Address Location is hexadecimal value of 0xFF.

// Variables
unsigned int RAM =0; // Temporarily store values of in progress calculations.
long Entered_Value; // Store value of written and read contents.
char ASCII_Conversion [50] ; // Store string data to and from USART.


//Function Definitions
void USART_String_Transmit(char *string); // Transmit String data Via USART.
 
/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device

    for (int Counter = ADDRESS_1 ; Counter <= ADDRESS_Last; Counter++) // Code within For loop increments through entire register, and adds up all register entry values.
    {
        RAM = DATAEE_ReadByte(Counter) + RAM ; // Calculate entire EEPROM register value.
        
    } 
    
    sprintf(ASCII_Conversion,"%s %u","\r\n EEPROM Calculated Value : ", RAM); //Convert number variable into string and concatenate with existing text.
    USART_String_Transmit(ASCII_Conversion);// Output string on UART.
    __delay_ms(500);                   // Half Second Delay.
  
    
    while (1);	            // Remain in Loop Forever.
 }


 void USART_String_Transmit(char *string){  //Function that will send string data.
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.  
  }
/**
 End of File
*/