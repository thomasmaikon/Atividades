#include <stdio.h>


void select_sort(int vet[], int size){
    
    for(int j = 0; j < size; ++j){
        for(int i = 0; i < size;++i){
            if(vet[j] < vet[i]){
                int buffer = vet[j];
                vet[j] = vet[i];
                vet[i] = buffer;
            }
        }
    }
}

int main(){

    int vet[] = {7,2,9,5,6,4,3};

    printf("Vetor Inicial: ");
    for(int i=0;i<sizeof(vet)/4;++i){
        printf(" %d ",vet[i]);
    }

    select_sort(vet,sizeof(vet)/4);

    printf("\nVetor Ordenado: ");
    for(int i = 0; i < sizeof(vet)/4; ++i){
        printf(" %d ",vet[i]);
    }

}