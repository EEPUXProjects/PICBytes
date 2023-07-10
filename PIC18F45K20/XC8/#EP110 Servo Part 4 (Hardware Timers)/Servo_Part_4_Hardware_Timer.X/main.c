/* Exercise : Servo Controllll Via A Timer.
 * Modified for XC8 by : Usmaan H
 * Version : 1.0
 * Description : This exercise has been modified so that it is now compatible with XC8 V2.36 and MCC code configurator.
 *               Also it is now possible to request a certain angle by entering the number in variable Requested_Angle.
 * Original Author : Martin d'Allens
 * Source : https://github.com/7Robot/PIC/blob/master/servomotor_lib.X/servo.c
 * Note: Approx 2 Degrees Simulated Accuracy.
 */

// Include Necessary Header Files
#include "mcc_generated_files/mcc.h" // Include MCC Configurator Generated Files
#include <stdio.h> // Standard Input Output Header File.
#include <string.h> // String Header File.

// Function Declarations
void OpenServo(int count); // Initialise Servos.
void WriteServo(int n, int angle); // Write servo angle to servo n.
void InterruptServo(void); // Background Interrupt servo control routine.
long map(long x, long in_min, long in_max, long out_min, long out_max){}; // Function to map one range of values to another range of values.

//Variable Definitions
unsigned int AngleServo[8] = {0}; // Store upto 8 servos for use.
int Selected_Servo = 0; // Initialise selected servo variable.
int Current_Servo = 0; // Initialise current servo variable.
int Angle = 0; // Initialise angle variable.
int Direction = 1; // Initialise direction variable.
unsigned int Requested_Angle = 90; //Store requested angle.
unsigned int Calibrated_Angle; //Store calibrated angle.
unsigned int Servo_1_Calibration_Value = 2; //Adjust Value to match requested angle to actual angle.
unsigned int Servo_1_Map ;   //Servo 1 PWM value.
//Port Definitions
#define PORT_LAT LATB // Define name for LAT register of PORT with servo.
#define PORT_TRIS TRISB // Define name for TRIS register of PORT with servo.

// Main Program
void main(void)
{
    SYSTEM_Initialize();// Initialise the device.
    
    INTERRUPT_GlobalInterruptEnable(); // Enable the Global Interrupts. 
    
    OpenServo(1); // Enable 1 Servo. Pin RB0.

    TMR0_SetInterruptHandler(InterruptServo); // Load custom servo interrupt routine "InterruptServo" into MCC interrupt routine.
    
    while (1) { 
        Calibrated_Angle = (Requested_Angle - Servo_1_Calibration_Value);// Calibrated servo value.
        Servo_1_Map = map(Calibrated_Angle, 0, 180, 38, 139); // Map 10 bit ADC resolution to pan servo motor rotation of -90 to +90 degrees.
        WriteServo(0, Servo_1_Map);  //Write current value of variable Angle to servo 0. RB0.
        
        //WriteServo(0, Angle);  //Write current value of variable Angle to servo 0. RB0.
        __delay_ms(50); // Short delay.

        Angle += Direction; // Angle = Angle + Direction.

        if (Angle >= 180 || Angle <= 0) { // Control whether servo turns clockwise or anti-clockwise.
            Direction = -Direction;       // Invert value.
            __delay_ms(10);               // Short delay.
        }
    }
}

// Configure the Servo library.
// Max number of servos is 8. Available ports RB0 to RB7.
void OpenServo(int count) {
    if (count < 0 || count > 8)
        return;
    Selected_Servo = count;
    // Configure pins as outputs and initialise them to 0.
    PORT_TRIS &= 0xFF << count;
    PORT_LAT &= 0xFF << count;   
}

// Write servo angle to servo n.
void WriteServo(int n, int angle) {
    if (0 <= n && n < Selected_Servo && 0 <= angle && angle < 180)
        AngleServo[n] = angle;
}

// Background Interrupt servo control routine.
void InterruptServo(void) {

        if (Current_Servo > 0) {
            // Set previous pin (CurrentServo - 1) to 0.
            PORTB &= ~(1 << (Current_Servo - 1));
        }

        if (Current_Servo < Selected_Servo) {
            // Set current (CurrentServo) pin to 1.
            PORTB |= 1 << Current_Servo;

            TMR0_WriteTimer(65534 /* Max int */
                    /* Maximum width of 2.4ms. */
                    - AngleServo[Current_Servo] * 2 * ((2400 - 544) / 180)
                    /* Minimum width of 544µs. */
                    - 544 * 2 /* 2 = 8MHz / 4 (proc. freq) / 1µs  */
                    );
            // Between 0.9ms and 2.1ms.
        } else {
            TMR0_WriteTimer(65535 - 20000 * 2); // Minimum of 20ms between pulses.
        }

        Current_Servo++;
        if (Current_Servo > Selected_Servo)
            Current_Servo = 0;
        // When CurrentServo == CountServo, the next interrupt sets every pin to 0.

}

/**
 End of File
*/