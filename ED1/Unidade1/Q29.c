#include <stdio.h>

int maior(int vet[], int tamanho);
int menor(int vet[],int size);
int main(){

	int vet[] = {-9,2,10,200,5};
	int index;
	printf("O vetor e [");

	for(index = 0;index < sizeof(vet)/4;++index){
		printf("%d ",vet[index]);
	}

	printf("]\nO maior elemento do vetor e:[%d]",maior(vet,sizeof(vet)/4));
	printf("\nO menor elemento do vetor e:[%d]",menor(vet,sizeof(vet)/4));
}

int maior(int vet[],int tamanho){
	int maior = 0, index=0;
	for(index;index < tamanho; ++index){
		if(maior < vet[index]){
			maior = vet[index];
		}
	}
	return maior;
}

int menor(int vet[],int size){
	int menor=0,index=0;
	for(index;index<size;++index){
		if(menor > vet[index]){
			menor = vet[index];
		}
	}
return menor;
}
