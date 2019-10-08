#include <stdio.h>
#include <stdlib.h>

typedef struct {
        char nome[100];
        int idade;
        float peso;
        char sexo;
        float altura;
        float IMC; 
}tPessoa;

int main(){
    int quantity;
    
    printf("Informe a quantidade de pessoas:");
        scanf("%d",&quantity);

    tPessoa* pessoas = (tPessoa*) malloc(quantity * sizeof(pessoas));

    int indice;

    for(indice = 0; indice < quantity; ++indice){
        getchar();
        printf("Informe o Nome da pessoa[%d]",indice+1);
            fgets(pessoas[indice].nome,100,stdin);
        printf("Informe sua idade:");
            scanf("%d",&pessoas[indice].idade);
        printf("Informe seu peso:");
            scanf("%f",&pessoas[indice].peso);
        printf("Informe seu Sexo (F ou M):");
            getchar();
            scanf("%c",&pessoas[indice].sexo);
        printf("Informe sua altura:");
            scanf("%f",&pessoas[indice].altura);
            pessoas[indice].IMC =  (pessoas[indice].peso / (pessoas[indice].altura*pessoas[indice].altura));
    }
    printf("Resultado da pesquisa:");
    
    for(indice=0;indice < quantity; ++indice){
        printf("\nO IMC de %s: %f ",pessoas[indice].nome, pessoas[indice].IMC);

    }
//Tirar duvida com o Professor: https://stackoverflow.com/questions/6187908/is-it-possible-to-dynamically-define-a-struct-in-c

}