#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

struct arvb{
	int info;
	ArvB *esq;
	ArvB *dir;
};

ArvB* arvb_cria_vazia(void){
	return NULL;
}

int arvb_vazia(ArvB *a){
	return a==NULL;
}

ArvB* arvb_busca(ArvB *a, int c){
	if(arvb_vazia(a))
		return NULL;
	else if(a->info < c)
		return arvb_busca(a->dir,c);
	else if(a->info > c)
		return arvb_busca(a->esq,c);
	else //(a->info == c)
		return a;
}

void arvb_imprime(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_imprime(a->esq);
		printf("%d ",a->info);
		arvb_imprime(a->dir);
		}
}

int arvb_altura(ArvB *a){
	if(arvb_vazia(a))
		return -1;
	else{
		int hSAE = arvb_altura(a->esq);
		int hSAD = arvb_altura(a->dir);
		if(hSAE > hSAD)
			return 1+hSAE;
	else
		return 1+hSAD;
	}
}

ArvB* arvb_insere(ArvB *a, int c){
	if(arvb_vazia(a)){
		a = (ArvB*)malloc(sizeof(ArvB));
		a->info = c;
		a->esq = NULL;
		a->dir = NULL;
	}else if(a->info > c)
		a->esq = arvb_insere(a->esq,c);
	else if (a->info < c)
		a->dir = arvb_insere(a->dir,c);
	else
		printf("\nElemento Ja Pertence a Arvore");
		return a;
}

ArvB* arvb_remove(ArvB *a, int c){
	if(!arvb_vazia(a)){
		if(a->info > c)
			a->esq = arvb_remove(a->esq,c);
		else if (a->info < c)
			a->dir = arvb_remove(a->dir,c);
		else{
			ArvB* t;
		if (a->esq == NULL){
			t = a; a = a->dir;
			free(t);
			}
		else if (a->dir == NULL){
			t = a; a = a->esq;
			free(t);
			}
		else{
			t = a->esq;
			while(t->dir!=NULL)
				t = t->dir;
			a->info = t->info; t->info = c;
			a->esq = arvb_remove(a->esq,c);
		}
		}
	}
	return a;
}

void arvb_libera(ArvB *a){
	if(!arvb_vazia(a)){
		arvb_libera(a->esq);
		arvb_libera(a->dir);
		free(a);
	}
}

//----------------------- Fun��es do Trabalho-----------------------------//

//a)
//fun��o que retorne a quantidade de folhas de uma �rvore bin�ria de busca que possuem no campo info um n�mero divis�vel por n.
int folhas_div_n(ArvB* a, int n){
int cont = 0; // guarda a quantidade de folhas divisiveis por n na �rvore 
    if(a == NULL){
        return 0;
    }
    if( a->dir == NULL && a->esq == NULL){ // se a sub-arvore en�o tiver filhos ela vai ser uma folha
        if(a->info % n == 0) // logo se o numero contido em info for divisivel por n incrementa a o contador
            cont++;
         
    } else {
        cont = cont + folhas_div_n(a->esq, n); //chamada recursiva que testa as sub-�rvores a esquerda
        cont = cont + folhas_div_n(a->dir, n); //chamada recursiva que testa as sub-�rvores a direita
    }
    return cont; 
}

//b)fun��o que decida se uma �rvore � degenerada
int isdegenerada(ArvB* a){
	if (a->dir != NULL && a->esq != NULL) { // se a raiz tiver os dois filhos, ent�o n�o ser� degenerada .
        return 0;
        }
        if (a->esq != NULL && a->dir == NULL) { // se a �rvore direita for NULL e a esquerda n�o, pode ser degenerada.
            return isdegenerada(a->esq); // para saber se � degenerada � feito um teste de forma recursiva com a sub-�rvore esquerda.
        } else if (a->dir != NULL && a->esq == NULL) { // se a �rvore esquerda for NULL e a direta n�o, a mesma pode ser degenarada.
            return isdegenerada(a->dir); // � chamada de forma recursiva para testar a sub-�rvore direita.
        }

        return 1; // caso o c�digo esteja chegado em uma folha e n�o tivr entrado no primeiro if, ent�o ser� uma �rvore degenerada.
    }

