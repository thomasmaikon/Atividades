#include <stdio.h>
#include <stdlib.h>




typedef struct sElement{
	int id;
	struct sElement* next;
}tElement;


void add(tElement** element,int id){
	tElement* p = *element;
	tElement* newElement = (tElement*)calloc(1,sizeof(tElement));
	
	newElement->next = NULL;
	newElement->id = id;
	
	if(*element == NULL){
		
		*element = newElement;
	}else{
		while(p->next != NULL){
			p=p->next;
		}
		
		p->next= newElement;
	}
	
}

int main(){
	tElement* element = NULL;
	
	add(&element,1);
	add(&element,2);
	add(&element,3);
	add(&element,4);
	
	int qtd = 4;
	
	
	tElement** table = (tElement**)calloc(qtd,sizeof(tElement));
	
	
	while(element != NULL){
	
	int endereco = (element->id % qtd);
		
		while(table[endereco] != NULL){
			table[endereco] = table[endereco]->next;
		}
		table[endereco] = element;
		
		element = element->next;
	}
		
	int i=0;
	while(i < qtd){
		
			printf("\nIndice:%d Endereco:%d Valor:%d",i,table[i], table[i]->id);
			while(table[i]->next != NULL){
				table[i]= table[i]->next;
				printf("-> Endereco:%d Valor:%d ",table[i], table[i]->id);
			}	
	
		++i;
	}
		

	
}
