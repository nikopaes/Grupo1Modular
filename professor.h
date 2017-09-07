typedef struct prof Prof;

typedef enum{
	PRF_CondRetOk,
	PRF_CondRetNaoHaMemoria,
	PRF_CondRetNaoExisteProf,
	PRF_CondRetProfessorJaCriado,
	PRF_CondRetFormatoInvalido,
	PRF_CondRetErro
} PRF_tpCondRet;



PRF_tpCondRet criaProf(Prof** professor, int matricula, char *cpf, char *pais, int dia, int mes, int ano);
PRF_tpCondRet consultaCpfProf(Prof *p, char *cpf);
PRF_tpCondRet consultaPaisProf(Prof *p, char *pais);
PRF_tpCondRet consultaMatriculaProf(Prof *p, int *matricula);
PRF_tpCondRet ObtemProf(struct listaDeProfs *listaCorpoDocente, int matriculaProcurada);

PRF_tpCondRet alteraCpfProf(Prof *p, char *cpf);
PRF_tpCondRet alteraPaisProf(Prof *p, char *pais);
PRF_tpCondRet alteraMatriculaProf(Prof *p, int matricula);
PRF_tpCondRet mostraProf(Prof* p);
PRF_tpCondRet liberaProf(Prof** p);
PRF_tpCondRet mostraEndereco(Endereco* end);
PRF_tpCondRet mostraData(Data* d);

//-----------------------
PRF_tpCondRet alteraProf(Prof* p, char* nome, char* email, int matricula, int telefone, char* rua, int numero, int dia, int mes, int ano, int rg, char* cpf);
int verificaData(int dia, int mes, int ano);

PRF_tpCondRet alteraData(Prof* prof, int dia, int mes, int ano);

PRF_tpCondRet consultaEndereco(Prof* prof);
PRF_tpCondRet alteraCasa(Prof* prof, char* rua, int numero, char* complemento);
PRF_tpCondRet alteraBairro(Prof* prof, char* bairro, char* rua, int numero, char* complemento);
PRF_tpCondRet alteraCidade(Prof* prof, char* cidade, char* bairro, char* rua, int numero, char* complemento);
PRF_tpCondRet alteraUf(Prof* prof, char* uf, char* cidade, char* bairro, char* rua, int numero, char* complemento);
PRF_tpCondRet alteraPais(Prof* prof, char* pais, char* uf, char* cidade, char* bairro, char* rua, int numero, char* complemento);
PRF_tpCondRet alteraProfNome(Prof* p, char* nome);
PRF_tpCondRet alteraProfCpf(Prof* p, char* cpf);
PRF_tpCondRet alteraProfMatricula(Prof* p, int matricula);
PRF_tpCondRet alteraProfEmail(Prof* p, char* email);
PRF_tpCondRet alteraProfRg(Prof* p, int rg);
PRF_tpCondRet alteraProfDataNasciemento(Prof* p, int dia, int mes, int ano);
