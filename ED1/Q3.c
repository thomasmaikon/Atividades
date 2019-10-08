#include <stdio.h>
#include <stdlib.h>
void flush_in();

int main(){

    int idade;
    float altura;
    char letra;
    char bff;
    char nome[100];

    printf("\nDigiste sua idade:");
    scanf("%d",&idade);

    printf("\nDigite sual altura:");
    scanf("%f",&altura);

    setbuf(stdin,NULL);

    printf("\nInforme a primeira letra do seu nome:");
	scanf("%c",&letra);


	getchar();

    printf("\nInforme seu nome completo:");
	    fgets(nome,100,stdin);

    printf("\n idade:%d \n altura:%f \n letra:%c \n nome:%s",idade,altura,bff,nome);
}
