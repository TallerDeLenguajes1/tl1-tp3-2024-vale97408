// =========EJERCICIO 4- TP3=============
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo puede pedir hasta 10 productos

char *tiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct Producto
{
    int ProductoID; //Numerado en ciclo iterativo
    int cantidad;// entre 1 y 10
    char *TiposProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100

}typedef Producto;

struct Cliente
{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Numerado en el ciclo iterativo
    int CantidadProductosAPedir;  // (aleatorio entre 1 y 5)

    Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Cliente;


// ------PROTOTIPO DE FUNCIONES-------
//-----------FUNCION 1
int numAleatorios(int min, int max);

//-----------FUNCION 2
void cargarClientes(Cliente *clientes, int cantidad);

//-----------FUNCION 3
void cargarProducto(Producto *productos, int cantidad);

//-----------FUNCION 4
void mostrarClientes(Cliente *clientes, int cantidad);

//-----------FUNCION 5
void mostrarProducto(Producto *productos, int cantidad);

//-----------FUNCION 6
float costoProducto(Producto producto);

//-----------FUNCION 7
float pagoCliente(Producto *productos, int cantidad);


// --------PROGRAMA PRINCIPAL----------
int main() 
{
    srand(time(NULL)); // Semilla para la creación de numeros aleatorios

    int cantClientes, numCliente, numProducto;
    float costoProdu;

    Cliente *clientes; // declaro puntero del tipo de la variable cliente

    // Controlo que no se puedan cargar mas de 5 clientes para la visita del preventista 

    do{
        printf("\n Cantidad de clientes:  \n");
        scanf("%d", &cantClientes);

        if (cantClientes<0 && cantClientes>5)
        {
            printf("\n Cantidad ingresada incorrecta");
        }
        
    }while(cantClientes<0 && cantClientes>5);


    // Realizo reserva dinámica de memoria para la carga de los clientes en un arreglo del tamaño de la cantidad ingresada

    clientes = (Cliente *)malloc(cantClientes*sizeof(Cliente));

    cargarClientes(clientes, cantClientes); // Cargo datos de los clientes en el arreglo 

    mostrarClientes(clientes, cantClientes); // Muestro la informacion 

  printf("\n-----------------Costo de un producto-------------------- \n");  

    printf("\nNúmero de cliente: ");
    scanf("%d", &numCliente);

    
    printf("\nIngrese el número de producto:  ");
    scanf("%d", &numProducto);

    // Calculo el costo del producto 
    costoProdu = costoProducto(clientes[numCliente-1].Productos[numProducto-1]); // Tengo en cuenta que los arreglos inicializan en 0

    printf("\n------El costo del producto es: %.2f", costoProdu);

    // Libero memoria dinámica de los datos de los clientes y sus productos 
    for(int i = 0;i<cantClientes;i++)
    {
         // Libero memoria dinámica de los datos de sus productos 
        for(int j = 0;j<((clientes+i)->CantidadProductosAPedir);j++)
        {
            free(((clientes+i)->Productos+j)->TiposProducto);
        }

        free((clientes+i)->Productos);
        free((clientes+i)->NombreCliente);
    }

    free(clientes);
    return 0;
}


// -------- DESARROLLO DE FUNCIONES ----------


//-----------FUNCION 1
int numAleatorios(int min, int max)
{
    int num;
    num = min + rand()%(max-min+1);
    return num;
}

//-----------FUNCION 2


