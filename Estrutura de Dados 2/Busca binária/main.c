#include "buscaBinaria.h"

int *sorted_vector(int n)
{
    int *v = malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; i++)
        v[i] = i * 10;
    return v;
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int x = atoi (argv[2]);
    int *v = sorted_vector (n);
    int idx = buscaBinaria(v, n, x);
    printf ("Elemento %d esta na posicao %d\n", x, idx);
    return 0;
}