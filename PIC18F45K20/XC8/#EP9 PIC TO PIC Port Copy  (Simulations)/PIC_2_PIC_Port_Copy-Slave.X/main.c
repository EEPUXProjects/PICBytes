/* Exercise : PIC_2_PIC_PORT_SLAVE_Example
 * Author : Usmaan H
 * Version : 1.0
 * Description : Master PIC to Slave PIC8-bit parallel transfer with BARGRAPH example. 
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

    while (1)
    {
        LATC=PORTB;
    }
}
/**
 End of File
*/