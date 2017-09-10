/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              testeProf.C
*  Letras identificadoras:      TPRF
*
*  Nome da base de software:    Teste automatizado para o Modulo Professor
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicola Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   BM/RP   09/09/2017 Desenvolvimento para T1 modificando TESTARV.C
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo professor. É um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo professor:
*
*     "=criar"  <int>index <string>nome <int>rg <string>pais <string>cpf 
*				<string>cpf <int>matricula <string>email <int> telefone 
*				<int>dia <int>mes <int>ano <string>pais <string>uf <string>cidade
*				<string>bairro <string>rua <int>numero <string>complemento <int>CondRetEsperada  
*					- chama a função: 
*					PRF_cria(Prof** professor, char *nome, int rg, char *cpf, 
*					int matricula, char *email, int telefone, 
*					int dia, int mes, int ano, char *pais, char *uf, *cidade, 
*					 char *bairro, char *rua, int numero, char *complemento);
*					- Para o parametro "Prof** professor" é dado o indice do vetor criado neste codigo.
*     "=mostrar" <int>index
*                   - chama a função PRF_mostra(Prof* p)
*     "=liberar"    - chama a função PRF_libera(Prof** p)
*
*     "=consultaNome"        chama a função PRF_consultaNome 	      <int>index <string>nome
*	  "=consultaRg"          chama a função PRF_consultaRg 		      <int>index <int>rg
*	  "=consultaCpf"         chama a função PRF_consultaCpf           <int>index <string>cpf
*	  "=consultaMatricula"   chama a função PRF_consultaMatricula     <int>index <int>matricula
*	  "=consultaEmail"       chama a função PRF_consultaEmail         <int>index <string>email
*	  "=consultaTelefone"    chama a função PRF_consultaTelefone      <int>index <int>telefone
*	  "=consultaDia"         chama a função PRF_consultaDia           <int>index <int>dia
*	  "=consultaMes"         chama a função PRF_consultaMes           <int>index <int>mes
*	  "=consultaAno"         chama a função PRF_consultaAno           <int>index <int>ano
*	  "=consultaPais"        chama a função PRF_consultaPais          <int>index <string>pais
*	  "=consultaUf"          chama a função PRF_consultaUf            <int>index <string>uf
*	  "=consultaCidade"      chama a função PRF_consultaCidade        <int>index <string>cidade
*	  "=consultaBairro"      chama a função PRF_consultaBairro        <int>index <string>bairro
*	  "=consultaRua"         chama a função PRF_consultaRua           <int>index <string>rua
*	  "=consultaNumero"      chama a função PRF_consultaNumero        <int>index <int>numero
*	  "=consultaComplemento" chama a função PRF_consultaComplemento   <int>index <string>complemento
*
*     "=alterarNome"         chama a função PRF_alteraNome 	         <int>index <string>nome
*	  "=alterarRg"           chama a função PRF_alteraRg 		     <int>index <int>rg
*	  "=alterarCpf"          chama a função PRF_alteraCpf            <int>index <string>cpf
*	  "=alterarMatricula"    chama a função PRF_alteraMatricula      <int>index <int>matricula
*	  "=alterarEmail"        chama a função PRF_alteraEmail          <int>index <string>email
*	  "=alterarTelefone"     chama a função PRF_alteraTelefone       <int>index <int>telefone
*	  "=alterarData "        chama a função PRF_alteraDataNascimento <int>index <int>dia <int>mes <int>ano
*	  "=alterarPais"         chama a função PRF_alteraPais           <int>index <string>pais
*	  "=alterarUf"           chama a função PRF_alteraUf             <int>index <string>uf
*	  "=alterarCidade"       chama a função PRF_alteraCidade         <int>index <string>cidade
*	  "=alterarBairro"       chama a função PRF_alteraBairro         <int>index <string>bairro
*	  "=alterarRua"          chama a função PRF_alteraRua            <int>index <string>rua
*	  "=alterarNumero"       chama a função PRF_alteraNumero         <int>index <int>numero
*	  "=alterarComplemento"  chama a função PRF_alteraComplemento    <int>index <string>complemento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "professor.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define		CRIAR_CMD		"=criar"
#define		MOSTRAR_CMD		"=mostrar"
#define		LIBERAR_CMD		"=liberar"

