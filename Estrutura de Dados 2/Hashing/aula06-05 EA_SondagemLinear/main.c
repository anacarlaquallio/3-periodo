#include "thea.h"

int main(void)
{
    THEA *t;
    t = THEA_Criar(10);

    THEA_Inserir(t, 10, 10);
    THEA_Inserir(t, 21, 21);
    THEA_Inserir(t, 44, 44);
    THEA_Inserir(t, 32, 32);
    THEA_Inserir(t, 12, 12);
    THEA_Inserir(t, 37, 37);
    THEA_Inserir(t, 43, 43);

    THEA_Imprimir(t);

    return EXIT_SUCCESS;
}