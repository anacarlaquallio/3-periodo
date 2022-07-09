#include "lista.h"

int main()
{
    Lista lista1;

    if (lista1.inserir_inicio(123))
        std::cout << "Deu tudo certo" << std::endl;
    else
        std::cout << "Algo de errado não está certo!" << std::endl;

    return 0;
}