#include <stdio.h>
#include <stdlib.h>

#define linhas 10  
#define colunas 10

void imprimirTabuleiro(int tabuleiro[linhas][colunas]) {
    printf("\n¨¨¨¨¨¨Tabuleiro de BATALHA NAVAL:¨¨¨¨¨¨\n");
    printf("\n   ");
    for (int j = 0; j < colunas; j++){
        printf("%c ", 'A' + j);
    } 
     printf("\n");
    
    for (int i = 0; i < linhas; i++) {
        printf("%2d ", i);
        for (int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void imprimirHabilidade(int habilidade[5][5], const char* nome) {
        printf("\nHabilidade %s:\n", nome);
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                printf("%d ", habilidade[i][j]);
            }
            printf("\n");
        }
    }
    
    void preencherCone(int cone[5][5]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 2 - i; j <= 2 + i; j++) {
                cone[i][j] = 1;
            }
        }
    }
    
    void preencherOctaedro(int octaedro[5][5]) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (abs(i - 2) + abs(j - 2) <= 2) {
                    octaedro[i][j] = 1;
                }
            }
        }
    }
    
    void preencherCruz(int cruz[5][5]) {
        for (int i = 0; i < 5; i++) {
            cruz[i][2] = 1;
            cruz[2][i] = 1;
        }
    }
    void aplicarHabilidadeNoTabuleiro(int tabuleiro[linhas][colunas], int habilidade[5][5], int centro_i, int centro_j, int valor_habilidade) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int ti = centro_i - 2 + i;
            int tj = centro_j - 2 + j;
            if (ti >= 0 && ti < linhas && tj >= 0 && tj < colunas) {
                if (habilidade[i][j] == 1) {
                    if (tabuleiro[ti][tj] == 0){
                        tabuleiro[ti][tj] = valor_habilidade;
                    }
                    
                  //tabuleiro[ti][tj] = 1; // 1 representa área atingida
                }
            }
        }
    }
}


int main() {

    int tabuleiro[linhas][colunas] = {0};

    // Navio horizontal (linha 1, colunas 2 a 5)
    for (int j = 2; j <= 3; j++) {
        tabuleiro[1][j] = 3;
    }

    // Navio vertical (coluna 8, linhas 3 a 6)
    for (int i = 3; i <= 6; i++) {
        tabuleiro[i][8] = 3;
    }

    // Navio diagonal principal (0,0) até (3,3)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio diagonal secundária (0,9) até (3,6)
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }
   
        int cone[5][5] = {0};
        int octaedro[5][5] = {0};
        int cruzEspecial[5][5] = {0};
    
        preencherCone(cone);
        preencherOctaedro(octaedro);
        preencherCruz(cruzEspecial);
    
        imprimirHabilidade(cone, "Cone");
        imprimirHabilidade(octaedro, "Octaedro");
        imprimirHabilidade(cruzEspecial, "Cruz");

        aplicarHabilidadeNoTabuleiro(tabuleiro, cruzEspecial, 5, 5, 5);
        aplicarHabilidadeNoTabuleiro(tabuleiro, cone, 9, 3, 7);
        aplicarHabilidadeNoTabuleiro(tabuleiro, octaedro, 4, 2, 9);

        imprimirTabuleiro(tabuleiro);

           int i = 1;   int j = 2; 
    if (i >= 0 && i < linhas && j >= 0 && j < colunas) { 
         if (tabuleiro[i][j] == 0) {     
             tabuleiro[i][j] = 5;       
         } else {  printf("Aviso: Tentativa de sobrepor um navio em (%d, %d)\n", i, j);  }    
         } else {  printf("Aviso: Coordenada (%d, %d) fora dos limites do tabuleiro.\n", i, j);}
        


    return 0;
        }

         
