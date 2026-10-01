#ifndef CONJUNTOS_H
#define CONJUNTOS_H

void informarElementosPopularConjuntos(int conjuntoA[], int *qtdA, int conjuntoB[], int *qtdB);
void exibirMenu();
void uniao(int conjuntoA[], int tamA, int conjuntoB[], int tamB);
void intersecao(int conjuntoA[], int tamA, int conjuntoB[], int tamB);
void diferencaAB(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB);
void diferencaBA(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB);
void diferencaSimetrica(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB);
void pertinencia(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB);
void contidoAB(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB);
void contidoBA(int conjuntoA[], int qtdA, int conjuntoB[], int qtdB);

#endif