 // Carga los datos en un arreglo de estructuras clientes

void cargarClientes(Cliente *clientes, int cantidad)
{
    // Reserva de memoria en la variable auxiliar para almacenar el nombre del cliente

    char *buff = (char *)malloc(sizeof(char)*100);


    for(int i = 0;i<cantidad;i++)
    {
        (clientes +i)->ClienteID = i; // Id basado en el indice 

        printf("\nIngrese el nombre del cliente %d: ", i + 1);
        fflush(stdin);
        gets(buff);

        // Reserva de memoria para el nombre de cada cliente con la longitud del nombre

        (clientes + i)->NombreCliente = (char *)malloc((strlen(buff)+1)*sizeof(char));
       
       // Copia el nombre del buff en NombreCliente
        strcpy((clientes + i)->NombreCliente, buff);
 
        // Numero aleatorio de la cant de productos que pedira cada cliente
        (clientes + i)->CantidadProductosAPedir = numAleatorios(1,5);  

        int cantProductos = (clientes + i)->CantidadProductosAPedir; // Guardo el nro aleatorio generado 
 
        //Reserva de memoria dinamica para el arreglo productos 
        (clientes + i)->Productos = (Producto *)malloc(cantProductos*sizeof(Producto));

        // carga los productos relacionados al cliente
        cargarProducto((clientes + i)->Productos, cantProductos);
    }

    // Libero memoria de la variable auxiliar
    free(buff);
}


//-----------FUNCION 3
void cargarProducto(Producto *productos, int cantidad)
{
    char *punteroTipo;

    for(int i = 0;i<cantidad;i++) // Segun la cantidad de productos 
    {
        (productos + i)->ProductoID = i; // ID del producto segun el indice 

        (productos + i)->cantidad = numAleatorios(1,10);

        (productos + i)->PrecioUnitario = numAleatorios(1000,10000)*0.01; // Precio entre 10 y 100 , flotante

        punteroTipo = tiposProductos[numAleatorios(0,4)]; // Selecciona un tipo de producto 

        // Reserva de memoria
        (productos + i)->TiposProducto = (char *)malloc(sizeof(char)*(strlen(punteroTipo)+1));
        
        // Copio el tipo de producto 
        strcpy((productos + i)->TiposProducto, punteroTipo);
    }
}


//-----------FUNCION 4
void mostrarClientes(Cliente *clientes, int cantidad)
{


    for(int i = 0;i<cantidad;i++) // Itera sobre cada cliente en el arreglo clientes 
    {

        printf("\n--------Cliente Nro %d--------\n", i+1);

        printf("\nId del cliente: %d", (clientes + i)->ClienteID);

        printf("\nNombre del cliente: %s", (clientes + i)->NombreCliente);

        printf("\nCantidad de productos a pedir : %d", (clientes + i)->CantidadProductosAPedir);  

        mostrarProducto((clientes + i)->Productos, (clientes + i)->CantidadProductosAPedir); 

        printf("\nTotal a pagar por el cliente es: %.2f", pagoCliente((clientes + i)->Productos, (clientes + i)->CantidadProductosAPedir));
    }
}

//-----------FUNCION 5- ADICIONAL
void mostrarProducto(Producto *productos, int cantidad) // Info de cada producto 
{
    for(int i = 0;i<cantidad;i++) // Itera sobre cada producto en el arreglo productos
    {
        printf("\n\n--------Producto Nro  %d--------\n", i+1);

        printf("\nId del producto: %d", (productos + i)->ProductoID);

        printf("\nCantidad: %d", (productos + i)->cantidad);  

        printf("\nTipo de producto: %s", (productos + i)->TiposProducto);

        printf("\nPrecio unitario: %.2f", (productos + i)->PrecioUnitario);
    }
}
//-----------FUNCION 6- ADICIONAL
float costoProducto(Producto producto)
{
    return (producto.cantidad*producto.PrecioUnitario); // Cantidad por precio unitario
}


//-----------FUNCION 7- ADICIONAL
float pagoCliente(Producto *productos, int cantidad) 
{
    float total = 0;
    //Calcula el pago total de un cliente sumando los costos de todos sus productos

    for(int i = 0;i<cantidad;i++)
    {
        total = total + costoProducto(*(productos + i)); // Obteiene el costo de cada producto y luego lo suma para obtener el total
        
    }

    return total;
}