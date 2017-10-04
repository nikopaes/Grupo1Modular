/***************************************************************************
*  $MCI Módulo de implementação: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.C
*  Letras identificadoras:      CDO
*
*  Nome da base de software:    Fonte do módulo Corpo Docente
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
*     Versão  Autor Data     	Observações
*       0.50   FA   03/10/2017	Funções busca adicionadas
*       0.40   FA   03/10/2017	Funções busca adicionadas
*       0.30   MR   03/10/2017	Funções de get/set adicionadas 
*       0.20   BM   02/10/2017	Funcoes modelo adicionadas 
*       0.10   BM   01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para manipular os professores na lista de corpo docente.
*     Este módulo utiliza funcões de interface do modulo professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corpoDocente.h"
#include "professor.h"
#include "listas.h"

/*
QUESTÃO PARA DISCUTIR:
	Pode parecer estranho ter feito uma estrutura para armazenar apenas uma variável.	
Não sei se durante a execução do programa precisaremos de mais do que um corpo docente. O formato que está pode ser facilmente alterado para suportar mais de uma instância.	
	Basta colocar um parametro "doc", ponteiro para um corpo docente em cada variável, e retirar o "doc" que está no módulo.
*/


typedef struct corpoDocente{
	List *professores;
} CorpoDocente;

CorpoDocente *doc;

/*
LST_cria createList
LIS_adiciona push_front
LIS_reset first()
LIS_getVal get_val_cursor
LIS_next next
LIS_limpa clear
LIS_libera del
*/

// TODO colocar isso no professor.h
typedef Prof *PRF_ptProfessor;

CDO_tpCondRet CDO_cria(){
	doc = (CorpoDocente*) malloc(sizeof(CorpoDocente));
	createList(&doc->professores);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	//TODO verificar retorno de PRF_cria
	PRF_cria(&prof, nome, rg, cpf, matricula, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, complemento);
	push_back(doc->professores, prof);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_mostraAtual(){
	PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_mostra(prof);
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_mostraTodos(){
	PRF_ptProfessor prof = NULL;
	first(doc->professores);
	do{
		//TODO verificar retorno de get_val
		get_val_cursor(doc->professores, (void**) &prof);
		PRF_mostra(prof);
	}while(next(doc->professores)==LIS_CondRetOK);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_limpa(){
	clear(doc->professores);
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_retira(){
	void *nulo;
	pop_cursor(doc->professores, &nulo);
	//pop_cursor(doc->professores, NULL);
	/* TODO 
		colocar uma verificação na lista para ponteiros nulos.
		Assim será possível usar a função pop sem retornar.
		Sem precisar criar uma função só para isso.
		a função pop da lista tenta deferenciar o ponteiro passado,
		passar null pode quebrar o programa,
		não é possivel passar &null
		Para contornar isso, a gambiarra acima foi usada
	*/
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_libera(){
	del(doc->professores);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_buscaPorNome(char *chave){
	PRF_ptProfessor prof = NULL;
	char nome[80];
	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetNaoExisteCorpo;

		PRF_consultaNome(prof, nome);
		if(strcmp(chave, nome)==0) return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}

CDO_tpCondRet CDO_buscaPorEmail(char *chave){
	PRF_ptProfessor prof = NULL;
	char email[80];

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetNaoExisteCorpo;

		PRF_consultaEmail(prof, email);
		if(strcmp(chave, email)==0)
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}

CDO_tpCondRet CDO_buscaPorCpf(char *chave){
	PRF_ptProfessor prof = NULL;
	char cpf[80];

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetNaoExisteCorpo;

		PRF_consultaCpf(prof, cpf);
		if(strcmp(chave, cpf)==0)
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}

CDO_tpCondRet CDO_buscaPorRg(int chave){
	PRF_ptProfessor prof = NULL;
	int rg;

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetNaoExisteCorpo;

		PRF_consultaRg(prof, &rg);
		if(chave == rg) 
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}


CDO_tpCondRet CDO_consultaNome(char *nome){
	PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaNome(prof, nome);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_consultaRg(int *rg){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaRg(prof,rg);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_consultaCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaCpf(prof, cpf);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_consultaMatricula(int *matricula){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaMatricula(prof,matricula);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_consultaEmail(char *email){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaEmail(prof, email);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_consultaTelefone(int *tel){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaTelefone(prof, tel);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_consultaDataNascimento(int *dia, int *mes, int *ano){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaDiaNascimento(prof, dia);
	PRF_consultaMesNascimento(prof, mes);
	PRF_consultaAnoNascimento(prof, ano);
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_consultaEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int *numero, char *complemento){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_consultaPais(prof,pais);
	PRF_consultaUf(prof,uf);
	PRF_consultaCidade(prof,cidade);
	PRF_consultaBairro(prof,bairro);
	PRF_consultaRua(prof,rua);
	PRF_consultaNumero(prof,numero);
	PRF_consultaComplemento(prof,complemento);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraNome(char *nome){
	PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraNome(prof, nome);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraRg(int rg){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraRg(prof,rg);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraCpf(prof, cpf);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraMatricula(int matricula){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraMatricula(prof, matricula);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraEmail(char* email){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraEmail(prof, email);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraTelefone(int tel){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraTelefone(prof, tel);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraDataNascimento(int dia, int mes, int ano){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraDataNascimento(prof, dia, mes, ano);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_alteraEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
    PRF_ptProfessor prof = NULL;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraPais(prof,pais);
	PRF_alteraUf(prof,uf);
	PRF_alteraCidade(prof,cidade);
	PRF_alteraBairro(prof,bairro);
	PRF_alteraRua(prof,rua);
	PRF_alteraNumero(prof,numero);
	PRF_alteraComplemento(prof,complemento);
	return CDO_CondRetOk;
}