/*

Autor: Thales Costa
Disciplina: ED1
Professor: Irineu
Maio/2017

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

typedef struct lista {
	char info;
	struct lista* prox;
	
}Lista;

Lista* inicializa();
Lista* insere(Lista* L, char dado);
Lista* remove(Lista* L, char dado, bool* found);
int busca(Lista* L, char dado);
void mostra(Lista* L);
void libera(Lista* L);
