#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c ='\0';
    do{


    printf("Enter the caractere: \n");
    printf("Enter 0 to exit\n");
    scanf(" %c",&c);
    switch(c){
        case'a': case'A':
        case'e':case'E':
        case'i':case'I':
        case'u':case'U':
        case'y':case'Y':
        case'o':case'O':printf("the caractere is voyelle\n");
                        break;
        case'0': exit(0);
        default: printf("the caractere is not voyelle\n");
    }
    system("PAUSE");
    system("cls");
    }while(1);
    return 0;
}
