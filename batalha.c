/*
 * Desafio: Nível Novato - Posicionando Navios no Tabuleiro
 * Autor: Lucas Bittencourt
 * Data: 27/10/2025
 *
 * Descrição: Este programa inicializa um tabuleiro de Batalha Naval 10x10,
 * posiciona dois navios (tamanho 3) de forma hardcoded (um horizontal,
 * um vertical) e exibe o tabuleiro resultante no console.
 *
 * Requisitos Atendidos:
 * 1. Matriz 10x10 inicializada com 0 (AGUA).
 * 2. Navios (valor 3) posicionados (1 horizontal, 1 vertical).
 * 3. Validação de limites (dentro da função posicionar_navio).
 * 4. Validação de sobreposição (dentro da função posicionar_navio).
 * 5. Exibição do tabuleiro no console.
 * 6. Código documentado e legível.
 */

#include <stdio.h>

// --- Constantes Globais (Definições) ---

// Define o tamanho do tabuleiro (10x10)
#define TAMANHO_TABULEIRO 10
// Define o tamanho fixo dos navios deste desafio
#define TAMANHO_NAVIO 3

// Define os valores para representar água e navio no tabuleiro
// Usar constantes torna o código mais legível
#define AGUA 0
#define NAVIO 3

// --- Variáveis Globais ---

// Declara a matriz (array bidimensional) que representa o tabuleiro
// [linhas][colunas]
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// --- Protótipos das Funções ---
// Declarar as funções antes do main() é uma boa prática em C

/**
 * @brief Inicializa todo o tabuleiro com o valor AGUA (0).
 */
void inicializar_tabuleiro();

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 */
void exibir_tabuleiro();

/**
 * @brief Tenta posicionar um navio no tabuleiro.
 *
 * @param linha_inicio A linha (Y) onde o navio começa.
 * @param col_inicio A coluna (X) onde o navio começa.
 * @param tamanho O número de posições que o navio ocupa.
 * @param horizontal 1 se for horizontal, 0 se for vertical.
 * @return int Retorna 1 (sucesso) se o navio foi posicionado,
 * ou 0 (falha) se houver colisão ou sair dos limites.
 */
int posicionar_navio(int linha_inicio, int col_inicio, int tamanho, int horizontal);

// --- Função Principal (main) ---

