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

//----------------------- Funções do Trabalho-----------------------------//

//a)
//função que retorne a quantidade de folhas de uma árvore binária de busca que possuem no campo info um número divisível por n.
int folhas_div_n(ArvB* a, int n){
int cont = 0; // guarda a quantidade de folhas divisiveis por n na árvore 
    if(a == NULL){
        return 0;
    }
    if( a->dir == NULL && a->esq == NULL){ // se a sub-arvore enão tiver filhos ela vai ser uma folha
        if(a->info % n == 0) // logo se o numero contido em info for divisivel por n incrementa a o contador
            cont++;
         
    } else {
        cont = cont + folhas_div_n(a->esq, n); //chamada recursiva que testa as sub-árvores a esquerda
        cont = cont + folhas_div_n(a->dir, n); //chamada recursiva que testa as sub-árvores a direita
    }
    return cont; 
}

//b)função que decida se uma árvore é degenerada
int isdegenerada(ArvB* a){
	if (a->dir != NULL && a->esq != NULL) { // se a raiz tiver os dois filhos, então não será degenerada .
        return 0;
        }
        if (a->esq != NULL && a->dir == NULL) { // se a árvore direita for NULL e a esquerda não, pode ser degenerada.
            return isdegenerada(a->esq); // para saber se é degenerada é feito um teste de forma recursiva com a sub-árvore esquerda.
        } else if (a->dir != NULL && a->esq == NULL) { // se a árvore esquerda for NULL e a direta não, a mesma pode ser degenarada.
            return isdegenerada(a->dir); // é chamada de forma recursiva para testar a sub-árvore direita.
        }

        return 1; // caso o código esteja chegado em uma folha e não tivr entrado no primeiro if, então será uma árvore degenerada.
    }

//c) função que, dada uma árvore binária de busca, retorne a quantidade de nós que tenham fator de balanceamento igual a n
int nos_fb_n(ArvB* a, int n){
	int cont = 0; 
	if(a == NULL) // se a árvore for fazia retorna cont =0
		return cont;
	int Fatb = arvb_altura(a->dir) - arvb_altura(a->esq); // recebe a altura dos nós da diretia - a dos nós a esquerda que é o fator de balanceamento.
	if(Fatb == n) // se o fator de balanceamento for igual a n incrementa cont.
		cont++; 
	cont  = cont + nos_fb_n(a->esq, n) + nos_fb_n(a->dir, n); // chamada recursiva para rebeber os fatores de balancemanto das sub-árvores a esquerda e a direita.
	return cont;
}

//d) função que imprima os elementos em comum de duas árvores binárias de busca
void impressao_arv_elem_comuns(ArvB* a, ArvB* b){	
// esta função percorre os nós da árvore a 
if(a != NULL){ // se a arvore a não for nula
        if(compara(a->info,b) == 1) // compara o campo info de a, com o info de b através da função compara
        {
            printf("elemento comum: %d \n",a->info); // se form iguais então é printado na tela o elemento em comum
        }
        impressao_arv_elem_comuns(a->dir,b); // chamada recursiva para testar os elementos comuns a direita da arvore a com o valor de b
        impressao_arv_elem_comuns(a->esq,b); // chamada recursiva para testar os elementos comuns a esquerda da arvore a com o valor de b
	}
}
// e) função que imprima os elementos de uma árvore binária de busca por níveis
void impressao_arv_niveis(ArvB* a){
    int i;
    int cont = arvb_altura(a); // contador recebe a altura da arvore a.
    for (i = 0; i <=cont; i++){ // percorre do nivel 0 até o maior nível da arvore a.
        imprime_nivel(a, i); // função responsavel por imprimir os elementos contidos no nível i.
        printf("- nivel %d\n",i); // printa na tela qual o nivel vigente.
    }
}


// Função para comparar um nó com uma arvore (EXTRA).
int compara(int a, ArvB *b){
// Esta função percorre os nós de b.
    if(b != NULL){ // caso b não seja Nulo
	    if(a == b->info){ // testa o valor de a->info com b->info
            return 1; // retorna 1 caso seja verdadeiro
	    }
	    if(compara(a, b->esq) != 1 && compara(a, b->dir) != 1){ 
		// percorre de forma recursiva tanto os elementos a esquerda como a direta de b, caso não
		// caso não seja verdadeiro em nenhum caso retorna falso (0)
            return 0;
        }
	}
}
// função responsavel por imprimir os elementos de uma arvore dependendo do nivel passado (EXTRA).
void imprime_nivel(ArvB *a, int nivel){
    if (a != NULL && nivel == 0){ // se a não for nulo e nível for = 0 quer dizer que chegou no nivel que queremos atingir
    // EX: nivel = 2; vai entrar no else 2 vezes e chamar de forma recursiva tanto a sub-arvore esquerda quanto a direita e decrementar 1 nível 
    
        printf("%d ", a->info);
    }   
    else if (a != NULL){
    	// chamadas recursivas responsaveis por decrementar o nivel até 0 e percorrer os nós na arvore 
        imprime_nivel(a->esq, nivel - 1); 
        imprime_nivel(a->dir, nivel - 1);
    }
}



