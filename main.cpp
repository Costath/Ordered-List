/*

Autor: Thales Costa
Disciplina: ED1
Professor: Irineu
Maio/2017

*/

#include "lista_ordenada.h"

int main() {
setlocale(LC_ALL, "");
	
	system("title Lista ordenada");
	
	int funcao;
	char elemento;
	bool found;
	Lista* L;
	L = inicializa();
	
	menu:
	
	printf("==Lista ordenada==\n\n");
	printf("Selecione a função desejada:\n");
	printf("1 - Inserir elemento\n");
	printf("2 - Remover elemento\n");
	printf("3 - Buscar elemento\n");
	printf("4 - Mostrar todos\n");
	printf("0 - Sair\n\n");
	
	scanf("%d", &funcao);
	
	switch(funcao){			//Direciona para a função requisitada no menu acima.
		case(1):		//Insere na lista o elemento informado.
			printf("\nInforme a letra a ser inserida: ");
			getchar();
			scanf("%c", &elemento);
			
			L = insere(L, elemento);
			
			system("cls");
		break;
		case(2):		//Retira determinado elemento da lista.
			if(L != NULL){
				
				printf("\n\nInforme a letra a ser retirada: ");
				getchar();
				scanf("%c", &elemento);
				
				found = false;
				L = remove(L, elemento, &found);
				
				if(found){
					printf("\nA letra foi removida com sucesso.\n");
				}else{
					printf("\nA letra não foi encontrada na lista.\n");
				}
				
				system("pause");
				system("cls");
			}else{
				
				printf("\nA lista está vazia.\n");
				system("pause");
				system("cls");
			}
			
		break;
		case(3):		//Informa se determinado elemento está na lista.
			if(L != NULL){
				printf("\nInforme a letra a ser buscada: ");
				getchar();
				scanf("%c", &elemento);
				
				int position = busca(L, elemento);
				
				if(position != -1){
					
					printf("\nA letra está presente na posição %d.\n", position);
				}else{
					
					printf("\nA letra não está presente na lista.\n");
				}
			}else{
				
				printf("\nA lista está vazia. Não é possível realizar buscas.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(4):		//Mostra os elementos da lista.
			if(L != NULL){
				
				printf("\nLista:\n\n");
				
				mostra(L);
			}else{
				
				printf("\nA lista está vazia.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(0):		//Libera a memória alocada, caso tenha alguma, e encerra o programa.
			libera(L);
				
			printf("\nObrigado!\n");
			
			return 0;
		break;
		default:
			printf("Opção não existente.\n\n");
			
			system("pause");
			system("cls");
	}
	
	goto menu;		//Mantém no menu enquanto não for selecionada a opção "sair".
	
}
