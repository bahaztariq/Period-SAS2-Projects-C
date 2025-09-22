#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,reversed=0;

    printf("enter a number of 4 chiffre:");
    scanf(" %d",&num);

    reversed = reversed*10 + num%10;
    num /=10;
    reversed = reversed*10 + num%10;
    num /=10;
    reversed = reversed*10 + num%10;
    num /=10;
    reversed = reversed*10 + num%10;
    num /=10;

    printf("the reversed num is %d",reversed);



    return 0;
}
