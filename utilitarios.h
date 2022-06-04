#ifndef UTILITARIOS_H_INCLUDED
#define UTILITARIOS_H_INCLUDED

#include "cadastro_menu.h"
#include "sorteio.h"

void InicializaVetor(int *vet);
void clearBuffer();
void inicialiazarApostador ( Apostador *apostador );
void inicialiazarData_sorteio ( Data *data_sorteio );
void inicialiazarSorteios ( Sorteios *sorteios );
void inicializarGanhadores (Ganhadores *ganhadores);
void visualizar_tabela(int tabela[10][10]);
void inicializar_tabela(int tabela[10][10]);
#endif // UTILITARIOS_H_INCLUDED
