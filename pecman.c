#include <stdio.h>
#include <stdlib.h>
#include "pecman.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

int ehvalido(char direcao){
    if(direcao == 'a' || direcao == 's' || direcao == 'd' || direcao == 'w'){
        return  1;
    }
    else{
        return 0;
    }
}

void move(char direcao){
    // fazendo o herói andar (w - sobe,a - esquerda,s - desce,d - direita)
    if( !ehvalido(direcao) ){
        return;
    }

    int proximox, proximoy;

    proximox = heroi.x;
    proximoy = heroi.y;


    switch (direcao)
    {
    case 'a':
        proximoy--;
        break;
       
    case 'd':
        proximoy++;
        break;

    case 'w':
        proximox--;
        break;

    case 's':
        proximox++;
        break;
    }

    if(!podeandarnomapa(&m, proximox, proximoy)){
        return;
    }
 
    andanomapa(&m, &heroi.x, &heroi.y, &proximox, &proximoy, '@');

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
