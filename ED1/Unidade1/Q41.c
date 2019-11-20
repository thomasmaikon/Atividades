#include <stdio.h>
#include <time.h>

int recursividade(int x, int y, int z){
    while(x < y){
        z = x + recursividade(x+1,y,z);
        
    }
    return z;
}

int main(){

    int x,y,z;
    printf("Informe dois numeros:");
    scanf("%d",&x);
    scanf("%d",&y);

clock_t time[2];
    time[0] = clock();
    while(x <y){
        z = x+x+1;
        ++x;
    }
    time[1] = clock();

    clock_t time2[2];
    double Tempo = (time[1] - time[0]) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("O valor da soma :%d O tempo demorado foi de:%lf",z,Tempo);
int k;
    time[0] = clock();
     k = recursividade(x,y,z);
    time2[1]= clock();
    
    double Tempo2 = (time2[0] - time2[1]) * 1000.0 / CLOCKS_PER_SEC;
    printf("\nO valor com recursividade: %d O tempo demorado foi de: %lf",k,Tempo2);
}