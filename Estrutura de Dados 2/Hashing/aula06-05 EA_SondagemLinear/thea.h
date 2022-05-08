#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef enum ESTADO
{
    E_LIVRE,
    E_OCUPADO,
    E_APAGADO
} ESTADO;

typedef struct ELEM
{
    int chave;
    int valor;
    ESTADO estado;
} ELEM;

typedef struct THEA
{
    size_t m;
    ELEM *t;
} THEA;

THEA *THEA_Criar(int m);
int THEA_Hash(THEA *th, int chave, int k);
int THEA_Inserir(THEA *th, int chave, int valor);
int THEA_Imprimir (THEA *th);