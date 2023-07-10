/* Exercise : Preserving EEPROM
 * Author : Usmaan H 
 * Version : 1.0
 * Description : In this exercise we will be updating the value of the EEPROM only if the new value is different. Otherwise the Character input will be rejected and the user will be notified that this has 
 *              occurred.
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.
#include <stdlib.h> // Standard library files.
#include <stdio.h> //  Standard Input Output handling Functions.

//Definition
#define ADDRESS_1 0x00 // First Address Location.

// Variables
char ASCII_Conversion [50] ; // Store string from USART.
unsigned char RAM; // Store value of written and read contents.

//Function Definitions
void USART_String_Transmit(char *string); // Transmit String Via USART.
void Update_EEPROM (int address , int data);// Update EEPROM register only if a new value is entered.
 
/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device.
    
        while(1){
        USART_String_Transmit("\r\n Enter data to be stored in EEPROM : ");// Output string on USART.
        RAM= EUSART_Read();    // Get a character from the serial terminal.
        Update_EEPROM (ADDRESS_1 , RAM); //Update EEPROM Function.
    }
    
 }


 void USART_String_Transmit(char *string){  //Function that will send string data.
        while (*string)             //while the pointer has not reached the end of the array of chars it will keep sending.
        EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.
       
  }

 void Update_EEPROM (int address , int data)
 { // Update EEPROM register only if a new value is entered.
     if(DATAEE_ReadByte(address)==data) //EEPROM is not updated.
    {
         
        USART_String_Transmit("\r\n EEPROM Not Updated ");// Output string on USART.        
    }
    else
    {
       DATAEE_WriteByte(address,data); // //EEPROM is updated
       USART_String_Transmit("\r\n EEPROM Has Been Updated ");// Output string on USART.  
    }
    __delay_ms(500);                   // Half Second Delay  
   
 }
 
/**
 End of File
*/