#include <stdio.h>
int main(void){
	int fMatriz[5][4], sMatriz[4][3],resultante[5][3];
	int linhaAux, colunaAux, valor, count = 4;

	for(linhaAux = 0; linhaAux < 5;linhaAux++)
	{
		for(colunaAux = 0; colunaAux < 4; colunaAux++)
		{
			printf("Digite o elemento matriz[%d][%d] da primeira matriz  (5x4)\n",linhaAux,colunaAux);	
			scanf("%d",&fMatriz[linhaAux][colunaAux]);
		}
		
	}

	for(linhaAux = 0; linhaAux < 4;linhaAux++)
	{
		for(colunaAux = 0; colunaAux < 3; colunaAux++)
		{
			printf("Digite o elemento matriz[%d][%d] da segunda matriz  (4x3)\n",linhaAux,colunaAux);	
			scanf("%d",&sMatriz[linhaAux][colunaAux]);
		}
	}

	printf("\n\n");
	
	for(linhaAux = 0; linhaAux < 5;linhaAux++)
	{
		for(colunaAux = 0; colunaAux < 3; colunaAux++ )
		{
			valor = 0;
			for(count = 0; count < 4; count++)
			{
				valor += fMatriz[linhaAux][count] * sMatriz[count][colunaAux];
			}
			resultante[linhaAux][colunaAux] = valor;
			printf(" %d ",resultante[linhaAux][colunaAux]);
		}
		printf("\n");
	}

	prinf("\n\n");

	return 0;
}