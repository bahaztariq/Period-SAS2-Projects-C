#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define taille 50

typedef struct {
    char titre[taille];
    char auteur[taille];
    int annee;
}Livre;


Livre Ajoute();
void afficher(Livre);

int main()
{
    Livre L1;

    L1=Ajoute();
    afficher(L1);

    return 0;
}

Livre Ajoute(){
    Livre l;

    printf("entrer le tittre de Livre:");
    fgets(l.titre, taille, stdin);
    l.titre[strcspn(l.titre,"\n")]='\0';

    printf("entrer l'auteur de livre:");
    fgets(l.auteur, taille, stdin);
    l.auteur[strcspn(l.auteur,"\n")]='\0';

    printf("entrer l'annee de release:");
    scanf("%d", &l.annee);

    return l;
}

void afficher( Livre l)
{
    printf("le titre: %s\n", l.titre);
    printf("l'Auteur: %s\n", l.auteur);
    printf("l'Auteur: %d\n", l.annee);
}
