/* Exercise : Software PWM Servo Motor Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : To control servo via software PWM.
 */

// Library Files
#include "mcc_generated_files/mcc.h"

void servoRotate0() //0 Degree "-90" Degrees in proteus".
{
  unsigned int i;            // Integer variable to store delay.
  for(i=0;i<50;i++)          // Delay function to keep servo at specific position for 1 second.
  {                          // 50*((800ms+19200ms)/1000000) = 1 second.
    Software_Servo_LAT = 1;  // Enable pin.
    __delay_us(800);         // 800 microsecond delay.
    Software_Servo_LAT = 0;  // Disable pin.
    __delay_us(19200);       // 19200 microsecond delay.
  }
}

void servoRotate90() ///90 Degree "0" Degrees in proteus".
{
  unsigned int i;           // Integer variable to store delay.
  for(i=0;i<50;i++)         // Delay function to keep servo at specific position for 1 second.
  {                         // 50*((800ms+19200ms)/1000000) = 1 second.
    Software_Servo_LAT = 1; // Enable pin.
    __delay_us(1500);       // 1500 microsecond delay.
    Software_Servo_LAT = 0; // Disable pin.
    __delay_us(18500);      // 18500 microsecond delay.
  }
}

void servoRotate180() //180 Degree "+90" Degrees in proteus".
{
  unsigned int i;           // Integer variable to store delay.
  for(i=0;i<50;i++)         // Delay function to keep servo at specific position for 1 second.
  {                         // 50*((800ms+19200ms)/1000000) = 1 second.
    Software_Servo_LAT = 1; // Enable pin.
    __delay_us(2200);       // 2200 microsecond delay. 
    Software_Servo_LAT = 0; // Disable pin.
    __delay_us(17800);      // 17800 microsecond delay.
  }
}

/*
                         Main application
 */

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    while(1){
    servoRotate0();    // -90 Degrees. 
    __delay_ms(1000);  // 1000 millisecond delay.
    servoRotate90();   // 0 Degrees.
    __delay_ms(1000);  // 1000 millisecond delay.
    servoRotate180();  // +90 Degrees.
    __delay_ms(1000);  // 1000 millisecond delay.
  }
 
}
/**
 End of File
*/