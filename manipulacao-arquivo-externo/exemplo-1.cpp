/*conta o numero de linhas de um arquivo*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int c,nlinhas=0;
    FILE *arq;
    arq=fopen("entradas.txt", "rt"); //abre o arquivo
    if (arq==NULL) {
    	printf("Nao foi possivel abrir o arquivo.\n");
    	system("pause");
    	exit(1);//aborta o programa
    }
    while((c=fgetc(arq))!=EOF){
        if(c=='\n') nlinhas++;
    }
    fclose(arq);//fecha o arquivo
    printf("Numero de linhas = %d\n", nlinhas);
    /* exibe o resultado na tela */
    system("pause"); 
	return 0;
}
