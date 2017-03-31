
    #include <stdio.h>
    #include <stdlib.h>
/*
    int main()
    {
       int num;
       int contpares=0;
       int contimpares=0;
       char rta;
       int cont=0;
       int sumaimpares=0;
       int suma=0;
       float promedio;
       int contotal=0;
       int flagMax=0;
       int numMax;
       int cont3a15=0;
       int cont16a29=0;
       int cont30=0;
       int i=0;
       int sumainversa=0;


            while (rta!='s')
            {

            printf("ingrese numeros positivos: ");
            scanf("%d",&num);

            printf("desea continuar");
            rta=getche();

            contotal++;
            suma+=num;
            promedio=suma/contotal;


            while (num<=0)
            {  printf("ingrese un numero vàlido. ");
                scanf("%d",&num);
                cont++;
            }


            if(num%2==0)
            {
                contpares++;

            }

            if (num%2!=0)
            {
                contimpares++;
                sumaimpares+=num;

            }

            for(i=suma;i>0;i--)
            {

                sumainversa+=i;
            }

            if (flagMax==   0)
            {
                numMax=num;
                flagMax=1;
            }
            else
            {
                if(num>numMax)
                {
                    numMax=num;
                }
            }

            if (num>=3 && num<=15)

            {

                cont3a15++;
            }

            if (num>=16 && num<=29)

            {

                cont16a29++;
            }

            if (num>30)

            {
                cont30++;
            }






            }

            printf("\ncontador pares: %d \ncontador impares: %d  \nsuma: %d  \nsuma impares es: %d  \npromedio de todos los numeros es: %f  \n numero maximo es: %d  \n la cantidad de numeros entre 3 y 15 son: %d \n la cantidad de numeros que hay entre 16 y 29 son: %d \n la cantidad de numeros que son mayores a 30 son: %d  \suma inversa es %d"  ,contpares, contimpares,suma, sumaimpares, promedio,numMax,cont3a15,cont16a29,cont30,sumainversa);
             return 0;


    }*/

/**
    int pedirNumero();

    int main(){
    int numero;
    printf ("ingrese un numero");
    scanf("%d",&numero);
    return numero;
    }

    */

    /*HACER UNA FUNCIÓN QUE CALCULE EL PRODUCTO DE DOS NUMEROS*/

    int determinarProducto(int n1, int n2);

    int main()
        {
            int primerNumero;
            int segundoNumero;
            int mult;

            printf("ingrese el primer numero");
            scanf("%d",&primerNumero);
            printf("ingrese el segundo numero");
            scanf("%d",&segundoNumero);

            mult=primerNumero*segundoNumero;
            printf("el producto es %d",mult);
        }
    int determinarProducto (int n1,int n2)
        {
            int producto;
            producto=n1*n2;
            return producto;
        }




