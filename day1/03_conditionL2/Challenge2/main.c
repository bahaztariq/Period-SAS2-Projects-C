#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age,T_voiture,N_accident;
    float prime=0;
    start:
    printf("********welcome********\n");
    printf("enter your age:");
    scanf(" %d",&age);
    printf("1-sportif\n");
    printf("2-utilaire\n");
    printf("3-familiale\n");
    printf("enter your Type car:");
    scanf(" %d",&T_voiture);
    printf("enter your accident number in the last 5 years:");
    scanf(" %d",&N_accident);
    printf("enter your Prime de base:");
    scanf(" %f",&prime);


    //************prime age **********
    if(age<25){
       prime *=1.5;
    }else if (age>65){
        prime*=1.2;
    }

    //********** prime voiture********
    switch(T_voiture){
        case 1 : prime *=2;
                 break;
        case 2 : prime *=1.2;
                 break;
        case 3 : prime *=1.1;
                 break;
        default : printf("type of car invalid please try again");
                 system("Pause");
                 system("cls");
                 goto start;

    }
    //*************Prime accident********
    if(N_accident>1){
        prime *=1.3;
    }
    printf(" YOUR PRIME IS %.2f",prime);


    return 0;
}
