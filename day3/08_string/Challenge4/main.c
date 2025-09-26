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

    if (strcmpi(string1,string2)==0){
            if (strcmp(string1,string2)==0){
               printf("Les strings sont completement egal");
            }else{
               printf("Les strings sont egal mais avec different type Caractere");
            }
    }else{
        printf("Les strings sont different");
    }
    return 0;
}
