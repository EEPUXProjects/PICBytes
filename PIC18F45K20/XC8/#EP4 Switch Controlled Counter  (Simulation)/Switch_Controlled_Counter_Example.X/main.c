/* Exercise : Switch Controlled Counter Example 
 * Author : Usmaan H 
 * Version : 1.0
 * Description : This exercise teaches you how you can increment the value of 
 * port C when you press the switch connected to port pin B0. 
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files


void main(void)
{
    SYSTEM_Initialize();  // Initialise the device parameters

    LATC=0x00;
      while(1)                        
    {                               
        if(PORTBbits.RB0 == 0)   // If pin RB0 is Low
            {           
                LATC++;          // Directly Increment LATC register by 1
                __delay_ms(250); // Short delay              
            }
        else if (PORTBbits.RB0 == 1)// If pin RB0 is High 
            {
                NOP(); // Do nothing instruction   		 
            }       
    }
}

