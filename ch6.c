#include <stdio.h>
int main(){
    int a,b;
    printf("enter the value of a: ");
    scanf("%d",&a);
    printf("enter the value of b: ");
    scanf("%d",&b);

    printf("the sum of %d and %d is %d\n",a,b,a+b);
    printf("the sub of %d and %d is %d\n",a,b,a-b);
    printf("the Multiplication of %d and %d is %d\n",a,b,a*b);
    if(b!= 0){
        printf("the Divide of %d and %d is %d\n",a,b,a/b);
    }else{
        printf("you can not divite by 0\n");
    }
    
    return 0;
}