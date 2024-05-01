// =========EJERCICIO 3- TP3=============

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD_NOMBRES 5
#define MAX_LONGITUD_NOMBRE 50

//-----Programa principal------
int main(){


    char **nombres = (char**)malloc(CANTIDAD_NOMBRES * sizeof(char*)); // Doble puntero para manejar un conjunto dinámico de punteros a cadenas de caracteres

    char *buff; // Declaro variable auxiliar

    buff= (char *) malloc(MAX_LONGITUD_NOMBRE*sizeof(char)); // Reserva de memoria dinámica para un buffer de caracteres que contendra los nombres ingresados


    int longitud; // Almacenara la longitud de cada nombre ingresado por el usuario

      // Guardo los nombres en el vector
    for (int i = 0; i < 5; i++)
    {
        printf("Nombre Nro %d: \n", i+1);
        gets(buff); // Almaceno el nombre

        longitud = strlen(buff); // Calculo de longitud del nombre ingresado

         // Realizo una copia del nombre en el vector definido utilizando asignación dinamica de memoria 

        nombres[i] = (char *)malloc(sizeof(char)*(longitud + 1));
        // utilizo la longitud del nombre ingresado sumando un espacio para el caracter nulo

        strcpy(nombres[i], buff); // Copio el nombre desde buff a el vector nombres
    }

    // Muestro los nombres almacenados 
    for (int i = 0; i < 5; i++)
    {
        puts(nombres[i]);
    }
    
    // Libero memoria dinámica para buff
    free(buff);

    // Libero memoria reservada para cada uno de los nombres almacenados en el vector nombres

    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]);
    }
     
     // Libero la memoria del vector nombres en si 
    free(nombres);
    return 0;
}