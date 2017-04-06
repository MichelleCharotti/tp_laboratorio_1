#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion;
    float x;
    float y;
    int flagX=0;
    int flagY=0;


    while(seguir=='s')
    {
            if(opcion==1||flagX==1)
            {
                printf("1- Ingresar 1er operando (A=%.3f)\n",x);
                flagX=1;
            }
            else {
            printf("1- Ingresar 1er operando (A=x)\n");
            }

            if(opcion==2||flagY==1)
            {
                printf("2- Ingresar 2do operando (B=%.3f)\n",y);
            flagY=1;
            }
            else{
            printf("2- Ingresar 2do operando (B=y)\n");
            }




            printf("3- Calcular la suma (A+B)\n");
            printf("4- Calcular la resta (A-B)\n");
            printf("5- Calcular la division (A/B)\n");
            printf("6- Calcular la multiplicacion (A*B)\n");
            printf("7- Calcular el factorial (A!)\n");
            printf("8- Calcular todas las operacione\n");
            printf("9- Salir\n");


        printf("\nLa opcion elegida es: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("Numero A: ");
            scanf("%f",&x);
            break;
        case 2:
            printf("Numero B: ");
            scanf("%f",&y);
            break;
        case 3:
            if(flagX==1&&flagY==1)
            {
             suma(x,y);
            }
            else{
                printf("Error. Falta algun operando para realizar la operacion.\n");
            }
            break;
        case 4:
            if(flagX==1&&flagY==1)
            {
             resta(x,y);
            }
            else{
                printf("Error. Falta algun operando para realizar la operacion.\n");
            }
            break;
        case 5:
            if(flagX==1&&flagY==1)
            {
            division(x,y);
            }
            else{
                printf("Error. Falta algun operando para realizar la operacion.\n");
            }
            break;
        case 6:
            if(flagX==1&&flagY==1)
            {
            multiplicacion(x,y);
            }
            else{
                printf("Error. Falta algun operando para realizar la operacion.\n");
            }
            break;
        case 7:
            if(flagX==1)
            {
            factoreo(x);
            }
            else{
                printf("Error. Falta intgresar el operando para realizar la operacion.\n");
            }
            break;
        case 8:
            if(flagX==1&&flagY==1)
            {
            llamadaFuncion(x,y);
        }
            else{
                printf("Error. Falta algun operando para realizar las operaciones.\n");
            }
            break;
        case 9:
            seguir = 'n';
            break;
        }

        system("pause");
        system("cls");
    }


    return 0;
}
