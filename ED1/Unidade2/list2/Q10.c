#include<stdio.h>
#define size 30

typedef struct{
    char letra;
}tDado;
typedef struct{
    tDado dado[size];
    int posicao;
}tPilha;

void inity(tPilha* pilha){
    pilha->posicao = -1;
}

void Add(tPilha* element,char c){
    if(element->posicao < size){
        element->posicao+=1;
        element->dado[element->posicao].letra = c;
    }
}

void Remove(tPilha* element){
	if(element->posicao > -1){
		element->posicao -= 1;
	}
}


int main(){
	tPilha element;

	inity(&element);
	int i,j;

	char equacao[size];
	char result[size];
	
	printf("Digite a Equacao:");
	fgets(equacao,size,stdin);

	for(i=0,j=0;equacao[i]!='\n';++i){
		if(equacao[i] == '*' || equacao[i] == '/'){
			Add(&element,equacao[i]);
		}else if(equacao[i] == '+'||equacao[i] == '-'){
			if(element.dado[element.posicao].letra == '*' ||element.dado[element.posicao].letra == '/'){
				result[j] = element.dado[element.posicao].letra;
				Remove(&element);
				++j;
			}
			Add(&element, equacao[i]);
		}else if(equacao[i] == '('){
			Add(&element,equacao[i]);
		}else if(equacao[i] == ')'){
			
			while(element.dado[element.posicao].letra != '('){
				result[j] = element.dado[element.posicao].letra;
				Remove(&element);
				++j;
			}
				Remove(&element);
			while(element.posicao >= 0){
				result[j] = element.dado[element.posicao].letra;
				Remove(&element);
				++j;
			}
		}else{
			result[j] = equacao[i];
			++j;
		}
	}

	while(element.posicao > -1){
		result[j] = element.dado[element.posicao].letra;
		Remove(&element);
		++j;
	}
	printf("%s",result);

}
