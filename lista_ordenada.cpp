/*

Autor: Thales Costa
Disciplina: ED1
Professor: Irineu
Maio/2017

*/

#include "lista_ordenada.h"

Lista* inicializa(){
	
	return NULL;
}

Lista* insere(Lista* L, char dado){		//Insere determinado elemento na lista ordenadamente, utilizando de recursividade.

	if (L == NULL){
	    Lista* novo = (Lista*)malloc(sizeof(Lista));
	    
	    novo->info = dado;
	    novo->prox = L;
	    
		return novo;
	}else{
		if (dado > L->info){
			L->prox = insere (L->prox, dado);
	    	return L;
		}else{
			Lista* novo = (Lista*)malloc(sizeof(Lista));
			
	    	novo->info = dado;
			novo->prox = L;
			
			return novo;
		}
	}
}

Lista* remove(Lista* L, char dado, bool* found){		//Retira determinado elemento da lista de forma recursiva.
	
	if(L == NULL){
		return NULL;
	}
	
	if(dado == L->info){
		Lista* P = L;
		L = L->prox;
		
		free(P);
		
		*found = true;
	}else{
		L->prox = remove(L->prox, dado, found);
	}
	return L;	
}

int busca(Lista* L, char dado){		//Retorna a posição do elemento, caso este seja encontrado na lista.
	int position = 0;
	
	for(Lista* P = L; P != NULL; P = P->prox){
		position++;
		
		if(P->info == dado){
			
			return position;
		}
	}
	
	return -1;
}

void mostra(Lista* L){		//Mostra os elementos da lista de forma recursiva.
	
	if(L != NULL){
		putchar(L->info);
		printf("\t");
		mostra(L->prox);
	}else{
		printf("\n\n");

	}
}

void libera(Lista* L){		//Libera, de forma recursiva, a memória alocada, caso tenha alguma.
	
	if(L != NULL){
		libera(L->prox);
		free(L);
	}
	
}



