#include <stdio.h>
#include <stdlib.h>
#include "Lentgh.h"

int main(){

    char string[1000];
    printf("Entre le chaine de caractere:");
    scanf("%s",&string);
    printf("the string you entred is %d",Tlen(string));

    return 0;
}
