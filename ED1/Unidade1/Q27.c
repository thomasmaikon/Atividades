#include <stdio.h>
#include <stdlib.h>

int main()
{

    int posicaoY,posicaoX;
    int recebe,index,indey;
	
    printf("Informe o tamanho da matriz posicaoY e posicaoX:");
    
    printf("\nquantidade de colunas:");
        scanf("%d",&posicaoY);
    printf("\nquantidade de linhas:");
        scanf("%d",&posicaoX);
    
    int** mat = (int **) malloc(posicaoX * sizeof(int *)); /* faco um ponteiro de pointeiro ter o total de posicaoX que meu vetor precisa*/
    
    for(index = 0;index < posicaoX; ++index){
        mat[index] = (int *) malloc(posicaoY * sizeof(int)); /* converto cada celula que antes eu tinha no meu ponteiro de pointeiros em um vetor, 
                                                                                        tendo assim um vetor bidimenssional (Desenhar ajuda a saber)*/
    }

    for(index=0;index< posicaoX;++index){
        for(indey=0;indey<posicaoY;++indey){
            printf("Preencha os elementos da matriz[%d][%d]:",index+1,indey+1);
                scanf("%d",&recebe);
                *(*(mat+index)+indey) = recebe; //mat[index][indey] = recebe;
        }
    }
    indey = 0;
    for(index = 0; index < posicaoX; ++index){
        for(indey = 0;indey< posicaoY;++indey){
            printf("[%d]" , mat[index][indey]);
        }
        printf("\n");
    }
    free(mat);
}
