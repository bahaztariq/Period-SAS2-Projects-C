#include <stdio.h>
#include <stdlib.h>

int main()
{
    char string[]={'\0'};
    printf("entre le chaine de caractere:");
    fgets(string,1000,stdin);
    printf("the string you entred is %s",string);
    return 0;
}
