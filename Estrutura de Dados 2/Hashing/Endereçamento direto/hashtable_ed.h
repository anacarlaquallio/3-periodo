#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ilist.h"

typedef struct THED {
    ILIST** t; // a tabela é um vetor de m elementos e cada posição possui uma lista
    // cada posição vai ter um ponteiro para ILIST, por isso é **
    int m, n; // n = qtd de elementos que a gente inseriu, m é a qtd de listas, endereços
    // n/m vai ser o comprimento das listas
} THED;

unsigned int string_hash(char *string, int M);
int THED_Hash(THED* HT, int chave);
THED* THED_Criar(int m, int alloc_step);
void THED_Inserir(THED* HT, int chave, int valor);
void THED_Remover(THED* HT, int chave);
INOH* THED_Buscar(THED* HT, int chave);
void THED_Imprimir(THED* HT);
size_t THED_N(THED* HT);
ILIST* THED_Chaves(THED* HT);
void THED_Destruir(THED* HT);
int min(THED *HT);
int max(THED *HT);