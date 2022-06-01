#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main() {
	
	job *head = NULL;
		
    int opcao, job, operacao, maquina, velocidade;

    do{
    	printf("          PROCESS PLAN         \n");
    	printf("- - - - - - - - - - - - - - - -\n");
        printf("1) Inserir Job\n2) Remover Job\n3) Inserir Operacao no Job\n4) Remover Operacao do Job\n5) Editar Operacao\n6) Imprimir\n7) Limpar Consola\n8) Process Plan\n0) Sair\n" );
        printf("- - - - - - - - - - - - - - - -\n");
		printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");
        switch(opcao) {  
			case 1:
				printf("Numero do Job: ");
				scanf("%d", &job);
				inserirJob(&head ,job);
				printf("\n");
				do{
                	printf("Deseja inserir mais algum Job?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Numero do Job: ");
							scanf("%d", &job);
							inserirJob(&head ,job);
							printf("\n");
			                break;
			            case 2:
			            	printf("Jobs inseridos com sucesso!\n\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");			            
					}				
				}while(opcao!=2);	
				break;
			case 2:
				printf("Numero do Job a remover: ");
				scanf("%d", &job);	
				eliminarJob(&head, job);
				printf("\n");
				do{
                	printf("Deseja remover mais algum Job?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Numero de Job a remover: ");
							scanf("%d", &job);	
							eliminarJob(&head, job);
							printf("\n");
			                break;
			            case 2:
			            	printf("Jobs removidos com sucesso!\n\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");			            
					}				
				}while(opcao!=2);
				break;           
			case 3:
				printf("Numero do job: ");
				scanf("%d", &job);
				printf("Operacao a criar: ");
				scanf("%d", &operacao);
				printf("Numero da maquina: ");
				scanf("%d", &maquina);
				printf("Velocidade: ");
				scanf("%d", &velocidade);
				CriarOperacoes(&head, job, operacao, maquina, velocidade);
				printf("\n");
				do{
                	printf("Deseja inserir mais alguma operacao no Job?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Numero do job: ");
							scanf("%d", &job);
							printf("Operacao a criar: ");
							scanf("%d", &operacao);
							printf("Numero da maquina: ");
							scanf("%d", &maquina);
							printf("Velocidade: ");
							scanf("%d", &velocidade);
							CriarOperacoes(&head, job, operacao, maquina, velocidade);
							printf("\n");
			                break;
			            case 2:
			            	printf("Operacoes inseridas com sucesso!\n\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");			            
					}				
				}while(opcao!=2);															
				break;
			case 4:
					
				break;		
			case 5: 
				PrintarOperacoes(&head);
				printf("\n\n");
            	printf("Digite o numero de Job que contem a operacao a editar : ");
				scanf("%d", &job);	
				eliminarJob(&head, job);     
                inserirJob(&head ,job);
				printf("\n");  				
				printf("Digite novamente o numero do Job: ");
				scanf("%d", &job);
				printf("Digite o novo numero da operacao: ");
                scanf("%d", &operacao);                
                printf("Digite o novo numero da maquina: ");
                scanf("%d", &maquina);                
                printf("Digite a nova velocidade: ");
                scanf("%d", &velocidade);
                printf("\n");
                CriarOperacoes(&head, job, operacao, maquina, velocidade);                
				do{
                	printf("Deseja inserir mais algum no de operacao?\n");
	                printf("1-Sim ou 2-Nao: ");
	                scanf("%d", &opcao);
	                printf("\n");	
	                switch(opcao){
	                	case 1:
	                		printf("Digite novamente o numero do Job: ");
							scanf("%d", &job);
	                		printf("Digite o novo numero da operacao: ");
			                scanf("%d", &operacao);			                
			                printf("Digite o novo numero da maquina: ");
			                scanf("%d", &maquina);			                
			                printf("Digite a nova velocidade: ");
			                scanf("%d", &velocidade);
			                printf("\n");
			                CriarOperacoes(&head, job, operacao, maquina, velocidade);
			                break;
			            case 2:
			            	printf("Operacoes editadas com sucesso!\n\n");
			            	break;
			            default:
	                		printf("Opcao invalida!\n");			            
					}				
				}while(opcao!=2);				
				PrintarOperacoes(&head);
				printf("\n\n");
				break;
			case 6:
				PrintarOperacoes(&head);
				printf("\n\n");
				break;			
			case 7:
				system("cls");
				break;
			case 8:
				inserirJob(&head ,1);
				CriarOperacoes(&head, 1, 1, 1, 4);
				CriarOperacoes(&head, 1, 1, 3, 5);
				CriarOperacoes(&head, 1, 2, 2, 4);
				CriarOperacoes(&head, 1, 2, 4, 5);
				CriarOperacoes(&head, 1, 3, 3, 5);
				CriarOperacoes(&head, 1, 3, 5, 6);
				CriarOperacoes(&head, 1, 4, 4, 5);
				CriarOperacoes(&head, 1, 4, 5, 5);
				CriarOperacoes(&head, 1, 4, 6, 4);
				CriarOperacoes(&head, 1, 4, 7, 5);
				CriarOperacoes(&head, 1, 4, 8, 9);				
				
				inserirJob(&head ,2);
				CriarOperacoes(&head, 2, 1, 1, 1);
				CriarOperacoes(&head, 2, 1, 3, 5);
				CriarOperacoes(&head, 2, 1, 5, 7);
				CriarOperacoes(&head, 2, 2, 4, 5);
				CriarOperacoes(&head, 2, 2, 8, 4);
				CriarOperacoes(&head, 2, 3, 4, 1);
				CriarOperacoes(&head, 2, 3, 6, 6);
				CriarOperacoes(&head, 2, 4, 4, 4);
				CriarOperacoes(&head, 2, 4, 7, 4);
				CriarOperacoes(&head, 2, 4, 8, 7);
				CriarOperacoes(&head, 2, 5, 4, 1);
				CriarOperacoes(&head, 2, 5, 6, 2);
				CriarOperacoes(&head, 2, 6, 1, 5);
				CriarOperacoes(&head, 2, 6, 6, 6);
				CriarOperacoes(&head, 2, 6, 8, 4);
				CriarOperacoes(&head, 2, 7, 4, 4);				
				
				inserirJob(&head ,3);
				CriarOperacoes(&head, 3, 1, 2, 7);
				CriarOperacoes(&head, 3, 1, 3, 6);
				CriarOperacoes(&head, 3, 1, 8, 8);
				CriarOperacoes(&head, 3, 2, 4, 7);
				CriarOperacoes(&head, 3, 2, 8, 7);
				CriarOperacoes(&head, 3, 3, 3, 7);
				CriarOperacoes(&head, 3, 3, 5, 8);
				CriarOperacoes(&head, 3, 3, 7, 7);
				CriarOperacoes(&head, 3, 4, 4, 7);
				CriarOperacoes(&head, 3, 4, 6, 8);
				CriarOperacoes(&head, 3, 5, 1, 1);
				CriarOperacoes(&head, 3, 5, 2, 4);				
				
				inserirJob(&head ,4);
				CriarOperacoes(&head, 4, 1, 1, 4);
				CriarOperacoes(&head, 4, 1, 3, 3);
				CriarOperacoes(&head, 4, 1, 5, 7);
				CriarOperacoes(&head, 4, 2, 2, 4);
				CriarOperacoes(&head, 4, 2, 8, 4);
				CriarOperacoes(&head, 4, 3, 3, 4);
				CriarOperacoes(&head, 4, 3, 4, 5);
				CriarOperacoes(&head, 4, 3, 6, 6);
				CriarOperacoes(&head, 4, 3, 7, 7);
				CriarOperacoes(&head, 4, 4, 5, 3);
				CriarOperacoes(&head, 4, 4, 6, 5);
				CriarOperacoes(&head, 4, 4, 8, 5);				
				
				inserirJob(&head ,5);
				CriarOperacoes(&head, 5, 1, 1, 3);
				CriarOperacoes(&head, 5, 2, 2, 4);
				CriarOperacoes(&head, 5, 2, 4, 5);
				CriarOperacoes(&head, 5, 3, 3, 4);
				CriarOperacoes(&head, 5, 3, 8, 4);
				CriarOperacoes(&head, 5, 4, 5, 3);
				CriarOperacoes(&head, 5, 4, 6, 3);
				CriarOperacoes(&head, 5, 4, 8, 3);
				CriarOperacoes(&head, 5, 5, 4, 5);
				CriarOperacoes(&head, 5, 5, 6, 4);				
				
				inserirJob(&head ,6);
				CriarOperacoes(&head, 6, 1, 1, 3);
				CriarOperacoes(&head, 6, 1, 2, 5);
				CriarOperacoes(&head, 6, 1, 3, 6);
				CriarOperacoes(&head, 6, 2, 4, 7);
				CriarOperacoes(&head, 6, 2, 5, 8);
				CriarOperacoes(&head, 6, 3, 3, 9);
				CriarOperacoes(&head, 6, 3, 6, 8);				
				
				inserirJob(&head ,7);
				CriarOperacoes(&head, 7, 1, 3, 4);
				CriarOperacoes(&head, 7, 1, 5, 5);
				CriarOperacoes(&head, 7, 1, 6, 4);
				CriarOperacoes(&head, 7, 2, 4, 4);
				CriarOperacoes(&head, 7, 2, 7, 6);
				CriarOperacoes(&head, 7, 2, 8, 4);
				CriarOperacoes(&head, 7, 3, 1, 3);
				CriarOperacoes(&head, 7, 3, 3, 3);
				CriarOperacoes(&head, 7, 3, 4, 4);
				CriarOperacoes(&head, 7, 3, 5, 5);
				CriarOperacoes(&head, 7, 4, 4, 4);
				CriarOperacoes(&head, 7, 4, 6, 6);
				CriarOperacoes(&head, 7, 4, 8, 5);
				CriarOperacoes(&head, 7, 5, 1, 3);
				CriarOperacoes(&head, 7, 5, 3, 3);				
				
				inserirJob(&head ,8);
				CriarOperacoes(&head, 8, 1, 1, 3);
				CriarOperacoes(&head, 8, 1, 2, 4);
				CriarOperacoes(&head, 8, 1, 6, 4);
				CriarOperacoes(&head, 8, 2, 4, 6);
				CriarOperacoes(&head, 8, 2, 5, 5);
				CriarOperacoes(&head, 8, 2, 8, 4);
				CriarOperacoes(&head, 8, 3, 3, 4);
				CriarOperacoes(&head, 8, 3, 7, 5);
				CriarOperacoes(&head, 8, 4, 4, 4);
				CriarOperacoes(&head, 8, 4, 6, 6);
				CriarOperacoes(&head, 8, 5, 7, 1);
				CriarOperacoes(&head, 8, 5, 8, 2);				
				break;
			case 0:	
				printf("Fim!\n");
                break; 	 			           
            default:
                printf("Opcao invalida!\n");            
        }  		      
    }while(opcao!=0);
  	return 0;
}

