#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SuccessFull 1
#define Erro 0
#define name 30


typedef struct sDado{
	char nome[name];
	int id;
}tDado;
typedef struct sElement{
	tDado dado;
	struct sElement* proximo;
}tElement;

void Add(tElement** element,char nome[],int id){
	tElement* novo = (tElement*)calloc(1,sizeof(tElement));
	
	strcpy(novo->dado.nome,nome);
	novo->dado.id = id;
	novo->proximo = *element;
	*element = novo;
}

void AddFim(tElement** element,char nome[],int id){
	tElement* p = *element;
	
	tElement* last = (tElement*)calloc(1,sizeof(tElement));
	strcpy(last->dado.nome,nome);
	last->dado.id = id;

	if(*element==NULL){
		*element = last;
	}else{
		while(p->proximo != NULL){
			p = p->proximo;
		}
		p->proximo = last;
	}
}

int existe(tElement* element,int id){
	while(element != NULL){
		if(element->dado.id == id){
			return SuccessFull;
		}
		element = element->proximo;
	}
	return Erro;
}

void Remove(tElement** element, int id){
	tElement* p = *element;
	tElement* next = p->proximo;
	tElement* previous = p;

	if(p->dado.id == id){
		*p = *p->proximo;
	}else{
		if(existe(*element,id)){
			while (next != NULL && next->dado.id != id){
				previous = next;
				next = next->proximo;
			}
			p = previous;
			p->proximo = next->proximo;
		}
	}
}

int main(){
	tElement* element = NULL;
	
	AddFim(&element,"thomas",10);
	Add(&element,"Thominhas",50);
	AddFim(&element,"p",90);
	AddFim(&element,"s",60);
	Add(&element,"Thoms",26);
	//Remove(&element,90);

	while (element!=NULL){
		printf("\nNome:%s",element->dado.nome);
		element = element->proximo;
	}
}