#pragma once

#include "SystemX.h"

bool SystemX::cadastrarCliente(Cliente &cliente)
{
    return this->clienteDao->create(cliente);
}

Cliente *SystemX::pesquisarCliente(int clienteId)
{
    ClienteDao *clienteDao1 = new ClienteDao();

    return this->clienteDao->retrieve(clienteId);
}