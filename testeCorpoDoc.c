/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              testeCorpoDoc.C
*  Letras identificadoras:      TCDO
*
*  Nome da base de software:    Teste automatizado para o Modulo Corpo Docente
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
*       1.00   BM   03/10/2017 Desenvolvimento para T1
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo corpo docente. É um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo professor:
*
*     "=criar
*     "=cadastrar"  <int>index <string>nome <int>rg <string>pais <string>cpf 
*				<string>cpf <int>matricula <string>email <int> telefone 
*				<int>dia <int>mes <int>ano <string>pais <string>uf <string>cidade
*				<string>bairro <string>rua <int>numero <string>complemento <int>CondRetEsperada  
*					- chama a função: 
*					CDO_cria(Prof** professor, char *nome, int rg, char *cpf, 
*					int matricula, char *email, int telefone, 
*					int dia, int mes, int ano, char *pais, char *uf, *cidade, 
*					 char *bairro, char *rua, int numero, char *complemento);
*					- Para o parametro "Prof** professor" é dado o indice do vetor criado neste codigo.
*     "=mostrar" <int>index
*                   - chama a função CDO_mostra(Prof* p)
*     "=liberar"    - chama a função CDO_libera(Prof** p)
*
*     "=consultaNome"        chama a função CDO_consultaNome 	      <int>index <string>nome
*	  "=consultaRg"          chama a função CDO_consultaRg 		      <int>index <int>rg
*	  "=consultaCpf"         chama a função CDO_consultaCpf           <int>index <string>cpf
*	  "=consultaMatricula"   chama a função CDO_consultaMatricula     <int>index <int>matricula
*	  "=consultaEmail"       chama a função CDO_consultaEmail         <int>index <string>email
*	  "=consultaTelefone"    chama a função CDO_consultaTelefone      <int>index <int>telefone
*	  "=consultaDia"         chama a função CDO_consultaDia           <int>index <int>dia
*	  "=consultaMes"         chama a função CDO_consultaMes           <int>index <int>mes
*	  "=consultaAno"         chama a função CDO_consultaAno           <int>index <int>ano
*	  "=consultaPais"        chama a função CDO_consultaPais          <int>index <string>pais
*	  "=consultaUf"          chama a função CDO_consultaUf            <int>index <string>uf
*	  "=consultaCidade"      chama a função CDO_consultaCidade        <int>index <string>cidade
*	  "=consultaBairro"      chama a função CDO_consultaBairro        <int>index <string>bairro
*	  "=consultaRua"         chama a função CDO_consultaRua           <int>index <string>rua
*	  "=consultaNumero"      chama a função CDO_consultaNumero        <int>index <int>numero
*	  "=consultaComplemento" chama a função CDO_consultaComplemento   <int>index <string>complemento
*
*     "=alterarNome"         chama a função CDO_alteraNome 	         <int>index <string>nome
*	  "=alterarRg"           chama a função CDO_alteraRg 		     <int>index <int>rg
*	  "=alterarCpf"          chama a função CDO_alteraCpf            <int>index <string>cpf
*	  "=alterarMatricula"    chama a função CDO_alteraMatricula      <int>index <int>matricula
*	  "=alterarEmail"        chama a função CDO_alteraEmail          <int>index <string>email
*	  "=alterarTelefone"     chama a função CDO_alteraTelefone       <int>index <int>telefone
*	  "=alterarData "        chama a função CDO_alteraDataNascimento <int>index <int>dia <int>mes <int>ano
*	  "=alterarPais"         chama a função CDO_alteraPais           <int>index <string>pais
*	  "=alterarUf"           chama a função CDO_alteraUf             <int>index <string>uf
*	  "=alterarCidade"       chama a função CDO_alteraCidade         <int>index <string>cidade
*	  "=alterarBairro"       chama a função CDO_alteraBairro         <int>index <string>bairro
*	  "=alterarRua"          chama a função CDO_alteraRua            <int>index <string>rua
*	  "=alterarNumero"       chama a função CDO_alteraNumero         <int>index <int>numero
*	  "=alterarComplemento"  chama a função CDO_alteraComplemento    <int>index <string>complemento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "corpoDocente.h"

/* Tabela dos nomes dos comandos de teste específicos */

#define		CRIAR_CMD		"=criar"
#define		CADASTRAR_CMD		"=cadastrar"
#define		MOSTRAR_ATUAL_CMD	"=mostrarAtual"
#define		MOSTRAR_TODOS_CMD	"=mostrarTodos"
#define		RETIRAR_CMD		"=retirar"
#define		LIMPAR_CMD		"=limpar"
#define		LIBERAR_CMD		"=liberar"

