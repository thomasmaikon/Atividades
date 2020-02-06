#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nome[30];
}tDado;

void start(tDado* dado,int id,char nome[]){
    dado->id = id;
    strcpy(dado->nome,nome);
}

int insert_sort(tDado vet[],int size){
    int i, result = 0;
    for(i = 0; i< size-1; ++i){
       
        if(vet[i].id > vet[i+1].id){
            int buffer = vet[i].id;
            vet[i].id = vet[i+1].id;
            vet[i+1].id = buffer;
    
        int j;
        for(j = i; j > 0 ;--j){
                
            if(vet[j].id > vet[j-1].id){
                int buffer2 = vet[j-1].id;
                vet[j-1].id = vet[j].id;
                vet[j].id = buffer2;
            }    
            
        }
            result = 1;
        }
    }
    return result;
}


int main()
{
   tDado dado[5];
 
    start(&dado[0],15,"pp");
    start(&dado[1],10,"ppo");
    start(&dado[2],1,"012p");
    start(&dado[3],19,"thomas");
    start(&dado[4],11,"pedro");


    printf("Vetor Inicial:");
    int i;
    for(i=0;i <5; ++i){
        printf(" %d",dado[i].id);
    }
    
    while(insert_sort(dado,5));
    
    printf("\nVetor ordenado:");
    for(i=0;i < 5; ++i){
        printf(" %d",dado[i].id);
    }
    
    return 0;
}

