/* Exercise : HD44780 LCD display library.
 * Author : Usmaan H
 * Description : This is a library that allows you to use the HD44780 LCD. Having the Choice of implementing it in a 4 bit or 8 bit mode. As a short demo a custom character will be shown as the final result.
 * Custom Character Generation : https://maxpromer.github.io/LCD-Character-Creator/
 * Notes : Ignore this "./LCD.h:56:: warning: (759) expression generates no code"
 *         The CGRAM register has a maximum size of 64 Bytes. We are using 5 × 8 dots for custom character generation. So only eight character patterns can be written. 
 *         As 1 character consumes 8 bytes of space. But if 5 × 10 dots are used. Then four character patterns can only be stored. This is not covered here.
 * Version : 1.0
 */


// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files
#include "LCD.h" // LCD Header File

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    Configure_LCD();                                      // Initialize the LCD display.
    LCD_Write_Message(1,4,"Custom LCD ");          // Write message to first row
    LCD_Write_Message(2,5,"Library");                     // Write message to second row
    LCD_Write_Message(3,3,"Welcome !!!");                     // Write message to third row
    LCD_Write_Custom_Chararacter(LCD_CG_Mem_0,Happyface); // Write custom character to LCD CG address LCD_CG_Mem_0.
    LCD_Read_Custom_Chararacter(LCD_CG_Mem_0,4, 8);       // Recall character stored in CGRAM address LCD_CG_Mem_0 and place in row 2, column position 5.
    while(1);                                             // Looping in current state forever.
}

/**
 End of File
*/

