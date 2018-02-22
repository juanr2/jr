#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesutn.h"
#include "arrayList.h"
#include "parser.h"
#include "client.h"
#include "ventas.h"
#include "productos.h"

#define CLIENTES_FILE_NAME "clientes.csv"

int main()
{
    char seguir='s';
    char auxCad[100];
    char eliminar,modificar;
    int opcion, parser,auxDni,id,indice=-1, auxId,i;
    Eclient* auxClient;

    FILE* fCliente = fopen("clientes.csv", "rb+");

    if(fCliente == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    FILE* fVentas = fopen("ventas.csv ", "r");

    if(fVentas== NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    FILE* fproduct = fopen("productos.csv ", "r");

    if(fproduct== NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    ArrayList* listaCliente = al_newArrayList();

    if (listaCliente == NULL)
    {
        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }

    ArrayList* listaVentas = al_newArrayList();

    if (listaVentas == NULL)
    {
        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }

    ArrayList* listaProduct = al_newArrayList();

    if (listaProduct == NULL)
    {
        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }


    parser = parserClient(fCliente, listaCliente);

    if(parser)
    {
        printf("\nERROR: NO SE PUDO PARSEAR EL ARCHIVO\n\n");
    }
    else
    {
        printf("\nARCHIVO CARGADO EXITOSAMENTE\n\n");
    }

    parser = parserVentas(fVentas, listaVentas);

    if(parser)
    {
        printf("\nERROR: NO SE PUDO PARSEAR EL ARCHIVO\n\n");
    }
    else
    {
        printf("\nARCHIVO CARGADO EXITOSAMENTE\n\n");
    }

    parser = parserProduct(fproduct, listaProduct);


    if(parser)
    {
        printf("\nERROR: NO SE PUDO PARSEAR EL ARCHIVO\n\n");
    }
    else
    {
        printf("\nARCHIVO CARGADO EXITOSAMENTE\n\n");
    }


    while(seguir=='s')
    {
        opcion=getInt("-------MENU PRINCIPAL-------\n\n\n1-ALTA CLIENTE\n2-MODIFICACION DE CLIENTE\n3-BAJA DE CLIENTE\n4-LISTAR CLIENTES\n5-REALIZAR UNA VENTA\n6-ANULAR VENTA\n7-INFORMAR VENTAS\n8-INFORMAR VENTAS DE PRODUCTO\n9-GENERAR INFORME DE VENTAS\n\10-INFORMAR CANTIDAD DE VENTAS POR CLIENTE\nELIJA UNA OPCION: ","ERROR:SOLO SE ACEPTAN NUMEROS","Rango valido [1 - 6]",1,6);

        switch(opcion)
        {
        case 1:

            auxClient = client_new();

            if(auxClient != NULL)
            {
                printf("**ALTA CLIENTE**\n\n");
                printf("INGRESE id: ");
                scanf("%d", &id);
                // valido id
                if(client_setId(auxClient, id)==-1){
                    printf("ERROR!!!!ID INVALIDO\n");
                    continue;
                }

                printf("INGRESE NOMBRE: ");
                fflush(stdin);
                gets(auxCad);
                //validar cadena
                strcpy(auxClient->name, auxCad);
                printf("Ingrese Apellido: ");
                fflush(stdin);
                gets(auxCad);
                //validar cadena
                strcpy(auxClient->lastName, auxCad);

                printf("ingrese el dni");
                scanf("%d",&auxDni);

                auxClient->dni = auxDni;

                listaCliente->add(listaCliente, auxClient);

                if(saveClients(CLIENTES_FILE_NAME, listaCliente) == -1){
                   printf("Error al intentar guardar el archivo de clientes\n");
                }
            }


            system("pause");
            system("cls");
            break;
        case 2:

            printf("Ingrese id: ");
            scanf("%d", &auxId);
            for(i=0; i < listaCliente->len(listaCliente); i++)
            {
                auxClient = (Eclient*)listaCliente->get(listaCliente, i);
                if(auxClient->id == auxId)
                {
                    indice = i;
                    break;
                }
            }
            if(indice == -1)
            {
                printf("No existe un cliente con ese id\n\n");
            }
            else
            {
                auxClient = (Eclient*)listaCliente->get(listaCliente, indice);
                client_print(auxClient);

                printf("\nMODIFICAR CLIENTE? s/n: ");
                fflush(stdin);
                scanf("%c", &modificar);

                if(modificar == 's')
                {
                    //client_setId(auxClient, id);

                    printf("INGRESE NOMBRE: ");
                    fflush(stdin);
                    gets(auxCad);
                    //validar cadena
                    strcpy(auxClient->name, auxCad);
                    printf("Ingrese Apellido: ");
                    fflush(stdin);
                    gets(auxCad);
                    //validar cadena
                    strcpy(auxClient->lastName, auxCad);

                    printf("ingrese el dni");
                    scanf("%d",&auxDni);

                    auxClient->dni = auxDni;


                    if(saveClients(CLIENTES_FILE_NAME, listaCliente) == -1){
                         printf("Error al intentar guardar el archivo de clientes\n");
                    }else{
                         printf("\nCLIENTE MODIFICADO\n\n");
                    }

                }
                else
                {
                    printf("\nMODIFICACION CANCELADA\n\n");
                }
            }
            for(i=0; i < listaCliente->len(listaCliente); i++)
            {
                auxClient = (Eclient*)listaCliente->get(listaCliente, i);
                client_print(auxClient);

            }

            system("pause");
            system("cls");
            break;

        case 3:

            printf("Ingrese id: ");
            scanf("%d", &auxId);
            for(i=0; i < listaCliente->len(listaCliente); i++)
            {
                auxClient = (Eclient*)listaCliente->get(listaCliente, i);
                if(auxClient->id == auxId)
                {
                    indice = i;
                    break;
                }
            }
            if(indice == -1)
            {
                printf("No existe un cliente con ese id\n\n");
            }
            else
            {
                auxClient = (Eclient*)listaCliente->get(listaCliente, indice);
                client_print(auxClient);

                printf("\nEliminar cliente? s/n: ");
                fflush(stdin);
                scanf("%c", &eliminar);

                if(eliminar == 's')
                {
                    listaCliente->remove(listaCliente, indice);

                    if(saveClients(CLIENTES_FILE_NAME, listaCliente) == -1){
                         printf("Error al intentar guardar el archivo de clientes\n");
                    }else{
                         printf("\nCliente eliminado\n\n");
                    }
                }
                else
                {
                    printf("\nEliminacion cancelada\n\n");
                }
            }
            for(i=0; i < listaCliente->len(listaCliente); i++)
            {
                auxClient = (Eclient*)listaCliente->get(listaCliente, i);
                client_print(auxClient);

            }

            system("pause");
            system("cls");
            break;

        case 4:

            printf("Lista de empleados\n\n");

            printf("id  Nombre   Apellido dni\n\n");

            for(int i = 0 ; i < listaCliente->len(listaCliente) ; i++)
            {
                auxClient = (Eclient*)listaCliente->get(listaCliente, i);
                client_print(auxClient);
            }



            system("pause");
            system("cls");
            break;

        case 5:





            system("pause");
            system("cls");
            break;
        case 6:
            system("pause");
            system("cls");
            break;

        case 7:

            system("pause");
            system("cls");
            break;

        case 8:

            system("pause");
            system("cls");
            break;

        case 9:





            system("pause");
            system("cls");
            break;
        case 10:


            system("pause");
            system("cls");

            break;
        }

    }

    return 0;
}

