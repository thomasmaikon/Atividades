#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
#define Successfull 1
#define Erro 0


typedef struct sDado {
    int id, valor;
    char nome[MAX];
}tDado;

typedef struct sElemento{
    tDado dado;
    struct sElemento* pProximo;
}tElemento;


tElemento* Inicializa(){
    tElemento* pNovo = (tElemento*) calloc(1,sizeof(tElemento));
    strcpy(pNovo->dado.nome,"cabeca");
    pNovo->dado.id = -1;
    pNovo->dado.valor= -1;
    pNovo->pProximo = NULL;

    return pNovo;
}

void AddFIm(tElemento* elemento,char nome[],int id,int valor){
    tElemento* pAdd = (tElemento*)calloc(1,sizeof(tElemento));
    
    pAdd->dado.id = id;
    strcpy(pAdd->dado.nome,nome);
    pAdd->dado.valor = valor;
    pAdd->pProximo = NULL;
    
    while (elemento->pProximo != NULL){
     elemento = elemento->pProximo;
    }
    elemento->pProximo = pAdd;
    
}
tElemento* AddInicio(tElemento* elemento,char nome[], int id, int valor){
    tElemento* inicio = (tElemento*)calloc(1,sizeof(tElemento));

    strcpy(inicio->dado.nome,nome);
    inicio->dado.id = id;
    inicio->dado.valor=valor;
    
    inicio->pProximo = elemento;
    elemento = inicio;
    return elemento;
}

int existe(tElemento* elemento,int id){
    while(elemento != NULL){
            if(elemento->dado.id == id){
                return 1;
            }
        elemento= elemento->pProximo;
    }
    return 0;
}

void Remove(tElemento* elemento,int id){
    tElemento* proximo = elemento;
    tElemento* anterior;

    

    if(existe(elemento,id)){
        while(proximo->dado.id != id && proximo != NULL){
            anterior = proximo;
            proximo = proximo->pProximo;
        }
        
        if(proximo->dado.id == id){
            elemento = anterior ;
            if(elemento == NULL){
                elemento = proximo->pProximo;
                elemento->pProximo = elemento->pProximo;
            }else{
                elemento->pProximo = proximo->pProximo;
            }
        }
    }
}


int main(){
    tElemento* pInicio = Inicializa();    
    char nome[MAX];
    Inicializa(pInicio);
 
    pInicio =    AddInicio(pInicio,"Thominhas",10,6);
    AddFIm(pInicio,"Cabral",18,6);
    AddFIm(pInicio,"Arlindo",1,6);



    while(pInicio!= NULL){
        printf("\nNome:%s",pInicio->dado.nome);
        pInicio = pInicio->pProximo;
    }

    
}
