#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RED "\e[1;31m"
#define OLA "\e[1;32m"
#define GRN "\e[0;32m"
#define YEL "\e[1;33m"
#define YELLOW "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[1;35m"
#define ROSE "\e[0;35m"
#define CYN "\e[1;36m"
#define AZZ "\e[1;36m"
#define WHT "\e[0;36m"
#define reset "\e[0m"
//******************global variables*************
int choix,choix2;
    char Titre_Livre[][100]={"lune","moon","YOU","nothing to say"};
    char Auteur_Livre[][100]={"Salma","omar","basma","mohammed"};
    char R_TITRE[100];
    int prix[]={15,35,28,19};
    int quantity[]={50,99,101,120};
    int N_Livre = 4;
    int i,j,n,found=0;

void number_livre(){
            system("cls");
            printf(ROSE"************AFFICHER LE NOMBRES TOTAL DE LIVRE EN STOCK*********\n\n");
            printf("NOMBRE TOTAL DE LIVRE EST : %d\n\n",N_Livre);
            system("PAUSE");
}

void Supprimer_livre(){
    system("cls");

            printf(YEL"************SUPRIMER UN LIVRE DU STOCK*********\n\n");

            printf("ENTRE LE TITRE DE LIVRE TU SUPPRIMER: ");
            scanf("%s",&R_TITRE);

            strlwr(R_TITRE);

            for(i=0;i<N_Livre;i++){

                strlwr(Titre_Livre[i]);

                if(strcmp(R_TITRE,Titre_Livre[i])==0){

                   printf("+------+----------------------------------------------------------------------------------------------+\n");
                   printf("|  id  |          Titre de livre           |        Auteur de livre      |    prix   |     quantity   |\n");
                   printf("+------+----------------------------------------------------------------------------------------------+\n");
                   printf("|  %d  |          %s           |        %s      |    %d DH   |     %d    |\n",i,Titre_Livre[i],Auteur_Livre[i],prix[i],quantity[i]);
                   found=1;

                   printf("\n\n SUPRRIMER LIVRE DE %s\n",Titre_Livre[i]);

                   printf("1-CONFIRMER SUPPRIMER\n");
                   printf("2-ANNULER SUPPRIMER\n");
                   printf("ENTER VOTRE CHOIX: ");

                   scanf(" %d",&choix2);

                        switch(choix2){
                               case 1 :   for(j=i;j<N_Livre;j++){

                                              strcpy(Titre_Livre[j],Titre_Livre[j+1]);
                                              strcpy(Auteur_Livre[j],Auteur_Livre[j+1]);
                                              prix[j] = prix[j+1];
                                              quantity[j] = quantity[j+1];
                                        }
                                        N_Livre--;
                                        printf("**********SUPPRESSION DONE************\n");
                                        break;

                              case 2 :  printf("**********ANNULATION DONE*******\n");
                                        break;

                              default : printf("**********INVALID CHOIX*********\n");
                        }

                   break;

                }
            }
            if(found==0){
                printf("\nLE LIVRE EST N'EXCIST PAS DANS LE STOCK\n");
            }
}

void Update_quantity(){
    system("cls");

            printf(CYN"************METTRE A JOUR QUANTITY D'UN LIVRE*********\n\n");

            printf("ENTRE LE TITRE DE LIVRE TU METTRE A JOUR LA QUANTITY: ");
            scanf("%s",&R_TITRE);

            strlwr(R_TITRE);

            for(i=0;i<N_Livre;i++){

                strlwr(Titre_Livre[i]);

                if(strcmp(R_TITRE,Titre_Livre[i])==0){
                   printf("+------+----------------------------------------------------------------------------------------------+\n");
                   printf("|  id  |          Titre de livre           |        Auteur de livre      |    prix   |     quantity   |\n");
                   printf("+------+----------------------------------------------------------------------------------------------+\n");
                   printf("|  %d  |          %s           |        %s      |    %d DH   |     %d    |\n",i,Titre_Livre[i],Auteur_Livre[i],prix[i],quantity[i]);
                   found=1;
                   printf("\n\n METTRE A JOUR LA QUANTITY DE %s\n",Titre_Livre[i]);
                   printf("ENTER THE NEW QUANTITY OF THIS LIVRE:");
                   scanf(" %d",&quantity[i]);
                   printf("**********DONE************\n");
                }
            }
            if(found==0){
                printf("LE LIVRE EST N'EXCIST PAS DANS LE STOCK");
            }
}

