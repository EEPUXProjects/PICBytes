/* Please Select Method of LCD Connection.*/

//#define Four_Bit_LCD
#define Eight_Bit_LCD

#ifdef Four_Bit_LCD // Select 4 Bit mode
#define RS LATB0  //PIN 0 of PORTB is assigned for register select Pin of LCD.
#define EN LATB1  //PIN 1 of PORTB is assigned for enable Pin of LCD. 
#define RW LATB2  //PIN 2 of PORTB is assigned for read Pin of LCD. 
#define Data LATB  //PORTB(PB4-PB7) is assigned for LCD Data Output.
#define LCD_Port TRISB  //Defining name LCD_Port for PORTB Direction Register.
#define LCD_Control TRISD // Ignore this. This is just added to ignore compiler error. It is only used for 8 bit mode.
#define Format  4 // Define bit mode of LCD Display.
#define LCD_Format                0x28 // LCD Display Format.
#else  // Else Select 8 Bit mode
#define RS LATD0   // PIN 0 of PORTD is assigned for register select Pin of LCD.
#define EN LATD1   // PIN 1 of PORTD is assigned for enable Pin of LCD. 
#define RW LATD2   // PIN 2 of PORTD is assigned for read Pin of LCD.  
#define Data LATB //PORTB is assigned for LCD Data Output.
#define LCD_Port TRISB //Defining name LCD_Port for PORTB Direction Register.             
#define LCD_Control TRISD // Port D is used to control registers of LCD.
#define Format  8 // Define bit mode of LCD Display.
#define LCD_Format                0x38 // LCD Display Format.
#endif

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
#define LCD_CG_Mem_0              0    // First Memory CG Location.
#define LCD_CG_Mem_1              1    // Second Memory CG Location.
#define LCD_CG_Mem_2              2    // Third Memory CG Location.
#define LCD_CG_Mem_3              3    // Fourth Memory CG Location.
#define LCD_CG_Mem_4              4    // Fifth Memory CG Location.
#define LCD_CG_Mem_5              5    // Sixth Memory CG Location.
#define LCD_CG_Mem_6              6    // Seventh Memory CG Location.
#define LCD_CG_Mem_7              7    // Eigth and final CG Location.

//LCD Function Declarations
void Configure_LCD(void);                                  // LCD Configuration. 
void LCD_Command(unsigned char cmd );                      // Send LCD Command. 
void LCD_Write_Data(unsigned char x);                      // Send Data to LCD. 
void LCD_Write_Message(char row,char pos,const char *msg); // LCD Display Output.  
void LCD_Write_Custom_Chararacter(unsigned char Location,unsigned char *Message); //LCD custom character function.
void LCD_Read_Custom_Chararacter(unsigned char Character_Address, unsigned char row , unsigned char pos);//LCD custom character recall and placement function.

//LCD Variables
char DATA_PORT ; // Define variable DATA_PORT as character.
int Bit_Format = Format; // Define variable Bit_Format as integer.

// Custom Example Character Definition
unsigned char Happyface[] = {
  0x0E,
  0x1F,
  0x00,
  0x0A,
  0x04,
  0x15,
  0x0A,
  0x0E
};