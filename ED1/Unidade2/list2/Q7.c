#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 30
typedef struct{
    char letra[size];
    int qtd;
}tLetra;
typedef struct sElement{
    tLetra letra;
    struct sElement* next;
}tElement;


tElement* Inity(){
	tElement* element = (tElement*)calloc(1,sizeof(tElement));
	element->next = NULL;

	return element;
}

tLetra getLetra(char c[]){
	tLetra letra;
	strcpy(letra.letra,c);
	letra.qtd = 1;
	return letra;
}
tElement* getElement(char c[]){
	tElement* element = (tElement*)calloc(1,sizeof(tElement));

	element->letra = getLetra(c);
	element->next = NULL;
	
	return element;
}

void Add(tElement** element, char c[]){
	tElement* p = *element;
	tElement* add = getElement(c);
	
	while(p->next != NULL && strcmp(p->next->letra.letra,c)){
		p = p->next;
	}

	if(p->next == NULL){
		p->next = add;
	}else{
		p->next->letra.qtd += 1;
	}
	
}

int main(){
	tElement* element = Inity();
	
	FILE* file=fopen("test.txt","r+");
	
	int i=0;
	char letra;
	char c[size];

	while(fscanf(file,"%c",&letra)!=EOF){
		
		if(letra == ' '){
			c[i] = '\0';
			printf("%s",c);
			Add(&element,c);
			i=0;
		}else{
		c[i] = letra;
		++i;
		}
		
	}
		
	while(element->next != NULL){
		
			printf("\nLetra:%s -> %d",element->next->letra.letra,element->next->letra.qtd);
	
		element = element->next;
	}
	

}
