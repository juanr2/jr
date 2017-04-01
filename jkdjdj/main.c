#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main()
{
    int numero;
    int fact;

    printf ("ingrese un numero");
    scanf("%d",&numero);
    fact=factorial(numero);
    printf("%d",fact);
    return 0;
}

int factorial(int num)
{
    int i;
    int factorial=1;

for(i=num;i>1;i--)
    {
        factorial=factorial*i;
    }
    return factorial;
}
