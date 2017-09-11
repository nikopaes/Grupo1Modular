/*! \file professor.h
    \brief Arquivo header para o modulo Professor
    
    Detalhes adicionais
*/

/** @defgroup moduloProfessor Modulo Professor.h
 *  Modulo destinado para controlar tudo relacionado ao professor 
 *  @{
 */


/*! \brief typedef da Struct que guarda as informacoes referentes a um Professor
*/
typedef struct prof Prof;

//! Condicoes de retorno para as funcoes do Modulo Professor.
/*! Toda a funcao do modulo Professor precisa retornar algum tipo de \a PFR_tpCondRet pertenente a esse \a enum para tonar possiveis testes automatizados*/
typedef enum{
	PRF_CondRetOk, /**< Condicao de Retorno OK, usada quando a funcao funciona como esperado*/ 
	PRF_CondRetNaoHaMemoria, /**< Condicao de Retorno Nao Ha Memoria, usada quando a memoria do sistema nao apresenta mais espaco*/ 
	PRF_CondRetNaoExisteProf, /**< Condicao de Retorno Nao Existe Prof, usada quando nao existe aquela instancia de professor que estao requisitando o acesso */ 
	PRF_CondRetProfessorJaCriado, /**< Condicao de Retorno Professor Ja Criado, usada quando tentam criar um professor qe ja esta instaciado no sistema */ 
	PRF_CondRetFormatoInvalido, /**< Condicao de Retorno Formato Invalido, usada quando o formato de algum parametro esta errado*/
} PRF_tpCondRet;


/*! \fn PRF_tpCondRet PRF_cria(Prof** professor, int matricula, char *cpf, char *pais, int dia, int mes, int ano);
    \brief Cria uma instancia de Professor usando os parametros necessarios e armazena no espaco de memoria designado pelo ponteiro
    \param professor Ponteiro apontando para uma struct professor
    \param matricula Um numero de n caracteres que representa a matricula desse professor, deve ser unica para cada professor
    \param cpf Cadastro de Pessoa Fisica referente a esse professor, deve ser unico pra cada professor
    \param pais Pais de origem do professor 
    \param dia Dia de nascimento do professor
    \param mes Mes de nascimento do professor
    \param ano Ano de nascimento do professor
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_cria(Prof** professor, char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);

/*! \fn PRF_tpCondRet PRF_libera(Prof** professor);
    \brief Libera o espaco de memoria que esta guardando as informacoes do professor apontado
    \param professor Ponteiro apontando para uma struct professor
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_libera(Prof** professor);

/* 
Incluir esta função no modulo corpoDocente

Note que esta será uma família de fuções. Podemos querer disponibilizar a busca por diversos dados como: nome, matricula, etc.

tpCondRet ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada);
*/

/*! \fn PRF_tpCondRet PRF_mostra(Prof* professor);
    \brief Imprime no Prompt de Comando todas as informacoes referentes ao professor apontado
    \param professor Ponteiro apontando para uma struct professor
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_mostra(Prof* professor);


//------------------------------------------------------------------- FUNÇÕES CONSULTA --------------------------------------------------------------------------------------------

/** \name Funcoes de Consulta
 *  Funcoes de Consulta a um professor apontado
*/
/**@{*/ 

