#include <stdio.h>
#include <stdlib.h>

int main() {
    int anos, meses, dias;

    scanf("%d", &dias);

    anos = dias / 365;
    meses = (dias - (365 * anos)) / 30;
    dias = dias - (anos * 365) - (meses * 30);

    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);

    return 0;
}