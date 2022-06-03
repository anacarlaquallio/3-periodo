#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "ilist.h"
#include "hashtable_ed.h"

ILIST *intersecao(int *A, int nA, int *B, int nB)
{
    ILIST *r = ILIST_Criar(10);

    THED *set = THED_Criar(23, 23);
    for(int i = 0; i < nA; i++)
        THED_Inserir(set, A[i], A[i]);
    
    for(int i = 0; i < nB; i++)
        if(THED_Buscar(set, B[i]))
            ILIST_Inserir(r, B[i], B[i]);

    return r;
}

ILIST *uniao(int *A, int nA, int *B, int nB)
{
    ILIST *r = ILIST_Criar(10);

    THED *set = THED_Criar(23, 23);
    for(int i = 0; i < nA; i++)
    {
        THED_Inserir(set, A[i], A[i]);
        ILIST_Inserir(r, A[i], A[i]);
    }
    
    for(int i = 0; i < nB; i++)
    {
        if(!THED_Buscar(set, B[i]))
            ILIST_Inserir(r, B[i], B[i]);
    }
    
    return r;
}

ILIST *diferenca(int *A, int nA, int *B, int nB)
{
    ILIST *r = ILIST_Criar(10);
    
    THED *set = THED_Criar(23, 23);
        for(int i = 0; i < nB; i++)
            THED_Inserir(set, B[i], B[i]);
    
    for(int i = 0; i < nA; i++)
    {
        if(!THED_Buscar(set, A[i]))
            ILIST_Inserir(r, A[i], A[i]);
    }

    return r;
}

ILIST *diferenca_simetrica(int *A, int nA, int *B, int nB)
{
    ILIST *r = ILIST_Criar(10);
    
    THED *setA = THED_Criar(23, 23);
    for(int i = 0; i < nA; i++)
        THED_Inserir(setA, A[i], A[i]);

    THED *setB = THED_Criar(23, 23);
    for(int i = 0; i < nB; i++)
        THED_Inserir(setB, B[i], B[i]);

    for(int i = 0; i < nA; i++)
    {
        if(!THED_Buscar(setB, A[i]))
            ILIST_Inserir(r, A[i], A[i]);
    }

    for(int i = 0; i < nB; i++)
    {
        if(!THED_Buscar(setA, B[i]))
            ILIST_Inserir(r, B[i], B[i]);
    }

    return r;
}

int main()
{
    
    int A[] = {1, 2, 3, 4};
    int B[] = {2, 3, 5};

    ILIST *inter, *uni, *dif, *dif_sim;

    inter = intersecao(A, 4, B, 3);
    uni = uniao(A, 4, B, 3);
    dif = diferenca(A, 4, B, 3);
    dif_sim = diferenca_simetrica(A, 4, B, 3);

    ILIST_Imprimir(uni, 0);    

    return EXIT_SUCCESS;
}
