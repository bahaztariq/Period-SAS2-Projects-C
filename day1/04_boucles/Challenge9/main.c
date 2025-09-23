#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number =0,Cmp=0,Copynum;
    printf("***********INVERSE NUMBER************\n");
    printf("enter the number you want to inverse:");
    scanf(" %d",&number);
    Copynum = number;
    do{
        Copynum/=10;
        Cmp++;

    }while(Copynum>0);
    printf("THE NUMBER OF %d IS %d",number,Cmp);

    return 0;
}
