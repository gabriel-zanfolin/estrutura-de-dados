#include <stdio.h>
#include <stdlib.h>
//lista duplamente encadeada
typedef struct lista2 {
	int info;
	lista2* ant;
	lista2* prox;
}Lista2;

Lista2 * fimlista;

Lista2* lista_cria(){
	return NULL;
}

int lista_vazia(Lista2* l){
	if(l==NULL) return 1;
    return 0;
}

Lista2* lista_busca(Lista2* l, int dado){     
	Lista2 *a; //variavel usada para percorrer a lista
	for(a=l;a!=NULL;a=a->prox)
	{ 
		if(a->info == dado) return a;
	}         
	return NULL;
}

Lista2* lista_insere( Lista2* l, int dado){//Insere elemento no inicio da lista
	Lista2 *novo= (Lista2*) malloc (sizeof(Lista2));
	novo->info=dado;
	novo->prox=l;
	novo->ant=NULL;
	//verifica se a lista nao esta vazia
	if(l!= NULL)
		l->ant=novo;
    
	return novo;
}

void lista_mostra(Lista2* l){
	Lista2 *aux;//variavel usada para percorrer a lista
	for(aux=l;aux!=NULL;aux=aux->prox)
		printf("%d\t", aux->info);
	printf("\n");
}        

void lista_reverso(Lista2 *ls){
	Lista2 *a=ls;
	while(a->prox!=NULL)//percorrendo a lista ate encontrar o 
	//ultimo
	   a=a->prox;
	while (a!=NULL){
		printf("%d\t", a->info);
		a=a->ant;
	}
}       

void ultimo_lista(Lista2 *ls){
	Lista2 *a=ls;
	while(a->prox!=NULL)//percorrendo a lista ate encontrar o 
	//ultimo
	   a=a->prox;
	printf("Ultimo da lista: %d\n", a->info);
}  

void primeiro_lista(Lista2 *ls){
	Lista2 *a=ls;
	while(a->ant!=NULL)//percorrendo a lista ate encontrar o 
	//primeiro
	   a=a->ant;
	printf("Primeiro da lista: %d\n", a->info);
}

Lista2* lista_retira(Lista2* l, int dado){
	//procura o elemento na lista usando a funcao busca
	Lista2* aux=lista_busca(l, dado);
	if (aux==NULL) //n�o achou o elemento
		return l; 
	//retira o elemento encadeado
	if(l==aux) //verifica se eh o primeiro da lista
		l=aux->prox;
	else
		aux->ant->prox=aux->prox;
	//testa para ver se eh o ultimo da lista
	if (aux->prox!=NULL)        
		aux->prox->ant=aux->ant;
	free(aux);
	return l;
}

Lista2* lista_ordenada(Lista2* l, int v){//Insere elemento de forma ordenada
	Lista2* novo;
	Lista2* anterior=NULL;
	Lista2* p=l;
    
	//cria novo elemento
	novo=(Lista2*)malloc(sizeof(Lista2));
	novo->info=v;
        
    //procura posicao de insercao
	while (p!=NULL && p->info < v)
	{
		anterior=p;
		p=p->prox;
	}     
	//encadeia o elemento
	if(anterior==NULL) //insere no inicio
	{
		if(l!=NULL) l->ant=novo;
		novo->prox=l;
		novo->ant=NULL;
		l=novo;
	}      
	else //insere no meio ou no fim da lista
	{
		novo->prox=anterior->prox;
		novo->ant=anterior;
		if (anterior->prox!=NULL)
			anterior->prox->ant=novo;
		anterior->prox=novo;
	}
	fimlista=novo;
	return l;
}        

Lista2 *listaPares(Lista2 *l){
	Lista2 *aux;//variavel usada para percorrer a lista
	Lista2 *par= lista_cria();
	for(aux=l;aux!=NULL;aux=aux->prox)
		if(aux->info%2==0)
			par=lista_ordenada(par,aux->info);
	return par;
}

void lista_libera(Lista2 *li){//Libera cada item da lista individualmente
	Lista2 *p,*t;//ponteiros auxiliares
	p=li;
	while(p!=NULL){
		t=p->prox;
		free(p);
		p=t;
	}                           
}
//programa principal
void menu(){
	system("cls");
	printf("Escolha uma das opcoes do menu: \n");
	printf("------------------------------\n");
	printf("1. Insere na lista\n");       
	printf("2. Retira da lista\n");
	printf("3. Mostra a lista\n");
	printf("4. Busca item na lista\n");
	printf("5. Mostra a lista em ordem reversa\n");
	printf("6. Mostra o ultimo da lista\n");
	printf("7. Busca um elemento qualquer e a partir dele mostra o 1. e o ultimo da fila\n");
	printf("8. Gera uma lista de pares\n"); //Lista2 *listaPares(Lista2 *ls);
	printf("9. Fim\n");
	printf("==> ");
}
             
main(){
	int opmenu, item;
	Lista2 *li=lista_cria();
	Lista2 *aux;
	do{
		menu();   
		scanf("%d",&opmenu);
		switch(opmenu){
			case 1: 
				printf("Informe o item que deseja adicionar: ");
				scanf("%d",&item);
				li=lista_ordenada(li,item);
				//li=lista_insere(li,item);
				break;
			case 2:  
				printf("Informe o item que deseja retirar: ");
				scanf("%d",&item);
				li=lista_retira(li,item); 
				break;
			case 3:
				if(lista_vazia(li))
					printf("Lista vazia\n");
				else {
					printf("Lista: ");
					lista_mostra(li);
				}
				break;
			case 4:  
				printf("Informe o item que deseja procurar: ");
				scanf("%d",&item);
				//ponteiro auxiliar para nao perder a referencia
				//da lista
				aux=lista_busca(li,item); 
				if(aux==NULL)
					printf("Item %d nao localizado na lista\n",item);
				else
					printf("Item %d localizado\n",aux->info);
				break;
			case 5:
				if(lista_vazia(li))
					printf("Lista vazia\n");
				else {
					printf("Lista: ");
					lista_reverso(li);
				}
				break;
			case 6:
				if(lista_vazia(li))
					printf("Lista vazia\n");
				else {
					ultimo_lista(li);
				}
				break;
			case 7:  
				printf("Informe o item que deseja procurar: ");
				scanf("%d",&item);
				//ponteiro auxiliar para nao perder a referencia
				//da lista
				aux=lista_busca(li,item); 
				if(aux==NULL)
					printf("Item %d nao localizado na lista\n",item);
				else
					primeiro_lista(li);
					ultimo_lista(li);
				break;	
			case 8:
				if(lista_vazia(li))
					printf("Lista vazia\n");
				else {
					printf("Lista de pares: ");
					lista_mostra(listaPares(li));
				}
				break;
		}//fim switch
		printf("\n");
		system("pause");
	}while(opmenu!=9);
	lista_libera(li);
}
