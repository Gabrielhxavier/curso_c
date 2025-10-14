#include <stdio.h>
#include <stdlib.h>

char** mapa;                           // declarando uma matriz como ponteiro de ponteiro para alocar sua memoria dinamicamente
int linhas;
int colunas;

int main() {

    FILE* f;                                    //  declarando o tipo da variável como file (ponteiro) para abrir o arquivo
    
    f = fopen("mapa.txt","r");        
    if (f==0){
        printf("erro.\n");
        exit(1);
        
    }
    
    fscanf(f,"%d %d", &linhas, &colunas);

    mapa =  malloc(sizeof(char *)*linhas);
    for (int i=0; i< linhas; i++){
        mapa[i] = malloc(sizeof(char)*(colunas+1));
    }

    for (int i=0; i < linhas; i++){
        fscanf(f,"%s",mapa[i]);
    }
    
    for (int i=0; i < linhas; i++){
        printf("%s",mapa[i]);
        printf("\n");
    }

    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa);    

    fclose(f);                                  // realizando o fechamento do arquivo

    return 0;
}
