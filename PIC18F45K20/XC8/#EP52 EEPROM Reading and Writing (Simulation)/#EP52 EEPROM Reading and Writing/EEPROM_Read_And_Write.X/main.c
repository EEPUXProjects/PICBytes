/* Exercise : Writing and reading a tri-set of 8 bit hexadecimal values to and from the internal EEPROM.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be writing 3 different values to the internal EEPROM to 3 separate addresses and then reading it back on Bargraph Display in a 3 step sequence with an appropriate delay.
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header

//Definition
#define ADDRESS_1 0x01 // Address 1 Location
#define ADDRESS_2 0x02 // Address 2 Location
#define ADDRESS_3 0x03 // Address 3 Location
#define Output LATB // Result will be output on port B.

// Variable
unsigned char RAM; // Temporarily store value of written and read contents.

/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device

    DATAEE_WriteByte(ADDRESS_1,0xFF);  // Store 0xFF into address 0x01 of the EEPROM register        
    DATAEE_WriteByte(ADDRESS_2,0xF0);  // Store 0xF0 into address 0x02 of the EEPROM register          
    DATAEE_WriteByte(ADDRESS_3,0x0F);  // Store 0x0F into address 0x03 of the EEPROM register          
    __delay_ms(10);                    // Short Delay   
   
    RAM = DATAEE_ReadByte(ADDRESS_1);  // Copy data from address, 0x01 and move to RAM 
    Output = RAM;                      // Copy data from RAM, to output
    __delay_ms(500);                   // Half Second Delay                          
    
    RAM = DATAEE_ReadByte(ADDRESS_2);  // Copy data from address, 0x02 and move to RAM 
    Output = RAM;                      // Copy data from RAM, to output
    __delay_ms(500);                   // Half Second Delay  
    
    RAM = DATAEE_ReadByte(ADDRESS_3);  // Copy data from address, 0x03 and move to RAM 
    Output = RAM;                      // Copy data from RAM, to output  
    __delay_ms(500);                   // Half Second Delay  
    
    while (1);	            // Remain in Loop Forever
 }
/**
 End of File
*/