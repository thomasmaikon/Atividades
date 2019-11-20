#include <stdio.h>

int fat(int numero);

int main(){
    int numero;

    printf("Informe um numero");
    scanf("%d",&numero);
    int fatorial = fat(numero);
    printf("O fatorial de %d e : %d",numero,fatorial);
}

int fat(int numero){
    if(numero ==1){
        return numero;
    }else{

    return numero * fat(numero-1);
    }
}