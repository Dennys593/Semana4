#include <stdio.h>
#include "funciones.h"

int main (int argc, char *argv[]) {

    char nombres[10][20];
    int stock[10];
    float precio[10];

    int opc1 = 0, opc2 = 0, cont = 0;
    
    do
    {
        opc1 = menu();

        switch (opc1)
        {
        case 1:

            if (cont < 10)
            {
                cont = registrarProducto(nombres, precio, stock, cont);
            } else
            {
                printf("El inventario esta lleno");
            }
            
            break;

        case 2:

            verInventario(nombres, precio, stock, cont);
            break;

        case 3:

            productoCaroBarato(nombres, precio, cont);

            break;

        case 4:

            buscarProducto(nombres, precio, cont);
        
            break;

        default:
            break;
        }

        printf("Desea seleccionar otra opcion 1.SI 2. NO\n");
        opc2 = validarEnteroConRango(1,2);

    } while (opc2 == 1);

    return 0;
}
