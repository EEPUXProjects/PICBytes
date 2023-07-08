/* Exercise : Reading the DHT11 temperature and humidity sensor.
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this exercise we will be reading the output temperature and humidity data of the DHT11 sensor via USART.
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header
#include <stdio.h> //  Standard Input Output handling Functions
#include <string.h> // String Handing Functions

// Function Declaration
void DHT11_Initiate(void);       // Initiate connection with DHT11 sensor.
void DHT11_Responce_Check(void); // Wait for device to be ready.
char DHT11_Read_Data(void);      // Retrieve 8-bit data from DHT11.
void USART_String_Transmit(char *string); // Transmit serial string data.

// Variables
char RH_Decimal,RH_Integral,T_Decimal,T_Integral,Checksum; // Variables to store 8-bit data from DHT11 sensor. 
char xvalueASCII [50]; // character array to store string elements for USART.

/*
                         Main application
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        DHT11_Initiate();  // Initiate connection with sensor.
        DHT11_Responce_Check();  // Wait for device to be ready.

        RH_Integral = DHT11_Read_Data();  // Retrieve 8-bit humidity integral value.
        RH_Decimal = DHT11_Read_Data();   // Retrieve 8-bit humidity decimal value.
        T_Integral = DHT11_Read_Data();   // Retrieve 8-bit temperature integral value.
        T_Decimal = DHT11_Read_Data();    // Retrieve 8-bit temperature decimal value. 
        Checksum = DHT11_Read_Data();     // Retrieve 8-bit checksum value.
   
        sprintf(xvalueASCII,"%s %d.%d %s","Humidity : ",RH_Integral,RH_Decimal, " g.m-3 \n\r " ); //Convert to humidity string and combine pre written message.
        USART_String_Transmit(xvalueASCII);// Transmit string via serial USART.

        sprintf(xvalueASCII,"%s%d.%d%s","Temperature : ",T_Integral,T_Decimal, " Degrees \n\r " ); //Convert to temperature string and combine pre written message.
        USART_String_Transmit(xvalueASCII);// Transmit string via serial USART.

        sprintf(xvalueASCII,"%s%d%s","Checksum : ",Checksum, "\n\r " ); //Convert to checksum string and combine pre written message.
        USART_String_Transmit(xvalueASCII);// Transmit string via serial USART.
        
        // Check if total of humidity and temperature values is equal to checksum.
        if(Checksum != (RH_Integral + RH_Decimal + T_Integral + T_Decimal))
            USART_String_Transmit("Error\n\r ");// Transmit string via serial USART.
        else
            USART_String_Transmit("No Error\n\r ");// Transmit string via serial USART.

        __delay_ms(500); // 500 millisecond delay.
    }
}

char DHT11_Read_Data(void)
{
  char Counter,Data_in = 0;            //Create counter variable Counter and data in variable Data_in.
    for(Counter=0;Counter<8;Counter++)
    {                                 /*Essentially what is happening in this function is that 8 bits of data is collected at a time. So if a logic High is detected then the data register is being 
                                        shifted left by 1 with their now being a zero in the LSB. Then a 1 is OR'd or added to the register so that the LSB is now 1.
                                        Otherwise if a logic LOW is detected then the register is only shifted by 1. Leaving the LSB as 0. Finally the cycle starts again to check the next bit.*/
        while(!(DHT11_PORT & HIGH));   // Wait for port to be High.
        __delay_us(30);                // 30 millisecond delay.
        if(DHT11_PORT & HIGH)          // Check if data is HIGH or LOW  
          Data_in = ((Data_in<<1) | 1);// Left shift contents of data by one and add 1 at LSB by one. Then save into data variable.   
        else             
          Data_in = (Data_in<<1);      // Left shift contents of data by one and save into data variable.
        while(DHT11_PORT & HIGH);      // Wait for port to be LOW.  
    }
  return Data_in;                      // Return the 8 bit sensor data.
}

void DHT11_Initiate(void)
{    
    DHT11_TRIS = LOW;  // Configure port as output.
    DHT11_LAT = LOW;   // Disable pin.
    __delay_ms(18);    // 18 millisecond delay.
    DHT11_LAT = HIGH;  // Enable pin.
    __delay_us(20);    // 20 millisecond delay.
    DHT11_TRIS = HIGH; // Configure port as input.    
}

void DHT11_Responce_Check(void)
{
    while(DHT11_PORT & HIGH);     // Wait for port to be LOW.   
    while(!(DHT11_PORT & HIGH));  // Wait for port to be High. 
    while(DHT11_PORT & HIGH);     // Wait for port to be LOW.
}

 //Function that will send string data
void USART_String_Transmit(char *string)
{   
    while(!EUSART_is_tx_ready()); //wait for transmitter to be ready.
    while (*string)               //while the pointer has not reached the end of the array of chars keep sending.
    EUSART_Write(*string++);      // send the current element in the array to the terminal, then increment pointer.
    while (!EUSART_is_tx_done()); // wait until TX is done.    
}
/**
 End of File
*/