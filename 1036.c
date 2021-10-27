#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double A, B, C, delta;

    scanf("%lf", &A);
    scanf("%lf", &B);
    scanf("%lf", &C);

    delta = (B*B)-(4*A*C);

    if (A == 0) {
        printf("Impossivel calcular");
    } else if (delta > 0) {
        printf("R1 = %.5lf\n", ((-B + sqrt(delta)) / (2 * A)));
        printf("R2 = %.5lf\n", ((-B - sqrt(delta)) / (2 * A)));
    } else {
        printf("Impossivel calcular");
    }

    return 0;
}