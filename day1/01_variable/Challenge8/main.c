#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c, geo;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    geo = cbrt(a * b * c);

    printf("g�om�trique = %.2f\n", geo);

    return 0;
}
