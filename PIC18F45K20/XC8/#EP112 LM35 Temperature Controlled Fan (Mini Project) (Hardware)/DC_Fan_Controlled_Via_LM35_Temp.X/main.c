/* Exercise : LM35 Temperature controlled DC Fan 
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will see how the the LM35 will control the speed of the DC motor fan. This code only works for positive temperatures only.
 */


// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.
#include <stdio.h> // Standard Input Output Header File.
#include <string.h> // String Header File.

//Function declarations
void SendUsartString(char *str); // USART String Transmitting Function.
long map(long x, long in_min, long in_max, long out_min, long out_max); // Function to map one range of values to another range of values.

//Variables
float Voltage; // ADC conversion result storage.
int LM35_Reading; // Calculated temperature reading storage.
char xvalueASCII [50]; // USART string storage array.
long DC_Fan_Speed; // DC fan speed value storage.

/*Main application*/
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    
    L293D_IN1_LAT=HIGH; // Enable pin IN1.
    L293D_IN2_LAT=LOW;  // Disable pin IN2.
    
    while (1)
    {       
        Voltage = ADC_GetConversion(0); // Read the ADC result & store in variable voltage.         
        LM35_Reading = ((((Voltage*5000)/1023)))/10; // Convert adc reading into meaningful temperature reading.
        sprintf(xvalueASCII,"%s %3d %s","Temperature :",LM35_Reading ," Degrees \n\r "); //Concatenate message with temperature reading result.
        SendUsartString(xvalueASCII); // Transmit message via usart.
        DC_Fan_Speed = map(LM35_Reading, 35, 150, 0, 1023);// Map temperature with pwm range to calculate DC motor fan speed.
        PWM2_LoadDutyValue( DC_Fan_Speed ); // Apply calculated speed
        if (LM35_Reading < 35){             // Disable fan if temperature is within operational limits.
            PWM2_LoadDutyValue( 0 );
        }
       
    }
}

 void SendUsartString(char *str){  //Function that will send string data
       while (*str)             //while the pointer has not reached the end of the array of chars it will keep sending.
        EUSART_Write(*str++);  // send the current element in the array to the terminal, then increment pointer.
  }
 
 long map(long x, long in_min, long in_max, long out_min, long out_max) // Function to map one range of values to another range of values.
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
/**
 End of File
*/
