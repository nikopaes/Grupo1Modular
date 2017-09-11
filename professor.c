/***************************************************************************
*  $MCI Módulo de implementação: Módulo professor
*
*  Arquivo gerado:              professor.C
*  Letras identificadoras:      PRF
*
*  Nome da base de software:    Source do módulo professor
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   BM/RP   09/09/2017 Desenvolvimento para T1 modificando TESTARV.C
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para criar,modificar e consultar uma
*     instância de um professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"


//------------------------------------------------------------------------- ESTRUTURAS --------------------------------------------------------------------------------------------

/***********************************************************************
*
*  $TC Tipo de dados: Data
*
*
*  $ED Descrição do tipo
*     Estrutura dados com dia/mes/ano
*
***********************************************************************/
	typedef struct data{
		int dia;
		int mes;
		int ano;
	} Data;

/***********************************************************************
*
*  $TC Tipo de dados: Endereço
*
*
*  $ED Descrição do tipo
*     
*
***********************************************************************/

	typedef struct endereco{
		char pais[80];
		char uf[3];
		char cidade[80];
		char bairro[80];
		char rua[80];
		int numero;
		char complemento[80];
	} Endereco;
/***********************************************************************
*
*  $TC Tipo de dados: prof
*
*
*  $ED Descrição do tipo
*     
*
***********************************************************************/

	struct prof{
		char nome[80];
		char cpf[12];
		int matricula;
		char email[80];
		int telefone;
		Data* dataNascimento;
		Endereco* endereco;
		int rg;
	};

/***** Protótipos das funções encapuladas no módulo *****/

	PRF_tpCondRet mostraEndereco(Endereco* end);
	PRF_tpCondRet mostraData(Data* d);

	int verificaRg(int rg);
	int verificaTelefone(int telefone);
	int verificaEmail(char* email);
	int verificaMatricula(int matricula);
	int verificaCpf(char* cpf);
	int verificaNome(char* nome);
	int verificaPais(char* pais);
	int verificaUf(char* uf);
	int verificaCidade(char* cidade);
	int verificaBairro(char* bairro);
	int verificaComplemento(char* complemento);
	int verificaNumero(int numero);
	int verificaRua(char* rua);
	int verificaData(int dia, int mes, int ano);

/*****  Código das funções exportadas pelo módulo  *****/

//------------------------------------------------------------------- FUNÇÃO CRIA --------------------------------------------------------------------------------------------

/***************************************************************************
*
*  Função: PRF Criar professor
*  ****/

PRF_tpCondRet PRF_cria(Prof** professor, char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_tpCondRet ret;
	Data *dataNascimento;
	Endereco *endereco;
		
	Prof *p;

	if(*professor != NULL) return PRF_CondRetProfessorJaCriado; /* if */

	*professor = (Prof*) malloc(sizeof(Prof));

	p = *professor;

	if(p == NULL) return PRF_CondRetNaoHaMemoria; /* if */
	
	dataNascimento = (Data*) malloc(sizeof(Data));
	if(dataNascimento == NULL) return PRF_CondRetNaoHaMemoria; /* if */

	endereco = (Endereco*) malloc(sizeof(Endereco));
	if(endereco == NULL) return PRF_CondRetNaoHaMemoria; /* if */
	 
	p->dataNascimento = dataNascimento;
	p->endereco = endereco;

	if((ret = PRF_alteraNome(p, nome)) 		!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraRg(p, rg)) 			!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraCpf(p, cpf)) 		!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraMatricula(p, matricula)) 	!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraEmail(p, email)) 		!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraTelefone(p, telefone)) 	!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraDataNascimento(p, dia, mes, ano))	!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraPais(p, pais)) 		!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraUf(p, uf)) 			!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraCidade(p, cidade)) 		!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraBairro(p, bairro)) 		!= PRF_CondRetOk) return ret; /* if */ 
	if((ret = PRF_alteraRua(p, rua))		!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraNumero(p, numero))		!= PRF_CondRetOk) return ret; /* if */
	if((ret = PRF_alteraComplemento(p, complemento))!= PRF_CondRetOk) return ret; /* if */

	return PRF_CondRetOk;
} /* Fim função: PRF Criar professor */


//------------------------------------------------------------------- FUNÇÕES MOSTRA --------------------------------------------------------------------------------------------

/***************************************************************************
*
*  Função: PRF Mostra professor
*  ****/

