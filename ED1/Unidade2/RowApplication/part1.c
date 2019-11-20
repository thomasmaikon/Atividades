#include <stdio.h>
#include <stdlib.h>

#define Rota 2
#define size 6

typedef struct{
	int id;
	int rota[Rota];
	int DistRota[Rota];
}tCidade;
typedef struct{
	int total;
	int inicio, fim;
	tCidade cidade[size];
}tPointer;

void Inity(tPointer* point){
	point->inicio = -1;
	point->fim = -1;
}

void setCidade(int** vet,int cidade,tPointer* point){
	int i;
	int posicao=0;

	for(i=0;i<Rota;++i){
		point->cidade[point->fim].rota[i] = -1;
		point->cidade[point->fim].DistRota[i] = -1;
	}
	for(i=0,posicao=0;i<size;++i){
			point->cidade[point->fim].id = cidade;
		if(vet[cidade][i] > 0){
			point->cidade[point->fim].rota[posicao] = i;
			point->cidade[point->fim].DistRota[posicao] = vet[cidade][i];
			++posicao;
		}
	}
}

void Add(tPointer* point, int cidade, int** vet){
	int i;
	if(point->inicio == -1){
		point->inicio = 0;
		point->total = 0;
	}
	point->fim +=1;
	setCidade(vet,cidade,point);
}
void  Remove(tPointer* point){
	if(point->inicio == -1){

	}else{
		point->inicio +=1;
	}
}
int Cidade(){
	int cidade;

		printf("Informe no numero da cidade: ");
		scanf("%d",&cidade);

	return cidade;
}


int NextCity(tPointer* point){
	int cidade = -1,i;
	for(i=0;i<Rota;++i){
		if(point->cidade[point->fim].rota[i] >= 0){
			printf("\nvalor: %d",point->cidade[point->fim].rota[i]);
			cidade = point->cidade[point->fim].rota[i];
		}
	}

	return cidade;
}
void Distancia(tPointer* point,int atual,int proxima){
	int i, cidadeEscolhida=0;

	for(i=0;i<Rota;++i){
		if(point->cidade[point->fim].rota[i] == proxima){
			 cidadeEscolhida = i;
		}
	}

	if(atual!=proxima){
		point->total += point->cidade[point->fim].DistRota[cidadeEscolhida];
	}else{
		point->total += 0;
	}
}
int Destino(){
	printf("Digite o ponto de chegada:");
	int chegada;
	scanf("%d",&chegada);
	return chegada;
}


int main(){
	tPointer point;
	Inity(&point);
	int cidade = Cidade();
	int** vetCidade = (int**)calloc(size,sizeof(int*));

//Inicializa o vetor com as posicoes
	int i;
	for(i=0;i<size;++i){
		vetCidade[i] = (int*)calloc(size,sizeof(int));
			if(i == 0){
				vetCidade[i][1] = 3;
			}else if(i == 1){
				vetCidade[i][2] = 1;
			}else if(i == 2){
				vetCidade[i][4] = 1;
			}else if(i == 3){
				vetCidade[i][2] = 2;
				vetCidade[i][4] = 1;
			}else if(i == 4){
				vetCidade[i][0] = 1;
			}else if(i == 5){
				vetCidade[i][1] = 1;
			}
	}
// Finaliza vetor
int next;
int chegada = Destino();
	for(i=0;cidade != chegada;++i){
		Add(&point,cidade,vetCidade);
		printf("\nCidade atual:%d",point.cidade[point.fim].id);
		next = NextCity(&point);
		printf("\nProxima Cidade :%d",next);
		Distancia(&point,cidade,next);
		printf("\nDistancia %d",point.total);
		cidade = next;
	printf("\n======Proxima parada=======");
	}
}
