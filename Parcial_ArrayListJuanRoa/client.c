
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"
#include "client.h"

//
//int client_compare(void* pClientA,void* pClientB)
//{
//    if(pClientA != NULL && pClientB != NULL){
//
//    Eclient* empA = (Eclient*) pClientA;
//    Eclient* empB = (Eclient*) pClientB;
//    return strcmp(empA->name, empB->name);
//    }
//    return 0;
//}


// void client_compare(void* pClientA,void* pClientB)
//{
//    int cont=0,i=0,j=0;
//    if(pClientA != NULL && pClientB != NULL){
//
//
//    Eclient* empA = (Eclient*) pClientA;
//    Eclient* empB = (Eclient*) pClientB;
//
//    printf("%p",empA);
//
// for(i=0; i <al_len(pClientA); i++){
//                  for(j=0;j<al_len(pClientB);j++){
//
//
//                     if(strcmp(empA->name[i], empB->name[j])==0){
//
//        cont++;
//     }




//
//        }
//
//     printf("%d",cont);
//    }
//
//}
//


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
        printf(" %s %s \n", this->name, this->email);
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
//
//int client_setId(Eclient* this, int id)
//{
// if(this != NULL){
//       if(id > 0 && id < 100000){
//        this->id = id;
//        return 0;
//       }
//    }
//    return -1;
//
//}

//int client_getId(Eclient* this)
//{
//    int id = -1;
//     if(this != NULL){
//            id = this->id;
//     }
//    return id;
//
//}


