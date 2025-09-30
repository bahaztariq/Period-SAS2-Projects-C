#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nom [][50]= {
                     {"tarik"},
                     {"yahya"},
                     {"bouchaib"},
                     {"meryem"},
                     {"ABDELLAH"},
                     {"khadija"},
                     {"youness"},
                     {"mohammed"},
                     {"ghofran"}
                     };

    int n ;
    n = sizeof(nom)/sizeof(nom[0]);
    int found = 0 ;
    char nomE [] = "tarik";

    for(int i = 0 ; i<n ; i++){
            if(strcmp(nom[i],nomE)==0){
                printf("element exist");
                found=1;
                break;
            }

    }
    if(found == 0){
        printf("element not found!!");
    }

    return 0;
}
