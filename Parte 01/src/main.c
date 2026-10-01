#include <stdio.h>
#include "conjuntos.h"
#include <stdbool.h>

int main() {

    int conjuntoA[100], conjuntoB[100];
    int qtdA = 0, qtdB = 0, qtdU = 0, opcao = 0;
    bool sair = false;

    informarElementosPopularConjuntos(conjuntoA, &qtdA, conjuntoB, &qtdB);

    //67
    while(sair == false){
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao){
        case 0:
            printf("Saindo do programa...\n");
            sair = true;
            break;    
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
            contidoAB(conjuntoA, qtdA, conjuntoB, qtdB);
            break;

        case 8:
            contidoBA(conjuntoA, qtdA, conjuntoB, qtdB);
            break;

        case 9:
            int achou = 0;
            for (int i = 0; i < qtdA; i++){
                for (int j = 0; j < qtdB; j++){
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
            for (int i = 0; i < qtdB; i++){
                for (int j = 0; j < qtdA; j++){
                    if(conjuntoB[i] == conjuntoA[j]){
                        achou += 1;
                        break;
                    }
                }
            }
            if (achou == qtdB && qtdB < qtdA){
                printf("O conjunto B esta propriamente contido no conjunto A\n");
            }else{
                printf("O conjunto B nao esta contido no conjunto A\n");
            }
            break;

        case 11:
            printf("A cardinalidade do conjunto A é: %d\n", qtdA);
            break;

        case 12:
            printf("A cardinalidade do conjunto B é: %d\n", qtdB);
            break;

        case 13:
        int elemento = 0;
            printf("Informe o tamanho do conjunto Universo: ");
            scanf("%d", &qtdU);

            int conjuntoU[qtdU];

            printf("Informe os elementos do Conjunto Universo:");
            //Conjunto Universo
            for(j = 0; j < qtdU; j++){
                printf("Elemento %d: ", j + 1);
                scanf("%d", &elemento);

                conjuntoU[j] = elemento;
            }
            
            printf("Aᶜ = { ");
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
            break;

        case 14:
            printf("Informe o tamanho do conjunto Universo: ");
            scanf("%d", &qtdU);

            int conjuntoU[qtdU];

            printf("Informe os elementos do Conjunto Universo:");
            //Conjunto Universo
            for(int j = 0; j < qtdU; j++){
                printf("Elemento %d: ", j + 1);
                scanf("%d", &elemento);

                conjuntoU[j] = elemento;
            }
            
            printf("ᶜ = { ");
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
            break;
            
        default:
            break;
        }
    }
    return 0;
}