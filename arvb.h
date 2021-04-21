#ifndef LIBRARY_H
#define LIBRARY_H

typedef struct arvb ArvB;

int arv_vazia(ArvB *a);

/*Função que cria uma Árvore Binária de Busca Vazia.*/
ArvB* arvb_cria_vazia(void);
/*Testa se uma Árvore Binária é vazia.*/
int arvb_vazia(ArvB *a);
/*Função que busca a sub-árvore que contém um inteiro.*/
ArvB* arvb_busca(ArvB *a,int c);
/*Função que imprime os elementos de uma Árvore.*/
void arvb_imprime(ArvB *a);
/*Função que retorna a altura de uma árvore*/
int arv_altura(ArvB *a);
/*Função que insere um inteiro em uma Árvore.*/
ArvB* arvb_insere(ArvB *a, int c);
/*Função que remove um inteiro em uma Árvore.*/
ArvB* arvb_remove(ArvB *a, int c);
/*Libera o espaço alocado para uma Árvore.*/
void arvb_libera(ArvB *a);

//----------------------- Funções do Trabalho-----------------------------//

//função que retorne a quantidade de folhas de uma árvore binária de busca que possuem no campo info um número divisível por n.
int folhas_div_n(ArvB* a, int n);

//b)função que decida se uma árvore é degenerada
int isdegenerada(ArvB* a);

//c) função que, dada uma árvore binária de busca, retorne a quantidade de nós que tenham fator de balanceamento igual a n
int nos_fb_n(ArvB* a, int n);

//d) função que imprima os elementos em comum de duas árvores binárias de busca
void impressao_arv_elem_comuns(ArvB* a, ArvB* b);

// e) função que imprima os elementos de uma árvore binária de busca por níveis
void impressao_arv_niveis(ArvB* a);

// Função para comparar um nó com uma arvore (EXTRA).
int compara(int a, ArvB *b);

// função responsavel por imprimir os elementos de uma arvore dependendo do nivel passado (EXTRA).
void imprime_nivel(ArvB *a, int nivel);
	

#endif
