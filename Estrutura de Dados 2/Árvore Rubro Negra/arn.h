#pragma once

typedef enum
{
    C_VERMELHO,
    C_PRETO
} ARN_COR; // cor do nó é a cor do link que está entrando nele

typedef struct ARN
{
    int chave;
    int valor;
    struct ARN *esq;
    struct ARN *dir;
    ARN_COR cor;
} ARN; // estrutura da árvore rubo negra

ARN *ARN_Criar();
void ARN_Inserir(ARN **A, int chave, int valor);
void ARN_Imprimir(ARN *A, int nivel, char lado);