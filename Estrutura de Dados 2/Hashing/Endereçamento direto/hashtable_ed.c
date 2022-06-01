#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ilist.h"
#include "hashtable_ed.h"
#include <math.h>

unsigned int string_hash(char *string, int M)
{
    int h = 0;
    int i;
    int j = strlen(string) - 1;
    for (i = 0; i < strlen(string); i++)
    {
        printf("%d\n", j);
        h += (string[i] * (pow(31, j)));
        j--;
    }
    printf("%d\n", h);
    return h % M;
}

int THED_Hash(THED *HT, int chave)
{
    return chave % HT->m;
}

THED *THED_Criar(int m, int alloc_step) // inicializar nossa estrutura, alloc_step de quantos elementos vamos alocar
{
    THED *nova;                  // cria uma mova tabela Hash
    nova = malloc(sizeof(THED)); // aloca

    // inicializando as variáveis que estão dentro da estrutura
    nova->m = m;
    nova->t = malloc(sizeof(ILIST *) * m); // vai alocar o vetor com a quantidade de posições m, cada elemento é um ILIST*
    // cada posição dessa tabela é uma lista encadeada que vai ser criada de forma dinâmica e estamos alocando m ponteiros para a lista

    for (int i = 0; i < m; i++) // vamos incializar todas as listas
    {
        nova->t[i] = ILIST_Criar(alloc_step); // vai pegar a tabela da posição i e vai inicializar ela com o método da lista encadeada
    }
    return nova;
}

// THED *ht é o endereço inicial da tabela na qual quero inserir

void THED_Inserir(THED *HT, int chave, int valor)
{
    int h = THED_Hash(HT, chave); // calcula a hash passando a nossa tabela e a chave
    int tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Inserir(HT->t[h], chave, valor);
    if (tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n++;
}

void THED_Remover(THED *HT, int chave)
{
    int h = THED_Hash(HT, chave);
    int tam_lista = ILIST_Tamanho(HT->t[h]);
    ILIST_Remover(HT->t[h], chave);
    if (tam_lista != ILIST_Tamanho(HT->t[h]))
        HT->n--;
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
    return HT->n;
}

ILIST *THED_Chaves(THED *HT)
{
    ILIST *s = ILIST_Criar(THED_N(HT) + 1);
    INOH *p;
    for (int i = 0; i < HT->m; i++)
    {
        ILIST_Rebobinar(HT->t[i]);
        p = ILIST_Prox(HT->t[i]);
        while (p != NULL)
        {
            ILIST_Inserir(s, p->chave, p->valor);
            p = ILIST_Prox(HT->t[i]);
        }
    }
    return s;
}

void THED_Destruir(THED *HT)
{
    for (int i = 0; i < HT->m; i++)
        ILIST_Destruir(HT->t[i]);
    free(HT->t);
    free(HT);
}
