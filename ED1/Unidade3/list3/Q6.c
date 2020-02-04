#include <stdio.h>


int bubble_sort(int vet[],int size){
    int i, result = 0;
    for(i = 0; i< size-1; ++i){
        if(vet[i] > vet[i+1]){
            int buffer = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = buffer;
            result = 1;
        }
    }
    return result;
}


int main()
{
    int vet[] = {1,2,5,9,3,6,4};

    printf("Vetor Inicial:");
    int i;
    for(i=0;i < (sizeof(vet)/4); ++i){
        printf(" %d",vet[i]);
    }
    
    while(bubble_sort(vet,sizeof(vet)/4));
    
    printf("\nVetor ordenado:");
    for(i=0;i < (sizeof(vet)/4); ++i){
        printf(" %d",vet[i]);
    }
    
    return 0;
}
