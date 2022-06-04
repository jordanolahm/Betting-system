#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitarios.h"
#include "cadastro_menu.h"

int sorteio(Sorteios *sorteios, Data *data_sorteio, Ganhadores *ganhadores)
{
    int j, k, num = 0;
    int dia = 0, mes = 0, ano = 0;
    int horas = 0, minutos = 0;

    inicialiazarSorteios(sorteios);

    printf("Voce escolheu a opcao realizacao do sorteio\n");

    do
    {
        printf("A data do sorteio sera no dia %d/%d/%d\n", data_sorteio[1].dia, data_sorteio[1].mes, data_sorteio[1].ano);
        printf("Digite corretamente a data de hoje(DD/MM/AAAA):\n");
        scanf(" %d %d %d", &dia, &mes, &ano);
        clearBuffer();
    }
    while((dia < 1 || dia > 31 ) || (mes < 1 || mes > 12) || (ano < 2016));

    if( ano != data_sorteio[1].ano )
    {
        printf("O sorteio nao sera realiazado hoje!\nFique atendo ao dia\n");
        return 0;
    }

    if( (ano == data_sorteio[1].ano) && (mes != data_sorteio[1].mes) )
    {
        printf("O sorteio nao sera realiazado hoje!\nFique atendo ao dia\n");
        return 0;
    }

    if( (ano == data_sorteio[1].ano) && (mes == data_sorteio[1].mes) && (dia != data_sorteio[1].dia) )
    {
        printf("O sorteio nao sera realiazado hoje!\nFique atendo ao dia\n");
        return 0;
    }

    do
    {
        printf("A hora do sorteio sera %.2d:%.2d\n", data_sorteio[1].horas, data_sorteio[1].minutos);
        printf("Digite o horario valido de hoje(HH:MM)(Horas 0~23)(Minutos 0~60):\n");
        scanf(" %d %d", &horas, &minutos);
        clearBuffer();
    }
    while( ( horas > 23 || horas < 0 )
        || ( minutos > 60 || minutos < 0 ) );

    if( (ano == data_sorteio[1].ano) && (mes == data_sorteio[1].mes) && (dia == data_sorteio[1].dia)
            && ( horas != data_sorteio[1].horas ) && ( minutos != data_sorteio[1].minutos ) )
    {
        printf("O sorteio nao sera realiazado nesse horario!\nFique atendo ao horario\n");
        return 0;
    }

    //SORTEIO PARA O 1 TIPO
    for(j = 0; j < 10; j++)
    {
        num = rand()%99;

        for(k = 0; k < 10; k++)
        {
            if( num == sorteios[0].num_sorteados_1[k] )
            {
                num = rand()%99;
                k = 0;
                k --;
            }
        }
        sorteios[0].num_sorteados_1[j] = num;
    }

    printf("Os numeros sorteados sao:\n");

    for(j = 0; j < 10; j++)
    {
        printf("|%d| ", sorteios[0].num_sorteados_1[j]);
    }
    printf("\n");

    printf("Sorteio 1 realizado!\n");

    //SORTEIO PARA O TIPO 2

    for(j = 0; j < 25; j++)
    {
        num = rand()%99;

        for(k = 0; k < 25; k++)
        {
            if( num == sorteios[1].num_sorteados_2[k] )
            {
                num = rand()%99;
                k = 0;
                k --;
            }
        }
        sorteios[1].num_sorteados_2[j] = num;
    }

    printf("Os numeros sorteados sao:\n");

    for(j = 0; j < 25; j++)
    {
        printf("|%d| ", sorteios[1].num_sorteados_2[j]);
    }
    printf("\n");

    printf("Sorteio 2 realizado!\n");

    //SORTEIO PARA O 3 TIPO

    for(j = 0; j < 50; j++)
    {
        num = rand()%99;

        for(k = 0; k < 50; k++)
        {
            if(num == sorteios[2].num_sorteados_2[k])
            {
                num = rand()%99;
                k = 0;
                k --;
            }
        }
        sorteios[2].num_sorteados_2[j] = num;
    }

    printf("Os numeros sorteados sao:\n");

    for(j = 0; j < 50; j++)
    {
        printf("|%d| ", sorteios[2].num_sorteados_2[j]);
    }
    printf("\n");

    printf("Sorteio 3 realizado!\n");
    inicialiazarData_sorteio (data_sorteio);

    return 1;
}


