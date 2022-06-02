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

bool ClienteDao::update(Cliente &cliente)
{
    Cliente *c = this->retrieve(cliente.id);
    if (c == NULL)
        return false;
    c->nome = cliente.nome;
    c->email = cliente.email;
    c->idade = cliente.idade;
    return true;
}

bool ClienteDao::delet(Cliente &cliente)
{
    Cliente *c = this->retrieve(cliente.id);
    if (c == NULL)
        return false;
    
    return true;
}