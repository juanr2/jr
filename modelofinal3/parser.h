
int parserClient(FILE* pFile , ArrayList* pArrayListClient);

int parserVentas(FILE* pFile , ArrayList* pArrayListVenta);

int parserProduct(FILE* pFile , ArrayList* pArrayListProduct);


int saveClients(const char *fileName, ArrayList* pArrayListClient);

int saveVentas(const char *fileName, ArrayList* pArrayListVenta);

int saveProduct(const char *fileName, ArrayList* pArrayListProduct);

