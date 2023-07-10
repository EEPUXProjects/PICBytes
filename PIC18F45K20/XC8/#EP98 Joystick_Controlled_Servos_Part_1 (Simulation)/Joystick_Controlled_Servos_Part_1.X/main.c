/* Exercise : Joystick Controlled Servo Example.
 * Author : Usmaan H
 * Version : 1.0
 * Description : Using a joystick or two potentiometers and a switch to do simple control of the pan and tilt motion of the pan/tilt device.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.
#include <stdio.h> // Standard Input Output Header File.
#include <string.h> // String Header File.

//Function declarations
void SendUsartString(char *str); // USART String Transmitting Function.
long map(long x, long in_min, long in_max, long out_min, long out_max){}; // Function to map one range of values to another range of values.

//Variable declarations
char xvalueASCII [50]; // USART string storage array.
unsigned int ADC_Result_1;    //Value to store ADC Conversion result for panning.
unsigned int ADC_Result_2;    //Value to store ADC Conversion result for tilting
unsigned int Pan_MAP ;   //Pan PWM value.
unsigned int Tilt_MAP;   //Tilt PWM value.
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    while(1){
        
        ADC_Result_1 = ADC_GetConversion(1);                           //Retrieve Pan ADC result from RA1.
        Pan_MAP = map(ADC_Result_1, 0, 1023, 31, 63);                  // Map 10 bit ADC resolution to pan servo motor rotation of -90 to +90 degrees.
        PWM2_LoadDutyValue(Pan_MAP );                                  // Load requested angle of pan servo.
        sprintf(xvalueASCII,"%s%d%s","Pan Value : ",Pan_MAP,"\r\n");   //Concatenate message with servo angle and create string.
        SendUsartString(xvalueASCII);                                  // Transmit pan servo message.
        __delay_ms(1000);                                              // 1 second delay.
        ADC_Result_2 = ADC_GetConversion(0);                           //Retrieve Tilt ADC result from RA0.
        Tilt_MAP = map(ADC_Result_2, 0, 1023, 31, 63);                 // Map 10 bit ADC resolution to tilt servo motor rotation of -90 to 90 degrees.
        EPWM1_LoadDutyValue(Tilt_MAP );                                // Load requested angle of servo.
        sprintf(xvalueASCII,"%s%d%s","Tilt Value : ",Tilt_MAP,"\r\n"); //Concatenate message with servo angle and create string.
        SendUsartString(xvalueASCII);                                  // Transmit tilt servo message.
        __delay_ms(1000);                                              // 1 second delay.  
        if (SW0_PORT == LOW){                                          // Internal Pull up is activated.
            SendUsartString("Switch Pressed\r\n");                     // Confirm button press has been detected.   
        }      
    }
}

 void SendUsartString(char *str){  //Function that will send string data
       while (*str)             //while the pointer has not reached the end of the array of chars keep sending.
        EUSART_Write(*str++);  // send the current element in the array to the terminal, then increment pointer.
       
  }

 long map(long x, long in_min, long in_max, long out_min, long out_max) // Function to map one range of values to another range of values.
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
 
/**
 End of File
*/