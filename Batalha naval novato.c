#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // Declaração do tabuleiro (10x10), inicialmente preenchido com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;

    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 1;

    int i; // Variável para iteração

    // Validação: verificar se o navio horizontal cabe no tabuleiro
    if (coluna_navio_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio horizontal excede os limites do tabuleiro.\n");
        return 1;
    }

    // Validação: verificar se o navio vertical cabe no tabuleiro
    if (linha_navio_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio vertical excede os limites do tabuleiro.\n");
        return 1;
    }

    // Posiciona o navio horizontal no tabuleiro
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // Verificar se já existe um navio nessa posição
        if (tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] == VALOR_NAVIO) {
            printf("Erro: sobreposição detectada no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + i] = VALOR_NAVIO;
    }

    // Posiciona o navio vertical no tabuleiro
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        // Verificar se já existe um navio nessa posição
        if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == VALOR_NAVIO) {
            printf("Erro: sobreposição detectada no navio vertical.\n");
            return 1;
        }
        tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = VALOR_NAVIO;
    }

    // Exibe o tabuleiro no console
    printf("=== Tabuleiro de Batalha Naval ===\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
