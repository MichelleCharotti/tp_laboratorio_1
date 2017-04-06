#include <stdio.h>

float suma(float a,float b)
{
    float suma1;
    suma1= a+b;
    printf("La suma es: %.3f\n",suma1);
    return suma1;
}

float resta(float a,float b)
{
    float resta1;
    resta1=a-b;
    printf("La resta es: %.3f\n",resta1);
    return resta1;
}

float division(float a,float b)
{
    float div;
    if(b==0)
    {
        printf("Error.No se puede dividir por cero.");
    }
    else
    {
        div=a/b;
        printf("La division es: %.3f\n",div);
    }
    return div;
}

float multiplicacion(float a, float b)
{
    float mult;
    mult=a*b;
    printf("La multiplicacion es: %.3f\n",mult);
    return mult;
}

long int  factoreo(long int a)
{
    int i;
    long int fact =1;

    if(a>=0)
    {
        for(i=a; i>0; i--)
        {
            fact=fact*i;
            printf("%d\n",i);
        }
        printf("El factoreo es: %ld\n",fact);
    }
    else
    {
        printf("El numero tiene que ser positivo y entero para factoriar.\n");
    }
    return fact;
}
float llamadaFuncion(float a,float b)
{
    suma(a,b);
    resta(a,b);
    division(a,b);
    multiplicacion(a,b);
    factoreo(a);

    return 0;
}

