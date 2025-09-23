#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,result=0;
    printf("********Tableaux de multiplication*********\n");
    do{

    printf("enter the number :");
    scanf(" %d",&n);
    }while(n<0);

    for(int i=0;i<=n;i++){
        result +=i;
    }
    printf("the somme of %d nombres est : %d",n,result);
    return 0;
}
