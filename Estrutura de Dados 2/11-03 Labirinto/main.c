#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int labirinto[10][10] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0}};

bool explorar(int l[10][10], int i, int j)
{
    if (i < 0 || i > 9 || j < 0 || j > 9)
        return false;

    if (l[i][j] > 0) // sair se == 1(parede) ou se == 2(já passei)
        return false;

    l[i][j] = 2; // marcar que já passamos aqui

    if (i == 9 && j == 9)
        return true;

    if (explorar(l, i + 1, j)) // explorar pra baixo
    {
        printf("(%d,%d) ", i + 1, j);
        return true;
    }
    if (explorar(l, i, j + 1)) // explorar pra direita
    {
        printf("(%d,%d) ", i, j + 1);
        return true;
    }
    if (explorar(l, i - 1, j)) // explorar pra cima
    {
        printf("(%d,%d) ", i - 1, j);
        return true;
    }
    if (explorar(l, i, j - 1)) // explorar pra esquerda
    {
        printf("(%d,%d) ", i, j - 1);
        return true;
    }
    return false;
}
int main()
{
    
}