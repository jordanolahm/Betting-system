#ifndef CADASTRO_MENU_H_INCLUDED
#define CADASTRO_MENU_H_INCLUDED

typedef struct{
    int dia;
    int mes;
    int ano;
    int horas;
    int minutos;
}Data;

typedef struct{
    int num_cadastro;
    char nome_completo[25];
    Data data_nascimento;
    long int RI;
    char endereco[50];
    int contato ;
    Data data_hora;
    char tipo_bilhete[5];
    int num_apostados[50];
}Apostador;

typedef struct{
    int num_sorteio;
    int num_sorteados_1[10];
    int num_sorteados_2[25];
    int num_sorteados_3[50];

}Sorteios;

typedef struct{
    int num_cadastro;
}Ganhadores;

void menu(int tabela[10][10], Apostador *apostador, int *total_apostas, int indice,
          Data *data_sorteio, int *acumulado, int verificado, int sorteado, int agendado,
          Sorteios *sorteios, Ganhadores *ganhadores);
int cadastro(int tabela[10][10], Apostador *apostador, int *total_apostas, int indice, Data *data_sorteio);

#endif // CADASTRO_MENU_H_INCLUDED
