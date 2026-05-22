/*
 * Aula 06 - Grafos
 * 3. Grafo PONDERADO, NAO DIRECIONAL - Matriz de Adjacencias
 */
#include <stdio.h>
#include <stdlib.h>

#define SEM_ARESTA 0

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
            g->adj[i][j] = SEM_ARESTA;
    }
    return g;
}

int criarAresta(GRAFO *gr, int vi, int vf, int peso) {
    if (!gr) return 0;
    if (vi < 0 || vi >= gr->vertices) return 0;
    if (vf < 0 || vf >= gr->vertices) return 0;
    gr->adj[vi][vf] = peso;
    gr->adj[vf][vi] = peso; /* nao direcional */
    gr->aresta++;
    return 1;
}

int removerAresta(GRAFO *gr, int vi, int vf) {
    if (!gr) return 0;
    if (vi < 0 || vi >= gr->vertices) return 0;
    if (vf < 0 || vf >= gr->vertices) return 0;
    if (gr->adj[vi][vf] == SEM_ARESTA) return 0;
    gr->adj[vi][vf] = SEM_ARESTA;
    gr->adj[vf][vi] = SEM_ARESTA;
    gr->aresta--;
    return 1;
}

int existeAresta(GRAFO *gr, int vi, int vf) {
    return gr->adj[vi][vf] != SEM_ARESTA;
}

int pesoAresta(GRAFO *gr, int vi, int vf) {
    return gr->adj[vi][vf];
}

int grau(GRAFO *gr, int v) {
    int g = 0;
    for (int i = 0; i < gr->vertices; i++)
        if (gr->adj[v][i] != SEM_ARESTA) g++;
    return g;
}

void imprimir(GRAFO *gr) {
    printf("Vertices: %d. Arestas: %d.\n", gr->vertices, gr->aresta);
    printf("       ");
    for (int j = 0; j < gr->vertices; j++) printf(" v%-2d", j);
    printf("\n");
    for (int i = 0; i < gr->vertices; i++) {
        printf("v%-2d:  ", i);
        for (int j = 0; j < gr->vertices; j++)
            printf(" %3d", gr->adj[i][j]);
        printf("\n");
    }
}

void dfsAux(GRAFO *gr, int v, int *vis) {
    vis[v] = 1;
    printf("v%d ", v);
    for (int i = 0; i < gr->vertices; i++)
        if (gr->adj[v][i] != SEM_ARESTA && !vis[i])
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
            if (gr->adj[v][j] != SEM_ARESTA && !vis[j]) {
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
    /* Exemplo dos slides: V1-V3=10, V1-V2=2, V2-V3=5, V2-V4=8 */
    GRAFO *gr = criarGrafo(4);
    criarAresta(gr, 0, 1, 2);
    criarAresta(gr, 0, 2, 10);
    criarAresta(gr, 1, 2, 5);
    criarAresta(gr, 1, 3, 8);

    imprimir(gr);
    printf("Peso (0,2): %d\n", pesoAresta(gr, 0, 2));
    printf("Grau v1: %d\n", grau(gr, 1));
    buscaProfundidade(gr, 0);
    buscaLargura(gr, 0);

    removerAresta(gr, 0, 2);
    printf("\nApos remover (0,2):\n");
    imprimir(gr);

    liberar(gr);
    return 0;
}
