#include <stdio.h>

int main(){
	int entrada;

	printf("Digite um numero inteiro:");
	scanf("%d",&entrada);

	if(entrada%2 == 0){
		printf("O numero digitado e par");
	}else{
		printf("O numero digitado e impar");
	}
}
