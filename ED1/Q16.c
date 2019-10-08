#include <stdio.h>
#include <math.h>

float delta(float b,float a,float c);
void raizes(float b,float a,float raiz);

int main(){

	float a,b,c;
	a = 3;
	b = 6;
	c = 1;

	printf("O valor de delta e:%lf",delta(b,a,c));
	float raiz =  delta(b,a,c);
	raizes(b,a,raiz);
}

float delta(float b,float a,float c){
	float delta = (b*b) - 4*a*c;
	return delta;
}

void raizes(float b,float a,float raiz){

	printf("\nPara X1:%lf",(-b+raiz)/2*a);
	printf("\nPara X2:%lf",(-b-raiz )/2*a);
}
