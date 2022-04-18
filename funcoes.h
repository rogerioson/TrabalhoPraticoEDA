#include <stdio.h>

typedef struct No {
	int opnumero;
    int maquina;	
	int tempo;     
	struct No *proximo;
}No;  

typedef struct {
    No* inicio;
    int tam;
}Job;

void inserirInicio(Job *job, int opnumero, int maquina, int tempo);
No *insertAtBegin(int nOperation, int nMachine, int vTime, No *no);
void inserirFim(Job *job, int opnumero, int maquina, int tempo);
void inserirApos(Job *job, int opnumero, int maquina, int tempo, int ant);
No* remover(Job *job, int opnumero);
No* consultar(Job *job, int opnumero);
void tempoMinimo(Job *job);
int somaTempo(No *no);
void imprimirJob(Job *job);
void printJob(No *no);
