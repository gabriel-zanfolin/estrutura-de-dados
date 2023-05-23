#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
//lista simplesmente encadeada
main(){
	int opmenu, item;
	Lista *li=lista_cria();
	Lista *aux;
	do{
		menu();   
		scanf("%d",&opmenu);
		switch(opmenu){
		case 1: 
			printf("Informe o item que deseja adicionar: ");
			scanf("%d",&item);
			//li=lista_ordenada(li,item);
			li=lista_insere(li,item);
			break;
		case 2:  
			printf("Informe o item que deseja retirar: ");
			scanf("%d",&item);
			li=lista_retira(li,item); 
			break;
		case 3:
			if(lista_vazia(li))
				printf("Lista vazia\n");
			else {
				printf("Lista: ");
				lista_mostra(li);
			}
			break;
		case 4:  
			printf("Informe o item que deseja procurar: ");
			scanf("%d",&item);
			//ponteiro auxiliar para nao perder a referencia
			//da lista
			aux=lista_busca(li,item); 
			if(aux==NULL)
				printf("Item %d nao localizado na lista\n",item);
			else
				printf("Item %d localizado\n",aux->info);
			break;
		case 5: //conta elementos
			printf("Numero de elementos: %d\n", contaElementos(li));
			break;
		case 6: //soma elementos
			printf("Soma de elementos: %d\n", somaElementos(li));
			break;
		case 7: //mostra o ultimo
			ultimo(li);
			break;
		case 8: //duplica a lista
			duplicaLista(li);
			lista_mostra(li);
			break;
		}//fim switch
		printf("\n");
		system("pause");
	}while(opmenu!=9);
	lista_libera(li);
}