#define		CONSULTA_NOME_CMD		"=consultarNome"
#define		CONSULTA_RG_CMD			"=consultarRg"
#define		CONSULTA_CPF_CMD		"=consultarCPF"
#define		CONSULTA_MATRICULA_CMD		"=consultarMatricula"
#define		CONSULTA_EMAIL_CMD		"=consultarEmail"
#define		CONSULTA_TELEFONE_CMD		"=consultarTelefone"
#define		CONSULTA_DIA_CMD		"=consultarDia"
#define		CONSULTA_MES_CMD		"=consultarMes"
#define		CONSULTA_ANO_CMD		"=consultarAno"
#define		CONSULTA_PAIS_CMD		"=consultarPais"
#define		CONSULTA_UF_CMD			"=consultarUf"
#define		CONSULTA_CIDADE_CMD		"=consultarCidade"
#define		CONSULTA_BAIRRO_CMD		"=consultarBairro"
#define		CONSULTA_RUA_CMD		"=consultarRua"
#define		CONSULTA_NUMERO_CMD		"=consultarNumero"
#define		CONSULTA_COMPLEMENTO_CMD	"=consultarComplemento"

#define		ALTERA_NOME_CMD		"=alterarNome"
#define		ALTERA_RG_CMD		"=alterarRg"
#define		ALTERA_CPF_CMD		"=alterarCPF"
#define		ALTERA_MATRICULA_CMD	"=alterarMatricula"
#define		ALTERA_EMAIL_CMD	"=alterarEmail"
#define		ALTERA_TELEFONE_CMD	"=alterarTelefone"
#define		ALTERA_DATA_CMD		"=alterarData"
#define		ALTERA_PAIS_CMD		"=alterarPais"
#define		ALTERA_UF_CMD		"=alterarUf"
#define		ALTERA_CIDADE_CMD	"=alterarCidade"
#define		ALTERA_BAIRRO_CMD	"=alterarBairro"
#define		ALTERA_RUA_CMD		"=alterarRua"
#define		ALTERA_NUMERO_CMD	"=alterarNumero"
#define		ALTERA_COMPLEMENTO_CMD	"=alterarComplemento"

/*****  Código das funções exportadas pelo módulo  *****/


/*****  Definicoes globais a serem usadas no modulo testeProf.c  *****/
#define MAX_PROFS 10  /* no futuro deverá ser modificado ao introduzir modulo de lista encadeada */

/* Vetor de ponteiros usado para que o modulo de teste possa acessar ponteiros do modulo professor.c */
Prof *p[MAX_PROFS] = {NULL, NULL, NULL, NULL, NULL,
			NULL, NULL, NULL, NULL, NULL};
			
/*****  Fim de Definicoes globais a serem usadas no modulo testeProf.c  *****/

