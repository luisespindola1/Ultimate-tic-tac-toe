#include <stdio.h>
#include <stdlib.h>


#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

char jogo[9][9];
int flag_elemento = -1; // -1 = x     1 = o
int escolha_linha, escolha_coluna;
int move_valido = 1;
int flag_vitoria = 0;

int flag_jogos[9] = {0};

void clear(){
    system(CLEAR);
}

void check_vitoria(){
    int linha = 0;

    while(linha < 9){

        int idx = 0;

        int coluna = 0;

        while(coluna < 9) {

            for(int i = linha; i < linha + 3; i++){
                 if((jogo[i][coluna] == jogo[i][coluna + 1] && jogo[i][coluna + 1] == jogo[i][coluna + 2]) && jogo[i][coluna] != 0 && jogo[i][coluna + 1] != 0 && jogo[i][coluna + 2] != 0){
                    if(jogo[i][coluna] == 'o'){
                        flag_jogos[idx] = 1;
                    }
                    else if(jogo[i][coluna] == 'x'){
                        flag_jogos[idx] = -1;
                    }
            }
            }

            for(int i = coluna; i < coluna + 3; i++){
                if((jogo[linha][i] == jogo[linha + 1][i] && jogo[linha + 1][i] == jogo[linha + 2][i]) && jogo[linha][i] != 0 && jogo[linha + 1][i] != 0 && jogo[linha + 2][i] != 0){
                    if(jogo[linha][i] == 'o'){
                        flag_jogos[idx] = 1;
                    }
                    else if(jogo[linha][i] == 'x'){
                        flag_jogos[idx] = -1;
                    }
            }
            }

            if((jogo[linha][coluna] == jogo[linha + 1][coluna + 1] && jogo[linha + 1][coluna + 1] == jogo[linha + 2][coluna + 2]) && jogo[linha][coluna] != 0 && jogo[linha + 1][coluna + 1] != 0 && jogo[linha + 2][coluna + 2] != 0){
                if(jogo[linha][coluna] == 'o'){
                    flag_jogos[idx] = 1;
                }
                else if(jogo[linha][coluna] == 'x'){
                    flag_jogos[idx] = -1;
                }
            }

            if((jogo[linha][coluna + 2] == jogo[linha + 1][coluna + 1] && jogo[linha + 1][coluna + 1] == jogo[linha + 2][coluna]) && jogo[linha + 1][coluna + 1] != 0 && jogo[linha + 2][coluna] != 0 && jogo[linha][coluna + 2] != 0){
                if(jogo[linha][coluna + 2] == 'o'){
                    flag_jogos[idx] = 1;
                }
                else if(jogo[linha][coluna + 2] == 'x'){
                    flag_jogos[idx] = -1;
                }
            }

            coluna += 3;
            idx++;
        }

        linha += 3;
    }
}

int check_vitoria_jogos(){

    for(int i = 0; i < 9; i += 3){
        if(flag_jogos[i] == flag_jogos[i + 1] && flag_jogos[i + 1] == flag_jogos[i + 2] && flag_jogos[i] != 0 && flag_jogos[i + 1] != 0&& flag_jogos[i + 2] != 0){
            return 1;
        }
    }

    for(int i = 0; i < 3; i++){
        if(flag_jogos[i] == flag_jogos[i + 3] && flag_jogos[i + 3] == flag_jogos[i + 6] && flag_jogos[i] != 0 && flag_jogos[i + 3] != 0&& flag_jogos[i + 6] != 0){
            return 1;
        }
    }

    if(flag_jogos[0] == flag_jogos[4] && flag_jogos[4] == flag_jogos[8] && flag_jogos[0] != 0 && flag_jogos[4] != 0&& flag_jogos[8] != 0){
        return 1;
    }

    if(flag_jogos[2] == flag_jogos[4] && flag_jogos[4] == flag_jogos[6] && flag_jogos[2] != 0 && flag_jogos[4] != 0&& flag_jogos[6] != 0){
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

    printf("\n   1   2   3        4   5   6        7   8   9         \n");

    for(int i = 0; i < 9; i++){
        printf("%d ", i + 1);

        for(int j = 0; j < 9; j++){

            if(jogo[i][j] == 0){
                printf("   ");
            }
            else{
                printf(" %c ", jogo[i][j]);
            }
            if(j == 2 || j == 5){
                printf("  ┃   ");
            }
            else if(j != 8){
                printf("|");
            }
        } 

        if(i == 2 || i == 5){
            printf("\n  _____________________________________________\n  ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾");
        }

        else if(i != 8){
            printf("\n  -----------      -----------      -----------");
        }
        printf("\n");
    }
}

void input_jogador(){


    if(move_valido == 0) printf("\nEsse espaco ja esta preenchido!\n");
    printf("\nEscolha a linha (1 - 9): ");
    scanf("%d", &escolha_linha);
    while(escolha_linha < 1 || escolha_linha > 9){
        printf("\nLinha invalida!\n");
        printf("\nEscolha a linha (1 - 9): ");
        scanf("%d", &escolha_linha);
    }

    printf("\nEscolha a coluna (1 - 9): ");
    scanf("%d", &escolha_coluna);
    while(escolha_coluna < 1 || escolha_coluna > 9){
        printf("\nColuna invalida!\n");
        printf("\nEscolha a coluna (1 - 9): ");
        scanf("%d", &escolha_coluna);
    }

    printf("\n");
}

void game_loop(){

    while(1){

    check_vitoria();
    print_jogo();
    flag_vitoria = check_vitoria_jogos();
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