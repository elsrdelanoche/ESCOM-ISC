.section .text
.global _start

_start:
    ; Inicializamos los registros con los valores a ordenar
    MOV #8, W1
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
    MOV #1, W12     ; Variable de control para detectar si hubo intercambios

inicio:
    MOV #0, W12    ; Inicializamos W12 a 0 (sin intercambios por el momento)
    
    ; Llamamos a la función de comparación para cada par
    CALL comparar, W1, W2
    CALL comparar, W2, W3
    CALL comparar, W3, W4
    CALL comparar, W4, W5
    CALL comparar, W5, W6
    CALL comparar, W6, W7
    CALL comparar, W7, W8
    CALL comparar, W8, W9
    CALL comparar, W9, W10
    
    ; Si no hubo intercambios, termina el algoritmo
    CMP W12, #0
    BRA fin_sort    ; Si no hubo intercambios, lista ordenada
    BRA inicio      ; Si hubo intercambios, repetir el ciclo

fin_sort:
    HALT            ; Fin del algoritmo, lista ordenada

; Función comparar: recibe dos registros para comparar e intercambiar si es necesario
comparar:
    ; Entradas: Wn y Wn+1 (los registros que se compararán)
    CMP W0, W1         ; Compara los dos valores
    BRA intercambiar   ; Si W0 > W1, ir a intercambio
    BRA retorno        ; Si no, regresa sin hacer nada

intercambiar:
    MOV W0, W11        ; Almacenamos W0 en una temporal
    MOV W1, W0         ; Intercambiamos W0 y W1
    MOV W11, W1        ; Finalizamos el intercambio
    MOV #1, W12        ; Indicamos que hubo un intercambio
    BRA retorno

retorno:
    RET                ; Regresa a la siguiente comparación

