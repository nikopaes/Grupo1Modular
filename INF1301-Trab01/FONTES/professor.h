/***************************************************************************
*
*  $MCD Módulo de definição: Módulo árvore
*
*  Arquivo gerado:              professor.h
*  Letras identificadoras:      PRF
*
*  Nome da base de software:    Modulo de professor
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
*     Versão	Autor				Data		Observações
*       1.00	BM,FA,NP,MR,RP	11/09/2017		Desenvolvimento para T1.
*
*  $ED Descrição do módulo
*	  Este módulo implementa um conjunto simples de funções e estruturas para criar e manipular um professor.
*     A estrutura professor guarda uma referência para estruturas que armazenam data e endereço.
*     O módulo admite múltiplas instâncias de professor.
*     Ao iniciar a execução do programa não existe professor algum.
*     Ao chamar a função criar, as referências para data e estrutura são alocadas.
*	  Deve-se usar a função libera para que a memória alocada seja liberada.
*	  Passar argumentos inválidos como 0 ou "" podem causar erro de formato (PRF_CondRetFormatoInvalido).
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

#define  PRF_MIN_ANO  1850
#define  PRF_TAM_STRING  80
#define  PRF_TAM_UF 3
#define  PRF_TAM_CPF 11


/* Tipo professor */
typedef struct prof Prof;


/***********************************************************************
*
*  $TC Tipo de dados: PRF Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno
*
***********************************************************************/

typedef enum{
	PRF_CondRetOk,
			/* Condicao de Retorno OK, usada quando a função executa corretamente */
	PRF_CondRetNaoHaMemoria,
			/* Condicao de Retorno Nao Ha Memoria, usada quando a memoria do sistema nao apresenta mais espaco */ 
	PRF_CondRetNaoExisteProf,
			/* Condicao de Retorno Nao Existe Prof, usada quando aquela instância de professor ou algum dado que ele armazena e que está sendo acessado, não foi alocado. */ 
	PRF_CondRetProfessorJaCriado,
			/* Condicao de Retorno Professor Ja Criado, usada ao tentar instânciar um professor duas vezes no mesmo bloco de memória (no mesmo ponteiro). */ 
	PRF_CondRetFormatoInvalido,
			/* Condicao de Retorno Formato Inválido, usada quando o formato de algum parâmetro está errado */
} PRF_tpCondRet;


/***********************************************************************
*
*  $FC Função: PRF  Criar professor
*
*  $ED Descrição da função
*     Cria uma instância de professor, e o aloca no ponteiro passado por referência.
*
*  $EP Parâmetros
*	  $P professor		- endereço de um ponteiro, nele será alocado o professor criado.
*	  $P nome			- nome do professor criado.
*	  $P rg			- rg do professor criado.
*	  $P cpf			- cpf do professor criado.
*	  $P matricula		- matricula do professor criado.
*	  $P email			- email do professor criado.
*	  $P telefone		- telefone do professor criado.
*	  $P dia			- dia de nascimento do professor criado.
*	  $P mes			- mes de nascimento do professor criado.
*	  $P ano			- ano de nascimento do professor criado.
*	  $P pais			- pais do professor criado.
*	  $P uf			- uf do professor criado.
*	  $P cidade		- cidade do professor criado.
*	  $P bairro		- bairro do professor criado.
*	  $P rua			- rua do professor criado.
*	  $P numero		- numero da casa ou do predio do professor criado.
*	  $P complemento	- complemento para o endereço do professor criado.
*
*  $FV Valor retornado
*	  PRF_CondRetOk
*	  PRF_CondRetNaoHaMemoria
*	  PRF_CondRetProfessorJaCriado - usado ao tentar instânciar um professor duas vezes no mesmo bloco de memória (no mesmo ponteiro).
*	  PRF_CondRetFormatoInvalido - usado quando o formato de algum parâmetro está errado.
*
***********************************************************************/
PRF_tpCondRet PRF_cria(Prof** professor, char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);


/***********************************************************************
*
*  $FC Função: PRF  Liberar professor
*
*  $ED Descrição da função
*     Destrói o professor fornecido.
*     OBS. não existe previsão para possíveis falhas de execução.

*  $EP Parâmetros
*	  $P professor		- endereço de um ponteiro, que será liberado.

*  $FV Valor retornado
*     PRF_CondRetOK    - destruiu sem problemas
*
***********************************************************************/
PRF_tpCondRet PRF_libera(Prof** professor);

