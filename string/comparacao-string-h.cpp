#include <stdio.h>
#include <string.h>
//mostra o uso da biblioteca string.h
int main (){
	char s1[21]="Fatec", s2[21]="ABC";
	printf("%s %s\n", s1, s2);
	if(strcmp(s1,s2)>0){
		printf("Maior string: %s\n", s1);
	}
	else{
		printf("Maior string: %s\n", s2);
	}
	//comparacao entre a primeira letra de cada string
	if(s1[0]>s2[0]){
		printf("\n%c nao eh maior que %c\n", s1[0], s2[0]);
	}
	else if(s1[0]<s2[0]){
		printf("\n%c eh maior que %c\n", s1[0], s2[0]);
	}
	strcpy(s1, "Linguagem");
	strcpy(s2, "C");
	printf("%s - %s\n", s1, s2);
	printf("\n***Fim***");
}
