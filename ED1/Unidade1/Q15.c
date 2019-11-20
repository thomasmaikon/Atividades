#include <stdio.h>

int main(){
	int entrada;
	printf("Digite um numero:");
	scanf("%d",&entrada);


	switch (entrada){
	case 1:
		printf("Um");
		 break;
	case 2:
		printf("Dois");
		 break;
	case 3:
		printf("Tres");
		 break;
	case 4:
		printf("Quatro");
		 break;
	case 5:
		printf("Cinco");
		 break;
	default:
		printf("Numero invalido.");
	}
}
