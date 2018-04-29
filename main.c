#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "bibliotecaInput.h"

#define CANT_PER 20

int main()
{
    EPersona persona[CANT_PER];

    char auxiliarOpcionStr[50];
    char seguir='s';
    int opcion=0;

    inicializarEstado(persona, CANT_PER, 1);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        while (!getStringNumeros("\nIngrese la opcion: ", auxiliarOpcionStr)) {
            system("clear");
            printf("\nLa opcion debe ser numerica\n\n");
            printf("1- Agregar persona\n");
            printf("2- Borrar persona\n");
            printf("3- Imprimir lista ordenada por  nombre\n");
            printf("4- Imprimir grafico de edades\n\n");
            printf("5- Salir\n");
        }

        opcion = atoi(auxiliarOpcionStr);

        switch(opcion)
        {
            default:
                system("clear");
                printf("\nLa opcion debe ser un valor entre 1 y 5\n\n");
                break;
            case 1:
                altaPersona(persona, CANT_PER);
                break;
            case 2:
                borrarPersona(persona, CANT_PER);
                break;
            case 3:
                listaOrdenada(persona, CANT_PER);
                break;
            case 4:
                imprimrGrafico(persona, CANT_PER);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;

}

