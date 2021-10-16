#include<stdio.h>
#include<stdlib.h>

void numeroPerfeito(int n);

int main() {
	int numero;
	printf("Qual o número que você gostaria de verificar? \n");
	scanf("%d",&numero);
	int resultado = numeroPerfeito(numero);
	return 0;
}

void numeroPerfeito(int n) {
	int resto, soma;
	for(int i = 1; i < (numero-1); i++) {
		resto = numero % i;
		if(resto == 0)
			soma += i;
		else
			continue;
	}
	if(soma == n)
		print("É um número perfeito!");
	else
		print("Não é um número perfeito");
}
