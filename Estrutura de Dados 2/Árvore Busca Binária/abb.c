#include "abb.h"

ABB *ABB_Criar(int chave, ABB *esq, ABB *dir)
{
    ABB *novo = malloc(sizeof(ABB));
    novo->chave = chave;
    novo->dir = dir;
    novo->esq = esq;
    return novo;
}
void ABB_Inserir(ABB **A, int chave)
{
    if ((*A) == NULL)
    {
        *A = ABB_Criar(chave, NULL, NULL);
        return;
    }
    // A só é o endereço do ponteiro. *A é o ponteiro em si, que contém o valor
    if (chave <= (*A)->chave)
        ABB_Inserir(&(*A)->esq, chave);
    else
        ABB_Inserir(&(*A)->dir, chave);
}

ABB *ABB_Buscar(ABB *A, int chave)
{
    if (A == NULL)
        return NULL;

    // A está apontando para algo
    if (A->chave == chave)
        return A;
    if (chave < A->chave)
        return ABB_Buscar(A->esq, chave);
    return ABB_Buscar(A->dir, chave);
}