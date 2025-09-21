#include <stdio.h>
#include <stdlib.h>


#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

char jogo[3][3];
int flag_elemento = -1; // -1 = x     1 = o
int escolha_linha, escolha_coluna;
int move_valido = 1;
int flag_vitoria = 0;

void clear(){
    system(CLEAR);
}

int check_vitoria(){
    int coluna = 0;
    for(int i = 0; i < 3; i++){
        if((jogo[i][coluna] == jogo[i][coluna + 1] && jogo[i][coluna + 1] == jogo[i][coluna + 2]) && jogo[i][coluna] != 0 && jogo[i][coluna + 1] != 0 && jogo[i][coluna + 2] != 0){
            return 1;
        }
    }

    int linha = 0;
    for(int i = 0; i < 3; i++){
        if((jogo[linha][i] == jogo[linha + 1][i] && jogo[linha + 1][i] == jogo[linha + 2][i]) && jogo[linha][i] != 0 && jogo[linha + 1][i] != 0 && jogo[linha + 2][i] != 0){
            return 1;
        }
    }

    if((jogo[linha][coluna] == jogo[linha + 1][coluna + 1] && jogo[linha + 1][coluna + 1] == jogo[linha + 2][coluna + 2]) && jogo[linha][coluna] != 0 && jogo[linha + 1][coluna + 1] != 0 && jogo[linha + 2][coluna + 2] != 0){
        return 1;
    }

    if((jogo[linha][coluna + 2] == jogo[linha + 1][coluna + 1] && jogo[linha + 1][coluna + 1] == jogo[linha + 2][coluna]) && jogo[linha + 1][coluna + 1] != 0 && jogo[linha + 2][coluna] != 0 && jogo[linha][coluna + 2] != 0){
        return 1;
    }

    return 0;
}

int preencher_matriz(){

    if(jogo[escolha_linha - 1][escolha_coluna - 1] != 0){
        return 0;
    }

    if(flag_elemento < 0){
        jogo[escolha_linha - 1][escolha_coluna - 1] = 'x';
    }
    else{
        jogo[escolha_linha - 1][escolha_coluna - 1] = 'o';
    }

    return 1;
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

void input_jogador(){


    if(move_valido == 0) printf("\nEsse espaco ja esta preenchido!\n");
    printf("\nEscolha a linha (1 - 3): ");
    scanf("%d", &escolha_linha);
    while(escolha_linha < 1 || escolha_linha > 3){
        printf("\nLinha invalida!\n");
        printf("\nEscolha a linha (1 - 3): ");
        scanf("%d", &escolha_linha);
    }

    printf("\nEscolha a coluna (1 - 3): ");
    scanf("%d", &escolha_coluna);
    while(escolha_coluna < 1 || escolha_coluna > 3){
        printf("\nColuna invalida!\n");
        printf("\nEscolha a coluna (1 - 3): ");
        scanf("%d", &escolha_coluna);
    }

    printf("\n");
}

void game_loop(){

    while(1){

    print_jogo();
    flag_vitoria = check_vitoria();
    if(flag_vitoria == 1) {
        printf("\nVitoria!\n");
        break;
    }
    input_jogador();
    move_valido = preencher_matriz();
    if(move_valido == 0) continue;


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