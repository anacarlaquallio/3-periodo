#pragma once

#include <iostream>
#include <string>

class No
{
private:
    int dado;
    No *ant;
    No *prox;

public:
    No(int dado);
    int obterDado();
    No *obterProx();
    void setProx(No *outro);
};
class Lista
{
private:
    No *inicio;
    No *fim;
    int qtd;

public:
    Lista();
    ~Lista();
    Lista(int elemento);
    bool vazia();
    bool inserir_inicio(int elemento);
    bool inserir_fim(int elemento);
    int tamanho();
    bool buscar();
    bool remover();
};
