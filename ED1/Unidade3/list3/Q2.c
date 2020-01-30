#include <stdio.h>
#include <stdlib.h>


typedef struct sElement
{
	int id;
	struct sElement * next;
}tElement;



void add(tElement** element,int value){
	tElement* p = *element;
	tElement* add = (tElement*)calloc(1,sizeof(tElement));
	
	add->id = value;
	add->next = NULL;
	
	if(*element == NULL){
		*element = add;
	}else{
		while(p->next != NULL){
			p = p->next;
		}
		p->next = add;
	}
	
}

int main(){
	tElement* element = NULL;
	add(&element,50);
	add(&element,10);
	add(&element,80);
	
	int get_element = 80;
	
	for(;element->id != get_element; element=element->next){
		
		printf("\nVoce passou por: %d", element->id);
		
	}
}
