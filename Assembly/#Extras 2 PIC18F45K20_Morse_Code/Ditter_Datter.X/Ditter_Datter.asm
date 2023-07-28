;****************************************************************************************
;    Filename:		 Morse_Code_PIC18.asm                                           *
;    Date:               15/09/20                                                       *
;    File Version:       1.0                                                            *
;    Author:             Usmaan Hussain                                                 *
;    Company:            Coventry University                                            *
;    Program Function:   Output Characters Using Morse Code.                            *
;    Limitations Lifted !!! Write Whatever you like.                                    *
;****************************************************************************************
#include "p18f45k20.inc" ; Processor specific variable definitions                      *
;****************************************************************************************
; CONFIGURATION BITS                                                                    *
; (Microchip has changed the format for defining the configuration bits, please         *
; see the .inc file for further details on notation). Below are a few examples.         *
;                                                                                       *
; Oscillator Selection and other fuse settings:                                         *
	CONFIG    FOSC    =  INTIO67      ; Internal clock selected                     *
	CONFIG    MCLRE  =  ON      ; MCLR enabled                                      *
	CONFIG    DEBUG  =  OFF     ; Background debugger disabled                      *
        CONFIG    LVP    =  OFF	    ; Low Voltage Programming OFF                       *
	CONFIG    WDTEN = OFF     ; Watch-dog Timer Disabled                            *
;****************************************************************************************
; VARIABLES                                                                             *
; Your variables definition below:                                                      *
Delay_1   EQU   	 10   	; Reserve location for Delay value1                     *
Delay_2   EQU   	 11   	; Reserve location for Delay value2                     *
Delay_3   EQU   	 12   	; Reserve location for Delay value3                     *
 ;****************************************************************************************
; RESET VECTOR                                                                          *
; This code will start executing when a reset occurs.                                   *
    ORG     0x0000          ; ORG Directive                                             *
    goto    Main            ; go to start the code on "Main" label                      *
;****************************************************************************************
; Your configuration code here:                                                         *
Main                          ;                                                         *
    MOVLW b'01110110'         ;Move binary value into W register                        *
    MOVWF OSCCON              ;Configure for 16MHz internal oscillator                  *
    BCF TRISD,0               ;Configure Pin RD0 as output                              *
    BCF LATD,0                ;disable pin RD0                                          *
LOOP                          ;                                                         *
; Your looping behaviours & subroutine calls here:                                      *
    CALL New_Word        ; Call New_Word routine                                        *
    CALL Character_G   	      ; Call Character H routine                                *
    CALL New_Character        ; Call New Character routine                              *                           
    CALL Character_R   	      ; Call Character E routine                                *
    CALL New_Character        ; Call New Character routine                              *                         
    CALL Character_E   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                         
    CALL Character_E   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                          
    CALL Character_T   	      ; Call Character O routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_I   	      ; Call Character N routine                                *
    CALL New_Character        ; Call New Character routine                              *   
    CALL Character_N   	      ; Call Character I routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_G   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_S   	      ; Call Character I routine                                *
    CALL New_Word        ; Call New_Word routine                                        *
    CALL Character_A   	      ; Call Character T routine                                *
    CALL New_Character        ; Call New Character routine                              *   
    CALL Character_N   	      ; Call Character S routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_D   	      ; Call Character U routine                                *
    CALL New_Word        ; Call New_Word routine                                        *
    CALL Character_S   	      ; Call Character H routine                                *
    CALL New_Character        ; Call New Character routine                              *                      
    CALL Character_A   	      ; Call Character E routine                                *
    CALL New_Character        ; Call New Character routine                              *                            
    CALL Character_L   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                          
    CALL Character_U   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                           
    CALL Character_T   	      ; Call Character O routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_A   	      ; Call Character N routine                                *
    CALL New_Character        ; Call New Character routine                              *   
    CALL Character_T   	      ; Call Character I routine                                *
    CALL New_Character        ; Call New Character routine                              *                        
    CALL Character_I   	      ; Call Character E routine                                *
    CALL New_Character        ; Call New Character routine                              *                        
    CALL Character_O   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                        
    CALL Character_N   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_S   	      ; Call Character I routine                                *    
    CALL New_Word        ; Call New_Word routine                                        *                     
    CALL Character_U   	      ; Call Character O routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_R   	      ; Call Character N routine                                *
    CALL New_Word        ; Call New_Word routine                                        *    
    CALL Character_L   	      ; Call Character I routine                                *
    CALL New_Character        ; Call New Character routine                              *                        
    CALL Character_I   	      ; Call Character E routine                                *
    CALL New_Character        ; Call New Character routine                              *                         
    CALL Character_M   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                         
    CALL Character_A   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                        
    CALL Character_T   	      ; Call Character O routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_I   	      ; Call Character N routine                                *
    CALL New_Character        ; Call New Character routine                              *   
    CALL Character_O   	      ; Call Character I routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_N   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_S   	      ; Call Character H routine                                *
    CALL New_Word        ; Call New_Word routine                                        *                       
    CALL Character_H   	      ; Call Character E routine                                *
    CALL New_Character        ; Call New Character routine                              *                    
    CALL Character_A   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                         
    CALL Character_V   	      ; Call Character L routine                                *
    CALL New_Character        ; Call New Character routine                              *                         
    CALL Character_E   	      ; Call Character O routine                                *
    CALL New_Word        ; Call New_Word routine                                        * 
    CALL Character_B   	      ; Call Character N routine                                *
    CALL New_Character        ; Call New Character routine                              *   
    CALL Character_E   	      ; Call Character I routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_E   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_N   	      ; Call Character K routine                                *
    CALL New_Word        ; Call New_Word routine                                        * 
    CALL Character_L   	      ; Call Character N routine                                *
    CALL New_Character        ; Call New Character routine                              *   
    CALL Character_I   	      ; Call Character I routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_F   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_T   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_E   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_D   	      ; Call Character K routine                                *
    CALL New_Word        ; Call New_Word routine                                        * 
    CALL Character_E   	      ; Call Character N routine                                *
    CALL New_Character        ; Call New Character routine                              *   
    CALL Character_N   	      ; Call Character I routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_J   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_O   	      ; Call Character K routine                                *
    CALL New_Character        ; Call New Character routine                              * 
    CALL Character_Y   	      ; Call Character K routine                                *
