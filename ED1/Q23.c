#include <stdio.h>
#include <math.h>

void exibe();
int fatorial(float numero);

int main(){
	int opcao;
	float numero = 0,numero2 = 0,result;

	do{

	exibe();
	scanf("%d",&opcao);

		switch(opcao){
			case 1:
				printf("Informe o numero que deseja como base:");
					scanf("%f",&numero);

				printf("Informe a potencializacao:");
					scanf("%f",&numero2);

				result = pow(numero,numero2);

				printf("\n O resultado e: %f ^ %f = %f",numero,numero2,result);

				break;
			case 2:
				printf("Informe o Numero que deseja saber a raiz quadrada:");
					scanf("%f",numero);
				result = sqrt(numero);
				printf("A raiz quadrada de %f e:%f",numero,result);
				break;
			case 3:
				printf("Informe O numero que deseja saber o fatorial: ");
					scanf("%f",numero);
				result = fatorial(numero);
				printf("O fatorial de %f e de:%f",numero, result);
				break;
		}

	}while(opcao != 0);
}

void exibe(){
	printf("\n1-Potencializacao\n2-Raiz quadrada\n3-Fatorial\n0-Sair\n==>_\b");
}

int fatorial(float numero){
	if (numero == 1){
		return numero;
	}else{
		return numero * fatorial(numero-1);
	}
}
