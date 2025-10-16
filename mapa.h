struct mapa
{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

void liberamapa();
void lemapa();
void alocamapa();
void imprimemapa();