#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char string[1000];
    printf("Entre le chaine de caractere:");
    scanf("%s",&string);
    for(int i=0;i<strlen(string);i++){
         string[i]=toupper(string[i]);
    }
    printf("the chaine you entered is %s",string);
    return 0;
}
