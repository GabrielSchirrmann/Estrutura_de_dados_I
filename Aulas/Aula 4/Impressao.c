#include <stdio.h>
#include <stdlib.h>

// 1. Definição correta da struct e typedef juntos
typedef struct no {
    int dado;
    struct no *prox;  // 'no' minúsculo, igual ao nome da struct
} No;

typedef No* p_no;

// 2. Criar lista
p_no criar_lista() {
    return NULL;
}

// 3. Destruir lista (recursiva)
void destruir_lista(p_no lista) {
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}  // <- chave que estava faltando

// 4. Impressão iterativa
void imprime(p_no lista) {
    p_no atual;
    for (atual = lista; atual != NULL; atual = atual->prox)
        printf("%d\n", atual->dado);
}

// 5. Impressão recursiva
void imprime_recursivo(p_no lista) {
    if (lista != NULL) {
        printf("%d\n", lista->dado);
        imprime_recursivo(lista->prox);  // nome correto da função
    }
}

// 6. Main por último
int main() {
    p_no lista = criar_lista();  // declaração única
    printf("Lista criada com sucesso!\n");
    destruir_lista(lista);
    return 0;
}

p_no busca (p_no lista, int X){
    
}
