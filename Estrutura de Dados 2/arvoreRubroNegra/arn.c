#include "arn.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

ARN *ARN_Criar()
{
    return NULL;
}
static ARN *ARN_NovoNo(int chave, int valor) // static faz com que a função funcione apenas internamente
{
    ARN *novo = malloc(sizeof(ARN));
    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_VERMELHO;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

//**A endereço do ponteiro que aponta para o nó

static inline bool eh_vermelho(ARN *A)
{
    if (A == NULL)
        return false;
    // return A->cor == C_VERMELHO ? true : false;
    return A->cor == C_VERMELHO;
}

static inline void inverter_cores(ARN *A) // o compilador vai colocar essa função direto
{
    A->cor = C_VERMELHO;
    A->esq->cor = C_PRETO;
    A->dir->cor = C_PRETO;
}

static void rot_esq(ARN **A)
{
    ARN *h, *x;
    h = *A;     // pai
    x = h->dir; // x recebe filho direito
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

static void rot_dir(ARN **A)
{
    ARN *h, *x;
    h = *A;     // pai
    x = h->esq; // x recebe filho direito
    h->esq = x->dir;
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

void ARN_Inserir_R(ARN **A, int chave, int valor) // parte recursiva da recursão
{
    if ((*A) = NULL) // se valor que estiver sendo apontado para o A for null, pendura um novo nó
    {
        *A = ARN_NovoNo(chave, valor);
        return; // cai fora
    }
    if (chave < (*A)->chave)
    {
        ARN_Inserir_R(&(*A)->esq, chave, valor);
    }
    else if (chave > (*A)->chave)
    {
        ARN_Inserir_R(&(*A)->dir, chave, valor);
    }

    // filho esquerdo preto/null e filho direito vermelho
    // inserção nó simples à direta
    // inserção duplo valor mediano
    if (eh_vermelho((*A)->dir) && !eh_vermelho((*A)->esq))
    {
        ror_esq(A);
    }

    // inserção nó simples duplo menor valor
    // inserção nó simples valor duplo mediano
    if (eh_vermelho((*A)->esq) && eh_vermelho((*A)->esq->esq))
    {
        rot_dir(A);
    }

    // inserção duplo valor mediano
    // inserção nó duplo com maior valor
    if (eh_vermelho((*A)->esq) && eh_vermelho((*A)->dir))
    {
        inverter_cores(*A);
    }
}

void ARN_Inserir(ARN **A, int chave, int valor)
{ // garante que depois de inserir a aresta vai ser preta
    ARN_Inserir_R(A, chave, valor);
    (*A)->cor = C_PRETO;
}

void ARN_Imprimir(ARN *A)
{
}
