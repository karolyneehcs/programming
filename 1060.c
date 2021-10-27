#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double valores[6];
    int positivos, contador;

    for (contador=0;contador<6;contador++) {
        scanf("%lf", &valores[contador]);
    }

    for (contador=0;contador<6;contador++) {
        if (valores[contador] > 0) {
            positivos++;
        }
    }

    printf("%d valores positivos\n", positivos);
    
    return 0;
}