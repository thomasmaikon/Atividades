#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[100];
    int ind;

    printf("Digite uma frase:");
        fgets(str,99,stdin);
    

    printf("\nFrase invertida: ");    

    for(ind = strlen(str)-1; ind >=0; --ind){
        printf("%c",str[ind]);
    }
}