#include <stdio.h>
#include <stdlib.h>


#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

char jogo[3][3];

void clear(){
    system(CLEAR);
}

void game_loop(){

}

void start_jogo(){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            jogo[i][j] = 0; //preenche a matriz do jogo em zeros
        }
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
                printf(" %d ", jogo[i][j]);
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


int main(){

    start_jogo();
    print_jogo();

    return 0;
}