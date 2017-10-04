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
	0.31   NP   03/10/2017 	Documentação iniciada
*       0.30   BM   02/10/2017	Protótipos adicionados 
*       0.20   BM   02/10/2017	Funcoes modelo adicionadas 
*       0.10   BM   01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*	  TODO
*
***************************************************************************/
typedef enum{
	//TODO documentar os comentarios neste enum corretamente
	CDO_CondRetNaoHaMemoria,
	CDO_CondRetCorpoDocenteVazio,
	CDO_CondRetProfessorNaoEncontrado, // nas buscas, caso o professor nao seja encontrado, e em outras funcoes caso a lista esteja vazia (cursor aponta para null)
	CDO_CondRetIdJaCriado, //nao pode haver dois professores com o mesmo rg/cpf/matricula/email entao ao criar/alterar deve-se fazer uma busca.
	CDO_CondRetFormatoInvalido // quando uma altera/cria retorna formato invalido
} CDO_tpCondRet;

CDO_tpCondRet CDO_cria();
CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);
CDO_tpCondRet CDO_mostraAtual();
CDO_tpCondRet CDO_mostraTodos();
CDO_tpCondRet CDO_retira();
CDO_tpCondRet CDO_limpa();
CDO_tpCondRet CDO_libera();

/***********************************************************************
*
*  $FC Função: CDO Busca por Nome
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo Nome
*
*  $EP Parâmetros
*     
*     $P chave - Nome do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada não encontrado no Corpo Docente
*     CDO_CondRetNaoExisteCorpo - Caso não exista uma Instância de Corpo Docente 
*
*  Assertiva de Entrada: 
*		-A chave tem até 80 caracteres
*                    
*  Assertiva de Saída: 
*		-Caso exista uma instância de Professor com o Nome igual aquele enviado para a função via parâmetro a função retorno condição OK
*		-Caso não exista uma instância de Professor com o Nome igual aquele enviado para a funcão via parâmetro a função retorna condição de Prof não encontrado
*		-Caso não exista Corpo Docente válido a função retorna Não Existe Corpo
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorNome(char *chave);

/***********************************************************************
*
*  $FC Função: CDO Busca por RG
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo RG
*
*  $EP Parâmetros
*     
*     $P chave - RG do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetNaoExisteCorpo - Caso não exista uma Instância de Corpo Docente 
*
*  Assertiva de Entrada: 
*		-A chave tem até 80 caracteres
*                    
*  Assertiva de Saída: 
*		-Caso exista uma instância de Professor com o RG igual aquele enviado para a função via parâmetro a função retorno condição OK
*		-Caso não exista uma instância de Professor com o RG igual aquele enviado para a funcão via parâmetro a função retorna condição de Prof não encontrado
*		-Caso não exista Corpo Docente válido a função retorna Não Existe Corpo
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorRg(int chave);

/***********************************************************************
*
*  $FC Função: CDO Busca por CPF
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo CPF
*
*  $EP Parâmetros
*     
*     $P chave - CPF do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetNaoExisteCorpo - Caso não exista uma Instância de Corpo Docente 
*
*  Assertiva de Entrada: 
*		-A chave tem até 80 caracteres
*                    
*  Assertiva de Saída: 
*		-Caso exista uma instância de Professor com o CPF igual aquele enviado para a função via parâmetro a função retorno condição OK
*		-Caso não exista uma instância de Professor com o CPF igual aquele enviado para a funcão via parâmetro a função retorna condição de Prof não encontrado
*		-Caso não exista Corpo Docente válido a função retorna Não Existe Corpo
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorCpf(char *chave);

/***********************************************************************
*
*  $FC Função: CDO Busca por Matricula
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pela Matricula
*
*  $EP Parâmetros
*     
*     $P chave - Matricula do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetNaoExisteCorpo - Caso não exista uma Instância de Corpo Docente 
*
*  Assertiva de Entrada: 
*		-A chave tem até 80 caracteres
*                    
*  Assertiva de Saída: 
*		-Caso exista uma instância de Professor com a Matricula igual aquele enviado para a função via parâmetro a função retorno condição OK
*		-Caso não exista uma instância de Professor com a Matricula igual aquele enviado para a funcão via parâmetro a função retorna condição de Prof não encontrado
*		-Caso não exista Corpo Docente válido a função retorna Não Existe Corpo
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorMatricula(int *chave);

/***********************************************************************
*
*  $FC Função: CDO Busca por Email
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo Email
*
*  $EP Parâmetros
*     
*     $P chave - Email do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetNaoExisteCorpo - Caso não exista uma Instância de Corpo Docente 
*
*  Assertiva de Entrada: 
*		-A chave tem até 80 caracteres
*                    
*  Assertiva de Saída: 
*		-Caso exista uma instância de Professor com o Email igual aquele enviado para a função via parâmetro a função retorno condição OK
*		-Caso não exista uma instância de Professor com o Email igual aquele enviado para a funcão via parâmetro a função retorna condição de Prof não encontrado
*		-Caso não exista Corpo Docente válido a função retorna Não Existe Corpo
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorEmail(char *chave);

/***********************************************************************
*
*  $FC Função: CDO Consulta Nome
*
*  $ED Descrição da função
*     Consulta o Nome da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P nome - Cadeia de caracteres que receberá o nome do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-O ponteiro para o a cadeia nome é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaNome tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteudo do ponteiro para nome será preenchido com o nome do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaNome(char *nome);

/***********************************************************************
*
*  $FC Função: CDO Consulta RG
*
*  $ED Descrição da função
*     Consulta o RG da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P rg - Inteiro que receberá o rg do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-O ponteiro para o inteiro RG é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaRg tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para RG será preenchido com o RG do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaRg(int *rg);

/***********************************************************************
*
*  $FC Função: CDO Consulta CPF
*
*  $ED Descrição da função
*     Consulta o CPF da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P cpf - Cadeia de caracteres que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-O ponteiro para o cadeia CPF é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaCpf tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para CPF será preenchido com o CPF do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaCpf(char *cpf);

/***********************************************************************
*
*  $FC Função: CDO Consulta Matricula
*
*  $ED Descrição da função
*     Consulta a Matricula da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P matricula - Inteiro que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-O ponteiro para o inteiro matricula é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaMatricula tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para matricula será preenchido com a matricula do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaMatricula(int *matricula);

/***********************************************************************
*
*  $FC Função: CDO Consulta Email
*
*  $ED Descrição da função
*     Consulta o Email da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P email - Cadeia de Caracteres que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-O ponteiro para a cadeia email é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaEmail tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para email será preenchido com o email do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaEmail(char *email);

/***********************************************************************
*
*  $FC Função: CDO Consulta Telefone
*
*  $ED Descrição da função
*     Consulta o Telefone da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P telefone - Inteiro que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-O ponteiro para o inteiro telefone é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaTelefone tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para telefone será preenchido com o telefone do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaTelefone(int *tel);

/***********************************************************************
*
*  $FC Função: CDO Consulta Data de Nasciemnto
*
*  $ED Descrição da função
*     Consulta a data de Nascimento da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P dia - Inteiro que receberá o dia de nascimento do professor selecionado, por referência
*	  $P mes - Inteiro que receberá o mes de nascimento do professor selecionado, por referência
*     $P ano - Inteiro que receberá o ano de nascimento do professor selecionado, por referência
*
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-O ponteiro para o inteiro dia é válido
*		-O ponteiro para o inteiro mes é válido
*		-O ponteiro para o inteiro ano é valido
*                    
*  Assertiva de Saída: 
*	    -É necessário que as função  PRF_consultaDiaNascimento,	PRF_consultaMesNascimento, PRF_consultaAnoNascimento tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo dos ponteiros para dia/mes/ano serão preenchidos com o dia/mes/ano da data de nascimento do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaDataNascimento(int *dia, int *mes, int *ano);

/***********************************************************************
*
*  $FC Função: CDO Consulta Endereço
*
*  $ED Descrição da função
*     Consulta o Endereço da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P pais - Cadeia de Caracteres que receberá o pais de moradia do professor selecionado, por referência
*	  $P uf - Cadeia de Caracteres que receberá o uf de moradia do professor selecionado, por referência
*     $P cidade - Cadeia de Caracteres que receberá a cidade de moradia do professor selecionado, por referência
*     $P bairro - Cadeia de Caracteres que receberá o bairro de moradia do professor selecionado, por referência
*	  $P rua - Cadeia de Caracteres que receberá o a rua de moradia professor selecionado, por referência
*     $P numero - Inteiro que receberá o numero da moradia do professor selecionado, por referência
*     $P complemento - Cadeia de Caracteres que receberá o complemento da moradia do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-
*                    
*  Assertiva de Saída: 
*	    -
*       -
*
***********************************************************************/

CDO_tpCondRet CDO_consultaEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int *numero, char *complemento);

CDO_tpCondRet CDO_alteraNome(char *nome);
CDO_tpCondRet CDO_alteraRg(int rg);
CDO_tpCondRet CDO_alteraCpf(char *cpf);
CDO_tpCondRet CDO_alteraMatricula(int matricula);
CDO_tpCondRet CDO_alteraEmail(char* email);
CDO_tpCondRet CDO_alteraTelefone(int tel);
CDO_tpCondRet CDO_alteraDataNascimento(int dia, int mes, int ano);
CDO_tpCondRet CDO_alteraEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);
