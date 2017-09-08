#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

/* retirar todos os comentarios deste codigo na versão final e deixar so a documentação antes mandar para o professor*/

//------------------------------------------------------------------------- ESTRUTURAS --------------------------------------------------------------------------------------------
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
	char cpf[12];
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
int verificaData(int dia, int mes, int ano);

//------------------------------------------------------------------- FUNÇÃO CRIA --------------------------------------------------------------------------------------------
/* REFATORAR A FUNÇÃO CRIA USANDO AS ALTERA, NÃO ESQUECER DE VERIFICAR O RETORNO DAS FUNÇÕES ALTERA */
PRF_tpCondRet PRF_cria(Prof** p, int matricula, char *cpf, char *pais, int dia, int mes, int ano){
	Data *dataNascimento;
	Endereco *endereco;
		
	Prof *professor;

	if(*p != NULL) return PRF_CondRetProfessorJaCriado;

	*p = (Prof*) malloc(sizeof(Prof));

	professor = *p;

	if(professor == NULL) return PRF_CondRetNaoHaMemoria; //testa alocacao do ponteiro
	
	dataNascimento = (Data*) malloc(sizeof(Data));
	if(dataNascimento == NULL) return PRF_CondRetNaoHaMemoria;

	endereco = (Endereco*) malloc(sizeof(Endereco));
	if(endereco == NULL) return PRF_CondRetNaoHaMemoria;

	strcpy(professor->cpf, cpf);
	professor->matricula = matricula;

	if(!verificaData(dia, mes, ano)) return PRF_CondRetFormatoInvalido;

	dataNascimento->dia = dia;
	dataNascimento->mes = mes;
	dataNascimento->ano = ano;

	strcpy(endereco->pais, pais);

	professor->dataNascimento = dataNascimento;
	professor->endereco = endereco;

	return PRF_CondRetOk;
}


//------------------------------------------------------------------- FUNÇÕES MOSTRA --------------------------------------------------------------------------------------------
PRF_tpCondRet PRF_mostra(Prof* p){
	if(!p) return PRF_CondRetNaoExisteProf;
	printf("Exibindo Professor...\n");
//	printf("nome: %s\n", p->nome);
	printf("cpf : %s\n", p->cpf);
//	printf("rg : %d\n", p->rg);
	printf("matricula : %d\n", p->matricula);
//	printf("email : %s\n", p->email);
//	printf("telefone : %d \n", p->telefone);
	printf("data de nascimento : ");
	mostraData(p->dataNascimento);
	printf("endereco:\n");
	mostraEndereco(p->endereco);
	return PRF_CondRetOk;
}

PRF_tpCondRet mostraEndereco(Endereco* end){
	/* Descomentem as linhas conforme criarem*/

	//printf(" %s,", end->rua);
	//printf("No %d, ", end->numero);
	//printf("complemento:%s, ", end->complemento);
	//printf("%s, ", end->bairro);
	//printf("%s, ", end->cidade);
	//printf("%s, ", end->uf);
	printf("%s, \n", end->pais);
	return PRF_CondRetOk;
}

PRF_tpCondRet mostraData(Data* d){
	printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
	return PRF_CondRetOk;
}


//------------------------------------------------------------------- FUNÇÃO LIBERA --------------------------------------------------------------------------------------------
PRF_tpCondRet PRF_libera(Prof** p){
	free((*p)->dataNascimento);
	free((*p)->endereco);
	free(*p);
	*p=NULL;
	return PRF_CondRetOk;
}

/* 
Incluir esta função no modulo corpoDocente

Note que esta será uma família de funções. Podemos querer disponibilizar a busca por diversos dados como: nome, matricula, etc.

//------------------------------------------------------------------- FUNÇÕES BUSCA --------------------------------------------------------------------------------------------
PRF_tpCondRet ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada){
    struct noCorpoDocente* percorre;
    for(percorre = listaCorpoDocente->primeiro; percorre != NULL; percorre->no = percorre->prox){
        if(percorre->no->matricula= matriculaProcurada){
            mostraProf(percorre->no);
            return PRF_CondRetOk;
        }
    }
}
*/


