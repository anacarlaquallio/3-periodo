#include "abb.h"

ABB *ABB_Criar(int chave, ABB *esq, ABB *dir)
{
    ABB *novo = malloc(sizeof(ABB)); // cria um novo nó e aloca espaço pra ele
    // inicializa os valores
    novo->chave = chave;
    novo->dir = dir;
    novo->esq = esq;
    return novo;
}
void ABB_Inserir(ABB **A, int chave)
{
    if ((*A) == NULL) // se o conteúdo do ponteiro A for NULL
    {
        *A = ABB_Criar(chave, NULL, NULL); // cria um folha
        return;                            // cai fora da inserção
    }
    // A só é o endereço do ponteiro. *A é o ponteiro em si, que contém o valor

    if (chave <= (*A)->chave)
        ABB_Inserir(&(*A)->esq, chave); // pega o endereço do ponteiro que a gente vai seguir, está passando a aresta
    else
        ABB_Inserir(&(*A)->dir, chave);
}

// é pré-ordem
ABB *ABB_Buscar(ABB *A, int chave)
{
    // verifica se chegamos em folha, não encontramos o elemento
    if (A == NULL)
        return NULL;

    // caso A está apontando para algo
    if (A->chave == chave) // se a chave do nó atual é igual a chave
        return A;
    if (chave < A->chave)
        return ABB_Buscar(A->esq, chave);
    return ABB_Buscar(A->dir, chave);
}

void AB_Destruir(ABB **A)
{
    if ((*A) == NULL)
        return;
    AB_Destruir(&(*A)->esq);
    AB_Destruir(&(*A)->dir);
    free(*A);
}