/**************** IMPORT ALL LIBRARIES *************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#include "tarikbahaz.h"

/***************COLORS and CONSTANTS********************/
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
#define BWHT "\e[1;37m"

#define POSTE1 "guardian"
#define POSTE2 "Défenseur"
#define POSTE3 "Milieu"
#define POSTE4 "Attaquant"

/**************** STRUCTURE *************/
typedef struct{
    int id;
    char nom[100];
    char prenom[100];
    char poste[100];
    int age ;
    int maillot;
    int buts;
    char status[50];

}Players;

// initializing some values to start with
Players player[]={
                //guardiens de but
                  {1001, "ter Stegen", "Marc-André", "Gardien", 33, 1, 0, "Remplaçant"},
                  {1013, "García", "Joan", "Gardien", 24, 13, 0, "Titulaire"},

                  //defenseurs
                  {2003, "Balde", "Alejandro", "Défenseur", 21, 3, 0, "Titulaire"},
                  {2004, "Araújo", "Ronald", "Défenseur", 26, 4, 0, "Titulaire"},
                  {2005, "Cubarsí", "Pau", "Défenseur", 18, 5, 0, "Titulaire"},
                  {2015, "Christensen", "Andreas", "Défenseur", 29, 15, 0, "Remplaçant"},
                  {2023, "Koundé", "Jules", "Défenseur", 26, 23, 0, "Titulaire"},
                  {2024, "García", "Eric", "Défenseur", 24, 24, 0, "Remplaçant"},

                  // Milieux de terrain
                  {3006, "Gavi", "Pablo", "Milieu", 21, 6, 0, "Remplaçant"},
                  {3008, "Pedri", "Gonzalez", "Milieu", 22, 8, 0, "Titulaire"},
                  {3016, "López", "Fermín", "Milieu", 22, 16, 0, "Remplaçant"},
                  {3020, "Olmo", "Dani", "Milieu", 27, 20, 0, "Titulaire"},
                  {3021, "de Jong", "Frenkie", "Milieu", 28, 21, 0, "Titulaire"},

                  // Attaquants
                  {4009, "Lewandowski", "Robert", "Attaquant", 37, 9, 0, "Titulaire"},
                  {4010, "Yamal", "Lamine", "Attaquant", 18, 10, 0, "Titulaire"},
                  {4011, "Raphinha", "Belloli", "Attaquant", 28, 11, 0, "Titulaire"},
                  {4014, "Rashford", "Marcus", "Attaquant", 27, 14, 0, "Remplaçant"}
                  };
/**************** GLOBAL VARIABLES *************/
int N=16;

/**************** FUNCTIONS *************/
char Menu();
void Ajoute_Menu();
void Ajoute_Player();
void Delete_Player();
void statistics();
void afficher_Players();
void rechercher_Players();
void modifier_player();
void supprimer_Players();

