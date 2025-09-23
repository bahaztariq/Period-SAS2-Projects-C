#include <stdio.h>
#include <stdlib.h>

int main()
{
    int An_Revenu =0,ScoreCredit=0,Pretduree=0;
    printf("**********welcome*********\n");
    printf("Please enter the annual revenu (en euro): ");
    scanf(" %d",&An_Revenu);
    printf("Please enter the Score credit (sur 1000): ");
    scanf(" %d",&ScoreCredit);
    printf("Please enter the pret dure (en annee): ");
    scanf(" %d",&Pretduree);
    if(An_Revenu>=30000 && ScoreCredit>=650&&Pretduree<=10){
            printf("YOU ARE ELIGIBLE\n");
    }else if(An_Revenu>=30000 && ScoreCredit>=650&&Pretduree<=15){
            printf("YOU ARE ELIGIBLE AVEC CONDITIONS\n");

    }else
            printf("YOU ARE NOT ELIGIBLE");
    printf("**************************");


    return 0;
}
