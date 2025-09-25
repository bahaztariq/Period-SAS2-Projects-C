#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,facteur;
    printf("enter the numbers of your tableaux: ");
    scanf(" %d",&number);

    int n[number];
    for(int i=0; i<number;i++){
        printf("enter the numbers %d of your tableaux: ",i+1);
        scanf(" %d",&n[i]);
    }
    printf("entre the facteur:");
    scanf(" %d",&facteur);

    for(int i=0; i<number;i++){
        printf("the factuer of %d on %d is %d\n",n[i],facteur,n[i]);
    }



    return 0;
}
