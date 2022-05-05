#include <stdlib.h>
#include <stdio.h>
#include "ilist.h"
#include "hashtable_ed.h"

int THED_Hash(THED *HT, int chave)
{
    return chave % HT->m;
}

THED *THED_Criar(int m, int alloc_step)
{
    THED *nova;
    nova = malloc(sizeof(THED));
    nova->m = m;
    nova->t = malloc(sizeof(ILIST *) * m);
    for (int i = 0; i < m; i++)
    {
        nova->t[i] = ILIST_Criar(10);
    }
    return nova;
}

void THED_Inserir(THED *HT, int chave, int valor)
{
    int h = THED_Hash(HT, chave);
    ILIST_Inserir(HT->t[h], chave, valor);
}

void THED_Remover(THED *HT, int chave)
{
    int h = THED_Hash(HT, chave);
    ILIST_Remover(HT->t[h], chave);
}

INOH *THED_Buscar(THED *HT, int chave)
{
    int h = THED_Hash(HT, chave);
    int p = ILIST_Buscar(HT->t[h], chave);
    return ILIST_Endereco(HT->t[h], p);
}

void THED_Imprimir(THED *HT)
{
    printf("===TABELA HASH M = %ld ===\n", HT->m);
    for (int i = 0; i < HT->m; i++)
    {
        printf("%d: \n", i);
        ILIST_Imprimir(HT->t[i], 0);
    }
    printf("===\n");
}

size_t THED_N(THED *HT)
{
}

ILIST *THED_Chaves(THED *HT)
{
}

void THED_Destruir(THED *HT)
{
}
