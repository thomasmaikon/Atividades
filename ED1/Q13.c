#include <stdio.h>

int main(){
	float n1,n2,n3;
	n1 = 9;
	n2 = 9;
	n3 = 5;

	if((n1+n2+n3)/3 < 7){
		printf("Aluno em recuperacao");
	}else{
		printf("O aluno foi aprovado com Media: %f",(n1+n2+n3)/3);
	}

}
