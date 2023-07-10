/* Exercise : Clearing the Entire EEPROM Register Example.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be see on how to clear the entire EEPROM register.
 */

//Include Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header

//Definition
#define ADDRESS_1 0x00 // First EEPROM Address Location.
#define ADDRESS_Last 0xFF // Last EEPROM Address Location.

/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device

    for (int Counter = ADDRESS_1 ; Counter <= ADDRESS_Last; Counter++)
    {
        DATAEE_WriteByte(Counter,0x00);  // Clear currently selected register.      
    }
    
    Indicator_LAT = 1;      // Enable LED to indicate entire EEPROM is cleared.
    while (1);	            // Remain in Loop Forever.
 }
/**
 End of File
*/