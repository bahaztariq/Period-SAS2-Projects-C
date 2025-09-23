#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,factorial=1;
    printf("********Factorial*********\n");
    do{

    printf("enter the number :");
    scanf(" %d",&n);
    }while(n<0);

    for(int i=1;i<=n;i++){
        factorial *=i;
    }
    printf("the factorial of %d is %d",n,factorial);
    return 0;
}
