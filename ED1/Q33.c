#include <stdio.h>

int main(){

    typedef struct{
        char nome[100];
        int idade;
        float peso;
        char sexo;
        float altura;
        float IMC; 
    } p;

    p pessoa[3];
    int indice;

    for(indice = 0; indice < 3; ++indice){
        printf("Informe o Nome da pessoa[%d]",indice+1);
            fgets(pessoa[indice].nome,100,stdin);
        printf("Informe sua idade:");
            scanf("%d",&pessoa[indice].idade);
        printf("Informe seu peso:");
            scanf("%f",&pessoa[indice].peso);
        printf("Informe seu Sexo (F ou M):");
            getchar();
            scanf("%c",&pessoa[indice].sexo);
        printf("Informe sua altura:");
            scanf("%f",&pessoa[indice].altura);
            pessoa[indice].IMC =  (pessoa[indice].peso / (pessoa[indice].altura*pessoa[indice].altura));
            getchar();
    }
    printf("Resultado da pesquisa:");
    
    for(indice=0;indice < 3; ++indice){
        printf("\nO IMC de %s = %f ",pessoa[indice].nome, pessoa[indice].IMC);

    }

}