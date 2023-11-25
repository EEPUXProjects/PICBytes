/* Exercise : Interfacing MPXV7007GP Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : Monitor air sensor via serial usart interface.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files.
#include <string.h> // Include string function header file.

//Variable declarations
int sensorValue = 0;  // variable to store the Raw Data value coming from the sensor.
float outputValue = 0; // variable to store converted kPa value.   
char xvalueASCII [50]; // USART string storage array.
 
 //Function declarations
void SendUsartString(char *str); // USART String Transmitting Function.
long map(long x, long in_min, long in_max, long out_min, long out_max); // Function to map one range of values to another range of values.

// Main Program
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        sensorValue = ADC_GetConversion(0); // read the value from the sensor:  
        outputValue = map(sensorValue, 0, 1023, -7000, 7000); // map the Raw data to kPa.   
        sprintf(xvalueASCII, "%s%d%s%f%s", "MPXV7007GP Sensor : ", sensorValue, "\toutput : ",outputValue,"\r\n"); //Concatenate message with raw adc data and calculated air pressure with predefined string.
        SendUsartString(xvalueASCII); // Transmit message with sensor data.
        __delay_ms(20); // 1 second delay.    
    }
}
//Function that will send string data
 void SendUsartString(char *str){   
       while (*str)                 //while the pointer has not reached the end of the array of chars keep sending.
        EUSART_Write(*str++);  // send the current element in the array to the terminal, then increment pointer.
       
  }
// Function to map one range of values to another range of values.
 long map(long x, long in_min, long in_max, long out_min, long out_max) 
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
/**
 End of File
*/