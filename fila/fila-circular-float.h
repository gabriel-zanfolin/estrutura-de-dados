#define N 5
//a fila eh de float
typedef struct {
    float *vetFila;//ponteiro para o vetor
    int inicio; /* indexa o inicio da Fila */
    int fim;   /*indexa o final da Fila */
    int tamVetor; /* numero de elementos do vetor*/
    int tamFila; /* testes de vazia/cheia */
   } Fila;


void enfilera(Fila *fi, float novo){ //queue
     if (fi->tamFila ==fi->tamVetor) {//nao ha espaco
         printf("Fila cheia\n");
         return;
     }
     if (fi->fim==fi->tamVetor) //usa o aspecto circular
            fi->fim=0;
     fi->vetFila[fi->fim]=novo;
     fi->fim++;
     fi->tamFila++;
}
float retira(Fila *fi){//sempre do inicio
     int n;
     n=fi->vetFila[fi->inicio];
     //se eh o ultimo elemento do vetor
     if(fi->inicio==fi->tamVetor-1)
         fi->inicio=0;
     else
        (fi->inicio)++;
     (fi->tamFila)--;
     return n;

}
int fila_vazia(Fila *f){
    return (f->tamFila==0);
}
void mostrafila(Fila *f){
	int i;
	if(fila_vazia(f))
	   printf("Fila vazia\n");
	else{
		printf("\nConteudo da fila\n");
		if(f->inicio < f->fim){//a fila nao circulou
		   for(i=f->inicio;i < f->fim; i++)
		   		printf("%.0f\n",f->vetFila[i]);
		}
		else{ //a fila circulou
			for(i=f->inicio; i<f->tamVetor;i++)
				printf("%.0f\n",f->vetFila[i]);
			for(i=0;i<f->fim;i++)
				printf("%.0f\n",f->vetFila[i]);
		}
	}
}

Fila *fila_cria()
{
     Fila *f=(Fila*)malloc(sizeof(Fila));
     f->inicio=0;
     f->fim=0;
     f->tamVetor=N;
     f->tamFila=0;
     f->vetFila=(float*)malloc(f->tamVetor*sizeof(float));// (float*) malloc(N*sizeof(float));
     return f;
}
void fila_libera(Fila *f){
	free(f->vetFila);
	free(f);
}

