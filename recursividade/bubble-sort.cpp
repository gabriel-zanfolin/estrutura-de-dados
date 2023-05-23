#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bolha_rec (int *vet, int tam){
	if (tam==1) return;
    int aux;
	for (int i=0; i<tam-1; i++){
		if (vet[i]>vet[i+1]){
        	aux=vet[i];
            vet[i]=vet[i+1];
            vet[i+1]=aux;	
		}
	}
    bolha_rec(vet,tam-1);
}
int main(){
	srand(time(NULL));
	int tam=12, i;
	int v[tam];
	for(i=0;i<tam;i++){
		v[i]=rand()%100 +1;
		printf("%d\t",v[i]);
	}
	bolha_rec(v,tam);
	printf("\nDepois da funcao:\n");
	for(i=0;i<tam;i++){
		printf("%d\t",v[i]);
	}
	printf("\n");
}

