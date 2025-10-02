/***********IMPORT TOUS LES BIBLIOTHEQUE************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>
#include <time.h>

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

#define Max_animal 200
#define Max 50
/********************STRUCT ET FILE ****************/
typedef struct{
    int Id;
    char Name[Max];
    char Espece[Max];
    char Habitat[Max];
    char Categorie[Max];
    int Age;
    int Poids;
    char date_inscription[Max];
}Animaux;

Animaux Animal[Max_animal]={
                            { 1, "Simba", "Lion", "SAVANE", "CARNIVORES", 5, 190, "Wed Oct 01 18:10:21 2025" },
                            { 2, "Dumbo", "Elephant", "SAVANE", "HERBIVORES", 10, 5000, "Wed Oct 01 18:10:45 2025" },
                            { 3, "Kaa", "Python", "JUNGLE", "CARNIVORES", 15, 50, "Wed Oct 01 18:11:30 2025" },
                            { 4, "Zebra", "Equus", "PRAIRI", "HERBIVORES", 7, 300, "Wed Oct 01 18:11:13 2025" },
                            { 5, "Flipper", "Dolphin", "OCEAN", "CARNIVORES", 8, 150, "Wed Oct 01 18:11:33 2025" },
                            { 6, "Gigi", "Giraffe", "SAVANE", "HERBIVORES", 9, 800, "Wed Oct 01 18:11:55 2025" },
                            { 7, "Rocky", "Penguin", "AUTRE", "CARNIVORES", 4, 25, "Wed Oct 01 18:12:10 2025" },
                            { 8, "Manny", "Mammoth", "PRAIRI", "HERBIVORES", 12, 6000, "Wed Oct 01 18:12:40 2025" },
                            { 9, "Rajah", "Tiger", "JUNGLE", "CARNIVORES", 6, 220, "Wed Oct 01 18:12:53 2025" },
                            { 10, "Po", "Panda", "JUNGLE", "OMNIVORES", 7, 110, "Wed Oct 01 18:13:20 2025" },
                            { 11, "Camel", "Camelus", "DESERT", "HERBIVORES", 11, 600, "Wed Oct 01 18:14:00 2025" },
                            { 12, "Nemo", "Clownfish", "OCEAN", "OMNIVORES", 1, 1, "Wed Oct 01 18:14:15 2025" },
                            { 13, "Skar", "Lion", "SAVANE", "CARNIVORES", 21, 135, "Wed Oct 01 18:14:31 2025" },
                            { 14, "Hippo", "Hippo", "SAVANE", "HERBIVORES", 14, 1500, "Wed Oct 01 18:14:53 2025" },
                            { 15, "Kong", "Gorilla", "JUNGLE", "HERBIVORES", 16, 180, "Wed Oct 01 18:15:23 2025" },
                            { 16, "Leo", "Leopard", "SAVANE", "CARNIVORES", 8, 70, "Wed Oct 01 18:15:45 2025" },
                            { 17, "Sonic", "Hedgehog", "PRAIRI", "OMNIVORES", 3, 1, "Wed Oct 01 18:16:03 2025" },
                            { 18, "Jaws", "Shark", "OCEAN", "CARNIVORES", 18, 1000, "Wed Oct 01 18:16:21 2025" },
                            { 19, "Foxy", "Fox", "PRAIRI", "OMNIVORES", 4, 10, "Wed Oct 01 18:16:43 2025" },
                            { 20, "Croc", "Crocodile", "JUNGLE", "CARNIVORES", 20, 400, "Wed Oct 01 18:17:01 2025"}

                            };

int Total_Animaux = 20;
int current_id =21;

