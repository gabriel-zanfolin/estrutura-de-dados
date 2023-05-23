/*conta o numero de linhas de um arquivo
e mostra quantos caracteres o arquivo tem e quantas letras a
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int c,nlinhas=0;
    int a=0,cont=0;
    FILE *arq;
    arq=fopen("entrada.txt", "rt"); //abre o arquivo
    if (arq==NULL) {
    	printf("Nao foi possivel abrir o arquivo.\n");
    	system("pause");
    	exit(1);//aborta o programa
    }
    while((c=fgetc(arq))!=EOF){
        if(c=='\n') nlinhas++;
        else{
        	if(c=='a'||c=='A') a++;
        	cont++;
		}
    }
    fclose(arq);//fecha o arquivo
    printf("Numero de linhas = %d\n", nlinhas);
    printf("Total de caracteres = %d\n", cont);
    printf("Letras 'a' = %d\n", a);
    /* exibe o resultado na tela */
    system("pause"); 
	return 0;
}
