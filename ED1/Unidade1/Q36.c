#include <stdio.h>
#include <stdlib.h>

typedef struct gambiarra{
    char letra;
    int qtd;
} gambiarra;

int main(){
    char str[100];
    int i=0,ascii=97,quantidade = 0,index = 0;

    printf("Digite uma frase:");
    fgets(str,100,stdin);

    gambiarra * bem = (gambiarra*)malloc(26*sizeof(gambiarra)); // so possiveis apenas 26 letras em nosso alfabeto
    for(i=0;i<26;++i){
        bem[i].letra = (char)ascii;
        bem[i].qtd = 0;
        ++ascii;
    }

    for(i=0;str[i] != '\0';++i){
        quantidade+=1;
    }

    for(index = 0; index < quantidade;++index){
        for(i=0; i< 26;++i){
            if(bem[i].letra == str[index]){
                bem[i].qtd +=1;
                break;
            }
        }
    }
    for(i=0; i <26;++i){
        if(bem[i].qtd >0){
            printf("\n%c tem %d",bem[i].letra,bem[i].qtd );
        }
    }
}
