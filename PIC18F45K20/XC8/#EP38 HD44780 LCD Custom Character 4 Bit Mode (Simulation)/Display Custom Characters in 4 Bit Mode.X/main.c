/* Exercise : Demonstrating custom character displaying on the HD44780 LCD in 4 Bit Mode 
 * Author : Usmaan H
 * Description : To demonstrate wiring up of a HD44780 LCD display in 4 Bit Mode and load a custom character.
 * Custom Character Generation : https://maxpromer.github.io/LCD-Character-Creator/
 * Notes : Ignore this "./LCD.h:56:: warning: (759) expression generates no code"
 *         The CGRAM register has a maximum size of 64 Bytes. We are using 5 × 8 dots for custom character generation. So only eight character patterns can be written. 
 *         As 1 character consumes 8 bytes of space. But if 5 × 10 dots are used. Then four character patterns can only be stored. This is not covered here.
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
    // Initialize the device
    SYSTEM_Initialize();
    
    Configure_LCD(); // Initialize the LCD display.
    LCD_Write_Message(1,0,"Custom Character"); // Write title sequence to first row.
    LCD_Write_Custom_Chararacter(LCD_CG_Mem_0,Happyface); // Write custom character to LCD CG address 0.
    LCD_Read_Custom_Chararacter(LCD_CG_Mem_0,2, 5); // Recall character stored in CGRAM adress 0 and place in row 2, column position 5.
    while(1); // Looping in current state forever.
}

/**
 End of File
*/

