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

int main(){
 
    tDado dado[5];
 
    start(&dado[0],15,"pp");
    start(&dado[1],10,"ppo");
    start(&dado[2],1,"012p");
    start(&dado[3],19,"thomas");
    start(&dado[4],11,"pedro");

    int start = 0;
    int end = 4;
    int result = -1;

    
    int valor_desejado = 19;
    int meio = end/2;

    while(start<=end){
        
        if( start == end ){
            printf("\nAcabou");
            break;
        }else if(dado[meio].id == valor_desejado){
            printf("\nA posicao e:%d nome:%s",meio+1,dado[meio].nome);
            break;
        }else if(dado[meio].id > valor_desejado){
            meio = meio -1;
        }else{
            meio = meio +1;
        }
    }
 
}