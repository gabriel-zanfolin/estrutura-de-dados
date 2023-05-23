#include <stdio.h>
int buscavetor(int *vet,int tam,int valor){
	if (tam==0) return -1;
	if (vet[tam-1]==valor) return tam-1;
	return busca(vet,tam-1,valor);
}

int main(){
	int v[12]={2,4,6,9,1,7,5,10,8,0,11,3};
	int r,valor,tam =12;
	valor=10;
	r=buscavetor(v, tam, valor);
	if (r==-1)
	   printf("%d Nao encontrado\n",valor);
	else
	   printf("%d encontrado no indice %d\n", valor, r);
}
