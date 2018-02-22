
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "client.h"
#include "ventas.h"
#include "productos.h"


eProduct* product_new(void)
{
    eProduct* returnAux;
    returnAux = (eProduct*)malloc(sizeof(eProduct));
//    if(returnAux !=NULL){
//       returnAux->id = 0;
//       strcpy(returnAux->name, "");
//       strcpy(returnAux->lastName, "");
//       returnAux->isEmpty = 1;
//    }
    return returnAux;

}


void product_print(eProduct* this)
{
    if(this != NULL){
        printf(" %d %s %d \n", this->codeProd,this->nameProd,this->priceProd);
    }
}
