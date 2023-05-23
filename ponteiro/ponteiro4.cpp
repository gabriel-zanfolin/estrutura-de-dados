#include <stdio.h>
#include <stdlib.h>

void calcula (int a, int b, int *s, int *p){
	*s = a+b;
	*p = a*b;
}
int main(){
	int x=3, y=4;
	int soma, prod;
	calcula(x, y, &soma, &prod);
	printf("soma=%d produto=%d\n", soma, prod);
	return 0;
}
