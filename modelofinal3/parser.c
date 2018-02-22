

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "client.h"
#include "ventas.h"
#include "productos.h"

int parserClient(FILE* pFile , ArrayList* pArrayListClient)
{
    char auxInt[10];
    char auxNombre[51];
     char auxApellido[51];
     char auxDni[10];
   // char auxApellido[51];
   // char auxEmpty[10];

    Eclient* client;

    if(pFile == NULL || pArrayListClient == NULL){
            return -1;
    }

    ///fscanf(pFile, "%[^,],%[^,],%[^,],%s\n", auxInt, auxNombre, auxApellido, auxEmpty);

    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n",auxInt, auxNombre, auxApellido,auxDni);

         //  printf("id  Nombre   Apellido dni\n\n");

    while(!feof(pFile)){

    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n",auxInt, auxNombre, auxApellido,auxDni);

         client = client_new();
         if(client != NULL){
            client->id = atoi(auxInt);
            strcpy(client->name, auxNombre);
             strcpy(client->lastName, auxApellido);
             client->dni = atoi(auxDni);
           // strcpy(client->lastName, auxApellido);
          //  if(strcmp(auxEmpty, "false")== 0){
              //  client->isEmpty = 0;
           // }
           // else{
          //      client->isEmpty = 1;
          //  }

            pArrayListClient->add(pArrayListClient, client);
         //   al_add(pArrayListClient,client);
             client_print(client);

            }

         }

    return 0;
}


int parserVentas(FILE* pFile , ArrayList* pArrayListVentas)
{
    char auxIdVent[10];
    char auxIdClient[10];
    char auxCodeProd[10];
    char auxCant[10];
     char auxPrice[10];
   // char auxApellido[51];
   // char auxEmpty[10];

    eVentas* ventas;

    if(pFile == NULL || pArrayListVentas == NULL){
            return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%s\n", auxIdVent, auxIdClient, auxCodeProd, auxCant,auxPrice);

///    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n",auxInt, auxNombre, auxApellido,auxDni);

         //  printf("id  Nombre   Apellido dni\n\n");

    while(!feof(pFile)){

    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%s\n", auxIdVent, auxIdClient, auxCodeProd, auxCant,auxPrice);

  ///  fscanf(pFile, "%[^,],%[^,],%[^,],%s\n",auxInt, auxNombre, auxApellido,auxDni);

         ///ventas = client_new();
         ventas = ventas_new();
         if(ventas!= NULL){
            ventas->id = atoi(auxIdVent);
             ventas->id= atoi(auxIdClient);
              ventas->codeProd= atoi(auxCodeProd);
               ventas->cantidad = atoi(auxCant);
                ventas->priceProd = atoi(auxPrice);
//            strcpy(client->name, auxNombre);
//             strcpy(client->lastName, auxApellido);
//             client->dni = atoi(auxDni);
           // strcpy(client->lastName, auxApellido);
          //  if(strcmp(auxEmpty, "false")== 0){
              //  client->isEmpty = 0;
           // }
           // else{
          //      client->isEmpty = 1;
          //  }
         }
            pArrayListVentas->add(pArrayListVentas, ventas);
            al_add(pArrayListVentas, ventas);
     ventas_print(ventas);

            }



    return 0;
}


int parserProduct(FILE* pFile , ArrayList* pArrayListProduct)
{

    char auxCodeProd[10];
    char auxnameProd[10];
     char auxPriceProd[10];
   // char auxApellido[51];
   // char auxEmpty[10];

    eProduct* product;

    if(pFile == NULL || pArrayListProduct == NULL){
            return -1;
    }

    fscanf(pFile, "%[^,],%[^,],%s\n", auxCodeProd,auxnameProd,auxPriceProd);

///    fscanf(pFile, "%[^,],%[^,],%[^,],%s\n",auxInt, auxNombre, auxApellido,auxDni);

         //  printf("id  Nombre   Apellido dni\n\n");

    while(!feof(pFile)){

    fscanf(pFile, "%[^,],%[^,],%s\n", auxCodeProd,auxnameProd,auxPriceProd);
  ///  fscanf(pFile, "%[^,],%[^,],%[^,],%s\n",auxInt, auxNombre, auxApellido,auxDni);

         ///ventas = client_new();
         product = product_new();
         if(product!= NULL){

              product->codeProd= atoi(auxCodeProd);
              strcpy(product->nameProd,auxnameProd);
                product->priceProd = atoi(auxPriceProd);
//            strcpy(client->name, auxNombre);
//             strcpy(client->lastName, auxApellido);
//             client->dni = atoi(auxDni);
           // strcpy(client->lastName, auxApellido);
          //  if(strcmp(auxEmpty, "false")== 0){
              //  client->isEmpty = 0;
           // }
           // else{
          //      client->isEmpty = 1;
          //  }
         }
            pArrayListProduct->add(pArrayListProduct, product);
            al_add(pArrayListProduct, product);
     product_print(product);

            }



    return 0;
}

void saveClients(const char *fileName, ArrayList* pArrayListClient){
    FILE* file = fopen(fileName, "w");

    if(file == NULL || pArrayListClient == NULL)
    {
        return -1;
    }

    fprintf(file, "id,name,lastname,dni\n");

    for(int i = 0 ; i < pArrayListClient->len(pArrayListClient) ; i++)
    {
        Eclient* cliente = (Eclient*)pArrayListClient->get(pArrayListClient, i);
        fseek(file,0L,SEEK_CUR);
        fprintf(file, "%d,%s ,%s, %d\n", cliente->id, cliente->name, cliente->lastName, cliente->dni);
    }

    fclose(file);

    return 0;
}


