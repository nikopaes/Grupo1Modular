typedef struct prof Prof;

typedef enum{
	PRF_CondRetOk,
	PRF_CondRetNaoHaMemoria,
	PRF_CondRetNaoExisteProf,
	PRF_CondRetProfessorJaCriado,
	PRF_CondRetFormatoInvalido,
	PRF_CondRetErro
} PRF_tpCondRet;



PRF_tpCondRet PRF_cria(Prof** professor, int matricula, char *cpf, char *pais, int dia, int mes, int ano);

PRF_tpCondRet PRF_libera(Prof** p);

/* 
Incluir esta função no modulo corpoDocente

Note que esta será uma família de funções. Podemos querer disponibilizar a busca por diversos dados como: nome, matricula, etc.

tpCondRet ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada);
*/

PRF_tpCondRet PRF_mostra(Prof* p);


//------------------------------------------------------------------- FUNÇÕES CONSULTA --------------------------------------------------------------------------------------------
PRF_tpCondRet PRF_consultaNome(Prof* professor, char* nome);
PRF_tpCondRet PRF_consultaRg(Prof *professor, int *rg);
PRF_tpCondRet PRF_consultaCpf(Prof *professor, char *cpf);
PRF_tpCondRet PRF_consultaMatricula(Prof *professor, int *matricula);
PRF_tpCondRet PRF_consultaEmail(Prof* professor, char* email);
PRF_tpCondRet PRF_consultaTelefone(Prof *professor, int *telefone);
PRF_tpCondRet PRF_consultaDiaNascimento(Prof *professor, int *dia);
PRF_tpCondRet PRF_consultaMesNascimento(Prof *professor, int *mes);
PRF_tpCondRet PRF_consultaAnoNascimento(Prof *professor, int *ano);
PRF_tpCondRet PRF_consultaPais(Prof *professor, char *pais);
PRF_tpCondRet PRF_consultaUf(Prof *professor, char *uf);
PRF_tpCondRet PRF_consultaCidade(Prof *professor, char *cidade);
PRF_tpCondRet PRF_consultaBairro(Prof *professor, char *bairro);
PRF_tpCondRet PRF_consultaRua(Prof *professor, char *rua);
PRF_tpCondRet PRF_consultaNumero(Prof *professor, int *numero);
PRF_tpCondRet PRF_consultaComplemento(Prof *professor, char *complemento);


//------------------------------------------------------------------- FUNÇÕES ALTERA --------------------------------------------------------------------------------------------
PRF_tpCondRet PRF_alteraNome(Prof* p, char* nome);
PRF_tpCondRet PRF_alteraRg(Prof* p, int rg);
PRF_tpCondRet PRF_alteraCpf(Prof* p, char* cpf);
PRF_tpCondRet PRF_alteraMatricula(Prof* p, int matricula);
PRF_tpCondRet PRF_alteraEmail(Prof* p, char* email);
PRF_tpCondRet PRF_alteraTelefone(Prof* p, int tel);
PRF_tpCondRet PRF_alteraDataNascimento(Prof* p, int dia, int mes, int ano);
PRF_tpCondRet PRF_alteraPais(Prof* prof, char* pais);
PRF_tpCondRet PRF_alteraUf(Prof* prof, char* uf);
PRF_tpCondRet PRF_alteraCidade(Prof* prof, char* cidade);
PRF_tpCondRet PRF_alteraBairro(Prof* prof, char* bairro);
PRF_tpCondRet PRF_alteraRua(Prof* prof, char* rua);
PRF_tpCondRet PRF_alteraNumero(Prof* prof, int numero);
PRF_tpCondRet PRF_alteraComplemento(Prof* prof, char* complemento);
