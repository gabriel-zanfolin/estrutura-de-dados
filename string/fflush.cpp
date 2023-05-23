#include <stdio.h>
#include <stdlib.h>
int main (){
	char letra;//Um caractere soh
	int num;
	printf("Digite um numero: ");
	scanf("%d", &num);
	fflush(stdin);
	printf("Digite um caractere: ");
	scanf("%c", &letra);
	//scanf(" %c", &letra); //se eu usar dessa maneira com esse espaco antes do "%c" dispensa o uso do fflush
	printf("num=%d e letra= %c\n\n", num, letra);
	//system ("pause");
}