/*! \fn PRF_tpCondRet PRF_consultaNome(Prof* professor, char* nome);
    \brief Retorna por referencia o nome de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param nome O ponteiro para uma string para aonde a funcao retornara o nome requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaNome(Prof* professor, char* nome);

/*! \fn PRF_tpCondRet PRF_consultaRg(Prof *professor, int *rg);
    \brief Retorna por referencia o RG de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param RG O ponteiro para um inteiro para aonde a funcao retornara o RG requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaRg(Prof *professor, int *rg);

/*! \fn PRF_tpCondRet PRF_consultaCpf(Prof *professor, char *cpf);
    \brief Retorna por referencia o CPF de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param cpf O ponteiro para uma string para aonde a funcao retornara o cpf requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaCpf(Prof *professor, char *cpf);

/*! \fn PRF_tpCondRet PRF_consultaMatricula(Prof *professor, int *matricula);
    \brief Retorna por referencia a Matricula de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param matricula O ponteiro para um inteiro para aonde a funcao retornara o matricula requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaMatricula(Prof *professor, int *matricula);

/*! \fn PRF_tpCondRet PRF_consultaEmail(Prof* professor, char* email);
    \brief Retorna por referencia o Email de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param email O ponteiro para uma string para aonde a funcao retornara o email requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaEmail(Prof* professor, char* email);

/*! \fn PRF_tpCondRet PRF_consultaTelefone(Prof *professor, int *telefone);
    \brief Retorna por referencia o Telefone de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param telefone O ponteiro para um inteiro para aonde a funcao retornara o telefone requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaTelefone(Prof *professor, int *telefone);

/*! \fn PRF_tpCondRet PRF_consultaDiaNascimento(Prof *professor, int *dia);
    \brief Retorna por referencia o Dia do Nascimento de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param dia O ponteiro para um inteiro para aonde a funcao retornara o dia de nascimento requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaDiaNascimento(Prof *professor, int *dia);

/*! \fn PRF_tpCondRet PRF_consultaMesNascimento(Prof *professor, int *mes);
    \brief Retorna por referencia o Mes de Nascimento de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param mes O ponteiro para um inteiro para aonde a funcao retornara o mes de nascimento requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaMesNascimento(Prof *professor, int *mes);

/*! \fn PRF_tpCondRet PRF_consultaAnoNascimento(Prof *professor, int *ano);
    \brief Retorna por referencia o Ano de Nascimento de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param ano O ponteiro para um inteiro para aonde a funcao retornara o ano de nascimento requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaAnoNascimento(Prof *professor, int *ano);

/*! \fn PRF_tpCondRet PRF_consultaPais(Prof *professor, char *pais);
    \brief Retorna por referencia o Pais de Origem de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param pais O ponteiro para uma string para aonde a funcao retornara o pais requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaPais(Prof *professor, char *pais);

/*! \fn PRF_tpCondRet PRF_consultaUf(Prof *professor, char *uf);
    \brief Retorna por referencia o UF de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param uf O ponteiro para uma string para aonde a funcao retornara o uf requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaUf(Prof *professor, char *uf);

/*! \fn PRF_tpCondRet PRF_consultaCidade(Prof *professor, char *cidade);
    \brief Retorna por referencia a Cidade aonde mora um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param cidade O ponteiro para uma string para aonde a funcao retornara o cidade requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaCidade(Prof *professor, char *cidade);

/*! \fn PRF_tpCondRet PRF_consultaBairro(Prof *professor, char *bairro);
    \brief Retorna por referencia o Bairro da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param bairro O ponteiro para uma string para aonde a funcao retornara o bairro requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaBairro(Prof *professor, char *bairro);

/*! \fn PRF_tpCondRet PRF_consultaRua(Prof *professor, char *rua);
    \brief Retorna por referencia a Rua da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param rua O ponteiro para uma string para aonde a funcao retornara a rua requisitada por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaRua(Prof *professor, char *rua);

/*! \fn PRF_tpCondRet PRF_consultaNumero(Prof *professor, int *numero);
    \brief Retorna por referencia o Numero da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param numero O ponteiro para um inteiro para aonde a funcao retornara o numero da moradia requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaNumero(Prof *professor, int *numero);

/*! \fn PRF_tpCondRet PRF_consultaComplemento(Prof *professor, char *complemento);
    \brief Retorna por referencia o Complemento da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja obter a informacao
    \param complemento O ponteiro para uma string para aonde a funcao retornara o complemento da moradia requisitado por referencia
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_consultaComplemento(Prof *professor, char *complemento);

//---------------- FIM DAS FUNÇÕES CONSULTA --------------------------------------------------------------------------------------------

/***********************************************************************
*
*  $FC Função: PRF altera Nome
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu Nome a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P nome -  é o parametro que recebera o novo Nome a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraNome(Prof* professor, char* nome);

/***********************************************************************
*
*  $FC Função: PRF altera RG
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu RG a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P rg -  é o parametro que recebera o novo RG a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraRg(Prof* professor, int rg);

/***********************************************************************
*
*  $FC Função: PRF altera CPF
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu CPF a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P cpf -  é o parametro que recebera o novo CPF a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraCpf(Prof* professor, char* cpf);

/***********************************************************************
*
*  $FC Função: PRF altera Matricula
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua matricula a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P matricula - é o parametro que recebera o nova matricula a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraMatricula(Prof* professor, int matricula);

/***********************************************************************
*
*  $FC Função: PRF altera Email
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu email a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P email -  é o parametro que recebera o novo email a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraEmail(Prof* professor, char* email);

/***********************************************************************
*
*  $FC Função: PRF altera Telefone
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu telefone a ser alterado.
* 					Este parâmetro é passado por referência.
*     $P tel -  é o parametro que recebera o novo telefone a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraTelefone(Prof* professor, int tel);

/***********************************************************************
*
*  $FC Função: PRF altera Data de Nascimento
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua Data de Nascimento alterado.
* 					Este parâmetro é passado por referência.
*     $P dia -  é o parametro que recebera o novo dia a ser alterado no professor corrente.
*     $P mes -  é o parametro que recebera o novo mes a ser alterado no professor corrente.
*     $P ano -  é o parametro que recebera o novo ano a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraDataNascimento(Prof* professor, int dia, int mes, int ano);

/***********************************************************************
*
*  $FC Função: PRF altera Pais
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu País alterado.
* 					Este parâmetro é passado por referência.
*     $P pais -  é o parametro que recebera o novo País a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraPais(Prof* professor, char* pais);

/***********************************************************************
*
*  $FC Função: PRF altera UF
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua UF alterado.
* 					Este parâmetro é passado por referência.
*     $P uf -  é o parametro que recebera o nova UF a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraUf(Prof* professor, char* uf);

/***********************************************************************
*
*  $FC Função: PRF altera Cidade
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua cidade alterado.
* 					Este parâmetro é passado por referência.
*     $P cidade -  é o parametro que recebera o nova cidade a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraCidade(Prof* professor, char* cidade);

/***********************************************************************
*
*  $FC Função: PRF altera Bairro
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu bairro alterado.
* 					Este parâmetro é passado por referência.
*     $P bairro -  é o parametro que recebera o novo bairro a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraBairro(Prof* professor, char* bairro);

/***********************************************************************
*
*  $FC Função: PRF altera Rua
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá sua rua alterado.
* 					Este parâmetro é passado por referência.
*     $P rua -  é o parametro que recebera o nova rua a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraRua(Prof* professor, char* rua);

/***********************************************************************
*
*  $FC Função: PRF altera Numero
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu numero alterado.
* 					Este parâmetro é passado por referência.
*     $P numero -  é o parametro que recebera o novo numero a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraNumero(Prof* professor, int numero);

/***********************************************************************
*
*  $FC Função: PRF altera Complemento
*
*  $EP Parâmetros
*     $P professor - é o parâmetro que aponta para o professor que terá seu complemento alterado.
* 					 Este parâmetro é passado por referência.
*     $P complemento -  é o parametro que recebera o novo complemento a ser alterado no professor corrente.
*						
*  $FV Valor retornado
*     PRF_CondRetOk
*     PRF_CondRetNaoExisteProf - Ponteiro aponta para NULL.
*     PRF_CondRetFormatoInvalido - Formato invalido do dado a ser atribuído.
*
***********************************************************************/

PRF_tpCondRet PRF_alteraComplemento(Prof* professor, char* complemento);

//---------------- FIM DAS FUNÇÕES ALTERA --------------------------------------------------------------------------------------------

/********** Fim do módulo de definição: Módulo Professor **********/

