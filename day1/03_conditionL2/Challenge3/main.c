#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Restant,accordes,utiliser,status;
    printf("***********GESTIONER CONGEE********\n");
    printf("please entre jour accordes:");
    scanf(" %d",&accordes);
    printf("please entre jour utilise:");
    scanf(" %d",&utiliser);
    do{
    printf("1-FULL time\n");
    printf("2-PART time\n");
    scanf(" %d",&status);
    }while(status!=1 && status!=2);
    if(status==1)
        Restant = accordes - utiliser;
    else if(status==2)
        Restant = accordes/2 - utiliser;

    if (Restant<0)
        printf("alerte you passed accordes jours");
    else{
        printf("your reste jour are %d",Restant);
    }

    return 0;
}
