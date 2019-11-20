#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE * f = fopen("test.csv","r+");
    
    int c;
    char str[100];

    int vet[5] = {0}, i;

    if(!f){
        printf("Falha ao abrir arquivo csv");
        printf("\nCriando arquivo csv");
        f = fopen("test.csv","w");
        fputs("Dia/Mes/Ano\r\n",f);

        for(i = 0;i < 5;++i){
            fprintf(f," %d / %d / %d \n",vet[i]+i,vet[i]+i,vet[i]+i);
        }
    }
    i=0;
    while((fscanf(f,"%c",&c)) != EOF){
        
        printf("%c",c);
        ++i;
    }
    fclose(f);
    
}