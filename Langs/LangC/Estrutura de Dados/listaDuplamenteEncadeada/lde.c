#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox, *ant;
} No;

void mostrar_lista_llde(No **lista){
    if(*lista == NULL){
        printf("lista Vazia!\n");
    }

    printf("Lista: ");
    for (No *p = *lista; p != NULL; p = p->prox) {
            printf("%d ", p->dado);
        }
        printf("\n");
}

int inserir_inicio_llde(No **lista, int valor){
    No *novo;
    novo = (No *) malloc(sizeof(No));

    if(novo == NULL) {
        return 0;
    }
    novo->dado = valor;
    novo->prox = NULL;

    novo->ant = NULL;

    if(*lista == NULL){
        *lista = novo;
    }else{
        novo->prox = *lista;
        *lista = novo;
    }
    return 1;
}

int inserir_final_llde(No **lista, int valor){
    No *novo;
    novo = (No *) malloc(sizeof(No));

    if(novo == NULL) {
        return 0;
    }

    novo->dado = valor;
    novo->prox = NULL;

    novo->ant = NULL;
    
    if(*lista == NULL){
        *lista = novo;
    }else{
        No *p;
        for(p = *lista; p->prox != NULL; p = p->prox);
        p->prox = novo;
    }

    return 1;
}

int inserir_ordenado(No **lista, int valor){
    No *novo;
    novo = (No *) malloc(sizeof(No));

    if(novo == NULL) {
        return 0;
    }

    novo->dado = valor;

    novo->prox = NULL;
    novo->ant = NULL;
    
    if(*lista == NULL){
        *lista = novo;
    }else{
        No *p, *q;
        q = NULL;

        for(p = *lista; p != NULL; p = p->prox) {
            if(valor < p->dado) {
                break;
            }
            q = p;
        } 
        if(q == NULL) {

            novo->prox = *lista;
            p->ant = novo;
            *lista = novo;
            return 1;

        }
        if(p == NULL) {
            q->prox = novo;
            *lista = novo;
        }
        novo->prox = p;
        novo->ant = q;
        p->ant = novo;
        q->prox = novo;
    }

    return 1;
}

void Panel() {
    char *textos[] = {
        "[0] - Sair",
        "[1] - Inserir no Inicio",
        "[2] - Inserir no fim",
        "[3] - Inserir ordenado",
        "[4] - Remover no Início",
        "[5] - Remover no fim",
        "[6] - Remover por valor",
        "[7] - Mostrar Lista",
        "[8] - Consultar se um elemento existe na linha"
    };


    int x = sizeof(textos) / sizeof(textos[0]);

    printf("---\n");
    for (int i = 0; i < x; i++) {
        printf("%s\n", textos[i]);
    }

    printf("\n");
}

int valueInsert() {
    printf("Inserir um valor > ");
    int v;
    scanf("%d", &v);
    return v;
}

int main() {
    int c = 1;
    No *A = NULL, *novo;

    while (c) {
        Panel();
        int valor;

        printf(">> ");
        scanf("%d", &valor);

        switch (valor) {
        case 1:
            system("clear");
            if(inserir_inicio_llde(&A, valueInsert())); else {
                printf("Não foi concluido");
            }
            break;
        
        case 2:
           system("clear");
           if(inserir_final_llde(&A, valueInsert())); else {
            printf("O procedimento não foi concluído!");
           }
           break;

        case 3:
           system("clear");
           if(inserir_ordenado(&A, valueInsert())); else {
            printf("Nooee");
           }
           break;
        case 7:

           system("clear");
           mostrar_lista_llde(&A);
           break;
        default:
           c = 0;
           break;
        }
    }
    

    return 0;
}
