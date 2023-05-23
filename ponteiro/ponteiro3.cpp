#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
int main(){
	int x=3, y=5;
	troca(&x, &y);
	printf("x=%d y=%d\n", x, y);
	return 0;
}
