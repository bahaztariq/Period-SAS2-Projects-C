#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void spacesRemoved(char T[]){
    int l = strlen(T);
    for(int i=0;i<l;i++){
         if(T[i]== ' '){

            for(int j =i;j<l;j++){
             T[j]=T[j+1];
            }
           l--;
         }
    }
    T[l]='\0';
    printf("the chaine you entered is %s",T);
}

int main(){

    char string[1000];
    printf("Entre le chaine de caractere:");
    fgets(string,1000,stdin);

    spacesRemoved(string);
    return 0;
}