int main()
{
    /*********** SET CONSOLE TO UTF8 STANDARD ***********/
    SetConsoleOutputCP(CP_UTF8);
    do{
            switch(Menu()){
                case '1' : Ajoute_Menu();
                           getchar();
                           break;
                case '2' : printf("2");
                          system("PAUSE");
                          break;

                case '3' : printf("3");
                          system("PAUSE");
                          break;

                case '4' : printf("4");
                          system("PAUSE");
                          break;

                case '5' : printf("5");
                          system("PAUSE");
                          break;

                case '6' : printf("6");
                          system("PAUSE");
                          break;

                default : system("cls");
                          printf(RED"\n###########INVAlid CHOIX##########\n");
                          printf("\n#  PLEASE ENTER A VALID NUMBER   #\n");
                          printf("\n##################################\n"reset);
                          system("PAUSE");
            }

    }while(Menu()!='0');
    return 0;
}
char Menu(){
    /****************************************AFFICHAGE MENU******************************/
    char choix;

    system("cls");
    printf(BLU"\n");
    printf("\t\t\t██████╗  █████╗ ██████╗  ██████╗███████╗██╗      ██████╗ ███╗   ██╗███████╗\n");
    printf("\t\t\t██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██║     ██╔═══██╗████╗  ██║██╔════╝\n");
    printf("\t\t\t██████╔╝███████║██████╔╝██║     █████╗  ██║     ██║   ██║██╔██╗ ██║█████╗\n");
    printf("\t\t\t██╔══██╗██╔══██║██╔══██╗██║     ██╔══╝  ██║     ██║   ██║██║╚██╗██║██╔══╝  \n");
    printf("\t\t\t██████╔╝██║  ██║██║  ██║╚██████╗███████╗███████╗╚██████╔╝██║ ╚████║███████╗\n");
    printf("\t\t\t╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝\n\n");
    printf(YELLOW);
    printf("\t\t\t\t\t\t***************************\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  1-AJOUTER PLAYERS      *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  2-AFFICHER PLAYERS     *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  3-RECHERCHE PLAYERS    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  4-MODIFIER PLAYERS     *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  5-SUPPRIMER PLAYERS    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  6-STATISTICS           *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  0-QUITTER LE PROGRAM   *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t***************************\n\n");
    printf(BWHT"\t\t\t\t\t\t    ENTRER TON CHOIX:");

    scanf("%c",&choix);
    while(getchar()!= '\n');

    return choix;
}
void Ajoute_Menu(){
    /***********************************MENU D'AJOUTER PLAYER********************/
    char Ajchoix;
    int n;
    system("cls");
    printf(BLU"\n");
    printf("\t\t\t██████╗  █████╗ ██████╗  ██████╗███████╗██╗      ██████╗ ███╗   ██╗███████╗\n");
    printf("\t\t\t██╔══██╗██╔══██╗██╔══██╗██╔════╝██╔════╝██║     ██╔═══██╗████╗  ██║██╔════╝\n");
    printf("\t\t\t██████╔╝███████║██████╔╝██║     █████╗  ██║     ██║   ██║██╔██╗ ██║█████╗\n");
    printf("\t\t\t██╔══██╗██╔══██║██╔══██╗██║     ██╔══╝  ██║     ██║   ██║██║╚██╗██║██╔══╝  \n");
    printf("\t\t\t██████╔╝██║  ██║██║  ██║╚██████╗███████╗███████╗╚██████╔╝██║ ╚████║███████╗\n");
    printf("\t\t\t╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝\n\n");
    printf(YELLOW);
    printf("\t\t\t\t\t\t***************************\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  1-AJOUTER 1 PLAYERS    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  2-AJOUTER  PLUSIEUR    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  0-BACK TO MAIN MENU    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t***************************\n\n");
    printf(BWHT"\t\t\t\t\t\t    ENTRER TON CHOIX:");

    scanf("%c",&Ajchoix);
    while(getchar()!= '\n');

    switch(Ajchoix){
        case '1' : Ajoute_Player();
                   break;

        case '2' : printf(BWHT"\t\t\t\t\t\t Combien tu veux ajoute:");

                   scanf("%d",&n);
                   while(getchar()!= '\n');

                   for(int i=0;i<n;i++){
                     Ajoute_Player();
                   }
                   break;
        case '0' : break;
        default  : printf("invalid choix");
    }

}
void Ajoute_Player(){
    /*************************FUNCTIOON D'AJOUTER un player **********************/
    system("cls");
    printf("*****************AJOUTER PLAYERS****************\n\n");

    player[N].id = rand()%4000 +1000;

    printf("ENTER THE NAME OF PLAYER %d:",N+1);
    fgets(player[N].nom,100,stdin);
    player[N].nom[strcspn(player[N].nom,"\n")]='\0';

    printf("ENTER THE LAST NAME OF PLAYER %d:",N+1);
    fgets(player[N].prenom,100,stdin);
    player[N].prenom[strcspn(player[N].prenom,"\n")]='\0';

    printf("ENTER THE AGE OF PLAYER %d:",N+1);
    scanf("%d",player[N].age);
    while( getchar() != '\n');

    printf("ENTER T-SHIRT NUMBER OF PLAYER %d:",N+1);
    scanf("%d",player[N].maillot);
    while( getchar() != '\n');

    printf("ENTER SCORED GOAL NUMBER OF PLAYER %d:",N+1);
    scanf("%d",player[N].buts);
    while( getchar() != '\n');


    N++;
}
