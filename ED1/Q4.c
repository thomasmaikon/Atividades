#include <stdio.h>

int main(){

    float n1,n2;
    
    printf("Olá, Digite 2 numeros:");
    scanf("%f",&n1);
    scanf("%f",&n2);
    
        printf("%f + %f = %lf",n1,n2,n1+n2);
        printf("\n%f - %f = %lf",n1,n2,n1-n2);
        printf("\n%f * %f = %lf",n1,n2,n1*n2);
        printf("\n%f / %f = %lf",n1,n2,n1/n2);
        printf("\n%f % %f = %lf ",n1,n2,n1%n2);
}
