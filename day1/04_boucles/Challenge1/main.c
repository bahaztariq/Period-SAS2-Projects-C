#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    printf("********Tableaux de multiplication*********\n");
    do{

    printf("enter the number :");
    scanf(" %d",&n);
    }while(n<0);

    for(int i=0;i<=10;i++){
        printf("%d * %d = %d\n",n,i,n*i);
    }
    return 0;
}
