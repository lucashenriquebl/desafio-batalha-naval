/*
 * Desafio: Nível Mestre - Habilidades Especiais e Áreas de Efeito
 * Autor: Lucas Bittencourt
 * Data: 27/10/2025
 *
 * Descrição: Este programa evolui o jogo de Batalha Naval para incluir
 * a visualização de habilidades especiais (Cone, Cruz, Octaedro).
 *
 * O programa faz o seguinte:
 * 1. Inicializa o tabuleiro 10x10.
 * 2. Posiciona alguns navios (do Nível 2) para referência.
 * 3. Cria "matrizes de habilidade" 5x5 dinamicamente usando loops e
 * condicionais, marcando a área de efeito com '1'.
 * 4. Aplica essas habilidades (sobrepõe) no tabuleiro principal,
 * centradas em coordenadas específicas.
 * 5. Marca a área de efeito no tabuleiro principal com o valor '5'.
 * 6. Exibe o tabuleiro final com Água(0), Navios(3) e Habilidades(5).
 */

#include <stdio.h>
#include <stdlib.h> // Necessário para a função abs() (Octaedro)

// --- Constantes Globais (Tabuleiro) ---
#define TAMANHO_TABULEIRO 10
#define AGUA 0
#define NAVIO 3

// --- Constantes Globais (Navios - do Nível 2) ---
#define TAMANHO_NAVIO 3
#define HORIZONTAL 0
#define VERTICAL 1
#define DIAGONAL_DIREITA 2
#define DIAGONAL_ESQUERDA 3

// --- NOVAS Constantes Globais (Habilidades) ---
#define HABILIDADE 5       // Valor para marcar a área de efeito no tabuleiro
#define TAMANHO_HABILIDADE 5 // Tamanho fixo das matrizes de habilidade (5x5)

// --- Variáveis Globais ---
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// --- Protótipos das Funções (Jogo) ---
void inicializar_tabuleiro();
void exibir_tabuleiro();
int posicionar_navio(int linha_inicio, int col_inicio, int tamanho, int orientacao);

// --- NOVOS Protótipos de Funções (Habilidades) ---

/**
 * @brief Exibe uma matriz de habilidade 5x5 (função auxiliar para debug).
 */
void exibir_matriz_habilidade(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

/**
 * @brief Cria uma matriz de habilidade 5x5 com formato de CONE.
 * O cone aponta para baixo, com a ponta no centro da matriz.
 * Requisito: Usa loops aninhados e condicionais.
 */
void criar_matriz_cone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

/**
 * @brief Cria uma matriz de habilidade 5x5 com formato de CRUZ.
 * A cruz é centrada na matriz.
 * Requisito: Usa loops aninhados e condicionais.
 */
void criar_matriz_cruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

/**
 * @brief Cria uma matriz de habilidade 5x5 com formato de OCTAEDRO (Losango).
 * O losango é centrado na matriz.
 * Requisito: Usa loops aninhados e condicionais.
 */
void criar_matriz_octaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

/**
 * @brief Sobrepõe uma matriz de habilidade no tabuleiro principal.
 *
 * @param linha_origem Linha do tabuleiro onde o CENTRO (2,2) da
 * matriz de habilidade será posicionado.
 * @param col_origem Coluna do tabuleiro onde o CENTRO (2,2) da
 * matriz de habilidade será posicionado.
 * @param matriz_habilidade A matriz 5x5 (cone, cruz, etc.) a ser aplicada.
 */
void aplicar_habilidade(int linha_origem, int col_origem, int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]);

// --- Função Principal (main) ---

