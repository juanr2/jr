
struct
{
    int number;
    char name[51];
    int par;
    int impar;
    int primo;

}typedef Eclient;

int client_compareApe(void* pClientA,void* pClientB);
void client_compare(void* pClientA,void* pClientB);
void client_print(Eclient* this);
Eclient* client_new(void);
void client_delete(Eclient* this);
int client_setId(Eclient* this, int id);
int client_getId(Eclient* this);
