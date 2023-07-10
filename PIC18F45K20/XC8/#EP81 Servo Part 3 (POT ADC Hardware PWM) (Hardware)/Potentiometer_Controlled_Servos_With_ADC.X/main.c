/* Exercise : Potentiometer Controlled Servo Example.
 * Author : Usmaan H
 * Version : 1.0
 * Description : Using a single potentiometers to control a servo motor.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.
#include <stdio.h> // Standard Input Output Header File.
#include <string.h> // String Header File.

//Function declarations
void SendUsartString(char *str); // USART String Transmitting Function.
long map(long x, long in_min, long in_max, long out_min, long out_max); // Function to map one range of values to another range of values.

//Variable declarations
char xvalueASCII [50]; // USART string storage array.
unsigned int ADC_Result_1;    //Value to store ADC Conversion result for servo 1 angle.
unsigned int Servo_1_Map;   //Servo_1_Map PWM value.
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    while(1){
        
        ADC_GetConversion(0);                           //Retrieve Servo 1 result from RA0.
        Servo_1_Map = map(ADRESH, 0, 255, 31, 63);                 // Map 8 bit ADC resolution to Servo 1 motor rotation of -90 to 90 degrees.
        PWM2_LoadDutyValue(Servo_1_Map );                                // Load requested angle of servo 1.
        sprintf(xvalueASCII,"%s%d%s","Servo 1 Value : ",Servo_1_Map,"\r\n"); //Concatenate message with servo angle and create string.
        SendUsartString(xvalueASCII);                                  // Transmit Servo 1 servo message.
        __delay_ms(1000);                                              // 1 second delay.    
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