PRF_tpCondRet PRF_mostra(Prof* professor){
	if(!professor) return PRF_CondRetNaoExisteProf; /* if */
	if(!professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
	if(!professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
	printf("Exibindo Professor...\n"); 
	printf("nome: %s\n", professor->nome);
	printf("cpf : %s\n", professor->cpf);
	printf("rg : %d\n", professor->rg);
	printf("matricula : %d\n", professor->matricula);
	printf("email : %s\n", professor->email);
	printf("telefone : %d \n", professor->telefone);
	printf("data de nascimento : ");
	mostraData(professor->dataNascimento);
	printf("endereco:\n");
	mostraEndereco(professor->endereco);
	return PRF_CondRetOk;
} /* Fim função: PRF Mostra professor */

/***************************************************************************
*
*  Função: PRF Mostra endereço
*  ****/

	PRF_tpCondRet mostraEndereco(Endereco* end){
		printf(" %s,", end->rua);
		printf("No %d, ", end->numero);
		printf("complemento:%s, ", end->complemento);
		printf("%s, ", end->bairro);
		printf("%s, ", end->cidade);
		printf("%s, ", end->uf);
		printf("%s, \n", end->pais);
		return PRF_CondRetOk;
	} /* Fim função: PRF Mostra professor */

/***************************************************************************
*
*  Função: Mostra data
*  ****/	

	PRF_tpCondRet mostraData(Data* d){
		printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
		return PRF_CondRetOk;
	} /* Fim função: Mostra professor */


//------------------------------------------------------------------- FUNÇÃO LIBERA --------------------------------------------------------------------------------------------

/***************************************************************************
*
*  Função: PRF Libera professor
*  ****/	

	PRF_tpCondRet PRF_libera(Prof** professor){
		free((*professor)->dataNascimento);
		free((*professor)->endereco);
		free(*professor);
		*professor=NULL;
		return PRF_CondRetOk;
	} /* Fim função: Libera professor */


//------------------------------------------------------------------- FUNÇÕES CONSULTA --------------------------------------------------------------------------------------------

/***************************************************************************
*
*  Função: PRF Consulta nome
*  ****/	

	PRF_tpCondRet PRF_consultaNome(Prof* professor, char* nome){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(nome, professor->nome);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta nome */


/***************************************************************************
*
*  Função: PRF Consulta CPF
*  ****/	

	PRF_tpCondRet PRF_consultaCpf(Prof *professor, char *cpf){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(cpf, professor->cpf);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta CPF */


/***************************************************************************
*
*  Função: PRF Consulta matricula
*  ****/	

	PRF_tpCondRet PRF_consultaMatricula(Prof *professor, int *matricula){
		if(!professor) return PRF_CondRetNaoExisteProf; /* if */
		*matricula = professor->matricula;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta matricula */


/***************************************************************************
*
*  Função: PRF Consulta email
*  ****/

	PRF_tpCondRet PRF_consultaEmail(Prof* professor, char* email){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(email, professor->email);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta email */


/***************************************************************************
*
*  Função: PRF Consulta telefone
*  ****/

	PRF_tpCondRet PRF_consultaTelefone(Prof *professor, int *telefone){
		if(!professor) return PRF_CondRetNaoExisteProf; /* if */
		*telefone = professor->telefone;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta telefone */


/***************************************************************************
*
*  Função: PRF Consulta dia de nascimento
*  ****/

	PRF_tpCondRet PRF_consultaDiaNascimento(Prof *professor, int *dia){
		if(!professor || !professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
		*dia = professor->dataNascimento->dia;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta dia de nascimento */


/***************************************************************************
*
*  Função: PRF Consulta mês de nascimento
*  ****/

	PRF_tpCondRet PRF_consultaMesNascimento(Prof *professor, int *mes){
		if(!professor || !professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
		*mes = professor->dataNascimento->mes;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta mês de nascimento */


/***************************************************************************
*
*  Função: PRF Consulta ano de nascimento
*  ****/

	PRF_tpCondRet PRF_consultaAnoNascimento(Prof *professor, int *ano){
		if(!professor || !professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
		*ano = professor->dataNascimento->ano;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta ano de nascimento */


/***************************************************************************
*
*  Função: PRF Consulta país
*  ****/

	PRF_tpCondRet PRF_consultaPais(Prof *professor, char *pais){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(pais, professor->endereco->pais);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta país */


/***************************************************************************
*
*  Função: PRF Consulta uf
*  ****/

	PRF_tpCondRet PRF_consultaUf(Prof *professor, char *uf){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(uf, professor->endereco->uf);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta uf */


/***************************************************************************
*
*  Função: PRF Consulta cidade
*  ****/

	PRF_tpCondRet PRF_consultaCidade(Prof *professor, char *cidade){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(cidade, professor->endereco->cidade);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta cidade */


/***************************************************************************
*
*  Função: PRF Consulta bairro
*  ****/

	PRF_tpCondRet PRF_consultaBairro(Prof *professor, char *bairro){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(bairro, professor->endereco->bairro);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta bairro */


/***************************************************************************
*
*  Função: PRF Consulta rua
*  ****/

	PRF_tpCondRet PRF_consultaRua(Prof *professor, char *rua){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(rua, professor->endereco->rua);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta rua */


/***************************************************************************
*
*  Função: PRF Consulta numero
*  ****/

	PRF_tpCondRet PRF_consultaNumero(Prof *professor, int *numero){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		*numero = professor->endereco->numero;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta numero */


/***************************************************************************
*
*  Função: PRF Consulta complemento
*  ****/

	PRF_tpCondRet PRF_consultaComplemento(Prof *professor, char *complemento){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(complemento, professor->endereco->complemento);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta complemento */


/***************************************************************************
*
*  Função: PRF Consulta rg
*  ****/

	PRF_tpCondRet PRF_consultaRg(Prof *professor, int *rg){
		if(!professor) return PRF_CondRetNaoExisteProf; /* if */
		*rg = professor->rg;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta rg */


//------------------------------------------------------------------- FUNÇÕES ALTERA --------------------------------------------------------------------------------------------
/* Essas funções recebem um professor e alteram seus atributos */


/***************************************************************************
*
*  Função: PRF Altera data de Nascimento
*  ****/

	PRF_tpCondRet PRF_alteraDataNascimento(Prof* professor, int dia, int mes, int ano){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		if(verificaData(dia, mes, ano) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		professor->dataNascimento->ano = ano;
		professor->dataNascimento->mes = mes;
		professor->dataNascimento->dia = dia;
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera data de Nascimento */


/***************************************************************************
*
*  Função: PRF Altera rua
*  ****/

	PRF_tpCondRet PRF_alteraRua(Prof* professor, char* rua){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaRua(rua) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		// altera dados
		strcpy(professor->endereco->rua,rua);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera rua */


/***************************************************************************
*
*  Função: PRF Altera rua
*  ****/

	PRF_tpCondRet PRF_alteraNumero(Prof* professor, int numero){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaNumero(numero) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		professor->endereco->numero = numero;
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera numero */


/***************************************************************************
*
*  Função: PRF Altera complemento
*  ****/

	PRF_tpCondRet PRF_alteraComplemento(Prof* professor, char* complemento){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaComplemento(complemento) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		strcpy(professor->endereco->complemento, complemento);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera complemento */


/***************************************************************************
*
*  Função: PRF Altera bairro
*  ****/

	PRF_tpCondRet PRF_alteraBairro(Prof* professor, char* bairro){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaBairro(bairro) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		strcpy(professor->endereco->bairro,bairro);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera bairro */


/***************************************************************************
*
*  Função: PRF Altera cidade
*  ****/

	PRF_tpCondRet PRF_alteraCidade(Prof* professor, char* cidade){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaCidade(cidade) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		strcpy(professor->endereco->cidade,cidade);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera cidade */


/***************************************************************************
*
*  Função: PRF Altera UF
*  ****/

	PRF_tpCondRet PRF_alteraUf(Prof* professor, char* uf){
	    //essa funcao altera bairro, rua, numero da casa e complemento
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaUf(uf) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		// altera dados
		strcpy(professor->endereco->uf,uf);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera UF*/


/***************************************************************************
*
*  Função: PRF Altera país
*  ****/

PRF_tpCondRet PRF_alteraPais(Prof* professor, char* pais){
	if(professor == NULL || professor->endereco == NULL)
		return PRF_CondRetNaoExisteProf; /* if */
	if(verificaPais(pais) == 0)
		return PRF_CondRetFormatoInvalido; /* if */
	strcpy(professor->endereco->pais,pais);
	return PRF_CondRetOk;
} /* Fim função: PRF Altera UF*/


/***************************************************************************
*
*  Função: PRF Altera nome
*  ****/
 
	PRF_tpCondRet PRF_alteraNome(Prof* professor, char* nome){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaNome(nome) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    strcpy(professor->nome, nome);
	    return PRF_CondRetOk;
	} /* Fim função: PRF ALtera nome*/


/***************************************************************************
*
*  Função: PRF Altera CPF
*  ****/

	PRF_tpCondRet PRF_alteraCpf(Prof* professor, char* cpf){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaCpf(cpf) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    strcpy(professor->cpf, cpf);
	    return PRF_CondRetOk;
	} /* Fim função: PRF Altera CPF*/


/***************************************************************************
*
*  Função: PRF Altera matricula
*  ****/

	PRF_tpCondRet PRF_alteraMatricula(Prof* professor, int matricula){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaMatricula(matricula) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    professor->matricula = matricula;
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera matricula*/


/***************************************************************************
*
*  Função: PRF Altera email
*  ****/
 
	PRF_tpCondRet PRF_alteraEmail(Prof* professor, char* email){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaEmail(email) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    strcpy(professor->email, email);
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera email*/


/***************************************************************************
*
*  Função: PRF Altera telefone
*  ****/

	PRF_tpCondRet PRF_alteraTelefone(Prof* professor, int telefone){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaTelefone(telefone) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    professor->telefone = telefone;
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera telefone*/


/***************************************************************************
*
*  Função: PRF Altera RG
*  ****/

	PRF_tpCondRet PRF_alteraRg(Prof* professor, int rg){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaRg(rg) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    professor->rg = rg;
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera RG*/
 

//------------------------------------------------------------------- FUNÇÕES VERIFICA --------------------------------------------------------------------------------------------
/* Essas funções retornam 1 se a verificação for válida e 0 caso contrário, são funções auxiliares para as funções cria e altera, portanto não são funções de acesso */

/***************************************************************************
*
*  Função: Verifica data
*  ****/

	int verificaData(int dia, int mes, int ano){
		if(dia < 0 || dia > 31 || mes < 0 || mes > 12 || ano < 1900)
			return 0; /* if */
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
		} /* if */
	} /* Fim função: Verifica data*/


/***************************************************************************
*
*  Função: Verifica rua
*  ****/

	int verificaRua(char* rua){
		if(rua == NULL || strlen(rua) == 0 || strlen(rua) > 80)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica rua*/


/***************************************************************************
*
*  Função: Verifica numero
*  ****/

	int verificaNumero(int numero){
		if(numero < 0)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica numero*/


/***************************************************************************
*
*  Função: Verifica complemento
*  ****/

	int verificaComplemento(char* complemento){
		if(complemento == NULL || strlen(complemento) == 0 || strlen(complemento) > 80)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica complemento*/

/***************************************************************************
*
*  Função: Verifica bairro
*  ****/

	int verificaBairro(char* bairro){
		if(bairro == NULL || strlen(bairro) == 0 || strlen(bairro) > 80)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica bairro*/

/***************************************************************************
*
*  Função: Verifica cidade
*  ****/

	int verificaCidade(char* cidade){
		if(cidade == NULL || strlen(cidade) == 0 || strlen(cidade) > 80)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica cidade*/


/***************************************************************************
*
*  Função: Verifica bairro
*  ****/

	int verificaUf(char* uf){
		if(uf == NULL || strlen(uf) == 0 || strlen(uf) > 3)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica complemento*/


/***************************************************************************
*
*  Função: Verifica país
*  ****/

	int verificaPais(char* pais){
		if(pais == NULL || strlen(pais) == 0 || strlen(pais) > 80)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica país*/


/***************************************************************************
*
*  Função: Verifica nome
*  ****/

	int verificaNome(char* nome){
		if(nome == NULL || strlen(nome) == 0 || strlen(nome) > 80)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica nome*/


/***************************************************************************
*
*  Função: Verifica cpf
*  ****/

	int verificaCpf(char* cpf){
		if(cpf == NULL || strlen(cpf) < 10 || strlen(cpf) > 12)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica cpf*/


/***************************************************************************
*
*  Função: Verifica email
*  ****/

	int verificaMatricula(int matricula){
		if(matricula < 0)
			return 0; /* if */
		return 1; 
	} /* Fim função: Verifica email*/


/***************************************************************************
*
*  Função: Verifica email
*  ****/

	int verificaEmail(char* email){
		if(email == NULL || strlen(email) == 0 || strlen(email) > 80)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica email*/

/***************************************************************************
*
*  Função: Verifica telefone
*  ****/

	int verificaTelefone(int telefone){
		if(telefone < 0)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica telefone*/


/***************************************************************************
*
*  Função: Verifica rg
*  ****/

	int verificaRg(int rg){
		if(rg < 0)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica rg*/
