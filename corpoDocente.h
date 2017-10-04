/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.h
*  Letras identificadoras:      CDO
*
*  Nome da base de software:    Fonte do módulo Corpo Docente
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
*     Versão	Autor		Data		Observações
*       0.01   BM   02/10/2017	Protótipos adicionados 
*       0.01   BM   02/10/2017	Funcoes modelo adicionadas 
*       0.00   BM   01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*	  TODO
*
***************************************************************************/
typedef enum{
	CDO_CondRetOk,
	CDO_CondRetNaoHaMemoria,
	CDO_CondRetNaoExisteCorpo,
	CDO_CondRetProfessorNaoEncontrado,
	CDO_CondRetIdJaCriado,
	CDO_CondRetFormatoInvalido
} CDO_tpCondRet;

CDO_tpCondRet CDO_cria();
CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);
CDO_tpCondRet CDO_mostraAtual();
CDO_tpCondRet CDO_mostraTodos();
CDO_tpCondRet CDO_retira();
CDO_tpCondRet CDO_limpa();
CDO_tpCondRet CDO_libera();

CDO_tpCondRet CDO_buscaNome(char *chave);
CDO_tpCondRet CDO_buscaPorEmail(char *chave);
CDO_tpCondRet CDO_buscaPorCpf(char *chave);
CDO_tpCondRet CDO_buscaPorRg(int chave);

CDO_tpCondRet CDO_consultaNome(char *nome);
CDO_tpCondRet CDO_consultaRg(int *rg);
CDO_tpCondRet CDO_consultaCpf(char *cpf);
CDO_tpCondRet CDO_consultaMatricula(int *matricula);
CDO_tpCondRet CDO_consultaEmail(char *email);
CDO_tpCondRet CDO_consultaTelefone(int *tel);
CDO_tpCondRet CDO_consultaDataNascimento(int *dia, int *mes, int *ano);
CDO_tpCondRet CDO_consultaEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int *numero, char *complemento);

CDO_tpCondRet CDO_alteraNome(char *nome);
CDO_tpCondRet CDO_alteraRg(int rg);
CDO_tpCondRet CDO_alteraCpf(char *cpf);
CDO_tpCondRet CDO_alteraMatricula(int matricula);
CDO_tpCondRet CDO_alteraEmail(char* email);
CDO_tpCondRet CDO_alteraTelefone(int tel);
CDO_tpCondRet CDO_alteraDataNascimento(int dia, int mes, int ano);
CDO_tpCondRet CDO_alteraEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);