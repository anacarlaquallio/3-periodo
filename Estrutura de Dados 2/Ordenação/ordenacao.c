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
int max2(int *v, int n)
{
    int maior = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > maior)
            maior = v[i];
    }
    return maior;
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
    int x;
    int i, j;
    x = v[r];
    i = p - 1;
    for (j = p; j < r; j++)
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
        quick_sort(v, e, q - 1);
        quick_sort(v, q + 1, d);
    }
}
void counting_sort(int *v, int n, int div, int base, int *s)
{
    int i, t, c[base], acum = 0;
    memset(c, 0, sizeof(int) * base);
#define DIGIT(X) ((X / div) % base)
    for (i = 0; i < n; i++)
    {
        c[DIGIT(v[i])]++;
    }
    for (i = 0; i < base; i++)
    {
        t = c[i];
        c[i] = acum;
        acum += t;
    }
    for (i = 0; i < n; i++)
    {
        s[c[DIGIT(v[i])]] = v[i];
        c[DIGIT(v[i])]++;
    }
    memcpy(v, s, sizeof(int) * n);
}
void radix_sort(int *v, int n)
{
    int k, div = 1; // k iniciar sendo o maior número que tem no vetor
    k = max2(v, n);
    int *temp = malloc(sizeof(int) * n);
    while (k > 0)
    {
        counting_sort(v, n, div, 10, temp);
        div *= 10;
        k /= 10;
    }
    free(temp);
}