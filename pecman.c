#include <stdio.h>
#include <stdlib.h>
#include "pecman.h"

MAPA m;

void liberamapa(){
    for (int i = 0; i < m.linhas; i++)
    {
        free(m.matriz[i]);
    }
    free(m.matriz); 
}

void lemapa(){
    FILE* f;                                    //  declarando o tipo da variável como file (ponteiro) para abrir o arquivo
    
    f = fopen("mapa.txt","r");        
    if (f==0){
        printf("erro.\n");
        exit(1);
    }
    
    fscanf(f,"%d %d", &(m.linhas), &(m.colunas));

    alocamapa();

    for (int i=0; i < m.linhas; i++){
        fscanf(f,"%s",m.matriz[i]);
    }
    
    fclose(f);                                  // realizando o fechamento do arquivo

}

void alocamapa(){
    m.matriz =  malloc(sizeof(char *)*m.linhas);
    for (int i=0; i< m.linhas; i++){
        m.matriz[i] = malloc(sizeof(char)*(m.colunas+1));
    }
}

void imprimemapa(){
    for (int i=0; i < m.linhas; i++){
        printf("%s",m.matriz[i]);
        printf("\n");
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    // localizar o herói no mapa
    int x, y;                                   // variáveis que vão armazenar a posição atual do herói
    for (int i = 0; i < m.linhas; i++)
    {
        for (int j = 0; j < m.colunas; j++)
        {
            if (m.matriz[i][j] == '@')
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
        m.matriz[x][y-1] = '@';
        break;
       
    case 'd':
        m.matriz[x][y+1] = '@';
        break;

    case 'w':
        m.matriz[x-1][y] = '@';
        break;

    case 's':
        m.matriz[x+1][y] = '@';
        break;
    }

    // tirando o herói da antiga posição
    m.matriz[x][y] = '.';
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
