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

void imprimemapa(){
    for (int i=0; i < linhas; i++){
        printf("%s",mapa[i]);
        printf("\n");
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    // localizar o herói no mapa
    int x, y;                                   // variáveis que vão armazenar a posição atual do herói
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (mapa[i][j] == '@')
            {
                x = i;
                y = j;
            }
        }  
    }

    // fazendo o herói andar (w - sobe,a - esquerda,s - desce,d - direita)
    switch (direcao)
    {
    case 'a':
        mapa[x][y-1] = '@';
        break;
       
    case 'd':
        mapa[x][y+1] = '@';
        break;

    case 'w':
        mapa[x-1][y] = '@';
        break;

    case 's':
        mapa[x+1][y] = '@';
        break;
    }

    // tirando o herói da antiga posição
    mapa[x][y] = '.';
}

int main() {

    lemapa();

    do {
        imprimemapa();                      // função para imprimir o mapa no loop

        char direcao;                       // char que vai armazenar a mudança de direção do herói

        scanf(" %c", &direcao); 
        
        move(direcao);                      // função para mover o herói de acordo com a direção passada

    } 
    while(!acabou());

    
    

    liberamapa();   

    return 0;  
}
