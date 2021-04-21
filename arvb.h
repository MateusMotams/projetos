#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct arvb ArvB;

int arv_vazia(ArvB *a);

/*Fun��o que cria uma �rvore Bin�ria de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);
/*Testa se uma �rvore Bin�ria � vazia.*/
int arvb_vazia(ArvB *a);
/*Fun��o que busca a sub-�rvore que cont�m um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);
/*Fun��o que imprime os elementos de uma �rvore.*/
void arvb_imprime(ArvB *a);
/*Fun��o que retorna a altura de uma �rvore*/
int arv_altura(ArvB *a);
/*Fun��o que insere um inteiro em uma �rvore.*/
ArvB* arvb_insere(ArvB *a, int c);
/*Fun��o que remove um inteiro em uma �rvore.*/
ArvB* arvb_remove(ArvB *a, int c);
/*Libera o espa�o alocado para uma �rvore.*/
void arvb_libera(ArvB *a);

//----------------------- Fun��es do Trabalho-----------------------------//

//fun��o que retorne a quantidade de folhas de uma �rvore bin�ria de busca que possuem no campo info um n�mero divis�vel por n.
int folhas_div_n(ArvB* a, int n);

//b)fun��o que decida se uma �rvore � degenerada
int isdegenerada(ArvB* a);

//c) fun��o que, dada uma �rvore bin�ria de busca, retorne a quantidade de n�s que tenham fator de balanceamento igual a n
int nos_fb_n(ArvB* a, int n);

//d) fun��o que imprima os elementos em comum de duas �rvores bin�rias de busca
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

// e) fun��o que imprima os elementos de uma �rvore bin�ria de busca por n�veis
void impressao_arv_niveis(ArvB* a);

// Fun��o para comparar um n� com uma arvore (EXTRA).
int compara(int a, ArvB *b);

// fun��o responsavel por imprimir os elementos de uma arvore dependendo do nivel passado (EXTRA).
void imprime_nivel(ArvB *a, int nivel);
	

#endif
