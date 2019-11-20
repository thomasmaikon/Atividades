#include <stdio.h>

int fatorial(int numero);

int main(){
	int numero;
	printf("Digite o numero que queira o fatorial:");
	scanf("%d",&numero);

	printf("O fatorial e:%d",fatorial(numero));
}

int fatorial(int numero){
	if(numero == 1){
		return numero;
	}else{
		return numero * fatorial(numero-1);
	}

}
