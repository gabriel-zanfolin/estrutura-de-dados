#include <stdio.h>
#include <stdlib.h>

#include <string.h>
//strlwr - converte a string para minusculo
//strupr - converte a string para maiusculo

/*Uma lista duplamente encadeada guarda informacoes de nome e data de 
nascimento de diversas pessoas. Nesta lista os nomes sao unicos, mas ela nao
foi criada de forma ordenada por nomes. Escreva uma funcao recursiva que faca
a procura sequencial de um nome nessa lista.  Sao passados como parametros 
para esta funcao um ponteiro para o elemento final da lista, e um nome (n).
A funcao deve informar a data de nascimento correspondente ao nome encontrado,
ou informar n�o encontrado, se toda lista for percorrida sem sucesso.*/
typedef struct lista {
       char nome[21];
       char nasc[11];
	   struct lista *ant;
       struct lista* prox;
}Lista;

Lista* lista_cria(){
    return NULL;
}

int lista_vazia(Lista* l){
    /*if(l==NULL) return 1;
    return 0;*/
    return(l==NULL);//retorna o resultado da comparacao do ponteiro l com NULL
}

//insere novos elementos no inicio da lista
Lista* lista_insere( Lista* l, char *n, char *d){
      Lista *novo= (Lista*) malloc (sizeof(Lista));
      strcpy(novo->nome, n);//novo->nome=n; eh invalido
      strcpy(novo->nasc, d);
      novo->prox=l;
      novo->ant=NULL;
      //verifica se a lista nao esta vazia
      if(l!= NULL)
         l->ant=novo;
         
      return novo;
}

void lista_mostra(Lista* li){
     Lista *aux;//variavel usada para percorrer a lista
     for(aux=li;aux!=NULL;aux=aux->prox)
         printf("%-15s\t%s\n", aux->nome, aux->nasc);
	 printf("\n");
} 

Lista *busca_ultimo(Lista *li){
	Lista *aux;
	for(aux=li;aux->prox!=NULL;aux=aux->prox);//procura quem tem prox==NULL
	return aux;
}  
/* 
void busca(Lista *last, char *n){
	if (last==NULL)
		printf("%s nao encontrado!\n",n);
	else
		if (strcmp(last->nome,n)!=0)
		   busca(last->ant,n);
		else{
		   printf("%s nasceu na data: %s\n",last->nome, last->nasc);
		   return;
		}
}*/
void busca(Lista *last, char *n){
if(strcmp(last->nome,n) == 0) // Compara nome da entrada com o nome do elemento pesquisado
    printf("Data de nascimento: %s", last->nasc);
else
	 if(last->ant == NULL) // Caso seja o primeiro item da lista retornar "nao encontrado"
	 	printf("Nome nao encontrado!");
	 else // Busca no elemento anterior
	 	busca(last->ant, n);
	 return;
}
	 
//---------------------------------------------------------------
main(){
   Lista *li=lista_cria();
   Lista *aux;
   char nome[21];
   li=lista_insere(li,"Ana","10/12/2000");
   li=lista_insere(li,"Tadeu","12/05/2002");
   li=lista_insere(li,"Maria","15/02/1999");
   li=lista_insere(li,"Paulo Roberto","25/12/2001");
   li=lista_insere(li,"Daniel","20/01/1998");
   lista_mostra(li);
   aux=busca_ultimo(li);
   printf("\nUltimo: %s - %s\n",aux->nome,aux->nasc);
   printf("======================================================");
   do{
   	  printf("\nDigite o nome a ser procurado ou fim para encerrar: ");
   	  fflush(stdin);
   	  gets(nome);
   	  if(strcmp(nome,"fim")!=0)
   	  		busca(aux,nome);
   }while(strcmp(nome,"fim")!=0);
}
                          
