#include <stdio.h>
#include <stdlib.h>

main (){
	char frase[] = "ABRACADABRA";
	char *p;
	int i, n=0;
	//percurso usando o ponteiro para string (p)
	for (p=frase; *p!='\0'; p++){
		if (*p=='A')n++;
	}
	printf("Letras A = %d\n", n);
	//percurso usando o vetor frase
	for (i=0, n=0; frase[i]!='\0'; i++){
		if (frase[i]!='A')n++;
	}
	printf("Consoantes = %d\n", n);
}
