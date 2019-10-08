#include <stdio.h>

int main(){

    float raio, comprimento;
    
    do{
    
    printf("Informe o valor do raio de um circulo:");
    scanf("%f",&raio);
    
    printf("Informe o comprimento do circulo:");
    scanf("%f",&comprimento);
    
    }while(raio < 0);
    

    printf("A area do circulo e de :%lf",comprimento* (raio*raio) );
}
