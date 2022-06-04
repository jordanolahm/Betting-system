#ifndef SORTEIO_H_INCLUDED
#define SORTEIO_H_INCLUDED

#include "cadastro_menu.h"

int sorteio (Sorteios *sorteios, Data *data_sorteio, Ganhadores *ganhadores);
int verificar_ganhadores (Apostador *apostador, int *total_apostas, Sorteios *sorteios, Ganhadores *ganhadores);
void extrato_premio (Apostador *apostador, int *total_apostas, Sorteios *sorteios, int *acumulado, Ganhadores *ganhadores);
int agendamento (Data *data_sorteio);

#endif // SORTEIO_H_INCLUDED
