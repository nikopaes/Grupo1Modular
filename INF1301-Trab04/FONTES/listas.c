/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              listas.c
*  Letras identificadoras:      LIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Disciplina INF 1301
*  Gestor:  Grupo 1
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data				Observações
*		1.10			06/12/2017
*		1.00	RP,FA	04/12/2017		Deturpa e Verifica
*       0.04   GRUPO4   10/09/2017		Herdou lista.c versao 0.04 do grupo 4
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

#ifdef _DEBUG
#include   "Generico.h"
#include   "Conta.h"
#include   "cespdin.h"
#include   "IdTiposEspacoLista.def"
#endif

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização dos Nós em uma Lista
*
***********************************************************************/
struct node
{
	struct node* next;	//Aponta para o próximo nó
	struct node* prev;  //Aponta para o nó anterior
	void* val;			//Aponta para variável val
#ifdef _DEBUG
	int tipo;	/* tipo do dado armazenado no elemento */
	int tamMEM; /* tamanho de memoria utilizado pelo no */
	List * pCabeca; /* Ponteiro para a cabeça da lista */
				
#endif
};
/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização de uma Lista pelo cabeçalho. Pode-se fazer Listas de Listas.
*
***********************************************************************/
struct list
{
	Node* first;  //Aponta para o primeiro nó
	Node* last;	  //Aponta para o último nó
	Node* cursor; //Aponta para o nó cursor
		int tam;            //numero de elementos da lista
#ifdef _DEBUG
     int tipo;		/* tipo do dado armazenado no elemento */
     int tamElementos; /* tamanho total de memoria utilizado pelos elementos da lista */           
#endif
};
/***************************************************************************
*
*  Função: LIS create list
*  ****/
LIS_tpCondRet createList(List** l){ (*l) = (List*) calloc(1, sizeof(List)); if(!l) return LIS_CondRetFaltouMemoria; (*l)->first = NULL; (*l)->last = NULL; (*l)->cursor = NULL; return LIS_CondRetOK; }
/* Fim função: LIS create lista */
/***************************************************************************
*
*  Função: LIS del
*  ****/
LIS_tpCondRet del(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while(tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	free(l);
	return LIS_CondRetOK;
}/* Fim função: LIS del */
/***************************************************************************
*
*  Função: LIS clear
*  ****/
LIS_tpCondRet clear(List* l)
{
	Node* tnode = l->first;
	l->cursor = l->first;
	while(tnode != NULL)
	{
		l->cursor = l->cursor->next;
		free(tnode);
		tnode = l->cursor;
	}
	l->first = NULL;
	l->last = NULL;
	l->cursor = NULL;
	return LIS_CondRetOK;
}/* Fim função: LIS del */

/***************************************************************************
*
*  Função: LIS push back
*  ****/
LIS_tpCondRet push_back(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) calloc (1, sizeof(Node));
	if(!Nnode)
		return LIS_CondRetFaltouMemoria;
	Nnode->val = val;
	Nnode->next = NULL;
	if(l->first == NULL)//Se a lista estiver vazia, primeiro nó = último nó = nó cursor.
	{
		l->first = Nnode;
		l->cursor = Nnode;
		Nnode->prev = NULL;
	}
	else
	{
		Nnode->prev = l->last;
		l->last->next = Nnode;
	}
	l->last = Nnode;
	return LIS_CondRetOK;
} /* Fim função: LIS push back */
/***************************************************************************
*
*  Função: LIS push front
*  ****/
LIS_tpCondRet push_front(List* l, void* val)
{
	Node* Nnode;
	Nnode = (Node*) calloc(1, sizeof(Node));
	if(!Nnode)
		return LIS_CondRetFaltouMemoria;
	Nnode->val = val;
	Nnode->prev = NULL;
	if(l->first == NULL)
	{
		l->last = Nnode;
		l->cursor = Nnode;
		Nnode->next = NULL;
	}
	else
	{
		Nnode->next = l->first;
		l->first->prev = Nnode;
	}
	l->first = Nnode;
	return LIS_CondRetOK;
} /* Fim função: LIS push front */
/***************************************************************************
*
*  Função: LIS pop back
*  ****/
LIS_tpCondRet pop_back(List* l, void** val)
{
	Node* tnode;
	if(l->first == NULL) {
	//	printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");
		return LIS_CondRetListaVazia;
	}

	*val = l->last->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if(l->cursor == l->last)
		l->cursor = l->last->prev;
	tnode = l->last;
	l->last = l->last->prev;
	l->last->next = NULL;
	tnode->prev = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS pop back */
/***************************************************************************
*
*  Função: LIS pop front
*  ****/
LIS_tpCondRet pop_front(List* l, void** val)
{
	Node* tnode;
	if(l->first == NULL) {
#ifdef _DEBUG	
		printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");
#endif
		return LIS_CondRetListaVazia;
	}

	*val = l->first->val;

	if (l->first == l->last)
	{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
	}
	if(l->cursor == l->first)
		l->cursor = l->first->next;
	tnode = l->first;
	l->first = l->first->next;
	l->first->prev = NULL;
	tnode->next = NULL;
	return LIS_CondRetOK;
} /* Fim função: LIS pop front */
/***************************************************************************
*
*  Função: LIS pop cursor
*  ****/
LIS_tpCondRet pop_cursor(List* l, void** val)
{
	Node* tnode;
	if(l->cursor == l->first)
		return pop_front(l, val);
	else if(l->cursor == l->last)
		return pop_back(l, val);
	else
	{
		if(l->first == NULL) {
#ifdef _DEBUG	
		printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");
#endif
		return LIS_CondRetListaVazia;}
		
		*val = l->cursor->val;
	
		if (l->first == l->last)
		{
		l->first = NULL;
		l->last = NULL;
		l->cursor = NULL;
		return LIS_CondRetOK;
		}
		tnode = l->cursor;
		l->cursor->prev->next = l->cursor->next;
		l->cursor->next->prev = l->cursor->prev;
		l->cursor = l->cursor->next;
		tnode->next = NULL;
		tnode->prev = NULL;
		return LIS_CondRetOK;
		}
} /* Fim função: LIS pop cursor */
/***************************************************************************
*
*  Função: LIS get val cursor
*  ****/
LIS_tpCondRet get_val_cursor(List* l, void** val)
{
	if(l->first == NULL) {
#ifdef _DEBUG	
		printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");
#endif
		return LIS_CondRetListaVazia;} 
	*val = l->cursor->val;
	return LIS_CondRetOK;
}/* Fim função: LIS get val cursor */
/***************************************************************************
*
*  Função: LIS list size
*  ****/
LIS_tpCondRet list_size(List* l, unsigned int* size)
{
	Node* Tnode = l->first;
	if(l->first == NULL)
	{
		*size = 0;
		return LIS_CondRetListaVazia;
	}
	while(Tnode != NULL)
	{
		Tnode = Tnode->next;
		*size = *size +1;
	}
	return LIS_CondRetOK;
} /* Fim função: LIS list size */

/***************************************************************************
*
*  Função: LIS first
*  ****/
LIS_tpCondRet first(List* l){
	if(l->first == NULL) {
#ifdef _DEBUG	
		printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");
#endif
		return LIS_CondRetListaVazia;
	}
	l->cursor = l->first;
	return LIS_CondRetOK;
}


/***************************************************************************
*
*  Função: LIS next
*  ****/
LIS_tpCondRet next(List* l)
{
	if(l->first == NULL) {
#ifdef _DEBUG	
		printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");
#endif
		return LIS_CondRetListaVazia;}
	else if(l->cursor->next == NULL)
	{
#ifdef _DEBUG	
		printf("\n\n <!> Cursor ja posicionado no final da lista <!> \n\n");
#endif
		return LIS_CondRetCursorNoFinal;
	}
	else l->cursor = l->cursor->next;
	return LIS_CondRetOK;
} /* Fim função: LIS next */
/***************************************************************************
*
*  Função: LIS prev
*  ****/
LIS_tpCondRet prev(List* l)
{
	if(l->first == NULL) {
#ifdef _DEBUG	
		printf("\n\n <!><!><!> Lista Vazia! <!><!><!> \n\n");
#endif
		return LIS_CondRetListaVazia;}
	else if(l->cursor->prev == NULL)
	{
#ifdef _DEBUG	
		printf("\n\n <!> Cursor ja posicionado no inicio da lista <!> \n\n");
#endif
		return LIS_CondRetCursorNoInicio;
	}
	else l->cursor = l->cursor->prev;
	return LIS_CondRetOK;
} /* Fim função: LIS prev */


/***********************************************************************
*
*  $Função: LIS Limpar a cabeça da lista
*
***********************************************************************/
    void LimparCabeca( List* pList )
    {
    #ifdef _DEBUG
		CNT_CONTAR("LimparCabeca");
        pList->tamElementos = 0;
        pList->tipo = LIS_IdTipoNaoDefinido;
   #endif
        pList->first = NULL ;
        pList->last = NULL ;
        pList->cursor = NULL ;
        pList->tam  = 0 ;

    } /* Fim função: LIS  -Limpar a cabeça da lista */

#ifdef _DEBUG
//	Assertivas para lista (parte da matriz)
//A - Se o anterior à um nó não é nulo, então o próximo do anterior a ele é o próprio nó
//(Se pNo->pAnt != NULL, então pNo->pAnt->pProx = pNo );
// B - Se o próximo à um nó não é nulo, então o anterior do próximo a ele é o próprio nó
//(Se pNo->pProx != NULL, então pNo->pProx->pAnt = pNo );

/***************************************************************************
 *
 *  Função: CDO Verificador Estrutural
 *  ****/
	LIS_tpCondRet LIS_verificadorEstrutural(void* pListParam){
		List* pList;
		pList = (List*) pListParam;

		if(pList == NULL)
			return LIS_CondRetErroEstruturalLista;

		if(pList->first == NULL)
			return LIS_CondRetErroEstruturalFirstNull;

		if(pList->last == NULL)
			return LIS_CondRetErroEstruturalLastNull;

		if(pList->cursor == NULL)
			return LIS_CondRetErroEstruturalCursorNull;

		if(pList->first->prev != NULL)
			return LIS_CondRetErroEstruturalFirstPrev;

		if(pList->last->next != NULL)
			return LIS_CondRetErroEstruturalLastNext;

		first(pList);
		do{
			if(pList->cursor != pList->last && pList->cursor->next->prev != pList->cursor) 
				return LIS_CondRetErroEstruturalNoProximo;
			if(pList->cursor != pList->first && pList->cursor->prev->next != pList->cursor)
				return LIS_CondRetErroEstruturalNoAnterior;
		}while(next(pList)==LIS_CondRetOK);
		return LIS_CondRetOK;
	} /* Fim função: CDO Verificador Estrutural */

/***************************************************************************
 *
 *  Função: CDO Deturpador Estrutural
 *  ****/
	void deturpaLista(List* l, int deturpacao){
		if(deturpacao == 0){
			clear(l);
			l = NULL;
		}else if(deturpacao == 1){
			l->cursor->val = NULL;
		}
		else if(deturpacao == 2){
			l->first = NULL;
		}
		else if(deturpacao == 3){
			l->last = NULL;
		}
		else if(deturpacao == 4){
			l->cursor= NULL;
		}
		else if(deturpacao == 5){
			l->first->prev = l->cursor;
		}
		else if(deturpacao == 6){
			l->last->next = l->cursor;
		}
		else if(deturpacao == 7){
			l->cursor->prev = l->cursor;
		}
		else if(deturpacao == 8){
			l->cursor->next = l->cursor;
		}else if (deturpacao == 9){
			CED_DefinirTipoEspaco(l->cursor->val, LIS_IdCabecaLista);
		}
	}



/***********************************************************************
*
*  $FC Função: LIS Deturpar estrutura
*
*  $ED Descrição da função
*		Deturpa a estrutura, de acordo com a deturpacao fornecida.
*
*  $EP Parâmetros
*     $P pLista - ponteiro para a lista.
*     $P flag - tipo de deturpacao, pode ser:
*			1  - elimina o elemento corrente da estrutura escolhida.
*			2  - atribui NULL ao ponteiro para um nó sucessor.
*			3  - atribui NULL ao ponteiro para um nó predecessor.
*			4  - atribui lixo ao ponteiro para a referência a um nó sucessor
*			5  - atribui lixo ao ponteiro para a referência a um nó predecessor.
*			6  - atribui NULL ao ponteiro para o conteúdo do nó.
*			7  - altera o tipo de estrutura apontado no nó.
*			8  - destaca nó da lista sem liberá-lo com free
*			9  - atribui NULL ao ponteiro corrente
*			10 - atribui NULL a um ponteiro de origem.
*		//	11 - esvazia lista de vertices
*			12 - atribui lixo a todos os ponteiros para a cabeca da estrutura
*
*  $FV Valor retornado
*     LIS_CondRetOK
*
***********************************************************************/

	    /***************************************************************************
    *
    *  Função: LIS  &LIS Deturpar estrutura
    *  ****/

    LIS_tpCondRet LIS_Deturpar( LIS_tppLista pLista, int flag )
    {
        tpElemLista * ponteiroNaoInicializado, * auxProx, * auxAnt;
        switch(flag)
        {
            case 1:
                pLista->pElemCorr->pAnt = NULL;
                break;

            case 2:
                pLista->pElemCorr->pProx = NULL;
                break;

            case 3:
                pLista->pElemCorr->pValor = NULL;
                break;

            case 4:
                CED_DefinirTipoEspaco(pLista->pElemCorr->pValor, LIS_IdCabecaLista);
                break;

            case 5:
                auxAnt = pLista->pElemCorr->pAnt;
                auxProx = pLista->pElemCorr->pProx;
                pLista->pElemCorr->pProx->pAnt = auxAnt;
                pLista->pElemCorr->pAnt->pProx = auxProx;
                break;

            case 6:
                pLista->pElemCorr = NULL;
                break;

            case 7:
                pLista->pOrigemLista = NULL;
                break;

            case 8:
                pLista->pElemCorr->pAnt = pLista->pElemCorr->pAnt->pAnt;
                break;

            case 9:
                pLista->pElemCorr->pProx = pLista->pElemCorr->pProx->pProx;
                break;

            case 10:
                pLista->pElemCorr->tipo = LIS_IdTipoNaoDefinido;
                break;
        }

        return LIS_CondRetOK;
    }

#endif
