typedef struct lista {
	int info;
	struct lista* prox;
}Lista;

Lista* lista_cria() {
	return NULL;
}
int lista_vazia(Lista* l){
	return(l==NULL);
}

Lista* lista_busca(Lista* l, int dado) {     
	Lista *a; //variavel usada para percorrer a lista
	for(a=l;a!=NULL;a=a->prox) { 
		if(a->info == dado) return a;
	}
	return NULL;
}

Lista* lista_insere( Lista* l, int dado) {//insere no inicio
	Lista *novo= (Lista*) malloc (sizeof(Lista));
	novo->info=dado;
	novo->prox=l;
	return novo;
}

void lista_mostra(Lista* l) {
	Lista *aux;//variavel usada para percorrer a lista
	for(aux=l;aux!=NULL;aux=aux->prox)
		printf("%d\t", aux->info);
	printf("\n");
}         
  
Lista* lista_retira(Lista* l, int dado){
	Lista* ant=NULL; //ponteiro para o anterior
	Lista *aux=l;// ponteiro para percorrer a lista  
	//procura o elemento na lista guardando seu anterior
	while(aux!=NULL && aux->info!=dado) {
		ant=aux;
		aux=aux->prox;
	}
	//verifica se achou o elemento
	if(aux==NULL) {
		printf("\nNAO localizado\n");         
		return l; //n�o achou - retorna a lista
	}
	//retira o elemento
	if (ant==NULL) //primeiro da lista
		l=aux->prox;
	else
		//retira do meio da lista
		ant->prox=aux->prox;
	free(aux);
	return l;
}

//Opcionalmente pode-se inserir na lista de forma ordenada
Lista* lista_ordenada(Lista* l, int v) {
	Lista* novo;
	Lista* ant=NULL;
	Lista* p=l;
	//cria novo elemento
	novo=(Lista*)malloc(sizeof(Lista));
	novo->info=v;
	//procura posicao de insercao
	while (p!=NULL && p->info < v)  {
		ant=p;
		p=p->prox;
	}     
	//encadeia o elemento
	if(ant==NULL) { //insere no inicio
		novo->prox=l;
		l=novo;
	}
	else //insere no meio ou no fim da lista
	{
		novo->prox=ant->prox;
		ant->prox=novo;
	}
	return l;
}        
void lista_libera(Lista *l){
	Lista *p,*t;
	p=l;
	while(p!=NULL){
		t=p->prox;
		free(p);
		p=t;
	}                           
}
int contaElementos(Lista *ls){//numero de elementos da lista
	int conta=0;
	//percorre a lista para contar
	Lista *aux;
	for(aux=ls;aux!=NULL;aux=aux->prox){
		conta++;
	}
	return conta;
}
int somaElementos(Lista *ls){//somar os elementos da lista
	int soma=0;
	Lista *aux=ls;
	while (aux!=NULL){
		soma+=aux->info;//soma=soma+aux->info;
		aux=aux->prox;
	}
	return soma;
}
void ultimo(Lista *ls){
	//o ultimo elemento da lista eh que tem prox=NULL
	Lista *aux;
	for(aux=ls;aux->prox!=NULL;aux=aux->prox);//s� percorre procurando o ultimo
		printf("Ultimo da lista: %d\n", aux->info);
}
void duplicaLista(Lista *ls){
	Lista *aux=lista_cria();//vai conter uma copia da lista original
	//percorre a lista original copiando os elementos para a lista aux
	for(Lista *a=ls;a!=NULL;a=a->prox){
		aux=lista_ordenada(aux,a->info);
	}
	//acrescentar na lista original os elementos copiados para a lista aux
	for(Lista *a=aux;aux!=NULL;aux=aux->prox){
		ls=lista_ordenada(ls,aux->info);
	}
}

void menu(){
	system("cls");
	printf("Escolha uma das opcoes do menu: \n");
	printf("------------------------------\n");
	printf("1. Insere na lista\n");       
	printf("2. Retira da lista\n");
	printf("3. Mostra a lista\n");
	printf("4. Busca item na lista\n");
	printf("5. Conta Elementos\n");//int contaElementos(Lista *ls)
	printf("6. Soma Elementos\n");//int somaElementos(Lista *ls)
	printf("7. Mostra o ultimo da lista\n");//(elemento cujo prox eh null) //void mostraUltimo(Lista *li)
	printf("8. Duplica lista\n");//void duplicaLista(Lista *Ls)
	printf("9. Fim\n");
	printf("==> ");
}