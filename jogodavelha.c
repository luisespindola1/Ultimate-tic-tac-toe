#include <stdio.h>
#include <stdlib.h>


#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

char jogo[3][3];
int flag_elemento = -1; // -1 = x     1 = o

void clear(){
    system(CLEAR);
}
void preencher_matriz(int escolha_linha, int escolha_coluna){

    if(flag_elemento < 0){
        jogo[escolha_linha - 1][escolha_coluna - 1] = 'x';
    }
    else{
        jogo[escolha_linha - 1][escolha_coluna - 1] = 'o';
    }

}

void print_jogo(){

    clear();

    printf("\n");

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(jogo[i][j] == 0){
                printf("   ");
            }
            else{
                printf(" %c ", jogo[i][j]);
            }
            if(j != 2){
                printf("|");
            }
        }
        if(i != 2){
            printf("\n-----------");
        }
        printf("\n");
    }
}

void game_loop(){

    while(1){

    int escolha_linha, escolha_coluna;

    print_jogo();

    printf("Escolha a linha (1 - 3): ");
    scanf("%d", &escolha_linha);
    while(escolha_linha < 1 || escolha_linha > 3){
        printf("\nLinha invalida!\n");
        printf("Escolha a linha (1 - 3): ");
        scanf("%d", &escolha_linha);
    }
    printf("\n");

    printf("Escolha a coluna (1 - 3): ");
    scanf("%d", &escolha_coluna);
    while(escolha_coluna < 1 || escolha_coluna > 3){
        printf("\nColuna invalida!\n");
        printf("Escolha a coluna (1 - 3): ");
        scanf("%d", &escolha_coluna);
    }
    printf("\n");

    preencher_matriz(escolha_linha, escolha_coluna);

    flag_elemento *= -1;
    

    }
}

void start_jogo(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            jogo[i][j] = 0; //preenche a matriz do jogo em zeros
        }
    }
}


int main(){

    start_jogo();
    game_loop();

    return 0;
}