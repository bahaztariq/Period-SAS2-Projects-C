#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    printf("Enter a number: ");
    scanf(" %d",&num);
    if (num%2==0){
        printf("the number is Pair");
    }else{
        printf("the number is inPair");
    }
    return 0;
}
