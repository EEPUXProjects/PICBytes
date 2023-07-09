/* Exercise : TMP36 Temperature reading +- accuracy.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be reading the output temperature data of the TMP36 sensor via serial USART and the seven segment display.
 * Note: Serial terminal shows positive and negative temperatures. Seven segment shows positive only as we are unable to show a negative sign on the display as the decoder does not allow it. 
 *       Hence , why seven segment code does not have the function to show temperatures below 0. This can be fixed by not using the decoder, will be solved for the task "TMP36_Temperature_Example_Part_2".
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
#define Digit_4 LATAbits.LATA5 //Pin RA5 Is Designated With Name Digit_4.
#define Digit_3 LATAbits.LATA3 //Pin RA3 Is Designated With Name Digit_3.
#define Digit_2 LATAbits.LATA2 //Pin RA2 Is Designated With Name Digit_2.
#define Digit_1 LATAbits.LATA1 //Pin RA1 Is Designated With Name Digit_1.
#define Display_Port LATB //Port B Is Designated With Name Display_Port.
#define DP LATDbits.LATD0 //Pin RD0 Is Designated With Name DP.

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
        UART_Positive_Negative_Tempreture_Output(); // Output result on USART.
        Seven_Segment_Positive_Tempreture_Output(); // Output result on Seven Segment.  
    }
}

void Seven_Segment_Positive_Tempreture_Output(void)
{              
    DP = Active; // Disable Decimal Point

        First_Digit = (TMP36_Reading % 100)%10; // Retrieve Lowest Digit and Save in Lower Nibble of First_Digit
        RAM = Display_Port; // Save Display Port value into RAM
        Display_Port =  First_Digit | (RAM&=0xF0) ;  //Clear Lower Nibble Of Variable RAM and Add Value of First Digit To RAM.
        Digit_1 =  Active; // Enable Digit
        Digit_2 = !Active; // Disable Digit
        Digit_3 = !Active; // Disable Digit
        Digit_4 = !Active; // Disable Digit
        __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.


        Second_Digit = (TMP36_Reading % 100)/10;  // Retrieve 2nd Lowest Digit and Save in Lower Nibble of  Second_Digit
        RAM = Display_Port; // Save Display Port value into RAM
        Display_Port =  Second_Digit | (RAM&=0xF0) ; //Clear Lower Nibble Of Variable RAM and Add Value of Second Digit To RAM.
        Digit_1 = !Active; // Disable Digit
        Digit_2 =  Active; // Enable Digit
        Digit_3 = !Active; // Disable Digit
        Digit_4 = !Active; // Disable Digit
        __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.


        Third_Digit = (TMP36_Reading % 1000)/100; // Retrieve 3rd Lowest Digit and Save in Lower Nibble of Third_Digit
        RAM = Display_Port; // Save Display Port value into RAM
        Display_Port =  Third_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Third Digit To RAM.
        Digit_1 = !Active; // Disable Digit
        Digit_2 = !Active; // Disable Digit
        Digit_3 =  Active; // Enable Digit
        Digit_4 = !Active; // Disable Digit
        __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.


        Fourth_Digit = TMP36_Reading / 1000; // Retrieve Highest Digit and Save in Lower Nibble of Fourth_Digit
        RAM = Display_Port; // Save Display Port value into RAM
        Display_Port =  Fourth_Digit | (RAM&=0xF0);//Clear Lower Nibble Of Variable RAM and Add Value of Fourth Digit To RAM.
        Digit_1 = !Active; // Disable Digit
        Digit_2 = !Active; // Disable Digit
        Digit_3 = !Active; // Disable Digit
        Digit_4 = Active; // Enable Digit
        __delay_ms(Seg_Timing);// Run Millisecond Delay for Defined Time.

}

void UART_Positive_Negative_Tempreture_Output(void)
{              
    whole = TMP36_Reading; // Copy Temperature reading into whole.
    decimal=(TMP36_Reading-whole)*1000; //Calculate Decimal part of temperature reading.
    sprintf(xvalueASCII,"%s%3d.%01d%s","Temperature : ",whole,decimal, " Degrees \n\r " ); //Convert to string and combine pre written message
    USART_String_Transmit(xvalueASCII);// Transmit string via serial USART
        
}

 //Function that will send string data
void USART_String_Transmit(char *string)
{   
    while(!EUSART_is_tx_ready()); //wait for transmitter to be ready
    while (*string)             //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);  // send the current element in the array to the terminal, then increment pointer.
    while (!EUSART_is_tx_done()); // wait until TX is done    
}
/**
 End of File
*/