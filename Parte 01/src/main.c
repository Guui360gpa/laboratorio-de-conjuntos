#include <stdio.h>
#include "funcoes/conjuntos.h"
#include <stdbool.h>
#include <unistd.h>

int main() {

    int conjuntoA[100], conjuntoB[100];
    int qtdA = 0, qtdB = 0, opcao = 0;
    bool sair = false;

    informarElementosPopularConjuntos(conjuntoA, &qtdA, conjuntoB, &qtdB);

    while(sair == false){
        sleep(2);
        exibirMenu();
        scanf("%d", &opcao);
        switch (opcao){
        case 0:
            printf("\nSaindo do programa...\n");
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

            propriamenteContidoAB(conjuntoA, qtdA, conjuntoB, qtdB);
            break;

        case 10:
            propriamenteContidoBA(conjuntoA, qtdA, conjuntoB, qtdB);
            break;

        case 11:
            printf("A cardinalidade do conjunto A é: %d\n", qtdA);
            break;

        case 12:
            printf("A cardinalidade do conjunto B é: %d\n", qtdB);
            break;

        case 13:
            complementoA(conjuntoA, qtdA);
            break;

        case 14:
            complementoB(conjuntoB, qtdB);
            break;
            
        default:
            break;
        }
    }
    return 0;
}