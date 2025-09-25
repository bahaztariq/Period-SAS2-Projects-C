#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("enter the numbers of your tableaux: ");
    scanf(" %d",&number);

    int n[number];
    for(int i=0; i<number;i++){
        printf("enter the numbers %d of your tableaux: ",i+1);
        scanf(" %d",&n[i]);
    }
    for(int i=0; i<number;i++){
        printf("%d\n",n[i]);
    }



    return 0;
}
