
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "bibliotecaInput.h"

/**
 * \brief Inicializa el estado en un array de personas
 * \param personaArray Es el array el cual se inicializara
 * \param arrayLenght Indica la longitud del array
 * \param value Es el valor que se asignara a estado
 * \return -
 *
 */

void inicializarEstado(EPersona personaArray[], int arrayLenght, int value){
    int i;
    for (i = 0; i < arrayLenght; i++){
        personaArray[i].estado = value;
    }
}

/**
 * Obtiene el primer indice libre del array.
 * \param lista El array se pasa como parametro.
 * \param arrayLenght Indica la longitud del array
 * \return Si no hay lugares libres (-1) y si la hay el primer indice disponible
 */

int obtenerEspacioLibre(EPersona lista[], int arrayLenght){
    int i;
    for(i = 0; i < arrayLenght; i++){
        if (lista[i].estado == 1) {
            return i;
        }
    }
    return -1;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista El array se pasa como parametro.
 * \param arrayLenght Indica la longitud del array
 * \param dni El dni a ser buscado en el array.
 * \return Si no hay coincidencia (-1) y si la hay, el indice en donde se encuentra el elemento que coincide con el parametro dni
 */

int buscarPorDni(EPersona lista[], int arrayLenght, int dni){
    int i;
    for (i = 0; i < arrayLenght; i++) {
        if (lista[i].dni == dni && lista[i].estado == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * Muestra los datos almacenados en una estructura de persona.
 * \param persona El array que se va a mostrar.
 */

void mostrarPersona(EPersona persona){
    printf("DNI: %d\nNombre: %s\nEdad: %d\n\n", persona.dni, persona.nombre, persona.edad);
}

/**
 * Da de alta una nueva persona.
 * \param array El array donde se va a almacenar.
 * \param arrayLenght La longitud del array donde se va a almacenar.
 */

void altaPersona(EPersona array[], int arrayLenght){

    EPersona persona;

    int indice;
    int existe;
    int dni;
    int edad;

    char dniAuxStr[50];
    char nombreAux[50];
    char edadAuxStr[50];

    system("clear");
    printf("\n - ALTA - \n\n");

    indice = obtenerEspacioLibre(array, arrayLenght);

    if (indice == -1) {
        printf("\nNO QUEDAN INDICES LIBRES PARA DAR DE ALTA UNA NUEVA PERSONA\n\n");
    }
    else {
        while (!getStringNumeros("Ingrese el DNI: ", dniAuxStr)) {
            printf("El DNI debe ser numerico\n\n");
        }

        dni = atoi(dniAuxStr);

        existe = buscarPorDni(array, arrayLenght, dni);

        if (existe != -1) {
            printf("\nEl DNI %d ya esta dado de alta en el sistema\n\n", dni);
            mostrarPersona(array[existe]);
        }
        else {
            persona.estado = 0;
            persona.dni = dni;

            while (!getStringLetrasNombre("Ingrese el nombre: ", nombreAux)) {
                printf("El nombre debe estar compuesto solo por letras\n\n");
            }
            strcpy(persona.nombre, nombreAux);

            while (!getStringNumeros("Ingrese la edad: ", edadAuxStr)) {
                printf("La edad debe ser numerica\n\n");
            }

            edad = atoi(edadAuxStr);

            while (edad > 100) {
                printf("La edad debe ser menor a 100\n\n");
                while (!getStringNumeros("Ingrese la edad: ", edadAuxStr)) {
                    printf("La edad debe ser numerica\n\n");
                }

                edad = atoi(edadAuxStr);
            }

            persona.edad = edad;
            array[indice] = persona;

            printf("\nALTA REALIZADA!\n\n");
        }
    }
}

/**

 * Borra de la lista, luego de confirmar la baja, a la persona con el DNI ingresado.
 * \param array El array donde se va a buscar la persona con el DNI ingresado.
 * \param arrayLenght La longitud del array donde se va a almacenar.
 */

void borrarPersona(EPersona array[], int arrayLenght){
    int dni;
    int existe;
    char confirmar;

    char dniAuxStr[50];

    system("clear");
    printf("\n - BORRAR - \n\n");

    fpurge(stdin);
    while (!getStringNumeros("Ingrese el DNI de la persona que desea borrar: ", dniAuxStr)) {
        printf("El DNI debe ser numerico\n\n");
    }
    dni = atoi(dniAuxStr);

    existe = buscarPorDni(array, arrayLenght, dni);

    if (existe == -1) {
        printf("\nEl DNI %d ingresado, no se encuentra registrado\n\n", dni);
    } else {
        mostrarPersona(array[existe]);

        do {
            printf("Esta seguro que desea borrar a esta persona de la lista? [s|n]: ");
            fpurge(stdin);
            scanf("%c", &confirmar);
            confirmar = tolower(confirmar);
        } while (confirmar != 's' && confirmar != 'n');

        if (confirmar == 's') {
            array[existe].estado = 1;
            printf("\nPERSONA BORRADA\n\n");
        } else {
            printf("\nNO SE HA BORRADO A LA PERSONA\n\n");
        }
    }
}

/**

 * Ordena alfabeticamente el array ingresado.
 * \param array El array que se ordenara.
 * \param arrayLenght La longitud del array.
 */

void listaOrdenada(EPersona array[], int arrayLenght){
    EPersona arrayAux;
    int i, j;

    system("clear");
    printf("\n - LISTA ORDENADA - \n\n");

    for (i = 0; i < arrayLenght - 1; i++) {
        if (array[i].estado == 1) {
            continue;
        }
        for (j = i + 1; j < arrayLenght; j++) {
            if (array[i].estado == 1) {
                continue;
            }
            if (strcmp(array[i].nombre, array[j].nombre) > 0) {
                arrayAux = array[j];
                array[j] = array[i];
                array[i] = arrayAux;
            }
        }
    }

    for (i = 0; i < arrayLenght; i++) {
        if (array[i].estado == 0) {
            mostrarPersona(array[i]);
        }
    }
}

/**

 * Imprime grafico de barras de 3 grupos de edades, menores de 18, entre 19 a 35 y mayores de 35.
 * \param array El array que se ordenara.
 * \param arrayLenght La longitud del array.
 */

void imprimrGrafico(EPersona array[], int arrayLenght){
    int i, j, mayor = 0, filas;
    int contadores[3];

    system("clear");
    printf("\n - GRAFICO DE EDADES - \n\n");

    for (i = 0; i < 3; i++) {
        contadores[i] = 0;
    }

    for (i = 0; i < arrayLenght; i++) {
        if (array[i].edad < 19 && array[i].estado == 0) {
            contadores[0]++;
        }
        else {
            if (array[i].edad > 18 && array[i].edad < 36 && array[i].estado == 0) {
                contadores[1]++;
            }
            if (array[i].edad > 35 && array[i].estado == 0) {
                contadores[2]++;
            }
        }
    }

    if (contadores[0] >= contadores[1] && contadores[0] >= contadores[2]) {
        mayor = contadores[0];
    }
    else {
        if (contadores[1] >= contadores[0] && contadores[1] >= contadores[2]) {
            mayor = contadores[1];
        }
        if (contadores[2] >= contadores[0] && contadores[2] >= contadores[1]){
            mayor = contadores[2];
        }
    }

    filas = mayor;

    for (i = 0; i < mayor; i++) {
        for (j = 0; j < 3; j++) {
            if (contadores[j] >= filas) {
                printf(" *   ");
            }
            else {
                printf("     ");
            }
        }
        filas--;
        printf("\n");
    }
    printf("<18 19-35 >35\n\n");
}
