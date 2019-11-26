#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 30

typedef struct{
    int valor;
    char letra;
}tDado;

typedef struct{
    tDado dado[size];
    int posicao;
}tElement;

void AddValor(tElement* element,int valor){
    if(element->posicao < size){
        element->posicao+=1;
        element->dado[element->posicao].valor = valor;
    }
}
void Add(tElement* element, int valor,char letra){
    if(element->posicao < size){
        element->posicao+=1;
        element->dado[element->posicao].valor = valor;
        element->dado[element->posicao].letra = letra;
    }
}

void Remove(tElement* element){
    if(element->posicao > -1){
        element->posicao -=1;
    }
}


int main(){
    tElement element;
    element.posicao = -1;
    char funcao[size];

    char letras[size];
    int valores[size];
    int i,valor;
    printf("Entre com uma notacao:");
    fgets(funcao,size,stdin);

    for(i=0;funcao[i]!='\n';++i){
        if(funcao[i]!= '*' && funcao[i]!= '/' && funcao[i]!= '+' && funcao[i]!= '-'){
            printf("Defina o valor de:%c -> ",funcao[i]);
            scanf("%d",&valor);
            valores[i] = valor;
            letras[i] = funcao[i];
        }
    }
    int qtd=0;
    for(i=0;funcao[i]!='\n';++i){
        if(funcao[i]!= '*' && funcao[i]!= '/' && funcao[i]!= '+' && funcao[i]!= '-'){
            Add(&element,valores[i],letras[i]);
            qtd+=1;
        }else{
        switch(funcao[i]){
            case '*':
            {
                int mult = 1;
                printf("\nMultiplicando:\n");
                
                while(element.posicao > -1){
                    mult = mult * element.dado[element.posicao].valor;
                   // printf(" %c -> ",element.dado[element.posicao].letra);
                   // printf("%d\n",element.dado[element.posicao].valor);
                    Remove(&element);
                }
                AddValor(&element,mult);
                printf(" \nResultado = %d",element.dado[element.posicao].valor);
            }break;
            case'/':
            {
                int div = 1;  
                printf("\nDividindo:\n");
                
                while(element.posicao > -1){
                    div =  element.dado[element.posicao].valor / div;
                    printf(" %c -> ",element.dado[element.posicao].letra);
                    printf("%d\n",element.dado[element.posicao].valor);
                    Remove(&element);
                }
                AddValor(&element,div);
                printf(" \nResultado = %d",element.dado[element.posicao].valor);
            }break;

            case'+':
            {
                int sum = 0;
               for(sum;qtd >= 1;--qtd){
                    sum =  element.dado[element.posicao].valor + sum;
                   //printf(" %c -> ",element.dado[element.posicao].letra);
                   //printf("%d\n",element.dado[element.posicao].valor);
                    Remove(&element);
                }
                AddValor(&element,sum);
                printf(" \nResultado = %d",element.dado[element.posicao].valor);
            }break;
            
            case '-':{
						int subtrai=0, i = -1;
						for(qtd,subtrai;qtd>=1;--qtd){
							subtrai +=  (element.dado[element.posicao].valor * i);
							i = i * i;
							Remove(&element);
						}
						AddValor(&element,subtrai);
						printf("\n subtrai:%d",element.dado[element.posicao].valor);
					}
					 break;

        }
    }
    }
    
}