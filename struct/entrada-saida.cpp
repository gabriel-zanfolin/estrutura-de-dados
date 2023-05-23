//tipos estruturados
#include <stdio.h>
#include <stdlib.h>
struct aluno{
	int matricula;
	char nome[31];
	float nota;
	int falta;
};
void mostra(struct aluno x){
	printf("\nDados do aluno:\nMatricula: %d\nNome: %s\nNota: %.1f\nFaltas: %d\n",
			x.matricula, x.nome, x.nota, x.falta);
}
int main(){
	struct aluno a1, a2;
	printf("Digite a matricula do aluno a1: ");
	scanf("%d", &a1.matricula);
	printf("Digite o nome do aluno a1: ");
	fflush(stdin);
	gets(a1.nome);
	printf("Digite a nota do aluno a1: ");
	scanf("%f", &a1.nota);
	printf("Digite as faltas do aluno a1: ");
	scanf("%d", &a1.falta);
	a2=a1;//atribuicao de tipos estruturados
	mostra(a2);//chamada do procedimento mostra
	
}
