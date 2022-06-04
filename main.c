#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cadastro_menu.h"
#include "utilitarios.h"
#include "sorteio.h"

int main()
{
    int tabela[10][10], total_apostas[3] = {0, 0 , 0}, acumulado[3] = {0, 0, 0};
    int indice = 0, verificado = 0, sorteado = 0, agendado = 0;

    Apostador apostador[10];
    Data data_sorteio[2];
    Sorteios sorteios[3];
    Ganhadores ganhadores[10];

    inicialiazarApostador (apostador);
    inicialiazarData_sorteio (data_sorteio);
    inicializarGanhadores (ganhadores);
    inicializar_tabela(tabela);

    menu(tabela, apostador, total_apostas, indice, data_sorteio, acumulado, verificado, sorteado, agendado, sorteios, ganhadores);

    return 0;
}
