
#ifndef __TP_2_PROGRAMACION_I__bibliotecaInput__
#define __TP_2_PROGRAMACION_I__bibliotecaInput__

float getFloat(char mensaje[]);
int getInt(char mensaje[]);
char getChar(char mensaje[]);
void getString(char mensaje[], char input[]);
void getStringNombre(char mensaje[], char input[]);

int esNumerico(char str[]);
int esSoloLetras(char str[]);
int esAlfanumerico(char str[]);

int getStringNumeros(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);
int getStringLetrasNombre(char mensaje[], char input[]);

#endif /* defined(__TP_2_PROGRAMACION_I__bibliotecaInput__) */

