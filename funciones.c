#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(){

int opc = 0;
printf("\n   Seccione una opcion   \n");
printf("1. Registrar produto\n");
printf("2. Ver inventario\n");
printf("3. Producto mas cara y mas barato\n");
printf("4. Buscar Producto\n");
printf(">> ");
opc = validarEnteroConRango(1,4);
return opc;

}


void verInventario(char nombres[10][20], float precio[10], int stock[10], int cont){
    if(cont == 0){
        printf("No hay productos registrados.\n");
        return;
    }

    float totalProducto = 0;
    float totalInventario = 0;
    float precioPromedio = 0;

    printf("#\tNombre\tStock\tPrecio\tTotal\n");

    for (int i = 0; i < cont; i++){
        totalProducto = stock[i] * precio[i];
        totalInventario += totalProducto;
        precioPromedio += precio[i];

        printf("%d\t%s\t%d\t%.2f\t%.2f\n",
               i+1, nombres[i], stock[i], precio[i], totalProducto);
    }

    printf("Total inventario: %.2f\n", totalInventario);

    precioPromedio /= cont;
    printf("Precio promedio: %.2f\n", precioPromedio);
}

void productoCaroBarato(char nombres[10][20], float precio[10], int cont){
    if(cont == 0){
        printf("No hay productos registrados.\n");
        return;
    }

    int mayor = 0;
    int menor = 0;

    for(int i = 1; i < cont; i++){
        if(precio[i] > precio[mayor]){
            mayor = i;
        }
        if(precio[i] < precio[menor]){
            menor = i;
        }
    }

    printf("Producto mas caro: %s - %.2f\n", nombres[mayor], precio[mayor]);
    printf("Producto mas barato: %s - %.2f\n", nombres[menor], precio[menor]);
}

void buscarProducto(char nombres[10][20], float precio[10], int cont){
    if(cont == 0){
        printf("No hay productos registrados.\n");
        return;
    }

    char buscado[20];
    int encontrado = 0;

    printf("Ingrese el nombre del producto a buscar: ");
    leerCadena(buscado,20);

    for(int i = 0; i < cont; i++){
        if(strcmp(nombres[i], buscado) == 0){
            printf("Producto encontrado: %s - Precio: %.2f\n",
                   nombres[i], precio[i]);
            encontrado = 1;
        }
    }

    if(encontrado == 0){
        printf("Producto no encontrado.\n");
    }
}

void leerCadena(char cadena[], int n){
    int len;
    fgets(cadena,n,stdin);
    len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

int validarEnteroConRango(int a, int b){
    int n;
    int aux;
    do{
        aux = scanf("%d",&n);
        while((getchar()) != '\n');
        if(aux != 1 || n < a || n > b){
            printf("El valor ingresado es incorrecto\n>> ");
        }
    }while(aux!=1 || n < a || n > b);
    return n;
}

float validarFloatConRango(int a, int b){
    float n;
    int aux;
    do{
        aux = scanf("%f",&n);
        while((getchar()) != '\n');
        if(aux != 1 || n < a || n > b){
            printf("El valor ingresado es incorrecto\n>> ");
        }
    }while(aux!=1 || n < a || n > b);
    return n;
}