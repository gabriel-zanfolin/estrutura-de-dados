#define N 50 
typedef struct pilha{
        int n;//controla o indice livre da pilha
        float vet[N];
        }Pilha;

Pilha *pilha_cria(){//retorna o endereco da pilha
      Pilha *p=(Pilha*)malloc(sizeof(Pilha));
      p->n=0;
      return p;
} 
int pilha_vazia(Pilha *p){
    if (p->n==0) return 1;//verdadeiro
    else  return 0;
}
void pilha_push(Pilha *p, float v) {
    if(p->n==N){
      printf("Capacidade da pilha esgotada.\n");
      return; //volta para o programa
      }   //insere novo elemento
      p->vet[p->n]=v;
      p->n++; //incrementa o valor de n (dentro da pilha)
} 
float pilha_pop(Pilha *p){
     float v;
//retira o elemento da pilha
     v=p->vet[p->n-1];  
     p->n--;
     return v;
}
void pilha_libera(Pilha *p){
     free(p);
}      
void pilha_mostra(Pilha *p) {
     printf("Conteudo da pilha\n");
     for(int i=p->n-1;i>=0;i--)
         printf("%.0f\n",p->vet[i]);
     printf("\n");
} 

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");       
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Conta elementos\n");//int contaElementos(Pilha *p)
     printf("5. Soma elementos\n");//float somaElementos(Pilha *p)
     printf("6. Topo\n");//float topo(Pilha *p)
     printf("7. Base\n");//float base(Pilha *p)
     printf("9. Fim\n");
}

int contaElementos(Pilha *p){
	Pilha *aux=pilha_cria();//pilha para colocar os elementos retirados da pilha p
	int cont=0;
	float x;
	while(pilha_vazia(p)==0){
		x=pilha_pop(p);
		cont++;
		pilha_push(aux,x);
	}
	while(pilha_vazia(aux)==0){
		x=pilha_pop(aux);
		pilha_push(p,x);
	}
	pilha_libera(aux);
	return cont;
}

float somaElementos(Pilha *p){
	float x,soma=0;
	Pilha *a;
	a=pilha_cria();
	//esvazia a pilha original para somar os elementos
	while(!pilha_vazia(p)){//enquanto a pilha p nao estiver vazia
		x=pilha_pop(p);
		soma=soma+x;//soma+=x;
		pilha_push(a,x);
	}
	//restaurar a pilha original
	while(!pilha_vazia(a))
	   pilha_push(p,pilha_pop(a));
	pilha_libera(a);
	return soma;
}

float topo(Pilha *p){
	float x;
	x=pilha_pop(p);//saiu
	pilha_push(p,x);//coloquei de volta
	return x;
}

float base(Pilha *p){
	Pilha *aux=pilha_cria();//pilha para calcular os elementos retirados da pilha p
	float x, ultimo;
	while(pilha_vazia(p)==0){
		x=pilha_pop(p);
		pilha_push(aux,x);
		ultimo=x;
	}
	while(pilha_vazia(aux)==0){
		x=pilha_pop(aux);
		pilha_push(p,x);
	}
	pilha_libera(aux);
	return ultimo;
}