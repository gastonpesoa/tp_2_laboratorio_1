
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

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista El array se pasa como parametro.
 * \param arrayLenght Indica la longitud del array
 * \param dni El dni a ser buscado en el array.
 * \return Si no hay coincidencia (-1) y si la hay, el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int arrayLenght, int dni);

/**
 * Muestra los datos almacenados en una estructura de persona.
 * \param persona El array que se va a mostrar.
 */
void mostrarPersona(EPersona persona);

/**
 * Da de alta una nueva persona.
 * \param array El array donde se va a almacenar.
 * \param arrayLenght La longitud del array donde se va a almacenar.
 */
void altaPersona(EPersona array[], int arrayLenght);

void borrarPersona(EPersona array[], int arrayLenght);
void listaOrdenada(EPersona array[], int arrayLenght);
void imprimrGrafico(EPersona array[], int arrayLenght);

#endif /* defined(__TP_2_PROGRAMACION_I__funciones__) */
