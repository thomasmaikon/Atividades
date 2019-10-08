#include <stdio.h>

int main(){
	float n1,n2,n3;
	n1 = 9;
	n2 = 9;
	n3 = 5;

	float result = (n1+n2+n3)/3;
	
	switch (result){

	case result < 7 && result >= 3:
		printf("Voce foi para a recuperacao, media: %f\nVoce precisa tirar:%lf",result,final);
		break;
	case result < 3:
		printf("Infelizmente voce nao atingiu a pontuacao e foi reprovado.\n Media:%f",result);
		break;
	case result > 7:
		printf("Parabens voce foi aprovado com media de :%f",result);
	}

}
