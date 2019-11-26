#include<stdio.h>
#include<stdlib.h>
#define sizeName 30
#define sizeFila 10
#define Erro 0
#define Successful 1


typedef struct{
    int  value;
    char nome[sizeName];
}tDado;
typedef struct{
    tDado dado[sizeFila];
    int start;
    int end;
}tFila;
typedef struct sList{
    tFila fila;
    struct sList* next;
}tList;

void StartedFila(tFila* element){
    element->end   = -1;
    element->start = -1;
}

tDado getDado(){
    tDado dado;
    printf("Valor:");
    scanf("%d",&dado.value);
    
    getchar();
    
    printf("nome:");
    fgets(dado.nome,sizeName,stdin);

    return dado;
}

void  AddInFila(tFila* element,tDado dado){
    
    int fim = (element->end+1) % sizeFila;

    if(fim == element->start){
    
    }else if(element->start == -1){
        element->start += 1;
    }
    
    element->end = fim;
    element->dado[element->end] = dado;

    
}

tFila setFila(tFila fila,tDado dado){
    if(fila.start > sizeFila){
        StartedFila(&fila);
    }
    AddInFila(&fila,dado);
    return fila;
}
tFila getFila(){
    tFila fila;
    return fila;
}

tList* StartList(){
    tList* p = (tList*)calloc(1,sizeof(tList));
        
        p->next = NULL;
    return p;
}

tList* getList(tFila fila){
    tList* add = (tList*)calloc(1,sizeof(tList));
    add->fila = fila;
    
    add->next = NULL;

    return add;
}

void AddInList(tList** list,tFila fila){
    tList* p = *list;
    tList* add = getList(fila);
    
    while(p->next!=NULL){
        p= p->next;
    }
    p->next = add;
    
}

void RemoveInFila(tFila* fila){
    if(fila->start == -1){

    }else {
        fila->start = (fila->start+1)%sizeFila;
        
    }
}

int main(){
    tList* list = StartList();
    tFila fila = getFila();
    
    AddInList(&list,setFila(fila,getDado()));
    AddInFila(&list->next->fila,getDado());
    

    while(list->next != NULL){
        do{
            printf("\n%s",list->next->fila.dado[list->next->fila.start].nome);
            RemoveInFila(&list->next->fila);
        }while(list->next->fila.end != list->next->fila.start);
        printf("\n%s",list->next->fila.dado[list->next->fila.start].nome);
        list = list->next;
    }
}