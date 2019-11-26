#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define numElement 5
#define ERRO 0
#define Successful 1


typedef struct {
    char nome[MAX];
    int valor;
}tDado;

typedef struct {
    int position;
    tDado dado[numElement];
}tPilha;

void Inicializa(tPilha* pilha){
    pilha->position = -1;
    printf("\n Inicializando pilha %d",pilha->position);
}
int AddElement(tDado* dado,char nome[],int valor){
    strcpy(dado->nome,nome);
    dado->valor = valor;
}

int Prox(tPilha* pilha, char nome[],int valor){
    
    if(pilha->position == numElement){
        printf("\nPilha cheia");
        return ERRO;
    }
    
    pilha->position+=1;
    printf("\nEmpilhando %d",pilha->position);
    AddElement(&pilha->dado[pilha->position],nome,valor);

    return Successful;
}

int Desempilha(tPilha* pilha){
    if(pilha->position == -1){
        printf("\nPilha vasia\n");
        return ERRO;
    }
    
    pilha->position-=1;
    printf("\n Desempilhando, %d",pilha->position);
    return Successful;
}
int main(){
    tPilha pilha;
    Inicializa(&pilha);

    Prox(&pilha, "thomas",10);
    printf("\nOla, voce inseriu: %s com o valor %d",pilha.dado[pilha.position].nome,pilha.dado[pilha.position].valor);
    
    Desempilha(&pilha);
    
    Prox(&pilha, "Bug",19);
    printf("\nOla, voce inseriu: %s com o valor %d",pilha.dado[pilha.position].nome,pilha.dado[pilha.position].valor);
    
    Desempilha(&pilha);
}