While_Loop                    ;                                                         *
    CALL New_Word        ; Call New_Word routine                                        *
    GOTO While_Loop                 ; Loop                                              *             
; New Word Routine is below                                                             *
New_Word                      ;                                                         *    
    BCF LATD,0                ;disable pin RD0                                          * 
    CALL Word_Pause      ; Call routine to indicate new word                            *
    RETLW 0                   ; Return back from subroutine to Main.                    *
; New Character Routine is below                                                        *
New_Character                  ;                                                        *    
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    *
    RETLW 0                    ; Return back from subroutine to Main.                   *   
; Character Selection Routine is below                                                  *                  
Character_B                    ;                                                        *
   ;Morse Dash                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
Character_S                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *     
   ;Morse Dot                                                                           *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *   
   ;Morse Dot                                                                           *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *   
    RETLW 0                   ; Return back from subroutine to Main.                    *    
Character_C                    ;                                                        *
   ;Morse Dash                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
   ;Morse Dash                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  * 
    RETLW 0                   ; Return back from subroutine to Main.                    *    
Character_E                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *         
    RETLW 0                   ; Return back from subroutine to Main.                    *    
Character_F                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                
   ;Morse Dash                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                   
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                        
    RETLW 0                   ; Return back from subroutine to Main.                    * 
Character_H                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                     
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                       
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                      
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                       
    RETLW 0                   ; Return back from subroutine to Main.                    *
Character_J                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                            
Character_O                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
   ;Morse Dash                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
   ;Morse Dash                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                        
    RETLW 0                   ; Return back from subroutine to Main.                    *      
Character_L                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
Character_D                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                        
    RETLW 0                   ; Return back from subroutine to Main.                    *   
Character_P                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                         
Character_G                    ;                                                        * 
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                         
    RETLW 0                   ; Return back from subroutine to Main.                    *    
Character_Q                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
Character_K                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                         
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                        
    RETLW 0                   ; Return back from subroutine to Main.                    *    
Character_R                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
Character_N                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                         
    RETLW 0                   ; Return back from subroutine to Main.                    *
Character_V                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                       
Character_U                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
     ;Morse Dash                                                                        *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                        
    RETLW 0                   ; Return back from subroutine to Main.                    *
Character_X                    ;                                                        *
     ;Morse Dash                                                                        *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
Character_A                    ;                                                        *    
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
Character_T                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                         
    RETLW 0                   ; Return back from subroutine to Main.                    *
Character_Y                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
Character_W                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
Character_M                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                        
    RETLW 0                   ; Return back from subroutine to Main.                    *
Character_Z                    ;                                                        *
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
    ;Morse Dash                                                                         *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          * 
Character_I                    ;                                                        *
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *                        
    ;Morse Dot                                                                          *
    BSF LATD,0                ;disable pin RD0                                          *
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                      *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                    * 
;    CALL Dot   		       ; Call routine to indicate dots                  *                        
    RETLW 0                   ; Return back from subroutine to Main.                    * 
; DELAY ROUTINE FOLLOWS BELOW                                                           *
Word_Pause		      ;                                                         *
    MOVLW D'4'	              ; Move Decimal 4 into W Reg.                              *
    ADDWF Delay_3 , F	      ; ADD Contents of W Reg into Variable Delay_3.            *    
Dash_Spaces 	              ;                                                         *
    MOVLW D'2'	              ; Move Decimal 2 into W Reg.                              *  
    ADDWF Delay_3 , F	      ; ADD Contents of W Reg into Variable Delay_3.            *            
Dot 	                      ;                                                         *
    MOVLW D'1'	              ; Move Decimal 1 into W Reg.                              *     	             
    ADDWF Delay_3 , F	      ; ADD Contents of W Reg into Variable Delay_3.            *      
LOOP_Dot 	              ;                                                         *
    MOVLW D'50'	      ; MOVE Decimal value of 50 into W Reg.                            *       	 
    MOVWF Delay_1             ; Move this W reg value now to DELVAL2 location.          * 
    MOVLW D'200'   	      ; MOVE Decimal value of 255 into W Reg.                   *    
    MOVWF Delay_2             ; Move this W reg value now to DELVAL2 location.          *    		 
DELAY  	                      ;                                                         *
    DECFSZ Delay_1, F         ; skip next instruction if F=0.                           *    	             
    GOTO DELAY   	      ; Unconditional branch to DELAY.                          *   		 
    DECFSZ Delay_2, F         ; skip next instruction if F=0.                           *                 
    GOTO DELAY   	      ; Unconditional branch to DELAY.                          * 
    DECFSZ Delay_3, F         ; skip next instruction if F=0.                           *  
    GOTO LOOP_Dot   	      ; Unconditional branch to Loop_Dot.                       *
    RETLW 0   	              ; Return back from subroutine to Main.                    *
;**************************************************************************************** 
; END OF PROGRAM                                                                        *
; Assembler directive for end of program:                                               *
	END			    ;                                                   *
;****************************************************************************************