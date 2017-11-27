#include <stdio.h>
#include <stdlib.h>
#include "arrayList.h"
#include "client.h"
#include "string.h"



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




    int depurar(ArrayList* listaDestinatarios, ArrayList* listaNegra,ArrayList* listaDepurada){
int result=0;
int i=0;
  for(i=0; i < al_len(listaDestinatarios) ; i++)
  {
      Eclient* destinatario = al_get(listaDestinatarios, i);

      if(alContainsDestinatario(listaDepurada, destinatario) ||
         alContainsDestinatario(listaNegra, destinatario)) continue;

      Eclient * newDestinatario = client_new();

      strcpy(newDestinatario->name, destinatario->name);
      strcpy(newDestinatario->email, destinatario->email);
      al_add(listaDepurada, newDestinatario);
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

      if(strcmp(destinatarioAl->email, destinatario->email ) == 0){
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
