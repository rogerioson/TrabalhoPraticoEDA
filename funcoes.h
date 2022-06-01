#include <stdio.h>

typedef struct Job {
	int job;     
	struct Job *proximo;
	struct Operacao *iniop;
}job;  

typedef struct Operacao {
    int operacao;
    int maquina;
    int vmaqui;
    struct Operacao *proximo;
}opera;

void inserirJob(job **head, int jobs);
void CriarOperacoes(job **head, int job, int ope, int maquina, int velocidade);
void PrintarOperacoes(job **head);
void eliminarJob(job **head, int jobs);

