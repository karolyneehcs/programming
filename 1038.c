#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int item, quantidade;

    scanf("%d", &item);
    scanf("%d", &quantidade);

    if (item == 1) {
        printf("Total: R$ %.2lf\n", (4.00*quantidade));
    } else if (item == 2) {
        printf("Total: R$ %.2lf\n", (4.50*quantidade));
    } else if (item == 3) {
        printf("Total: R$ %.2lf\n", (5.00*quantidade));
    } else if (item == 4) {
        printf("Total: R$ %.2lf\n", (2.00*quantidade));
    } else {
        printf("Total: R$ %.2lf\n", (1.50*quantidade));
    }
    
    return 0;
}