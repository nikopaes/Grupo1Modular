typedef struct prof Prof;


typedef enum{
	PRF_tpCondRetOk,
	PRF_tpCondRetErro,
} PRF_tpCondRet;

PRF_tpCondRet criaProf(Prof** p);
PRF_tpCondRet mostraProf(Prof* p);
PRF_tpCondRet liberaProf(Prof* p);
