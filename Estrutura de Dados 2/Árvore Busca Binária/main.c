#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

int *gerar_vetor_aleatorio(int n, int seed, int max)
{
    int *v = malloc(sizeof(int) * n);
    srand(seed);
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % max;
    }
    return v;
}

int main()
{
    ABB *r = NULL;

    int v[] = {5, 2, 8, 1, 6};
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        ABB_Inserir(&r, v[i]);
    }

    // int *v = gerar_vetor_aleatorio (n, 1, 10*n)
    // int n = atoi(argv[1]);
    // v[i] = rand & max

    ABB_ImprimirEmOrdem(r);
    printf("\nEsta arvore tem %d nos\n", ABB_N(r));
    printf("Esta arvore tem %d de altura\n", ABB_Altura(r));

    return 0;
}