int main() {
    printf("--- Batalha Naval: Desafio Nivel Novato ---\n");

    // 1. Inicializa o tabuleiro com água (0)
    inicializar_tabuleiro();

    printf("Tabuleiro inicializado (so agua):\n");
    // Exibe o tabuleiro vazio para verificação
    exibir_tabuleiro();
    printf("\n");

    // 2. Posiciona os Navios (coordenadas definidas no código)

    // Navio 1: Horizontal, Tamanho 3, começando em (Linha 2, Coluna 3)
    // Ocupará as posições: (2,3), (2,4), (2,5)
    printf("Posicionando Navio 1 (Horizontal) em (2, 3)...\n");
    // Chamamos a função de posicionamento
    // (linha 2, coluna 3, tamanho 3, horizontal = 1)
    posicionar_navio(2, 3, TAMANHO_NAVIO, 1);

    // Navio 2: Vertical, Tamanho 3, começando em (Linha 5, Coluna 5)
    // Ocupará as posições: (5,5), (6,5), (7,5)
    printf("Posicionando Navio 2 (Vertical) em (5, 5)...\n");
    // Chamamos a função de posicionamento
    // (linha 5, coluna 5, tamanho 3, horizontal = 0 [vertical])
    posicionar_navio(5, 5, TAMANHO_NAVIO, 0);

    /*
    // ---- TESTES DE VALIDACAO (Opcional, descomente para testar) ----
    
    // Teste 1: Tentar sobrepor o Navio 1 (deve falhar)
    // Tenta colocar um navio vertical em (1, 4), que cruzaria (2, 4)
    printf("\nTentando posicionar navio sobreposto (deve falhar)...\n");
    posicionar_navio(1, 4, TAMANHO_NAVIO, 0); // (1,4), (2,4), (3,4)

    // Teste 2: Tentar colocar fora dos limites (deve falhar)
    // Tenta colocar um navio horizontal em (8, 8)
    // Ocuparia (8,8), (8,9), (8,10) <- Coluna 10 está fora (índices 0-9)
    printf("Tentando posicionar navio fora dos limites (deve falhar)...\n");
    posicionar_navio(8, 8, TAMANHO_NAVIO, 1);
    
    // ---------------------------------------------------------------
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
    // Loop aninhado para percorrer todas as posições da matriz

    // Loop externo: percorre as LINHAS (i)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Loop interno: percorre as COLUNAS (j) para cada linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            // Define o valor da célula [linha][coluna] como AGUA
            tabuleiro[i][j] = AGUA;
        }
    }
}

/**
 * @brief Exibe o estado atual do tabuleiro no console.
 */
void exibir_tabuleiro() {
    // Imprime cabeçalho das colunas (0 a 9)
    printf("   "); // Espaçamento para alinhar com os números das linhas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n"); // Quebra de linha
    
    // Imprime linha separadora
    printf("   ---------------------\n");

    // Loop aninhado para percorrer e imprimir a matriz

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
 * @brief Tenta posicionar um navio no tabuleiro.
 */
int posicionar_navio(int linha_inicio, int col_inicio, int tamanho, int horizontal) {
    
    // --- ETAPA 1: Validação de Limites ---
    // Verifica se o navio cabe DENTRO do tabuleiro

    if (horizontal == 1) { // Se for horizontal
        // Verifica se a coluna inicial + tamanho ultrapassa o limite
        if (col_inicio + tamanho > TAMANHO_TABULEIRO) {
            printf("Erro: Navio horizontal em (%d, %d) sai dos limites do tabuleiro.\n", linha_inicio, col_inicio);
            return 0; // Falha
        }
    } else { // Se for vertical
        // Verifica se a linha inicial + tamanho ultrapassa o limite
        if (linha_inicio + tamanho > TAMANHO_TABULEIRO) {
            printf("Erro: Navio vertical em (%d, %d) sai dos limites do tabuleiro.\n", linha_inicio, col_inicio);
            return 0; // Falha
        }
    }

    // --- ETAPA 2: Validação de Sobreposição ---
    // Verifica se alguma posição desejada já está ocupada por outro NAVIO

    // Loop para verificar cada célula que o navio ocuparia
    for (int i = 0; i < tamanho; i++) {
        if (horizontal == 1) { // Movendo pela coluna
            // Se a célula [linha_inicio][col_inicio + i] já for NAVIO
            if (tabuleiro[linha_inicio][col_inicio + i] == NAVIO) {
                printf("Erro: Sobreposicao detectada em (%d, %d)!\n", linha_inicio, col_inicio + i);
                return 0; // Falha
            }
        } else { // Movendo pela linha
            // Se a célula [linha_inicio + i][col_inicio] já for NAVIO
            if (tabuleiro[linha_inicio + i][col_inicio] == NAVIO) {
                printf("Erro: Sobreposicao detectada em (%d, %d)!\n", linha_inicio + i, col_inicio);
                return 0; // Falha
            }
        }
    }

    // --- ETAPA 3: Posicionamento ---
    // Se passou nas duas validações, podemos posicionar o navio

    // Loop para "desenhar" o navio no tabuleiro
    for (int i = 0; i < tamanho; i++) {
        // A "dica" do desafio é implementada aqui:
        // "copiando o valor 3 [...] para as posições correspondentes na matriz"
        
        if (horizontal == 1) { // Posição horizontal
            tabuleiro[linha_inicio][col_inicio + i] = NAVIO;
        } else { // Posição vertical
            tabuleiro[linha_inicio + i][col_inicio] = NAVIO;
        }
    }

    printf("Navio posicionado com sucesso em (%d, %d).\n", linha_inicio, col_inicio);
    return 1; // Sucesso!
}
