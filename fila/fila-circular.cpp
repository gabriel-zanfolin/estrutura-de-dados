#include <stdio.h>
#include <stdlib.h>
#include "fila-circular.h"

void menu(){
	system("cls");
	printf("Escolha uma das opcoes do menu: \n");
	printf("1. Enfilera (queue)\n");
	printf("2. Retira (dequeue)\n");
	printf("3. Mostra a fila\n");
	printf("9. Fim\n");
	
}
main(){
	int t, opmenu, item;
	//criafila
	Fila *fi=fila_cria(t);
	
	do{
		menu();
		scanf("%d", &opmenu);
		switch(opmenu){
			case 1:
				printf("Informe o item que deseja adicionar: ");
				scanf("%d", &item);
				enfilera(fi,item);
				break;
			case 2:
				if (!fila_vazia(fi))
					printf("elemento retirado = %d\n", retira(fi));
				else
					printf("Fila vazia!\n");
				break;
			case 3:
					mostrafila(fi);
					break;
					
		}//fim switch
		printf("\n");
		system("pause");
	}while(opmenu!=9);
}
