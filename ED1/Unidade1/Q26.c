#include <stdio.h>

int main(){
	int mat[2][2];
	int i = 0;
	int j = 0;
	printf("Preencha os elementos da matriz:");

	for(i;i<2;++i){
		for(j;j<2;++j){
			printf("posicao da matriz: mat[%d][%d]\ninforme o valor:",i,j);
			scanf("%d",&mat[i][j]);
		}
		j=0;
	}

	j=0;
	i=0;

	printf("Exibindo a matriz\n");

	for(i;i<2;++i){
		for(j;j<2;++j){
		printf("[%d]",mat[i][j]);
		}
	j=0;
	printf("\n");

	}
}
