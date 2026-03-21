#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int dado;
    struct No *proximo;
} No;


No *inicio = NULL;



void inserirInicio(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return;
    }
    novo->dado = valor;
    novo->proximo = inicio;
    inicio = novo;
    printf("Elemento %d inserido no inicio.\n", valor);
}

void inserirFinal(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return;
    }
    novo->dado = valor;
    novo->proximo = NULL;

    if (inicio == NULL) {
        inicio = novo;
    } else {
        No *atual = inicio;
        while (atual->proximo != NULL)
            atual = atual->proximo;
        atual->proximo = novo;
    }
    printf("Elemento %d inserido no final.\n", valor);
}

void inserirMeio(int valor, int posicao) {

    if (posicao <= 1) {
        inserirInicio(valor);
        return;
    }

    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return;
    }
    novo->dado = valor;

    No *atual = inicio;
    int i = 1;
    while (atual != NULL && i < posicao - 1) {
        atual = atual->proximo;
        i++;
    }

    if (atual == NULL) {

        free(novo);
        inserirFinal(valor);
        return;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
    printf("Elemento %d inserido na posicao %d.\n", valor, posicao);
}

void imprimir() {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    No *atual = inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->proximo != NULL)
            printf(" -> ");
        atual = atual->proximo;
    }
    printf("\n");
}

void apagarElemento(int valor) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    int removidos = 0;

    while (inicio != NULL && inicio->dado == valor) {
        No *temp = inicio;
        inicio = inicio->proximo;
        free(temp);
        removidos++;
    }

    No *atual = inicio;
    while (atual != NULL && atual->proximo != NULL) {
        if (atual->proximo->dado == valor) {
            No *temp = atual->proximo;
            atual->proximo = temp->proximo;
            free(temp);
            removidos++;
        } else {
            atual = atual->proximo;
        }
    }

    if (removidos == 0)
        printf("Elemento %d nao encontrado.\n", valor);
    else
        printf("%d ocorrencia(s) do elemento %d removida(s).\n", removidos, valor);
}

void apagarLista() {
    if (inicio == NULL) {
        printf("Lista ja esta vazia.\n");
        return;
    }
    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    inicio = NULL;
    printf("Lista apagada com sucesso.\n");
}

int main() {
    int opcao, valor, posicao;

    do {
        printf("\n===== MENU =====\n");
        printf("0 - Sair\n");
        printf("1 - InserirIN  (inicio)\n");
        printf("2 - InserirFI  (final)\n");
        printf("3 - InserirMe  (meio)\n");
        printf("4 - Imprimir\n");
        printf("5 - ApagarElemento\n");
        printf("6 - ApagarLista\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Encerrando...\n");
                apagarLista();
                break;

            case 1:
                printf("Valor a inserir no inicio: ");
                scanf("%d", &valor);
                inserirInicio(valor);
                break;

            case 2:
                printf("Valor a inserir no final: ");
                scanf("%d", &valor);
                inserirFinal(valor);
                break;

            case 3:
                printf("Valor a inserir: ");
                scanf("%d", &valor);
                printf("Posicao (1 = antes do 1o elemento): ");
                scanf("%d", &posicao);
                inserirMeio(valor, posicao);
                break;

            case 4:
                imprimir();
                break;

            case 5:
                printf("Valor a apagar: ");
                scanf("%d", &valor);
                apagarElemento(valor);
                break;

            case 6:
                apagarLista();
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}