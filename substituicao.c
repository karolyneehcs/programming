#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char palavra[30];
  char sub, res;
  int aux = 0;
  printf("Insira a palavra desejada:");
  scanf("%s", &palavra);
  printf("Insira a letra:");
  scanf("%c", &sub);
  printf("Insira a segunda letra:");
  scanf("%c", &res);

  for(int i=0; i < 30; i++) {
    if(palavra[i]==sub){
      palavra[i] = res;
      aux+=1
    } else {
      continue;
    }

    if(aux == 0)
       print("Nao foi encontrado nenhuma letra equivalente")
   
  return 0;
}
