#include <stdio.h>
#include <stdlib.h>
#include "pecman.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

void move(char direcao){
    // fazendo o herói andar (w - sobe,a - esquerda,s - desce,d - direita)
    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao)
    {
    case 'a':
        m.matriz[heroi.x][heroi.y-1] = '@';
        heroi.y--;
        break;
       
    case 'd':
        m.matriz[heroi.x][heroi.y+1] = '@';
        heroi.y++;
        break;

    case 'w':
        m.matriz[heroi.x-1][heroi.y] = '@';
        heroi.x--;
        break;

    case 's':
        m.matriz[heroi.x+1][heroi.y] = '@';
        heroi.x++;
        break;
    }

    // tirando o herói da antiga posição
    
}

int main() {

    lemapa(&m);

    encontraheroi(&heroi, &m, '@');

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
