#include <stdio.h>


int main(){
    char name[50];
    char prenom[50];
    int age = 0;
    char sex = '\0';
    char email[50];

    printf("Please enter you name: ");
    scanf("%s",name);
    printf("Please enter you prenom: ");
    scanf("%s",prenom);
    printf("Please enter you Age: ");
    scanf("%d",&age);
    do
    {
        while (getchar() != '\n');
        printf("Please enter you gender M/F: ");
        scanf("%c",&sex);
    } while (sex !='M' && sex !='F');
    printf("Please enter you email: ");
    scanf("%s",email);
    system("cls");
    printf("\nname: %s\nprenom: %s\nage: %d\nsex: %c\nemail: %s\n",name,prenom,age,sex,email);

    return 0;

}
