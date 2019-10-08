#include <stdio.h>


int main(){
	int vet[] = {1,2,3,4,5,6,7,8,9,10};
	int index=0, cache=0;

	printf("O vetor inicial [");

	for(index = 0;index < sizeof(vet)/4;++index){
		printf("%d ",vet[index]);
	}

	printf("]\n");

	for(index = 0;index < (sizeof(vet)/4)/2;++index){
		cache = vet[index];
		vet[index] = vet[9-index];
        vet[9-index] = cache;
	}
	printf("Invertendo: ");
	for(index = 0;index < 10; ++index){
        printf(" %d ",vet[index]);
    }
}
