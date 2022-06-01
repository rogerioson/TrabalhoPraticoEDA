#include <string.h>
#include <stdlib.h>
#include "funcoes.h"

// Insere novo job
void inserirJob(job **head, int jobs){
	job *novo = malloc(sizeof(job));
	job *ultimo = *head;
	
	novo->job = jobs;
	novo->proximo = NULL;
	novo->iniop = NULL;
	
	if (*head == NULL){
		*head = novo;
		return;
	}
	
	while(ultimo->proximo != NULL){
		ultimo = ultimo->proximo;		
	}
	
	ultimo->proximo = novo;
	return;
}

// Imprime lista de jobs com suas operações
void PrintarOperacoes(job **head){
	job *lista = *head;
	opera *lista1;
	
	while(lista != NULL)
	{
		lista1 = lista->iniop;
		printf("{Job->%d} ", lista->job);
		while(lista1 != NULL)
		{
			printf("|| Operacao->%d || Maquina->%d || Velocidade->%d ", lista1->operacao, lista1->maquina, lista1->vmaqui);
			lista1 = lista1->proximo;
		}	
		lista = lista->proximo;
	}
}

// Elimina jobs
void eliminarJob(job **head, int jobs){
	job *lista = *head, *ant;
	opera *lista1, *eli;
	
	while(lista != NULL && lista->job == jobs)
	{	
		*head = lista->proximo;
		lista1 = lista->iniop;
		while(lista1 != NULL)
		{
			eli = lista1->proximo;
			free(lista1);
			lista1 = eli;
		}
		free(lista);
		lista = *head;
		return;
	}
	
	while(lista != NULL)
	{
		while(lista != NULL && lista->job != jobs)
		{
			ant = lista;
			lista = lista->proximo;
		}
		lista1 = ant->proximo->iniop;
		while(lista1 != NULL)
		{
			eli = lista1->proximo;
			free(lista1);
			lista1 = eli;
		}
	}
}

// Cria operações num job 
void CriarOperacoes(job **head, int jobs, int ope, int maquina, int velocidade){
	job *lista = *head;
	opera *new = malloc(sizeof(opera));
	opera **listaO;
	
	while(lista != NULL)
	{
		if(jobs == lista->job)
		{
			listaO = &(lista->iniop);	
		}	
		lista = lista->proximo;
	}
	
	lista = *head;
		
	new->operacao = ope;
	new->maquina = maquina;
	new->vmaqui = velocidade;
	new->proximo = NULL;
	
	opera *last = *listaO;	
	
	if(*listaO == NULL)
	{
		*listaO = new;
		return;
	}
	
	while(last->proximo != NULL)
	{
		last = last->proximo;
	}
	
	last->proximo = new;	
	return;	
}


