/*
 * Desafio: Nível Aventureiro - Tabuleiro Completo e Navios Diagonais
 * Autor: Lucas Bittencourt
 * Data: 27/10/2025
 *
 * Descrição: Este programa inicializa um tabuleiro de Batalha Naval 10x10,
 * posiciona QUATRO navios (tamanho 3) de forma hardcoded:
 * - 1 Horizontal
 * - 1 Vertical
 * - 1 Diagonal (Cima-Esquerda para Baixo-Direita)
 * - 1 Diagonal (Cima-Direita para Baixo-Esquerda)
 *
 * Requisitos Atendidos:
 * 1. Matriz 10x10 inicializada com 0 (AGUA).
 * 2. Quatro navios (valor 3) posicionados, incluindo duas diagonais.
 * 3. Validação de limites e sobreposição para todas as orientações.
 * 4. Exibição do tabuleiro no console.
 * 5. Código documentado e legível.
 */

#include <stdio.h>

// --- Constantes Globais (Definições) ---

// Define o tamanho do tabuleiro (10x10)
#define TAMANHO_TABULEIRO 10
// Define o tamanho fixo dos navios deste desafio
#define TAMANHO_NAVIO 3

// Define os valores para representar água e navio no tabuleiro
#define AGUA 0
#define NAVIO 3

// --- NOVAS Constantes de Orientação ---
// Precisamos de mais opções além de "horizontal ou não"
// Usar constantes torna a chamada da função muito mais legível
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL_DIREITA 2 // Diagonal para baixo e para a direita (ex: (1,1), (2,2))
#define DIAGONAL_ESQUERDA 3 // Diagonal para baixo e para a esquerda (ex: (1,8), (2,7))


// --- Variáveis Globais ---

// Declara a matriz (array bidimensional) que representa o tabuleiro
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// --- Protótipos das Funções ---

/**
 * @brief Inicializa todo o tabuleiro com o valor AGUA (0).
 * (Sem alterações do Nível Novato)
 */
void inicializar_tabuleiro();

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 * (Sem alterações do Nível Novato)
 */
void exibir_tabuleiro();

/**
 * @brief Tenta posicionar um navio no tabuleiro com uma orientação específica.
 *
 * @param linha_inicio A linha (Y) onde o navio começa.
 * @param col_inicio A coluna (X) onde o navio começa.
 * @param tamanho O número de posições que o navio ocupa.
 * @param orientacao O tipo de orientação (HORIZONTAL, VERTICAL, 
 * DIAGONAL_DIREITA, DIAGONAL_ESQUERDA).
 * @return int Retorna 1 (sucesso) se o navio foi posicionado,
 * ou 0 (falha) se houver colisão ou sair dos limites.
 */
int posicionar_navio(int linha_inicio, int col_inicio, int tamanho, int orientacao);

// --- Função Principal (main) ---

int main() {
    printf("--- Batalha Naval: Desafio Nivel Aventureiro ---\n");

    // 1. Inicializa o tabuleiro com água (0)
    inicializar_tabuleiro();

    printf("Tabuleiro inicializado (so agua):\n");
    exibir_tabuleiro();
    printf("\n");

    // 2. Posiciona os Quatro Navios (coordenadas definidas no código)

    // --- Navios "Normais" ---
    
    // Navio 1: Horizontal, Tamanho 3, começando em (Linha 1, Coluna 1)
    // Ocupará: (1,1), (1,2), (1,3)
    printf("Posicionando Navio 1 (Horizontal) em (1, 1)...\n");
    posicionar_navio(1, 1, TAMANHO_NAVIO, HORIZONTAL);

    // Navio 2: Vertical, Tamanho 3, começando em (Linha 3, Coluna 8)
    // Ocupará: (3,8), (4,8), (5,8)
    printf("Posicionando Navio 2 (Vertical) em (3, 8)...\n");
    posicionar_navio(3, 8, TAMANHO_NAVIO, VERTICAL);

    // --- Novos Navios Diagonais ---
    
    // Navio 3: Diagonal (Baixo-Direita), Tamanho 3, começando em (3, 1)
    // Ocupará: (3,1), (4,2), (5,3)
    printf("Posicionando Navio 3 (Diagonal Direita) em (3, 1)...\n");
    posicionar_navio(3, 1, TAMANHO_NAVIO, DIAGONAL_DIREITA);

    // Navio 4: Diagonal (Baixo-Esquerda), Tamanho 3, começando em (7, 8)
    // Ocupará: (7,8), (8,7), (9,6)
    printf("Posicionando Navio 4 (Diagonal Esquerda) em (7, 8)...\n");
    posicionar_navio(7, 8, TAMANHO_NAVIO, DIAGONAL_ESQUERDA);

    /*
    // ---- TESTES DE VALIDACAO (Opcional) ----
    
    // Teste 1: Tentar sobrepor o Navio 3 (D_DR)
    printf("\nTentando posicionar navio sobreposto (deve falhar)...\n");
    posicionar_navio(2, 0, TAMANHO_NAVIO, DIAGONAL_DIREITA); // (2,0), (3,1), (4,2) -> Falha em (3,1) e (4,2)

    // Teste 2: Tentar colocar D_DR fora dos limites (coluna)
    printf("Tentando posicionar navio D_DR fora do limite (coluna)...\n");
    posicionar_navio(0, 8, TAMANHO_NAVIO, DIAGONAL_DIREITA); // (0,8), (1,9), (2,10) <- Falha

    // Teste 3: Tentar colocar D_DL fora dos limites (coluna)
    printf("Tentando posicionar navio D_DL fora do limite (coluna)...\n");
    posicionar_navio(0, 1, TAMANHO_NAVIO, DIAGONAL_ESQUERDA); // (0,1), (1,0), (2,-1) <- Falha
    */

    // 3. Exibe o tabuleiro final
    printf("\n--- Tabuleiro Final com Navios Posicionados ---\n");
    exibir_tabuleiro();

    return 0; // Indica que o programa terminou com sucesso
}

