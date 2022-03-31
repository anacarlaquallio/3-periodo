#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

bool explorar(int l[10][10], int i, int j);

int main()
{
    int labirinto[10][10] = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                             {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                             {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}};

    bool sucesso = explorar(labirinto, 0, 0);
    if (!sucesso)
        printf("Não foi encontrada a saida.\n");

    return 0;
}
bool explorar(int l[10][10], int i, int j)
{
    if (i < 0 || i > 9 || j < 0 || j > 9)
        return false;
    if (l[i][j] > 0)
        return false;

    l[i][j] = 2;

    if (i == 9 && j == 9)
        return true;

    if (explorar(l, i + 1, j))
    {
        printf("(%d,%d) ", i + 1, j);
        return true;
    }
    if (explorar(l, i, j + 1))
    {
        printf("(%d,%d) ", i, j + 1);
        return true;
    }
    if (explorar(l, i - 1, j))
    {
        printf("(%d,%d) ", i - 1, j);
        return true;
    }
    if (explorar(l, i, j - 1))
    {
        printf("(%d,%d) ", i, j - 1);
        return true;
    }
    return false;
}
