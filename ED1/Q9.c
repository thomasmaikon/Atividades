#include <stdio.h>

int main(){
    float peso, altura;
    
    printf("Informe o seu peso e altura respectivamente:");
    scanf("%f",&peso);
    scanf("%f",&altura);
    
    printf("O seu imc e de:%lf",peso/(altura*altura));
}
