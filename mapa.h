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
int podeandarnomapa(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int* origemx, int* origemy, int* destinox, int* destinoy, char heroi);