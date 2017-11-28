
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "client.h"


int parserClient(FILE* pFile, ArrayList* pArrayListClient)
{

    char auxInt[10];
    char auxNombre[51];
    char auxPar[51];
    char auxImpar[51];
    char auxPrimo[10];

    Eclient* client;

    if(pFile == NULL || pArrayListClient == NULL)
    {
        return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxPar, auxImpar,auxPrimo);

    // fscanf(pFile, "%[^,],%s\n", auxNombre, auxEmail);

    while(!feof(pFile))
    {
        // fscanf(pFile, "%[^,],%s\n",auxNombre, auxEmail);

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxPar, auxImpar,auxPrimo);

        client = client_new();
        if(client != NULL)
        {
            client->number = atoi(auxInt);
            strcpy(client->name, auxNombre);
            client->par = atoi(auxPar);
            client->impar = atoi(auxImpar);
            client->primo = atoi(auxPrimo);



            //strcpy(client->email, auxEmail);
            // strcpy(client->lastName, auxApellido);
            //  if(strcmp(auxEmpty, "false")== 0){
            //  client->isEmpty = 0;
            // }
            // else{
            //      client->isEmpty = 1;
            //  }

//            if(count==250)
//            {
//                system("pause");
//
//            }
//            count++;

            pArrayListClient->add(pArrayListClient, client);

            // al_add(pArrayListEmployee, nuevoEmpleado);
            client_print(client);

        }

    }

    return 0;
}
