#include <stdio.h>
#include <stdlib.h>
/*Este programa le 3 notas de um aluno, valida se as notas vao de 0 a 10, impedindo de
prosseguir caso contrario.
Chamar uma funcao que recebe as 3 notas e retorna a media aritmetica delas.
O programa principal recebe e mostra a media calculada e chama um procedimento que
recebe a media obtida como parametro e vai informar se o aluno esta ou nao aprovado.
(Criterio fatec)
Prever repeticao*/

//funcao valida nota
bool validacao (double nota);

//funcao media
double calc_media (double nota1, double nota2, double nota3);

//funcao resultado
void resultado (double media);

//funcao principal
int main() {
	double nota1, nota2, nota3, media;
	char repet='s';
	bool valida;
	
	do {
		//entrada
		valida = false;
		do{
			printf("Informe a nota 1: ");
			scanf("%lf", &nota1);
			valida = validacao(nota1);
		} while (!valida);
		do{
			printf("Informe a nota 2: ");
			scanf("%lf", &nota2);
			valida = validacao(nota2);
		} while (!valida);
		do{
			printf("Informe a nota 3: ");
			scanf("%lf", &nota3);
			valida = validacao(nota3);
		} while (!valida);
		
		//processamento
		media = calc_media(nota1,nota2,nota3);
		
		//saida
		printf("\nMedia = %.2lf\n", media);
		resultado(media);
		printf("Deseja calcular nova media(S/N)? ");
		scanf(" %c", &repet);
		while (repet!='s' && repet!='n' && repet!='S' && repet!='N') {
			printf("Opcao invalida! Redigite: ");
			scanf(" %c", &repet);		
		}
		printf("\n\n");
	} while (repet=='s' || repet=='S');
	system("pause");
	return 0;
}

//funcao valida nota
bool validacao (double nota){
	bool valida = true;
	if (nota<0 || nota>10){
		valida = false;
	}
	return valida;
}

//funcao media
double calc_media (double nota1, double nota2, double nota3){
	double media;
	media = (nota1+nota2+nota3)/3;
	return media;
}

//funcao resultado
void resultado (double media){
	printf("====================\n");
	if (media>=6.0){
		printf("Aluno Aprovado!\n");
	}
	else{
		printf("Aluno Reprovado!\n");
	}
	printf("====================\n\n");
}

