/* Exercise : TMP36 Temperature reading part 2.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be reading the positive and negative output temperature data of the TMP36 sensor via the seven segment display. 
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header
#include <stdio.h> //  Standard Input Output handling Functions
#include <string.h> // String Handing Functions

/*Common_Anode_Seven_Segment*/
//Seven Segment Numbers
#define Number_0 0xC0 // Define Name Number_0 With Value 0  
#define Number_1 0xF9 // Define Name Number_1 With Value 1  
#define Number_2 0xA4 // Define Name Number_2 With Value 2 
#define Number_3 0xB0 // Define Name Number_3 With Value 3 
#define Number_4 0x99 // Define Name Number_4 With Value 4 
#define Number_5 0x92 // Define Name Number_5 With Value 5 
#define Number_6 0x82 // Define Name Number_6 With Value 6
#define Number_7 0xF8 // Define Name Number_7 With Value 7
#define Number_8 0x80 // Define Name Number_8 With Value 8 
#define Number_9 0x90 // Define Name Number_9 With Value 9

//Segment Activator
#define Active 1 // Segment Activator Value ( Active "Logic High" = Display off, !Active "Logic Low" = Display on))

//Port Definitions
#define Digit_1 LATAbits.LATA1 //Pin RA5 Is Designated With Name Digit_4.
#define Digit_2 LATAbits.LATA2 //Pin RA3 Is Designated With Name Digit_3.
#define Digit_3 LATAbits.LATA3 //Pin RA2 Is Designated With Name Digit_2.
#define Digit_4 LATAbits.LATA5 //Pin RA1 Is Designated With Name Digit_1.
#define Display_Port LATB //Port B Is Designated With Name Display_Port.
#define DP LATBbits.LATB7 //Pin RD0 Is Designated With Name DP.

//Display Refresh Time
#define Seg_Timing 255 //Segment Delay Value Is Named Delay_Value.

//Variable Definitions
unsigned char First_Digit,Second_Digit,Third_Digit,Fourth_Digit,RAM; // Store Value of 1st,2nd,3rd and Fourth Digit.

//Variable Definitions
float Voltage; // Store ADC result.
int TMP36_Reading; //Store temperature reading in degrees c.
int whole,decimal; //Store temperature reading in decimal and non decimal format.
char xvalueASCII [50]; // Store string for USART.

//Function Definitions
void Seven_Segment_Positive_Tempreture_Output(void);// Output only positive temperature reading on seven segment.
void UART_Positive_Negative_Tempreture_Output(void);// Output only positive temperature reading on UART.
void USART_String_Transmit(char *str); // USART string output function
unsigned char Number_Mapping[10] = {Number_0,Number_1,Number_2,Number_3,Number_4,Number_5,Number_6,Number_7,Number_8,Number_9};// Array of Hex Values for Seven Segment Number Map

/*Main application*/
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {   ADC_SelectChannel(0);               // Select Channel 0.
        ADC_StartConversion();		        // Start A/D conversion                 
        while(ADC_IsConversionDone()); 	    // Wait for A-D conversion to complete  
        Voltage= ADC_GetConversionResult(); // Read the ADC result & store          
        TMP36_Reading = (((Voltage*3300)/1024));//Convert ADC result in temperature reading in degrees C.
        TMP36_Reading = ((TMP36_Reading-500)/10);//Modify temperature reading to account for voltage reference offset in device.
        if(TMP36_Reading>=0){
                First_Digit = (TMP36_Reading % 100)%10; // Retrieve Lowest Digit and Save in First_Digit
                Display_Port =  Number_Mapping[First_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
                DP = Active; // Disable Decimal Point
                Digit_1 =  Active; // Enable Digit
                Digit_2 = !Active; // Disable Digit
                Digit_3 = !Active; // Disable Digit
                Digit_4 = !Active; // Disable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

                Second_Digit = (TMP36_Reading % 100)/10;  // Retrieve 2nd Lowest Digit and Save in Second_Digit
                Display_Port =  Number_Mapping[Second_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
                DP = Active; // Disable Decimal Point
                Digit_1 = !Active; // Disable Digit
                Digit_2 =  Active; // Enable Digit
                Digit_3 = !Active; // Disable Digit
                Digit_4 = !Active; // Disable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

                Third_Digit = (TMP36_Reading % 1000)/100; // Retrieve 3rd Lowest Digit and Save in Third_Digit
                Display_Port =  Number_Mapping[Third_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
                DP = Active; // Disable Decimal Point
                Digit_1 = !Active; // Disable Digit
                Digit_2 = !Active; // Disable Digit
                Digit_3 =  Active; // Enable Digit
                Digit_4 = !Active; // Disable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

                Fourth_Digit = TMP36_Reading / 1000; // Retrieve Highest Digit and Save in Fourth_Digit
                Display_Port =  Number_Mapping[Fourth_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
                DP = Active; // Disable Decimal Point
                Digit_1 = !Active; // Disable Digit
                Digit_2 = !Active; // Disable Digit
                Digit_3 = !Active; // Disable Digit
                Digit_4 = Active; // Enable Digit
                __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.
        }
        if(TMP36_Reading<=0){
            int TMP36_Reading_Convert; // Variable temporarily stores value for positive seven segment output
            TMP36_Reading_Convert = TMP36_Reading*-1; // Convert negative value to positive for display output
            First_Digit = (TMP36_Reading_Convert % 100)%10; // Retrieve Lowest Digit and Save in First_Digit
            Display_Port =  Number_Mapping[First_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
            Digit_1 =  Active; // Enable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

            Second_Digit = (TMP36_Reading_Convert % 100)/10;  // Retrieve 2nd Lowest Digit and Save in Second_Digit
            Display_Port =  Number_Mapping[Second_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
            Digit_1 = !Active; // Disable Digit
            Digit_2 =  Active; // Enable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

            Third_Digit = (TMP36_Reading_Convert % 1000)/100; // Retrieve 3rd Lowest Digit and Save in Third_Digit
            Display_Port =  Number_Mapping[Third_Digit] ;  //Based on Digit Number. Select Equivalent Seven Segment Hex Value and Output On Designated Port
            Digit_1 = !Active; // Disable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 =  Active; // Enable Digit
            Digit_4 = !Active; // Disable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

            Fourth_Digit = TMP36_Reading_Convert / 1000; // Retrieve Highest Digit and Save in Fourth_Digit
            Display_Port =  0xBF ;  //Designate digit as negative value indicator. Hex code illuminates middle horizontal segment only.
            Digit_1 = !Active; // Disable Digit
            Digit_2 = !Active; // Disable Digit
            Digit_3 = !Active; // Disable Digit
            Digit_4 = Active; // Enable Digit
            __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.
        }
    }
}

/**
 End of File
*/