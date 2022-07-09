#include "lista.h"

No::No(int dado)
{
    this->dado = dado;
    this->prox = NULL;
}
int No::obterDado()
{
    return this->dado;
}

No *No::obterProx()
{
    return this->prox;
}
void No::setProx(No *outro)
{
    this->prox = outro;
}

Lista::Lista()
{
    this->inicio = NULL;
    this->fim = NULL;
    this->qtd = 0;
}
Lista::~Lista()
{
    this->qtd = 0;
    delete inicio;
}
Lista::Lista(int elemento)
{
    inicio = new No(elemento);
    fim = inicio;
}
bool Lista::vazia()
{
    return (inicio == NULL);
}
bool Lista::inserir_inicio(int elemento)
{
    No *novo = new No(elemento);
    if (vazia())
    {
        inicio = novo;
        fim = novo;
    }
    else
    {
        fim->setProx(novo);
        fim = novo;
    }
    qtd++;
    return true;
}
bool Lista::inserir_fim(int elemento)
{
    No *novo = new No(elemento);
    if (vazia())
    {
        inicio = novo;
        fim = novo;
    }
    else
    {
        fim->setProx(novo);
        fim = novo;
    }
    qtd++;
    return true;
}
int Lista::tamanho()
{
    if (vazia())
        return 0;
    return qtd;
}
bool Lista::buscar()
{
    No *i = inicio;
    if (vazia())
        return false;

    else
    {
        while (inicio)
        {
            inicio = inicio->obterProx();
        }
    }
    return true;
}
bool Lista::remover()
{
    if (!vazia())
    {
        // se houver só 1 elemento
        if (inicio->obterProx() == NULL)
            inicio = NULL;
        else if (inicio->obterProx()->obterProx() == NULL) // 2 elementos
            inicio->setProx(NULL);
        else // > 2 elementos
        {
            No *ant_ant = inicio;
            No *ant = inicio->obterProx();
            No *corrente = inicio->obterProx()->obterProx();

            while (corrente)
            {
                No *aux = ant;
                ant = corrente;
                ant_ant = aux;
                corrente = corrente->obterProx();
            }

            delete ant_ant->obterProx(); // libera memória
            ant_ant->setProx(NULL);      // seta o prox como NULL
            fim = ant_ant;               // atualiza a cauda
        }
    }
    return true;
}
