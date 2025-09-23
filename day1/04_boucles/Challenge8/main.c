#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n){

    if (n==0){
        return  0;
    }else if(n==1){
        return  1;
    }else
       return fibonacci(n-1)+ fibonacci(n-2);

}

int main()

{   int n = 1;

    while(n>0){

    printf("enter the number ");
    scanf(" %d",&n);
    printf("%d\n",fibonacci(n));

    }
    return 0;
}
