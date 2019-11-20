#include <stdio.h>
#define size 30
#define Erro 0
#define SuccessFull 1

typedef struct{
	int pilha[size];
}tPilha;

typedef struct{
	tPilha pilha;
	int posicao;
}tPoint;

void Inity(tPoint* point){
	point->posicao = -1;
}

int Add(tPoint* point, char element){
	if(point->posicao == size){
		return Erro;
	}
	point->posicao += 1;
	point->pilha.pilha[point->posicao] = element;
	return SuccessFull;
}

int Remove(tPoint* point){
	if(point->posicao == -1){
		return Erro;
	}
	point->posicao -=1;
	return SuccessFull;
}

int main(){
	tPoint point;
	Inity(&point);

	char str[size];
	int  valores[size];
	int  i,valor, qtd = 0;

	printf("Informe a equacao na forma posfixa:");
	fgets(str,size,stdin);

	for(i=0;str[i] != '\n';++i){
		if(str[i] != '*' && str[i] != '/' && str[i] != '+' && str[i] != '-'){
			printf("Defina o valor de sua variavel [%c]:",str[i]);
			scanf("%i",&valor);
			valores[i] = valor;
		}
	}



	for(i=0; str[i]!='\n';++i){
		if(str[i] != '*' && str[i] != '/' && str[i] != '+' && str[i] != '-'){
			Add(&point, valores[i]);
			qtd+=1;
		}else{
			switch(str[i]){
				case '+':
                    {
						int soma = 0;
						for(qtd,soma;qtd >= 1; --qtd){
							soma += point.pilha.pilha[point.posicao];
                            Remove(&point);
						}
						Add(&point,soma);
						printf("\n soma:%d",point.pilha.pilha[point.posicao]);
					}
					break;

				case '-':{
						int subtrai=0, i = -1;
						for(qtd,subtrai;qtd>=1;--qtd){
							subtrai +=  (point.pilha.pilha[point.posicao] * i);
							i = i * i;
							Remove(&point);
						}
						Add(&point,subtrai);
						printf("\n subtrai:%d",point.pilha.pilha[point.posicao]);
					}
					 break;

				case '*':{
						int multiplica = 1 ;
						for(multiplica;point.posicao!=-1;Remove(&point)){
							multiplica *= point.pilha.pilha[point.posicao];
					 	}
						Add(&point,multiplica);
						printf("\n multiplica:%d",point.pilha.pilha[point.posicao]);
					}
					break;
				case '/':{
						int divide ;
						int cont;
						for(divide,cont=0;point.posicao!= -1;Remove(&point),++cont){
							if(cont >=1){
								divide =  point.pilha.pilha[point.posicao] / divide ;
							}else{
								divide = point.pilha.pilha[point.posicao];
							}
						}
						Add(&point,divide);
						printf("\n divide:%d",point.pilha.pilha[point.posicao]);
					}
					break;
			}
		}
	}

	printf("Resultado Final:%d",point.pilha.pilha[point.posicao]);

}
