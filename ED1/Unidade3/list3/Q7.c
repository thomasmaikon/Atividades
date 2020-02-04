
#include <stdio.h>


int insert_sort(int vet[],int size){
    int i, result = 0;
    for(i = 0; i< size-1; ++i){
       
        if(vet[i] > vet[i+1]){
            int buffer = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = buffer;
    
        int j;
        for(j = i; j > 0 ;--j){
                
            if(vet[j] > vet[j-1]){
                int buffer2 = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = buffer2;
            }    
            
        }
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
    
    while(insert_sort(vet,sizeof(vet)/4));
    
    printf("\nVetor ordenado:");
    for(i=0;i < (sizeof(vet)/4); ++i){
        printf(" %d",vet[i]);
    }
    
    return 0;
}

