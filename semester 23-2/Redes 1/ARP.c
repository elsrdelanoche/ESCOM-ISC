#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char tramaARP[17];
    char direccionMACDestino[13];
    char direccionMACOrigen[13];
    char direccionIPDestino[16];
    char direccionIPOrigen[16];
    char direccionMASCARA[16];

    printf("Ingrese la trama ARP en formato hexadecimal (16 caracteres): ");
    scanf("%s", tramaARP);

    // Extraer las diferentes partes de la trama ARP
    strncpy(direccionMACDestino, tramaARP, 12);
    direccionMACDestino[12] = '\0';

    strncpy(direccionMACOrigen, tramaARP + 12, 12);
    direccionMACOrigen[12] = '\0';

    strncpy(direccionIPDestino, tramaARP + 24, 8);
    direccionIPDestino[8] = '\0';

    strncpy(direccionIPOrigen, tramaARP + 32, 8);
    direccionIPOrigen[8] = '\0';

    strncpy(direccionMASCARA, tramaARP + 40, 8);
    direccionMASCARA[8] = '\0';

    // Comparar las direcciones IP de origen y destino para determinar si están en la misma red
    int mismaRed = strncmp(direccionIPDestino, direccionIPOrigen, 8) == 0;

    // Comparar las direcciones MAC de origen y destino para determinar si pertenecen al mismo router
    int mismoRouter = strncmp(direccionMACDestino, direccionMACOrigen, 12) == 0;

    if (mismaRed && mismoRouter) {
        printf("La trama ARP pertenece a la misma red y al mismo router.\n");
    } else if (mismaRed) {
        printf("La trama ARP pertenece a la misma red pero a un router diferente.\n");
    } else {
        printf("La trama ARP pertenece a una red diferente.\n");
    }

    return 0;
}
