/* Exercise : Internal Incrementing Port C Output Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : This exercise teaches you a few ways on how to increment a variable called 'A' and
 * then load that new value into the LATC register.
 * 
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h"

// Define Variables
unsigned char A = 0x00;	  // Assign a hex value of 0 to variable A 

// Main Program
void main(void)
{
    SYSTEM_Initialize();  // Initialize the device parameters
    LATC=A;               // Load value of variable A into LATC
    while (1)
    {                             
        __delay_ms(100);  // Short time delay
        
        /*Option 1 (Better ways to do this)*/
//        A=A+1;            // Add 1 to variable A
//        LATC = A;	      // Then load new value in A into LATC
//        /*Option 2 (ok)*/
//        LATC= A++;        // Increment variable A by one, and then load new value into LATC
//        /*Option 3 (Best One and most efficient)*/
        LATC++;           // Increment LATC directly.
    }                          
}

/*
 End of File
*/