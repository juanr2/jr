struct
{
    int id_ventas;
    int id;
    int codeProd;
    int cantidad;
    int priceProd;


}typedef eVentas;

//int client_compareApe(void* pClientA,void* pClientB);
//int client_compare(void* pClientA,void* pClientB);
void ventas_print(eVentas* this);
eVentas* ventas_new(void);
//void client_delete(Eclient* this);
//int client_setId(Eclient* this, int id);
//int client_getId(Eclient* this);


