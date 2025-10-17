struct mapa
{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao
{
    int x;
    int y;
};

typedef struct posicao POSICAO;

void liberamapa();
void lemapa();
void alocamapa();
void imprimemapa();
void encontraheroi(POSICAO* p, MAPA* m, char c);