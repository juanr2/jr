#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"
#include "funcionesutn.h"
#include "parser.h"
#include "client.h"
#include <string.h>



int main()
{

    char seguir='s';
    int opcion, parser, retorno;


    FILE* fDest;
//    FILE*  fBlack;
//    FILE* fDepurado;




    ArrayList* listaDestinatarios = al_newArrayList();
    if (listaDestinatarios == NULL)
    {

        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }

    ArrayList* nuevaLista = al_newArrayList();
    if (nuevaLista == NULL)
    {

        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }




    while(seguir=='s')
    {


        opcion=getInt("-------MENU PRINCIPAL-------\n\n\n1-LEER\n2-COMPLETAR\n3-GENERAR Y LISTAR\n4-INFORMAR\n5-SALIR\n\nELIJA UNA OPCION: ","ERROR:SOLO SE ACEPTAN NUMEROS","Rango valido [1 - 5]",1,5);


        switch(opcion)
        {
        case 1:

//            printf("INGRESE LA RUTA DE ACCESO AL ARCHIVO: ");
//            scanf("%s",auxRuta);


             fDest = fopen("datos.csv", "r");

           /// fDest = fopen("destinatarios.csv ", "r");

            if(fDest == NULL)
            {
                printf("No se pudo abrir el archivo");
                exit(1);
            }

            parser = parserClient(fDest, listaDestinatarios);

            if(parser)
            {
                printf("\nERROR: NO SE PUDO PARSEAR EL ARCHIVO\n\n");
            }
            else
            {
                printf("\nARCHIVO CARGADO EXITOSAMENTE\n\n");
            }

            fclose(fDest);




            system("pause");
            system("cls");
            break;




        case 2:

            retorno = depurar(listaDestinatarios);

            if(retorno==0)
            {

                printf("NO SE PUDO COMPLETAR!!");
            }
            else
            {

                printf("SE PUDO COMPLETAR CON EXITO\n!!");
            }




            system("pause");
            system("cls");
            break;

        case 3:
          retorno = ordenarList(listaDestinatarios,nuevaLista);

            if(retorno==0)
            {

                printf("NO SE PUDO ORDENAR LA LISTA!!");
            }
            else
            {

                printf("SE PUDO ORDENAR LA LISTA CON EXITOS\n!!");
            }

            listarListaDepurada(nuevaLista);
            nuevaLista->sort(nuevaLista, comparaNumeros,1);

            system("pause");
            system("cls");
            break;

        case 4:

            informar(nuevaLista);

//            al_deleteArrayList(listaDestinatarios);
//    al_deleteArrayList(listaNegra);
//    al_deleteArrayList(listaDepurada);
            system("pause");
            system("cls");
            break;
        case 5:
            seguir = 'n';
            break;
        }

    }

    return 0;
}




