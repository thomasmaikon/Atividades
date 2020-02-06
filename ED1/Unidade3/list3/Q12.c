#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



typedef struct{
    int id;
    char nome[30];
}tDado;

void start(tDado* dado,int id,char nome[]){
    dado->id = id;
    strcpy(dado->nome,nome);
}


void shell_sort(tDado dado[], int size){
    int metade = size/2;
    for(; metade > 0 ; metade = metade/2){
        for(int i=0; i+metade <= size ;++i){
            if (dado[i].id >= dado[i+metade].id){
                int buffer = dado[i].id;
                dado[i].id = dado[i+metade].id;
                dado[i+metade].id = buffer;
            }
        }
    }
}


void select_sort(tDado dado[], int size){
    
    for(int j = 0; j < size; ++j){
        for(int i = 0; i < size;++i){
            if(dado[j].id < dado[i].id){
                int buffer = dado[j].id;
                dado[j].id = dado[i].id;
                dado[i].id = buffer;
            }
        }
    }
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
int bubble_sort(tDado vet[],int size){
    int i, result = 0;
    for(i = 0; i< size-1; ++i){
        if(vet[i].id > vet[i+1].id){
            int buffer = vet[i].id;
            vet[i].id = vet[i+1].id;
            vet[i+1].id = buffer;
            result = 1;
        }
    }
    return result;
}


int main(){
     tDado dado[5];
 
    start(&dado[0],15,"pp");
    start(&dado[1],10,"ppo");
    start(&dado[2],1,"012p");
    start(&dado[3],19,"thomas");
    start(&dado[4],11,"pedro");

    tDado dado1[5];
    start(&dado1[0],15,"pp");
    start(&dado1[1],10,"ppo");
    start(&dado1[2],1,"012p");
    start(&dado1[3],19,"thomas");
    start(&dado1[4],11,"pedro");

    tDado dado2[5];
    start(&dado2[0],15,"pp");
    start(&dado2[1],10,"ppo");
    start(&dado2[2],1,"012p");
    start(&dado2[3],19,"thomas");
    start(&dado2[4],11,"pedro");

    tDado dado3[5];
    start(&dado3[0],15,"pp");
    start(&dado3[1],10,"ppo");
    start(&dado3[2],1,"012p");
    start(&dado3[3],19,"thomas");
    start(&dado3[4],11,"pedro");

    printf("Vetor Inicial: ");
    for(int i=0;i < 5 ;++i){
        printf("-> id:%d ",dado[i].id);
    }
    
    clock_t end,start;

    start = clock();
    shell_sort(dado,5);
    end = clock();
    
    float diff = (((float)end - (float)start) / 1000000.0F );
    printf("\n Tempo do shell_sort: %4.0f",diff);

    start = clock();
    select_sort(dado1,5);
    end = clock();

    diff = (((float)end - (float)start) / 1000000.0F );
    printf("\n Tempo do select_sort: %4.0f",diff);


    start = clock();
    insert_sort(dado2,5);
    end = clock();

    diff = (((float)end - (float)start) / 1000000.0F );
    printf("\n Tempo do insert_sort: %4.0f",diff);

    start = clock();
    bubble_sort(dado3,5);
    end = clock();

    diff = (((float)end - (float)start) / 1000000.0F );
    printf("\n Tempo do bubble_sort: %4.0f",diff);

}