#define		BUSCA_RG_CMD		"=buscarRg"
#define		BUSCA_CPF_CMD		"=buscarCPF"
#define		BUSCA_MATRICULA_CMD	"=buscarMatricula"
#define		BUSCA_EMAIL_CMD		"=buscarEmail"

#define		CONSULTA_NOME_CMD		"=consultarNome"
#define		CONSULTA_RG_CMD			"=consultarRg"
#define		CONSULTA_CPF_CMD		"=consultarCPF"
#define		CONSULTA_MATRICULA_CMD		"=consultarMatricula"
#define		CONSULTA_EMAIL_CMD		"=consultarEmail"
#define		CONSULTA_TELEFONE_CMD		"=consultarTelefone"
#define		CONSULTA_DATA_CMD		"=consultarData"
#define		CONSULTA_ENDERECO_CMD		"=consultarEndereco"

#define		ALTERA_NOME_CMD		"=alterarNome"
#define		ALTERA_RG_CMD		"=alterarRg"
#define		ALTERA_CPF_CMD		"=alterarCPF"
#define		ALTERA_MATRICULA_CMD	"=alterarMatricula"
#define		ALTERA_EMAIL_CMD	"=alterarEmail"
#define		ALTERA_TELEFONE_CMD	"=alterarTelefone"
#define		ALTERA_DATA_CMD		"=alterarData"
#define		ALTERA_ENDERECO_CMD		"=alterarEndereco"

/*****  Código das funções exportadas pelo módulo  *****/

