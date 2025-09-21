#include<stdio.h>
int main(){
    int vitesse = 0;
    float result = 0.00 ;
    printf("Please enter the vitesse in km/h :");
    scanf("%d",&vitesse);
    result = vitesse*1000.0/3600.0;
    printf("the vitesse of %dkm/h is equal to %.2fm/s",vitesse,result);
    
    return 0;
}