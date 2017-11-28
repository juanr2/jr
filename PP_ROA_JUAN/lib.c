

#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include "lib.h"



/** \brief solicita un numero y lo valida teniendo en cuenta un limite inferior y superior
 *
 * \param
 * \param
 * \return retorna un numero entero validado
 *
 */



int getInt(char message[],char errorMensaje[],char eMessage[], int lowLimit, int hiLimit){
   char auxString[256];
    int auxInt;


    while(1){


   if(!funcionValidarNumeros(message,auxString)){


     printf("%s",errorMensaje);
     printf("\n");
     system("pause");
     system("cls");
   continue;


   }




   auxInt=atoi(auxString);

   if(auxInt < lowLimit || auxInt > hiLimit){

     printf("%s",eMessage);
     printf("\n");
     system("pause");
     system("cls");


      continue;



   }



        return auxInt;


     }



}

long int getLongInt(char message[],char errorMensaje[],char eMessage[], int lowLimit, int hiLimit){
   char auxString[256];
    long int auxInt;


    while(1){


   if(!funcionValidarNumeros(message,auxString)){


     printf("%s",errorMensaje);
     printf("\n");
     system("pause");
     system("cls");
   continue;


   }




   auxInt=atol(auxString);

   if(auxInt < lowLimit || auxInt > hiLimit){

     printf("%s",eMessage);
     printf("\n");
     system("pause");
     system("cls");


      continue;



   }



        return auxInt;


     }



}



int funcionValidarNumeros(char mensaje[],char validar[])
{

    int i=0;

    printf("\n%s",mensaje);
    fflush(stdin);
    scanf("%s",validar);

    while(validar[i]!='\0')
    {

        if(validar[i]<'0'||validar[i]>'9')

            return 0;



        i++;

    }
    return 1;

}
/** \brief recibe un array de estructura y busca el primer indice libre
 *
 * \param Array de estructura
 * \param cant representa el tamaño de la variable de la estructura
 * \return i que representa el indice libre o cero si no hay lugar disponible
 *
 */

int obtenerEspacioLibre(eAlquiler alquiler[],int cant ){

int i;


for(i=0;i<cant;i++){

if(alquiler[i].status==0){

    return i;
}


}

return -1;

}

/** \brief recibe un array de estructura y busca el primer indice libre
 *
 * \param Array de estructura
 * \param cant representa el tamaño de la variable de la estructura
 * \return i que representa el indice libre o cero si no hay lugar disponible
 *
 */


int obtenerEspacioLibreClienteAlquiler(eClienteAlquiler clienteAlquiler[],int cant){
int i;


for(i=0;i<cant;i++){

if(clienteAlquiler[i].status==0){

    return i;
}


}

return -1;

}


int obtenerEspacioLibreUno(eCliente cliente[],int cant){
int i;


for(i=0;i<cant;i++){

if(cliente[i].status==0){

    return i;
}


}

return -1;

}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void getString(char message[],char errorMensaje[],char eMessage[],char input[], int lowLimit, int hiLimit){
   char auxString[256];
    int auxInt;


    while(1){


   if(!functionValidString(message,auxString)){


     printf("%s",errorMensaje);
     printf("\n");
     system("pause");
     system("cls");
   continue;


   }




   auxInt=strlen(auxString);

   if(auxInt < lowLimit || auxInt > hiLimit){

     printf("%s",eMessage);
     printf("\n");
     system("pause");
     system("cls");


      continue;



   }



       strcpy(input,auxString);

        break;
     }



}
int functionValidString(char mensaje[],char str[]){


int i=0;


    printf("\n%s",mensaje);
    fflush(stdin);
    scanf("%s",str);

while(str[i]!='\0'){

    if((str[i]<'a'||str[i]>'z')&&(str[i]<'A'||str[i]>'Z')&&(str[i]!='\n')&&(str[i]!=' '))

        return 0;



    i++;

}
return 1;
}


void setCliente(eCliente cliente[],int index,int id ,char name[],char surname[],long int dni){



            cliente[index].idCliente= id ;
            strcpy(cliente[index].name,name);
            strcpy(cliente[index].surname,surname);
            cliente[index].dni=dni;
            cliente[index].status=1;

}

void setAlquiler(eAlquiler alquiler[],int index,int motivo ,int operador,int tiempo){


            alquiler[index].motivo=motivo;
            alquiler[index].operador=operador;
            alquiler[index].tiempoEstimado=tiempo;
            alquiler[index].status=1;


}
/** \brief recibe un array con un indice de la posicion y carga los parametros id cliente y motivo
 *
 * \param index indice a cargar
 * \param auxCodeCliente es el identificador del cliente
  * \param motivo indica la maquina alquilada por el cliente
 * \return no devuelve nada
 *
 */

void setClienteAlquiler(eClienteAlquiler clienteAlquiler[],int index,int auxCodeCliente,int motivo){


            clienteAlquiler[index].motivo=motivo;
            clienteAlquiler[index].idCliente=auxCodeCliente;
            clienteAlquiler[index].status=1;


}



void setStatusCliente(eCliente cliente[],int cant ){

    int i;

for(i=0;i<cant;i++){


        cliente[i].status=0;
    }


}

void setStatusAlquiler(eAlquiler alquiler[],int cant){

int i;


 for(i=0;i<cant;i++){


        alquiler[i].status=0;
    }
}





int flagDetector(int firstFlag){

                 if(firstFlag==0){
                printf("DEBE DAR DE ALTA POR LO MENOS UN PRODUCTO!!!\n");
                system("pause");
                system("cls");

                return 0;
            }
            return 1;
}

/** \brief recibe un array su tamaño y un numero a buscar en el, y completa los campos del array con ceros o '/0'
 *
 * \param array de clientes
 * \param canClientes representa el tamaño del array
  * \param auxCode el numero a buscar

 * \return no retorna nada
 *
 */

void cleanProduct(eCliente cliente[],int cantClientes,int auxCode){

int i;

for(i=0;i<cantClientes;i++){


    if((cliente[i].idCliente==auxCode)&&(cliente[i].status!=0)){


            cliente[i].idCliente=0;
            cliente[i].name[0]='\0';
            cliente[i].surname[0]='\0';
            cliente[i].dni=0;
            cliente[i].status=0;

    }



}
}


int findClienteByCode(eCliente cliente[],int cant,int auxCodeCliente){

int i;

for(i=0;i<cant;i++){

    if((cliente[i].idCliente==auxCodeCliente)&&(cliente[i].status!=0))

        return i;
}
return -1;

}

