#include <stdio.h>
#include <stdlib.h>
#include "pecman.h"

char** mapa;                           // declarando uma matriz como ponteiro de ponteiro para alocar sua memoria dinamicamente
int linhas;
int colunas;

void liberamapa(){
    for (int i = 0; i < linhas; i++)
    {
        free(mapa[i]);
    }
    free(mapa); 
}

void lemapa(){
    FILE* f;                                    //  declarando o tipo da variável como file (ponteiro) para abrir o arquivo
    
    f = fopen("mapa.txt","r");        
    if (f==0){
        printf("erro.\n");
        exit(1);
    }
    
    fscanf(f,"%d %d", &linhas, &colunas);

    alocamapa();

    for (int i=0; i < linhas; i++){
        fscanf(f,"%s",mapa[i]);
    }
    
    fclose(f);                                  // realizando o fechamento do arquivo

}

void alocamapa(){
    mapa =  malloc(sizeof(char *)*linhas);
    for (int i=0; i< linhas; i++){
        mapa[i] = malloc(sizeof(char)*(colunas+1));
    }
}

int main() {

    lemapa();
    
    for (int i=0; i < linhas; i++){
        printf("%s",mapa[i]);
        printf("\n");
    }

    liberamapa();   

    return 0;  
}
