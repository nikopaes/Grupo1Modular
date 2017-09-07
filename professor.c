#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

/* retirar todos os comentarios deste codigo na versão final e deixar so a documentação antes mandar para o professor*/


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

struct noCorpoDocente{
    Prof* no;
    Prof* prox;
};

struct listaDeProfs{
    struct noCorpoDocente* primeiro;
    struct noCorpoDocente* ultimo;
};

PRF_tpCondRet mostraEndereco(Endereco* end);
PRF_tpCondRet mostraData(Data* d);
int verificaData(int dia, int mes, int ano);


PRF_tpCondRet criaProf(Prof** p, int matricula, char *cpf, char *pais, int dia, int mes, int ano){
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


PRF_tpCondRet mostraProf(Prof* p){
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

PRF_tpCondRet liberaProf(Prof** p){
	free((*p)->dataNascimento);
	free((*p)->endereco);
	free(*p);
	*p=NULL;
	return PRF_CondRetOk;
}



PRF_tpCondRet consultaCpfProf(Prof *professor, char *cpf){
	if(!professor) return PRF_CondRetNaoExisteProf;
	strcpy(cpf, professor->cpf);
	return PRF_CondRetOk;
}

PRF_tpCondRet consultaPaisProf(Prof *professor, char *pais){
	if(!professor) return PRF_CondRetNaoExisteProf;
	strcpy(pais, professor->endereco->pais);
	return PRF_CondRetOk;
}

PRF_tpCondRet consultaMatriculaProf(Prof *professor, int *matricula){
	if(!professor) return PRF_CondRetNaoExisteProf;
	*matricula = professor->matricula;
	return PRF_CondRetOk;
}

/*

PQ ESSAS FUNCOES ESTAO REPETIDAS? ERA PARA ESTAR MESMO?
-Mariana

PRF_tpCondRet alteraCpfProf(Prof *professor, char *cpf){
	if(!professor) return PRF_CondRetNaoExisteProf;
	strcpy(professor->cpf, cpf);
	return PRF_CondRetOk;
}

PRF_tpCondRet alteraPaisProf(Prof *professor, char *pais){
	if(!professor) return PRF_CondRetNaoExisteProf;
	strcpy(professor->endereco->pais, pais);
	return PRF_CondRetOk;
}

PRF_tpCondRet alteraMatriculaProf(Prof *professor, int matricula){
	if(!professor) return PRF_CondRetNaoExisteProf;
	professor->matricula = matricula;
	return PRF_CondRetOk;
}

*/


PRF_tpCondRet ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada){
    struct noCorpoDocente* percorre;
    for(percorre = listaCorpoDocente->primeiro; percorre != NULL; percorre->no = percorre->prox){
        if(percorre->no->matricula= matriculaProcurada){
            mostraProf(percorre->no);
            return PRF_CondRetOk;
        }
    }
}

//----------------------------------------------------------------------------------------------------

/* verifica se a data é válida, retorna 1 se for e 0 caso contrário */
int verificaData(int dia, int mes, int ano){
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

PRF_tpCondRet alteraData(Prof* prof, int dia, int mes, int ano){
	if(verificaData(dia, mes, ano)){
		prof->dataNascimento->ano = ano;
		prof->dataNascimento->mes = mes;
		prof->dataNascimento->dia = dia;
		return PRF_CondRetOk;
	} else {
		return PRF_CondRetFormatoInvalido;
	}
}

//desmembrar!
/*
Usar as verificações aqui incluídas
desmembrar essa função em duas funções para cada variável: consulta e altera. (get/set)

PRF_tpCondRet alteraEndereco(Prof* prof, char* rua, int numero){
	/*  MODO recebe ponteiros para estruturas
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
/* MODO sem ponteiros para estruras além de professor
	if(rua == NULL || strlen(rua) < 0 || strlen(rua) > 80)
		return PRF_CondRetErro;
	if(numero < 0)
		return PRF_CondRetErro;

	strcpy(prof->endereco->rua, rua);
	prof->endereco->numero = numero;
	return PRF_CondRetOk;
	
}
*/

/*alteraEndereco e consultaEndereco desmembrada:*/

PRF_tpCondRet consultaEndereco(Prof* prof){
	if(prof->endereco == NULL)
		return PRF_CondRetErro;
	if(prof->endereco->pais != NULL && strlen(prof->endereco->pais) > 0 && strlen(prof->endereco->pais) <= 80)
		printf("Pais: %s\n", &prof->endereco->pais);
	if(prof->endereco->uf != NULL && strlen(prof->endereco->uf) > 0 && strlen(prof->endereco->uf) <= 3)
		printf("UF: %s\n", &prof->endereco->uf);
	if(prof->endereco->cidade != NULL && strlen(prof->endereco->cidade) > 0 && strlen(prof->endereco->cidade) <= 80)
		printf("Cidade: %s\n", &prof->endereco->cidade);
	if(prof->endereco->bairro != NULL && strlen(prof->endereco->bairro) > 0 && strlen(prof->endereco->bairro) <= 80)
		printf("Bairro: %s\n", &prof->endereco->bairro);
	if(prof->endereco->complemento != NULL && strlen(prof->endereco->complemento) > 0 && strlen(prof->endereco->complemento) <= 80)
		printf("Complemento: %s\n", &prof->endereco->complemento);
		return PRF_CondRetOk;
}


PRF_tpCondRet alteraCasa(Prof* prof, char* rua, int numero, char* complemento){
    //essa funcao altera rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL){
		return PRF_CondRetErro;
	}
	strcpy(rua,prof->endereco->rua);
	prof->endereco->numero = numero;
	strcpy(complemento,prof->endereco->complemento);
		return PRF_CondRetOk;
}

PRF_tpCondRet alteraBairro(Prof* prof, char* bairro, char* rua, int numero, char* complemento){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL){
		return PRF_CondRetErro;
	}
	strcpy(bairro,prof->endereco->bairro);
	alteraCasa(prof,rua,numero,complemento);
		return PRF_CondRetOk;
}

