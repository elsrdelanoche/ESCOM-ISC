/*
 * File:   %<%NAME%>%.%<%EXTENSION%>%
 * Author: %<%USER%>%
 *
 * Created on %<%DATE%>%, %<%TIME%>%
 */

    .include "p33fj32mc202.inc"

    ; _____________________Configuration Bits_____________________________
    ;User program memory is not write-protected
    #pragma config __FGS, GWRP_OFF & GSS_OFF & GCP_OFF
    
    ;Internal Fast RC (FRC)
    ;Start-up device with user-selected oscillator source
    #pragma config __FOSCSEL, FNOSC_FRC & IESO_ON
    
    ;Both Clock Switching and Fail-Safe Clock Monitor are disabled
    ;XT mode is a medium-gain, medium-frequency mode that is used to work with crystal
    ;frequencies of 3.5-10 MHz
  ; #pragma config __FOSC, FCKSM_CSDCMD & POSCMD_XT
    
    ;Watchdog timer enabled/disabled by user software
    #pragma config __FWDT, FWDTEN_OFF
    
    ;POR Timer Value
    #pragma config __FPOR, FPWRT_PWR128
   
    ; Communicate on PGC1/EMUC1 and PGD1/EMUD1
    ; JTAG is Disabled
    #pragma config __FICD, ICS_PGD1 & JTAGEN_OFF
Esto es lo que soñé
MOV #8, W1      ; Inicializamos los registros con los valores a ordenar
MOV #6, W2
MOV #3, W3
MOV #5, W4
MOV #2, W5
MOV #4, W6
MOV #1, W7
MOV #9, W8
MOV #7, W9
MOV #10, W10
MOV #0, W11     ; Variable temporal para intercambio
MOV #1, FLAG    ; Bandera para controlar el ciclo

inicio:
    MOV #0, FLAG    ; Inicializamos la bandera a 0 en cada recorrido

    ; Comparamos W1 y W2
    CPSGT W1, W2    ; Compara W1 y W2
    BRA intercambiow1w2  ; Si W1 > W2, ir a intercambio
    BRA compararw2w3     ; Si no, seguir con la siguiente comparación

intercambiow1w2:
    MOV W1, W11     ; Intercambiar W1 y W2
    MOV W2, W1
    MOV W11, W2
    MOV #1, FLAG    ; Se hizo un cambio, activamos la bandera
    BRA compararw2w3

compararw2w3:
    CPSGT W2, W3
    BRA intercambiow2w3
    BRA compararw3w4

intercambiow2w3:
    MOV W2, W11
    MOV W3, W2
    MOV W11, W3
    MOV #1, FLAG
    BRA compararw3w4

compararw3w4:
    CPSGT W3, W4
    BRA intercambiow3w4
    BRA compararw4w5

intercambiow3w4:
    MOV W3, W11
    MOV W4, W3
    MOV W11, W4
    MOV #1, FLAG
    BRA compararw4w5

compararw4w5:
    CPSGT W4, W5
    BRA intercambiow4w5
    BRA compararw5w6

intercambiow4w5:
    MOV W4, W11
    MOV W5, W4
    MOV W11, W5
    MOV #1, FLAG
    BRA compararw5w6

compararw5w6:
    CPSGT W5, W6
    BRA intercambiow5w6
    BRA compararw6w7

intercambiow5w6:
    MOV W5, W11
    MOV W6, W5
    MOV W11, W6
    MOV #1, FLAG
    BRA compararw6w7

compararw6w7:
    CPSGT W6, W7
    BRA intercambiow6w7
    BRA compararw7w8

intercambiow6w7:
    MOV W6, W11
    MOV W7, W6
    MOV W11, W7
    MOV #1, FLAG
    BRA compararw7w8

compararw7w8:
    CPSGT W7, W8
    BRA intercambiow7w8
    BRA compararw8w9

intercambiow7w8:
    MOV W7, W11
    MOV W8, W7
    MOV W11, W8
    MOV #1, FLAG
    BRA compararw8w9

compararw8w9:
    CPSGT W8, W9
    BRA intercambiow8w9
    BRA compararw9w10

intercambiow8w9:
    MOV W8, W11
    MOV W9, W8
    MOV W11, W9
    MOV #1, FLAG
    BRA compararw9w10

compararw9w10:
    CPSGT W9, W10
    BRA intercambiow9w10
    BRA fin

intercambiow9w10:
    MOV W9, W11
    MOV W10, W9
    MOV W11, W10
    MOV #1, FLAG
    BRA fin

fin:
    CPSNE FLAG, #0     ; Si FLAG no es 0, repetir el ciclo
    BRA inicio

    HALT               ; Si FLAG es 0, se detiene el algoritmo (lista ordenada)
    

;..............................................................................
;Program Specific Constants (literals used in code)
;..............................................................................

    .equ SAMPLES, 64         ;Number of samples



;..............................................................................
;Global Declarations:
;..............................................................................

    .global _wreg_init       ;Provide global scope to _wreg_init routine
                                 ;In order to call this routine from a C file,
                                 ;place "wreg_init" in an "extern" declaration
                                 ;in the C file.

    .global __reset          ;The label for the first line of code.

;..............................................................................
;Constants stored in Program space
;..............................................................................

    .section .myconstbuffer, code
    .palign 2                ;Align next word stored in Program space to an
                                 ;address that is a multiple of 2
ps_coeff:
    .hword   0x0002, 0x0003, 0x0005, 0x000A




;..............................................................................
;Uninitialized variables in X-space in data memory
;..............................................................................

    .section .xbss, bss, xmemory
x_input: .space 2*SAMPLES        ;Allocating space (in bytes) to variable.



;..............................................................................
;Uninitialized variables in Y-space in data memory
;..............................................................................

    .section .ybss, bss, ymemory
y_input:  .space 2*SAMPLES




;..............................................................................
;Uninitialized variables in Near data memory (Lower 8Kb of RAM)
;..............................................................................

    .section .nbss, bss, near
var1:     .space 2               ;Example of allocating 1 word of space for
                                 ;variable "var1".




;..............................................................................
;Code Section in Program Memory
;..............................................................................

.text                             ;Start of Code section
__reset:
    MOV #__SP_init, W15       ;Initalize the Stack Pointer
    MOV #__SPLIM_init, W0     ;Initialize the Stack Pointer Limit Register
    MOV W0, SPLIM
    NOP                       ;Add NOP to follow SPLIM initialization

    CALL _wreg_init           ;Call _wreg_init subroutine
                                  ;Optionally use RCALL instead of CALL




        ;<<insert more user code here>>


;SETM    AD1PCFGL  ;PORTB AS DIGITAL
;CLR	TRISB
SETM	W10

	
done:	    ;INFINITE LOOP
    
    COM	    W10,    W10
    
    BRA     done              ;Place holder for last line of executed code



;..............................................................................
;Subroutine: Initialization of W registers to 0x0000
;..............................................................................

_wreg_init:
    CLR W0
    MOV W0, W14
    REPEAT #12
    MOV W0, [++W14]
    CLR W14
    RETURN




;--------End of All Code Sections ---------------------------------------------

.end                               ;End of program code in this file
