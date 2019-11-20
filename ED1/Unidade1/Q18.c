#include <stdio.h>

int main(){
	int inicio, fim;

	printf("Utilizando o While \nDigite dois numeros Inicio e Fim\n");
		scanf("%d",&inicio);
		scanf("%d",&fim);

	while(inicio <= fim){
		if(inicio%2 != 0){
			printf(" %d ",inicio);
		}

		inicio+=1;
	}

	printf("\nUtilizando Do While\n Digite dois Numeros Inicio e Fim\n");
		scanf("%d",&inicio);
		scanf("%d",&fim);

		inicio -=1;
	do{
		inicio+=1;

		if(inicio %2 != 0){
			printf(" %d ",inicio);
		}

	}while(inicio <fim);

	printf("\n Utilizando For\n Digite dois numeros Inicio e Fim\n");
		scanf("%d",&inicio);
		scanf("%d",&fim);

	for(inicio;inicio <= fim;++inicio){
		if(inicio%2 != 0)
			printf(" %d ",inicio);
	}
}

