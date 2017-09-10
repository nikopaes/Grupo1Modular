/*! \file professor.h
    \brief Arquivo header para o modulo Professor
    
    Detalhes adicionais
*/

/** @defgroup moduloProfessorH Modulo Professor.h
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
	PRF_CondRetErro /**< Condicao de Retorno ERRO, quando a funcao nao funciona como esperado e nao apresenta erro especifico e ja esperado*/ 
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
PRF_tpCondRet PRF_cria(Prof** professor, int matricula, char *cpf, char *pais, int dia, int mes, int ano);

/*! \fn PRF_tpCondRet PRF_libera(Prof** p);
    \brief Libera o espaco de memoria que esta guardando as informacoes do professor apontado
    \param professor Ponteiro apontando para uma struct professor
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_libera(Prof** p);

/* 
Incluir esta função no modulo corpoDocente

Note que esta será uma família de fuções. Podemos querer disponibilizar a busca por diversos dados como: nome, matricula, etc.

tpCondRet ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada);
*/

/*! \fn PRF_tpCondRet PRF_mostra(Prof* p);
    \brief Imprime no Prompt de Comando todas as informacoes referentes ao professor apontado
    \param professor Ponteiro apontando para uma struct professor
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_mostra(Prof* p);


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

/** @}*/ // Fim do Bloco de Funcoes de Consulta

//------------------------------------------------------------------- FUNÇÕES ALTERA --------------------------------------------------------------------------------------------
/** \name Funcoes de Alteracao
 *  Funcoes que alteram as informacoes guardadas referentes a um professor
*/

/**@{*/ 

/*! \fn PRF_tpCondRet PRF_alteraNome(Prof* p, char* nome);
    \brief Altera o nome de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param nome O ponteiro para uma string que substituira o nome do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraNome(Prof* p, char* nome);

/*! \fn PRF_tpCondRet PRF_alteraRg(Prof* p, int rg);
    \brief Altera o RG de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param rg Um int que substituira o rg do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraRg(Prof* p, int rg);

/*! \fn PRF_tpCondRet PRF_alteraCpf(Prof* p, char* cpf);
    \brief Altera o CPF de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param cpf O ponteiro para uma string que substituira o cpf do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraCpf(Prof* p, char* cpf);

/*! \fn PRF_tpCondRet PRF_alteraMatricula(Prof* p, int matricula);
    \brief Altera a matricula de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param matricula Um int que substituira a matricula do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraMatricula(Prof* p, int matricula);

/*! \fn PRF_tpCondRet PRF_alteraEmail(Prof* p, char* email);
    \brief Altera o email de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param email O ponteiro para uma string que substituira o email do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraEmail(Prof* p, char* email);

/*! \fn PRF_tpCondRet PRF_alteraTelefone(Prof* p, int tel);
    \brief Altera o telefone de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param telefone Um int que substituira o telefone do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraTelefone(Prof* p, int tel);

/*! \fn PRF_tpCondRet PRF_alteraDataNascimento(Prof* p, int dia, int mes, int ano);
    \brief Altera a data de nascimento completa de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param dia Um int que substituira o dia de nascimento do professor apontado
    \param mes Um int que substituira o mes de nascimento do professor apontado 
    \param ano Um int que substituira o ano de nascimento do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraDataNascimento(Prof* p, int dia, int mes, int ano);

/*! \fn PRF_tpCondRet PRF_alteraPais(Prof* prof, char* pais);
    \brief Altera o pais de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param pais O ponteiro para uma string que substituira o pais do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraPais(Prof* prof, char* pais);

/*! \fn PRF_tpCondRet PRF_alteraUf(Prof* prof, char* uf);
    \brief Altera o uf de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param uf O ponteiro para uma string que substituira o uf do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraUf(Prof* prof, char* uf);

/*! \fn PRF_tpCondRet PRF_alteraCidade(Prof* prof, char* cidade);
    \brief Altera o cidade da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param cidade O ponteiro para uma string que substituira o cidade do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraCidade(Prof* prof, char* cidade);

/*! \fn PRF_tpCondRet PRF_alteraBairro(Prof* prof, char* bairro);
    \brief Altera o bairro da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param bairro O ponteiro para uma string que substituira o bairro da residencia do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraBairro(Prof* prof, char* bairro);

/*! \fn PRF_tpCondRet PRF_alteraRua(Prof* prof, char* rua);
    \brief Altera o bairro da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param rua O ponteiro para uma string que substituira a rua da residencia do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraRua(Prof* prof, char* rua);

/*! \fn PRF_tpCondRet PRF_alteraNumero(Prof* prof, int numero);
    \brief Altera o numero da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param numero O ponteiro para uma string que substituira o bairro da residencia do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraNumero(Prof* prof, int numero);

/*! \fn PRF_tpCondRet PRF_alteraComplemento(Prof* prof, char* complemento);
    \brief Altera o complemento da residencia de um professor
    \param professor Ponteiro apontando para a struct professor que deseja alterar
    \param complemento O ponteiro para uma string que substituira o complemento da residencia do professor apontado
    \return Condicao de retorno como definido em \a PRF_tpCondRet
*/
PRF_tpCondRet PRF_alteraComplemento(Prof* prof, char* complemento);

/** @}*/ // Fim do Bloco de Funcoes de Alteracao

/** @}*/ // Fim do Modulo ProfessorH
