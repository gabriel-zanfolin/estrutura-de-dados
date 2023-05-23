#include <stdio.h>
#include <stdlib.h>
//uso do fseek

int main(){
    FILE *fp;
    int num[20];
    int vet[5];
    //preenche o vetor num com os proprios indices
    for(int i=0;i<20;i++)
       num[i]=i;
       
    fp=fopen("vetBin.bin","ab");
    fwrite(num, sizeof(int),20,fp); //gravacao em binario (gera novo arquivo)
    fclose(fp);
    fp=fopen("vetBin.bin","rb");
    //posiciona no fim do arquivo e volta 5 inteiros
    //fseek(fp,-10*sizeof(int),SEEK_END); //SEEK_CUR ou SEEK_SET
    //rewind(fp);// equivale a fseek(fp,0,SEEK_SET);
    printf("\nVetor resultante\n\n");
    while(fread(vet, sizeof(int),5,fp)){//leitura de binario 
	  	for(int i=0; i<5;i++)
	        printf("%d\t",vet[i]);
	    printf("\n"); }	
    fclose(fp);
    return 0;
}

