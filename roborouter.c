// Feito por Douglas Alves Costa
// Nivel Mestre

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INFINITO 9999

// ==========================================================
// ALGORITMOS EM GRAFOS - RESCUE BOTICS: ROBOROUTER
// NIVEL MESTRE - CAMINHO MINIMO COM DIJKSTRA
// ==========================================================

int grafo[MAX_VERTICES][MAX_VERTICES];
int num_vertices = 0;

void inicializarGrafo(int n) {
    num_vertices = n;

    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {

            if (i == j) {
                grafo[i][j] = 0;
            } else {
                grafo[i][j] = INFINITO;
            }
        }
    }
}

void adicionarAresta(int origem, int destino, int peso) {

    if (origem < 0 || origem >= num_vertices ||
        destino < 0 || destino >= num_vertices) {

        printf("Erro: vertice invalido!\n");
        return;
    }

    grafo[origem][destino] = peso;
    grafo[destino][origem] = peso;
}

void imprimirGrafo() {

    printf("\n=== MATRIZ DE ADJACENCIAS PONDERADA ===\n\n");

    printf("    ");

    for (int i = 0; i < num_vertices; i++) {
        printf("%4d", i);
    }

    printf("\n");

    for (int i = 0; i < num_vertices; i++) {

        printf("%2d |", i);

        for (int j = 0; j < num_vertices; j++) {

            if (grafo[i][j] == INFINITO) {
                printf("%4s", "-");
            } else {
                printf("%4d", grafo[i][j]);
            }
        }

        printf("\n");
    }
}

int encontrarMenorDistancia(
    int distancias[],
    bool processados[]
) {
    int menor = INFINITO;
    int indice = -1;

    for (int i = 0; i < num_vertices; i++) {

        if (!processados[i] &&
            distancias[i] < menor) {

            menor = distancias[i];
            indice = i;
        }
    }

    return indice;
}

void imprimirCaminho(
    int antecessores[],
    int destino
) {

    if (antecessores[destino] == -1) {
        printf("%d", destino);
        return;
    }

    imprimirCaminho(
        antecessores,
        antecessores[destino]
    );

    printf(" -> %d", destino);
}

void dijkstra(
    int origem,
    int destino
) {

    int distancias[MAX_VERTICES];
    int antecessores[MAX_VERTICES];
    bool processados[MAX_VERTICES];

    for (int i = 0; i < num_vertices; i++) {

        distancias[i] = INFINITO;
        antecessores[i] = -1;
        processados[i] = false;
    }

    distancias[origem] = 0;

    for (int i = 0; i < num_vertices - 1; i++) {

        int atual = encontrarMenorDistancia(
            distancias,
            processados
        );

        if (atual == -1) {
            break;
        }

        processados[atual] = true;

        for (int vizinho = 0;
             vizinho < num_vertices;
             vizinho++) {

            if (!processados[vizinho] &&
                grafo[atual][vizinho] != INFINITO &&
                distancias[atual] != INFINITO &&
                distancias[atual] + grafo[atual][vizinho]
                < distancias[vizinho]) {

                distancias[vizinho] =
                    distancias[atual] +
                    grafo[atual][vizinho];

                antecessores[vizinho] = atual;
            }
        }
    }

    printf("\n=== RESULTADO DO DIJKSTRA ===\n\n");

    if (distancias[destino] == INFINITO) {

        printf("Nao existe rota entre %d e %d.\n",
               origem,
               destino);

        return;
    }

    printf("Rota ideal: ");

    imprimirCaminho(
        antecessores,
        destino
    );

    printf("\n");

    printf("Distancia total: %d metros\n",
           distancias[destino]);
}

// ==========================================================
// FUNCAO PRINCIPAL
// ==========================================================

int main() {

    int origem;
    int destino;

    printf("====================================\n");
    printf(" RESCUE BOTICS - ROBOROUTER\n");
    printf(" NIVEL MESTRE\n");
    printf("====================================\n");

    inicializarGrafo(6);

    /*
        LABIRINTO

            (1)
          4/   \2
          /     \
        (0)     (3)
          \3   /1
           \ /
           (2)
            |
           5|
            |
           (4)
            |
           2|
            |
           (5)
    */

    adicionarAresta(0, 1, 4);
    adicionarAresta(0, 2, 3);
    adicionarAresta(1, 3, 2);
    adicionarAresta(2, 3, 1);
    adicionarAresta(2, 4, 5);
    adicionarAresta(4, 5, 2);

    imprimirGrafo();

    printf("\nDigite o vertice de origem: ");
    scanf("%d", &origem);

    printf("Digite o vertice de destino: ");
    scanf("%d", &destino);

    if (origem < 0 || origem >= num_vertices ||
        destino < 0 || destino >= num_vertices) {

        printf("\nErro: vertice invalido.\n");
        return 1;
    }

    dijkstra(origem, destino);

    printf("\n\nMissao concluida pelo RoboRouter!\n");

    return 0;
}