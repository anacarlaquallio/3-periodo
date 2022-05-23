#include <stdlib.h>
#include <stdio.h>
#include "hashtable_ea.h"

static void THEA_Redimensionar(THEA *TH, int novo_m) // static serve para impedir que a função seja usada de fora do arquivo .c
{
    // aloca uma nova tabela que tenha o tamanho novo m
    // insere os elementos da tabela antiga na tabela nova
    // libera a tabela antiga
    // vai realocar o valor de registro dos elementos e ligar ele na tabela nova
    ELEM *nova, *antiga;
    int m_antigo;
    nova = malloc(sizeof(ELEM) * novo_m); // aloca a nova tabela com novo m
    for (int i = 0; i < novo_m; i++)
        nova[i].estado = E_LIVRE; // passa por todos os elementos setando eles como livres
    antiga = TH->TH; // salvar a tabela antiga
    m_antigo = TH->m; // salvar o m antigo
    TH->TH = nova; //ligamos a tabela
    TH->n = 0; // reseta o n para 0; o inserir já atualiza o n da forma correta
    TH->m = novo_m;
    for (int i = 0; i < m_antigo; i++)
        if (antiga[i].estado == E_OCUPADO) // se o elemento atual na tabela antiga é ocupado
            THEA_Inserir(TH, antiga[i].chave, antiga[i].valor); // vai inserir as chaves e valores na tabela nova
    free(antiga);
}

int THEA_Hash(THEA *TH, int chave, int k)
{
    return ((chave % TH->m) + k) % TH->m;
}

THEA *THEA_Criar(int m)
{
    // criar uma instância da estrutura da tabela hash
    // salva valor de m
    // aloca dinamicamente todos os elementos da tabela
    // marcar os elementos coomo livres

    THEA *nova;
    nova = malloc(sizeof(THEA));
    nova->m = m;
    nova->n = 0;
    nova->TH = malloc(sizeof(ELEM) * m);
    for (int i = 0; i < m; i++) // passa por todos os elementos da tabela, atribuindo o estado livre
        nova->TH[i].estado = E_LIVRE;
    return nova; // retorna a tabela que acabamos de alocar
}

int THEA_Inserir(THEA *TH, int chave, int valor)
{
    int h, k, h_inicial;
    h = THEA_Buscar(TH, chave);
    if (h >= 0) // se a chave está na tabela
    {
        TH->n--; // decrementa o n quando encontramos uma repetição, pois é incrementado abaixo independente se o valor é repetido ou não
    }
    else
    {
        k = 0;

        if (TH->n > TH->m / 2) // detectar que está na hora de redimensionar a tabela, com base no fator de carga
        {
            printf("Tabela redimensionada de m=%d para %d", TH->m, TH->m * 2); // dobrar a capacidade da tabela (quebra a recomendação de que M deve ser primo)
            // Obs: não é o caso feito aqui, mas M deve ser primo tal próximo de M*2
            printf("(n = %d)\n", TH->n);
            THEA_Redimensionar(TH, TH->m * 2);
        }
        h = THEA_Hash(TH, chave, k);
        h_inicial = h;
        while (TH->TH[h].estado == E_OCUPADO)
        {
            if (TH->TH[h].chave == chave)
                break;
            k++;                         // posição ++
            h = THEA_Hash(TH, chave, k); // calcula uma nova hash com k++
            if (h == h_inicial)          // se h for igual ao inicial, não foi possível fazer a inserção pq não tem espaço
                return -1;
        }
    }
    TH->n++; // conta que está ocupado
    // na tabela hash na posição h vamos atribuir a chave, o valor e o estado como ocupado
    TH->TH[h].chave = chave;
    TH->TH[h].valor = valor;
    TH->TH[h].estado = E_OCUPADO;

    return h;
}

int THEA_Buscar(THEA *TH, int chave)
{
    // dado uma chave, queremos descobrir qual elemento que tem ela e se está na tabela
    // primeiro calcula a hash da chave e vai olhar para aquela posição na tabela
    // só vai estar válido se o estado do elemento for ocupado 
    int h, h_inicial, k;
    k = 0;
    h = THEA_Hash(TH, chave, k);
    h_inicial = h;

    while (TH->TH[h].estado != E_LIVRE)
    {
        if ((TH->TH[h].estado == E_OCUPADO) && (TH->TH[h].chave == chave)) // uma vez que o estado estiver ocupado e a chave bater com a qual estamos procurando, então encontramos o elemento
            return h; // retorna a posição do elemento
        // senão incrementa as tentativas, isto é, testa o próximo deslocamento, e atualiza a hash
        k++;
        h = THEA_Hash(TH, chave, k);
        if (h_inicial == h) // se passou por toda a lista e voltou ao começo
            return -1;
    }
    return -1; // retorna -1 com o caso em que o estado se tornou livre
}

void THEA_Remover(THEA *TH, int chave)
{
    // dado uma determinada chave, queremos remover o elemento correspondente àquela chave da tabela
    // temos que considerar que a remoção em uma tabela hash é simplesmente marcar o elemento correspondente àquela chave como um elemento que não é mais válido
    // não é necessário sobrescrever os valores, basta marcar o estado como inválido
    int p = THEA_Buscar(TH, chave);
    if (p >= 0) // se achou
    {
        TH->TH[p].estado = E_APAGADO;
        TH->n--; // decrementa n indicando que temos um elemento a menos com o estado ocupado ocupando a tabela hash
    }
}