/***********************************************************************
*
*  $FC Função: PRF  Mostrar professor
*
*  $ED Descrição da função
*     Exibe na tela todos os dados de professor.

*  $EP Parâmetros
*	  $P professor		- ponteiro armazenando um professor que será exibido.

*  $FV Valor retornado
*     PRF_CondRetOK    - exibiu na tela com sucesso.
*
***********************************************************************/
PRF_tpCondRet PRF_mostra(Prof* professor);

/***********************************************************************
*
*  $FC Função: PRF Consulta nome professor
*
*  $ED Descrição da função
*     Retorna por referência o nome de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P nome - Ponteiro para uma string para o qual a função retornará o nome requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
/* Inicio do Bloco de Funcoes de Consulta */

    PRF_tpCondRet PRF_consultaNome(Prof* professor, char* nome);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta rg
*
*  $ED Descrição da função
*     Retorna por referencia o RG de um professor
*
*  $EP Parâmetros
*     $P professor -  Ponteiro para um professor
*     $P rg - Ponteiro para um inteiro para o qual a função retornará o RG requisitado por referencia
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaRg(Prof *professor, int *rg);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta cpf
*
*  $ED Descrição da função
*     Retorna por referencia o CPF de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P cpf - Ponteiro para uma string para o qual a função retornará o cpf requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaCpf(Prof *professor, char *cpf);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta matricula
*
*  $ED Descrição da função
*     Retorna por referencia a matricula de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P matricula - Ponteiro para um inteiro para o qual a função retornará o matricula requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaMatricula(Prof *professor, int *matricula);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta email
*
*  $ED Descrição da função
*     Retorna por referencia o email de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P email - Ponteiro para uma string para o qual a função retornará o email requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaEmail(Prof* professor, char* email);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta telefone
*
*  $ED Descrição da função
*     Retorna por referencia o telefone de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P telefone - Ponteiro para um inteiro para o qual a função retornará o telefone requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaTelefone(Prof *professor, int *telefone);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta data de nascimento
*
*  $ED Descrição da função
*     Retorna por referencia a data de nascimento de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P dia - Ponteiro para um inteiro para o qual a função retornará o dia de nascimento requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaDiaNascimento(Prof *professor, int *dia);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta mês de nascimento
*
*  $ED Descrição da função
*     Retorna por referencia o mês de nascimento de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P mes - Ponteiro para um inteiro para o qual a função retornará o mes de nascimento requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaMesNascimento(Prof *professor, int *mes);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta ano de nascimento
*
*  $ED Descrição da função
*     Retorna por referencia o ano de nascimento de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P ano - Ponteiro para um inteiro para o qual a função retornará o ano de nascimento requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaAnoNascimento(Prof *professor, int *ano);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta país de moradia
*
*  $ED Descrição da função
*     Retorna por referencia o país de moradia de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P pais - Ponteiro para uma string para o qual a função retornará o pais de moradia requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaPais(Prof *professor, char *pais);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta uf
*
*  $ED Descrição da função
*     Retorna por referencia o uf de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P uf - Ponteiro para uma string para o qual a função retornará o uf requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaUf(Prof *professor, char *uf);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta cidade
*
*  $ED Descrição da função
*     Retorna por referencia o cidade de moradia de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P cidade - Ponteiro para uma string para o qual a função retornará a cidade requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaCidade(Prof *professor, char *cidade);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta bairro
*
*  $ED Descrição da função
*     Retorna por referencia o bairro de moradia de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P cidade - Ponteiro para uma string para o qual a função retornará o bairro requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaBairro(Prof *professor, char *bairro);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta bairro
*
*  $ED Descrição da função
*     Retorna por referencia o bairro de moradia de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P bairro - Ponteiro para uma string para o qual a função retornará a rua requisitada por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaRua(Prof *professor, char *rua);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta numero
*
*  $ED Descrição da função
*     Retorna por referencia o numero de moradia de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P numero - Ponteiro para um inteiro para o qual a função ao retornará o numero da moradia requisitado por referência
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaNumero(Prof *professor, int *numero);
 
/***********************************************************************
*
*  $FC Função: PRF Consulta complemento
*
*  $ED Descrição da função
*     Retorna por referencia o complemento de moradia de um professor
*
*  $EP Parâmetros
*     $P professor - Ponteiro para um professor
*     $P complemento - Ponteiro para uma string para o qual a funcao retornará o complemento da moradia requisitado por referencia
*
*  $FV Valor retornado
*     PRF_tpCondRetOK
*     PRF_CondRetNaoExisteProf
*
***********************************************************************/
 
    PRF_tpCondRet PRF_consultaComplemento(Prof *professor, char *complemento);
 
