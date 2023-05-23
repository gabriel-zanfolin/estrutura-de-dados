//tipos estruturados
//uso de ponteiro variavel
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

void mostra(aluno *x){
	printf("\nMatricula: %d\nNome: %s\nNota: %.1f\nFaltas: %d\n",
			x->matricula, x->nome, x->nota, x->falta);
			//(*x).matricula,(*x).nome,(*x).nota,(*x).falta)
			//a forma descrita acima tambem serve, e a equivalente eh utilizada
}
int main(){
	aluno *pa, *pb;
	pa=(aluno*)malloc(sizeof(aluno)*3);
	pb=pa;//guardar o endereco inicial
	int i;
	for(i=0;i<3;i++,pa++){
		printf("Digite a matricula do aluno %d: ", i+1);
		scanf("%d", &pa->matricula);
		printf("Digite o nome do aluno %d: ", i+1);
		fflush(stdin);
		gets(pa->nome);
		printf("Digite a nota do aluno %d: ", i+1);
		scanf("%f", &pa->nota);
		printf("Digite as faltas do aluno %d: ", i+1);
		scanf("%d", &pa->falta);
		printf("\n");
	}
	system("cls");
	pa=pb;//restaura o ponteiro para o endereco inicial
	for(i=0; i<3; i++){
		mostra(pa);
		pa++;
	}
}
