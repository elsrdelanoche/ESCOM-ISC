#include "Concurrencia.h"
#include <stdbool.h>


int main(int argc, char const *argv[])
{
    //Iniciar Servidor
    //Cargar BD de los archivos de texto
    Load_DB("Base_Datos/Inv.xml");

    //Escuchar puertos
    bool exit = false;

    while (!exit)
    {
        //Tareas del servidor
    }
    //Cerrar el servidor

    return 0;
}
