#include "arn.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

ARN *ARN_Criar()
{
    return NULL;
}

static ARN *ARN_NovoNo(int chave, int valor)
{
    // essa função cria um novo nó e inicializa ele corretamente
    ARN *novo = malloc(sizeof(ARN));
    novo->chave = chave;
    novo->valor = valor;
    novo->cor = C_VERMELHO; // a cor inicialmente do nó é sempre vermelha
    novo->dir = NULL;
    novo->esq = NULL;
    return novo;
}

static inline bool eh_vermelho(ARN *A)
{
    if (A == NULL)
        return false;
    // return A->cor == C_VERMELHO ? true : false;
    return A->cor == C_VERMELHO;
}

static inline void inverter_cores(ARN *A)
{
    A->cor = C_VERMELHO;
    A->esq->cor = C_PRETO;
    A->dir->cor = C_PRETO;
}

static void rot_esq(ARN **A)
{
    ARN *h, *x;
    h = *A; // h é o nó que está sendo apontado por A
    x = h->dir; // x é filho direto de h
    h->dir = x->esq;
    x->esq = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

static void rot_dir(ARN **A)
{
    ARN *h, *x;
    h = *A;
    x = h->esq;
    h->esq = x->dir; // h vai apontar para T2
    x->dir = h;
    x->cor = h->cor;
    h->cor = C_VERMELHO;
    *A = x;
}

void ARN_Inserir_R(ARN **A, int chave, int valor)
{

    if ((*A) == NULL) // se o ponteiro do nó é nulo, chegamos ao fim da árvore
    {
        *A = ARN_NovoNo(chave, valor); // pendura o novo nó
        return;
    }

    // senão temos que procurar aonde vamos fazer a inserção
    if (chave < (*A)->chave)
    {
        ARN_Inserir_R(&(*A)->esq, chave, valor); // endereço do ponteiro pra esq para pendurar o novo nó
    }
    else if (chave > (*A)->chave) // caso for maior
    {
        ARN_Inserir_R(&(*A)->dir, chave, valor);
    }

    // caso rotação a esquerda
    if (eh_vermelho((*A)->dir) &&
        !eh_vermelho((*A)->esq))
    {
        rot_esq(A);
    }
    // verifica se há dois links esquerdos vermelhos seguidos
    if (eh_vermelho((*A)->esq) &&
        eh_vermelho((*A)->esq->esq))
    {
        rot_dir(A);
    }
    // caso inversão e cores
    if (eh_vermelho((*A)->esq) &&
        eh_vermelho((*A)->dir))
    {
        inverter_cores(*A);
    }
}

void ARN_Inserir(ARN **A, int chave, int valor)
{
    ARN_Inserir_R(A, chave, valor);
    (*A)->cor = C_PRETO; // garantir que a cor do nó raíz permanece preta durante toda execução
}
void ARN_Imprimir(ARN *A, int nivel, char lado)
{
    int i;
    for (i = 0; i < nivel; i++)
    {
        printf("--> ");
    }
    if (A == NULL)
    {
        printf("(%c) NONE\n", lado);
    }
    else
    {
        printf("(%c) %c [%s]\n", lado, (char)A->chave, A->cor == C_VERMELHO ? "V" : "P");
        ARN_Imprimir(A->esq, nivel + 1, 'e');
        ARN_Imprimir(A->dir, nivel + 1, 'd');
    }
}