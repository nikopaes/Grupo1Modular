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

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "professor.h"

/* Tabela dos nomes dos comandos de teste específicos */

/*
PRF_tpCondRet criaProf(int cpf, char *pais, int dia, int mes, int ano);
PRF_tpCondRet consultaCpfProf();
PRF_tpCondRet alteraCpfProf(int cpf);
PRF_tpCondRet mostraProf();
PRF_tpCondRet liberaProf();
*/

#define     CRIAR_CMD       "=criar"
#define     ALTERA_CPF_CMD  "=alterarCPF"
#define     ALTERA_PAIS_CMD  "=alterarPais"
#define     ALTERA_MATRICULA_CMD  "=alterarMatricula"
#define     CONSULTA_CPF_CMD  "=consultarCPF"
#define     CONSULTA_PAIS_CMD  "=consultarPais"
#define     CONSULTA_MATRICULA_CMD  "=consultarMatricula"
#define     MOSTRAR_CMD     "=mostrar"
#define     LIBERAR_CMD     "=liberar"

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

Prof *p = NULL;

   TST_tpCondRet TST_EfetuarComando(char * ComandoTeste){

      PRF_tpCondRet CondRetObtido   ;
	  PRF_tpCondRet CondRetEsperada ;

	  int paramMatricula;
	  char paramCPF[11];
	  char paramPais[80];
	  int paramDia;
	  int paramMes;
	  int paramAno;

	  int valorObtido;
	  int valorEsperado;
	  char valorStringObtido[80];
	  char valorStringEsperado[80];


      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar PRF Criar professor */

         if ( strcmp( ComandoTeste , CRIAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isiiii" ,
								&paramCPF, paramPais, &paramDia, &paramMes, &paramAno,
                               &CondRetEsperada ) ;
            if ( NumLidos != 6 )
            {
               return TST_CondRetParm ;
            } /* if */

			CondRetObtido = criaProf( &p, paramMatricula, paramCPF, paramPais, paramDia, paramMes, paramAno ) ;
			
			
            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar professor." );

         } /* fim ativa: Testar PRF Criar professor */

		  /* Testar mostrar Professor */

         else if ( strcmp( ComandoTeste , MOSTRAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
								&CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = mostraProf(p) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao mostrar Professor." );

         } /* fim ativa: Testar PRF mostrar professor */

      /* Testar PRF liberar professor */

         else if ( strcmp( ComandoTeste , LIBERAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = liberaProf(&p) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao liberar Professor." );

         } /* fim ativa: Testar PRF liberar professor */

//------------------------------------------Consultas----------------------------------

		  /* Testar PRF consulta CPF professor */

		 else if ( strcmp( ComandoTeste , CONSULTA_CPF_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" ,
								&valorStringEsperado,
								&CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = consultaCpfProf(p, valorStringObtido) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao consultar CPF de Professor." );
			if(Ret != TST_CondRetOK) return Ret;
			Ret = TST_CompararString( valorStringEsperado , valorStringObtido, 
                                    "Retorno por referencia errado ao consultar CPF de Professor." );
			return Ret;

         } /* fim ativa: Testar PRF consulta CPF professor */

		 /* Testar PRF consulta Pais professor */

		 else if ( strcmp( ComandoTeste , CONSULTA_PAIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" ,
								&valorStringEsperado,
								&CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = consultaPaisProf(p, valorStringObtido) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao consultar Pais de Professor." );
			if(Ret != TST_CondRetOK) return Ret;
			Ret = TST_CompararString( valorStringEsperado , valorStringObtido, 
                                    "Retorno por referencia errado ao consultar Pais de Professor." );
			return Ret;

         } /* fim ativa: Testar PRF consulta Pais professor */

		 /* Testar PRF consulta Matricula professor */

		 else if ( strcmp( ComandoTeste , CONSULTA_MATRICULA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
								&valorEsperado,
								&CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = consultaMatriculaProf(p, &valorObtido) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao consultar Matricula de Professor." );
			if(Ret != TST_CondRetOK) return Ret;
			Ret = TST_CompararInt( valorEsperado , valorObtido, 
                                    "Retorno por referencia errado ao consultar Matricula de Professor." );
			return Ret;

         } /* fim ativa: Testar PRF consulta Matricula professor */


		 //TODO inicio

		  /*
		 
//		 As partes que devem ser alteradas estão como TODO

		 */



		 /* Testar PRF consulta TODO professor */

// coloque o nome do define no topo do documento correspondente a sua variavel
// se não houver tal variavel crie outro define
//		 else if ( strcmp( ComandoTeste , CONSULTA_TODO_CMD ) == 0 )
//         {
//		coloque o tipo da leitura, s=string, c=char, i=inteiro
//     Não retire o ultimo i que já está ai.
// Coloque o nome da variavel de acordo com uma variavel no inicio da função. Se não houver variavel, crie.
// La tem cima tem valorEsperado do tipo int, e valorStringEsperado do tipo char* (string), use o correspondente
//            NumLidos = LER_LerParametros( "TODOi" ,
//								&valorTODOEsperado,
//								&CondRetEsperada ) ;
//            if ( NumLidos != 2 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//
//	Chame a função de professor que faz a consulta desta variavel
// use a variavel obtido do tipo correspondente, ou crie uma se necessario
//            CondRetObtido = consultaTODOProf(p, &valorTODOObtido) ;
//
// Nome da variavel que esta tratando
//            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                    "Retorno errado ao consultar TODO de Professor." );
//			if(Ret != TST_CondRetOK) return Ret;
// novamente o mesmo nome da variavel que esta tratando aqui
//			Ret = TST_CompararInt( valorEsperado , valorObtido, 
//                                    "Retorno por referencia errado ao consultar TODO de Professor." );
//			return Ret;
//
// Coloque o nome desta variavel
//         } /* fim ativa: Testar PRF consulta TODO professor */
//delete todos esses comentarios com // e deixe os com /* . Compare com as outras funções.
//			TODO fim


// ----------------------------------------Alteras-------------------------------

      /* Testar PRF alterar cpf */

         else if ( strcmp( ComandoTeste , ALTERA_CPF_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" ,
                               &paramCPF , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = alteraCpfProf(p,  paramCPF ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar CPF." );

         } /* fim ativa: Testar PRF alterar cpf */

		 /* Testar PRF alterar Pais */

         else if ( strcmp( ComandoTeste , ALTERA_PAIS_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "si" ,
                               &paramPais , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = alteraPaisProf(p,  paramPais ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar CPF." );

         } /* fim ativa: Testar PRF alterar Pais */

		 /* Testar PRF alterar matricula */

         else if ( strcmp( ComandoTeste , ALTERA_MATRICULA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &paramMatricula , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = alteraMatriculaProf(p,  paramMatricula ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao alterar CPF." );

         } /* fim ativa: Testar ARV alterar cpf */	


		 /* TODO inicio

		 /*
		 
//		 As partes que devem ser alteradas estão como TODO

		 */

		 /* Testar PRF alterar TODO */
		 // coloque o nome do define no topo do documento correspondente a sua variavel
		 // se não houver tal variavel crie outro define
//         else if ( strcmp( ComandoTeste , ALTERA_TODO_CMD ) == 0 )
//        {
//		coloque o tipo da leitura, s=string, c=char, i=inteiro
//     Não retire o ultimo i que já está ai.
// Coloque o nome da variavel de acordo com uma variavel no inicio da função. Se não houver variavel, crie.
//            NumLidos = LER_LerParametros( "TODOi" ,
//                               &paramTODO , &CondRetEsperada ) ;
//            if ( NumLidos != 2 )
//            {
//               return TST_CondRetParm ;
//            } /* if */
//
//	Chame a função de professor que altera a variavel deste bloco
// Essa é a mesma variavel de antes
//            CondRetObtido = alteraTODOProf(p,  paramTODO ) ;
//
// coloque o nome da variavel que voce esta tratando
//            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
//                                   "Retorno errado ao alterar TODO." );
//
// de novo o nome da variavel
//         } /* fim ativa: Testar PRF alterar TODO */
//
//delete todos esses comentarios com // deixe os com /* e compare com as outras funções prontas.
//			TODO fim
//		 */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TPRF Efetuar operações de teste específicas para professor */

/********** Fim do módulo de implementação: Módulo de teste específico **********/
