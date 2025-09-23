#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    printf("********NOMBER IMPAIR*********\n");
    do{

    printf("enter the number :");
    scanf(" %d",&n);
    }while(n<0);

    for(int i=1;i<=n*2;i++){
        if (i%2!=0)
            printf("%d ",i);
    }
    return 0;
}
