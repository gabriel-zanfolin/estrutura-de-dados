#define N 50
typedef struct {
	int n;//posicao final
	int ini;//posicao inicial
	float vet[N];//valor da fila
}Fila;

Fila *fila_cria(void){
	Fila *f=(Fila*)malloc(sizeof(Fila));
	f->n=0;
	f->ini=0;
	return f;
}
void fila_insere(Fila *f, float v){
	int fim;
	if(f->n==N){ //fila cheia
		printf("Capacidade da fila esgotada.\n");
		return;//retorna ao programa
	}
	//insere novo elemento
	f->vet[f->n]=v;
	f->n++;
}
int fila_vazia(Fila *f){
	return(f->n==f->ini);
}
float fila_retira(Fila *f){
	float v;
	//retira elemento da fila
	v=f->vet[f->ini];
	f->ini++;
	return v;
}
void fila_libera(Fila *f){
	free(f);
}
void mostra_fila(Fila *f){
	if (fila_vazia(f)){
		printf("Fila vazia!\n");
	}
	else {
		printf("Conteudo da fila\n");
		int i;
		for(i=f->ini;i<f->n;i++){
			printf("%0.f\n", f->vet[i]);
		}
		printf("\n");
	}
}
void menu(void){
	system("cls");
	printf("Escolha uma das opcoes do menu: \n");
	printf("1. Enfilera\n");
	printf("2. Retira\n");
	printf("3. Mostra a fila\n");
	printf("4. Conta Elementos\n");
	printf("5. Soma Elementos\n");
	printf("6. Ultimo da fila\n");
	printf("7. Primeiro da fila\n");
	printf("8. Soma pares\n");//PROVA N1 Q10-A
	printf("9. Fim\n");
}
int contaElementos(Fila *f){
	//Eh preciso tirar os elementos da fila para contar e depois eh preciso recolocar
	float v;
	int cont=0;
	Fila *aux=fila_cria();
	//Esvazia a fila original e coloca os elementos na fila auxiliar para contar
	while(!fila_vazia(f)){
		v = fila_retira(f);
		cont++;
		fila_insere(aux,v);
	}
	//Restaura a fila original
	while(!fila_vazia(aux)){
		v = fila_retira(aux);
		fila_insere(f,v);
	}
	fila_libera(aux);
	return cont;
}
float somaElementos(Fila *f){
	//Eh preciso tirar os elementos da fila para somar e depois eh preciso recolocar
	float v;
	int soma=0;
	Fila *aux=fila_cria();
	//Esvazia a fila original e coloca os elementos na fila auxiliar para somar
	while(!fila_vazia(f)){
		soma+=f->vet[f->ini];
		v = fila_retira(f);
		fila_insere(aux,v);
	}
	//Restaura a fila original
	while(!fila_vazia(aux)){
		v = fila_retira(aux);
		fila_insere(f,v);
	}
	fila_libera(aux);
	return soma;
}
//void ultimo(Fila *f){
float ultimo(Fila *f){//professora queria que a funcao retornasse o valor ao inves de fazer printf
	//Eh preciso tirar os elementos da fila e depois recolocar
	float v, ultimo;
	Fila *aux=fila_cria();
	//Esvazia a fila original e coloca os elementos na fila auxiliar
	while(!fila_vazia(f)){
		v = fila_retira(f);
		//ultimo=f->vet[f->ini];
		ultimo=v;
		fila_insere(aux,v);
	}
	//Restaura a fila original
	while(!fila_vazia(aux)){
		v = fila_retira(aux);
		fila_insere(f,v);
	}
	fila_libera(aux);
	//printf("Ultimo da fila = %.0f", ultimo);
	return ultimo;
}
void primeiro(Fila *f){
	//Eh preciso tirar os elementos da fila e depois recolocar
	float v, primeiro;
	Fila *aux=fila_cria();
	primeiro = fila_retira(f);
	fila_insere(aux,primeiro);
	//Esvazia a fila original e coloca os elementos na fila auxiliar
	while(!fila_vazia(f)){
		v = fila_retira(f);
		fila_insere(aux,v);
	}
	//Restaura a fila original
	while(!fila_vazia(aux)){
		v = fila_retira(aux);
		fila_insere(f,v);
	}
	fila_libera(aux);
	printf("Primeiro da fila = %.0f", primeiro);	
}
