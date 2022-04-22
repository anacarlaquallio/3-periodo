#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Fatorial
int fat(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fat(n - 1);
}

// Fatorial não recursivo
int fac(int num)
{
    int f = 1;
    for (int i = num; i > 0; i--)
        f *= i;
    return f;
}

// Binário
void bin(int n)
{
    if (n < 2)
        printf("%d", n);
    else
    {
        bin(n / 2);
        printf("%d", n % 2);
    }
}

// Torres de Hanói
void hanoi(int n, int origem, int auxiliar, int destino)
{
    if (n == 1)
        printf("Mova da torre %d para a torre %d\n", origem, destino);
    else
    {
        hanoi(n - 1, origem, destino, auxiliar);
        printf("Mova da torre %d para a torre %d\n", origem, destino);
        hanoi(n - 1, auxiliar, origem, destino);
    }
}

// Contagem regressiva
void regressiva(int n)
{
    if (n < 0)
        printf("%d\n", n);
    else
        regressiva(n - 1);
}

// Resto da divisão
int resto(int m, int n)
{
    if (m < n)
        return m;
    else
        return resto(m - n, n);
}

////////////////////// Exercícios PEREIRA //////////////////////

// Ex. 6.1: x elevado a n
int potencia(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return (x * potencia(x, n - 1));
}

// Ex 6.2
int soma(int n)
{
    if (n <= 0)
        return 0;
    else
        return n + soma(n - 1);
}

// Ex 6.3
float fracao(int n)
{

    if (n == 1)
        return 1;

    return 1.0 / n + fracao(n - 1);
}

// Ex 6.4
int produto(int n, int m)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return m;

    return m + (n - 1) * m;
}

// Ex 6.5
int divisao(int m, int n)
{
    if (n == 1)
        return m;
    else if (m < n)
        return 0;
    return 1 + divisao(m - n, n);
}

// Ex 6.6
bool impar(int n);
bool par(int n)
{
    return ((n == 0) || impar(n - 1));
}
bool impar(int n)
{
    return (n > 0 && ((n == 1) || (par(n - 1))));
}

// Ex 6.9
int somaVetor(int *v, int n)
{
    if (n == 0)
        return v[n];
    return (v[n] + somaVetor(v, n - 1));
}

// Ex 6.10
int maximo(int n, int *v)
{
    if (n == 1)
        return v[0];
    else
    {
        int x;
        x = maximo(n - 1, v);
        if (x > v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

int minimo(int n, int *v)
{
    /*
    if (n == 1)
        return v[0];
    int m = minimo(n - 1, v + 1);
    return (v[0] < m) ? v[0] : m;
    */
    int min;
    if (n == 1)
        return v[0];
    min = minimo(n - 1, v);
    if (v[n - 1] < v[min])
        return n - 1;
    else
        return min;
}

////////////////////// Exercícios FEOFILOFF //////////////////////

// Ex 3.4
int produtoVetor(int *v, int n)
{
    if (n == 0)
        return v[n];
    if (v[n] < 0)
        return 0;
    return (v[n] * produtoVetor(v, n - 1));
}

// Ex 3.5
int somaDigito(int n)
{
    if (n == 0)
        return 0;
    return ((n % 10) + somaDigito(n / 10));
}

// Ex 3.6
int log(int n)
{
    if (n == 1)
        return 0;
    return log(n / 2) + 1;
}

int main()
{
    // Fatorial
    int fatorial = fat(4);
    printf("%d\n", fatorial);

    // Binário
    bin(4);
    printf("\n");

    // Torres de Hanói
    hanoi(3, 1, 2, 3);

    // Potência
    int resultado1 = potencia(4, 2);
    printf("%d\n", resultado1);

    // Soma
    int resultado2 = soma(4);
    printf("%d\n", resultado2);

    // Soma Fração
    float resultado3 = fracao(4);
    printf("%f\n", resultado3);

    // Produto
    int resultado4 = produto(4, 5);
    printf("%d\n", resultado4);

    // Produto
    int resultado5 = divisao(10, 2);
    printf("%d\n", resultado5);

    // Par
    if (par(5))
        printf("Par\n");
    else
        printf("Impar\n");

    // Soma vetor
    int i, n;
    printf("Entre com a quantidade de numeros do vetor: ");
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    printf("Entre com os numeros: ");
    for (i = 0; i < n; i++)
        scanf("%d", &v[i]);
    printf("Resultado soma vetor = %d\n", somaVetor(v, n - 1));

    // Maximo
    int max = maximo(n, v);
    printf("Maximo: %d\n", max);

    // Minimo
    int min = minimo(n, v);
    printf("Minimo: %d\n", min);

    // Produto vetor
    int prod = produtoVetor(v, n - 1);
    printf("Produto: %d\n", prod);

    // Soma digito
    int somaDigit = somaDigito(120);
    printf("Soma digito: %d\n", somaDigit);

    return EXIT_SUCCESS;
}