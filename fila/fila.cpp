#include <stdio.h>
#include <stdlib.h>
#include "fila.h"//arquivo de header feito pelo usuario
//#include "fila-inteligente.h"//arquivo de header feito pelo usuario
main(){
	Fila *fi = fila_cria();
	/*
	se eu quisesse declarar o ponteiro fila para depois cria-lo, a escrita eh diferente:
	Fila *fi;
	fi = fila_cria();// Sem o "*"
	*/
	int opmenu;
	float item;
	do{
		menu();
		scanf("%d", &opmenu);
		switch (opmenu){
			case 1: //insere
				printf("Digite o valor a ser enfileirado: ");
				scanf("%f", &item);
				fila_insere(fi,item); break; //porque precisa desses breaks??
			case 2: //retira
				if (fila_vazia(fi)){
					printf("Fila ja esta vazia!\n");
				}
				else {
					printf("Elemento retirado = %.0f\n", fila_retira(fi));
				}
				break;
			case 3: //mostra a fila
				mostra_fila(fi);
				break;
			case 4: //conta elementos
				printf("Qtde de elementos = %d\n", contaElementos(fi));
				break;
			case 5: //soma elementos
				printf("Soma dos elementos = %.0f\n", somaElementos(fi));
				break;				
			case 6: //ultimo
				if (fila_vazia(fi)){
					printf("Fila vazia, nao tem ultimo!\n");
				}
				else {
					//ultimo(fi);
					printf("Ultimo da fila = %.0f", ultimo(fi));
				}
				break;
			case 7: //primeiro
				if (fila_vazia(fi)){
					printf("Fila vazia, nao tem primeiro!\n");
				}
				else {
					primeiro(fi);
				}
				break;
			case 8: //SomaPares
				printf("Soma dos pares = %.0f\n", somaPares(fi));
				break;
		}
		printf("\n");
		system("pause");
	}while(opmenu!=9);
}
