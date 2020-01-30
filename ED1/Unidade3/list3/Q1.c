#include <stdio.h>
#include <stdlib.h>


int main(){
    int vet[]={1,5,9,8,4,7};

    int i=0;
    while(vet[i] != 8){
        ++i;
    }

    printf("A posicao no meu vetor e:%d",i+1);
}