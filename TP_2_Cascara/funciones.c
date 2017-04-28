#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

void  Estados (EPersona persona[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        persona[i].estado=0;
    }
}

void ingresarDato(EPersona persona[],int tam)
{
    int i,j;
    int flag=0;
    int flagDig;
    int cant;
    int estados;
    int dni;


    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==0)
        {
            printf("\ningrese nombre: ");
            fflush(stdin);
            gets(persona[i].nombre);


            flagDig = 0;
            cant = strlen(persona[i].nombre);
            for(j=0; j<cant; j++)
            {
                while(isdigit(persona[i].nombre[j]))
                {
                    flagDig = 1;
                    if(flagDig ==1)
                    {
                        printf("\nError.Contiene numeros.\nReingrese nombre: ");
                        fflush(stdin);
                        gets(persona[i].nombre);
                    }
                    cant = strlen(persona[i].nombre);
                }
            }

            strlwr(persona[i].nombre);
            persona[i].nombre[0]=toupper(persona[i].nombre[0]);
            for(j=0; j<strlen(persona[i].nombre); j++)
            {
                if(isspace(persona[i].nombre[j]))
                {
                    persona[i].nombre[j+1]=toupper(persona[i].nombre[j+1]);
                }
            }


            printf("ingrese edad: ");
            scanf("%d",&persona[i].edad);

                while(persona[i].edad<0 || persona[i].edad>105)
                {
                    printf("\nError.Edad no valida.\nReingrese edad: ");
                    scanf("%d",&persona[i].edad);
                }


            printf("ingrese DNI: ");
            scanf("%d\n\n",&dni);

            estados = buscarDNI(persona,tam,dni);
            if(estados != 0)
            {
                printf("\nExiste una persona con ese DNI!!!\n\n");
                system("pause");
            }
            else
            {
                persona[i].dni = dni;
            }
            persona[i].estado=1;
            flag=1;
            break;
        }

    }
    if(flag==0)
    {
        printf("\nNo hay espacio.\n\n");
    }
    return;
}

void borrarUnDato(EPersona persona[],int tam)
{
    int i;
    int auxDni;
    char respuesta;
    int flag=0;

    printf("Ingrese DNI a eliminar: ");
    scanf("%d",&auxDni);

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1 && auxDni==persona[i].dni)
        {
            printf("%d - %s - %d\n", persona[i].dni,persona[i].nombre,persona[i].edad);
            printf("Esta seguro de eliminar? s/n: ");
            respuesta=getche();

            if(respuesta=='s')
            {
                persona[i].estado=0;

            }
            else
            {
                printf("\nAccion cancelada.\n");
            }
             flag=1;
                break;
        }
    }
    if(flag==0)
    {
        printf("\nEl DNI no existe.\n");
    }
}

void ordenPorNombre(EPersona persona[],int tam)
{
    int i;
    int j;
    char auxNom[100];
    int aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(persona[i].estado==1 && persona[j].estado==1)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)>0)
                {
                    strcpy(auxNom,persona[i].nombre);
                    strcpy(persona[i].nombre,persona[j].nombre);
                    strcpy(persona[j].nombre,auxNom);

                    aux=persona[i].dni;
                    persona[i].dni=persona[j].dni;
                    persona[j].dni=aux;

                    aux=persona[i].edad;
                    persona[i].edad=persona[j].edad;
                    persona[j].edad=aux;
                }
                else
                {
                    if(strcmp(persona[i].nombre,persona[j].nombre)==0)
                    {
                        if(persona[i].dni>persona[i].dni)
                        {
                            aux=persona[i].dni;
                            persona[i].dni=persona[j].dni;
                            persona[j].dni=aux;

                            aux=persona[i].edad;
                            persona[i].edad=persona[j].edad;
                            persona[j].edad=aux;

                            aux=persona[i].estado;
                            persona[i].estado=persona[j].estado;
                            persona[j].estado=aux;
                        }
                    }
                }
            }
        }
    }

    printf("NOMBRE\t EDAD\t DNI\n");
    for(i=0; i<tam; i++)
    {
        if(persona[i].estado!=0)
        {
            printf("%s\t %d\t %d\n",persona[i].nombre,persona[i].edad,persona[i].dni);
        }
    }

}

void graficoEdad(EPersona persona[],int tam)
{

    int i,j;
    int contMen =0;
    int cont=0;
    int contMay=0;
    int maximo;
    int dato[3]= {};

    for(i=0; i<tam; i++)
    {
        if(persona[i].estado==1)
        {


            if(persona[i].edad<18)
            {
                contMen++;
            }
            else
            {
                if(persona[i].edad>=19 && persona[i].edad<=35)
                {
                    cont++;
                }
                else
                {
                    if(persona[i].edad>35)
                    {
                        contMay++;
                    }
                }
            }
        }
    }

    dato[0]=contMen;
    dato[1]=cont;
    dato[2]=contMay;

    maximo=0;

    for (i = 0; i < 3; i++)
    {
        if (dato[i] >= maximo)
        {
            maximo =  dato[i];
        }
    }

    for (i = maximo; i > 0; i--)
    {

        for (j = 0; j < 3; j++)
        {
            if (dato[j] >= i)
            {
                printf("\t*");

            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");

    }

    printf("\t<18\t19-35\t>35\n\n");

    return;
}

int buscarDNI(EPersona persona[], int tam, int dni)
{
    int i;
    int estado=0;

    for(i=0; i<tam; i++)
    {
        if(persona[i].dni == dni)
        {
            estado= 1;
            break;
        }
    }
    return estado;
}