//c) fun��o que, dada uma �rvore bin�ria de busca, retorne a quantidade de n�s que tenham fator de balanceamento igual a n
int nos_fb_n(ArvB* a, int n){
	int cont = 0; 
	if(a == NULL) // se a �rvore for fazia retorna cont =0
		return cont;
	int Fatb = arvb_altura(a->dir) - arvb_altura(a->esq); // recebe a altura dos n�s da diretia - a dos n�s a esquerda que � o fator de balanceamento.
	if(Fatb == n) // se o fator de balanceamento for igual a n incrementa cont.
		cont++; 
	cont  = cont + nos_fb_n(a->esq, n) + nos_fb_n(a->dir, n); // chamada recursiva para rebeber os fatores de balancemanto das sub-�rvores a esquerda e a direita.
	return cont;
}

//d) fun��o que imprima os elementos em comum de duas �rvores bin�rias de busca
void impressao_arv_elem_comuns(ArvB* a, ArvB* b){	
// esta fun��o percorre os n�s da �rvore a 
if(a != NULL){ // se a arvore a n�o for nula
        if(compara(a->info,b) == 1) // compara o campo info de a, com o info de b atrav�s da fun��o compara
        {
            printf("elemento comum: %d \n",a->info); // se form iguais ent�o � printado na tela o elemento em comum
        }
        impressao_arv_elem_comuns(a->dir,b); // chamada recursiva para testar os elementos comuns a direita da arvore a com o valor de b
        impressao_arv_elem_comuns(a->esq,b); // chamada recursiva para testar os elementos comuns a esquerda da arvore a com o valor de b
	}
}
// e) fun��o que imprima os elementos de uma �rvore bin�ria de busca por n�veis
void impressao_arv_niveis(ArvB* a){
    int i;
    int cont = arvb_altura(a); // contador recebe a altura da arvore a.
    for (i = 0; i <=cont; i++){ // percorre do nivel 0 at� o maior n�vel da arvore a.
        imprime_nivel(a, i); // fun��o responsavel por imprimir os elementos contidos no n�vel i.
        printf("- nivel %d\n",i); // printa na tela qual o nivel vigente.
    }
}


// Fun��o para comparar um n� com uma arvore (EXTRA).
int compara(int a, ArvB *b){
// Esta fun��o percorre os n�s de b.
    if(b != NULL){ // caso b n�o seja Nulo
	    if(a == b->info){ // testa o valor de a->info com b->info
            return 1; // retorna 1 caso seja verdadeiro
	    }
	    if(compara(a, b->esq) != 1 && compara(a, b->dir) != 1){ 
		// percorre de forma recursiva tanto os elementos a esquerda como a direta de b, caso n�o
		// caso n�o seja verdadeiro em nenhum caso retorna falso (0)
            return 0;
        }
	}
}
// fun��o responsavel por imprimir os elementos de uma arvore dependendo do nivel passado (EXTRA).
void imprime_nivel(ArvB *a, int nivel){
    if (a != NULL && nivel == 0){ // se a n�o for nulo e n�vel for = 0 quer dizer que chegou no nivel que queremos atingir
    // EX: nivel = 2; vai entrar no else 2 vezes e chamar de forma recursiva tanto a sub-arvore esquerda quanto a direita e decrementar 1 n�vel 
    
        printf("%d ", a->info);
    }   
    else if (a != NULL){
    	// chamadas recursivas responsaveis por decrementar o nivel at� 0 e percorrer os n�s na arvore 
        imprime_nivel(a->esq, nivel - 1); 
        imprime_nivel(a->dir, nivel - 1);
    }
}



