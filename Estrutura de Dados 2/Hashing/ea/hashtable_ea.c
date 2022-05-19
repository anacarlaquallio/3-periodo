#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"

static void THEA_Redimensionar(THEA *TH, int novo_m)
{
    ELEM *nova, *antiga;
    int m_antigo;
    nova = malloc(sizeof(ELEM) * novo_m);
    for (int i = 0; i < novo_m; i++)
        nova[i].estado = E_LIVRE;
    antiga = TH->TH;
    m_antigo = TH->m;
    TH->TH = nova;
    TH->n = 0;
    TH->m = novo_m;
    for (int i = 0; i < m_antigo; i++)
        if (antiga[i].estado == E_OCUPADO)
            THEA_Inserir(TH, antiga[i].chave, antiga[i].valor);
    free(antiga);
}

int THEA_Hash(THEA *TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

THEA *THEA_Criar(int m)
{
    THEA *nova;
    nova = malloc(sizeof(THEA));
    nova->m = m;
    nova->n = 0;
    nova->TH = malloc(sizeof(ELEM) * m);
    for (int i = 0; i < m; i++)
        nova->TH[i].estado = E_LIVRE;
    return nova;
}

int THEA_Inserir(THEA *TH, int chave, int valor)
{
    int h, k, h_inicial;
    h = THEA_Buscar(TH, chave);
    if (h >= 0)
    {
        TH->n--;
    }
    else
    {
        k = 0;

        if (TH->n > TH->m / 2)
        {
            printf("Tabela redimensionada de m=%d para %d", TH->m, TH->m*2);
            printf("(n = %d)\n", TH->n);
            THEA_Redimensionar(TH, TH->m*2);
        }
        h = THEA_Hash(TH, chave, k);
        h_inicial = h;
        while (TH->TH[h].estado == E_OCUPADO)
        {
            k++;
            h = THEA_Hash(TH, chave, k);
            if (h == h_inicial)
                return -1;
        }
    }
    TH->n++;
    TH->TH[h].chave = chave;
    TH->TH[h].valor = valor;
    TH->TH[h].estado = E_OCUPADO;

    return h;
}

int THEA_Buscar(THEA *TH, int chave)
{
    int h, h_inicial, k;
    k = 0;
    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while (TH->TH[h].estado != E_LIVRE)
    {
        if ((TH->TH[h].estado == E_OCUPADO) && (TH->TH[h].chave == chave))
            return h;
        k++;
        h = THEA_Hash(TH, chave, k);
        if (h_inicial == h)
            return -1;
    }
    return -1;
}

void THEA_Remover(THEA *TH, int chave)
{
    int p = THEA_Buscar(TH, chave);
    if (p >= 0)
    {
        TH->TH[p].estado = E_APAGADO;
        TH->n--;
    }
}