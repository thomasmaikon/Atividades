#include <stdio.h>


void shell_sort(int vet[], int size){
    
}

int main(){

    int vet[] = {7,2,9,5,6,4,3};

    printf("Vetor Inicial: ");
    for(int i=0;i<sizeof(vet)/4;++i){
        printf(" %d ",vet[i]);
    }

    shell_sort(vet,sizeof(vet)/4);

    printf("\nVetor Ordenado: ");
    for(int i = 0; i < sizeof(vet)/4; ++i){
        printf(" %d ",vet[i]);
    }

}