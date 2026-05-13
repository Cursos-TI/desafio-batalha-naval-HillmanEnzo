#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal

int main() {
    // 1. Criação e Inicialização do Tabuleiro 10x10
    int tabuleiro[10][10];
    int tamanhoNavio = 3;

    // Preenchendo toda a matriz com 0 (representando a água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Variável auxiliar para checar sobreposições
    int espacoLivre; 

    // --- NAVIO 1: HORIZONTAL ---
    // Coordenadas: Linha 2, começando na Coluna 2
    int l_hor = 2, c_hor = 2;
    espacoLivre = 1;

    // Valida limites do tabuleiro
    if (c_hor + tamanhoNavio <= 10) {
        // Valida sobreposição (simula o caminho antes de preencher)
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l_hor][c_hor + i] != 0) espacoLivre = 0;
        }
        // Se estiver livre, preenche com 3
        if (espacoLivre) {
            for (int i = 0; i < tamanhoNavio; i++) tabuleiro[l_hor][c_hor + i] = 3;
        } else {
            printf("Erro: Sobreposição no Navio Horizontal.\n");
        }
    }

    // --- NAVIO 2: VERTICAL ---
    // Coordenadas: Linha 5, começando na Coluna 7
    int l_ver = 5, c_ver = 7;
    espacoLivre = 1;

    if (l_ver + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l_ver + i][c_ver] != 0) espacoLivre = 0;
        }
        if (espacoLivre) {
            for (int i = 0; i < tamanhoNavio; i++) tabuleiro[l_ver + i][c_ver] = 3;
        } else {
            printf("Erro: Sobreposição no Navio Vertical.\n");
        }
    }

    // --- NAVIO 3: DIAGONAL PRINCIPAL (\) ---
    // Coordenadas: Linha 0, Coluna 0 (vai descer para a direita: 0,0 -> 1,1 -> 2,2)
    int l_diag1 = 0, c_diag1 = 0;
    espacoLivre = 1;

    // Na diagonal principal, tanto a linha quanto a coluna aumentam
    if (l_diag1 + tamanhoNavio <= 10 && c_diag1 + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l_diag1 + i][c_diag1 + i] != 0) espacoLivre = 0;
        }
        if (espacoLivre) {
            for (int i = 0; i < tamanhoNavio; i++) tabuleiro[l_diag1 + i][c_diag1 + i] = 3;
        } else {
            printf("Erro: Sobreposição no Navio Diagonal 1.\n");
        }
    }

    // --- NAVIO 4: DIAGONAL SECUNDÁRIA (/) ---
    // Coordenadas: Linha 6, Coluna 3 (vai descer para a esquerda: 6,3 -> 7,2 -> 8,1)
    int l_diag2 = 6, c_diag2 = 3;
    espacoLivre = 1;

    // Na diagonal secundária, a linha aumenta e a coluna diminui
    // Limite da coluna: tem que ser maior ou igual ao tamanho do navio - 1
    if (l_diag2 + tamanhoNavio <= 10 && c_diag2 - (tamanhoNavio - 1) >= 0) {
        for (int i = 0; i < tamanhoNavio; i++) {
            if (tabuleiro[l_diag2 + i][c_diag2 - i] != 0) espacoLivre = 0;
        }
        if (espacoLivre) {
            for (int i = 0; i < tamanhoNavio; i++) tabuleiro[l_diag2 + i][c_diag2 - i] = 3;
        } else {
            printf("Erro: Sobreposição no Navio Diagonal 2.\n");
        }
    }

    // --- EXIBIÇÃO DO TABULEIRO ---
    printf("=========================================\n");
    printf("        BATALHA NAVAL - MATECHECK        \n");
    printf("=========================================\n\n");
    
    // Loops aninhados para imprimir a matriz
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Imprime o valor da posição e adiciona um espaço para alinhamento
            printf("%d ", tabuleiro[i][j]);
        }
        // Ao terminar de imprimir todas as colunas de uma linha, quebra a linha
        printf("\n");
    }
    
    printf("\nLegenda:\n0 = Agua\n3 = Navio\n");

    return 0;
}