#pragma once

#include "Cliente.h"
#include "ClienteDao.h"

class SystemX
{
    ClienteDao *clienteDao = new ClienteDao();

public:
    bool cadastrarCliente(Cliente &);
    Cliente *pesquisarCliente(int);
};