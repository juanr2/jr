#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"
#include "funcionesutn.h"
#include "parser.h"
#include "client.h"
#include <string.h>

int depurar(ArrayList* listaDestinatarios,ArrayList* listaNegra,ArrayList* listaDepurada);

void listarListaDepurada(ArrayList* listaDepurada);


int main()
{

    char seguir='s';
    int opcion, parser, retorno,i;
    char auxRuta[30];

    FILE* fDest;
    FILE*  fBlack;
    FILE* fDepurado;



//    char auxRuta[30],ruta[30];
//    char comillas [30]=  " ;


    ArrayList* listaDestinatarios = al_newArrayList();
    if (listaDestinatarios == NULL)
    {

        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }
    ArrayList* listaNegra = al_newArrayList();
    if (listaNegra == NULL)
    {

        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }
    ArrayList* listaDepurada = al_newArrayList();
    if (listaNegra == NULL)
    {

        printf("NO SE PUEDE CARGAR LA LISTA!!");
        exit(1);
    }




    while(seguir=='s')
    {


        opcion=getInt("-------MENU PRINCIPAL-------\n\n\n1-CARGAR DESTINATARIOS\n2-CARGAR LISTA NEGRA\n3-DEPURAR\n4-LISTAR\n5-LISTAR\n6-SALIR\n\nELIJA UNA OPCION: ","ERROR:SOLO SE ACEPTAN NUMEROS","Rango valido [1 - 6]",1,6);


        switch(opcion)
        {
        case 1:

            printf("INGRESE LA RUTA DE ACCESO AL ARCHIVO: ");
            scanf("%s",auxRuta);

//            strcpy(str," );
//            strcpy(str,rutaUno);
//            strcat(str,comillas)
//            strcpy(ruta,"\"auxRuta");
//
//            printf("%s",ruta);
             fDest = fopen(auxRuta, "r");

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


            fBlack = fopen("black_list.csv ", "r");

            if(fDest == NULL)
            {
                printf("No se pudo abrir el archivo");
                exit(1);
            }

            parser = parserClient(fBlack, listaNegra);

            if(parser)
            {
                printf("\nERROR: NO SE PUDO PARSEAR EL ARCHIVO\n\n");
            }
            else
            {
                printf("\nARCHIVO CARGADO EXITOSAMENTE\n\n");
            }

            fclose(fBlack);

            system("pause");
            system("cls");
            break;

        case 3:

            retorno = depurar(listaDestinatarios,listaNegra,listaDepurada);

            if(retorno==0)
            {

                printf("NO SE PUDO CREAR EL ARCHIVO DEPURADO!!");
            }
            else
            {

                printf("SE CREO CON EXITO EL ARCHIVO DEPURADO!!");
            }




            system("pause");
            system("cls");
            break;

        case 4:

            listarListaDepurada(listaDepurada);

            system("pause");
            system("cls");
            break;

        case 5:

            if((fDepurado=fopen("listaDepurada.csv","w"))==NULL){



                printf("EL ARCHIVO NO PUEDE SER ABIERTO!!");
                exit(1);
            }

            for(i = 0; i < al_len(listaDepurada); i++){
                Eclient* cli = al_get(listaDepurada, i);
                fflush(stdin);

                fprintf(fDepurado,"%s %s\n", cli->name,cli->email);
//                strcpy( row, cli->name );
//                strcat( row, cli->email);
//                fwrite(row,sizeof(row),1,fDepurado);
            }


            fclose(fDepurado);
            system("pause");
            system("cls");
            break;
        case 6:
            seguir = 'n';
            break;
        }

    }

    return 0;
}




