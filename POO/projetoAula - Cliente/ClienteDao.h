#pragma once

#include "Cliente.h"

#define MAX_CLIENTES 10
class ClienteDao
{
    Cliente *clientes[MAX_CLIENTES];
    int clientesCount = 0;

public:
    bool create(Cliente &);
    Cliente *retrieve(int);
    bool update(Cliente &);
    bool delet(Cliente &);
};