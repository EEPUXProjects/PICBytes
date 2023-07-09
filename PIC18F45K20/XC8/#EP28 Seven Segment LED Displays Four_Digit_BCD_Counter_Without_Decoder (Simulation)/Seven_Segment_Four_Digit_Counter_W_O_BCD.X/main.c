/* Exercise : Four Digit Multiplexed Seven Segment Display Counter Common Anode W/O a Decoder .
 * Author : Usmaan H 
 * Version : 1.0
 * Description : A switch controlled counter example where the user can increment
 * or decrement a 4 digit seven segment display upto 9999. Utilising a multiplexed seven segment display.
 * without a 7447 decoder.
 */

//Header Files
#include "mcc_generated_files/mcc.h" // Include Necessary header file.

/*Common_Anode_Seven_Segment*/
//Seven Segment Numbers
#define Number_0 0xC0 // Define Name Number_0 With Value 0.
#define Number_1 0xF9 // Define Name Number_1 With Value 1.  
#define Number_2 0xA4 // Define Name Number_2 With Value 2. 
#define Number_3 0xB0 // Define Name Number_3 With Value 3. 
#define Number_4 0x99 // Define Name Number_4 With Value 4. 
#define Number_5 0x92 // Define Name Number_5 With Value 5. 
#define Number_6 0x82 // Define Name Number_6 With Value 6.
#define Number_7 0xF8 // Define Name Number_7 With Value 7.
#define Number_8 0x80 // Define Name Number_8 With Value 8. 
#define Number_9 0x90 // Define Name Number_9 With Value 9.

//Segment Activator
#define Active 1 // Segment Activator Value ( Active "Logic High" = Display off, !Active "Logic Low" = Display on)).

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
unsigned char Number_Mapping[10] = {Number_0,Number_1,Number_2,Number_3,Number_4,Number_5,Number_6,Number_7,Number_8,Number_9};// Array of Hex Values for Seven Segment Number Map

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

            First_Digit = (Counter % 100)%10; // Retrieve Lowest Digit and Save in First_Digit
            Display_Port =  Number_Mapping[First_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
            Digit_1 =  Active; // Enable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

            Second_Digit = (Counter % 100)/10;  // Retrieve 2nd Lowest Digit and Save in Second_Digit
            Display_Port =  Number_Mapping[Second_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
            Digit_1 = !Active; // Disable Digit
            Digit_2 =  Active; // Enable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

            Third_Digit = (Counter % 1000)/100; // Retrieve 3rd Lowest Digit and Save in Third_Digit
            Display_Port =  Number_Mapping[Third_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
            Digit_1 = !Active; // Disable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 =  Active; // Enable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

            Fourth_Digit = Counter / 1000; // Retrieve Highest Digit and Save in Fourth_Digit
            Display_Port =  Number_Mapping[Fourth_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
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