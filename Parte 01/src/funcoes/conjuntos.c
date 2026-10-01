#include <stdio.h>
#include "conjuntos.h"


void informarElementosPopularConjuntos(int conjuntoA[], int *qtdA, int conjuntoB[], int *qtdB) {
    printf("Informe a quantidade de elementos do conjunto A: ");
    scanf("%d", qtdA);
    printf("Informe os elementos do conjunto A:\n");
    for (int i = 0; i < *qtdA; i++) {
        scanf("%d", &conjuntoA[i]);
    }

    printf("Informe a quantidade de elementos do conjunto B: ");
    scanf("%d", qtdB);
    printf("Informe os elementos do conjunto B:\n");
    for (int i = 0; i < *qtdB; i++) {
        scanf("%d", &conjuntoB[i]);
    }
}


void exibirMenu() {
    printf("\n\n-------------------------\n");
    printf("    MENU DE OPERAÇÕES   ");
    printf("\n-------------------------\n\n");
    printf("[1] União (A U B)\n");
    printf("[2] Interseção (A ∩ B)\n");
    printf("[3] Diferença (A - B)\n");
    printf("[4] Diferença (B - A)\n");
    printf("[5] Diferença simétrica (A U B) - (A ∩ B)\n");
    printf("[6] Pertinência (x ∈ A)\n");
    printf("[7] Inclusão (A C B)\n");
    printf("[8] Inclusão (B C A)");
    printf("[0] Sair");
}


void uniao(int conjuntoA[], int tamA,int conjuntoB[],int tamB){
    int achou;
    int i,j,k;

        printf("A U B = {");
        for (i = 0; i < tamA; i++){
            printf("%d",conjuntoA[i]);
        }
        for (j = 0; j < tamB; j++){
            achou = 0;
            for (k = 0; k < tamA; k++){
                if (conjuntoB[j] == conjuntoA[k]){
                    achou = 1;
                    break;
                }
            }
            if (!achou){
                printf("%d",conjuntoB[j]);
            }
        }
        
        printf("}\n");
}

void intersecao(int conjuntoA[], int tamA,int conjuntoB[],int tamB){
            printf("Intersecao = { ");
        for (int i = 0; i < tamA; i++){
            for (int j = 0; j < tamB; j++){
                if (conjuntoA[i] == conjuntoB[j]){
                    printf("%d ", conjuntoA[i]);
                }
            }
        }
        printf("}\n");
}

void diferencaAB(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int resultado[qtdA];
    int qtdR = 0;

    for (int i = 0; i < qtdA; i++) {
        int achou = 0;

        for (int j = 0; j < qtdB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                achou = 1;
                break;
            }
        }

        if (!achou) {
            resultado[qtdR++] = conjuntoA[i];
        }
    }

    printf("Resultado da diferença (A - B):\n");
    if (qtdR == 0) {
        printf("Conjunto vazio\n");
        return;
    }
    for (int i = 0; i < qtdR; i++) {
        printf("%d\n", resultado[i]);
    }
}

void diferencaBA(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int resultado[qtdB];
    int qtdR = 0;

    for (int i = 0; i < qtdB; i++) {
        int achou = 0;

        for (int j = 0; j < qtdA; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                achou = 1;
                break;
            }
        }

        if (!achou) {
            resultado[qtdR++] = conjuntoB[i];
        }
    }

    printf("Resultado da diferença (B - A):\n");
    if (qtdR == 0) {
        printf("Conjunto vazio\n");
        return;
    }
    for (int i = 0; i < qtdR; i++) {
        printf("%d\n", resultado[i]);
    }
}

void diferencaSimetrica(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int achou;

    printf("Diferença simétrica = { ");

    for (int i = 0; i < qtdA; i++) {
        achou = 0;
        for (int j = 0; j < qtdB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                achou = 1;
                break;
            }
        }
        if (!achou) {
            printf("%d ", conjuntoA[i]);
        }
    }

    for (int i = 0; i < qtdB; i++) {
        achou = 0;
        for (int j = 0; j < qtdA; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                achou = 1;
                break;
            }
        }
        if (!achou) {
            printf("%d ", conjuntoB[i]);
        }
    }

    printf("}\n");
}

void pertinencia(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int elemento;
    char opcao;
    int achou = 0;

    printf("Informe o elemento a ser verificado: ");
    scanf("%d", &elemento);
    printf("Informe o conjunto a ser verificado (A/B): ");
    scanf(" %c", &opcao);

    if (opcao == 'A' || opcao == 'a') {
        for (int i = 0; i < qtdA; i++) {
            if (conjuntoA[i] == elemento) {
                achou = 1;
                break;
            }
        }
        printf("O elemento %d %s ao conjunto A\n", elemento, achou ? "pertence" : "não pertence");
    } else if (opcao == 'B' || opcao == 'b') {
        for (int i = 0; i < qtdB; i++) {
            if (conjuntoB[i] == elemento) {
                achou = 1;
                break;
            }
        }
        printf("O elemento %d %s ao conjunto B\n", elemento, achou ? "pertence" : "não pertence");
    } else {
        printf("Conjunto inválido.\n");
    }
}

void contidoAB(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int achou = 0;

    for (int i = 0; i < qtdA; i++) {
        for (int j = 0; j < qtdB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                achou++;
                break;
            }
        }
    }

    if (achou == qtdA) {
        printf("O conjunto A está contido no conjunto B\n");
    } else {
        printf("O conjunto A não está contido no conjunto B\n");
    }
}

void contidoBA(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int achou = 0;

    for (int i = 0; i < qtdB; i++) {
        for (int j = 0; j < qtdA; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                achou++;
                break;
            }
        }
    }

    if (achou == qtdB) {
        printf("O conjunto B está contido no conjunto A\n");
    } else {
        printf("O conjunto B não está contido no conjunto A\n");
    }
}