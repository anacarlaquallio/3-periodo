#include "ordenacao.h"

int max(int *v, int ini, int fim)
{
    int pm = ini;
    for (int j = ini + 1; j <= fim; j++)
    {
        if (v[j] > v[pm])
        {
            pm = j;
        }
    }
    return pm;
}

void troca(int *v, int i, int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void selection_sort(int *v, int n)
{
    int pm;
    for (int i = n - 1; i > 0; i--)
    {
        pm = max(v, 0, i);
        troca(v, i, pm);
    }
}

void bubble_sort(int *v, int n)
{
    for (int j = n - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (v[i] > v[i + 1])
            {
                troca(v, i, i + 1);
            }
        }
    }
}

void insertion(int *v, int k)
{
    int x = v[k];
    int i = k - 1;
    while ((i >= 0) && (v[i] > x))
    {
        v[i + 1] = v[i];
        i--;
    }
    v[i + 1] = k;
}

void insertion_sort(int *v, int n)
{
    int j;
    for (j = 1; j < n; j++)
    {
        insertion(v, j);
    }
}

void merge(int *v, int p, int q, int r)
{
    int ne = q - p + 2;
    int nd = r - q + 1;
    int i, j, k;
    int *e = malloc(sizeof(int) * ne);
    int *d = malloc(sizeof(int) * nd);

    for (i = 0; i < ne - 1; i++)
    {
        e[i] = v[p + 1];
        e[ne - 1] = INT_MAX;
    }
}

void merge_sort(int *v, int e, int d)
{
    if (e < d)
    {
        int m = (e + d) / 2;
        merge_sort(v, e, m);
        merge_sort(v, m + 1, d);
        merge(v, e, m, d);
    }
}

int partition(int *v, int p, int r)
{
    int x, i, j;
    x = v[r];
    i = p - 1;
    for (j = 0; j < r; j++)
    {
        if (v[j] <= x)
        {
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i + 1, r);
    return i + 1;
}

void quick_sort(int *v, int e, int d)
{
    if (e < d)
    {
        int q = partition(v, e, d);
    }
    quick_sort(v, e, q - 1);
    quick_sort(v, q + 1, d);
}