// --- Implementação das Funções ---

/**
 * @brief Inicializa todo o tabuleiro com o valor AGUA (0).
 */
void inicializar_tabuleiro() {
    // Loop externo: percorre as LINHAS (i)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Loop interno: percorre as COLUNAS (j) para cada linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 */
void exibir_tabuleiro() {
    // Imprime cabeçalho das colunas (0 a 9)
    printf("   "); 
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n"); 
    
    // Imprime linha separadora
    printf("   ---------------------\n");

    // Loop externo: percorre as LINHAS (i)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Imprime o cabeçalho da linha (0 a 9)
        printf("%d | ", i);
        
        // Loop interno: percorre as COLUNAS (j)
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Imprime o valor da célula (0 ou 3)
            printf("%d ", tabuleiro[i][j]);
        }
        // Ao final de cada linha, pula para a próxima
        printf("\n");
    }
}

/**
 * @brief Tenta posicionar um navio no tabuleiro (VERSÃO AVENTUREIRO).
 */
int posicionar_navio(int linha_inicio, int col_inicio, int tamanho, int orientacao) {
    
    // --- ETAPA 1: Validação de Limites ---
    // Verifica se o navio cabe DENTRO do tabuleiro
    // Usamos um switch para tratar cada orientação
    
    switch (orientacao) {
        case HORIZONTAL:
            if (col_inicio + tamanho > TAMANHO_TABULEIRO) {
                printf("Erro: Navio horizontal em (%d, %d) sai do limite (coluna).\n", linha_inicio, col_inicio);
                return 0; // Falha
            }
            break;
            
        case VERTICAL:
            if (linha_inicio + tamanho > TAMANHO_TABULEIRO) {
                printf("Erro: Navio vertical em (%d, %d) sai do limite (linha).\n", linha_inicio, col_inicio);
                return 0; // Falha
            }
            break;

        case DIAGONAL_DIREITA:
            // Precisa checar AMBOS os limites (linha E coluna)
            if (linha_inicio + tamanho > TAMANHO_TABULEIRO || col_inicio + tamanho > TAMANHO_TABULEIRO) {
                printf("Erro: Navio D_DIREITA em (%d, %d) sai dos limites.\n", linha_inicio, col_inicio);
                return 0; // Falha
            }
            break;

        case DIAGONAL_ESQUERDA:
            // Precisa checar limite da linha (para baixo) E coluna (para esquerda)
            // A coluna final será (col_inicio - (tamanho - 1))
            if (linha_inicio + tamanho > TAMANHO_TABULEIRO || (col_inicio - tamanho + 1) < 0) {
                 printf("Erro: Navio D_ESQUERDA em (%d, %d) sai dos limites.\n", linha_inicio, col_inicio);
                return 0; // Falha
            }
            break;
            
        default:
            printf("Erro: Orientacao desconhecida (%d).\n", orientacao);
            return 0; // Falha
    }

    // --- ETAPA 2: Validação de Sobreposição ---
    // Verifica se alguma posição desejada já está ocupada
    
    for (int i = 0; i < tamanho; i++) {
        int linha_atual, col_atual;

        // Calcula a célula [linha][coluna] a ser verificada
        switch (orientacao) {
            case HORIZONTAL:
                linha_atual = linha_inicio;
                col_atual = col_inicio + i;
                break;
            case VERTICAL:
                linha_atual = linha_inicio + i;
                col_atual = col_inicio;
                break;
            case DIAGONAL_DIREITA:
                linha_atual = linha_inicio + i;
                col_atual = col_inicio + i;
                break;
            case DIAGONAL_ESQUERDA:
                linha_atual = linha_inicio + i;
                col_atual = col_inicio - i;
                break;
        }

        // Agora verifica a célula calculada
        if (tabuleiro[linha_atual][col_atual] == NAVIO) {
            printf("Erro: Sobreposicao detectada em (%d, %d)!\n", linha_atual, col_atual);
            return 0; // Falha
        }
    }

    // --- ETAPA 3: Posicionamento ---
    // Se passou nas duas validações, podemos posicionar o navio

    for (int i = 0; i < tamanho; i++) {
        switch (orientacao) {
            case HORIZONTAL:
                tabuleiro[linha_inicio][col_inicio + i] = NAVIO;
                break;
            case VERTICAL:
                tabuleiro[linha_inicio + i][col_inicio] = NAVIO;
                break;
            case DIAGONAL_DIREITA:
                tabuleiro[linha_inicio + i][col_inicio + i] = NAVIO;
                break;
            case DIAGONAL_ESQUERDA:
                tabuleiro[linha_inicio + i][col_inicio - i] = NAVIO;
                break;
        }
    }

    printf("Navio (orientacao %d) posicionado com sucesso em (%d, %d).\n", orientacao, linha_inicio, col_inicio);
    return 1; // Sucesso!
}
