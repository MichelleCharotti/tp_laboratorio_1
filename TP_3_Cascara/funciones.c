#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

void Estados(EMovie movie[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        movie[i].estado=0;
    }
}

int buscarID(EMovie movie[], int tam, int id)
{
    int i;
    int estado=-1;

    for(i=0; i<tam; i++)
    {
        if(movie[i].idPelicula == id)
        {
            estado= 1;
            break;
        }
    }
    return estado;
}

void agregarPelicula(EMovie movie[],int tam)
{
    int i;
    int id,estados;
    int validar;
    int flag=0;
    char auxChar[20];

    for(i=0; i<tam; i++)
    {
        if(movie[i].estado==0)
        {
            printf("Ingrese Id de la pelicula: ");
            scanf("%d",&id);

            estados = buscarID(movie,tam,id);

            if(estados != -1)
            {
                printf("\nExiste una persona con ese ID!!!\n\n");
                continue;
            }
            else
            {
                movie[i].idPelicula = id;
            }

            printf("Ingrese titulo de la pelicula: ");
            fflush(stdin);
            gets(movie[i].titulo); //no valide el titulo por que pueden contener letras y numero

            printf("Ingrese genero: ");
            fflush(stdin);
            gets(auxChar);

            validar= validacionChar(auxChar);
            while(validar==1)
            {
                printf("\nERROR.Contiene numeros.\nReingrese: ");
                fflush(stdin);
                gets(auxChar);
                validar= validacionChar(auxChar);
            }

            strcpy(movie[i].genero,auxChar);

            printf("Ingrese duracion en minutos: ");
            scanf("%d",&movie[i].duracion);
            while(movie[i].duracion<0||movie[i].duracion>300)
            {
                printf("ERROR.Numeros equivocados.Reingrese: ");
                scanf("%d",&movie[i].duracion);
            }

            printf("Ingrese descripcion: ");
            fflush(stdin);
            gets(movie[i].descripcion);

            printf("Ingrese puntaje de 1 a 10: ");
            scanf("%d",&movie[i].puntaje);
            while(movie[i].puntaje<0 || movie[i].puntaje>10)
            {
                printf("ERROR.Reingrese puntaje del 1 a 10: ");
                scanf("%d",&movie[i].puntaje);
            }

            printf("Ingrese link de imagen: ");
            fflush(stdin);
            gets(movie[i].linkImagen);


            movie[i].estado=1;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("NO HAY ESPACIO SUFICIENTE.\n\n");
    }
    return;
}


void borrarPelicula(EMovie movie[],int tam)
{
    int i;
    int auxId;
    char respuesta;
    int flag=0;

    printf("Ingrese Id a borrar: ");
    scanf("%d",&auxId);

    for(i=0; i<tam; i++)
    {
        if(movie[i].estado==1 && auxId==movie[i].idPelicula)
        {
            printf("%d - %s - %s - %d\n%s - %d\n\n",movie[i].idPelicula,movie[i].titulo,movie[i].genero,movie[i].duracion,movie[i].descripcion,movie[i].puntaje);
            printf("Esta seguro de eliminarlo s/n: ");
            respuesta=getche();

            if(respuesta=='s')
            {
                movie[i].estado=0;
            }
            else
            {
                printf("\nACCION CANCELADA.\n");

            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nEL ID NO EXISTE.\n");
    }
}

void modificarPelicula(EMovie movie[],int tam)
{
    int flag=0;
    int auxInt;
    int i;
    char respuesta;
    char auxChar[50];

    printf("Ingrese id de la pelicula: ");
    scanf("%d",&auxInt);

    for(i=0; i<tam; i++)
    {
        if(movie[i].estado==1 && auxInt==movie[i].idPelicula)
        {
            printf("%d - %s - %s - %d - %s - %d\n\n",movie[i].idPelicula,movie[i].titulo,movie[i].genero,movie[i].duracion,movie[i].descripcion,movie[i].puntaje);
            printf("Ingrese la nueva descripcion: ");
            fflush(stdin);
            gets(auxChar);
            printf("Ingrese el nuevo puntaje de 1 a 10: ");
            scanf("%d",&auxInt);

            printf("Esta seguro de realizar la modificacion? s/n: ");
            respuesta=getch();

            if(respuesta=='s')
            {
                strcpy(movie[i].descripcion,auxChar);
                movie[i].puntaje=auxInt;
            }
            else
            {
                printf("ACCION CANCELADA.");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("EL ID NO EXISTE.");
    }
}

void listar(EMovie* movie,int tam)
{
    int i;

    printf("ID  TITULO    GENERO  DURACION   PUNTAJE  DESCRIPCION\n");
    for(i=0; i<tam; i++)
    {
        if(movie[i].estado==1)
        {
            printf("%d \t%s \t%s\t%d \t%d \t%s\n",movie[i].idPelicula,movie[i].titulo,movie[i].genero,movie[i].duracion,movie[i].puntaje,movie[i].descripcion);
        }
    }
}


int cargarDesdeArchivo(EMovie* x, int tam)
{
    int flag = 0;
    FILE *f;

    f=fopen("bin.dat", "rb");
    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");
        if(f==NULL)
        {
            return 1;
        }

        flag=1;
    }

    if(flag ==0)
    {
        fread(x,sizeof(EMovie),tam,f);
    }

    fclose(f);
    return 0;
}


void generarPagina(EMovie lista[])
{
    FILE *f;
    FILE *fHtml;

    if((f=fopen("bin.dat","rb"))!=NULL)
    {
        if((fHtml=fopen("Lista de Pelicula.html","wb"))!=NULL)
        {
            fprintf(fHtml,
                    "<!DOCTYPE html>\n"
                    "<html lang='en'>\n"
                     "<head>\n"
            "    <meta charset='utf-8'>\n"
            "    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
            "    <meta name='viewport' content='width=device-width, initial-scale=1'>\n"
            "    <title>Lista peliculas</title>\n"
            "    <link href='css/bootstrap.min.css' rel='stylesheet'>\n"
            "    <link href='css/custom.css' rel='stylesheet'>\n"
            "</head>\n"
                    "<body>\n"
                    "    <div class='container'>\n"
                    "        <div class='row'>\n");
            while((fread(lista,sizeof(EMovie),1,f))!=0)
            {
                if(lista->estado==1)
                {
                    fprintf(fHtml,
                            "<article class='col-md-4 article-intro'>\n"
                            "<a href='#'>\n"
                            "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                            "</a>\n"
                            "<h3>\n"
                            "<a href='#'>%s</a>\n"
                            "</h3>\n"
                            "<ul>\n"
                            "<li>Genero:%s</li>\n"
                            "<li>Puntaje:%d</li>\n"
                            "<li>Duracion:%d minutos</li>\n"
                            "</ul>\n"
                            "<p>%s</p>\n"
                            " </article>\n",lista->linkImagen,lista->titulo,lista->genero,lista->puntaje,lista->duracion,lista->descripcion);
                }
            }

            fprintf(fHtml,
                    "</div>\n"
                    "</div>\n"
                    "<script src='js/jquery-1.11.3.min.js'></script>\n"
            "<script src='js/bootstrap.min.js'></script>\n"
            "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
            "<script src='js/holder.min.js'></script>\n"
                    "</body>\n"
                    "</html>\n");
        }
        else
        {
            printf("\nNO SE PUDO CREAR EL HTML.\n");
            return 0;
        }
    }
    else
    {
        printf("\nNO SE PUDO ABRIR EL ARCHIVO.\n");
        return 0;
    }

    printf("\nPagina web creada con exito.\n\n");
    fclose(f);
    fclose(fHtml);

    return;
}

int guardarEnArchivo(EMovie* x,int tam)
{

    FILE *f;

    f=fopen("bin.dat","wb");
    if(f == NULL)
    {
        return 1;
    }

    fwrite(x,sizeof(EMovie),tam,f);

    fclose(f);

    return 0;
}


int validacionChar(char validacion[])
{
    int j=0;
    while(validacion[j] != '\0')
    {
        if(isdigit(validacion[j]))
        {
            return 1;
        }
        j++;
    }
    return 0;
}
