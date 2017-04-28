#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

#define TAMANIO 20

int main()
{
    char seguir='s';
    int opcion=0;

    EPersona pers[TAMANIO];
    Estados(pers,TAMANIO);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            ingresarDato(pers,TAMANIO);
            break;
        case 2:
            borrarUnDato(pers,TAMANIO);
            break;
        case 3:
            ordenPorNombre(pers,TAMANIO);
            break;
        case 4:
            graficoEdad(pers,TAMANIO);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("\nOpcion incorrecta\n");
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}


