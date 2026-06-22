// Feito por Douglas Alves Costa
// Nivel Aventureiro

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ALGORITMOS EM GRAFOS - Desafio RoboRouter (RescueBotics)
// Nivel Aventureiro: Busca pela vitima usando DFS

#define MAX_VERTICES 10

int grafo[MAX_VERTICES][MAX_VERTICES];
int num_vertices = 0;
bool visitados[MAX_VERTICES];
bool caminhoEncontrado = false;

void inicializarGrafo(int n) {
    num_vertices = n;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            grafo[i][j] = 0;
        }
    }
}

void adicionarAresta(int origem, int destino) {
    if (origem < 0 || origem >= num_vertices || destino < 0 || destino >= num_vertices) {
        printf("Erro: vertice invalido! Origem: %d | Destino: %d\n", origem, destino);
        return;
    }

    grafo[origem][destino] = 1;
    grafo[destino][origem] = 1;
}

void imprimirGrafo() {
    printf("--- Representacao do Labirinto (Matriz de Adjacencias) ---\n\n");

    printf("    ");
    for (int i = 0; i < num_vertices; i++) {
        printf("%d ", i);
    }

    printf("\n   ");
    for (int i = 0; i < num_vertices; i++) {
        printf("--");
    }

    printf("\n");

    for (int i = 0; i < num_vertices; i++) {
        printf("%d | ", i);

        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", grafo[i][j]);
        }

        printf("\n");
    }
}

void exibirConexoes() {
    printf("\n--- Caminhos livres entre os cruzamentos ---\n");

    for (int i = 0; i < num_vertices; i++) {
        printf("Cruzamento %d conectado com: ", i);

        int possuiConexao = 0;

        for (int j = 0; j < num_vertices; j++) {
            if (grafo[i][j] == 1) {
                printf("%d ", j);
                possuiConexao = 1;
            }
        }

        if (!possuiConexao) {
            printf("nenhum");
        }

        printf("\n");
    }
}

void inicializarVisitados() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visitados[i] = false;
    }
}

void buscaProfundidade(int verticeAtual, int destino) {
    visitados[verticeAtual] = true;

    printf("%d ", verticeAtual);

    if (verticeAtual == destino) {
        caminhoEncontrado = true;
        return;
    }

    for (int i = 0; i < num_vertices; i++) {
        if (grafo[verticeAtual][i] == 1 && !visitados[i]) {
            buscaProfundidade(i, destino);

            if (caminhoEncontrado) {
                return;
            }
        }
    }
}

int validarVertice(int vertice) {
    return vertice >= 0 && vertice < num_vertices;
}

int main() {
    int origem, destino;

    printf("=== RESCUE BOTICS: ROBOROUTER ===\n");
    printf("=== NIVEL AVENTUREIRO - A BUSCA PELA VITIMA ===\n\n");

    inicializarGrafo(6);

    adicionarAresta(0, 1);
    adicionarAresta(0, 2);
    adicionarAresta(1, 3);
    adicionarAresta(2, 3);
    adicionarAresta(2, 4);
    adicionarAresta(3, 5);
    adicionarAresta(4, 5);

    imprimirGrafo();
    exibirConexoes();

    printf("\nDigite o vertice de origem: ");
    scanf("%d", &origem);

    printf("Digite o vertice de destino: ");
    scanf("%d", &destino);

    if (!validarVertice(origem) || !validarVertice(destino)) {
        printf("\nErro: origem ou destino invalido.\n");
        printf("Use vertices entre 0 e %d.\n", num_vertices - 1);
        return 1;
    }

    inicializarVisitados();
    caminhoEncontrado = false;

    printf("\n--- Ordem dos vertices visitados pela DFS ---\n");
    buscaProfundidade(origem, destino);

    printf("\n\n--- Resultado da busca ---\n");

    if (caminhoEncontrado) {
        printf("Existe um caminho possivel entre o vertice %d e o vertice %d.\n", origem, destino);
        printf("Vitima localizada com sucesso pelo RoboRouter!\n");
    } else {
        printf("Nao existe caminho possivel entre o vertice %d e o vertice %d.\n", origem, destino);
        printf("O RoboRouter nao conseguiu alcancar a vitima por essa rota.\n");
    }

    return 0;
}