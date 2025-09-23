#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number =0,reverse=0,Copynum;
    printf("***********INVERSE NUMBER************\n");
    printf("enter the number you want to inverse:");
    scanf(" %d",&number);
    Copynum = number;
    do{
        reverse= reverse*10 + Copynum%10;
        Copynum/=10;

    }while(Copynum>0);
    printf("THE REVERSED NUMBER OF %d IS %d",number,reverse);

    return 0;
}
