typedef struct prof Prof;

typedef enum{
	PRF_CondRetOk,
	PRF_CondRetNaoHaMemoria,
	PRF_CondRetNaoExisteProf,
	PRF_CondRetErro,
	PRF_CondRetProfessorJaCriado
} PRF_tpCondRet;

PRF_tpCondRet criaProf(Prof** prof, int matricula, char *cpf, char *pais, int dia, int mes, int ano);
PRF_tpCondRet consultaCpfProf(Prof *p, char *cpf);
PRF_tpCondRet consultaPaisProf(Prof *p, char *pais);
PRF_tpCondRet consultaMatriculaProf(Prof *p, int *matricula);
PRF_tpCondRet alteraCpfProf(Prof *p, char *cpf);
PRF_tpCondRet alteraPaisProf(Prof *p, char *pais);
PRF_tpCondRet alteraMatriculaProf(Prof *p, int matricula);
PRF_tpCondRet mostraProf(Prof* p);
PRF_tpCondRet liberaProf(Prof** p);

//-----------------------
PRF_tpCondRet alteraProf(Prof* p, char* nome, char* email, int matricula, int telefone, char* rua, int numero, int dia, int mes, int ano, int rg, char* cpf);
