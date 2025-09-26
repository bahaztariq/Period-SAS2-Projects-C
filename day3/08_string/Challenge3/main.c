#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string1[1000],string2[1000];

    printf("Entre le chaine de caractere 1: ");
    scanf("%s",&string1);
    printf("Entre le chaine de caractere 2: ");
    scanf("%s",&string2);

    strcat(string1,string2);
    printf("the some of strings is %s",string1);

    return 0;
}
