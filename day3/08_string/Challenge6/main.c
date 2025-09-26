#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[1000],c;
    int cmp=0;
    printf("Entre le chaine de caractere:");
    scanf(" %s",&string);
    printf("entre le caractere tu veux compter:");
    scanf(" %c",&c);
    for(int i = 0;i<strlen(string);i++){
        if (string[i] == c){
            cmp++;
        }
    }
    printf("the caractere you entered afficher %d fois",cmp);
    return 0;
}
