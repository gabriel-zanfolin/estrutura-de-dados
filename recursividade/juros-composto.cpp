#include <stdio.h>
#include <stdlib.h>
double juroscompostos(double valor, double taxa, int meses){
	valor+=valor*taxa;
	if (meses==1) return valor;
	return juroscompostos(valor,taxa,meses-1);
}
int main(){
	double valor=1000.0, taxa=0.1, jurosC;
	int meses=7;
	jurosC=juroscompostos(valor,taxa,meses);
	printf("%.2lf\n",jurosC);
	system ("pause");
}
