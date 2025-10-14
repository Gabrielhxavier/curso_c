#include <stdio.h>
#include <stdlib.h>

int main() {

    char mapa[5][11];                           // declarando uma matriz

    FILE* f;                                    //  declarando o tipo da variável como file (ponteiro) para abrir o arquivo
    
    f = fopen("mapa.txt","r");        
    if (f==0){
        printf("erro.\n");
        exit(1);
        
    }
    for (int i=0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    
    }
    
    fclose(f);                                  // realizando o fechamento do arquivo

    for (int i = 0; i < 5; i++)
    {
        printf("%s", mapa[i]);
        printf("\n");
    }
    

    return 0;
}
