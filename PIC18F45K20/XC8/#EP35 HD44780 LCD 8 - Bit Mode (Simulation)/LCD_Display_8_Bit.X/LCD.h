/*8 Bit LCD Definition*/
// Port Definitions
#define RS LATD0   // Pin 0 of PORTD is assigned for register select Pin of LCD.
#define EN LATD1   // Pin 1 of PORTD is assigned for enable Pin of LCD.
#define RW LATD2   // Pin 2 of PORTD is assigned for read Pin of LCD.  
#define Data LATB //PORTB is assigned for LCD Data Output.
#define LCD_Port TRISB    //Defining name LCD_Port for PORTB Direction Register.             
#define LCD_Control TRISD // Port D is used to control registers of LCD.

// LCD Row Definitions
#define Row_1 0x80 //Row 1. 
#define Row_2 0xC0 //Row 2.
#define Row_3 0x90 //Row 3. 
#define Row_4 0xD0 //Row 4. 

//LCD Control Definitions
#define CLR_LCD   0x01                  // Clear Display.             
#define HOME_LCD  0x02                  // Home Cursor.
#define Disp_ON  0x0C                   // Display on.
#define Shift_Disp_Right 0x1C           // Shift display right.
#define Shift_Disp_Left  0x18           // Shift display left.
#define Shift_CURS_Right 0x14           // Shift cursor right.
#define Shift_CURS_Left  0x10           // Shift cursor left.
#define Disp_On_CURS_On_BLK_CURS  0x0F  // Display on, cursor on, blinking cursor.
#define Disp_On_CURS_On_STDY_CURS 0x0E  // Display on, cursor on, steady cursor.
#define Disp_On_CURS_Off          0x0   // Display on, cursor off.
#define Disp_Off                  0x08  // Turn display off.
#define CURS_Move_Right_Disp_Shift_Left 0x07 // Move cursor right, do shift display left.
#define CURS_Move_Right_Disp_Shift_None 0x06 // Move cursor right, don't shift display.
#define LCD_Format                0x38 // LCD Display Format.

//LCD Function Declarations
void Configure_LCD(void);                                  // LCD Configuration. 
void LCD_Command(unsigned char cmd );                      // Send LCD Command. 
void LCD_Write_Data(unsigned char x);                      // Send Data to LCD. 
void LCD_Write_Message(char row,char pos,const char *msg); // LCD Display Output.  

