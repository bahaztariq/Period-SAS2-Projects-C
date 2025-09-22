#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float rayon = .0;
    float volume =.0;
    const float PI = 3.14;
    printf("Please enter the rayon of the sphere:");
    scanf(" %f",&rayon);

    volume = (4.0/3.0) * PI * pow(rayon,3);

    printf("the volume of the sphere is %.2f",volume);
    return 0;
}
