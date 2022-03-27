#include <stdio.h>
#include "listaCompras.h"

int main(int argc, char **argv)
{
    char listona[] = "banana melancia maca banana pera ameixa";
    ListaCompras *lc = LC_Criar(listona);
    LC_Imprimir(lc);
    char* s = LC_SemRepeticoes(lc);
    printf("%s\n", s);
    LC_Destruir(lc);
    return EXIT_SUCCESS;
}
