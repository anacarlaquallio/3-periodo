#include "abb.h"

ABB **ABB_Min(ABB **A)
{
    if ((*A) == NULL)
        return NULL;
    while ((*A)->esq != NULL)
    {
        A = &(*A)->esq;
        return A;
    }
}

int ABB_Profundidade(ABB *A, int chave)
{
    if (A == NULL)
        return -1;

    int dist = -1;

    if ((A->chave == chave) || (dist = ABB_Profundidade(A->esq, chave)) >= 0 || (dist = ABB_Profundidade(A->dir, chave)) >= 0)
        return dist + 1;
    return dist;
}
/*
void AB_CalcularProfundidades(AB A, int p)
{
    if (A == NULL)
    {
        return;
    }
    A->profundidade = p;
    p++;
    AB_CalcularProfundidades(A->esq, p);
    AB_CalcularProfundidades(A->dir, p);
    p -= 2;
}

int AB_ComprimentoInternoLazy(AB A, int c)
{
    if (A == NULL)
    {
        return c;
    }
    c += A->profundidade;
    c = AB_ComprimentoInternoLazy(A->esq, c);
    c = AB_ComprimentoInternoLazy(A->dir, c);
}
*/
int ABB_Altura(ABB *A) // Conta altura da árvore
{
    if (A == NULL)
        return 0;
    int dir = ABB_Altura(A->dir);
    int esq = ABB_Altura(A->esq);
    if (dir > esq)
        return dir + 1;
    else
        return esq + 1;

    // Solução do professor
    /*
        if (A = NULL)
            return 0;
        int alt_esq = ABB_Altura(A->esq);
        int alt_dir = ABB_Altura(A->dir);
        if (alt_dir>alt_esq) return alt_dir+1;
        else return alt_esq +1;
    */
}

int ABB_N(ABB *A) // Conta nós da árvore
{
    // Minha solução:
    if (A == NULL)
        return 0;
    int dir = ABB_N(A->dir);
    int esq = ABB_N(A->esq);
    return dir + esq + 1; // 1 pq conta o nó

    /*
    // Solução do professor
    if (A == NULL)
        return 0;
    return 1 + ABB_N(A->esq) + ABB_N(A->dir);
    */
}

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

    // Não insere repetido
    if (chave == (*A)->chave)
    {
        return;
    }
    else if (chave < (*A)->chave)
    {
        ABB_Inserir(&(*A)->esq, chave);
    }
    else
        ABB_Inserir(&(*A)->dir, chave);

    // Insere repetido
    /*
        if (chave <= (*A)->chave)
            ABB_Inserir(&(*A)->esq, chave); // pega o endereço do ponteiro que a gente vai seguir, está passando a aresta
        else
            ABB_Inserir(&(*A)->dir, chave);
    */
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

void ABB_ImprimirEmOrdem(ABB *A)
{
    if (A == NULL)
        return;
    ABB_ImprimirEmOrdem(A->esq);
    printf("%d, ", A->chave);
    ABB_ImprimirEmOrdem(A->dir);
}

void ABB_Remover(ABB **A, int chave)
{
    if ((*A) == NULL)
        return;
    if (chave < (*A)->chave)
        ABB_Remover(&(*A)->esq, chave);
    else if (chave > (*A)->chave)
        ABB_Remover(&(*A)->dir, chave);
    else
    {
        ABB *t;
        if ((*A)->esq == NULL)
        {
            t = *A;
            *A = (*A)->dir;
            free(t);
            return;
        }
        if ((*A)->dir == NULL)
        {
            t = *A;
            *A = (*A)->esq;
            free(t);
            return;
        }
        ABB **suc = ABB_Min((*A)->dir);
        (*A)->chave = (*suc)->chave;
        ABB_Remover(suc, (*suc)->chave);
    }
}