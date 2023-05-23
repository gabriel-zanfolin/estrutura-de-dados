#include<stdio.h>
#include<stdlib.h>

int main () {
	int idade1, idade2, i;
	char nome1[21], nome2[21];
	
	printf("Nome: ");
	fgets(nome1,21,stdin);
	printf("Idade: ");
	scanf(" %d", &idade1);
	printf("==============");
	fflush(stdin);
	printf("\nNome: ");
	fgets(nome2,21,stdin);
	printf("Idade: ");
	scanf(" %d", &idade2);
	printf("==============\n");
	
	if (idade1>idade2){
		printf ("%s tem %d anos e eh o mais velho.\n\n", nome1, idade1);
	}
	else if (idade1<idade2){
		printf ("%s tem %d anos e eh o mais velho.\n\n", nome2, idade2);
	}
	else {
		printf ("Ambos tem a mesma idade.\n\n");
	}
	system("pause");
	return 0;
}
