#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nom[100];
    char prenom[100];
    int age;
    int notes[100];

}person;

int main(){

    person p1 = {"tariq","bahaz",23};

    p1.notes ={19,18,16,14,12};

    printf("*****infos**** \nName: %s\nFirst Name: %s\nAge: %d\n*****notes****\nMATH: %d\nPHYSICS: %d\nGEOGRAPHIE: %d\nHISTORY: %d\nSPORT: %d\n",p1.nom,p1.prenom,p1.age,p1.notes[0],p1.notes[1],p1.notes[2],p1.notes[3],p1.notes[4]);

    return 0;
}
