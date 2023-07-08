/* Exercise : Reading the Entire Internal EEPROM Register.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be reading and outputting the value of each writable address in the EEPROM register on the serial terminal.
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header
#include <stdlib.h> // Standard library files
#include <stdio.h> //  Standard Input Output handling Functions
#include <string.h> // String Handing Functions

//Definition
#define ADDRESS_1 0x00 // First Address Location
#define ADDRESS_Last 0xFF // Last Address Location

// Variables
char ASCII_Conversion [50] ; // Store string from USART.
int Address_Counter; // Store value of free EEPROM addresses. (0x00 is the value for the register to be free)

//Function Definition
void USART_String_Transmit(char *string); // Transmit String Via USART

/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device

    for (int Current_Address = ADDRESS_1 ; Current_Address <= ADDRESS_Last; Current_Address++)// For loop counter to go through entire EEPROM register. To output result on USART.
    {
        sprintf(ASCII_Conversion,"%s %u %s %u","\r\n Address ", Current_Address,": ",DATAEE_ReadByte(Current_Address) );
        USART_String_Transmit(ASCII_Conversion);// Output string on UART.
        if (DATAEE_ReadByte(Current_Address) == 0x00) 
        { 
            Address_Counter++;//Increment variable by one.
        }
        __delay_ms(50);                   // Half Second Delay  
    }  
    sprintf(ASCII_Conversion,"%s %u","\r\n EEPROM Free",Address_Counter); // Create a string of data where we know how many eeprom addresses are free.
    USART_String_Transmit(ASCII_Conversion);// Output string on UART.
    while (1);	            // Remain in Loop Forever
 }
   

 void USART_String_Transmit(char *string){  //Function that will send string data
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.       
  }
/**
 End of File
*/