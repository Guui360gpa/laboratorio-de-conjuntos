#include <stdio.h>
#include "conjuntos.h"


void informarElementosPopularConjuntos(int conjuntoA[], int *qtdA, int conjuntoB[], int *qtdB) {
    printf("\nInforme a quantidade de elementos do conjunto A: ");
    scanf("%d", qtdA);
    printf("\nInforme os elementos do conjunto A:\n");
    for (int i = 0; i < *qtdA; i++) {
        scanf("%d", &conjuntoA[i]);
    }

    printf("\nInforme a quantidade de elementos do conjunto B: ");
    scanf("%d", qtdB);
    printf("\nInforme os elementos do conjunto B:\n");
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
    printf("[8] Inclusão (B C A)\n");
    printf("[9] Inclusão própria (A C B e A ≠ B)\n");
    printf("[10] Inclusão própria (B C A e B ≠ A)\n");
    printf("[11] Cardinalidade (|A|)\n");
    printf("[12] Cardinalidade (|B|)\n");
    printf("[13] Complemento (Aᶜ)\n");
    printf("[14] Complemento (Bᶜ)\n");
    printf("[0] Sair\n");
    printf("\nEscolha uma opção: ");
}


void uniao(int conjuntoA[], int tamA,int conjuntoB[],int tamB){
    int achou;
    int i,j,k;

        printf("\nA U B = {");
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
            printf("\nIntersecao = { ");
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

    printf("\nResultado da diferença (A - B):\n{");
    if (qtdR == 0) {
        printf("\nConjunto vazio\n");
        return;
    }
    for (int i = 0; i < qtdR; i++) {
        printf("%d ", resultado[i]);
    }
    printf("}\n");
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

    printf("\nResultado da diferença (B - A):\n{");
    if (qtdR == 0) {
        printf("\nConjunto vazio\n");
        return;
    }
    for (int i = 0; i < qtdR; i++) {
        printf("%d ", resultado[i]);
    }
    printf("}\n");
}

void diferencaSimetrica(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int achou;

    printf("\nDiferença simétrica = { ");

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

    printf("\nInforme o elemento a ser verificado: ");
    scanf("%d", &elemento);
    printf("\nInforme o conjunto a ser verificado (A/B): ");
    scanf(" %c", &opcao);

    if (opcao == 'A' || opcao == 'a') {
        for (int i = 0; i < qtdA; i++) {
            if (conjuntoA[i] == elemento) {
                achou = 1;
                break;
            }
        }
        printf("\nO elemento %d %s ao conjunto A\n", elemento, achou ? "pertence" : "não pertence");
    } else if (opcao == 'B' || opcao == 'b') {
        for (int i = 0; i < qtdB; i++) {
            if (conjuntoB[i] == elemento) {
                achou = 1;
                break;
            }
        }
        printf("\nO elemento %d %s ao conjunto B\n", elemento, achou ? "pertence" : "não pertence");
    } else {
        printf("\nConjunto inválido.\n");
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
        printf("\nO conjunto A está contido no conjunto B\n");
    } else {
        printf("\nO conjunto A não está contido no conjunto B\n");
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
        printf("\nO conjunto B está contido no conjunto A\n");
    } else {
        printf("\nO conjunto B não está contido no conjunto A\n");
    }
}

void propriamenteContidoAB(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int achou = 0;

    for (int i = 0; i < qtdA; i++) {
        for (int j = 0; j < qtdB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                achou++;
                break;
            }
        }
    }

    if (achou == qtdA && qtdA < qtdB) {
        printf("\nO conjunto A está propriamente contido no conjunto B\n");
    } else {
        printf("\nO conjunto A não está propriamente contido no conjunto B\n");
    }
}

void propriamenteContidoBA(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB) {
    int achou = 0;

    for (int i = 0; i < qtdB; i++) {
        for (int j = 0; j < qtdA; j++) {
            if (conjuntoB[i] == conjuntoA[j]) {
                achou++;
                break;
            }
        }
    }

    if (achou == qtdB && qtdB < qtdA) {
        printf("\nO conjunto B está propriamente contido no conjunto A\n");
    } else {
        printf("\nO conjunto B não está propriamente contido no conjunto A\n");
    }
}

void complementoA(int conjuntoA[], int qtdA) {
            int elemento = 0;
            int qtdU = 0;

            printf("\nInforme o tamanho do conjunto Universo: ");
            scanf("%d", &qtdU);

            int conjuntoU[qtdU];

            printf("\nInforme os elementos do Conjunto Universo:");

            for(int j = 0; j < qtdU; j++){
                printf("Elemento %d: ", j + 1);
                scanf("%d", &elemento);

                conjuntoU[j] = elemento;
            }
            
            printf("\nAᶜ = { ");
            for (int i = 0; i < qtdU; i++){
                int achou = 0;
                for (int j = 0; j < qtdA; j++){
                    if(conjuntoU[i] == conjuntoA[j]){
                        achou = 1;
                        break;
                    }
                }
                if (achou == 0){
                    printf("%d ", conjuntoU[i]); 
                }
            }
            printf("}\n");
}

void complementoB(int conjuntoB[], int qtdB) {
            int elemento = 0;
            int qtdU = 0;

            printf("\nInforme o tamanho do conjunto Universo: ");
            scanf("%d", &qtdU);

            int conjuntoU[qtdU];

            printf("\nInforme os elementos do Conjunto Universo:");
            //Conjunto Universo
            for(int j = 0; j < qtdU; j++){
                printf("Elemento %d: ", j + 1);
                scanf("%d", &elemento);

                conjuntoU[j] = elemento;
            }
            
            printf("\nBᶜ = { ");
            for (int i = 0; i < qtdU; i++){
                int achou = 0;
                for (int j = 0; j < qtdB; j++){
                    if(conjuntoU[i] == conjuntoB[j]){
                        achou = 1;
                        break;
                    }
                }
                if (achou == 0){
                    printf("%d ", conjuntoU[i]); 
                }
            }
            printf("}\n");
}