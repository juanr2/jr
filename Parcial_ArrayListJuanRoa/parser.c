
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "client.h"


int parserClient(FILE* pFile , ArrayList* pArrayListClient)
{
    //char auxInt[10];
    char auxNombre[51];
     char auxEmail[51];
   // char auxApellido[51];
   // char auxEmpty[10];

    Eclient* client;

    if(pFile == NULL || pArrayListClient == NULL){
            return -1;
    }

    ///fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

    fscanf(pFile, "%[^,],%s\n", auxNombre, auxEmail);

    while(!feof(pFile)){
         fscanf(pFile, "%[^,],%s\n",auxNombre, auxEmail);

         client = client_new();
         if(client != NULL){
           // client->id = atoi(auxInt);
            strcpy(client->name, auxNombre);
             strcpy(client->email, auxEmail);
           // strcpy(client->lastName, auxApellido);
          //  if(strcmp(auxEmpty, "false")== 0){
              //  client->isEmpty = 0;
           // }
           // else{
          //      client->isEmpty = 1;
          //  }

            pArrayListClient->add(pArrayListClient, client);
           // al_add(pArrayListEmployee, nuevoEmpleado);
             client_print(client);

            }

         }

    return 0;
}