int main() {
    printf("--- Batalha Naval: Desafio Nivel Mestre ---\n\n");

    // 1. Inicializa o tabuleiro
    inicializar_tabuleiro();

    // 2. Posiciona alguns navios (do Nível 2) para termos algo no tabuleiro
    posicionar_navio(1, 1, TAMANHO_NAVIO, HORIZONTAL);
    posicionar_navio(3, 8, TAMANHO_NAVIO, VERTICAL);
    posicionar_navio(3, 1, TAMANHO_NAVIO, DIAGONAL_DIREITA);
    posicionar_navio(7, 8, TAMANHO_NAVIO, DIAGONAL_ESQUERDA);

    printf("--- Tabuleiro Inicial com Navios ---\n");
    exibir_tabuleiro();

    // 3. Criar Matrizes de Habilidade
    printf("\n--- Criando Matrizes de Habilidade (Templates 5x5) ---\n");
    
    // Declara as matrizes que servirão de "template"
    int matriz_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int matriz_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Preenche as matrizes usando as funções
    criar_matriz_cone(matriz_cone);
    criar_matriz_cruz(matriz_cruz);
    criar_matriz_octaedro(matriz_octaedro);

    // Exibe os templates criados (para verificação)
    printf("Template CONE (ponta em 2,2):\n");
    exibir_matriz_habilidade(matriz_cone);

    printf("\nTemplate CRUZ (centro em 2,2):\n");
    exibir_matriz_habilidade(matriz_cruz);

    printf("\nTemplate OCTAEDRO (centro em 2,2):\n");
    exibir_matriz_habilidade(matriz_octaedro);

    // 4. Integrar Habilidades ao Tabuleiro
    printf("\n--- Aplicando Habilidades ao Tabuleiro ---\n");

    // Aplicar a CRUZ na origem (2, 2) do tabuleiro
    // O centro (2,2) da matriz-cruz será colocado em (2,2) do tabuleiro
    printf("Aplicando CRUZ com centro em (2, 2)...\n");
    aplicar_habilidade(2, 2, matriz_cruz);

    // Aplicar o CONE na origem (7, 5) do tabuleiro
    // A ponta do cone (centro 2,2 da matriz) estará em (7,5) do tabuleiro
    printf("Aplicando CONE com ponta em (7, 5)...\n");
    aplicar_habilidade(7, 5, matriz_cone);

    // Aplicar o OCTAEDRO na origem (4, 7) do tabuleiro
    // O centro (2,2) da matriz-octaedro estará em (4,7) do tabuleiro
    // Isso deve sobrepor o navio vertical em (4,8)
    printf("Aplicando OCTAEDRO com centro em (4, 7)...\n");
    aplicar_habilidade(4, 7, matriz_octaedro);


    // 5. Exibir o Tabuleiro Final
    printf("\n--- Tabuleiro Final com Habilidades Aplicadas ---\n");
    printf("Legenda: 0=Agua, 3=Navio, 5=Habilidade\n");
    exibir_tabuleiro();

    return 0;
}


// --- Implementação das Funções (Habilidades) ---

/**
 * @brief Cria uma matriz de habilidade 5x5 com formato de CONE.
 */
void criar_matriz_cone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Define o ponto central (onde a ponta do cone estará)
    int centro = TAMANHO_HABILIDADE / 2; // (Para 5x5, centro = 2)

    // Loop aninhado para construir a matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condição para o cone:
            // 1. A linha (i) deve estar no centro ou abaixo dele.
            // 2. O cone se expande para os lados conforme a linha (i) aumenta.
            
            if (i >= centro) {
                // offset_linha: 0 na linha do centro, 1 na prox, 2 na prox...
                int offset_linha = i - centro;
                
                // Condicional: A coluna (j) está dentro da expansão do cone?
                if (j >= (centro - offset_linha) && j <= (centro + offset_linha)) {
                    matriz[i][j] = 1; // 1 = Afetado
                } else {
                    matriz[i][j] = 0; // 0 = Não Afetado
                }
            } else {
                // Linhas acima do centro (ponta do cone) não são afetadas
                matriz[i][j] = 0;
            }
        }
    }
}

/**
 * @brief Cria uma matriz de habilidade 5x5 com formato de CRUZ.
 */
void criar_matriz_cruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // (centro = 2)

    // Loop aninhado para construir a matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condicional: A posição [i][j] está na linha central OU
            // na coluna central?
            if (i == centro || j == centro) {
                matriz[i][j] = 1; // Afetado
            } else {
                matriz[i][j] = 0; // Não Afetado
            }
        }
    }
}

/**
 * @brief Cria uma matriz de habilidade 5x5 com formato de OCTAEDRO (Losango).
 */
