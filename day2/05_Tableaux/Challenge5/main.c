#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,min;
    printf("enter the numbers of your tableaux: ");
    scanf(" %d",&number);

    int n[number];
    for(int i=0; i<number;i++){
        printf("enter the numbers %d of your tableaux: ",i+1);
        scanf(" %d",&n[i]);
    }
    min=n[0];
    for(int i=0; i<number;i++){
        if(n[i]<min){
            min = n[i];
        }
    }
    printf("the minimum of the numbers is %d\n",min);


    return 0;
}
