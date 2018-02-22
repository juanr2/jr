
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "client.h"
#include "ventas.h"
#include "productos.h"

eVentas* ventas_new(void)
{
    eVentas* returnAux;
    returnAux = (eVentas*)malloc(sizeof(eVentas));
//    if(returnAux !=NULL){
//       returnAux->id = 0;
//       strcpy(returnAux->name, "");
//       strcpy(returnAux->lastName, "");
//       returnAux->isEmpty = 1;
//    }
    return returnAux;
}



void ventas_print(eVentas* this)
{
    if(this != NULL){
        printf(" %d %d %d %d %d \n", this->id_ventas, this->id, this->codeProd,this->cantidad,this->priceProd);
    }
}