//------------------------------------------------------------------- FUNÇÕES CONSULTA --------------------------------------------------------------------------------------------
PRF_tpCondRet PRF_consultaNome(Prof* professor, char* nome){
	if(professor == NULL) return PRF_CondRetNaoExisteProf;
	strcpy(nome, professor->nome);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaCpf(Prof *professor, char *cpf){
	if(!professor) return PRF_CondRetNaoExisteProf;
	strcpy(cpf, professor->cpf);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaMatricula(Prof *professor, int *matricula){
	if(!professor) return PRF_CondRetNaoExisteProf;
	*matricula = professor->matricula;
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaEmail(Prof* professor, char* email){
	if(professor == NULL) return PRF_CondRetNaoExisteProf;
	strcpy(email, professor->email);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaTelefone(Prof *professor, int *telefone){
	if(!professor) return PRF_CondRetNaoExisteProf;
	*telefone = professor->telefone;
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaDiaNascimento(Prof *professor, int *dia){
	if(!professor || !professor->data) return PRF_CondRetNaoExisteProf;
	*dia = professor->dataNascimento->dia;
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaMesNascimento(Prof *professor, int *mes){
	if(!professor || !professor->data) return PRF_CondRetNaoExisteProf;
	*mes = professor->dataNascimento->mes;
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaAnoNascimento(Prof *professor, int *ano){
	if(!professor || !professor->data) return PRF_CondRetNaoExisteProf;
	*ano = professor->dataNascimento->ano;
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaPais(Prof *professor, char *pais){
	if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf;
	strcpy(pais, professor->endereco->pais);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaUf(Prof *professor, char *uf){
	if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf;
	strcpy(uf, professor->endereco->uf);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaCidade(Prof *professor, char *cidade){
	if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf;
	strcpy(cidade, professor->endereco->cidade);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaBairro(Prof *professor, char *bairro){
	if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf;
	strcpy(bairro, professor->endereco->bairro);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaRua(Prof *professor, char *rua){
	if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf;
	strcpy(rua, professor->endereco->rua);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaNumero(Prof *professor, int *numero){
	if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf;
	*numero = professor->endereco->numero;
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaComplemento(Prof *professor, char *complemento){
	if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf;
	strcpy(complemento, professor->endereco->complemento);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_consultaRg(Prof *professor, int *rg){
	if(!professor) return PRF_CondRetNaoExisteProf;
	*rg = professor->rg;
	return PRF_CondRetOk;
}


//------------------------------------------------------------------- FUNÇÕES ALTERA --------------------------------------------------------------------------------------------
/* Essas funções recebem um professor e alteram seus atributos */
PRF_tpCondRet PRF_alteraDataNascimento(Prof* prof, int dia, int mes, int ano){
	if(verificaData(dia, mes, ano) == 0)
		return PRF_CondRetFormatoInvalido;
	prof->dataNascimento->ano = ano;
	prof->dataNascimento->mes = mes;
	prof->dataNascimento->dia = dia;
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraRua(Prof* prof, char* rua){
	if(prof == NULL || prof->endereco == NULL))
		return PRF_CondRetNaoExisteProf;
	if(verificaRua(complemento) == 0)

		return PRF_CondRetFormatoInvalido;
	// altera dados
	strcpy(prof->endereco->rua,rua);
	return PRF_CondRetOk;
}
PRF_tpCondRet PRF_alteraNumero(Prof* prof, int numero){
	if(prof == NULL || prof->endereco == NULL))
		return PRF_CondRetNaoExisteProf;
	if(verificaNumero(rua, numero, complemento) == 0)

		return PRF_CondRetFormatoInvalido;
	// altera dados
	prof->endereco->numero = numero;
	return PRF_CondRetOk;
}
PRF_tpCondRet PRF_alteraComplemento(Prof* prof, char* complemento){
	if(prof == NULL || prof->endereco == NULL))
		return PRF_CondRetNaoExisteProf;
	if(verificaComplemento(complemento) == 0)

		return PRF_CondRetFormatoInvalido;
	// altera dados
	strcpy(complemento,prof->endereco->complemento);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraBairro(Prof* prof, char* bairro){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL)
		return PRF_CondRetNaoExisteProf;
	if(verificaBairro(bairro) == 0)
		return PRF_CondRetFormatoInvalido;
	// altera dados
	strcpy(prof->endereco->bairro,bairro);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraCidade(Prof* prof, char* cidade){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL)
		return PRF_CondRetNaoExisteProf;
	if(verificaCidade(cidade) == 0)
		return PRF_CondRetFormatoInvalido;
	// altera dados
	strcpy(prof->endereco->cidade,cidade);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraUf(Prof* prof, char* uf){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL)
		return PRF_CondRetNaoExisteProf;
	if(verificaUf(uf) == 0)
		return PRF_CondRetFormatoInvalido;
	// altera dados
	strcpy(prof->endereco->uf,uf);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraPais(Prof* prof, char* pais){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL)
		return PRF_CondRetNaoExisteProf;
	if(verificaPais(pais) == 0)
		return PRF_CondRetFormatoInvalido;
	// altera dados
	strcpy(prof->endereco->pais,pais);
	return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraNome(Prof* p, char* nome){
    if(verificaNome(nome) == 0)
		return PRF_CondRetFormatoInvalido;
    strcpy(p->nome, nome);
    return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraCpf(Prof* p, char* cpf){
    if(verificaCpf(cpf) == 0)
		return PRF_CondRetFormatoInvalido;
    strcpy(p->cpf, cpf);
    return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraMatricula(Prof* p, int matricula){
    if(verificaMatricula(matricula) == 0)
		return PRF_CondRetFormatoInvalido;
    p->matricula = matricula;
    return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraEmail(Prof* p, char* email){
    if(verificaEmail(email) == 0)
		return PRF_CondRetFormatoInvalido;
    strcpy(p->email, email);
    return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraTelefone(Prof* p, int tel){
    if(verificaTelefone(telefone) == 0)
		return PRF_CondRetFormatoInvalido;
    p->telefone = tel;
    return PRF_CondRetOk;
}

PRF_tpCondRet PRF_alteraRg(Prof* p, int rg){
    if(verificaRg(rg) == 0)
		return PRF_CondRetFormatoInvalido;
    p->rg = rg;
    return PRF_CondRetOk;
}


//------------------------------------------------------------------- FUNÇÕES VERIFICA --------------------------------------------------------------------------------------------
/* Essas funções retornam 1 se a verificação for válida e 0 caso contrário, são funções auxiliares para as funções cria e altera, portanto não são funções de acesso */
int verificaData(int dia, int mes, int ano){
	if(dia < 0 || dia > 31 || mes < 0 || mes > 12 || ano < 1900)
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

int verificaRua(char* rua){
	if(rua == NULL || strlen(rua) == 0 || strlen(rua) > 80)
		return 0;
	return 1;
}
int verificaNumero(char* complemento){
	if(numero < 0)
		return 0;
	return 1;
}
int verificaComplemento(char* complemento){
	if(complemento == NULL || strlen(complemento) == 0 || strlen(complemento) > 80)
		return 0;
	return 1;
}

int verificaBairro(char* bairro){
	if(bairro == NULL || strlen(bairro) == 0 || strlen(bairro) > 80)
		return 0;
	return 1;
}

int verificaCidade(char* cidade){
	if(cidade == NULL || strlen(cidade) == 0 || strlen(cidade) > 80)
		return 0;
	return 1;
}

int verificaUf(char* uf){
	if(uf == NULL || strlen(uf) == 0 || strlen(uf) > 3)
		return 0;
	return 1;
}

int verificaPais(char* pais){
	if(pais == NULL || strlen(pais) == 0 || strlen(pais) > 80)
		return 0;
	return 1;
}

int verificaNome(char* nome){
	if(nome == NULL || strlen(nome) == 0 || strlen(nome) > 80)
		return 0;
	return 1;
}

int verificaCpf(char* cpf){
	if(cpf == NULL || strlen(cpf) < 10 || strlen(cpf) > 12)
		return 0;
	return 1;
}

int verificaMatricula(int matricula){
	if(matricula < 0)
		return 0;
	return 1;
}

int verificaEmail(char* email){
	if(email == NULL || strlen(email) == 0 || strlen(email) > 80)
		return 0;
	return 1;
}

int verificaTelefone(int telefone){
	if(telefone < 0)
		return 0;
	return 1;
}

int verificaRg(int rg){
	if(rg < 0)
		return 0;
	return 1;
}













