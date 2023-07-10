// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files
#include "LCD.h" // LCD Header File
#include <stdio.h> // Standard Input Output header File
#include <string.h> // String Header File

void Configure_LCD(void)
{
    __delay_ms(15);           // LCD Power On Delay.
    LCD_Port = 0x00;          // Set PORTB as output PORT for LCD data(D0-D7) pins.  
    LCD_Control = 0x00;       // Set PORTD as output PORT LCD Control(RS,EN) Pins.
                              // If other Port D pins are used. Define them after the function.
    LCD_Command(LCD_Format);  // Configure TO 8 BIT MODE.  
    LCD_Command(CLR_LCD);     // Clear display screen.
    LCD_Command(Disp_ON);    // Display on cursor off 
    LCD_Command(CURS_Move_Right_Disp_Shift_None);   // Shift cursor to right.
  
}

void LCD_Command(unsigned char cmd )
{
	Data= cmd;            // Send command data via port assigned to Data. 
	RS = 0;               // Select the command register.
	EN = 1;               // Enable pin is high.
	NOP();                // No operation.
	EN = 0;               // Enable pin is low.
    __delay_ms(3);        // 3 millisecond delay.
}

void LCD_Write_Data(unsigned char dat)
{	
    Data= dat;            // Send data via port assigned to Data.  
	RS = 1;               // Select the data register.
	EN = 1;               // Enable pin is high.
	NOP();                // No operation.
	EN = 0;               // Enable pin is low.
	__delay_ms(1);        // 1 millisecond delay.
}


void LCD_Write_Message(char row,char pos,const char *msg)
{
    char location=0; // Define variable location to store hex value of requested row.

    switch(row)   // Obtain Hex value for requested row number.
    {
        case 1:  location=Row_1; // Row number 1.
        break;                   // Exit case function.

        case 2:  location=Row_2; // Row number 2.
        break;                   // Exit case function.

        case 3:  location=Row_3; // Row number 3.
        break;                   // Exit case function.

        case 4:  location=Row_4; // Row number 4.
        break;                   // Exit case function.

    }
    
    LCD_Command((location) | ((pos) & 0x0f)); // Move cursor to requested row and column.

    while((*msg)!=0) // Write message until string is completely written. 
    {		
        LCD_Write_Data(*msg); // Write current character of msg pointer to LCD display.
        msg++;	              // Increment msg variable by 1.
    }

}


