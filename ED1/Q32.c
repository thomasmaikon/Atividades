#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    int ind;

    printf("Digite uma frase:");
        fgets(str,99,stdin);
    

    printf("\nFrase invertida: ");    
    char* array = (char*)malloc((strlen(str)-1) * sizeof(char));
    
    for(ind = 0; ind < strlen(str); ++ind){
        array[ind] = str[ind];
    }
    
    printf("\n Deu Certo \n A string no array: %s",array);
}