// =========EJERCICIO 2- TP3=============

#include<stdio.h>
#include<stdlib.h>// Libreria para la creación de números aleatorios
#include<time.h>// Libreria para la creación de números aleatorios

#define N 5
#define M 12

#define LIM_SUP 50000
#define LIM_INF 10000

// Declaracion de funciones

void cargarMatriz( int matriz[N][M]); // Punto A
void mostrarMatriz(int matriz[N][M]) ; // Punto B
void promedioGananciaPorAnio(int matriz[N][M]); // Punto C
void valorMaximoyMinimo(int matriz[N][M]); // Punto D


// ------Programa principal-----

int main()
{ 
 int matriz[N][M]; // Matriz 5x12
 
 // Numeros aleatorios

 srand(time(NULL)); // Semilla para la creacion de numeros aleatorios no repetidos

 // A- Cargado de numeros aleatorios a la matriz
 printf("\n-----------Cargando matriz...---------- \n");
 cargarMatriz(matriz);

//-------------------------


 //B- Muestro  numeros aleatorios a la matriz
  printf("\n Mostrando matriz de num aleatorios....\n");
 mostrarMatriz(matriz);


 // C- Saco el prmedio de ganancia por año y lo muestro
  printf("\n -------Promedio de ganancia por anio-------- \n");

 promedioGananciaPorAnio(matriz);

  // D- Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
  
  valorMaximoyMinimo(matriz);

   return 0;
}



//=====Desarrollo de funciones======

//-----------Punto A ----------------
void cargarMatriz(int matriz[N][M])
{

for(int i = 0;i<N; i++)
 {
    for(int j = 0;j<M; j++)
   {
      matriz[i][j]=rand() % (LIM_SUP - LIM_INF + 1) + LIM_INF;  // Numeros aleatorios entre 10000 a 50000
    }
  printf("\n");
 }

  printf("---Matriz Cargada----\n");

}
//------------------------------

//-----------Punto B ----------------
void mostrarMatriz(int matriz[N][M])
{

for(int i = 0;i<N; i++)
 {
    for(int j = 0;j<M; j++)
   {
      printf("%3d ",  matriz[i][j]);
    }
  printf("\n");
 }

}
//------------------------------

//-----------Punto C ----------------
void promedioGananciaPorAnio(int matriz[N][M])
{

int  suma=0;
 float promedio; 
  printf("-------- El promedio obtenido por anio es:----------\n");
  
 for(int i = 0;i<N; i++)
 {
    for(int j = 0;j<M; j++)
   {
     suma= suma+ matriz[i][j];
      
    }
  
   promedio= suma/ M; 
  printf("\n");
    printf("-------- Anio (%d): %.2f----------\n",i+1, promedio);
  
 }

}
//------------------------------

//-----------Punto D ----------------
void valorMaximoyMinimo(int matriz[N][M])
{


   printf("\n -------Obteniendo valor de maximo y minimo  (con anio y mes)------\n");
 
     int max = matriz[0][0];
    int min = matriz[0][0];
    int maxAnio = 0, maxMes = 0;
    int minAnio = 0, minMes = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
                maxAnio = i + 1;
                maxMes = j + 1;
            }
            if (matriz[i][j] < min) {
                min = matriz[i][j];
                minAnio = i + 1;
                minMes = j + 1;
            }
        }
    }

    printf("\nValor MAXIMO: %d (Anio: %d, Mes: %d)\n", max, maxAnio, maxMes);
    printf("Valor MINIMO: %d (Anio: %d, Mes: %d)\n", min, minAnio, minMes);



}
//------------------------------