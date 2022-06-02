#pragma once

#include "ClienteDao.h"

bool ClienteDao::create(Cliente &cliente)
{
    if (this->clientesCount == MAX_CLIENTES)
        return false;
    this->clientes[this->clientesCount++] = &cliente;
    return true;
}

Cliente *ClienteDao::retrieve(int clienteId)
{
    for (int i = 0; i < this->clientesCount; i++)
        if (this->clientes[i]->id == clienteId)
            return this->clientes[i];

    return NULL;
}
