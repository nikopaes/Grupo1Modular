/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTARV.C
*  Letras identificadoras:      TARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este mÇodulo contém as funções específicas para o teste do
*     módulo árvore. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
*
*     =criar        - chama a função ARV_CriarArvore( )
*     =insdir <Char>
*                   - chama a função ARV_InserirDireita( <Char> )
*                     Obs. notação: <Char>  é o valor do parâmetro
*                     que se encontra no comando de teste.
*
*     "=insesq" <Char>
*                   - chama a função ARV_InserirEsquerda( <Char> )
*     "=irpai"      - chama a função ARV_IrPai( )
*     "=iresq"      - chama a função ARV_IrEsquerda( )
*     "=irdir"      - chama a função ARV_IrDireita( )
*     "=obter" <Char>
*                   - chama a função ARV_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a função ARV_DestruirArvore( )
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
#define		CONSULTA_COMPLEMENTO_CMD	"=consultarcomplemento"

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
#define		ALTERA_COMPLEMENTO_CMD	"=alterarcomplemento"

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPRF Efetuar operações de teste específicas para professor
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     árvore sendo testado.
*
*  $EP Parâmetros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/
#define MAX_PROFS 10

Prof *p[MAX_PROFS] = {NULL, NULL, NULL, NULL, NULL,
			NULL, NULL, NULL, NULL, NULL};

  

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste){

	PRF_tpCondRet CondRetObtido;
	PRF_tpCondRet CondRetEsperada;

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
