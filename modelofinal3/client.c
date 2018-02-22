

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "client.h"
#include "ventas.h"
#include "productos.h"
#include "parser.h"



//void client_close(ArrayList* listaCliente){
//
//FILE* fCliente;
//
//fflush(stdin);
//
//fseek(fCliente, 0L, SEEK_END);
//fwrite(&Eclient, sizeof(Eclient), 1, fCliente);
//
//fclose(fCliente);
//
//
//
//}


int client_compare(void* pClientA,void* pClientB)
{
    if(pClientA != NULL && pClientB != NULL){

    Eclient* empA = (Eclient*) pClientA;
    Eclient* empB = (Eclient*) pClientB;
    return strcmp(empA->name, empB->name);
    }
    return 0;
}

//int client_compareApe(void* pClientA,void* pClientB)
//{
//    if(pClientA != NULL && pClientB != NULL){
//
//    Eclient* empA = (Eclient*) pClientA;
//    Eclient* empB = (Eclient*) pClientB;
//    return strcmp(empA->lastName, empB->lastName);
//    }
//    return 0;
//}


void client_print(Eclient* this)
{
    if(this != NULL){
        printf(" %d %s %s %d \n", this->id, this->name, this->lastName,this->dni);
    }
}


Eclient* client_new(void)
{
    Eclient* returnAux;
    returnAux = (Eclient*)malloc(sizeof(Eclient));
//    if(returnAux !=NULL){
//       returnAux->id = 0;
//       strcpy(returnAux->name, "");
//       strcpy(returnAux->lastName, "");
//       returnAux->isEmpty = 1;
//    }
    return returnAux;

}

//void client_delete(Eclient* this)
//{
//    if(this != NULL){
//        this->isEmpty = 1;
//    }
//
//}

int client_setId(Eclient* this, int id)
{
 if(this != NULL){
       if(id > 0 && id < 100000){
        this->id = id;
        return 0;
       }
    }
    return -1;

}

//int client_getId(Eclient* this)
//{
//    int id = -1;
//     if(this != NULL){
//            id = this->id;
//     }
//    return id;
//
//}


