#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 80

void toUpperCase(char *dest, char *s){
	while(*s){
		*dest = *s;
		if('a' <= *s && *s <= 'z' ) 
			*dest += 'A'-'a';
		s++; dest++;
	}
	*dest = '\0';
}

void imprimeConsulta(FILE *fConsulta, char *tipo, char *nome, char *nomeUpperCase){
	char nomeInicialUpper[LINE_MAX];
	strcpy(nomeInicialUpper, nome);
	if('a' <= nomeInicialUpper[0] && nomeInicialUpper[0] <= 'z' )
		nomeInicialUpper[0] += 'A'-'a';

	fprintf(fConsulta, "\t/* Testar PRF consulta %s professor */\n", nome);
	fprintf(fConsulta, "\n");
	fprintf(fConsulta, "\telse if ( strcmp( ComandoTeste , CONSULTA_%s_CMD ) == 0 ){\n", nomeUpperCase);
	fprintf(fConsulta, "\t\tNumLidos = LER_LerParametros( \"i%ci\" , &index, %sEsperado, &CondRetEsperada );\n", *tipo=='c'?'s':'i', *tipo=='c'?"valorString":"&valor");
	fprintf(fConsulta, "\t\tif(NumLidos != 3){\n");
	fprintf(fConsulta, "\t\t\treturn TST_CondRetParm;\n");
	fprintf(fConsulta, "\t\t} /* if */\n");
	fprintf(fConsulta, "\n");
	fprintf(fConsulta, "\t\tCondRetObtido = PRF_consulta%s(p[index], %sObtido);\n", nomeInicialUpper, *tipo=='c'?"valorString":"&valor");
	fprintf(fConsulta, "\n");
	fprintf(fConsulta, "\t\tRet = TST_CompararInt(CondRetEsperada, CondRetObtido,\n");
	fprintf(fConsulta, "\t\t\t\t\"Retorno errado ao consultar %s de Professor.\"\n", nomeInicialUpper);
	fprintf(fConsulta, "\t\tif(Ret != TST_CondRetOK) return Ret;\n");
	if(*tipo=='c')
		fprintf(fConsulta, "\t\tRet = TST_CompararString( valorStringEsperado , valorStringObtido,\n");
	else
		fprintf(fConsulta, "\t\tRet = TST_CompararInt( valorEsperado , valorObtido,\n");
	fprintf(fConsulta, "\t\t\t\t\"Retorno por referencia errado ao consultar %s de Professor.\");\n", nomeInicialUpper);
	fprintf(fConsulta, "\t\treturn Ret;\n");
	fprintf(fConsulta, "\t} /* fim ativa: Testar PRF consulta %s professor */\n", nomeInicialUpper);
	fprintf(fConsulta, "\n");
}

void imprimeAltera(FILE *fAltera, char *tipo, char *nome, char *nomeUpperCase){
	char nomeInicialUpper[LINE_MAX];
	strcpy(nomeInicialUpper, nome);
	if('a' <= nomeInicialUpper[0] && nomeInicialUpper[0] <= 'z' )
		nomeInicialUpper[0] += 'A'-'a';
	
	fprintf(fAltera, "\t/* Testar PRF altera %s professor */\n", nome);
	fprintf(fAltera, "\n");
	fprintf(fAltera, "\telse if ( strcmp( ComandoTeste , ALTERA_%s_CMD ) == 0 ){\n", nomeUpperCase);
	fprintf(fAltera, "\t\tNumLidos = LER_LerParametros( \"i%ci\" , &index, %sEsperado, &CondRetEsperada );\n", *tipo=='c'?'s':'i', *tipo=='c'?"valorString":"&valor");
	fprintf(fAltera, "\t\tif(NumLidos != 3){\n");
	fprintf(fAltera, "\t\t\treturn TST_CondRetParm;\n");
	fprintf(fAltera, "\t\t} /* if */\n");
	fprintf(fAltera, "\n");
	fprintf(fAltera, "\t\tCondRetObtido = PRF_altera%s(p[index], param%s);\n", nomeInicialUpper, *tipo=='c'?"String":"Int");
	fprintf(fAltera, "\n");
	fprintf(fAltera, "\t\treturn TST_CompararInt(CondRetEsperada, CondRetObtido,\n");
	fprintf(fAltera, "\t\t\t\t\"Retorno errado ao alterar %s de Professor.\"\n", nomeInicialUpper);
	fprintf(fAltera, "\t} /* fim ativa: Testar PRF altera %s professor */\n", nomeInicialUpper);
	fprintf(fAltera, "\n");
}


void geraCodigo(FILE *fEntrada, FILE *fConsulta, FILE *fAltera){
	char tipo[LINE_MAX];
	char nome[LINE_MAX];
	char nomeUpperCase[LINE_MAX];

	while(fscanf(fEntrada, " %s %[^[;]%*s", tipo, nome)!=EOF){
		toUpperCase(nomeUpperCase, nome);
		printf("%s\t%s\t%s\n", tipo, nome, nomeUpperCase);
		imprimeConsulta(fConsulta, tipo, nome, nomeUpperCase);		
		imprimeAltera(fAltera, tipo, nome, nomeUpperCase);
	}
}

int main(void){
	FILE *fEntrada;
	FILE *fConsulta;
	FILE *fAltera;
	
	fEntrada = fopen("entrada", "r");
	fConsulta = fopen("consulta", "w");
	fAltera = fopen("altera", "w");
	
	if(!fEntrada || !fConsulta || !fAltera){ fprintf(stderr, "erro ao abrir!\n"); exit(EXIT_FAILURE);}
	
	geraCodigo(fEntrada, fConsulta, fAltera);
	
	fclose(fAltera);
	fclose(fConsulta);
	fclose(fEntrada);
	return 0;
}
