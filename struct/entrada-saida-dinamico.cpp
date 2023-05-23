//tipos estruturados
#include <stdio.h>
#include <stdlib.h>
struct aluno{
	int matricula;
	char nome[31];
	float nota;
	int falta;
};
/*typedef struct aluno Aluno; --> Antigamente era necessario usar o typedef, porem
								  atualmente eh dispensavel*/

void mostra(aluno x){
	printf("\nMatricula: %d\nNome: %s\nNota: %.1f\nFaltas: %d\n",
			x.matricula, x.nome, x.nota, x.falta);
}
int main(){
	aluno *pa;
	pa=(aluno*)malloc(sizeof(aluno)*3);
	
	int i;
	for(i=0;i<3;i++){
		printf("Digite a matricula do aluno %d: ", i+1);
		scanf("%d", &pa[i].matricula);
		printf("Digite o nome do aluno %d: ", i+1);
		fflush(stdin);
		gets(pa[i].nome);
		printf("Digite a nota do aluno %d: ", i+1);
		scanf("%f", &pa[i].nota);
		printf("Digite as faltas do aluno %d: ", i+1);
		scanf("%d", &pa[i].falta);
		printf("\n");
	}
	system("cls");
	for(i=0; i<3; i++)
		mostra(pa[i]);
}
