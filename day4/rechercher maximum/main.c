#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[]={51,21,5,45,58,52,1,0,1,5,23,3,6,4,7,8,9,6,75,12,14,15};
    int max,n;
    n=sizeof(num)/sizeof(num[0]);
    max =num[0];
    for (int i=0;i<n;i++){
         if(num[i]>max)
            max =num[i];
    }
    printf("the minimum number is %d",max);
    return 0;
}
