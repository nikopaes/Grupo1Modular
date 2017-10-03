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
*     Versão  Autor    		Data     	Observações
*       0.01   BM,FA,NP,MR,RP   01/10/2017	Desenvolvimento para T2 
*
*  $ED Descrição do módulo
*     TODO
*
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
	Basta colocar um parametro doc, ponteiro para um corpo docente em cada variável, e retirar o que está no módulo.

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

//typedef struct Prof *PRF_ptProfessor;

CDO_tpCondRet CDO_cria(){
	doc = (CorpoDocente*) malloc(sizeof(CorpoDocente));
	createList(&doc->professores);
	return CDO_CondRetOk;
}

CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	//PRF_ptProfessor prof;
	Prof *prof = NULL;
	printf("cria: %d\n",PRF_cria(&prof, nome, rg, cpf, matricula, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, complemento));
	push_back(doc->professores, prof);
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_buscaNome(char *chave){
	//PRF_ptProfessor prof;
	Prof *prof;
	int n;
	//char nome[80];
	first(doc->professores);
	list_size(doc->professores, &n);
	printf("tamLista: %d\n", n);
	do{
		//TODO verificar retorno de get_val
		printf("comeca procura\t");
		get_val_cursor(doc->professores, (void**) &prof);
		//PRF_consultaNome(prof, nome);
		//printf("|%s|-|%s|\t", nome, chave);
		PRF_mostra(prof);
		//if(strcmp(chave, nome)==0) return CDO_CondRetOk;
		printf("termina procura\n");
	}while(next(doc->professores)==LIS_CondRetOK);
	//return CDO_naoAchei;
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_mostraAtual(){
	//PRF_ptProfessor prof;
	Prof *prof;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_mostra(prof);
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_alteraNome(char *nome){
	//PRF_ptProfessor prof;
	Prof *prof;
	get_val_cursor(doc->professores, (void**) &prof);
	PRF_alteraNome(prof, nome);
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_limpa(){
	clear(doc->professores);
	return CDO_CondRetOk;
}
CDO_tpCondRet CDO_libera(){
	del(doc->professores);
	return CDO_CondRetOk;
}