void criar_matriz_octaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // (centro = 2)

    // Loop aninhado para construir a matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // Condicional: Usa a "Distância de Manhattan"
            // (distancia em linha + distancia em coluna)
            // Se a distância do centro for <= ao raio (centro), está dentro.
            int dist = abs(i - centro) + abs(j - centro);
            
            if (dist <= centro) {
                matriz[i][j] = 1; // Afetado
            } else {
                matriz[i][j] = 0; // Não Afetado
            }
        }
    }
}

/**
 * @brief Sobrepõe uma matriz de habilidade 5x5 no tabuleiro principal 10x10.
 */
void aplicar_habilidade(int linha_origem, int col_origem, int matriz_habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    
    int centro = TAMANHO_HABILIDADE / 2; // (centro = 2)

    // Loop aninhado para percorrer a MATRIZ DE HABILIDADE (5x5)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            
            // 1. Verifica se esta parte da habilidade afeta algo (== 1)
            if (matriz_habilidade[i][j] == 1) {
                
                // 2. Calcula a coordenada correspondente no TABULEIRO
                // (i - centro) dá o offset da linha (ex: -2, -1, 0, 1, 2)
                int linha_tabuleiro = linha_origem + (i - centro);
                int col_tabuleiro = col_origem + (j - centro);

                // 3. Validação de Limites (Condicional)
                // Verifica se a coordenada calculada está DENTRO do tabuleiro 10x10
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    col_tabuleiro >= 0 && col_tabuleiro < TAMANHO_TABULEIRO) 
                {
                    // 4. Aplica a habilidade no tabuleiro
                    // Nota: Isso sobrepõe ÁGUA(0) e também NAVIO(3)
                    tabuleiro[linha_tabuleiro][col_tabuleiro] = HABILIDADE;
                }
            }
            // Se matriz_habilidade[i][j] == 0, não faz nada.
        }
    }
}


// --- Funções Auxiliares (Debug e Jogo Básico) ---

/**
 * @brief Exibe uma matriz de habilidade 5x5 (função auxiliar para debug).
 */
void exibir_matriz_habilidade(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("   "); // Indentação
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


/**
 * @brief Inicializa todo o tabuleiro com o valor AGUA (0).
 */
void inicializar_tabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

/**
 * @brief Exibe o estado atual do tabuleiro (imprime 0, 3 ou 5).
 */
void exibir_tabuleiro() {
    printf("   "); 
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n   ---------------------\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d | ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Tenta posicionar um navio no tabuleiro (do Nível 2).
 */
int posicionar_navio(int linha_inicio, int col_inicio, int tamanho, int orientacao) {
    // Validação de Limites
    switch (orientacao) {
        case HORIZONTAL:
            if (col_inicio + tamanho > TAMANHO_TABULEIRO) return 0;
            break;
        case VERTICAL:
            if (linha_inicio + tamanho > TAMANHO_TABULEIRO) return 0;
            break;
        case DIAGONAL_DIREITA:
            if (linha_inicio + tamanho > TAMANHO_TABULEIRO || col_inicio + tamanho > TAMANHO_TABULEIRO) return 0;
            break;
        case DIAGONAL_ESQUERDA:
            if (linha_inicio + tamanho > TAMANHO_TABULEIRO || (col_inicio - tamanho + 1) < 0) return 0;
            break;
    }

    // Validação de Sobreposição (simplificada para este exemplo, não checa outras posições)
    // Posicionamento
    for (int i = 0; i < tamanho; i++) {
        switch (orientacao) {
            case HORIZONTAL:
                tabuleiro[linha_inicio][col_inicio + i] = NAVIO; break;
            case VERTICAL:
                tabuleiro[linha_inicio + i][col_inicio] = NAVIO; break;
            case DIAGONAL_DIREITA:
                tabuleiro[linha_inicio + i][col_inicio + i] = NAVIO; break;
            case DIAGONAL_ESQUERDA:
                tabuleiro[linha_inicio + i][col_inicio - i] = NAVIO; break;
        }
    }
    return 1; // Sucesso
}
