/*
 * Aula 06 - Grafos
 * 1. Grafo NAO PONDERADO, NAO DIRECIONAL - Matriz de Adjacencias
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
    int vertices;
    int aresta;
    int **adj;
} GRAFO;

GRAFO* criarGrafo(int v) {
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
    g->vertices = v;
    g->aresta = 0;
    g->adj = (int **) malloc(v * sizeof(int *));
    for (int i = 0; i < v; i++) {
        g->adj[i] = (int *) malloc(v * sizeof(int));
        for (int j = 0; j < v; j++)
            g->adj[i][j] = 0;
    }
    return g;
}

int criarAresta(GRAFO *gr, int vi, int vf) {
    if (!gr) return 0;
    if (vi < 0 || vi >= gr->vertices) return 0;
    if (vf < 0 || vf >= gr->vertices) return 0;
    gr->adj[vi][vf] = 1;
    gr->adj[vf][vi] = 1; /* nao direcional */
    gr->aresta++;
    return 1;
}

int removerAresta(GRAFO *gr, int vi, int vf) {
    if (!gr) return 0;
    if (vi < 0 || vi >= gr->vertices) return 0;
    if (vf < 0 || vf >= gr->vertices) return 0;
    if (gr->adj[vi][vf] == 0) return 0;
    gr->adj[vi][vf] = 0;
    gr->adj[vf][vi] = 0;
    gr->aresta--;
    return 1;
}

int existeAresta(GRAFO *gr, int vi, int vf) {
    return gr->adj[vi][vf] == 1;
}

int grau(GRAFO *gr, int v) {
    int g = 0;
    for (int i = 0; i < gr->vertices; i++)
        if (gr->adj[v][i] == 1) g++;
    return g;
}

void imprimir(GRAFO *gr) {
    printf("Vertices: %d. Arestas: %d.\n", gr->vertices, gr->aresta);
    printf("     ");
    for (int j = 0; j < gr->vertices; j++) printf("v%d ", j);
    printf("\n");
    for (int i = 0; i < gr->vertices; i++) {
        printf("v%d:  ", i);
        for (int j = 0; j < gr->vertices; j++)
            printf(" %d ", gr->adj[i][j]);
        printf("\n");
    }
}

void dfsAux(GRAFO *gr, int v, int *vis) {
    vis[v] = 1;
    printf("v%d ", v);
    for (int i = 0; i < gr->vertices; i++)
        if (gr->adj[v][i] == 1 && !vis[i])
            dfsAux(gr, i, vis);
}

void buscaProfundidade(GRAFO *gr, int ini) {
    int *vis = (int *) calloc(gr->vertices, sizeof(int));
    printf("DFS: ");
    dfsAux(gr, ini, vis);
    printf("\n");
    free(vis);
}

void buscaLargura(GRAFO *gr, int ini) {
    int *vis = (int *) calloc(gr->vertices, sizeof(int));
    int *fila = (int *) malloc(gr->vertices * sizeof(int));
    int i = 0, f = 0;
    vis[ini] = 1;
    fila[f++] = ini;
    printf("BFS: ");
    while (i < f) {
        int v = fila[i++];
        printf("v%d ", v);
        for (int j = 0; j < gr->vertices; j++) {
            if (gr->adj[v][j] == 1 && !vis[j]) {
                vis[j] = 1;
                fila[f++] = j;
            }
        }
    }
    printf("\n");
    free(vis); free(fila);
}

void liberar(GRAFO *gr) {
    for (int i = 0; i < gr->vertices; i++) free(gr->adj[i]);
    free(gr->adj);
    free(gr);
}

int main(void) {
    GRAFO *gr = criarGrafo(5);
    criarAresta(gr, 0, 1);
    criarAresta(gr, 0, 2);
    criarAresta(gr, 1, 2);
    criarAresta(gr, 1, 3);
    criarAresta(gr, 2, 4);
    criarAresta(gr, 3, 4);

    imprimir(gr);
    printf("Grau v0: %d\n", grau(gr, 0));
    printf("Existe (1,3)? %s\n", existeAresta(gr, 1, 3) ? "sim" : "nao");
    buscaProfundidade(gr, 0);
    buscaLargura(gr, 0);

    removerAresta(gr, 1, 3);
    printf("\nApos remover (1,3):\n");
    imprimir(gr);

    liberar(gr);
    return 0;
}
