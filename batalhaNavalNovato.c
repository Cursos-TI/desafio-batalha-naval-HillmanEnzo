#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Conforme a instrução do texto, utilizaremos o tamanho fixo de 10x10 já neste nível.
    int tabuleiro[10][10];

    // Inicializando todas as posições do tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    int tamanhoNavio = 3;

    // 1. Posicionando o Navio Horizontal
    // Coordenadas iniciais: Linha 2, Coluna 2
    int linhaHor = 2;
    int colHor = 2;

    // Validação de limite: verifica se o navio cabe horizontalmente no tabuleiro
    if (colHor + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            tabuleiro[linhaHor][colHor + i] = 3; // Preenche as colunas sucessivas
        }
    } else {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
    }

    // 2. Posicionando o Navio Vertical
    // Coordenadas iniciais: Linha 5, Coluna 7
    int linhaVer = 5;
    int colVer = 7;

    // Validação de limite e sobreposição: verifica se cabe verticalmente
    if (linhaVer + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            // Verifica se a posição já está ocupada por outro navio (sobreposição)
            if (tabuleiro[linhaVer + i][colVer] == 0) {
                tabuleiro[linhaVer + i][colVer] = 3; // Preenche as linhas sucessivas
            } else {
                printf("Erro: Sobreposição detectada na coordenada [%d][%d].\n", linhaVer + i, colVer);
            }
        }
    } else {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
    }

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    // Exibindo o tabuleiro completo de forma organizada
    printf("--- Batalha Naval - Tabuleiro 10x10 ---\n\n");
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Imprime a matriz com um espaço entre os números para melhor visualização
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n"); // Quebra de linha ao final de cada linha da matriz
    }
    printf("\n");

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
    // 
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}