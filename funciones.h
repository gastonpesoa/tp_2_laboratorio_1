
#ifndef __TP_2_PROGRAMACION_I__funciones__
#define __TP_2_PROGRAMACION_I__funciones__

#include <stdio.h>

typedef struct {



    char nombre[50];

    int edad;

    int estado;

    int dni;



}EPersona;


void inicializarEstado(EPersona personaArray[], int arrayLenght, int value);

int obtenerEspacioLibre(EPersona lista[], int arrayLenght);

int buscarPorDni(EPersona lista[], int arrayLenght, int dni);

void mostrarPersona(EPersona persona);

void altaPersona(EPersona array[], int arrayLenght);

void borrarPersona(EPersona array[], int arrayLenght);
void listaOrdenada(EPersona array[], int arrayLenght);
void imprimrGrafico(EPersona array[], int arrayLenght);

#endif /* defined(__TP_2_PROGRAMACION_I__funciones__) */
