#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct ABB
{
    int chave;
    struct ABB *esq; // ponteiro subárvore esquerda
    struct ABB *dir; // ponteiro subárvore direita
} ABB;

ABB **ABB_Min(ABB **A);
int ABB_Profundidade(ABB *A, int chave);
int ABB_Altura(ABB *A);
int ABB_N(ABB *A);
ABB *ABB_Criar(int chave, ABB *esq, ABB *dir); // também retorna o endereço de um novo nó
void ABB_Inserir(ABB **A, int chave);          // vamos trocar o valor que o ponteiro está apontando, por isso precisamos do endereço do ponteiro do nó da árvore, ou seja, ABB**
ABB *ABB_Buscar(ABB *A, int chave);            // retorna o endereço do elemento da árvore
void AB_Destruir(ABB **A);
void ABB_ImprimirEmOrdem(ABB *A);
