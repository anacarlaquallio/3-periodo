#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"

int main(int argc, char **argv)
{
    THEA *th;
    th = THEA_Criar(10);

    THEA_Inserir(th, 10, 10);
    THEA_Inserir(th, 21, 21);
    THEA_Inserir(th, 44, 44);
    THEA_Inserir(th, 32, 32);
    THEA_Inserir(th, 12, 12);
    THEA_Inserir(th, 37, 37);
    THEA_Inserir(th, 43, 43);

    THEA_Imprimir(th);
}
