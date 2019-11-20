#include <stdio.h>
#include <stdlib.h>

int numEspaco(char  vet[], int size);

int main(){
    char vet[100];

    printf("Digite uma string:");
    fgets(vet,100,stdin);

    int index,indey=0 ,posicao=0;
    
    char** pointer = (char**)malloc(50*sizeof(char*));
    
    int qtdEspacos = numEspaco(vet,sizeof(vet));

    for(posicao=0;posicao < qtdEspacos+1 ; ++posicao){
        pointer[posicao] = (char*) malloc(50*sizeof(char));
    }
    
    posicao=0;

    while(vet[index] != '\0'){
        if(vet[index] == ' '){
            
            ++index;
            indey = 0;
            ++posicao;
        }

        pointer[posicao][indey] = vet[index];
        ++index;
        ++indey;
    }
    
    for(posicao = 0;posicao <qtdEspacos+1; ++posicao){
        printf("\nA parte [%d] e :%s",posicao+1,pointer[posicao]);
    }
    free(pointer);
}

int numEspaco(char  vet[],int size){
    int quantidade = 0,index;
    for(index = 0; index < size;++index){
        if((int)vet[index] == 32){
            quantidade+=1;
        }
    }
    return quantidade;
}