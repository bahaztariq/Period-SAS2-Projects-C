#include<stdio.h>
int main(){

    int temperature= 0 ;
    printf("Enter the temperature of Water: ");
    scanf("%d",&temperature);

    if (temperature>=100)
    {
        printf("The status of water is gaz");

    }else if (temperature<0){

        printf("The status of water is solid");
    }else{

        printf("The status of water is luquid");
    }

    return 0;
}