/***********************************************************************
*
*  $FC Função: TCDO Efetuar operações de teste específicas para professor
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

	CDO_tpCondRet CondRetObtido;
	CDO_tpCondRet CondRetEsperada;

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

	int valorObtido;
	int valorEsperado;
	char valorStringObtido[80];
	char valorStringEsperado[80];

	int paramDiaEsperado;
	int paramMesEsperado;
	int paramAnoEsperado;

	char paramPaisEsperado[80];
	char paramUfEsperado[80];
	char paramCidadeEsperado[80];
	char paramBairroEsperado[80];
	char paramRuaEsperado[80];
	int paramNumeroEsperado;
	char paramComplementoEsperado[80];

	int paramInt;
	char paramString[80];
	
	int NumLidos = -1 ;

	TST_tpCondRet Ret ;

	/* Testar CDO Criar Corpo Docente */

         if ( strcmp( ComandoTeste , CRIAR_CMD ) == 0 ){
            NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = CDO_cria();
			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
					"Retorno errado ao criar Corpo Docente." );

         } /* fim ativa: Testar CDO Criar Corpo Docente */

      /* Testar CDO Cadastrar Corpo Docente */

         if ( strcmp( ComandoTeste , CADASTRAR_CMD ) == 0 ){
            NumLidos = LER_LerParametros( "sisisiiiisssssisi" , paramNome, &paramRg, paramCpf, &paramMatricula, paramEmail, &paramTelefone, &paramDia, &paramMes, &paramAno, paramPais, paramUf, paramCidade, paramBairro, paramRua, &paramNumero, paramComplemento, &CondRetEsperada ) ;
            if ( NumLidos != 17 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = CDO_cadastra( paramNome, paramRg, paramCpf, paramMatricula, paramEmail, paramTelefone, paramDia, paramMes, paramAno, paramPais, paramUf, paramCidade, paramBairro, paramRua, paramNumero, paramComplemento);
			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
					"Retorno errado ao cadastrar Corpo Docente." );

         } /* fim ativa: Testar CDO Cadastrar Corpo Docente */

	/* Testar CDO Retirar Corpo Docente */

         if ( strcmp( ComandoTeste , RETIRAR_CMD ) == 0 ){
            NumLidos = LER_LerParametros( "i" ,  &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = CDO_retira();
			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
					"Retorno errado ao retirar Corpo Docente." );

         } /* fim ativa: Testar CDO Retirar Corpo Docente */

	/* Testar mostrar todos Corpo Docente */

         else if ( strcmp( ComandoTeste , MOSTRAR_TODOS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,  &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CDO_mostraTodos();

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao mostrar todos Corpo Docente." );

         } /* fim ativa: Testar CDO mostrar todos Corpo Docente */

	 /* Testar mostrar atual Corpo Docente */

         else if ( strcmp( ComandoTeste , MOSTRAR_ATUAL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CDO_mostraAtual();

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao mostrar um professor de Corpo Docente." );

         } /* fim ativa: Testar CDO mostrar atual Corpo Docente */

	/* Testar CDO limpar Corpo Docente */

         else if ( strcmp( ComandoTeste , LIMPAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CDO_limpa() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao limpar Corpo Docente." );

         } /* fim ativa: Testar CDO limpar Corpo Docente */

      /* Testar CDO liberar Corpo Docente */

         else if ( strcmp( ComandoTeste , LIBERAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" , &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = CDO_libera() ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao liberar Corpo Docente." );

         } /* fim ativa: Testar CDO liberar Corpo Docente */

	/* Testar CDO busca Rg Corpo Docente */	

	else if ( strcmp( ComandoTeste , BUSCA_RG_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" , &paramInt, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_buscaPorRg(paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao buscar por Rg em Corpo Docente.");
	} /* fim ativa: Testar CDO busca Nome Corpo Docente  */

	/* Testar CDO busca Nome Corpo Docente */	

	else if ( strcmp( ComandoTeste , BUSCA_CPF_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" , paramString, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_buscaPorCpf(paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao buscar por CPF em Corpo Docente.");
	} /* fim ativa: Testar CDO busca Nome Corpo Docente  */

	/* Testar CDO busca Nome Corpo Docente */	

	else if ( strcmp( ComandoTeste , BUSCA_MATRICULA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" , &paramInt, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_buscaPorMatricula(paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao buscar por Matricula em Corpo Docente.");
	} /* fim ativa: Testar CDO busca Nome Corpo Docente  */

	/* Testar CDO busca Nome Corpo Docente */	

	else if ( strcmp( ComandoTeste , BUSCA_EMAIL_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" , paramString, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_buscaPorEmail(paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao buscar por Email em Corpo Docente.");
	} /* fim ativa: Testar CDO busca Nome Corpo Docente  */


	/* Testar CDO consulta nome Corpo Docente */

	else if ( strcmp( ComandoTeste , CONSULTA_NOME_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" , valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaNome(valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Nome de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Nome de um professor Corpo Docente.");
		return Ret;
	} /* fim ativa: Testar CDO consulta Nome Corpo Docente */

	/* Testar CDO consulta rg Corpo Docente */

	else if ( strcmp( ComandoTeste , CONSULTA_RG_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" , &valorEsperado, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaRg(&valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Rg de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Rg de um professor em Corpo Docente.");
		return Ret;
	} /* fim ativa: Testar CDO consulta Rg professor */

	/* Testar CDO consulta cpf professor */

	else if ( strcmp( ComandoTeste , CONSULTA_CPF_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" , valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaCpf(valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Cpf de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Cpf de um professor em Corpo Docente.");
		return Ret;
	} /* fim ativa: Testar CDO consulta Cpf professor */

	/* Testar CDO consulta matricula professor */

	else if ( strcmp( ComandoTeste , CONSULTA_MATRICULA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" , &valorEsperado, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaMatricula(&valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Matricula de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Matricula de um professor em Corpo Docente.");
		return Ret;
	} /* fim ativa: Testar CDO consulta Matricula professor */

	/* Testar CDO consulta email professor */

	else if ( strcmp( ComandoTeste , CONSULTA_EMAIL_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" , valorStringEsperado, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaEmail(valorStringObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Email de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararString( valorStringEsperado , valorStringObtido,
				"Retorno por referencia errado ao consultar Email de um professor em Corpo Docente.");
		return Ret;
	} /* fim ativa: Testar CDO consulta Email professor */

	/* Testar CDO consulta telefone professor */

	else if ( strcmp( ComandoTeste , CONSULTA_TELEFONE_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" , &valorEsperado, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaTelefone(&valorObtido);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Telefone de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;
		Ret = TST_CompararInt( valorEsperado , valorObtido,
				"Retorno por referencia errado ao consultar Telefone de um professor em Corpo Docente.");
		return Ret;
	} /* fim ativa: Testar CDO consulta Telefone professor */

	/* Testar CDO consulta data professor */

	else if ( strcmp( ComandoTeste , CONSULTA_DATA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iiii" , &paramDiaEsperado, &paramMesEsperado, &paramAnoEsperado, &CondRetEsperada );
		if(NumLidos != 4){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaDataNascimento(&paramDia,&paramMes,&paramAno);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Data de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararInt( paramDiaEsperado , paramDia,
				"Retorno por referencia errado ao consultar Dia de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararInt( paramMesEsperado , paramMes,
				"Retorno por referencia errado ao consultar Mes de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararInt( paramAnoEsperado , paramAno,
				"Retorno por referencia errado ao consultar Ano de um professor em Corpo Docente.");

		return Ret;
	} /* fim ativa: Testar CDO consulta data professor */

	/* Testar CDO consulta Endereco professor */

	else if ( strcmp( ComandoTeste , CONSULTA_ENDERECO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "sssssisi" , paramPaisEsperado, paramUfEsperado, paramCidadeEsperado, paramBairroEsperado, paramRuaEsperado, &paramNumeroEsperado, paramComplementoEsperado, &CondRetEsperada );
		if(NumLidos != 8){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_consultaEndereco(paramPais, paramUf, paramCidade, paramBairro, paramRua, &paramNumero, paramComplemento);

		Ret = TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao consultar Endereco de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararString( paramPaisEsperado , paramPais,
				"Retorno por referencia errado ao consultar Pais de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararString( paramUfEsperado , paramUf,
				"Retorno por referencia errado ao consultar Uf de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararString( paramCidadeEsperado , paramCidade,
				"Retorno por referencia errado ao consultar Cidade de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararString( paramBairroEsperado , paramBairro,
				"Retorno por referencia errado ao consultar Bairro de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararString( paramRuaEsperado , paramRua,
				"Retorno por referencia errado ao consultar Rua de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararInt( paramNumeroEsperado , paramNumero,
				"Retorno por referencia errado ao consultar Numero de um professor em Corpo Docente.");
		if(Ret != TST_CondRetOK) return Ret;

		Ret = TST_CompararString( paramComplementoEsperado , paramComplemento,
				"Retorno por referencia errado ao consultar Complemento de um professor em Corpo Docente.");
		return Ret;
	} /* fim ativa: Testar CDO consulta Endereco professor */

	/* Testar CDO altera Nome professor */

	else if ( strcmp( ComandoTeste , ALTERA_NOME_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" , paramString, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraNome(paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Nome de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera Nome professor */

	/* Testar CDO altera rg professor */

	else if ( strcmp( ComandoTeste , ALTERA_RG_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" ,  &paramInt, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraRg( paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Rg de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera Rg professor */

	/* Testar CDO altera cpf professor */

	else if ( strcmp( ComandoTeste , ALTERA_CPF_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" ,  paramString, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraCpf(paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Cpf de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera Cpf professor */

	/* Testar CDO altera matricula professor */

	else if ( strcmp( ComandoTeste , ALTERA_MATRICULA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" , &paramInt, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraMatricula(paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Matricula de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera Matricula professor */

	/* Testar CDO altera email professor */

	else if ( strcmp( ComandoTeste , ALTERA_EMAIL_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "si" , paramString, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraEmail( paramString);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Email de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera Email professor */

	/* Testar CDO altera telefone professor */

	else if ( strcmp( ComandoTeste , ALTERA_TELEFONE_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "ii" ,  &paramInt, &CondRetEsperada );
		if(NumLidos != 2){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraTelefone( paramInt);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Telefone de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera Telefone professor */

	/* Testar CDO altera diaNascimento professor */

	else if ( strcmp( ComandoTeste , ALTERA_DATA_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "iiii" , &paramDia, &paramMes, &paramAno, &CondRetEsperada );
		if(NumLidos != 4){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraDataNascimento(paramDia, paramMes, paramAno);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Data de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera DiaNascimento professor */

	/* Testar CDO altera Endereco professor */

	else if ( strcmp( ComandoTeste , ALTERA_ENDERECO_CMD ) == 0 ){
		NumLidos = LER_LerParametros( "sssssisi" , paramPais, paramUf, paramCidade, paramBairro, paramRua, &paramNumero, paramComplemento, &CondRetEsperada );
		if(NumLidos != 8){
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = CDO_alteraEndereco(paramPais, paramUf, paramCidade, paramBairro, paramRua, paramNumero, paramComplemento);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
				"Retorno errado ao alterar Endereco de um professor em Corpo Docente.");
	} /* fim ativa: Testar CDO altera Endereco professor */

      return TST_CondRetNaoConhec ;

   } /* Fim função: CDO Efetuar operações de teste específicas para professor */

/********** Fim do módulo de implementação: Módulo de teste específico **********/

