/* Exercise : Master Receiver Example Part 2 of 2. 
 * Author : Usmaan H
 * Version : 1.0
 * Description : In this combined exercise the slave device receives a 8 bit value via USART and then
 *               outputs that value on Port B.
 */

// Header Files
#include "mcc_generated_files/mcc.h" // MCC Code Configurator Generated Header.

//Port Definitions
#define Output LATB // Assign LATB with name Output.

/*Main application*/
void main(void)
{
    
    SYSTEM_Initialize();// Initialize the device       
    
    while (1){   
    Output = EUSART_Read(); // Copy value of USART Rx register on PORT B.
    }
    
}

/**
 End of File
*/

