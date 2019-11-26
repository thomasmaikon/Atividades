#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define numElementos 5
#define Erro 0
#define Successfull 1


typedef struct{
    int valor;
    char nome[MAX];
}tDado;

typedef struct{
    int inicio, fim;
    tDado dado[numElementos];
}tFila;

void Inicializa(tFila* fila){
    fila->inicio = -1;
    fila->fim = -1;
}

void AddElement(tDado* dado,char nome[], int valor){
    dado->valor = valor;
    strcpy(dado->nome, nome);
}

int Inserir(tFila* fila, char nome[], int valor){
    int position = (fila->fim +1) % numElementos;

    if(position == fila->inicio){
        printf("A fila está cheia");
        return Erro;
    }
    if(fila->inicio == -1){
        fila->inicio +=1;
    }
    
    fila->fim = position;
    AddElement(&fila->dado[fila->fim], nome, valor);
    return Successfull;
}

int Remover(tFila* fila){
    
    if(fila->inicio == -1){
        printf("\nFila nao iniciada");
        return Erro;
    }
    printf("\nvoce removeu:%s",fila->dado[fila->inicio].nome);

    int posicao = (fila->inicio +1 ) % numElementos;
    fila->inicio = posicao;

    return Successfull;
}

int main(){
    tFila fila;

    Inicializa(&fila);
    Inserir(&fila, "Thomas",19);

    Inserir(&fila, "Phomas",19);
    Inserir(&fila, "homas",19);
    Inserir(&fila, "Thoas",19);
    Inserir(&fila, "Thoms",19);
    Remover(&fila);
    Inserir(&fila, "Thops",19);
    Remover(&fila);
    Remover(&fila);
    Remover(&fila);
    Remover(&fila);
    printf("\n-Voce inseriu: nome: %s",fila.dado[fila.inicio].nome);
    printf("\n-Voce inseriu: nome: %s",fila.dado[fila.fim].nome);
}
