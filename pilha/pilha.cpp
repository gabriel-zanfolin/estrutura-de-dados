#include <stdio.h>
#include <stdlib.h>
#include "pilha1.h"

main(){     
      Pilha *pi=pilha_cria();
      int opmenu;
      float item;
      do{
         menu(); 
         scanf("%d", &opmenu);
         switch (opmenu) {
         case 1 : //insere
                printf("Digite o valor a ser empilhado: "); 
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        case 2 : //retira
			 if(pilha_vazia(pi)) 
                    printf("Pilha Vazia\n");
                else
                 printf("Elemento retirado = %.0f\n",pilha_pop(pi));
                break;    
        case 3 : //mostra
        		if(pilha_vazia(pi))
        			printf("Pilha Vazia\n");
                else
                	pilha_mostra(pi);
			    break;   
		case 4://conta elementos
		       printf("Numero de elementos: %d\n",contaElementos(pi));
			   break;  
		case 5://soma elementos
		       printf("Soma dos elementos: %.0f\n",somaElementos(pi));
			   break; 
		case 6://mostra o topo
				if(pilha_vazia(pi))
        			printf("Pilha Vazia- nao tem topo\n");
                else
                	printf("Topo: %.0f\n",topo(pi));
			    break;    
		case 7 ://mostra a base
				if(pilha_vazia(pi))
        			printf("Pilha Vazia- nao tem topo\n");
                else
					printf("Base da pilha: %.2f\n", base(pi));
				break;    
       }  //switch
       printf("\n"); system("pause"); 
     } while(opmenu!=9);
   } 

