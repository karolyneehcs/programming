#include<stdio.h> 
#include<stdlib.h> 
#define TAM_MAX 30
void insertionSort(int array[], int tamanho); 
int BinarySearch(int k[], int chave, int length); 

int main(){
	int vetor[TAM_MAX]; 
	int i, key; 
	int comeco = 0; 
	int fim = TAM_MAX-1; 
	int meio = (fim + comeco)/2; 
	

	for(i = 0; i < TAM_MAX; i++){
		printf("insira o numero da posicao %d\n", i+1); 
		scanf("%d",&vetor[i]); 
		if(vetor[i]%2 == 0)
			vetor[i] = vetor[i]*2; 
		else 
			vetor[i] = vetor[i]*5; 
	}

	printf("insira o numero a ser pesquisado\n"); 
	scanf("%d", &key);


	insertionSort(vetor, TAM_MAX); 

	int a = BinarySearch(vetor, key, TAM_MAX); 

	if(a == -1)
		printf("O número desejado não foi encontrado\n"); 
	else
		printf("O número desejado foi encontrado com sucesso\n");

	return 0;

}

void insertionSort(int array[], int tamanho) {
      int i, j, tmp;
      for (i = 1; i < tamanho; i++) {
            j = i;
            while (j > 0 && array[j - 1] > array[j]) {
                  tmp = array[j];
                  array[j] = array[j - 1];
                  array[j - 1] = tmp;
                  j--;
            }
      }
}

int BinarySearch (int k[], int chave , int length)
{
 int inf,sup,meio;
 inf=0;
 sup=length-1;
 while (inf<=sup)
 {
      meio=(inf+sup)/2;
      if (chave==k[meio])
           return meio;
      else if (chave<k[meio])
           sup=meio-1;
      else
           inf=meio+1;
 }
 return -1;   /* não encontrado */
}