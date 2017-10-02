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
#include "lista.h"

typedef struct corpoDocente{
	Lista *professores;
} CorpoDocente;

corpoDocente *doc;

CDO_tpCondRet CDO_cria(){
	doc = (CorpoDocente*) malloc(sizeof(CorpoDocente));
	LST_cria(&doc->professores);
}
CDO_tpCondRet CDO_cadastra(Prof** professor, char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_ptProfessor prof = PRF_cria(professor, nome, rg, cpf, matricula, email, telefone, dia, mes, nao, pais, uf, cidade, bairro, rua, complemento);
	LIS_adiciona(doc->professores, prof);
}
CDO_tpCondRet CDO_busca(char *nome){
	ptProfessor prof;
	LIS_reset();
	do{
		if(LIS_getVal(doc->professores, &prof)) break;

		if(strcmp(nome, PRF_getNome(prof)==0) return CDO_achei;

	}while(LIS_next()==LIS_CondRetOK);
	return CDO_naoAchei;
}
