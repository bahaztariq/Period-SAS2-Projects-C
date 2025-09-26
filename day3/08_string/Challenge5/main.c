#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[1000];
    printf("Entre le chaine de caractere:");
    scanf("%s",&string);
    strrev(string);
    printf("le chaine inverse est :%s",string);
    return 0;
}
