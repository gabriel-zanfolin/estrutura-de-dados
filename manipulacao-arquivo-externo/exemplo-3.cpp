/*mostra linhas de arquivo de texto*/
#include <stdio.h>
#include <stdlib.h>

int main () {
    char c[81];
    FILE *arq;
    arq=fopen("entrada.txt", "rt"); //abre o arquivo
   if (arq==NULL) {
      printf("Nao foi possivel abrir o arquivo.\n");
      system("pause");
      exit(1);//aborta o programa indicando excecao(erro)
   }
   while(fgets(c, 80, arq)!= NULL) {
        printf("%s",c); // ou puts(c);
  }
  system("pause");
  fclose(arq); //fecha o arquivo
}
