#include "buscaBinaria.h"
#define DEBUG 1

void print_subarray(int *v, int e, int d)
{
    int i;
    for (i = e; i <= d; i++)
    {
        printf("%d ", v[i]);
    }
}

static int buscaBinariaR(int *v, int e, int d, int x)
{
    int m = (e + d) / 2;

    if (e <= d) // se o vetor não for unitário
    {
#if DEBUG
        print_subarray(v, e, d);
        printf("(Meio: %d)\n", v[m]);
#endif
        if (x == v[m])
            return m;
        if (x < v[m])
            return buscaBinariaR(v, e, m - 1, x);
        return buscaBinariaR(v, m + 1, d, x);
    }
    return -1;
}

int buscaBinaria(int *v, int n, int x)
{
    return buscaBinariaR(v, 0, n - 1, x);
}