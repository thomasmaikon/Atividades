#include <stdio.h>

int main(){
	int vet[10];
	int i=0;

	printf("Informe todos os elementos do vetor:");
	for(i;i<10;++i){
		printf("informe o elemento %d da lista",i+1);
		scanf("%d",&vet[i]);
	}
	i=0;
	printf("O vetor e:");
	for(i;i<sizeof(vet)/4;++i){
		printf("%d",vet[i]);
	}
}
