// Feito por Douglas Alves Costa
// Nivel Novato

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ALGORITMOS EM GRAFOS - Desafio RoboRouter (RescueBotics)
// Nivel Novato: Representacao do labirinto usando Matriz de Adjacencias

#define MAX_VERTICES 10

int grafo[MAX_VERTICES][MAX_VERTICES];
int num_vertices = 0;

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

int main() {
    printf("=== RESCUE BOTICS: ROBOROUTER ===\n");
    printf("=== NIVEL NOVATO - MAPEANDO OS ESCOMBROS ===\n\n");

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

    printf("\nLabirinto armazenado com sucesso na memoria do RoboRouter!\n");

    return 0;
}