/* Exercise : Two Digit Seven Segment Counter 
 * Author : Usmaan H
 * Version : 1.0
 * Description : A switch controlled counter example where the user can increment
 * or decrement a two digit seven segment display.
 */

//Header Files
#include "mcc_generated_files/mcc.h"

//Port Definitions
#define Display_Port LATB //Port B Is Designated With Name Display_Port.
#define DP_1 LATAbits.LATA0 //Pin RA0 Is Designated With Name DP_1.
#define DP_2 LATAbits.LATA1 //Pin RA1 Is Designated With Name DP_2.
#define Switch_1 PORTDbits.RD0 //Pin RD0 Is Designated With Name Switch_1.
#define Switch_2 PORTDbits.RD1 //Pin RD1 Is Designated With Name Switch_2.
#define Active 0 // Segment Activator Value
//Display Refresh Time
#define Seg_Timing 100 //Segment Delay Value.

//Variable Definitions
unsigned char First_Digit;// Store Lower Nibble Value
unsigned char Second_Digit; // Store Higher Nibble Value
unsigned char Counter=0; // Store Value of Counter Value.  


/*Main application*/
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    DP_1 = !Active; // Disable Decimal Point
    DP_2 = !Active; // Disable Decimal Point
    
    while (1)
    {
                if(Switch_1 == 0){
                __delay_ms(500);      //Debounce delay part 1.
                while(Switch_1 == 0); //Debounce delay part 2.
                Counter++; // Increment Counter by 1
                }
                else if(Switch_2 == 0){
                __delay_ms(500);      //Debounce delay part 1.
                while(Switch_2 == 0); //Debounce delay part 2.
                Counter--; // Decrement Counter by 1
                } 
                if (Counter>99 || Counter <=0){Counter = 0;}// Reset Counter to zero .
                First_Digit = Counter %10;   // Retrieve Lower Digit 
                Second_Digit = ((Counter /10)<<4); // Retrieve Higher Digit And Left Shift Answer by 4.
                Display_Port = First_Digit | Second_Digit ; // Add Contents of First_Digit & Second_Digit , and display on designated Port.
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

                
                

    }
}
/**
 End of File
*/