#include <stdio.h>
#include <string.h>

int confere(char senha[], char input[]);
int confere2(char senha[], char input[]);

int main(){
	char senha[100] = "incorreta";
	char setInput[100];

	printf("Digite a senha:");
		scanf("%s",setInput);
	if(confere(senha,setInput)){
		if(confere2(senha,setInput))
		printf("Login realizado com sucesso");
	}
}

int confere(char senha[], char input[]){

	int i        =             0;
	int tamSenha = strlen(senha);
	int tamInput = strlen(input);

	if (tamSenha != tamInput){
		return 0;
	}else{
		while(i <= tamSenha){
			if(senha[i] == input[i]){

			}else{
			return 0;
			}
		++i;
		}
	}
return 1;
}

int confere2(char senha[],char input[]){
	
	int i        =             0;
	int tamSenha = strlen(senha);
	int tamInput = strlen(input);

	if (tamSenha != tamInput){
		return 0;
	}else{
		do{
			if(senha[i] == input[i]){
			}else{
				return 0;
			}
		++i;
		}while(i<=tamSenha);
	}
return 1;
}
