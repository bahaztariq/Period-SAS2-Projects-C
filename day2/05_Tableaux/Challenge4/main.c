#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,max;
    printf("enter the numbers of your tableaux: ");
    scanf(" %d",&number);

    int n[number];
    for(int i=0; i<number;i++){
        printf("enter the numbers %d of your tableaux: ",i+1);
        scanf(" %d",&n[i]);
    }
    max=n[0];
    for(int i=0; i<number;i++){
        if(n[i]>max){
            max = n[i];
        }
    }
    printf("the maximum of the numbers is %d\n",max);


    return 0;
}
