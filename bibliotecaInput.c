
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "bibliotecaInput.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje es el mensaje a ser mostrado
 * \return El numero ingresado por el usuario
 *
 */

char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fpurge(stdin);
    scanf("%c", &auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 *
 */

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    scanf("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve (acpeta espacios)
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return void
 *
 */

void getStringNombre(char mensaje[], char input[])
{
    fpurge(stdin);
    printf("%s", mensaje);
    scanf("%50[^\n]", input);
}

/**
 * \brief Verifica si el valor recibido es numerico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es numerico, 0 si no lo es
 *
 */

int esNumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] < '0' || str[i] > '9') && (str[i] != '-') && (str[i] != '.'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio y letras, 0 si no lo es
 *
 */

int esSoloLetras(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y numeros, 0 si no lo es
 *
 */

int esAlfanumerico(char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo numeros
 *
 */

int getStringNumeros(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esNumerico(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 */

int getStringLetras(char mensaje[], char input[])
{
    char auxiliar[256];
    getString(mensaje, auxiliar);
    if(esSoloLetras(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve con el primer caracter de cada palabra en mayusculas y lo demas en minusculas
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargara el texto ingresado
 * \return 1 si el texto contiene solo letras
 *
 */

int getStringLetrasNombre(char mensaje[], char input[])
{
    char auxiliar[256];
    int i, auxiliarLenght;
    getStringNombre(mensaje, auxiliar);
    if(esSoloLetras(auxiliar))
    {
        auxiliarLenght = strlen(auxiliar);
        for (i = 0; i < auxiliarLenght; i++) {
            auxiliar[i] = tolower(auxiliar[i]);
        }
        auxiliar[0] = toupper(auxiliar[0]);
        for (i = 0; i < auxiliarLenght; i++) {
            if (auxiliar[i] == ' ') {
                auxiliar[i + 1] = toupper(auxiliar[i + 1]);
            }
        }
        strcpy(input, auxiliar);
        return 1;
    }
    return 0;
}


