#include <stdio.h>
#include <stdlib.h>




typedef struct sElement{
	int id;
	struct sElement* next;
}tElement;



void add(tElement** element){
	tElement* p = *element;
	tElement* newElement = (tElement*)calloc(1,sizeof(tElement));
	
	newElement->next = NULL;
	
	if(*element == NULL){
		newElement->id = 0;
		*element = newElement;
	}else{
		int id = 1;
		while(p->next != NULL){
			p=p->next;
			++id;
		}
		newElement->id = id;
		p->next= newElement;
	}
	
}

int main(){
	tElement* element = NULL;
	
	add(&element);
	add(&element);
	add(&element);
	add(&element);
	
	int qtd = 4;
	
	
	int** table = (int**)calloc(qtd,sizeof(int));
	
	while(element != NULL){
		int endereco = (element->id % qtd);
		table[endereco] = element;
		element = element->next;
	}
	
	int i=0;
	while(i < qtd)
	{
		printf("\n posicao:%d endereco:%d",i,table[i]);
		++i;
	}
	
}
