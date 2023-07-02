/* Exercise : PIC_2_PIC_PORT_Master_Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : Master PIC to Slave PIC 8-bit parallel transfer with BARGRAPH example. 
 */

//Include Library Files
#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    LATD=0x55;
    while (1)
    {   
        LATD = ~LATD;		    // Load value of complemented LATD
        __delay_ms(750);	    // Short time delay
    }
}
/**
 End of File
*/