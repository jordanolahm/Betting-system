#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cadastro_menu.h"
#include "sorteio.h"
#include "utilitarios.h"

void menu(int tabela[10][10], Apostador *apostador, int *total_apostas,
          int indice, Data *data_sorteio, int *acumulado, int verificado,
          int sorteado, int agendado, Sorteios *sorteios, Ganhadores *ganhadores)
{
    int opcao = 0;

    do
    {
        printf("...:::Bem vindo ao sistema Tatooine CAP:::...\n");

        printf("Digite:\n");
        printf("1-Para cadastro dos apostadores e seus bilhetes\n");
        printf("2-Para agendamento dos sorteios\n");
        printf("3-Para realizacao dos sorteios\n");
        printf("4-Para a verificacao dos ganhadores e seus premios\n");
        printf("5-Para extrato de premios a ser pago e acumulado\n");
        printf("0-Para sair do sistema\n");
        scanf(" %d", &opcao);
        clearBuffer();

        switch(opcao)
        {
        case 1:
            //CADASTRO DOS APOSTADORES E SEUS BILHETES
            if( !agendado )
            {
                printf("Faca o agendamento antes!\n");
            }
            else
            {
                indice = cadastro(tabela, apostador, total_apostas, indice, data_sorteio);
            }
            if( sorteado )
            {
                printf("Faca a verificacao do sorteio e extrato do premio antes!\n");
            }
            break;
        case 2:
            //AGENDAMENTOS
            agendado = agendamento(data_sorteio);
            break;
        case 3:
            //REALIZACAO DOS SORTEIOS
            if( sorteado )
            {
                printf("Verifique o sorteio antes de fazelo novamente!\n");
                break;
            }
            if( !agendado )
            {
                printf("Faca o agendamento antes!\n");
            }
            else
            {
                sorteado = sorteio(sorteios, data_sorteio, ganhadores);
            }
            break;
        case 4:
            //VERIFICAO DOS GANHADORES E SEUS PREMIOS
            if( !agendado || !sorteado)
            {
                printf("O agendamento nao foi realizado ou nao foi feito o sorteio!\n");
            }
            else
            {
                if(sorteado)
                {
                    verificado = verificar_ganhadores (apostador, total_apostas, sorteios, ganhadores);
                }
            }
            break;
        case 5:
            //EXTRATO DO PREMIO
            if(verificado)
            {
                extrato_premio(apostador, total_apostas, sorteios, acumulado, ganhadores);
                agendado = 0;
                sorteado = 0;
                verificado = 0;
            }
            else
            {
                printf("Voce ainda nao verificou os ganhadores!\n");
            }
            break;
        case 0:
            exit( 0 );
        default:
            printf("opcao invalida\n");
        }
    }
    while ( 1 );

}


