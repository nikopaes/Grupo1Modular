#include <stdio.h>
#include <stdlib.h>
#include "corpoDocente.h"

int main(void){
	char nome[80];
	CDO_tpCondRet condRet;
	CDO_cria();

	CDO_cadastra( "Bruce" , 111222333, "12345678901", 1112223, "bmMail@mail", 111222333, 11, 12, 2196, "BrasilComS", "Ra", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	CDO_mostraAtual();

	printf("vamos alterar nome\n");
	printf("%d\n", CDO_alteraNome("Marcellino"));
	CDO_mostraAtual();

	printf("vamos consultar o nome\n");
	CDO_consultaNome(nome);
	printf("%s\n", nome);

	CDO_cadastra( "Souza" , 121222333, "22345678901", 2112223, "cmMail@mail", 211222333, 12, 12, 2196, "BrasilComB", "Rb", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	CDO_cadastra( "Pereira" , 131222333, "32345678901", 3112223, "dmMail@mail", 311222333, 13, 12, 2196, "BrasilComC", "Rc", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	CDO_cadastra( "De" , 141222333, "42345678901", 4112223, "emMail@mail", 411222333, 14, 12, 2196, "BrasilComD", "Rd", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	CDO_cadastra( "Andrade" , 151222333, "52345678901", 5112223, "fmMail@mail", 511222333, 15, 12, 2196, "BrasilComE", "Re", "RioDeJaneiro", "umBairro", "AvQalquer", 666, "defrontePuc");
	CDO_mostraAtual();
	
	printf("vamos retirar o atual\n");
	CDO_retira();
	CDO_mostraAtual();

	printf("vamos mostrar todos\n");
	CDO_mostraTodos();
	CDO_buscaPorMatricula(3112223);
	CDO_deturpadorEstrutural();
	condRet = CDO_verificadorEstrutural();
	if(condRet == CDO_CondRetOk)
		printf("CDO_CondRetOk");
	else if (condRet == CDO_CondRetErroEstruturalNoAnterior)
		printf("CDO_CondRetErroEstruturalNoAnterior");
	else if (condRet == CDO_CondRetErroEstruturalNoProximo)
		printf("CDO_CondRetErroEstruturalNoProximo");
	else if (condRet == CDO_CondRetErroEstruturalLista)
		printf("CDO_CondRetErroEstruturalLista");
	else if (condRet == CDO_CondRetErroEstruturalFirstNull)
		printf("CDO_CondRetErroEstruturalFirstNull");
	else if (condRet == CDO_CondRetErroEstruturalLastNull)
		printf("CDO_CondRetErroEstruturalLastNull");
	else if (condRet == CDO_CondRetErroEstruturalCursorNull)
		printf("CDO_CondRetErroEstruturalCursorNull");
	else if (condRet == CDO_CondRetErroEstruturalFirstPrev)
		printf("CDO_CondRetErroEstruturalFirstPrev");
	else if (condRet == CDO_CondRetErroEstruturalLastNext)
		printf("CDO_CondRetErroEstruturalLastNext");

	CDO_limpa();
	CDO_libera();
	printf("FIM\n");
	return 0;
}
