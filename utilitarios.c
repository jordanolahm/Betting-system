#include <stdlib.h>
#include <stdio.h>
#include "utilitarios.h"
#include <string.h>

void clearBuffer()
{
    int ch;

    do
        ch = fgetc(stdin);
    while(ch != EOF && ch != '\n' );
}

void inicialiazarApostador ( Apostador *apostador )
{
    int i, j;

    for(i = 0; i < 10; i++)
    {
        strcpy( apostador[i].nome_completo, " " );
        strcpy( apostador[i].endereco, " " );
        strcpy( apostador[i].tipo_bilhete, " " );
        apostador[i].contato = 0;
        apostador[i].data_hora.ano = 0;
        apostador[i].data_hora.mes = 0;
        apostador[i].data_hora.dia = 0;
        apostador[i].data_hora.minutos = 0;
        apostador[i].data_hora.horas = 0;

        for(j = 0; j < 50; j++)
        {
            apostador[i].num_apostados[j] = -1;
        }

        apostador[i].num_cadastro = 0;
        apostador[i].RI = 0;
        apostador[i].data_nascimento.dia = 0;
        apostador[i].data_nascimento.mes = 0;
        apostador[i].data_nascimento.ano = 0;
        apostador[i].data_nascimento.minutos = 0;
        apostador[i].data_nascimento.horas = 0;

    }

  }

void inicialiazarData_sorteio ( Data *data_sorteio )
{
int i;
for(i = 0; i < 2; i++)
    {
        data_sorteio[i].ano = 0;
        data_sorteio[i].mes = 0;
        data_sorteio[i].dia = 0;
    }
}

void inicialiazarSorteios ( Sorteios *sorteios )
{
int i, j;
      for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 10; j++)
        {
            sorteios[i].num_sorteados_1[j] = -1;
        }
        for(j = 0; j < 25; j++)
        {
            sorteios[i].num_sorteados_2[j] = -1;
        }
        for(j = 0; j < 50; j++)
        {
            sorteios[i].num_sorteados_3[j] = -1;
        }
    }
}

void inicializarGanhadores (Ganhadores *ganhadores)
{
    int i;

    for(i = 0; i < 10; i++)
    {
        ganhadores[i].num_cadastro = -1;
    }
}

void visualizar_tabela(int tabela[10][10])
{
    int i, j;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            printf("|%.2d|", tabela[i][j]);
        }
        printf("\n");
    }
}

void inicializar_tabela(int tabela[10][10])
{
    int i, j, preencher_matriz = 0;

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            tabela[i][j]=preencher_matriz;
            preencher_matriz++;
        }
    }
}



