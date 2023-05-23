#include <stdio.h>
#include <stdlib.h>

struct produto{
	char nome[31];
	float preco;
	int qtd;
};

float calc_tt(float preco,int qtd){
	float total;
	total = preco * (float)qtd;
	return total;
}
void mostra(char produto[], float total){
	printf("%s\nValor Total: R$%.2f\n\n", produto, total);
}

int main(){
	produto prod[3];
	int i;
	float total[3];
	
	for (i=0;i<3;i++){
		printf("Digite o nome do produto: ");
		fflush(stdin);
		gets(prod[i].nome);
		printf("Digite o preco do produto: ");
		scanf("%f", &prod[i].preco);
		printf("Digite a quantidade: ");
		scanf("%d", &prod[i].qtd);
		printf("\n");
		total[i] = calc_tt(prod[i].preco,prod[i].qtd);
	}
	system("cls");
	for (i=0;i<3;i++){
		mostra(prod[i].nome, total[i]);
	}
}
