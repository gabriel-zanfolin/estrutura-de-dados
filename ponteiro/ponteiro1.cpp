#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, *pm;
	pm=&m;//pm recebe o endereco de m
	*pm=3;//o conteudo enderecado por pm recebera o valor 3
	printf("%d", m);
	return 0;
}
