#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char **itens;
    int n;
} ListaCompras;

ListaCompras *LC_Criar(char *itens);
void LC_Ordenar(ListaCompras *lc);
char *LC_SemRepeticoes(ListaCompras *lc);
void LC_Imprimir(ListaCompras *lc);
void LC_Destruir(ListaCompras *lc);

#define MAX_ITENS 1000
#define MAX_TAM 21
#define BUF_LEN ((MAX_ITENS * MAX_TAM) + 1)