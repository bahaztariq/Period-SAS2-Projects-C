#include <stdio.h>
#include <stdlib.h>

int main()
{
    int largeur,longeur,surface;

    printf("enter the largeur of rectangle: ");
    scanf(" %d",&largeur);

    printf("enter the longeur of rectangle: ");
    scanf(" %d",&longeur);

    surface = largeur*longeur;
    printf("the surface de rectangle est : %d",surface);

    return 0;
}
