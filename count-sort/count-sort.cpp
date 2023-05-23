#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ordena_por_contagem(int vet[], int ord[], int n){
	int i,j,p;
	//determinar a posicao de cada elemento do vetor 
	//quando ordenado 
	for(i=0;i<n;i++){
		p=0;
		for(j=0;j<n;j++)
			if (vet[i]>vet[j]) p++;
		ord[p]=vet[i];
	} 
}
int main(){
	srand(time(NULL));
	int tam=5, i;
	int v[tam], ord[tam];
	for(i=0;i<tam;i++){
		v[i]=rand()%100 +1;
		printf("%d\t",v[i]);
	}
	ordena_por_contagem(v,ord,tam);/*ALGORITMO DE ORDENACAO*/
	printf("\nDepois da funcao:\n");
	for(i=0;i<tam;i++){
		printf("%d\t",ord[i]);
	}
	printf("\n");
}

