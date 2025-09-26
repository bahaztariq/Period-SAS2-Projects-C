#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char nom[100];
    char prenom[100];
    int age;

}person;

int main(){
    person p1 = {"tariq","bahaz",23};
    printf("Name: %s\nFirst Name: %s\nAge: %d",p1.nom,p1.prenom,p1.age);

    return 0;
}
