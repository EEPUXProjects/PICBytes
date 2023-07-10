/* Exercise : Demonstrating HD44780 LCD in 8 Bit Mode 
 * Author : Usmaan H
 * Description : To demonstrate wiring up of a HD44780 LCD display in 8 Bit Mode and presenting simple welcome message. 
 * Version : 1.0
*/

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.
#include "LCD.h" // LCD Header File.

/*
                         Main application
 */
void main(void)
{
    // Initialize the device.
    SYSTEM_Initialize();
    
    Configure_LCD(); // Initialize the LCD display.
    LCD_Write_Message(1,6,"Hello");   // Write first message to first row.
    LCD_Write_Message(2,5,"I'm in "); // Write second message to second row. 
    LCD_Write_Message(3,3,"8-BIT Mode "); // Write third message to third row. 
    while(1); // Looping in current state forever.
}

/**
 End of File
*/

