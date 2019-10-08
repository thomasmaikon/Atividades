#include <stdio.h>
#include <stdlib.h>
int main(){

	int i=0;
	int quantidade;

	printf("Informe o numero de elementos do seu vetor");
		scanf("%d",&quantidade);

	int * vet = (int*)malloc(quantidade * sizeof(int)); // criando vetor dinamicamente alocado

	printf("Informe todos os elementos do vetor:");
	for(i;i<quantidade;++i){
		printf("informe o elemento %d da lista",i+1);
		scanf("%d",&vet[i]);
	}
	i=0;
	printf("O vetor e:");
	for(i;i<quantidade;++i){
		printf("%d",vet[i]);
	}
}
