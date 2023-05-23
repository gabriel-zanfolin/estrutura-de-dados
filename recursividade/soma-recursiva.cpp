#include <stdio.h>
#include <stdlib.h>
int soma (int a, int b) {
	if (a==b) return a;
	return b+soma(a, b-1);
}
/*
// Versao alternativa
int soma(int a, int b){
	if(a>b) return 0;
	return a + soma(a+1,b);
}
*/
int main(){
	int x=1,y=5,s;
	s=soma(x,y);
	printf("%d\n",s);
	system ("pause");
}
