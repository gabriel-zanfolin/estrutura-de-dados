#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char frase[]="Estrutura de Dados";
    char pula='\n';
    fp=fopen("saida3.txt","wt");
    if (fp==NULL){
    	printf("Erro!");
    	return 1;
	}
    fputs(frase,fp);
    fputc(pula,fp);
    fputs(frase,fp);
    fputc(pula,fp);
    fclose(fp);
    return 0;
}
