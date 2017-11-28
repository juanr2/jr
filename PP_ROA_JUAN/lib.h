
typedef struct{

int idCliente;
char name[50];
char surname[50];
long int dni;
int status;
int cantidadAlquileres;

}eCliente;


typedef struct{

int motivo;
int operador;
int tiempoEstimado;
int tiempoReal;
int status;


}eAlquiler;

typedef struct{

int idCliente;
int motivo;
int status;

}eClienteAlquiler;

long int getLongInt(char message[],char errorMensaje[],char eMessage[], int lowLimit, int hiLimit);
int getInt(char message[],char errorMensaje[],char eMessage[], int lowLimit, int hiLimit);
int funcionValidarNumeros(char mensaje[],char validar[]);
int obtenerEspacioLibre(eAlquiler [],int );
int obtenerEspacioLibreClienteAlquiler(eClienteAlquiler [],int );
int obtenerEspacioLibreUno(eCliente cliente[],int cant);
//int obtenerEspacioLibrePP(eProductProvider [],int );
//float getFloat(char message[],char errorMensaje[],char eMessage[], int lowLimit, int hiLimit);
//int functionValidString(char mensaje[],char str[]);
//
//
//
void getString(char message[],char errorMensaje[],char eMessage[],char input[], int lowLimit, int hiLimit);
//
//void getDescription(char message[],char eMessage[],char inputDescription[], int lowLimit, int hiLimit);
//
void setCliente(eCliente[],int,int ,char[],char[],long int);

void setClienteAlquiler(eClienteAlquiler[],int,int ,int);

void setAlquiler(eAlquiler [],int,int ,int,int);

void setStatusCliente(eCliente[],int );

void setStatusAlquiler(eAlquiler[],int );


//void   showProduct(eProduct [],int);
//
//void   showProvider(eProvider [],int );
//
//void   showProductProvider(eProductProvider [],int cant);

int flagDetector(int);


void cleanProduct(eCliente cliente[],int,int);

int findClienteByCode(eCliente[],int,int);

//int findProductProviderByCode(eProductProvider[] ,int ,int auxCodeProduct);
//
