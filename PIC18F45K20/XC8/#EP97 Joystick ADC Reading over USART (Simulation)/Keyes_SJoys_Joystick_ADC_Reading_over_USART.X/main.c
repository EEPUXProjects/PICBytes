/* Exercise : Joystick ADC Reading Via USART Example.
 * Author : Usmaan H
 * Version : 1.0
 * Description : Using a joystick or the equivalent two potentiometers and a switch we can see how to read the joystick using the ADC.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.
#include <stdio.h> // Standard Input Output Header File.
#include <string.h> // String Header File.

//Function declarations
void SendUsartString(char *str); // USART String Transmitting Function.

//Variable declarations
char xvalueASCII [50]; // USART string storage array.
unsigned int ADC_Result_1;    //Value to store ADC Conversion result for VRY.
unsigned int ADC_Result_2;    //Value to store ADC Conversion result for VRX.

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    while(1){
        
        ADC_Result_1 = ADC_GetConversion(1);                             //Retrieve VRY ADC result from RA1.
        sprintf(xvalueASCII,"%s%d%s","VRY Value : ",ADC_Result_1,"\r\n");//Concatenate message with VRY value and create string.
        SendUsartString(xvalueASCII);                                    // Transmit VRY message.
        __delay_ms(1000);                                                // 1 second delay.
        ADC_Result_2 = ADC_GetConversion(0);                             //Retrieve VRX ADC result from RA0.
        sprintf(xvalueASCII,"%s%d%s","VRX Value : ",ADC_Result_2,"\r\n");//Concatenate message with VRX value and create string.
        SendUsartString(xvalueASCII);                                    // Transmit VRX message.
        __delay_ms(1000);                                                // 1 second delay. 
        if (SW0_PORT == LOW){                                            // Internal Pull up is activated.
            __delay_ms(500);                                             //Debounce delay part 1.
            while(SW0_PORT == LOW);                                      //Debounce delay part 2.
            SendUsartString("Switch Pressed\r\n");                       // Confirm button press has been detected.   
        }      
    }
}

 void SendUsartString(char *str){  //Function that will send string data
       while (*str)             //while the pointer has not reached the end of the array of chars keep sending.
        EUSART_Write(*str++);  // send the current element in the array to the terminal, then increment pointer.
       
  }
 
/**
 End of File
*/