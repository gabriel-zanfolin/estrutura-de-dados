/*conta o numero de linhas de um arquivo*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    char c;
    int nl=0;
    FILE *arq;
    arq=fopen("entrada.txt", "rt"); //abre o arquivo
    if (arq==NULL) {
    	printf("Nao foi possivel abrir o arquivo.\n");
    	system("pause");
    	exit(1);
    }
    while(fscanf(arq, "%c",&c)==1) {
        if(c=='\n') nl++;
    }
    fclose(arq); //fecha o arquivo
    printf("Numero de linhas = %d\n", nl); /* exibe o resultado na tela */
    system("pause");
	return 0;
}