int verificar_ganhadores (Apostador *apostador, int *total_apostas, Sorteios *sorteios, Ganhadores *ganhadores)
{
    int i, j, k, cont = 0, num_ganhadores[3] = {0, 0, 0};

    printf("Voce escolheu a verificacao dos ganhadores e seus premios\n");

    for(i = 0; i < 10; i++)
    {
        if( strcmp(apostador[i].tipo_bilhete, "C-3PO") == 0)
        {
            for (j = 0; j < 10; j++)
            {
                for (k = j; k < 10; k++)
                {
                    if( apostador[i].num_apostados[j] == sorteios[0].num_sorteados_1[k] )
                    {
                        cont++;
                    }
                }
            }

            if(cont == 10)
            {
                num_ganhadores[0]++;
                ganhadores[i].num_cadastro = apostador[i].num_cadastro;

                printf("O apostador(a) %s eh um ganhador\n", apostador[i].nome_completo);
                printf("Numeros apostados\n");

                for(j = 0; j < 10; j++)
                {
                    printf("%d ", apostador[i].num_apostados[j]);
                }
                printf("\n");
            }
        }

        if( strcmp(apostador[i].tipo_bilhete, "R2-D2") == 0)
        {
            for (j = 0; j < 25; j++)
            {
                for (k = j; k < 25; k++)
                {
                    if(apostador[i].num_apostados[j] == sorteios[1].num_sorteados_2[k])
                    {
                        cont++;
                    }
                }
            }

            if(cont-10 >= 0)
            {
                num_ganhadores[1]++;
                ganhadores[i].num_cadastro = apostador[i].num_cadastro;

                printf("O apostador(a) %s eh um ganhador\n", apostador[i].nome_completo);
                printf("Numeros apostados\n");

                for(j = 0; j < 25; j++)
            {
                printf("%d ", apostador[i].num_apostados[j]);
                }
                printf("\n");
            }
        }

        if( strcmp(apostador[i].tipo_bilhete, "BB-8") == 0)
        {
            for (j = 0; j < 50; j++)
            {
                for (k = j; k < 50; k++)
                {
                    if(apostador[i].num_apostados[j] == sorteios[2].num_sorteados_3[k])
                    {
                        cont++;
                    }
                }
            }

            if(cont-20 >= 0)
            {
                num_ganhadores[2]++;
                ganhadores[i].num_cadastro = apostador[i].num_cadastro;

                printf("O apostador(a) %s eh um ganhador\n", apostador[i].nome_completo);
                printf("Numeros apostados\n");

                for(j = 0; j < 20; j++)
            {
                printf("%d ", apostador[i].num_apostados[j]);
                }
                printf("\n");
            }
        }

        cont = 0;//ZERAR O CONTADOR PARA FAZER NOVA ANALISE

    }

    if(num_ganhadores[0] > 0)
    {
        total_apostas[0] = total_apostas[0] * 0.75;
        total_apostas[0] = total_apostas[0] / num_ganhadores[0];
    }

    if(num_ganhadores[1] > 0)
    {
        total_apostas[1] = total_apostas[1] * 0.50;
        total_apostas[1] = total_apostas[1] / num_ganhadores[1];
    }

    if(num_ganhadores[2] > 0)
    {
        total_apostas[2] = total_apostas[2] * 0.30;
        total_apostas[2] = total_apostas[2] / num_ganhadores[2];
    }

    for(i = 0; i < 3; i++)
    {
        if (num_ganhadores[i] == 0)
        {
            printf("Nao ha ganhadores para o bilhete do tipo %d\n", i+1);
        }
    }

    printf("A verificacao foi feita\n");

    return 1;
}


