#define  _CRT_SECURE_NO_WARNINGS

#include "Prof.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


struct prof 
{
	int matricula;
	char* nome;
};

/* Struct prof CadastrarProf (nome - string, cpf-vetor , matr�cula- vetor, eMail- string, telefone-vetor, 
data de nascimento- struct, endere�o- struct, disciplina habilitado- lista, rg-vetor) */

/*
tpCondRet* CadastraProf(Prof* professor,int NovaMatricula, char* NovoNome)
{
	professor = (Prof*)malloc(sizeof(Prof)); // Alocando professor na memoria 
	if (professor == NULL)
		return tpCondRet.error; // Retorna o tpcondRet referente ao erro de cadastro do professor;
		

	professor->matricula = NovaMatricula; 
	strcpy(professor->nome, NovoNome);

	return tpCondRet.CadastroProfOK;	
}*/


//Fun��o teste que retorn um int
int CadastraProfINT(Prof* professor, int NovaMatricula, char* NovoNome)
{
	professor = (Prof*)malloc(sizeof(Prof*)); // Alocando professor na memoria 
	if (professor == NULL)
		return 0; // Retorna o tpcondRet referente ao erro de cadastro do professor;


	professor->matricula = NovaMatricula;
	strcpy(professor->nome, NovoNome);

	return 1;
}