PRF_tpCondRet alteraCidade(Prof* prof, char* cidade, char* bairro, char* rua, int numero, char* complemento){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL){
		return PRF_CondRetErro;
	}
	strcpy(cidade,prof->endereco->cidade);
	alteraBairro(prof,bairro,rua,numero,complemento);
		return PRF_CondRetOk;
}

PRF_tpCondRet alteraUf(Prof* prof, char* uf, char* cidade, char* bairro, char* rua, int numero, char* complemento){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL){
		return PRF_CondRetErro;
	}
	strcpy(uf,prof->endereco->uf);
	alteraCidade(prof,cidade,bairro,rua,numero,complemento);
		return PRF_CondRetOk;
}

PRF_tpCondRet alteraPais(Prof* prof, char* pais, char* uf, char* cidade, char* bairro, char* rua, int numero, char* complemento){
    //essa funcao altera bairro, rua, numero da casa e complemento
	if(prof == NULL || prof->endereco == NULL){
		return PRF_CondRetErro;
	}
	strcpy(pais,prof->endereco->pais);
	alteraUf(prof,uf,cidade,bairro,rua,numero,complemento);
		return PRF_CondRetOk;
}



//desmembrar!
/*
Usar as verificações aqui incluídas
desmembrar essa função em duas funções para cada variável: consulta e altera. (get/set)

PRF_tpCondRet alteraProf(Prof* p, char* nome, char* email, int matricula, int telefone, char* rua, int numero, int dia, int mes, int ano, int rg, char* cpf){
	if(matricula == 0)
		return PRF_CondRetErro;
	if(nome == NULL || strlen(nome) == 0)
		return PRF_CondRetErro;
	strcpy(p->nome, nome);
	p->matricula = matricula;
	if(telefone != 0)
		p->telefone = telefone;
	if(rg != 0)
		p->rg = rg;
	//if(cpf != 0)
		strcpy(p->cpf, cpf);
	if(strlen(email) == 0)
		strcpy(p->email, email);
	if (atualizaEndereco(p, rua, numero) != PRF_CondRetOk)
		return atualizaEndereco(p, rua, numero);
	if (atualizaDataNascimento(p, dia, mes, ano) != PRF_CondRetOk)
		return atualizaDataNascimento(p, dia, mes, ano);
	return PRF_CondRetOk;
}
*/












