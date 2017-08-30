typedef struct prof Prof;


typedef enum{
	professorCriadoErro,
	professorCriadoOk,
	professorMostraOk,
	professorLiberaOk,
} tpCondRetProfessor;

tpCondRetProfessor criaProf(Prof** p,int mat, char*nome);
tpCondRetProfessor mostraProf(Prof* p);
tpCondRetProfessor liberaProf(Prof* p);
