#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base,exposant,result=1;
    printf("********PUISSANCE*********\n");

    printf("enter the base :");
    scanf(" %d",&base);
    printf("enter the base :");
    scanf(" %d",&exposant);

    for(int i=0;i<exposant;i++){
        result *=base;
    }
    printf("the puissance de %d a %d est : %d",base,exposant,result);
    return 0;
}
