#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Le diversas palavras simples ate que a palavra "fim" seja digitada.
Para cada palavra lida informe: 1- o tamanho da palavra, 2- o inverso da palavra*/

int tam (char p[]){//funcao do tipo inteiro que retorna o tamanho da palavra
	int i, n=0;
	for (i=0; p[i]!='\0'; i++){
		n++;
	}
	return n;
}
void inverte(char *p){//recebe uma palavra e mostra invertida
	int i, j;
	for (i=0; p[i]!='\0'; i++);//procura o indice onde esta o '\0'
	for (j=i-1;j>=0;j--)
		printf("%c", p[j]);
	printf("\n");
}
//---------------------------------------------------------------------
int main(){
	char palavra[21];
	do{
		system("cls");
		printf("Informe a palavra: ");
		scanf(" %s", palavra);
		if(strcmp(palavra,"fim")!=0){
			//a funcao tam esta sendo chamada diretamente no printf
			printf("Tamanho da palavra:%d\n", tam(palavra));
			//o procedimento inverte- mostra a palavra ao contrario
			inverte(palavra);
			system("pause");
		}
	} while(strcmp(palavra,"fim")!=0);
}
