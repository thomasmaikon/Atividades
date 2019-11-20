#include <stdio.h>
#define size 30
#define Erro 0
#define SuccessFul 1

typedef struct{
	char pilha[size];
}tPilha;

typedef struct{
	tPilha pilha;
	int  posicao;
}tPoint;

void Inity(int* posicao){
	*posicao = -1;
}

int Add(tPoint* point, char element){
	if(point->pilha.pilha[point->posicao] == size){
		return Erro;
	}
	point->posicao += 1;
	point->pilha.pilha[point->posicao] = element;
	return SuccessFul;
}

int Remove(tPoint* point){
	if (point->posicao == -1){
		return Erro;
	}
	point->posicao -= 1;
	return SuccessFul;
}

int anterior(char str){
	if(str == '*' || str == '/'){
		return SuccessFul;
	}
	return Erro;
}



int main(){
	tPoint point;
	Inity(&point.posicao);

	char str[size], result[size];
	int i,j;

	printf("Digite a equacao:");
	fgets(str,size,stdin);


	for(i=0,j=0; str[i]!='\n';++i){
		if(str[i] == '*' || str[i] == '/'){
			Add(&point,str[i]);
		}else if(str[i] == '+' || str[i]== '-'){
			if(point.pilha.pilha[point.posicao] == '*' || point.pilha.pilha[point.posicao] == '/'){
				result[j] = point.pilha.pilha[point.posicao];
				Remove(&point);
				j+=1;
			}
			Add(&point,str[i]);
		}else if(str[i] == '('){
			Add(&point,str[i]);
		}else if(str[i] == ')'){

			while(point.pilha.pilha[point.posicao] != '('){
				result[j] = point.pilha.pilha[point.posicao];
				Remove(&point);
				j+=1;
			}

			Remove(&point); //remove '(' da pilha

			while(point.posicao != -1){
				result[j] = point.pilha.pilha[point.posicao];
				j+=1;
				Remove(&point);
			}
		}else{
			result[j] = str[i];
				j+=1;
		}
	}
	do{

	result[j] = point.pilha.pilha[point.posicao];
		j+=1;
		Remove(&point);
	result[j] = '\0';
	}while(point.posicao !=-1);

	printf("\n Resultado final: %s",result);



}
