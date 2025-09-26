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

    if (strstr(string1,string2)){
            printf("String found\n");
         printf("First occurrence of string '%s' in '%s' is " "'%s'",string1,string2,strstr(string1,string2));
    }else{
        printf("String not found\n");
    }
    return 0;
}
