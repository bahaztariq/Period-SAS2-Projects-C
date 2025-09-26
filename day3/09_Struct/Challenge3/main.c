#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int longeur;
    int largeur;
}Rectangle;

int calculaire(Rectangle rect){

    return rect.largeur*rect.longeur;
}
int main()
{
    int aire;
    Rectangle rect ={12,10};
    aire = calculaire(rect);
    printf("the air calculated is %d",aire);
    return 0;
}
