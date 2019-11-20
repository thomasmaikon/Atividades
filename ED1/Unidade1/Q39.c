#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palavra{
    char  str[100];
    int quantidade;
}Palavra;

int quantidadePalavras(char *vet,int size);
int quantidadeletras(char * vet, int size);

int main(){
    
    char c;
    char copia[100] = "";
    int i =0,index,j=0,posicao = 0,posicao_elemento =0;
    int tamanhoString=1;

    FILE * file = fopen("TEST.txt","r+");

    if(!file){
        printf("\n Nao existe arquivo txt");
        file = fopen("TEST.txt","w");
        fprintf(file,"OlA thomas nao passou aqui ainda, mas thomas vai ola passou OLA adnia testando");
        fclose(file);
        return 0;
    }
    printf("\nA string e:");

    while(fscanf(file,"%c",&c)!= EOF){
        ++tamanhoString;
        printf("%c",c);
    }
    
    char* str = (char *) calloc(tamanhoString,sizeof(char));
    
    fclose(file);
    file = fopen("TEST.txt","r");
    
    while(fscanf(file,"%c",&c)!= EOF){
        str[i] = c;
        ++i;
    }
    i = 0;
    int QTDpalavras = quantidadePalavras(str,sizeof(str));
    int QTDletras = quantidadeletras(str,sizeof(str)) -1;
    
    Palavra * palavras = (Palavra*) calloc(QTDpalavras,sizeof(Palavra));


    for(index=0;index<QTDpalavras;++index){
        while( str[i] != '\0' && str[i] !=' '){
            if(i<QTDletras){
               copia[j] = str[i];
                }
            ++i;
            ++j;
        }

        if(posicao_elemento == 0){ // se for o primeiro elemento ele simplesmente registra ele
               strcpy(palavras[posicao].str,copia);
               palavras[posicao].quantidade = 1;
               ++posicao_elemento;
        }else{
            for(posicao = 0;posicao<QTDpalavras;++posicao){
                if(!strcmp(palavras[posicao].str,copia)){
                    palavras[posicao].quantidade += 1;
                    break;
                }else if(!strcmp("",palavras[posicao+1].str)){ // so entra quando for o ultimo valor da posicao, o que significa que nao existe palavra registrada
                     strcpy(palavras[posicao+1].str,copia);
                     palavras[posicao+1].quantidade = 0;
                }
            }
        }
        j=0;
        while(j< 99){ // limpa meu vetor q copia as strings
            copia[j] = '\0';
            ++j;
        }
       ++i;
       j=0;
    }
    
    for(index = 0; index<QTDpalavras;++index){
        if(palavras[index].quantidade!= 0){
            printf("\n[%s] aparece %d vezes",palavras[index].str,palavras[index].quantidade);
        }
    }

}

int quantidadePalavras(char *vet,int size){
    int quantidade=1;
    int i=0;
    
    while(vet[i]!='\0'){
        if(vet[i+1] == ' '){
            if(vet[i+2] != ' ' && vet[i+2] != '\0' ){
                ++quantidade;
            }
        }
        ++i;
    }

    return quantidade;
}

int quantidadeletras(char * vet, int size){
    int quantidade =0;
    int i=0;
    while(vet[i] != '\0'){
        quantidade+=1;
        ++i;
    }
    return quantidade;
}