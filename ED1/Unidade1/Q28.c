#include <stdio.h>

void invert(int vet[],int tamanho);

int main(){
	int vet[] = {1,2,3,4};

	printf("O vetor na forma inicial:[");
	int index;

	for(index = 0;index < sizeof(vet)/4;++index){
		printf("%d ",vet[index]);
	}
	printf("]\n Vetor Invertido:");

	invert(vet,sizeof(vet)/4);
}

void invert(int vet[], int tamanho){
	int index = tamanho - 1;
	for(index;index >= 0; --index){
		printf(" %d ",vet[index]);
	}
}