/* Fim do Bloco de Funcoes de Consulta */

/* Início do Bloco de Funcoes de Altera */

/***********************************************************************
*
*  $FC Função: PRF altera Nome
*
*  $ED Descrição da função
*     Altera o Nome do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu Nome a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P nome -  é o parametro que receberá o novo Nome a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraNome(Prof* professor, char* nome);

/***********************************************************************
*
*  $FC Função: PRF altera RG
*
*  $ED Descrição da função
*     Altera o RG do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu RG a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P rg -  é o parametro que receberá o novo RG a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraRg(Prof* professor, int rg);

/***********************************************************************
*
*  $FC Função: PRF altera CPF
*
*  $ED Descrição da função
*     Altera o CPF do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu CPF a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P cpf -  é o parametro que receberá o novo CPF a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraCpf(Prof* professor, char* cpf);

/***********************************************************************
*
*  $FC Função: PRF altera Matricula
*
*  $ED Descrição da função
*     Altera o Matricula do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua matricula a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P matricula - é o parametro que receberá o nova matricula a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraMatricula(Prof* professor, int matricula);

/***********************************************************************
*
*  $FC Função: PRF altera Email
*
*  $ED Descrição da função
*     Altera o email do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu email a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P email -  é o parametro que receberá o novo email a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraEmail(Prof* professor, char* email);

/***********************************************************************
*
*  $FC Função: PRF altera Telefone
*
*  $ED Descrição da função
*     Altera o telefone do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu telefone a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P tel -  é o parametro que receberá o novo telefone a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraTelefone(Prof* professor, int tel);

/***********************************************************************
*
*  $FC Função: PRF altera Data de Nascimento
*
*  $ED Descrição da função
*     Altera o data de nascimento do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua Data de Nascimento alterado.
* 					Este parâmetro é passado por referência.
*     $P dia -  é o parametro que receberá o novo dia a ser alterado no professor atual.
*     $P mes -  é o parametro que receberá o novo mes a ser alterado no professor atual.
*     $P ano -  é o parametro que receberá o novo ano a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraDataNascimento(Prof* professor, int dia, int mes, int ano);

/***********************************************************************
*
*  $FC Função: PRF altera Pais
*
*  $ED Descrição da função
*     Altera o Pais do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu País alterado.
* 					Este parâmetro é passado por referência.
*     $P pais -  é o parametro que receberá o novo País a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraPais(Prof* professor, char* pais);

/***********************************************************************
*
*  $FC Função: PRF altera UF
*
*  $ED Descrição da função
*     Altera o UF do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua UF alterado.
* 					Este parâmetro é passado por referência.
*     $P uf -  é o parametro que receberá o nova UF a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraUf(Prof* professor, char* uf);

/***********************************************************************
*
*  $FC Função: PRF altera Cidade
*
*  $ED Descrição da função
*     Altera o Cidade do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua cidade alterado.
* 					Este parâmetro é passado por referência.
*     $P cidade -  é o parametro que receberá o nova cidade a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraCidade(Prof* professor, char* cidade);

/***********************************************************************
*
*  $FC Função: PRF altera Bairro
*
*  $ED Descrição da função
*     Altera o Bairro do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu bairro alterado.
* 					Este parâmetro é passado por referência.
*     $P bairro -  é o parametro que receberá o novo bairro a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraBairro(Prof* professor, char* bairro);

/***********************************************************************
*
*  $FC Função: PRF altera Rua
*
*  $ED Descrição da função
*     Altera o Rua do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua rua alterado.
* 					Este parâmetro é passado por referência.
*     $P rua -  é o parametro que receberá o nova rua a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraRua(Prof* professor, char* rua);

/***********************************************************************
*
*  $FC Função: PRF altera Numero
*
*  $ED Descrição da função
*     Altera o Numero do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu numero alterado.
* 					Este parâmetro é passado por referência.
*     $P numero -  é o parametro que receberá o novo numero a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraNumero(Prof* professor, int numero);

/***********************************************************************
*
*  $FC Função: PRF altera Complemento
*
*  $ED Descrição da função
*     Altera o Complemento do professor
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu complemento alterado.
* 					 Este parâmetro é passado por referência.
*     $P complemento -  é o parametro que receberá o novo complemento a ser alterado no professor atual.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Instância de professor ou o argumento passado não foi alocado.
*     PRF_CondRetFormatoInvalido - Formato inválido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraComplemento(Prof* professor, char* complemento);

/* Fim do Bloco de Funcoes de Altera */

/********** Fim do módulo de definição: Módulo Professor **********/
