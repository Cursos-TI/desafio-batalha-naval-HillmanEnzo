#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Mestre - Habilidades Especiais com Matrizes e Áreas de Efeito

int main() {
    // 1. Criação e Inicialização do Tabuleiro 10x10
    int tabuleiro[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Posicionamento de Navios (Herança do Nível Aventureiro)
    // Horizontal
    for (int i = 0; i < 3; i++) tabuleiro[0][i] = 3; 
    // Vertical
    for (int i = 0; i < 3; i++) tabuleiro[7 + i][9] = 3;
    // Diagonal Principal
    for (int i = 0; i < 3; i++) tabuleiro[2 + i][8 + i] = 3; 

    // 3. CRIAÇÃO DAS MATRIZES DE HABILIDADE (5x5)
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // Preenchendo a matriz do CONE
    // O cone começa no topo (linha 0) no centro (coluna 2) e desce expandindo.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Condicional matemática para desenhar o triângulo invertido (cone)
            if (i <= 2 && j >= (2 - i) && j <= (2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Preenchendo a matriz da CRUZ
    // O centro exato da matriz 5x5 é a linha 2, coluna 2.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Preenchendo a matriz do OCTAEDRO (Losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Calcula a distância da célula atual até o centro (2,2)
            int distLinha = (i > 2) ? (i - 2) : (2 - i);
            int distColuna = (j > 2) ? (j - 2) : (2 - j);
            
            // Se a soma das distâncias for menor ou igual ao raio (2), preenche
            if (distLinha + distColuna <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // 4. INTEGRAÇÃO E SOBREPOSIÇÃO NO TABULEIRO
    
    // Aplicando a habilidade CONE (Origem Topo: Linha 1, Coluna 4)
    int origConeL = 1, origConeC = 4;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cone[i][j] == 1) {
                int linhaReal = origConeL + i;
                int colunaReal = origConeC + (j - 2); // -2 para centralizar a matriz 5x5
                // Condicional para validar se o ataque não sai do tabuleiro
                if (linhaReal >= 0 && linhaReal < 10 && colunaReal >= 0 && colunaReal < 10) {
                    tabuleiro[linhaReal][colunaReal] = 5;
                }
            }
        }
    }

    // Aplicando a habilidade CRUZ (Origem Centro: Linha 7, Coluna 2)
    int origCruzL = 7, origCruzC = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (cruz[i][j] == 1) {
                int linhaReal = origCruzL + (i - 2);
                int colunaReal = origCruzC + (j - 2);
                if (linhaReal >= 0 && linhaReal < 10 && colunaReal >= 0 && colunaReal < 10) {
                    tabuleiro[linhaReal][colunaReal] = 5;
                }
            }
        }
    }

    // Aplicando a habilidade OCTAEDRO (Origem Centro: Linha 4, Coluna 7)
    int origOctaL = 4, origOctaC = 7;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (octaedro[i][j] == 1) {
                int linhaReal = origOctaL + (i - 2);
                int colunaReal = origOctaC + (j - 2);
                if (linhaReal >= 0 && linhaReal < 10 && colunaReal >= 0 && colunaReal < 10) {
                    tabuleiro[linhaReal][colunaReal] = 5;
                }
            }
        }
    }

    // 5. EXIBIÇÃO DO TABULEIRO FINAL
    printf("=========================================\n");
    printf("     BATALHA NAVAL - HABILIDADES AoE     \n");
    printf("=========================================\n\n");
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    printf("\n--- LEGENDA ---\n");
    printf("0 = Agua\n");
    printf("3 = Navios\n");
    printf("5 = Area de Efeito (Habilidades)\n");

    return 0;
}