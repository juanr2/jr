struct
{
    int id;
    char name[51];
    //char email[51];
    char lastName[51];
    int dni;
    //int isEmpty;

}typedef Eclient;

int client_compareApe(void* pClientA,void* pClientB);
int client_compare(void* pClientA,void* pClientB);
void client_print(Eclient* this);
Eclient* client_new(void);
void client_delete(Eclient* this);
int client_setId(Eclient* this, int id);
int client_getId(Eclient* this);


