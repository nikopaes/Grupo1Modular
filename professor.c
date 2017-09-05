#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"



/* Endereco e Data são estruturas bem genéricas então talvez depois fosse bom transferi-las para outro lugar depois.
Aluno também deve usa-las..
*/
typedef struct data{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct endereco{
	char pais[80];
	char uf[3];
	char cidade[80];
	char bairro[80];
	char rua[80];
	int numero;
	char complemento[80];
} Endereco;

struct prof{
	char nome[80];
	int cpf;
	int matricula;
	char email[80];
	int telefone;
	Data* dataNascimento;
	Endereco* endereco;
	int rg;
/*
	As disciplinas que aquele professor pode dar aula estão aqui numa lista
*/

};

PRF_tpCondRet mostraEndereco(Endereco* end);
PRF_tpCondRet mostraData(Data* d);


PRF_tpCondRet criaProf(Prof** p){
	char nome[80];
	int cpf;
	int mat;
	char email[80];
	int telefone;
	Data *dataNascimento;
	Endereco *endereco;
	int rg;

	*p = (Prof*) malloc(sizeof(Prof));
	if(*p == NULL) return PRF_tpCondRetErro; //testa alocacao do ponteiro
	
	dataNascimento = (Data*) malloc(sizeof(Data));
	if(dataNascimento == NULL) return PRF_tpCondRetErro;

	endereco = (Endereco*) malloc(sizeof(Endereco));
	if(endereco == NULL) return PRF_tpCondRetErro;

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

	(*p)->dataNascimento = dataNascimento;
	(*p)->endereco = endereco;

	return PRF_tpCondRetOk;
}



PRF_tpCondRet mostraProf(Prof* p){
	printf("Exibindo Professor...\n");
	printf("nome: %s\n", p->nome);
	printf("cpf : %d\n", p->cpf);
	printf("rg : %d\n", p->rg);
	printf("matricula : %d\n", p->matricula);
	printf("email : %s\n", p->email);
	printf("telefone : %d \n", p->telefone);
	printf("data de nascimento : ");
	mostraData(p->dataNascimento);
	printf("endereco:\n");
	mostraEndereco(p->endereco);
	return PRF_tpCondRetOk;
}

PRF_tpCondRet mostraEndereco(Endereco* end){
	printf(" %s, No %d, complemento:%s, %s, %s, %s, %s\n",
 end->rua,
 end->numero,
 end->complemento,
 end->bairro,
 end->cidade,
 end->uf,
 end->pais);
	return PRF_tpCondRetOk;
}

PRF_tpCondRet mostraData(Data* d){
	printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
	return PRF_tpCondRetOk;
}

PRF_tpCondRet liberaProf(Prof* p){
	free(p->dataNascimento);
	free(p->endereco);
	free(p);
	return PRF_tpCondRetOk;
}

/* verifica se a data é válida, retorna 1 se for e 0 caso contrário */
int eDataValido(int dia, int mes, int ano){
	if(dia < 0 || dia > 31 || mes < 0 || mes > 12 || ano > 1900)
		return 0;
	if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
		if(dia > 0 && dia <= 31){
			return 1;
		} else {
			return 0;
		}
	} else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
		if(dia <= 30){
			return 1;
		} else {
			return 0;
		}
	} else { /* mes 2 (fevereiro) */
		int maxDias = 28;
		if(ano % 4 == 0)
			maxDias = 29;
		if(dia <= maxDias){
			return 1;
		} else {
			return 0;
		}
	}
}

PRF_tpCondRet atualizaDataNascimento(Prof* prof, int dia, int mes, int ano){
	if(eDataValido(dia, mes, ano) == 1){
		prof->dataNascimento->ano = ano;
		prof->dataNascimento->mes = mes;
		prof->dataNascimento->dia = dia;
		return PRF_tpCondRetOk;
	} else {
		return PRF_tpCondRetErro;
	}
}

PRF_tpCondRet atualizaEndereco(Prof* prof, char* rua, int numero){
	/*
	if(endereco == NULL)
		return PRF_tpCondRetErro;
	if(endereco->pais != NULL && strlen(endereco->pais) > 0 && strlen(endereco->pais) <= 80)
		strcpy(prof->endereco->pais, endereco->pais);
	if(endereco->uf != NULL && strlen(endereco->uf) > 0 && strlen(endereco->uf) <= 3)
		strcpy(prof->endereco->uf, endereco->uf);
	if(endereco->cidade != NULL && strlen(endereco->cidade) > 0 && strlen(endereco->cidade) <= 80)
		strcpy(prof->endereco->cidade, endereco->cidade);
	if(endereco->bairro != NULL && strlen(endereco->bairro) > 0 && strlen(endereco->bairro) <= 80)
		strcpy(prof->endereco->bairro, endereco->bairro);
	if(endereco->complemento != NULL && strlen(endereco->complemento) > 0 && strlen(endereco->complemento) <= 80)
		strcpy(prof->endereco->complemento, endereco->complemento);
	*/
	if(rua == NULL || strlen(rua) < 0 || strlen(rua) > 80)
		return PRF_tpCondRetErro;
	if(numero < 0)
		return PRF_tpCondRetErro;

	strcpy(prof->endereco->rua, rua);
	prof->endereco->numero = numero;
	return PRF_tpCondRetOk;
}

PRF_tpCondRet atualizaProf(Prof* p, char* nome, char* email, int matricula, int telefone, char* rua, int numero, int dia, int mes, int ano, int rg, int cpf){
	if(matricula == 0)
		return PRF_tpCondRetErro;
	if(nome == NULL || strlen(nome) == 0)
		return PRF_tpCondRetErro;
	strcpy(p->nome, nome);
	p->matricula = matricula;
	if(telefone != 0)
		p->telefone = telefone;
	if(rg != 0)
		p->rg = rg;
	if(cpf != 0)
		p->cpf = cpf;
	if(strlen(email) == 0)
		strcpy(p->email, email);
	if (atualizaEndereco(p, rua, numero) != PRF_tpCondRetOk)
		return atualizaEndereco(p, rua, numero);
	if (atualizaDataNascimento(p, dia, mes, ano) != PRF_tpCondRetOk)
		return atualizaDataNascimento(p, dia, mes, ano);
	return PRF_tpCondRetOk;
}













