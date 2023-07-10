/* Exercise :  Monitoring Potentiometer Voltage Over UART.
 * Author : Usmaan H 
 * Version : 1.0
 * Description : In this exercise we will see how to display the voltage output of the potentiometer connected on pin RA0 using the USART serial terminal.
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header
#include <stdio.h> //  Standard Input Output handling Functions
#include <string.h> // String Handing Functions

//Define Functions
void USART_String_Transmit(char *string); // Transmit String using USART.

// Declaring Variables
 unsigned int adc; // Variable adc stores the 10bit ADC result.
 float VREF = 3.30; // Variable VREF which is the reference voltage.
 float Vin;// Variable Vin which is the calculated input voltage.
 char intvalueASCII[50];// character array to store string elements for USART.

/*Main application*/
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        adc= ADC_GetConversion(0); // Copy the conversion results into variable adc.
        LATD = ADRESL; // Display contents of ADRESL on Port D. 
        LATB = ADRESH; // Display contents of ADRESH on Port B. 
        //Left Justified = 8 bit result in ADRESH , ignore 2 LSB in ADRESL.
        //Right Justified = 10 bit result with 8 bits in ADRESL and 2 MSB in ADRESH.
        
        Vin = (adc * VREF / 1023); // Calculate the input voltage Vin.
        sprintf(intvalueASCII,"%s%.2f%s","Potentiometer Wiper Voltage : ", Vin,"V\r\n"); //Assembly message for USART output.
        USART_String_Transmit(intvalueASCII); //Transmit string message via USART.
    }
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