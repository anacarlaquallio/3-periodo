#pragma once
#include "Cliente.h"

class ClienteManager
{
    Cliente *cliente;

public:
    bool verificaCPF(int);
    bool verificaEmail (char);
};