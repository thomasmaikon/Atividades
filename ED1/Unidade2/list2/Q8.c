#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SizeNome 30
#define NumDado 5

typedef struct{
    char name[SizeNome];
    int value;
}tDado;
typedef struct {
    int posicao;
    tDado dado[NumDado];
}tPilha;
typedef struct sLinked{
    tPilha pilha;
    struct sLinked* next;
}tLinked;

void InicializaPilha(tPilha* pilha){
    pilha->posicao = -1;
}

void AddPilha(tPilha* pilha,tDado dado){
    if(pilha->posicao < NumDado){
        pilha->posicao +=1;
        pilha->dado[pilha->posicao] = dado;
    }
    
}
void Unstack(tPilha* pilha){
    
    if(pilha->posicao>-1){
        pilha->posicao -=1;
    }
}

tDado getDado(){
    tDado dado;
    printf("Valor:");
    scanf("%d",&dado.value);
    
    getchar();

    printf("Nome:");
    fgets(dado.name,SizeNome,stdin);
    
    return dado;
}

tLinked* InicializaLinked(){
    tLinked* linked = (tLinked*)calloc(1,sizeof(tLinked));
    linked->next = NULL;
    strcpy(linked->pilha.dado[0].name,"cabeca");
    
    return linked;
}

tLinked* getLinked(tPilha pilha){
    tLinked* linked = (tLinked*)calloc(1,sizeof(tLinked));
    linked->pilha = pilha;
    linked->next = NULL;
    
    return linked;
}

void AddList(tLinked** list,tPilha pilha){
    tLinked* p = *list;
    tLinked* add = getLinked(pilha);
    
    while(p->next !=NULL){
        p = p->next;
    }

    p->next = add;
}

tPilha getPilha(tPilha pilha){
    InicializaPilha(&pilha);
    AddPilha(&pilha,getDado());
    AddPilha(&pilha,getDado());
    return pilha;
}

int main(){
    tLinked* linkedlist = InicializaLinked();

    tPilha pilha;

    AddList(&linkedlist,getPilha(pilha));
    AddList(&linkedlist,getPilha(pilha));
    int i;
    for(i=1;linkedlist->next!=NULL;++i){
    printf("\nDesempilhando... List[%d]",i);
        while(linkedlist->next->pilha.posicao > -1){
            printf("\nNome:%s -> Valor:%d",linkedlist->next->pilha.dado[linkedlist->next->pilha.posicao].name,linkedlist->next->pilha.dado[linkedlist->next->pilha.posicao].value);
            Unstack(&linkedlist->next->pilha);
        }
        linkedlist=linkedlist->next;
    }
    
   
}
