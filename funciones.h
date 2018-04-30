
#ifndef __TP_2_PROGRAMACION_I__funciones__
#define __TP_2_PROGRAMACION_I__funciones__

#include <stdio.h>

typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

/**
 * \brief Inicializa el estado en un array de personas
 * \param personaArray Es el array el cual se inicializara
 * \param arrayLenght Indica la longitud del array
 * \param value Es el valor que se asignara a estado
 * \return -
 *
 */
void inicializarEstado(EPersona personaArray[], int arrayLenght, int value);

/**
 * Obtiene el primer indice libre del array.
 * \param lista El array se pasa como parametro.
 * \param arrayLenght Indica la longitud del array
 * \return Si no hay lugares libres (-1) y si la hay el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int arrayLenght);

int buscarPorDni(EPersona lista[], int arrayLenght, int dni);

void mostrarPersona(EPersona persona);

void altaPersona(EPersona array[], int arrayLenght);

void borrarPersona(EPersona array[], int arrayLenght);
void listaOrdenada(EPersona array[], int arrayLenght);
void imprimrGrafico(EPersona array[], int arrayLenght);

#endif /* defined(__TP_2_PROGRAMACION_I__funciones__) */
