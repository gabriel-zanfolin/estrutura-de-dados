#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
     int num; 
     char nome[10];
     float nota;
     }Aluno;   
int main(){
    FILE *fp;
    Aluno a,b; 
    a.num=100;
    strcpy(a.nome, "Maria");
    a.nota=8.5;
    fp=fopen("saidaBin.bin","a+b"); 
    fwrite(&a, sizeof(Aluno),1,fp); //gravacao em binario
    //fclose(fp);
    //fp=fopen("saidaBin.bin","rb");
    fseek(fp,0,SEEK_SET);
    while(fread(&b, sizeof(Aluno),1,fp));
		printf("\nDados gravados:\nNum: %d, Nome: %s, Nota=%.1f\n\n",
		         b.num,b.nome,b.nota);  
	fclose(fp);
    return 0;
}

