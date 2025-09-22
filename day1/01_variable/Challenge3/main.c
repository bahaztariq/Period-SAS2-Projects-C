include <stdio.h>

int main(){

    float km=.0;
    float yards =.0;

    printf("PLease enter the kilometer value : ");
    scanf(" %f",&km);
    yards= km * 1093.61;
    printf("The yards in %.2f km is %.2f yard",km,yards);

    return 0;
}
