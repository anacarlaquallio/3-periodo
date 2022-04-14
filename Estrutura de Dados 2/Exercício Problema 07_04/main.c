#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "ordenacao.h"
#include "utils.h"

bool twosum_bruteforce(int *v, int n, int x)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((v[i] + v[j]) == x)
            {
                printf("%d + %d = %d\n", v[i], v[j], x);
                return true;
            }
        }
    }
    return false;
}

bool twosum_sort(int *v, int n, int x)
{
    int i = 0, j = n - 1;
    quicksort(v, n);
    while (i != j)
    {
        int soma = v[i] + v[j];
        if (soma == x)
        {
            printf("%d + %d = %d\n", v[i], v[j], x);
            return true;
        }
        else
        {
            if (x > soma)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
    return false;
}

int main(int argc, char **argv)
{

    int n = atoi(argv[1]);
    int *v = random_vector(n, n, 999);
    twosum_bruteforce(v, n, 11);

    return 0;
}