int cadastro(int tabela[10][10], Apostador *apostador, int *total_apostas, int indice, Data *data_sorteio)
{
    int opcao = 0, i = indice, j, k, num = 0;
    char resposta;

    printf("Voce escolheu a opcao cadastro.\n\n");

    while(i < 10)
    {
        printf("Iniciando cadastro...\n\n");

        do
        {
            printf("A data de inicio do sorteio eh: %d/%d/%d\n", data_sorteio[0].dia, data_sorteio[0].mes, data_sorteio[0].ano);
            printf("A data do final do sorteio eh: %d/%d/%d\n", data_sorteio[1].dia, data_sorteio[1].mes, data_sorteio[1].ano);
            printf("Digite a data valida para a aposta(DD/MM/AAAA):\n");
            scanf(" %d %d %d", &apostador[i].data_hora.dia, &apostador[i].data_hora.mes, &apostador[i].data_hora.ano);
            clearBuffer();
        }
        while( (apostador[i].data_hora.dia < 1 || apostador[i].data_hora.dia > 31 ) ||
                (apostador[i].data_hora.mes < 1 || apostador[i].data_hora.mes > 12 ) ||
                (apostador[i].data_hora.ano < 2016) );

        if( (apostador[i].data_hora.ano < data_sorteio[0].ano) || (apostador[i].data_hora.ano > data_sorteio[1].ano) )
        {
            printf("Voce nao pode fazer uma aposta nessa data!\n");
            break;
        }

        if( (apostador[i].data_hora.ano == data_sorteio[1].ano) && (apostador[i].data_hora.mes > data_sorteio[1].mes) )
        {
            printf("Voce nao pode fazer uma aposta nessa data!\n");
            break;
        }

        if( (apostador[i].data_hora.ano == data_sorteio[0].ano) && (apostador[i].data_hora.mes < data_sorteio[0].mes) )
        {
            printf("Voce nao pode fazer uma aposta nessa data!\n");
            break;
        }

        if( (apostador[i].data_hora.ano == data_sorteio[1].ano) && (apostador[i].data_hora.mes == data_sorteio[1].mes) && (apostador[i].data_hora.dia > data_sorteio[1].dia) )
        {
            printf("Voce nao pode fazer uma aposta nessa data!\n");
            break;
        }

        if( (apostador[i].data_hora.ano == data_sorteio[0].ano) && (apostador[i].data_hora.mes == data_sorteio[0].mes) && (apostador[i].data_hora.dia < data_sorteio[0].dia) )
        {
            printf("Voce nao pode fazer uma aposta nessa data!\n");
            break;
        }

        do
        {
            printf("Digite o horario valida para a aposta(HH:MM)(Horas 0~23)(Minutos 0~60):\n");
            scanf(" %d %d", &apostador[i].data_hora.horas, &apostador[i].data_hora.minutos);
            clearBuffer();
        }
        while( ( apostador[i].data_hora.horas > 23 || apostador[i].data_hora.horas < 0 )
                || ( apostador[i].data_hora.minutos > 60 || apostador[i].data_hora.minutos < 0 ) );

        if( (apostador[i].data_hora.ano == data_sorteio[1].ano) && (apostador[i].data_hora.mes == data_sorteio[1].mes)
                && (apostador[i].data_hora.dia == data_sorteio[1].dia) && ( apostador[i].data_hora.horas > data_sorteio[1].horas ) )
        {
            printf("Voce nao pode realiazar uma aposta nesse horario!");
            break;
        }

        if( (apostador[i].data_hora.ano == data_sorteio[1].ano) && (apostador[i].data_hora.mes == data_sorteio[1].mes)
                && (apostador[i].data_hora.dia == data_sorteio[1].dia) && ( apostador[i].data_hora.horas == data_sorteio[1].horas )
                && (apostador[i].data_hora.minutos > data_sorteio[1].minutos) )
        {
            printf("Voce nao pode realiazar uma aposta nesse horario!");
            break;
        }

        if( (apostador[i].data_hora.ano == data_sorteio[0].ano) && (apostador[i].data_hora.mes == data_sorteio[0].mes)
                && (apostador[i].data_hora.dia == data_sorteio[0].dia) && ( apostador[i].data_hora.horas < data_sorteio[0].horas ) )
        {
            printf("Voce nao pode realiazar uma aposta nesse horario!");
            break;
        }

        if( (apostador[i].data_hora.ano == data_sorteio[0].ano) && (apostador[i].data_hora.mes == data_sorteio[0].mes)
                && (apostador[i].data_hora.dia == data_sorteio[0].dia) && ( apostador[i].data_hora.horas == data_sorteio[0].horas )
                && (apostador[i].data_hora.minutos < data_sorteio[0].minutos) )
        {
            printf("Voce nao pode realiazar uma aposta nesse horario!");
            break;
        }

        printf("Digite o numero do cadastro\n");
        scanf(" %i", &apostador[i].num_cadastro);
        clearBuffer();

        printf("Digite o nome completo\n");
        scanf(" %s", &apostador[i].nome_completo);
        clearBuffer();

        do
        {
            printf("Digite a data do nascimento valida (18+)(DD/MM/AAAA)\n");
            scanf(" %i %i %i", &apostador[i].data_nascimento.dia, &apostador[i].data_nascimento.mes, &apostador[i].data_nascimento.ano);
            clearBuffer();
        }
        while( (apostador[i].data_nascimento.dia < 1 || apostador[i].data_nascimento.dia > 31 ) ||
               (apostador[i].data_nascimento.mes < 1 || apostador[i].data_nascimento.mes > 12 ) ||
               (apostador[i].data_nascimento.ano > 1998) );


        printf("Digite o RI (Registro imperial)\n");
        scanf(" %li", &apostador[i].RI);
        clearBuffer();

        printf("Digite o endereco\n");
        scanf(" %s", &apostador[i].endereco);
        clearBuffer();

        printf("Digite o telefone para contato\n");
        scanf(" %i", &apostador[i].contato);
        clearBuffer();

        do
        {
            printf("\nEscolha o bilhete desejado:\n");
            printf("(Digite 1) C-3PO- Para escolher 10 numeros. Voce ganhara se acertar 10 numero e seu custo eh de T$10\n");
            printf("(Digite 2) R2-D2- Para escolher 25 numeros. Voce ganhara se acertar 10 numero e seu custo eh de T$75\n");
            printf("(Digite 3) BB-8- Gera-se 50 numeros aleatorios. Voce ganhara se acertar 20 numeros e custa T$955\n");
            scanf(" %d", &opcao);
            clearBuffer();

            if(opcao > 3 || opcao < 1)
            {
                printf("Voce digitou uma opcao invalida!\n");
            }

        }
        while(opcao > 3 || opcao < 1);

        if(opcao == 1)
        {
            printf("Escolha 10 numeros da tabela:");

            total_apostas[0] += 10;
            strcpy(apostador[i].tipo_bilhete, "C-3PO");

            for(j = 0; j < 10; j++)
            {
                printf("\nEscolha o %i numero:\n", j+1);
                visualizar_tabela(tabela);
                scanf(" %i", &num);
                clearBuffer();

                if(num <= 99 && num >= 0)
                {
                    for(k = 0; k < 10; k++)
                    {
                        if( apostador[i].num_apostados[k] == num )
                        {
                            do
                            {
                                k = 0;
                                printf("Esse numero ja foi escolhido ou esse numero nao existe na tabela!\nEscolha um numero diferente.\n");
                                printf("\nEscolha o %i numero:\n", j+1);
                                visualizar_tabela(tabela);
                                scanf(" %i", &num);
                                clearBuffer();
                            }
                            while(num > 99 && num < 0);
                        }
                    }
                    apostador[i].num_apostados[j] = num;
                }
                else
                {
                    printf("Esse numero nao existe na tabela!\nEscolha um numero valido.\n");
                    j--;
                }
            }
        }

        if(opcao == 2)
        {
            printf("Escolha 25 numeros da tabela:");

            total_apostas[1] += 75;
            strcpy(apostador[i].tipo_bilhete, "R2-D2");

            for(j = 0; j < 25; j++)
            {
                printf("\nEscolha o %i numero:\n", j+1);
                visualizar_tabela(tabela);
                scanf(" %i", &num);
                clearBuffer();

                if(num <= 99 && num >= 0)
                {
                    for(k = 0; k < 25; k++)
                    {
                        if( apostador[i].num_apostados[k] == num )
                        {
                            do
                            {
                                k = 0;
                                printf("Esse numero ja foi escolhido ou esse numero nao existe na tabela!\nEscolha um numero diferente.\n");
                                printf("\nEscolha o %i numero:\n", j+1);
                                visualizar_tabela(tabela);
                                scanf(" %i", &num);
                                clearBuffer();
                            }
                            while(num > 99 && num < 0);
                        }
                    }
                    apostador[i].num_apostados[j] = num;
                }
                else
                {
                    printf("Esse numero nao existe na tabela!\nEscolha um numero valido.\n");
                    j--;
                }
            }
        }

        if(opcao == 3)
        {
            srand(time(NULL));
            printf("Gerando 50 numeros da tabela:\n");
            visualizar_tabela(tabela);

            total_apostas[2] += 995;
            strcpy(apostador[i].tipo_bilhete, "BB-8");
            printf("\n");

            for(j = 0; j < 50; j++)
            {
                num = rand()%99;

                for(k = 0; k < 50; k++)
                {
                    if(num == apostador[i].num_apostados[k])
                    {
                        num = rand()%99;
                        k = 0;
                        k --;
                    }
                }
                apostador[i].num_apostados[j] = num;
                printf("|%d| ", apostador[i].num_apostados[j]);
            }
        }

        i++;
        printf("Deseja fazer um novo cadastro?(S/N)\n");
        scanf(" %c", &resposta);
        clearBuffer();

        if(resposta == 'S' || resposta == 's')
        {
            if(i == 10)
            {
                printf("O cadastro chegou ao limite!\nVoltando ao menu\n");
                return i;
            }
        }
        else if(resposta == 'N' || resposta == 'n')
            return i;
        else
        {
            printf("\nResposta invalida!\nRetornando ao menu...\n\n");
            return i;
        }
    }
    return i;
}





