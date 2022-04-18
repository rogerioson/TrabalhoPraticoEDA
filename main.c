#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main() {
	
	Job job;	
	No *removido;
	No *aux;

    int opcao, opnumero, maquina, tempo, ant;

    job.inicio = NULL;
    job.tam = 0;

    do{
    	printf("              MENU             \n");
    	printf("- - - - - - - - - - - - - - - -\n");
        printf("1) Inserir Operacao no Inicio\n2) Inserir Operacao no Fim\n3) Inserir Operacao Apos\n4) Alterar Operacao\n5) Remover Operacao\n6) Consultar Operacao\n7) Tempo Minimo do Job\n8) Imprimir Job\n9) Sair\n" );
        printf("- - - - - - - - - - - - - - - -\n");
		printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao) {
            case 1:
                printf("Digite o numero da operacao: ");
                scanf("%d", &opnumero);                
                printf("Digite o numero da maquina: ");
                scanf("%d", &maquina);                
                printf("Digite a quantidade de tempo de execucao: ");
                scanf("%d", &tempo);
                printf("\n");
                inserirInicio(&job, opnumero, maquina, tempo);                
				do{
                	printf("Deseja inserir mais alguma operacao no inicio?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Digite o numero da operacao: ");
			                scanf("%d", &opnumero);			                
			                printf("Digite o numero da maquina: ");
			                scanf("%d", &maquina);			                
			                printf("Digite a quantidade de tempo de execucao: ");
			                scanf("%d", &tempo);
			                printf("\n");
			                inserirInicio(&job, opnumero, maquina, tempo);
			                break;
			            case 2:
			            	printf("Operacoes inseridas com sucesso!\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");			            
					}				
				}while(opcao!=2);				
            	break;
            case 2:
            	printf("Digite o numero da operacao: ");
                scanf("%d", &opnumero);
                printf("Digite o numero da maquina: ");
                scanf("%d", &maquina);
                printf("Digite a quantidade de tempo de execucao: ");
                scanf("%d", &tempo);
                printf("\n");
                inserirFim(&job, opnumero, maquina, tempo);                
				do{
                	printf("Deseja inserir mais alguma operacao no fim?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Digite o numero da operacao: ");
			                scanf("%d", &opnumero);			                
			                printf("Digite o numero da maquina: ");
			                scanf("%d", &maquina);			                
			                printf("Digite a quantidade de tempo de execucao: ");
			                scanf("%d", &tempo);
			                printf("\n");
			                inserirFim(&job, opnumero, maquina, tempo);
			                break;
			            case 2:
			            	printf("Operacoes inseridas com sucesso!\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");			            
					}				
				}while(opcao!=2);				
                break;
             case 3:
            	printf("Digite o numero da operacao: ");
                scanf("%d", &opnumero);                
                printf("Digite o numero da maquina: ");
                scanf("%d", &maquina);                
                printf("Digite a quantidade de tempo de execucao: ");
                scanf("%d", &tempo);                
                printf("Digite o numero da operacao de referencia: ");
                scanf("%d", &ant);
                printf("\n");
                inserirApos(&job, opnumero, maquina, tempo, ant);                
				do{
                	printf("Deseja inserir mais alguma operacao no meio?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Digite o numero da operacao: ");
			                scanf("%d", &opnumero);			                
			                printf("Digite o numero da maquina: ");
			                scanf("%d", &maquina);			                
			                printf("Digite a quantidade de tempo de execucao: ");
			                scanf("%d", &tempo);			                
			                printf("Digite o numero da operacao de referencia: ");
                			scanf("%d", &ant);
                			printf("\n");
			                inserirApos(&job, opnumero, maquina, tempo, ant);
			                break;
			            case 2:
			            	printf("Operacoes inseridas com sucesso!\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");		            
					}				
				}while(opcao!=2);				
                break;              
			case 4:
				imprimirJob(&job);
            	printf("Digite o numero da operacao a alterar: ");
                scanf("%d", &opnumero);        
                printf("\n");
                removido = remover(&job, opnumero);                
                if(removido){						
                	free(removido); 
					imprimirJob(&job); 
				}
            	else{				
            		printf("Operacao inexistente!\n\n"); 
					break;
				}
				
				printf("Digite o novo numero da operacao: ");
                scanf("%d", &opnumero);                
                printf("Digite o novo numero da maquina: ");
                scanf("%d", &maquina);                
                printf("Digite o novo tempo de execucao: ");
                scanf("%d", &tempo);
                printf("\n");
                inserirInicio(&job, opnumero, maquina, tempo);                
				do{
                	printf("Deseja inserir mais algum no de operacao?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Digite o novo numero da operacao: ");
			                scanf("%d", &opnumero);			                
			                printf("Digite o novo numero da maquina: ");
			                scanf("%d", &maquina);			                
			                printf("Digite o novo tempo de execucao: ");
			                scanf("%d", &tempo);
			                printf("\n");
			                inserirInicio(&job, opnumero, maquina, tempo);
			                break;
			            case 2:
			            	printf("Operacoes alteradas com sucesso!\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");			            
					}				
				}while(opcao!=2);				
				imprimirJob(&job);				         	
                break;             
            case 5:
            	imprimirJob(&job);
            	printf("Digite o numero da operacao a remover: ");
                scanf("%d", &opnumero);        
                printf("\n");
                removido = remover(&job, opnumero);                
                if(removido){						
                	free(removido); 
					imprimirJob(&job); 
				}
            	else
            		printf("Operacao inexistente!\n\n");  				         	
                break;				
            case 6:
            	printf("Digite o numero da operacao a consultar: ");
                scanf("%d", &opnumero);			
                printf("\n");                
				consultar(&job, opnumero);											    																	    	
                break; 
			case 7:				
				tempoMinimo(&job);										
				break;   
			case 8:				
				imprimirJob(&job);									
				break;    
			case 9:	
				printf("Fim!\n");
                break; 	            
			case 12: //1º job da Tabela 1 de process plan
				inserirInicio(&job, 1, 1, 4);
				inserirInicio(&job, 1, 3, 5);
				inserirInicio(&job, 2, 2, 4);
				inserirInicio(&job, 2, 4, 5);
				inserirInicio(&job, 3, 3, 5);
				inserirInicio(&job, 3, 5, 6);
				inserirInicio(&job, 4, 4, 5);
				inserirInicio(&job, 4, 5, 5);
				inserirInicio(&job, 4, 6, 4);
				inserirInicio(&job, 4, 7, 5);
				inserirInicio(&job, 4, 8, 9);								
				break;			           
            default:
                printf("Opcao invalida!\n");
            
        }  		      
    }while(opcao!=9);
  	return 0;
}

