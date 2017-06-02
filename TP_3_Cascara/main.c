#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

#define TAMANIO 10

int main()
{
    char seguir='s';
    int opcion=0;
    char guardar;

    EMovie pelicula[TAMANIO];
    Estados(pelicula,TAMANIO);


    if(cargarDesdeArchivo(pelicula,TAMANIO))
    {
        printf("NO SE PUDO ABRIR EL FICHERO.");
    }
    else
    {
        printf("Se cargaron las estructuras con exito.\n");
    }

    system("pause");
    system("cls");

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            agregarPelicula(pelicula,TAMANIO);
            break;
        case 2:
            borrarPelicula(pelicula,TAMANIO);
            break;
        case 3:
            modificarPelicula(pelicula,TAMANIO);

            break;
        case 4:
            listar(pelicula,TAMANIO);
            generarPagina(pelicula);
            break;
        case 5:
            printf("\nDesea guardar los cambios? s/n: ");
            guardar = tolower(getche());

            if(guardar == 's')
            {
                if(guardarEnArchivo(pelicula,TAMANIO))
                {
                    printf("\nNO SE PUDO ABRIR EL ARCHIVO.\n");
                }
                else
                {
                    printf("\nSe guardo con exito la informacion.\n");
                }
            }
            seguir = 'n';
            break;
        default:
            printf("\nOPCION INCORRECTA.\n");
            break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
