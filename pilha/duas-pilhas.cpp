#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
Pilha *intercala_pilhas(Pilha *a, Pilha *b){
	Pilha *nova=pilha_cria();
	Pilha *aa=pilha_cria();
	Pilha *bb=pilha_cria();
	float x;
	//esvaziar a pilha a em aa
	while(!pilha_vazia(a))
	  pilha_push(aa,pilha_pop(a));
	//esvaziar a pilha b em bb
	while(!pilha_vazia(b))
	  pilha_push(bb,pilha_pop(b));
	//intercala as pilhas na pilha nova e restaura as pilhas originais
	while(!pilha_vazia(aa) || !pilha_vazia(bb)){
		if(!pilha_vazia(aa)){
		x=pilha_pop(aa);
		pilha_push(a,x);
		pilha_push(nova,x);
		}
		if(!pilha_vazia(bb)){
			x=pilha_pop(bb);
			pilha_push(b,x);
			pilha_push(nova,x);
		}
	}
	pilha_libera(aa);
	pilha_libera(bb);
	return nova;
}

main(){     
      Pilha *p1=pilha_cria();
      Pilha *p2=pilha_cria();
      Pilha *p3;
      //inserir dados na pilha p1
      pilha_push(p1,1);
      pilha_push(p1,2);
      pilha_push(p1,3);
      //pilha_push(p1,4);
      //inserir dados na pilha p2
      pilha_push(p2,10);
      pilha_push(p2,20);
      pilha_push(p2,30);
      pilha_push(p2,40);
      //mostrar o conte�do das pilhas
      p3=intercala_pilhas(p1,p2);
      printf("P1\n");
      pilha_mostra(p1);
      printf("P2\n");
      pilha_mostra(p2);
      printf("P3\n");
      pilha_mostra(p3);
  }
