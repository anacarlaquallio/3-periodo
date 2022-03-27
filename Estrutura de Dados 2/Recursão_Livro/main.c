#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// Fatorial
int fat(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fat(n - 1);
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

// Ex. 6.1: x elevado a n
int potencia(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return (x * potencia(x, n - 1));
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
    int resultado = potencia(4, 2);
    printf("%d\n", resultado);

    return EXIT_SUCCESS;
}