void extrato_premio(Apostador *apostador, int *total_apostas, Sorteios *sorteios, int *acumulado, Ganhadores *ganhadores)
{
    int vetCont[3] = {0, 0, 0}, i;

    printf("Voce escolheu extrato de premios a ser pago e acumulado\n");

    for(i = 0; i < 10; i++)
    {
        if ( apostador[i].num_cadastro == ganhadores[i].num_cadastro )
        {
            printf("Dados do ganhador:\n");
            printf("Apostador(a) %s\n", apostador[i].nome_completo );
            printf("numero de cadastro: %d\n", apostador[i].num_cadastro );
            printf("Nascido em: %d/%d/%d\n", apostador[i].data_nascimento.dia, apostador[i].data_nascimento.mes, apostador[i].data_nascimento.ano);
            printf("RI(Registro imperial): %ld\n", apostador[i].RI );
            printf("Endereço: %s\n", apostador[i].endereco );
            printf("telefone: %d\n", apostador[i].contato );
            printf("Data da aposta: %d/%d/%d\n", apostador[i].data_hora.dia, apostador[i].data_hora.mes, apostador[i].data_hora.ano );
            printf("Horario da aposta: %d:%d", apostador[i].data_hora.horas, apostador[i].data_hora.minutos);
            printf("Tipo do bilhete: %s\n", apostador[i].tipo_bilhete);

            if( strcmp(apostador[i].tipo_bilhete, "C-3PO") == 0)
            {
                printf("O premio recebido eh de: %d\n", total_apostas[0]);
                vetCont[0]++;
            }

            if( strcmp(apostador[i].tipo_bilhete, "R2-D2") == 0)
            {
                printf("O premio recebido eh de: %d\n", total_apostas[1]);
                vetCont[1]++;
            }

            if( strcmp(apostador[i].tipo_bilhete, "BB-8") == 0)
            {
                printf("O premio recebido eh de: %d\n", total_apostas[2]);
                vetCont[2]++;
            }
        }
    }

    if(vetCont[0] == 0)
    {
        printf("O premio 1 foi acumulado!\n");
        printf("O valor acumulado eh %d\n", total_apostas[0]);
        acumulado[0]++;
    }

    if(vetCont[0] > 0)
    {
        acumulado[0] = 0;
        total_apostas[0] = 0;
    }

    if(acumulado[0] == 3)
    {
        printf("Como houve 3 acumulacoes no sorteio 1, o dinheiro foi para o imperio\n");
        total_apostas[0] = 0;
        acumulado[0] = 0;
    }

    if(vetCont[1] == 0)
    {
        printf("O premio 2 foi acumulado!\n");
        printf("O valor acumulado eh %d\n", total_apostas[1]);
        acumulado[1]++;
    }

    if(vetCont[1] > 0)
    {
        acumulado[1] = 0;
        total_apostas[1] = 0;
    }

    if(acumulado[1] == 3)
    {
        printf("Como houve 3 acumulacoes no sorteio 2, o dinheiro foi para o imperio\n");
        total_apostas[1] = 0;
        acumulado[1] = 0;
    }

    if(vetCont[2] == 0)
    {
        printf("O premio 3 foi acumulado!\n");
        printf("O valor acumulado eh %d\n", total_apostas[2]);
        acumulado[2]++;
    }

    if(vetCont[2] > 0)
    {
        acumulado[2] = 0;
        total_apostas[2] = 0;
    }

    if(acumulado[2] == 3)
    {
        printf("Como houve 3 acumulacoes no sorteio 3, o dinheiro foi para o imperio\n");
        total_apostas[2] = 0;
        acumulado[2] = 0;
    }
    inicializarGanhadores (ganhadores);
    inicialiazarApostador (apostador);
}


int agendamento(Data *data_sorteio)
{

    printf("Voce escolheu a opcao agendamento do sorteio\n");

    do
    {
        printf("Digite uma data valida para o inicio do sorteio(DD/MM/AAAA)\n");
        scanf(" %d %d %d", &data_sorteio[0].dia, &data_sorteio[0].mes, &data_sorteio[0].ano);
        clearBuffer();
    }
    while( (data_sorteio[0].dia < 1 || data_sorteio[0].dia > 31 )
            || (data_sorteio[0].mes < 1 || data_sorteio[0].mes > 12)
            || (data_sorteio[0].ano < 2016) );


    data_sorteio[0].horas = 18;
    data_sorteio[0].minutos = 00;


    do
    {
        printf("Digite uma data valida para o final do sorteio(DD/MM/AAAA)\n");
        scanf(" %d %d %d", &data_sorteio[1].dia, &data_sorteio[1].mes, &data_sorteio[1].ano);
        clearBuffer();

        while(data_sorteio[1].ano < data_sorteio[0].ano)
        {
            printf("Digite uma data posterior!\n");
            printf("Digite uma ano valida para o final do sorteio(AAAA)\n");
            scanf(" %d", &data_sorteio[1].ano);
            clearBuffer();
        }

        while( (data_sorteio[1].ano == data_sorteio[0].ano) && (data_sorteio[1].mes < data_sorteio[0].mes) )
        {
            printf("Digite uma data posterior!\n");
            printf("Digite um mes valido para o final do sorteio(MM)\n");
            scanf(" %d", &data_sorteio[1].mes);
            clearBuffer();
        }

        while( (data_sorteio[1].ano == data_sorteio[0].ano) && (data_sorteio[1].mes == data_sorteio[0].mes) && (data_sorteio[1].dia < data_sorteio[0].dia) )
        {
            printf("Digite uma data posterior!\n");
            printf("Digite um dia valido para o final do sorteio(DD)\n");
            scanf(" %d", &data_sorteio[1].dia);
            clearBuffer();
        }
    }
    while( (data_sorteio[1].dia < 1 || data_sorteio[1].dia > 31 ) || (data_sorteio[1].mes < 1 || data_sorteio[1].mes > 12) || (data_sorteio[1].ano < 2016) );

    data_sorteio[1].horas = 20;
    data_sorteio[1].minutos = 00;

    printf("O agendamento foi realizado\n");
    printf("A data de inicio do sorteio eh: %d %d %d\n", data_sorteio[0].dia, data_sorteio[0].mes, data_sorteio[0].ano);
    printf("A data do final do sorteio eh: %d %d %d\n", data_sorteio[1].dia, data_sorteio[1].mes, data_sorteio[1].ano);
    printf("A hora do sorteio inicial eh: %d:%d\n", data_sorteio[0].horas, data_sorteio[0].minutos);
    printf("A hora do sorteio final eh: %d:%d\n", data_sorteio[1].horas, data_sorteio[1].minutos);

    return 1;
}

