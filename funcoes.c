#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

// Inserir nó de operação no início do job.
void inserirInicio(Job *job, int opnumero, int maquina, int tempo){
    No *novo = (No*)malloc(sizeof(No));    
    if(novo){
		novo->opnumero = opnumero;
	    novo->maquina = maquina;
	    novo->tempo = tempo;
	    novo->proximo = job->inicio;
	    job->inicio = novo;
	    job->tam++;
	}
	else
		printf("Erro ao alocar memória!\n");
}

// Inserir nó de operação no início do job de uma outra forma.
No *insertAtBegin(int nOperation, int nMachine, int vTime, No *no) {
    No *new = (No*)malloc(sizeof(No));
    if (new != NULL) {
        new->opnumero = nOperation;
        new->maquina = nMachine;
        new->tempo = vTime;
        new->proximo = no;
        return(new);
    } else {
        return(no);
    }
}

// Inserir nó de operação no final do job.
void inserirFim(Job *job, int opnumero, int maquina, int tempo){
	No *no, *novo = (No*)malloc(sizeof(No));	
	if(novo){	
		novo->opnumero = opnumero;
	    novo->maquina = maquina;
	    novo->tempo = tempo;
	    novo->proximo = NULL;
		
		if(job->inicio == NULL){
			job->inicio = novo;
		}	
		else{
			no = job->inicio;
			while(no->proximo != NULL)
				no = no->proximo;
			no->proximo = novo;
		}
		job->tam++;
	}
	else
		printf("Erro ao alocar memória!\n");
}

// Inserir nó de operação no job após um nó de referência.
void inserirApos(Job *job, int opnumero, int maquina, int tempo, int ant){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->opnumero = opnumero;
	    novo->maquina = maquina;
	    novo->tempo = tempo;       
        if(job->inicio == NULL){
            novo->proximo = NULL;
            job->inicio = novo;
        }
        else{
            aux = job->inicio;
            while(aux->opnumero != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
        job->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// Remover todos os nós de uma operação
No* remover(Job *job, int opnumero){
	No *aux, *remover = NULL;
	No *inicio = job->inicio;		
	while(inicio != NULL){	
		if(job->inicio){
			if(job->inicio->opnumero == opnumero){
				remover = job->inicio;
				job->inicio = remover->proximo;
				job->tam--;			
			}
			else{
				aux = job->inicio;
				while((aux->proximo && aux->proximo->opnumero != opnumero))
					aux = aux->proximo;
				if(aux->proximo){
					remover = aux->proximo;
					aux->proximo = remover->proximo;
					job->tam--;
				}
			}		
		}
	inicio = inicio->proximo;
	}
	return remover;	
}

// Consultar todos os nós de uma operação
No* consultar(Job *job, int opnumero){	
	No *inicio = job->inicio;
	printf("Tamanho do Job: %d\n\n", job->tam);		
	while(inicio != NULL){		
			if(inicio->opnumero == opnumero){
				printf("|-----------------------|\n");
		        printf("| Numero da Operacao: %d |\n", inicio->opnumero);
		        printf("| Numero da Maquina:  %d |\n", inicio->maquina);
		        printf("| Tempo de Execucao:  %d |\n", inicio->tempo);
		        printf("|-----------------------|\n\n");   
		        inicio = inicio->proximo;								
			}
			else				
				inicio = inicio->proximo;	
	}	
}

// Calcula a soma dos tempos
int somaTempo(No *no){
	int soma;
    No *inicio = no;
    while(inicio != NULL){
    	soma += inicio->tempo;
        inicio = inicio->proximo;
    }
	return soma;
}

// Calcula o tempo mínimo do job
void tempoMinimo(Job *job){
	No *aux2 = job->inicio;
	No *aux = job->inicio;
	No *novaLista = NULL;
	if(aux2 != NULL){
		while(aux2 != NULL){
			if(aux->proximo != NULL && aux2->opnumero == aux2->proximo->opnumero){
				if(aux->tempo >= aux2->proximo->tempo){				
					aux = aux->proximo;
				}
			} 
			else{
				novaLista = insertAtBegin(aux->opnumero, aux->maquina, aux->tempo, novaLista);
				aux = aux2->proximo;
			}
			aux2 = aux2->proximo;
		}
	}
	if(novaLista != NULL){
		printf("Quantidade minima de tempo do job: %d\n\n", somaTempo(novaLista));	
	}
	printJob(novaLista);
	free(novaLista);
}

// Imprimir job.
void imprimirJob(Job *job){
    No *inicio = job->inicio;
    printf("Tamanho do Job: %d\n\n", job->tam);
    while(inicio != NULL){
    	printf("|-----------------------|\n");
        printf("| Numero da Operacao: %d |\n", inicio->opnumero);
        printf("| Numero da Maquina:  %d |\n", inicio->maquina);
        printf("| Tempo de Execucao:  %d |\n", inicio->tempo);
        printf("|-----------------------|\n\n");    
        inicio = inicio->proximo;
    }
	printf("\n");
	if(job->tam == 0)
		printf("Job inexistente!\n\n");
}

// Imprimir job de uma outra forma.
void printJob(No *no){
	No *inicio = no;
	while(inicio != NULL){
    	printf("|-----------------------|\n");
        printf("| Numero da Operacao: %d |\n", inicio->opnumero);
        printf("| Numero da Maquina:  %d |\n", inicio->maquina);
        printf("| Tempo de Execucao:  %d |\n", inicio->tempo);
        printf("|-----------------------|\n\n");    
        inicio = inicio->proximo;
    }
	printf("\n");
}


