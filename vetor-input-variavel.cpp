#include <stdio.h>
#include <stdlib.h>
int main(){
	int i, tam;
	printf("Informe o tamanho do vetor: ");
	scanf("%d", &tam);
	int vet[tam];
	for(i=0;i<tam;i++){
		vet[i]=i+1;
		printf("%d\t", vet[i]);
	}
	printf("\n\n");
	system("pause");
}
