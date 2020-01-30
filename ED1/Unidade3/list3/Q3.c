#include <stdio.h>
#include <stdlib.h>

int main(){
 
    int vet[] = {1,2,3,4,5,6,7};
 
    int start = 0;
    int end = (sizeof(vet)/4);
    int result = -1;

    
    int valor_desejado = 7;
    int meio = end/2;
    
    while(start<=end){
        
        if( start == end ){
            printf("\nAcabou");
            break;
        }else if(vet[meio] == valor_desejado){
            printf("\nA posicao e:%d",meio);
            break;
        }else if(vet[meio] > valor_desejado){
            meio = meio -1;
        }else{
            meio = meio +1;
        }
    }
    
}