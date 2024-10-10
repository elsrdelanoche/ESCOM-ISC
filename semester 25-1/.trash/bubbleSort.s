
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