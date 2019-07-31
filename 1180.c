#include<stdio.h> 
#include<stdlib.h>
#define MAX 1000

int main(){
	int vetor[MAX]; 
	int N, i, min, max, p; 

	scanf("%d",&N); 

	for(i = 0; i < N; i++){
		scanf("%d",&vetor[i]);
	}

	min = vetor[0];

	for(i = 1; i < N; i++){
		if(vetor[i] < min){
			min = vetor[i]; 
			p = i; 
		} 
	}

	printf("Menor valor: %d\nPosicao: %d",min,p);
}