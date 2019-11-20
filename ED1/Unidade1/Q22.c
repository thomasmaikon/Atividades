#include <stdio.h>

int primo(int numero);

int main()
{
	int numero;

	printf("Digite um numero:");
	scanf("%d",&numero);

	if(primo(numero))
    {
        printf("\n O numero e primo");
    }else
    {
        printf("\n O numero nao e primo");
    }
    
}

int primo(int numero)
{
    int inicio;
    for(inicio = 2; inicio < numero;++inicio)
    {
        if(numero % inicio == 0){
            return 0;
        }
    }
    return 1;
}