/***********************************************************************
*
*  $FC Função: TPRF Efetuar operações de teste específicas para professor
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     professor sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste){

	PRF_tpCondRet CondRetObtido;
	PRF_tpCondRet CondRetEsperada;

	//definicoes usadas a cada chamada de comando contida no script
	int index;
	char paramNome[80];
	int paramRg;
	char paramCpf[80];
	int paramMatricula;
	char paramEmail[80];
	int paramTelefone;
	int paramDia;
	int paramMes;
	int paramAno ;
	char paramPais[80];
	char paramUf[80];
	char paramCidade[80];
	char paramBairro[80];
	char paramRua[80];
	int paramNumero;
	char paramComplemento[80];

	//usado nas consultas
	int valorObtido;
	int valorEsperado;
	char valorStringObtido[80];
	char valorStringEsperado[80];

	//usado nas alteras
	int paramInt;
	char paramString[80];
	
	int NumLidos = -1 ;

	TST_tpCondRet Ret ;

      /* Testar PRF Criar professor */

         if ( strcmp( ComandoTeste , CRIAR_CMD ) == 0 ){
            NumLidos = LER_LerParametros( "isisisiiiisssssisi" , &index, paramNome, &paramRg, paramCpf, &paramMatricula, paramEmail, &paramTelefone, &paramDia, &paramMes, &paramAno, paramPais, paramUf, paramCidade, paramBairro, paramRua, &paramNumero, paramComplemento, &CondRetEsperada ) ;
            if ( NumLidos != 18 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = PRF_cria( p+index, paramNome, paramRg, paramCpf, paramMatricula, paramEmail, paramTelefone, paramDia, paramMes, paramAno, paramPais, paramUf, paramCidade, paramBairro, paramRua, paramNumero, paramComplemento);
			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
					"Retorno errado ao criar professor." );

         } /* fim ativa: Testar PRF Criar professor */

	 /* Testar mostrar Professor */

         else if ( strcmp( ComandoTeste , MOSTRAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &index, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PRF_mostra(p[index]);

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao mostrar Professor." );

         } /* fim ativa: Testar PRF mostrar professor */

      /* Testar PRF liberar professor */

         else if ( strcmp( ComandoTeste , LIBERAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , 
									&index, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = PRF_libera(p+index) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao liberar Professor." );

         } /* fim ativa: Testar PRF liberar professor */

//------------------------------------------Consultas----------------------------------

	/* Testar PRF consulta nome professor */

	else if ( strcmp( ComandoTeste , CONSULTA_NOME_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaNome(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Nome de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Nome de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Nome professor */

	/* Testar PRF consulta rg professor */

	else if ( strcmp( ComandoTeste , CONSULTA_RG_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &valorEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaRg(p[index], &valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Rg de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Rg de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Rg professor */

	/* Testar PRF consulta cpf professor */

	else if ( strcmp( ComandoTeste , CONSULTA_CPF_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaCpf(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Cpf de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Cpf de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Cpf professor */

	/* Testar PRF consulta matricula professor */

	else if ( strcmp( ComandoTeste , CONSULTA_MATRICULA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &valorEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaMatricula(p[index], &valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Matricula de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Matricula de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Matricula professor */

	/* Testar PRF consulta email professor */

	else if ( strcmp( ComandoTeste , CONSULTA_EMAIL_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaEmail(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Email de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Email de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Email professor */

	/* Testar PRF consulta telefone professor */

	else if ( strcmp( ComandoTeste , CONSULTA_TELEFONE_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &valorEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaTelefone(p[index], &valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Telefone de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Telefone de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Telefone professor */

	/* Testar PRF consulta dia professor */

	else if ( strcmp( ComandoTeste , CONSULTA_DIA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &valorEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaDiaNascimento(p[index], &valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Dia de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Dia de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Dia professor */

	/* Testar PRF consulta mes professor */

	else if ( strcmp( ComandoTeste , CONSULTA_MES_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &valorEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaMesNascimento(p[index], &valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Mes de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Mes de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Mes professor */

	/* Testar PRF consulta ano professor */

	else if ( strcmp( ComandoTeste , CONSULTA_ANO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &valorEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaAnoNascimento(p[index], &valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Ano de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Ano de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Ano professor */

	/* Testar PRF consulta pais professor */

	else if ( strcmp( ComandoTeste , CONSULTA_PAIS_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaPais(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Pais de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Pais de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Pais professor */

	/* Testar PRF consulta uf professor */

	else if ( strcmp( ComandoTeste , CONSULTA_UF_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaUf(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Uf de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Uf de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Uf professor */

	/* Testar PRF consulta cidade professor */

	else if ( strcmp( ComandoTeste , CONSULTA_CIDADE_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaCidade(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Cidade de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Cidade de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Cidade professor */

	/* Testar PRF consulta bairro professor */

	else if ( strcmp( ComandoTeste , CONSULTA_BAIRRO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaBairro(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Bairro de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Bairro de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Bairro professor */

	/* Testar PRF consulta rua professor */

	else if ( strcmp( ComandoTeste , CONSULTA_RUA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaRua(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Rua de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Rua de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Rua professor */

	/* Testar PRF consulta numero professor */

	else if ( strcmp( ComandoTeste , CONSULTA_NUMERO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &valorEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaNumero(p[index], &valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Numero de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Numero de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Numero professor */

	/* Testar PRF consulta complemento professor */

	else if ( strcmp( ComandoTeste , CONSULTA_COMPLEMENTO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_consultaComplemento(p[index], valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Complemento de Professor.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Complemento de Professor.");
		return Ret;
	} /* fim ativa: Testar PRF consulta Complemento professor */




// ----------------------------------------Alteras-------------------------------

	/* Testar PRF altera nome professor */

	else if ( strcmp( ComandoTeste , ALTERA_NOME_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraNome(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Nome de Professor.");
	} /* fim ativa: Testar PRF altera Nome professor */

	/* Testar PRF altera rg professor */

	else if ( strcmp( ComandoTeste , ALTERA_RG_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &paramInt, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraRg(p[index], paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Rg de Professor.");
	} /* fim ativa: Testar PRF altera Rg professor */

	/* Testar PRF altera cpf professor */

	else if ( strcmp( ComandoTeste , ALTERA_CPF_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraCpf(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Cpf de Professor.");
	} /* fim ativa: Testar PRF altera Cpf professor */

	/* Testar PRF altera matricula professor */

	else if ( strcmp( ComandoTeste , ALTERA_MATRICULA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &paramInt, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraMatricula(p[index], paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Matricula de Professor.");
	} /* fim ativa: Testar PRF altera Matricula professor */

	/* Testar PRF altera email professor */

	else if ( strcmp( ComandoTeste , ALTERA_EMAIL_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraEmail(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Email de Professor.");
	} /* fim ativa: Testar PRF altera Email professor */

	/* Testar PRF altera telefone professor */

	else if ( strcmp( ComandoTeste , ALTERA_TELEFONE_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &paramInt, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraTelefone(p[index], paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Telefone de Professor.");
	} /* fim ativa: Testar PRF altera Telefone professor */

	/* Testar PRF altera diaNascimento professor */

	else if ( strcmp( ComandoTeste , ALTERA_DATA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iiiii" , &index, &paramDia, &paramMes, &paramAno, &CondRetEsperada );
		if(NumLidos != 5){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraDataNascimento(p[index], paramDia, paramMes, paramAno);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar DiaNascimento de Professor.");
	} /* fim ativa: Testar PRF altera DiaNascimento professor */

	/* Testar PRF altera pais professor */

	else if ( strcmp( ComandoTeste , ALTERA_PAIS_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraPais(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Pais de Professor.");
	} /* fim ativa: Testar PRF altera Pais professor */

	/* Testar PRF altera uf professor */

	else if ( strcmp( ComandoTeste , ALTERA_UF_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraUf(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Uf de Professor.");
	} /* fim ativa: Testar PRF altera Uf professor */

	/* Testar PRF altera cidade professor */

	else if ( strcmp( ComandoTeste , ALTERA_CIDADE_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraCidade(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Cidade de Professor.");
	} /* fim ativa: Testar PRF altera Cidade professor */

	/* Testar PRF altera bairro professor */

	else if ( strcmp( ComandoTeste , ALTERA_BAIRRO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraBairro(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Bairro de Professor.");
	} /* fim ativa: Testar PRF altera Bairro professor */

	/* Testar PRF altera rua professor */

	else if ( strcmp( ComandoTeste , ALTERA_RUA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraRua(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Rua de Professor.");
	} /* fim ativa: Testar PRF altera Rua professor */

	/* Testar PRF altera numero professor */

	else if ( strcmp( ComandoTeste , ALTERA_NUMERO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iii" , &index, &paramInt, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraNumero(p[index], paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Numero de Professor.");
	} /* fim ativa: Testar PRF altera Numero professor */

	/* Testar PRF altera complemento professor */

	else if ( strcmp( ComandoTeste , ALTERA_COMPLEMENTO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "isi" , &index, paramString, &CondRetEsperada );
		if(NumLidos != 3){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PRF_alteraComplemento(p[index], paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Complemento de Professor.");
	} /* fim ativa: Testar PRF altera Complemento professor */



      return TST_CondRetNaoConhec ;

   } /* Fim função: PRF Efetuar operações de teste específicas para professor */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
