#include <stdio.h>
#include <stdlib.h>

int main()
{
    int budget=0,N_Person=0;
    printf("entre your budget (en euro):");
    scanf(" %d",&budget);
    printf("enter How many persons :");
    scanf(" %d",&N_Person);
    if(budget>=1000&&N_Person>2){
        printf("voyage Haut gamme\n");
        printf("1-Plage\n");
        printf("2-ville\n");
    }else if(budget>=500&& N_Person<=2){
        printf("voyage MOYEN\n");
        printf("1-Montagne\n");
        printf("2-ville\n");
    }else if(budget<500&&N_Person<=2){
        printf("voyage Economic\n");
        printf("1-ville\n");
    }
    return 0;
}
