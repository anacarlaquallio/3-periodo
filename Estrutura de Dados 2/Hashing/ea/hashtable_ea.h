#pragma once

typedef enum ESTADO {
    E_LIVRE,
    E_OCUPADO,
    E_APAGADO
} ESTADO;

typedef struct ELEM{ // descreve cada elemento da nossa tabela
    int chave;
    int valor;
    ESTADO estado;
} ELEM;

typedef struct THEA{ // estrutura da tabela hash
    int m; // tamanho da tabela
    int n; // quantidade de elementos inseridos na tabela que possuem estado = ocupado
    ELEM* TH; // vetor dinâmico
} THEA;

int THEA_Hash(THEA* TH, int chave, int k); // calcula a hash, retornando um inteiro (a posição). recebe um ponteiro pra tabela, chave e k (quantidade de tentativas)
THEA* THEA_Criar(int m); // retorna um ponteiro para a estrutura hash já inicializado
int THEA_Inserir(THEA *TH, int chave, int valor); // recebe qual é o endereço da tabela que queremos fazer a inserção, qual é a chave e qual o valor que queremos inserir
int THEA_Buscar(THEA *TH, int chave);
void THEA_Remover(THEA* TH, int chave);