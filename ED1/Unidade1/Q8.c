#include <stdio.h>

int main(){
    float n1,n2;
    
    printf("Digite dois numeros :");
    scanf("%f",&n1);
    scanf("%f",&n2);
    
    if(n2 == 0){
        printf("Nao foi possivel dividir pois o segundo numero e 0");
    }else{
        printf("A divisao e:%lf", n1/n2);
    }
}
