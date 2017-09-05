#include <stdio.h>
#include"prof.h"

typedef struct data Data; 
struct data{
int dia;
int mes;
int ano;
};

typedef struct endereco Endereco;
struct endereco{
char pais[40];
char uf[3];
char cidade[80];
char bairro[80];
char rua[80];
int numero;
char complemento[30];
};

typedef struct prof Prof;
struct prof{
char nome[80];
int cpf;
int mat;
char email[80];
int telefone;
Data nascimento;
Endereco casa;
//(discipinas habilitado eh uma lista de disciplinas)
int rg;
};

struct noCorpoDocente{
    Prof* no;
    Prof* prox;
};

struct listaDeProfs{
    struct noCorpoDocente* primeiro;
    struct noCorpoDocente* ultimo;
};

void mostraProf(Prof* p){
	printf("nome: %s\n", &p->nome);
	printf("cpf : %d\n", &p->cpf);
	printf("rg do novo professor : %d\n",&p->rg);
	printf("matricula : %d\n", &p->mat);
	printf("email : %s\n", &p->email);
	printf("telefone : %d \n", &p->email);
	printf("data de nascimento : %d/%d/%d)\n", &p->nascimento.dia, &p->nascimento.mes, &p->nascimento.ano);
	printf("endereco:\n");
	printf(" %s, No %d, complemento:%s, %s, %s, %s, %s\n", &p->casa.rua, &p->casa.numero, &p->casa.complemento, &p->casa.bairro, &p->casa.cidade, &p->casa.uf, &p->casa.pais);
}

void ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada){
    struct noCorpoDocente* percorre;
    for(percorre = listaCorpoDocente->primeiro; percorre != NULL; percorre = percorre->prox){
        if(percorre->no->mat= matriculaProcurada){
            mostraProf(percorre->no);
            break;
        }
    }
}
