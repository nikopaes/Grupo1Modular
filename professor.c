#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct prof{

/*

nome - string, cpf-vetor , matricula- vetor, eMail- string, telefone-vetor, 
data de nascimento- struct, endereco- struct, disciplina habilitado- lista, rg-vetor

*/

	int mat;
	char nome[80];
};

void criaProf(Prof** p, int mat, char*nome){
	*p = (Prof*) malloc(sizeof(Prof));
	if(!p) printf("ERRO\n");
	(*p)->mat = mat;
	strcpy((*p)->nome, nome);
	printf("ok\n");
}
void mostraProf(Prof* p){
	printf("%d, %s \n", p->mat, p->nome);
}
void liberaProf(Prof* p){
	free(p);
}


