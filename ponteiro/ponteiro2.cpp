#include <stdio.h>
#include <stdlib.h>

int main()
{
	float x, y, *z;
	x = 2.0;
	*z = 5.0;
	y = x + (*z);
	printf("%.0f", y);
	return 0;
}
/*
Este programa nao da resultado, isso porque esta sendo atribuido um valor para
o ponteiro sem antes ter sido atribuido um endereco para tal, portanto isso eh
apenas um exemplo do tipo de situacao que pode ocasionar falhas no processamento
do programa.
*/
