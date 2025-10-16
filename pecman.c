#include <stdio.h>
#include <stdlib.h>
#include "pecman.h"
#include "mapa.h"

MAPA m;

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

    lemapa(&m);

    do {
        imprimemapa(&m);                      // função para imprimir o mapa no loop

        char direcao;                       // char que vai armazenar a mudança de direção do herói

        scanf(" %c", &direcao); 
        
        move(direcao);                      // função para mover o herói de acordo com a direção passada

    } 
    while(!acabou());

    
    

    liberamapa(&m);   

    return 0;  
}
