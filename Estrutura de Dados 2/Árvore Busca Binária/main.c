#include "abb.h"
#include <stdio.h>

int main()
{
    ABB *r = NULL;

    ABB_Inserir(&r, 5);
    ABB_Inserir(&r, 4);
    ABB_Inserir(&r, 20);
    ABB_Inserir(&r, 2);
    ABB_Inserir(&r, 6);
    ABB_Inserir(&r, 1);
    ABB_Inserir(&r, 3);

    printf("%p\n", ABB_Buscar(r, 1));
    printf("%p\n", ABB_Buscar(r, 7));
    printf("%p\n", ABB_Buscar(r, 2));
    printf("%p\n", ABB_Buscar(r, 20));
    printf("%p\n", ABB_Buscar(r, 8));

    return 0;
}