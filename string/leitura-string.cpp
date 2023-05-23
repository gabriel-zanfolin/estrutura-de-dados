#include <stdio.h>
#include <stdlib.h>

//faz a leitura de string e compara dois valores numericos
int main (){
	int id1, id2, segue;
	char nome2[21], nome1[21];
	
	do{
		system("cls");
		printf("Digite a primeira idade: ");
		scanf("%d", &id1);
		printf("Digite o primeiro nome: ");
		scanf(" %20[^\n]", nome1);
		fflush(stdin);
		printf("Digite a segunda idade: ");
		scanf("%d", &id2);
		printf("Digite o segundo nome: ");
		scanf(" %20[^\n]", nome2);
		fflush(stdin);
		if (id1==id2){
			printf("\n%s e %s tem a mesma idade, %d anos", nome1, nome2, id1);		
		}
		else{
			if (id1>id2){
				printf("\n%s eh o mais velho(a) com %d anos", nome1, id1);
			}
			else {
				printf("\n%s eh o mais velho(a) com %d anos", nome2, id2);
			}
		}
		printf("\nDigite 1 para continuar: ");
		scanf("%d", &segue);
	}while(segue==1);

	printf("\n***Fim***");
}
