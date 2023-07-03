/* Exercise : Sharp GP2S120 Distance Sensor Reading Via USART Example.
 * Author : Usmaan H
 * Version : 1.0
 * Description : Using the Sharp GP2S120 Distance Sensor we can calculate the distance of an object from the sensor using the channel A0 of the PIC's ADC.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.
#include <stdio.h> // Standard Input Output Header File.
#include <string.h> // String Header File.
#include <math.h> // Include math header file.

//Function declarations
void SendUsartString(char *str); // USART String Transmitting Function.

//Variable declarations
char xvalueASCII [50];     // USART string storage array.
unsigned int ADC_Result_1; // Value to store ADC Conversion result from distance sensor.
float Calculated_result;   // Store calculated distance sensor value.

/*
                         Main application
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    while(1){
        
        ADC_Result_1 = ADC_GetConversion(0);                                                 //Retrieve distance sensor ADC result from RA0.
        Calculated_result =(4450/(float)(ADC_Result_1)-1);                                   //Calculate distance of object.
        Calculated_result = round(Calculated_result);                                        //Round result to nearest integer.  
        sprintf(xvalueASCII,"%s%d%s","Distance : ",(unsigned int)Calculated_result,"cm\r\n");//Concatenate message with distance sensor value and create string.
        SendUsartString(xvalueASCII);                                                        // Transmit distance sensor measurement message.
        __delay_ms(1000);                                                                    // 1 second delay.
    }
}

 void SendUsartString(char *str){  //Function that will send string data
       while (*str)             //while the pointer has not reached the end of the array of chars keep sending.
        EUSART_Write(*str++);  // send the current element in the array to the terminal, then increment pointer.
  }
 
/**
 End of File
*/