#include <stdio.h>
#include"prof.h"

/*Esse arquivo contem algumas funções e trechos de codigo que usaremos no futuro.
Contem:
	-> a função obtemProfessor, inclui-la no modulo corpo docente.
	-> contem uma versão da função criaProfessro com scanf.



*/


/*	CriaProfessor modo scanf. Incluir isso numa interface */
	
	printf("nome do novo professor\n");
	scanf(" %s", nome);
	strcpy((*p)->nome, nome);

	printf("cpf do novo professor\n");
	scanf(" %d",&cpf);
	(*p)->cpf=cpf;

	printf("rg do novo professor\n");
	scanf(" %d",&rg);
	(*p)->rg = rg;

	printf("matricula do novo professor\n");
	scanf(" %d",&mat);
	(*p)->matricula = mat;

	printf("email do novo professor\n");
	scanf(" %s",email);
	strcpy((*p)->email, email);

	printf("telefone do novo professor\n");
	scanf(" %d",&telefone);
	(*p)->telefone = telefone;
	
	printf("data de nascimento do novo professor(DD/MM/AA)\n");
	scanf(" %d/%d/%d",&(dataNascimento->dia), &(dataNascimento->mes),&(dataNascimento->ano));

	printf("endereco do novo professor:\n");

	printf(" rua:\n");
	scanf(" %s",endereco->rua);

	printf(" numero:\n");
	scanf(" %d",&(endereco->numero));

	printf(" complemento:\n");
	scanf(" %s",endereco->complemento);

	printf(" bairro:\n");
	scanf(" %s",endereco->bairro);

	printf(" cidade:\n");
	scanf(" %s",endereco->cidade);

	printf(" UF:\n");
	scanf(" %s",endereco->uf);

	printf(" pais:\n");
	scanf(" %s",endereco->pais);

//-----------------------------

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


/* Incluir isso em corpo docente */
void ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada){
    struct noCorpoDocente* percorre;
    for(percorre = listaCorpoDocente->primeiro; percorre != NULL; percorre = percorre->prox){
        if(percorre->no->mat= matriculaProcurada){
            mostraProf(percorre->no);
            break;
        }
    }
}

