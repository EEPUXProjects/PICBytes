;****************************************************************************************
;    Filename:		 Morse_Code.asm                                                 *
;    Date:               15/09/20                                                       *
;    File Version:       1.0                                                            *
;    Author:             Usmaan H                                                       *
;    Program Function:   Output Characters Using Morse Code.                            *
;Notes: Uncomment subcode for use. Insufficent space , does not include entire alphabet *
;****************************************************************************************
#include "p10f200.inc" ; Processor specific variable definitions                        *
;****************************************************************************************
;****************************************************************************************
; CONFIGURATION BITS                                                                    *
; (Microchip has changed the format for defining the configuration bits, please         *
; see the .inc file for further details on notation). Below are a few examples.         *
;                                                                                       *
; __config 0xFFB                                                                        *
 __CONFIG _WDTE_OFF & _CP_OFF & _MCLRE_ON ;                                             *
;****************************************************************************************
; VARIABLES                                                                             *
; Your variables definition below:                                                      *
Delay_1   EQU   	 10   	; Reserve location for Delay value1                     *
Delay_2   EQU   	 11   	; Reserve location for Delay value1                     *
Delay_3   EQU   	 12   	; Reserve location for Delay value1                     *
 ;****************************************************************************************
; RESET VECTOR                                                                          *
; This code will start executing when a reset occurs.                                   *
    ORG     0x0000          ; ORG Directive                                             *
    goto    Main            ; go to start the code on "Main" label                      *
;****************************************************************************************
; Your configuration code here:                                                         *
Main                          ;                                                         *
    MOVLW  ~(1<<T0CS)         ;enable GPIO2                                             *
    OPTION		      ;                                                         * 
    MOVLW ~(1 << GP2)         ;set GP2 as an output                                     *
    TRIS GPIO                 ;                                                         *
LOOP                          ;                                                         *
; Your looping behaviours & subroutine calls here:                                      *
    CALL Character_A   	      ; Call Character A routine                                *
    CALL New_Character        ; Call New Character A routine                            *                          *     

    GOTO LOOP                 ; Loop                                                    *             
; New Word Routine is below                                                             *
New_Word                      ;                                                         *    
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Word_Pause      ; Call routine to indicate new word                            *
    RETLW 0                   ; Return back from subroutine to Main.                    *
; New Character Routine is below                                                        *
New_Character                  ;                                                        *    
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    *
    RETLW 0                    ; Return back from subroutine to Main.                   *   
; Character Selection Routine is below                                                  *
;Character_A                    ;                                                        *
;   ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *   			 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 	 
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *   
;    RETLW 0                   ; Return back from subroutine to Main.                    *
;Character_B                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *     
;   ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *   
;   ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *   
;    RETLW 0                   ; Return back from subroutine to Main.                    *    
;Character_C                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    RETLW 0                   ; Return back from subroutine to Main.                    *    
;Character_D                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.                    *    
;Character_E                    ;                                                        *
;;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *     *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.                    *    
;Character_F                    ;                                                        *
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.         
;Character_G                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.       
;Character_H                    ;                                                        *
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.       
;Character_I                    ;                                                        *
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                               *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.   
;Character_J                    ;                                                        *
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                               *                        * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.       
;Character_K                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.       
;Character_L                    ;                                                        *
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.   
;    
;Character_M                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.      
;Character_N                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.       
;Character_O                    ;                                                        *
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.       
;
;Character_P                    ;                                                        *
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dash                                                                          *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          * 
;    ;Morse Dot                                                                           *
;    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
;    CALL Dot   		       ; Call routine to indicate dots                          *       
;;   ;Element Pause                                                                       *
;;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
;    RETLW 0                   ; Return back from subroutine to Main.       
;    
Character_Q                    ;                                                        *
   ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
   ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.    
    

Character_R                    ;                                                        *
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.      

Character_S                    ;                                                        *
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       

Character_T                    ;                                                        *
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       
 
Character_U                    ;                                                        *
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       

Character_V                    ;                                                        *
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
     ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       

Character_W                    ;                                                        *
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
     ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
     ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       
   
Character_X                    ;                                                        *
     ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
      ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       
 
Character_Y                    ;                                                        *
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       

Character_Z                    ;                                                        *
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dash                                                                          *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dash_Spaces     ; Call routine to indicate dashes/spaces between characters    * 
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
   ;Element Pause                                                                       *
    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    ;Morse Dot                                                                           *
    BSF GPIO,2                 ; Enable GPIO Pin 2                                      * 
    CALL Dot   		       ; Call routine to indicate dots                          *       
;   ;Element Pause                                                                       *
;    BCF GPIO,2                 ; Diaable GPIO Pin 2                                     * 
;    CALL Dot   		       ; Call routine to indicate dots                          *                        * 
    RETLW 0                   ; Return back from subroutine to Main.       
   
    
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
    MOVLW D'150'	      ; MOVE Decimal value of 255 into W Reg.                   *       	 
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