/********************FUNCTIONS ****************/
int Menu();
void Ajoute_Menu();
void Ajoute_Animal();
void Affichage_Menu();
void afficher_Tous_Animeaux();
void afficher_un_animal(int i);
void Trier_par_Nom();
void Trier_par_Age();
void affiche_Par_Habitat();
void Recherche_Menu();
int Recherche_Par_ID();
int Recherche_Par_Nom();
void Recherche_Par_Espece();
void modifier_Menu();
void supprimer_Menu();
void statistics();
/*************************************/
int main(){ /**main function that containt do while loop keep the program running till user type 0*/

    do{
            switch(Menu()){
                case 1 : Ajoute_Menu();
                         system("PAUSE");
                         break;
                case 2 : Affichage_Menu();
                          system("PAUSE");
                          break;

                case 3 : Recherche_Menu();
                          system("PAUSE");
                          break;

                case 4 : modifier_Menu();
                          system("PAUSE");
                          break;

                case 5 : supprimer_Menu();
                          system("PAUSE");
                          break;

                case 6 : statistics();
                          system("PAUSE");
                          break;
                case 0 :printf("MERCI BEAUCOUP");
                          exit(0);
                          break;
                default : system("cls");
                          printf(RED" \t\t\t\t\t\t \n###########INVAlid CHOIX##########\n");
                          printf("\t\t\t\t\t\t \n#  PLEASE ENTER A VALID NUMBER   #\n");
                          printf("\t\t\t\t\t\t \n##################################\n"reset);
                          system("PAUSE");
            }

    }while(1);
    return 0;
}
int Menu(){ /** Principal menu*/
    int choix;
    system("cls");
    printf(GRN);
    printf("\t\t\t\t\t\t    _oo     .-.        .-.\n");
    printf("\t\t\t\t\t\t >-(_  \\  c(O_O)c    c(O_O)c\n");
    printf("\t\t\t\t\t\t    / _/ ,'.---.`,  ,'.---.`,\n");
    printf("\t\t\t\t\t\t   / /  / /|_|_|\\ \\/ /|_|_|\\ \\\n");
    printf("\t\t\t\t\t\t  / (   | \\_____/ || \\_____/ |\n");
    printf("\t\t\t\t\t\t (   `-.'. `---' .`'. `---' .`\n");
    printf("\t\t\t\t\t\t  `--.._) `-...-'    `-...-'\n\n");
    printf("\t\t\t\t\t\t***************************\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  1-AJOUTER ANIMAL       *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  2-AFFICHER ANIMAUX     *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  3-RECHERCHE ANIMAL     *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  4-MODIFIER ANIMAL      *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  5-SUPPRIMER ANIMAL     *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  6-STATISTICS           *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  0-QUITTER LE PROGRAM   *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t***************************\n\n");
    printf("\t\t\t\t\t\t    ENTRER TON CHOIX:");

    scanf("%d",&choix);
    while(getchar()!= '\n');

    return choix;

}
void Ajoute_Menu(){ /** ajoute menu appear wwhen user type 1*/
    char Ajchoix;
    int n;
    system("cls");
    printf("\n");
    printf(CYN);
    printf("\t\t\t\t\t\t***************************\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  1-AJOUTER 1 ANIMAL    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  2-AJOUTER  PLUSIEUR    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  0-BACK TO MAIN MENU    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t***************************\n\n");
    printf("\t\t\t\t\t\t    ENTRER TON CHOIX:");

    scanf("%c",&Ajchoix);
    while(getchar()!= '\n');

    switch(Ajchoix){
        case '1' : Ajoute_Animal(); /** ajoute function let user ajoute 1 animal*/
                   break;

        case '2' : printf("\t\t\t\t\t\t Combien tu veux ajoute:"); /** start a boucle from 0 to the number user input and keep calling ajoute function*/

                   scanf("%d",&n);
                   while(getchar()!= '\n');
                   if(Total_Animaux + n >= Max_animal){
                   printf("Cannot add more animals. Maximum capacity reached!\n");

                   }else{

                           for(int i=0;i<n;i++){
                             Ajoute_Animal();
                           }
                   }
                   break;
        case '0' : break;
        default  : printf("invalid choix");
    }
}
void Ajoute_Animal(){ /** ajoute function let user ajoute 1 animal*/

    if(Total_Animaux >= Max_animal){
    printf("impossible,Maximum capacity reached!\n");
    return;
    }

    int habitat,categorie;

    system("cls");
    printf("\t\t\t\t\t\t*********** ANIMAL %d ************\n",Total_Animaux+1);
    Animal[Total_Animaux].Id = current_id;

    do{
    printf("\t\t\t\t\t\t  NOM :");
    fgets(Animal[Total_Animaux].Name,Max,stdin);
    Animal[Total_Animaux].Name[strcspn(Animal[Total_Animaux].Name,"\n")]='\0';

    }while(strlen(Animal[Total_Animaux].Name)<3);

    do{
    printf("\t\t\t\t\t\t  ESPECE :");
    fgets(Animal[Total_Animaux].Espece,Max,stdin);
    Animal[Total_Animaux].Espece[strcspn(Animal[Total_Animaux].Espece,"\n")]='\0';
    }while(strlen(Animal[Total_Animaux].Espece)<3);

    do{

    printf("\t\t\t\t\t\t  AGE :");
    scanf("%d",&Animal[Total_Animaux].Age);
    while(getchar()!='\n');

    if(Animal[Total_Animaux].Age<0){
        printf("\t\t\t\t\t\t  please ENter A valid age\n");
    }

    }while(Animal[Total_Animaux].Age<0);

    do{
    printf("\t\t\t\t\t\t  Poids :");
    scanf("%d",&Animal[Total_Animaux].Poids);
    while(getchar()!='\n');

    if(Animal[Total_Animaux].Poids<0){
        printf("\t\t\t\t\t\t  please ENter A valid poids\n");
    }

    }while(Animal[Total_Animaux].Poids<0);


    do{
    printf("\n");
    printf("\t\t\t\t\t\t  1 pour desert   2 pour savane \n");
    printf("\t\t\t\t\t\t  3 pour jungle   4 pour la mer \n");
    printf("\t\t\t\t\t\t  5 pour prairi   6 pour Autre  \n");
    printf("\n");
    printf("\t\t\t\t\t\t  Habitat:");

    scanf("%d",&habitat);
    while(getchar()!='\n');

    switch(habitat){
        case 1:strcpy(Animal[Total_Animaux].Habitat,"DESERT");
        break;
        case 2:strcpy(Animal[Total_Animaux].Habitat,"SAVANE");
        break;
        case 3:strcpy(Animal[Total_Animaux].Habitat,"JUNGLE");
        break;
        case 4:strcpy(Animal[Total_Animaux].Habitat,"OCEAN");
        break;
        case 5:strcpy(Animal[Total_Animaux].Habitat,"PRAIRI");
        break;
        case 6:strcpy(Animal[Total_Animaux].Habitat,"AUTRE");
        break;
        default:printf("\t\t\t\t\t\t  please choose from menu");
    }

    }while(habitat<1 || habitat>6);

    do{
    printf("\n");
    printf("\t\t\t\t\t\t   1 carnivores    2 herbivores  \n");
    printf("\t\t\t\t\t\t          3 omnivores           \n");
    printf("\n");
    printf("\t\t\t\t\t\t  categorie:");

    scanf("%d",&categorie);
    while(getchar()!='\n');

    switch(categorie){
        case 1:strcpy(Animal[Total_Animaux].Categorie,"CARNIVORES");
        break;
        case 2:strcpy(Animal[Total_Animaux].Categorie,"HERBIVORES");
        break;
        case 3:strcpy(Animal[Total_Animaux].Categorie,"OMNIVORES");
        break;
        default:printf("\t\t\t\t\t\t  please choose from menu");
    }

    }while(categorie<1 || categorie>3);


    time_t inscreption;
    time(&inscreption);
    strcpy(Animal[Total_Animaux].date_inscription,ctime(&inscreption));

    Total_Animaux++;
    current_id++;
    printf("\n\t\t\t\t\t*****L'Ajoute effectuee avec succes!*****\n");

}
void Affichage_Menu(){ /** affichage menu appear wwhen user type 2*/
    char Afchoix;
    int n;
    system("cls");
    printf("\n");
    printf(YELLOW);
    printf("\t\t\t\t\t\t***************************\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  1-AFFICHER ANIMEAUX    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  2-TRIER PAR NOM        *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  3-TRIER PAD AGE        *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  4-SPECIFIQUE HABITAT   *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  0-BACK TO MAIN MENU    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t***************************\n\n");
    printf("\t\t\t\t\t\t    ENTRER TON CHOIX:");

    scanf("%c",&Afchoix);
    while(getchar()!= '\n');

    switch(Afchoix){
        case '1' : afficher_Tous_Animeaux();
                   break;

        case '2' : Trier_par_Nom();
                   break;
        case '3' : Trier_par_Age();
                   break;
        case '4' : affiche_Par_Habitat();
                   break;
        case '0' : break;
        default  : printf("invalid choix");
    }
}
void afficher_Tous_Animeaux(){ /** affichage all animals by running a boucle calling afichage function*/
    system("cls");
    printf("==========================================================================================================\n");
    printf("| Id  | Name        | Espece        | Age  | Poids | Habitat    | categorie  | Date Inscreption          |\n");
    printf("==========================================================================================================\n");

    for(int i=0;i<Total_Animaux;i++){
        afficher_un_animal(i);
    }
    printf("==========================================================================================================\n");
}
void afficher_un_animal(int i){ /** affichage single animal at time*/

    if(i == -1){

    printf("|                                          not found                                                    |\n");

    }else{
     printf("| %-3d | %-11s | %-13s | %-4d | %-5d | %-10s | %-10s | %-27s |\n"
            ,Animal[i].Id
            ,Animal[i].Name
            ,Animal[i].Espece
            ,Animal[i].Age
            ,Animal[i].Poids
            ,Animal[i].Habitat
            ,Animal[i].Categorie
            ,Animal[i].date_inscription);
    }
}
void Trier_par_Age(){  /** trier animaaux par ech one id it appears in afichage menu */

    Animaux temp;

    for(int i=0;i<Total_Animaux;i++){
        for(int j=0;j<Total_Animaux-i-1;j++){
            if(Animal[j].Age>Animal[j+1].Age){
                temp=Animal[j];
                Animal[j]=Animal[j+1];
                Animal[j+1]=temp;
            }
        }
    }
    afficher_Tous_Animeaux();
}
void Trier_par_Nom(){  /** trier animaaux par each one name it apears in affichage menu*/
   Animaux temp;

    for(int i=0;i<Total_Animaux;i++){
        for(int j=0;j<Total_Animaux-i-1;j++){
            if(strcmp(Animal[j].Name,Animal[j+1].Name)>0){
                temp=Animal[j];
                Animal[j]=Animal[j+1];
                Animal[j+1]=temp;
            }
        }
    }
    afficher_Tous_Animeaux();
}
void affiche_Par_Habitat(){ /** affichage a specific habitat it apears in affichage menu*/
    char habitat[50];
    int found =0;

    printf("\t\t\t\t\t\t ENTER HABITAT CHERCHER:");
    fgets(habitat,50,stdin);
    habitat[strcspn(habitat,"\n")]='\0';
    system("cls");
    printf("==========================================================================================================\n");
    printf("| Id  | Name        | Espece        | Age  | Poids | Habitat    | categorie  | Date Inscreption          |\n");
    printf("==========================================================================================================\n");

    for(int i=0;i<Total_Animaux;i++){
        if(strcmpi(Animal[i].Habitat,habitat)==0){
            afficher_un_animal(i);
            found=1;
        }
    }
    if (found == 0){
            printf("\t\t\t\t\t there is no animal in the zoo that lives in %s\n",habitat);
    }

}
void Recherche_Menu(){ /** recherche menu appears when user type 3*/
    char choix;
    system("cls");
    printf("\n");
    printf(MAG);
    printf("\t\t\t\t\t\t***************************\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  1-RECHERCHE PAR ID     *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  2-RECHERCHE PAR NOM    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  3-RECHERCHE PAR ESPECE *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t*  0-BACK TO MAIN MENU    *\n");
    printf("\t\t\t\t\t\t*                         *\n");
    printf("\t\t\t\t\t\t***************************\n\n");
    printf("\t\t\t\t\t\t    ENTRER TON CHOIX:");
    scanf("%c",&choix);
    while(getchar()!= '\n');

    switch(choix){
        case '1': afficher_un_animal(Recherche_Par_ID());
                 break;
        case '2': Recherche_Par_Nom();
                 break;
        case '3': Recherche_Par_Espece();
                 break;
        case '0': break;
        default: printf("\t\t\t\t\t\tChoix invalide!\n");
    }
}
int Recherche_Par_ID(){ /** Recherche par each animal id and return the index of animal*/
   int id_recherche;
   printf("\n\t\t\t\t\t\t Entrez l'ID a rechercher: ");
   scanf("%d", &id_recherche);
   while(getchar() != '\n');
    system("cls");
    printf("==========================================================================================================\n");
    printf("| Id  | Name        | Espece        | Age  | Poids | Habitat    | categorie  | Date Inscreption          |\n");
    printf("==========================================================================================================\n");
   int i, found = -1;
   for( i =0;i<Total_Animaux;i++){
     if(Animal[i].Id==id_recherche){
        found = i;
        return i;
     }
   }

   return -1;
}
int Recherche_Par_Nom(){ /** Recherche par each animal Name and return the index of animal*/
    char name[100];
    printf("\t\t\t\t\t\t ENTER NAME TO SEARCH: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';
    system("cls");
    printf("==========================================================================================================\n");
    printf("| Id  | Name        | Espece        | Age  | Poids | Habitat    | categorie  | Date Inscreption          |\n");
    printf("==========================================================================================================\n");

    int i, found = -1;
    for(i = 0; i < Total_Animaux; i++){
        if(strcmpi(Animal[i].Name, name) == 0){
            found = i;
            break;
        }
    }
    afficher_un_animal(found);
    return found;
}
void Recherche_Par_Espece(){ /** Recherche par each animal espece and return the index of animal*/
   char Espece[50];
    int found =0;

    printf("\t\t\t\t\t\t ENTER ESPECE CHERCHER:");
    fgets(Espece,50,stdin);
    Espece[strcspn(Espece,"\n")]='\0';
    system("cls");
    printf("==========================================================================================================\n");
    printf("| Id  | Name        | Espece        | Age  | Poids | Habitat    | categorie  | Date Inscreption          |\n");
    printf("==========================================================================================================\n");


    for(int i=0;i<Total_Animaux;i++){
        if(strcmpi(Animal[i].Espece,Espece)==0){
            afficher_un_animal(i);
            found=1;
        }
    }
    if (found == 0){
            printf("\t\t\t\t\t there is no %s in the zoo \n",Espece);
    }
}
void modifier_Menu(){  /** modification Menu let user to modifie an animal */
    int m_choix;
    system("cls");
    printf(BLU);
    printf("\t\t\t\t\t\t    _oo     .-.        .-.\n");
    printf("\t\t\t\t\t\t >-(_  \\  c(O_O)c    c(O_O)c\n");
    printf("\t\t\t\t\t\t    / _/ ,'.---.`,  ,'.---.`,\n");
    printf("\t\t\t\t\t\t   / /  / /|_|_|\\ \\/ /|_|_|\\ \\\n");
    printf("\t\t\t\t\t\t  / (   | \\_____/ || \\_____/ |\n");
    printf("\t\t\t\t\t\t (   `-.'. `---' .`'. `---' .`\n");
    printf("\t\t\t\t\t\t  `--.._) `-...-'    `-...-'\n\n");
    printf("\t\t\t\t\t\t********MODIFICAION********\n");
    int modifier= Recherche_Par_ID();
    afficher_un_animal(modifier);
    if (modifier == -1){
        return;
    }else{
        printf("\n\n\n\t\t\t\t\t\t What are you willing to change\n");
        printf("\t\t\t\t\t\t  1-NAME  2-Espece 3-habitat   \n");
        printf("\t\t\t\t\t\t  4-Age   5-poids  6-categorie \n");
        printf("\t\t\t\t\t\t       0- Back to menu         \n\n");
        printf("\t\t\t\t\t\t       Entrer ton choix :");
        scanf("%d",&m_choix);
        while ( getchar()!='\n');

        switch(m_choix){
             case 1:
            printf("\t\t\t\t\t\tNouveau nom: ");
            fgets(Animal[modifier].Name, Max, stdin);
            Animal[modifier].Name[strcspn(Animal[modifier].Name, "\n")] = '\0';
            break;
        case 2:
            printf("\t\t\t\t\t\tNouvelle espece: ");
            fgets(Animal[modifier].Espece, Max, stdin);
            Animal[modifier].Espece[strcspn(Animal[modifier].Espece, "\n")] = '\0';
            break;
        case 3:
            {
                int habitat;
                printf("\n\t\t\t\t\t\t  1-DESERT   2-SAVANE\n");
                printf("\t\t\t\t\t\t  3-JUNGLE   4-OCEAN\n");
                printf("\t\t\t\t\t\t  5-PRAIRI   6-AUTRE\n");
                printf("\t\t\t\t\t\tHabitat: ");
                scanf("%d", &habitat);
                while(getchar() != '\n');

                switch(habitat){
                    case 1: strcpy(Animal[modifier].Habitat, "DESERT"); break;
                    case 2: strcpy(Animal[modifier].Habitat, "SAVANE"); break;
                    case 3: strcpy(Animal[modifier].Habitat, "JUNGLE"); break;
                    case 4: strcpy(Animal[modifier].Habitat, "OCEAN"); break;
                    case 5: strcpy(Animal[modifier].Habitat, "PRAIRI"); break;
                    case 6: strcpy(Animal[modifier].Habitat, "AUTRE"); break;
                }
            }
            break;
        case 4:
            printf("\t\t\t\t\t\tNouvel age: ");
            scanf("%d", &Animal[modifier].Age);
            while(getchar() != '\n');
            break;
        case 5:
            printf("\t\t\t\t\t\tNouveau poids: ");
            scanf("%d", &Animal[modifier].Poids);
            while(getchar() != '\n');
            break;
        case 6:
            {
                int categorie;
                printf("\n\t\t\t\t\t\t  1-CARNIVORES  2-HERBIVORES\n");
                printf("\t\t\t\t\t\t  3-OMNIVORES\n");
                printf("\t\t\t\t\t\t Categorie: ");
                scanf("%d", &categorie);
                while(getchar() != '\n');

                switch(categorie){
                    case 1: strcpy(Animal[modifier].Categorie, "CARNIVORES"); break;
                    case 2: strcpy(Animal[modifier].Categorie, "HERBIVORES"); break;
                    case 3: strcpy(Animal[modifier].Categorie, "OMNIVORES"); break;
                }
            }
            break;
        case 0:
            return;
        default:
            printf("\t\t\t\t\t\tChoix invalide!\n");
            return;
         }

    printf("\n\t\t\t\t\t\t*****Modification effectuee avec succes!*****\n");
    }
}
void supprimer_Menu(){ /** suprression Menu let user to modifie an animal */
    int S_choix;
    system("cls");
    printf(RED);
    printf("\t\t\t\t\t\t    _oo     .-.        .-.\n");
    printf("\t\t\t\t\t\t >-(_  \\  c(O_O)c    c(O_O)c\n");
    printf("\t\t\t\t\t\t    / _/ ,'.---.`,  ,'.---.`,\n");
    printf("\t\t\t\t\t\t   / /  / /|_|_|\\ \\/ /|_|_|\\ \\\n");
    printf("\t\t\t\t\t\t  / (   | \\_____/ || \\_____/ |\n");
    printf("\t\t\t\t\t\t (   `-.'. `---' .`'. `---' .`\n");
    printf("\t\t\t\t\t\t  `--.._) `-...-'    `-...-'\n\n");
    printf("\t\t\t\t\t\t******** SUPRESSION ********\n");
    int suprimmer = Recherche_Par_ID();
    afficher_un_animal(suprimmer);
    if (suprimmer == -1){
        return;
    }else{
        printf("\t\t\t\t\t\tare you sure?\n");
        printf("\t\t\t\t\t\t1-confirmer\n");
        printf("\t\t\t\t\t\t2-Annulle\n");
        printf("\t\t\t\t\t\tEntre ton choix:");
        scanf("%d",&S_choix);
        switch(S_choix){
             case 1 : for(int i=suprimmer;i<Total_Animaux;i++){
                         Animal[i]=Animal[i+1];
                      }
                      Total_Animaux--;
                      printf("\t\t\t\t\t\t*********suppression effectuee avec succes!**********\n");
                      break;
             case 2 : printf("\t\t\t\t\t\t*********suppression Anuller**********\n");
                      break;
            default : printf("\t\t\t\t\t\tinvalid choix\n");
        }
    }
}
void statistics(){ /** statistics of moyen age,poids,plus viuex,plus jeune et plus espece */
    if(Total_Animaux==0){
        printf("there is no data !!");
        return;
    }

    int total_age=0,total_Poids=0,min_Age,max_Age;
    char min_name[50],max_name[50];
    char plus_espece[100];
    int nombre_espece=0,max_espece=0;
    float moyen_age,moyen_poids;

    min_Age=Animal[0].Age;
    max_Age=Animal[0].Age;

    for(int i =0;i<Total_Animaux;i++){

        total_age+=Animal[i].Age;
        total_Poids+=Animal[i].Poids;

        if(Animal[i].Age<min_Age){
            min_Age=Animal[i].Age;
            strcpy(min_name,Animal[i].Name);
        }
        if(Animal[i].Age>max_Age){
            max_Age=Animal[i].Age;
            strcpy(max_name,Animal[i].Name);
        }
    }
    moyen_age = (float)total_age/Total_Animaux;
    moyen_poids =(float)total_Poids/Total_Animaux;


    for(int i=0;i<Total_Animaux;i++){
        nombre_espece=0;
        for(int j =0;j<Total_Animaux;j++){
            if(strcmpi(Animal[i].Espece,Animal[j].Espece)==0){
                nombre_espece++;
            }

        }
        if(nombre_espece>max_espece){
            max_espece=nombre_espece;
            strcpy(plus_espece,Animal[i].Espece);
        }
    }

    system("cls");
    printf(ROSE);
    printf("\t\t\t\t\t\t    _oo     .-.        .-.\n");
    printf("\t\t\t\t\t\t >-(_  \\  c(O_O)c    c(O_O)c\n");
    printf("\t\t\t\t\t\t    / _/ ,'.---.`,  ,'.---.`,\n");
    printf("\t\t\t\t\t\t   / /  / /|_|_|\\ \\/ /|_|_|\\ \\\n");
    printf("\t\t\t\t\t\t  / (   | \\_____/ || \\_____/ |\n");
    printf("\t\t\t\t\t\t (   `-.'. `---' .`'. `---' .`\n");
    printf("\t\t\t\t\t\t  `--.._) `-...-'    `-...-'\n\n");
    printf("\t\t\t\t\t\t*********STATISTICS********\n");
    printf("\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t  Total Animaux : %d\n",Total_Animaux);
    printf("\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t  Moyen AGE: %.2f\n",moyen_age);
    printf("\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t  moyen poids: %.2f\n",moyen_poids);
    printf("\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t  plus jeune : %s %d\n",min_name,min_Age);
    printf("\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t  plus vieux : %s %d\n",max_name,max_Age);
    printf("\t\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t  plus Espece : %s\n",plus_espece);
    printf("\t\t\t\t\t\t\n");;
    printf("\t\t\t\t\t\t***************************\n\n");
}
