#include <stdio.h>

int main(){
	float conta1 = 100;

	float entrada;

	float conta2 = 0;

	printf("Digite o quanto deseja transferir da conta1 para a conta2:");
	scanf("%f",&entrada);

	if(entrada <= conta1){
		conta1 = conta1 - entrada;
		conta2 = entrada;
		printf(" transferencia realizada com sucesso\n Saldo conta1: %f \n Saldo conta2: %f",conta1,conta2);

	}else{
		printf("Saldo insuficiente, tente novamente mais tade.");
	}
}
