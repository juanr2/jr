#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "client.h"
#include <string.h>



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




    int depurar(ArrayList* listaDestinatarios){
int result=0;
int i=0;
  for(i=0; i < al_len(listaDestinatarios) ; i++)
  {
      Eclient* destinatario = al_get(listaDestinatarios, i);

      if(((destinatario->number)%2)==0){


        destinatario->par=1;
      }

      if((destinatario->number)%2!=0){


        destinatario->impar=1;
      }

      if(((destinatario->number)%1==0)&&(((destinatario->number)%(destinatario->number))==0)){


        destinatario->primo=1;
      }


       client_print(destinatario);


      result = 1;
  }
  return result;
}


   int ordenarList(ArrayList* listaDestinatarios,ArrayList* nuevaLista){
int result=0;
int i=0;

  for(i=0; i < al_len(listaDestinatarios) ; i++)
  {
      Eclient* destinatario = al_get(listaDestinatarios, i);


      if(alContainsDestinatario(nuevaLista, destinatario) ) continue;





      Eclient * newDestinatario = client_new();

      newDestinatario->number = destinatario->number;
      strcpy(newDestinatario->name, destinatario->name);
      newDestinatario->par = destinatario->par;
      newDestinatario->impar = destinatario->impar;
      newDestinatario->primo = destinatario->primo;
      al_add(nuevaLista, newDestinatario);

      /// nuevaLista->sort(nuevaLista, comparaNumeros,1);


      result = 1;
  }
  return result;
}



int alContainsDestinatario(ArrayList* al, Eclient* destinatario){
    int result = 0;
    int i = 0;

    for(i=0; i < al_len(al) ; i++)
    {
      Eclient* destinatarioAl = al_get(al, i);

      if(strcmp(destinatarioAl->name, destinatario->name ) == 0){
         result = 1;
         break;
      }
    }

    return result;
}





void listarListaDepurada(ArrayList* listaDepurada){
  int i=0;

  for(i=0; i < al_len(listaDepurada) ; i++)
  {
      Eclient* destinatario = al_get(listaDepurada, i);
      client_print(destinatario);
  }
}


int comparaNumeros(void* pPersonA,void* pPersonB)
{
if(((Eclient*)pPersonA)->number > ((Eclient*)pPersonB)->number)
{
 return 1;
}
if(((Eclient*)pPersonA)->number < ((Eclient*)pPersonB)->number)
{
 return -1;
}
return 0;
}



 int informar(ArrayList* nuevaLista ){
int countCero=0, countPar=0, countImpar=0, countPrimo=0;

int result=0;
int i=0;
  for(i=0; i < al_len(nuevaLista) ; i++)
  {
      Eclient* destinatario = al_get(nuevaLista, i);

      if((destinatario->number)==0){


        countCero++;
      }

      if((destinatario->number)%2==0){


        countPar++;
      }

       if((destinatario->number)%2!=0){


        countImpar++;
      }


      if(((destinatario->number)%1==0)&&(((destinatario->number)%(destinatario->number))==0)){


        countPrimo++;
      }



      result = 1;
  }

  printf("ceros: %d\n pares:%d\n impares:%d\n primos:%d\n",countCero,countPar,countImpar, countPrimo);
  return result;
}
