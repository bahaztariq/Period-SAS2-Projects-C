#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number,Temp;
    printf("enter the numbers of your tableaux: ");
    scanf(" %d",&number);

    int n[number];
    //****************saisir**************

    for(int i=0; i<number;i++){
        printf("enter the numbers %d of your tableaux: ",i+1);
        scanf(" %d",&n[i]);
    }


    for(int i = 0; i<number ;i++){

        for(int j = 0 ; j<number ;j++){

            if( n[j+1] < n[j] ){
                Temp = n[j+1];
                n[j+1] = n[j];
                n[j] = Temp;
            }
        }
    }
    //***************printing************

    for(int i=0; i<number;i++){
        printf("%d  ",n[i]);
    }



    return 0;
}
