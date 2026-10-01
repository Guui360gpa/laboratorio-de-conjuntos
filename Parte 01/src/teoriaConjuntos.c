#include <stdio.h>
#include "conjuntos.h"

int main() {

    int i = 0, j =0, elemento;
    int qtdA = 0, qtdB = 0, opcao = 0;
    int achou;

    printf("Informe o tamanho do conjunto A: ");
    scanf("%d", &qtdA);

    int conjuntoA[qtdA];


    printf("Informe os elementos do Conjunto A:\n");
    for(i = 0; i < qtdA; i++){
        printf("Elemento %d: ", i + 1);
        scanf("%d", &elemento);

        conjuntoA[i] = elemento;
    }

    printf("\nInforme o tamanho do conjunto B: ");
    scanf("%d", &qtdB);

    int conjuntoB[qtdB];

    printf("Informe os elementos do Conjunto B:\n");
    for(j = 0; j < qtdB; j++){
        printf("Elemento %d: ", j + 1);
        scanf("%d", &elemento);

        conjuntoB[j] = elemento;
    }
    printf("\n\n-------------------------\n");
    printf("    MENU DE OPERAÇÕES   ");
    printf("\n-------------------------\n\n");
    printf("[1] União (A U B)\n");
    printf("[2] Interseção (A ∩ B)\n");
    printf("[3] Diferença (A - B)\n");
    printf("[4] Diferença (B - A)\n");
    printf("[5] Diferença simétrica (A U B) - (A ∩ B)\n");
    printf("[6] Pertinência (x ∈ A)\n");
    printf("[7] Inclusão (A ⊆ B)\n");
    printf("[8] Inclusão (B ⊆ A)\n");
    printf("[9] Inclusão (A ⊂ B)\n");
    printf("[10] Inclusão (B ⊂ A)\n");
    scanf("%d", &opcao);
    
    switch (opcao){
    case 1:
        uniao(conjuntoA,qtdA,conjuntoB,qtdB);
        break;

    case 2:
        intersecao(conjuntoA,qtdA,conjuntoB,qtdB);
        break;

    case 3:
        diferencaAB(conjuntoA,qtdA,conjuntoB,qtdB); 
        break;

    case 4:
        diferencaBA(conjuntoA,qtdA,conjuntoB,qtdB);
        break;

    case 5:
        diferencaSimetrica(conjuntoA,qtdA,conjuntoB,qtdB);
        break;
        
    case 6: 
        pertinencia(conjuntoA, qtdA, conjuntoB, qtdB);
        break;
    case 7:
        achou = 0;
        for (i = 0; i < qtdA; i++){
            for (j = 0; j < qtdB; j++){
                if(conjuntoA[i] == conjuntoB[j]){
                    achou += 1;
                    break;
                }
            }
        }
        if (achou == qtdA){
            printf("O conjunto A esta contido no conjunto B\n");
        }else{
            printf("O conjunto A nao esta contido conjunto B\n");
        }
        break;

    case 8:
        achou = 0;
        for (i = 0; i < qtdB; i++){
            for (j = 0; j < qtdA; j++){
                if(conjuntoB[i] == conjuntoA[j]){
                    achou += 1;
                    break;
                }
            }
        }
        if (achou == qtdB){
            printf("O conjunto B esta contido no conjunto A\n");
        }else{
            printf("O conjunto B nao esta contido conjunto A\n");
        }
        break;

    case 9:
        achou = 0;
        for (i = 0; i < qtdA; i++){
            for (j = 0; j < qtdB; j++){
                if(conjuntoA[i] == conjuntoB[j]){
                    achou += 1;
                    break;
                }
            }
        }
        if (achou == qtdA && qtdA < qtdB){
            printf("O conjunto A esta propriamente contido no conjunto B\n");
        }else{
            printf("O conjunto A nao esta contido no conjunto B\n");
        }
        break;

    case 10:
        achou = 0;
        for (i = 0; i < qtdB; i++){
            for (j = 0; j < qtdA; j++){
                if(conjuntoB[i] == conjuntoA[j]){
                    achou += 1;
                    break;
                }
            }
        }
        if (achou == qtdA && qtdA < qtdB){
            printf("O conjunto A esta propriamente contido no conjunto B\n");
        }else{
            printf("O conjunto A nao esta contido no conjunto B\n");
        }
        break;
    
    default:
        break;
    }
    return 0;
}