/*
 * Aula 06 - Grafos
 * 6. Grafo PONDERADO, DIRECIONAL - Lista de Adjacencias
 * (estrutura conforme slide de Implementacao)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct adjacencia {
    int vertice;
    int peso;
    struct adjacencia *proximo;
} ADJACENCIA;

typedef struct vertice {
    ADJACENCIA *cabeca;
} VERTICE;

typedef struct grafo {
    int vertices;
    int aresta;
    VERTICE *adj;
} GRAFO;

GRAFO* criarGrafo(int v) {
    GRAFO *g = (GRAFO *) malloc(sizeof(GRAFO));
    g->vertices = v;
    g->aresta = 0;
    g->adj = (VERTICE *) malloc(v * sizeof(VERTICE));
    for (int i = 0; i < v; i++)
        g->adj[i].cabeca = NULL;
    return g;
}

ADJACENCIA* criarAdj(int v, int peso) {
    ADJACENCIA *temp = (ADJACENCIA *) malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->proximo = NULL;
    return temp;
}

int criarAresta(GRAFO *gr, int vi, int vf, int p) {
    if (!gr) return 0;
    if (vf < 0 || vf >= gr->vertices) return 0;
    if (vi < 0 || vi >= gr->vertices) return 0;
    ADJACENCIA *novo = criarAdj(vf, p);
    novo->proximo = gr->adj[vi].cabeca;
    gr->adj[vi].cabeca = novo;
    gr->aresta++;
    return 1;
}

int removerAresta(GRAFO *gr, int vi, int vf) {
    if (!gr) return 0;
    if (vi < 0 || vi >= gr->vertices) return 0;
    if (vf < 0 || vf >= gr->vertices) return 0;
    ADJACENCIA *atual = gr->adj[vi].cabeca, *ant = NULL;
    while (atual) {
        if (atual->vertice == vf) {
            if (ant) ant->proximo = atual->proximo;
            else gr->adj[vi].cabeca = atual->proximo;
            free(atual);
            gr->aresta--;
            return 1;
        }
        ant = atual;
        atual = atual->proximo;
    }
    return 0;
}

int existeAresta(GRAFO *gr, int vi, int vf) {
    ADJACENCIA *ad = gr->adj[vi].cabeca;
    while (ad) {
        if (ad->vertice == vf) return 1;
        ad = ad->proximo;
    }
    return 0;
}

int pesoAresta(GRAFO *gr, int vi, int vf) {
    ADJACENCIA *ad = gr->adj[vi].cabeca;
    while (ad) {
        if (ad->vertice == vf) return ad->peso;
        ad = ad->proximo;
    }
    return 0;
}

int grauSaida(GRAFO *gr, int v) {
    int g = 0;
    ADJACENCIA *ad = gr->adj[v].cabeca;
    while (ad) { g++; ad = ad->proximo; }
    return g;
}

int grauEntrada(GRAFO *gr, int v) {
    int g = 0;
    for (int i = 0; i < gr->vertices; i++) {
        ADJACENCIA *ad = gr->adj[i].cabeca;
        while (ad) {
            if (ad->vertice == v) g++;
            ad = ad->proximo;
        }
    }
    return g;
}

void imprimir(GRAFO *gr) {
    printf("Vertices: %d. Arestas: %d.\n", gr->vertices, gr->aresta);
    for (int i = 0; i < gr->vertices; i++) {
        printf("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cabeca;
        while (ad) {
            printf("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->proximo;
        }
        printf("\n");
    }
}

void dfsAux(GRAFO *gr, int v, int *vis) {
    vis[v] = 1;
    printf("v%d ", v);
    ADJACENCIA *ad = gr->adj[v].cabeca;
    while (ad) {
        if (!vis[ad->vertice]) dfsAux(gr, ad->vertice, vis);
        ad = ad->proximo;
    }
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
        ADJACENCIA *ad = gr->adj[v].cabeca;
        while (ad) {
            if (!vis[ad->vertice]) {
                vis[ad->vertice] = 1;
                fila[f++] = ad->vertice;
            }
            ad = ad->proximo;
        }
    }
    printf("\n");
    free(vis); free(fila);
}

void liberar(GRAFO *gr) {
    for (int i = 0; i < gr->vertices; i++) {
        ADJACENCIA *ad = gr->adj[i].cabeca;
        while (ad) {
            ADJACENCIA *tmp = ad;
            ad = ad->proximo;
            free(tmp);
        }
    }
    free(gr->adj);
    free(gr);
}

int main(void) {
    /* Exemplo dos slides (Lista de Adjacencias - Dirigido):
       V1->V2(4), V1->V3(2), V2->V3(8), V4->V2(10) */
    GRAFO *gr = criarGrafo(4);
    criarAresta(gr, 0, 1, 4);
    criarAresta(gr, 0, 2, 2);
    criarAresta(gr, 1, 2, 8);
    criarAresta(gr, 3, 1, 10);

    imprimir(gr);
    printf("Peso (0->1): %d\n", pesoAresta(gr, 0, 1));
    printf("Grau saida v0: %d\n", grauSaida(gr, 0));
    printf("Grau entrada v2: %d\n", grauEntrada(gr, 2));
    buscaProfundidade(gr, 0);
    buscaLargura(gr, 0);

    removerAresta(gr, 0, 2);
    printf("\nApos remover (0->2):\n");
    imprimir(gr);

    liberar(gr);
    return 0;
}
