/* Exercise : Four Digit Multiplexed Seven Segment Display Counter With a BCD Decoder On Low Nibble
 * Author : Usmaan H 
 * Version : 1.0
 * Description : A switch controlled counter example where the user can increment
 * or decrement a 4 digit seven segment display from 0 to 9999. Utilising a multiplexed seven segment display
 * with a 7447 decoder on the ports lower nibble.
 */

//Header Files
#include "mcc_generated_files/mcc.h"

/*Common_Anode_Seven_Segment*/

//Segment Activator
#define Active 1 // Segment Activator Value ( Active "Logic High" = Display off, !Active "Logic Low" = Display on))

//Port Definitions
#define Digit_4 LATAbits.LATA3 //Pin RA3 Is Designated With Name Digit_4.
#define Digit_3 LATAbits.LATA2 //Pin RA2 Is Designated With Name Digit_3.
#define Digit_2 LATAbits.LATA1 //Pin RA1 Is Designated With Name Digit_2.
#define Digit_1 LATAbits.LATA0 //Pin RA0 Is Designated With Name Digit_1.
#define Display_Port LATB //Port B Is Designated With Name Display_Port.
#define DP LATAbits.LATA5 //Pin RA5 Is Designated With Name DP.
#define Switch_1 PORTDbits.RD0 //Pin RD0 Is Designated With Name Switch_1.
#define Switch_2 PORTDbits.RD1 //Pin RD1 Is Designated With Name Switch_2.

//Display Refresh Time
#define Seg_Timing 100 //Segment Delay Value Is Named Delay_Value.

//Variable Definitions
unsigned char First_Digit,Second_Digit,Third_Digit,Fourth_Digit;// Store Value of 1st,2nd,3rd and 4th Digit.
unsigned char RAM; // Temporarily Store Data For Operations.
unsigned int Counter=0; // Store Value of current Counter state Value.  

/* Main application */
void main(void)
{
// Initialize the device
    SYSTEM_Initialize();
    PIN_MANAGER_IOC();
    while (1)
    {

        while(Counter<=9999)
        {   // Count Up if Switch Number 1 is pressed.
            if(Switch_1 == 0){
                __delay_ms(500);      //Debounce delay part 1.
                while(Switch_1 == 0); //Debounce delay part 2.   
                Counter++; // Increment Counter by 1             
            }
            // Count Down if Switch Number 2 is pressed.
            else if(Switch_2 == 0){
                __delay_ms(500);      //Debounce delay part 1.
                while(Switch_2 == 0); //Debounce delay part 2.
                Counter--; // Decrement Counter by 1
            }
            DP = Active;// Disable Decimal Point

            First_Digit = (Counter % 100)%10; // Retrieve Lowest Digit and Save in Lower Nibble of First_Digit
            RAM = Display_Port; // Save Display Port value into RAM
            Display_Port =  First_Digit | (RAM&=0xF0) ;  //Clear Lower Nibble Of Variable RAM and Add Value of First Digit To RAM.
            Digit_1 =  Active; // Enable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.


            Second_Digit = (Counter % 100)/10;  // Retrieve 2nd Lowest Digit and Save in Lower Nibble of  Second_Digit
            RAM = Display_Port; // Save Display Port value into RAM
            Display_Port =  Second_Digit | (RAM&=0xF0) ; //Clear Lower Nibble Of Variable RAM and Add Value of Second Digit To RAM.
            Digit_1 = !Active; // Disable Digit
            Digit_2 =  Active; // Enable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.


            Third_Digit = (Counter % 1000)/100; // Retrieve 3rd Lowest Digit and Save in Lower Nibble of Third_Digit
            RAM = Display_Port; // Save Display Port value into RAM
            Display_Port =  Third_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Third Digit To RAM.
            Digit_1 = !Active; // Disable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 =  Active; // Enable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.


            Fourth_Digit = Counter / 1000; // Retrieve Highest Digit and Save in Lower Nibble of Fourth_Digit
            RAM = Display_Port; // Save Display Port value into RAM
            Display_Port =  Fourth_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Fourth Digit To RAM.
            Digit_1 = !Active; // Disable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = Active; // Enable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.
        }
        Counter=0;// Reset Counter to zero.
    }
}


/**
 End of File
*/