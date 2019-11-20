#include <stdio.h>

#define  refri 1.5
#define fatia 3.0
#define garcom 0.1
int main(){
    
    int pessoas, refrigerante, fatias;
    
    printf("Digite a quantidade de Refrigerante:");
    scanf("%d",&refrigerante);
    
    printf("Digite a quantidade de Fatias:");
    scanf("%d",&fatias);
    
    printf("Digite a quantidade de Pessoas:");
    scanf("%d",&pessoas);
    
    double total = refri*refrigerante + fatias*fatia ;
    
    printf("Valor total: %lf",total*1.1 );
    printf("\nValor total sem os 10%: %lf",total);
    printf("\nCusto por pessoa: %lf",total/pessoas);
}
