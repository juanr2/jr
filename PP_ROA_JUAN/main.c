
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include "lib.h"

#define CANTCLIENTE 5
#define CANTALQUILER 3
#define CARDINAL 15


eCliente cliente[CANTCLIENTE];
eAlquiler alquiler[CANTALQUILER];
eClienteAlquiler clienteAlquiler[CARDINAL];



int main()
{

    char seguir='s';
    int opcion,i,j,k,indexFreeClienteAlquiler,auxIdCliente,firstFlag=0,auxCodeCliente,foundIndexCliente,auxMotivo, auxOperador,auxTiempoEstimado,indexFree,auxTiempoReal,indexFirstFree;
    char inputName[50],inputSurname[50];
    long int auxDni;

    setStatusCliente(cliente,CANTCLIENTE );

     setStatusAlquiler(alquiler,CANTALQUILER);


    while(seguir=='s')
    {


        opcion=getInt("-------MENU PRINCIPAL-------\n\n\n1-ALTA CLIENTE\n2-MODIFICAR DATOS DEL CLIENTE\n3-BAJA\n4-NUEVO ALQUILER\n5-FIN DE ALQUILER\n6-INFORMAR\n7-SALIR\n\nELIJA UNA OPCION: ","ERROR:SOLO SE ACEPTAN NUMEROS","Rango valido [1 - 6]",1,6);


        switch(opcion)
        {
        case 1:

                indexFirstFree=obtenerEspacioLibreUno(cliente,CANTCLIENTE);

                       if(indexFirstFree==-1){
               printf("NO HAY LUGAR DISPONIBLE\n");
                break;
            }


               // indexLibre++;


            auxIdCliente=getInt("INGRESE EL ID DEL CLIENTE:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,5);

            getString("INGRESE EL NOMBRE DEL CLIENTE: ","SOLO SE ACEPTAN LETRAS","EXCEDIO LOS 50 CARACTERES",inputName, 1, 50);

            getString("INGRESE EL APELLIDO DEL CLIENTE: ","SOLO SE ACEPTAN LETRAS","EXCEDIO LOS 50 CARACTERES",inputSurname, 1, 50);


           auxDni=getLongInt("INGRESE EL DNI:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,40000000);


              setCliente(cliente,indexFirstFree,auxIdCliente,inputName,inputSurname,auxDni);



            firstFlag=1;

            system("pause");
            system("cls");

            break;


        case 2:
            if(!flagDetector(firstFlag))
            {
                break;
            }

            auxCodeCliente=getInt("INGRESE EL ID DEL CLIENTE A MODIFICAR:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,5);

            foundIndexCliente=findClienteByCode(cliente,CANTCLIENTE,auxCodeCliente);

            if(foundIndexCliente==-1)
            {

                printf("CODIGO DE CLIENTE INEXISTENTE");
            }

            getString("INGRESE EL NOMBRE DEL CLIENTE: ","SOLO SE ACEPTAN LETRAS","EXCEDIO LOS 50 CARACTERES",inputName, 1, 50);

            getString("INGRESE EL APELLIDO DEL CLIENTE: ","SOLO SE ACEPTAN LETRAS","EXCEDIO LOS 50 CARACTERES",inputSurname, 1, 50);


           auxDni=getLongInt("INGRESE EL DNI:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,40000000);


              setCliente(cliente,foundIndexCliente,auxIdCliente,inputName,inputSurname,auxDni);

            system("pause");
            system("cls");
            break;
        case 3:

            if(!flagDetector(firstFlag))
            {
                break;
            }


            auxCodeCliente=getInt("INGRESE EL NUMERO ID DEL CLIENTE QUE DESEA BORRAR:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,5);

            cleanProduct(cliente,CANTCLIENTE,auxCodeCliente);


            system("pause");
            system("cls");
            break;
        case 4:


            indexFree=obtenerEspacioLibre(alquiler,CANTALQUILER);

                       if(indexFree==-1){
               printf("NO HAY LUGAR DISPONIBLE\n");
                break;
            }

             auxCodeCliente=getInt("INGRESE EL ID DEL CLIENTE :  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 100",1,100);

            foundIndexCliente=findClienteByCode(cliente,CANTCLIENTE,auxCodeCliente);

            if(foundIndexCliente==-1)
            {

                printf("CODIGO DE CLIENTE INEXISTENTE");
            }


            clienteAlquiler[indexFree].idCliente=auxCodeCliente;




            auxMotivo=getInt("MOTIVO:\n1-AMOLADORA\n2-MEZCLADORA\n3-TALADRO\nSELECCIONE UN MOTIVO:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 3",1,3);

             auxOperador=getInt("OPERADOR:\n1-JUAN\n2-MARIA\nSELECCIONE EL OPERADOR:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 2",1,2);

            auxTiempoEstimado=getInt("INGRESE EL TIEMPO ESTIMADO:  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,5);


            setAlquiler(alquiler,indexFree,auxMotivo ,auxOperador,auxTiempoEstimado);

            indexFreeClienteAlquiler=obtenerEspacioLibreClienteAlquiler(clienteAlquiler,CARDINAL);

                       if(indexFreeClienteAlquiler==-1){
               printf("NO HAY LUGAR DISPONIBLE\n");
                break;
            }
            setClienteAlquiler(clienteAlquiler,indexFreeClienteAlquiler,auxCodeCliente,auxMotivo);




            system("pause");
            system("cls");
            break;

        case 5:


                auxCodeCliente=getInt("INGRESE EL ID DEL CLIENTE :  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,5);

                auxTiempoReal=getInt("INGRESE EL TIEMPO REAL DE ALQUILER :  ","ERROR USTED NO INGRESO UN NUMERO","EL RANGO VALIDO ES DEL 1 AL 5",1,1000);
                for(i=0;i<CANTCLIENTE;i++){

                    for(j=0;j<CARDINAL;j++){

                        if((cliente[i].idCliente==auxCodeCliente)&&(clienteAlquiler[j].status==1)){

                            for(k=0;k<CANTALQUILER;k++){

                                if((clienteAlquiler[j].motivo==alquiler[k].motivo)&&(alquiler[k].status==1))

                                    clienteAlquiler[j].status=0;
                                    alquiler[k].tiempoReal=auxTiempoReal;


                            }
                        }


                    }
                }






            system("pause");
            system("cls");
            break;
        case 6:

             if(!flagDetector(firstFlag))
            {
                break;
            }


             printf("listar\n");
            int  ClienteConMasIndex = 0;
            int count = 0;

              for(i=0;i<CANTCLIENTE;i++){
                for(j=0;j<CARDINAL;j++){
                           if((cliente[i].idCliente==clienteAlquiler[j].idCliente)&&(clienteAlquiler[j].status==1)){
                                cliente[i].cantidadAlquileres++;
                            }

                }

                if(cliente[i].cantidadAlquileres > count){
                    ClienteConMasIndex = i;
                    count = cliente[i].cantidadAlquileres;
                }
              }


               printf("El CLIENTE CON MAS ALQUILERES ES : %d\t%s Y TIENE %d ALQUILERES asociados.\n",cliente[ClienteConMasIndex].idCliente,cliente[ClienteConMasIndex].name, count);





                    printf("\n");


            system("pause");
            system("cls");
            break;
        case 7:
            seguir = 'n';
            break;
        }




}
return 0;
}
