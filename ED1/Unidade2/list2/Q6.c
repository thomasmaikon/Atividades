#include <stdio.h>
#include <stdlib.h>
#define size 30

typedef struct {
    int age, value;
    char name[size];
}tDado;

typedef struct sElement{
    tDado dado;
    struct sElement* next;
    struct sElement* previous;
}tElement;

tDado getDado(){
    tDado dado;
    
    printf("\nIdade:");
    scanf("%d",&dado.age);
    
    printf("\nValor:");
    scanf("%d",&dado.value);
    
    getchar();

    printf("\nNome:");
    fgets(dado.name,size,stdin);
    
    return dado;
}

tElement* getElement(tDado dado){
    tElement* element = (tElement*)calloc(1,sizeof(tElement));
    
    element->dado     = dado;
    element->next     = NULL;
    element->previous = NULL;
    return element;
}

void AddElement(tElement** element, tDado dado){
    tElement* pointer = *element;
    tElement* add = getElement(dado);
    
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next = add;
    pointer->previous = add;
    add->previous = pointer;

}

void after(tElement** element,int value ,tDado dado){
    tElement* p = *element;
    tElement* add = getElement(dado);
    
    while((p->dado.value != value) && (p != NULL)){
        printf("\nNome:%s",p->dado.name);
        p = p->next;
    }
    
    if(p == NULL){
    }
    else{
        add->previous = p;
        p->next->previous = add;
        add->next = p->next;
        p->next = add;
    }
}

tElement* AddFirstElement(tElement** element,tDado dado){
    tElement* pointer = *element;
    tElement* add = getElement(dado);

    if(pointer == NULL){
        pointer = add;
        pointer->next = NULL;
        pointer->previous = NULL;
    }else{
        add->next = pointer;
        add->previous = pointer->previous;
        pointer->previous = add;
        pointer = add;
    }

    return pointer;
}



int main(){
    tElement* element = NULL ;
    
    element = AddFirstElement(&element,getDado());
    AddElement(&element,getDado());

    after(&element,8,getDado());
    

    printf("\nSequencia->");
    printf("\nNome:%s",element->dado.name);
    printf("\nNome:%s",element->next->dado.name);
    printf("\nNome:%s",element->next->next->dado.name);

}