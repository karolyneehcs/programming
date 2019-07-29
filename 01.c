#include <stdio.h>
#include <stdlib.h>

int main(){
	int A[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}; 
	int B[25] = {26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
	int C[50];
	int key, i, finder = 0; 


	for(i = 0; i < 25; i++){
		C[i] = A[i]; 
		C[i+25] = B[i];
	}

	printf("insira um numero a ser pesquisado\n"); 
	scanf("%d",&key); 


	for(i = 0; i < 50; i++){
		if(C[i] == key){
			finder = 1; 
		}
		else{
			finder = -1; 
		}
	}
	
	if(finder == 1)
		printf("Número não encontrado pela busca\n"); 
	else if( finder == -1)
		printf("Número encontrado com sucesso!\n"); 

	return 0;
}