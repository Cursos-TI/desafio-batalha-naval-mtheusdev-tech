#include <stdio.h>

#define linhas 10
#define colunas 10

void imprimirTabuleiro( int tabuleiro[linhas][colunas]) {
    printf("\n¨¨¨¨¨¨Tabuleiro de BATALHA NAVAL¨¨¨¨¨¨\n");
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

int main() {

    // Nível Aventureiro - Tabuleiro 10x10 com 4 navios
    int tabuleiro[linhas][colunas] = {0};

    // Navio horizontal (linha 1, colunas 2 a 5)
    for (int j = 2; j <= 5; j++) {
     for (int i = 3; i <= 6; i++) {
        tabuleiro[i][8] = 3;
    }
        tabuleiro[1][j] = 3;
    }

    for (int i = 0; i < 4; i++) {    // Navio diagonal principal (0,0) até (3,3)
     for (int i = 0; i < 4; i++) {  // Navio diagonal secundária (0,9) até (3,6)
        tabuleiro[i][9 - i] = 3;
    }
        tabuleiro[i][i] = 3;
    }
    

    imprimirTabuleiro(tabuleiro);

    return 0;
}

    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0