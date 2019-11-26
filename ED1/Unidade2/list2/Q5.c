#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 30

typedef struct{
    int age,value;
    char name[size];
}tDado;

typedef struct sElement{
    tDado dado;
    struct sElement* next;
    struct sElement* previous;

}tElement;

tElement* Cria(tDado dado){
    tElement* NewElement = (tElement*)calloc(1,sizeof(tElement));
    
    NewElement->dado     = dado;
    NewElement->next     = NULL;
    NewElement->previous = NULL;

    return NewElement;
}

tElement* Inity(){
    tElement* cabeca = (tElement*)calloc(1,sizeof(tElement));
    
    cabeca->dado.age   = -1;
    cabeca->dado.value = -1;
    cabeca->next       = NULL;
    cabeca->previous   = NULL;

    return cabeca;
}

void Add(tElement** element,tDado dado){
    tElement* p = *element;
    tElement* p1 = *element;
    tElement* add = Cria(dado);

    add->next = NULL;
    add->previous = p;

    while(p->next != NULL){
        p = p->next;
    }
    p->next = add;
    p1->previous = add;
}

void after(tElement** element, int age,tDado dado){
    tElement* p = *element;
    while(p->next->dado.age != age && p->next != NULL){
        p = p->next;
    }
    
    if(p->next == NULL){
    }else{
        tElement* add = Cria(dado);
        add->previous = p->next;
        add->next =  p->next->next;
        p->next->next->previous = add;
        p->next->next = add;
    }
}

tDado criar(){
    tDado dado;
    
    printf("\nIdade:");
    scanf("%d",&dado.age);
    getchar();
    printf("\nNome:");
    fgets(dado.name,size,stdin);
    
    printf("\nValor:");
    scanf("%d",&dado.value);
    
    return dado;
}



void Remove(tElement** element,int id,int value){
    tElement* p = *element;
    
    
        while(p->next != NULL && p->dado.age!=id && p->dado.value!=value){
            p=p->next;
        }
        if(p->next == NULL){
        }else{
            p->previous->next = p->next;   
        }
}

int main(){
    tDado dado;
    tElement* element = Inity();
    
    Add(&element,criar());
    Add(&element,criar());
    after(&element,9,criar());
    
        printf("\n Nome:%d",element->dado.age);
        printf("\n Nome:%d",element->next->dado.age);
        printf("\n Nome:%d",element->next->next->dado.age);
        printf("\n Nome:%d",element->next->next->next->dado.age);
    
}