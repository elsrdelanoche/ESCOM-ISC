#include <stdio.h>
#include <string.h>

int main() {
    // Se declara un buffer para almacenar la trama ARP ingresada por el usuario
    unsigned char frame[60];

    printf("Ingrese la trama ARP en formato hexadecimal (60 bytes): \n");
    for (int i = 0; i < 60; i++) {
        scanf("%hhx", &frame[i]);
    }

    // Se extraen las direcciones IP de origen y destino de la trama
    unsigned char sourceIP[4];
    unsigned char destinationIP[4];
    memcpy(sourceIP, &frame[28], 4);
    memcpy(destinationIP, &frame[38], 4);

    // Se verifica si las direcciones IP pertenecen a la misma red
    int sameNetwork = 1;
    for (int i = 0; i < 4; i++) {
        printf("IP fuente: %hhx\t",sourceIP[i]);
        printf("IP destino: %hhx\n",destinationIP[i]);
        if (sourceIP[i] != destinationIP[i]) {
            sameNetwork = 0;
            break;
        }
    }
    
    // Se imprime el resultado
    if (sameNetwork) {
        printf("La trama ARP pertenece a la misma red.\n");
    } else {
        printf("La trama ARP pertenece a una red diferente con el mismo enrutador.\n");
    }

    return 0;
}
