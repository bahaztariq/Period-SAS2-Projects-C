#include <stdio.h>
int main(){
    float Temp =.0;
    printf("Enter the temperature in Celusius:");
    scanf("%f",&Temp);
    printf("\n The temperature in kalvin is %.2f",Temp+273.15);
    return 0;
}