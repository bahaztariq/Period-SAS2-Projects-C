#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1,num2,num3;
    float moyene;

    printf("enter the value of number 1: ");
    scanf(" %f",&num1);
    printf("enter the value of number 2: ");
    scanf(" %f",&num2);
    printf("enter the value of number 3: ");
    scanf(" %f",&num3);

    moyene = (num1*2.0 + num2*3.0 + num3*5.0)/10.0;

    printf("the moyen of the three nums is %.2f",moyene);

    return 0;
}
