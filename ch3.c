#include <stdio.h>
int main(){
    int km=0;
    float yards =.0;
    printf("PLease enter the kilometer value : ");
    scanf("%d",&km);
    yards= km * 1093.61;
    printf("The yards in %dkm is %.2f yard",km,yards);
    return 0;
}