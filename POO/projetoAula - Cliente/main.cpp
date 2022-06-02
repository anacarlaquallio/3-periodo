#include "SystemX.h"
#include "Cliente.h"

int mainProject()
{
    SystemX *sys1 = new SystemX();

    Cliente *c1 = new Cliente();
    c1->id = 123;
    c1->nome = "Lucio";

    if (sys1->cadastrarCliente(*c1))
        std::cout << "Cliente cadastrado com SUCESSO\n";
    else
        std::cout << "Erro cadastrando cliente\n";

    c1 = sys1->pesquisarCliente(123);
    if (c1 != NULL)
        std::cout << "Cliente encontrado e seu nome é " << c1->nome << std::endl;
    else
        std::cout << "Erro cliente não cadastrado\n";

    return 0;
}