void Chercher_livre(){
            system("cls");
            printf(MAG"************RECHERCHER UN LIVRE*********\n\n");

            printf("ENTRE LE TITRE DE LIVRE TU RECHERCHE: ");
            scanf("%s",&R_TITRE);

            strlwr(R_TITRE);

            for(i=0;i<N_Livre;i++){

                strlwr(Titre_Livre[i]);

                if(strcmp(R_TITRE,Titre_Livre[i])==0){
                   printf("+------+----------------------------------------------------------------------------------------------+\n");
                   printf("|  id  |          Titre de livre           |        Auteur de livre      |    prix   |     quantity   |\n");
                   printf("+------+----------------------------------------------------------------------------------------------+\n");
                   printf("|  %d  |          %s           |        %s      |    %d DH   |     %d    |\n",i,Titre_Livre[i],Auteur_Livre[i],prix[i],quantity[i]);
                   found=1;
                   break;
                }
            }
            if(found==0){
                printf("LE LIVRE EST N'EXCIST PAS DANS LE STOCK");
            }
}

void Affiche_livre(){

            printf(BLU"************AFFICHER TOUS LES LIVRES*********\n\n");
            printf("+------+----------------------------------------------------------------------------------------------+\n");
            printf("|  id  |          Titre de livre           |        Auteur de livre      |    prix   |     quantity   |\n");
            printf("+------+----------------------------------------------------------------------------------------------+\n");

            for(i=0;i<N_Livre;i++){
            printf("|  %d  |          %s           |        %s      |    %d DH   |     %d    |\n",i,Titre_Livre[i],Auteur_Livre[i],prix[i],quantity[i]);

            }
            printf("+------+----------------------------------------------------------------------------------------------+\n");
}

void Ajouter_livre(){
     system("cls");
     printf("***************AJOUTER LIVRE*************\n\n");

            printf("Combien de Livre tu vuex AJouter:");
            scanf(" %d",&n);

            for(i=0;i<n;i++){

                printf("Please entre le Titre de livre %d :",N_Livre+1);
                scanf(" %s",&Titre_Livre[N_Livre]);
                printf("Please entre l'Auteur de livre %d :",N_Livre+1);
                scanf(" %s",&Auteur_Livre[N_Livre]);
                printf("Please entre le Prix de livre %d :",N_Livre+1);
                scanf(" %d",&prix[N_Livre]);
                printf("Please entre la Quantity de livre %d :",N_Livre+1);
                scanf(" %d",&quantity[N_Livre]);

                N_Livre++;
            }
}
int Menu(){


    int choix;

    printf(GRN"************* WELCOME TO YOUR LIBRARY ***********\n\n");
    printf(AZZ"1-AJOUTER UN LIVRE\n");
    printf(BLU"2-AFFICHER TOUS LES LIBRES DISPONIBLE\n");
    printf(MAG"3-RECHERCHER UN LLIVRE PAR SON TITRE\n");
    printf(CYN"4-METTRE A JOUR LA QUANTITY D'UN LIVRE\n");
    printf(YEL"5-SUPPRIMER UN LIVRE DU STOCK\n");
    printf(ROSE"6-AFFICHER LE NOMBRE TOTAL DE LIVRE EN STOCK\n");
    printf(RED"0-QUITTER LE PROGRAM\n\n");

    printf(GRN"ENTRE TON CHOIX: ");
    scanf("%d",&choix);
    system("cls");
    return choix;
}
int main()
{
    int n;

    do{
        n= Menu();

        switch(n){
        case 1 :Ajouter_livre();
                system("PAUSE");
                break;
        case 2 :Affiche_livre();
                system("PAUSE");
                break;
        case 3 :Chercher_livre();
                system("PAUSE");
                break;
        case 4 :Update_quantity();
                system("PAUSE");
                break;
        case 5 :Supprimer_livre();
                system("PAUSE");
                break;
        case 6 :number_livre();
                system("PAUSE");
                break;
        case 0 :exit(0);
                break;
        default:printf("INVALID CHOICE %d",n);
                system("PAUSE");
                break;
       }

    }while(1);

    return 0;
}
