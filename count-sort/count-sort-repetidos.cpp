#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void ordenaRepetidos(int origem[],int dest[],int tam){
	int i,j,p;
	//determinar a posicao de cada elemento do vetor 
	//quando ordenado 
	for(i=0;i<tam;i++){
		p=0;
		for(j=0;j<tam;j++)
			if (origem[i]>=origem[j]) p++;
		dest[p]=origem[i];
	} 
}
int main(){
	srand(time(NULL));
	int tam=12, i;
	int v[tam], ord[tam];
	for(i=0;i<tam;i++){
		v[i]=rand()%5 +1;
		printf("%d\t",v[i]);
	}
	ordenaRepetidos(v,ord,tam);/*ALGORITMO DE ORDENA��O*/
	printf("\nDepois da funcao:\n");
	for(i=0;i<tam;i++){
		printf("%d\t",ord[i]);
	}
	printf("\n");
}

