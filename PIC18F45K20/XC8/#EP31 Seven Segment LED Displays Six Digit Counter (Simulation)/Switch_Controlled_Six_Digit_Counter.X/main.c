/* Exercise : Six Digit Multiplexed Seven Segment Display Counter Common Anode W a Decoder .
 * Author : Usmaan H 
 * Version : 1.0
 * Description : A switch controlled counter example where the user can increment
 * or decrement a 6 digit seven segment display from 0 to 999999. Utilising a multiplexed seven segment display.
 * with a 7447 decoder.
 */

//Header Files
#include "mcc_generated_files/mcc.h"

//Segment Activator
#define Active 1 // Segment Activator Value ( Active "Logic High" = Display off, !Active "Logic Low" = Display on)).

//Port Definitions 
#define Digit_1 LATCbits.LATC6 //Pin RC6 Is Designated With Name Digit_1.
#define Digit_2 LATCbits.LATC7 //Pin RA2 Is Designated With Name Digit_2.
#define Digit_3 LATDbits.LATD4 //Pin RA3 Is Designated With Name Digit_3.
#define Digit_4 LATDbits.LATD5 //Pin RA2 Is Designated With Name Digit_4.
#define Digit_5 LATDbits.LATD6 //Pin RA1 Is Designated With Name Digit_5.
#define Digit_6 LATDbits.LATD7 //Pin RA0 Is Designated With Name Digit_6.
#define DP LATCbits.LATC5 //Pin RC5 Is Designated With Name DP.
#define UP PORTBbits.RB0 //Pin RB0 Is Designated With Name Switch_1.
#define DOWN PORTBbits.RB1 //Pin RB1 Is Designated With Name Switch_2.

//Display Refresh Time
#define Seg_Timing 75 //Segment Delay Value Is Named Delay_Value.

//Calculated Result
#define Result PORTD //Port D Is Designated With Name Result.

//Variables
unsigned char RAM; // Temporarily Store Data For Operations.
unsigned char First_Digit,Second_Digit,Third_Digit,Fourth_Digit,Fifth_Digit,Sixth_Digit;// Store Value of 1st,2nd,3rd,4th,5th and 6th Digit.
unsigned long Counter=0; // Store Value of current Counter state Value.  

/* Main application */
void main(void)
{
    SYSTEM_Initialize(); // Initialize the device
    
    while(1){
        while(Counter<=999999){
                // Count Up if Switch Number 1 is pressed.
                if(UP == 0){
                    __delay_ms(500);      //Debounce delay part 1.
                    while(UP == 0); //Debounce delay part 2.
                    Counter++; // Increment Counter by 1.               
                }
                // Count Down if Switch Number 2 is pressed.
                else if(DOWN == 0){
                    __delay_ms(500);      //Debounce delay part 1.
                    while(DOWN == 0); //Debounce delay part 2.  
                    Counter--; // Decrement Counter by 1.              
                }
                
                DP = Active;// Disable decimal point   
                
                First_Digit = (Counter % 100)%10; // Retrieve Lowest Digit and save in Lower Nibble of First_Digit
                RAM = Result; // Save Display Port value into RAM
                Result =  First_Digit | (RAM&=0xF0) ;  //Clear Lower Nibble Of Variable RAM and Add Value of First Digit To RAM.
                Digit_1 = !Active; // Enable Digit
                Digit_2 = !Active; // Disable Digit
                Digit_3 = !Active; // Disable Digit
                Digit_4 = !Active; // Disable Digit
                Digit_5 = !Active; // Disable Digit
                Digit_6 = Active; // Disable Digit

                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.                

                Second_Digit = (Counter % 100)/10;  // Retrieve 5th Highest Digit and save in Second_Digit.
                RAM = Result; // Save Display Port value into RAM
                Result =  Second_Digit | (RAM&=0xF0) ; //Clear Lower Nibble Of Variable RAM and Add Value of Second Digit To RAM.
                Digit_1 = !Active; // Disable Digit
                Digit_2 = !Active; // Enable Digit
                Digit_3 = !Active; // Disable Digit
                Digit_4 = !Active; // Disable Digit
                Digit_5 =  Active; // Disable Digit
                Digit_6 = !Active; // Disable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

                Third_Digit = (Counter % 1000)/100; // Retrieve 4th highest Digit and save in Third_Digit.
                RAM = Result; // Save Display Port value into RAM
                Result =  Third_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Third Digit To RAM.
                Digit_1 = !Active; // Disable Digit
                Digit_2 = !Active; // Disable Digit
                Digit_3 = !Active; // Enable Digit
                Digit_4 =  Active; // Disable Digit
                Digit_5 = !Active; // Disable Digit
                Digit_6 = !Active; // Disable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.        

                Fourth_Digit = (Counter /1000)%10; // Retrieve 3rd Highest Digit  and save in Fourth_Digit.
                RAM = Result; // Save Display Port value into RAM
                Result =  Fourth_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Fourth Digit To RAM.
                Digit_1 = !Active; // Disable Digit
                Digit_2 = !Active; // Disable Digit
                Digit_3 =  Active; // Disable Digit
                Digit_4 = !Active; // Enable Digit
                Digit_5 = !Active; // Disable Digit
                Digit_6 = !Active; // Disable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

                Fifth_Digit = (Counter / 10000) %10; // Retrieve 2nd Highest Digit and save in Fifth_Digit.
                RAM = Result; // Save Display Port value into RAM
                Result =  Fifth_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Fifth Digit To RAM.
                Digit_1 = !Active; // Disable Digit
                Digit_2 =  Active; // Disable Digit
                Digit_3 = !Active; // Disable Digit
                Digit_4 = !Active; // Disable Digit
                Digit_5 = !Active; // Enable Digit
                Digit_6 = !Active; // Disable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

                Sixth_Digit = Counter / 100000; // Retrieve Highest Digit and save in Sixth_Digit.
                RAM = Result; // Save Display Port value into RAM
                Result =  Sixth_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Sixth Digit To RAM.
                Digit_1 =  Active; // Disable Digit
                Digit_2 = !Active; // Disable Digit
                Digit_3 = !Active; // Disable Digit
                Digit_4 = !Active; // Disable Digit
                Digit_5 = !Active; // Disable Digit
                Digit_6 = !Active; // Enable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.
        }
        Counter=0;//Reset counter to 0
    }
}
/**
 End of File
*/