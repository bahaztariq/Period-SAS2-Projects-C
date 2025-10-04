#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


#define MAX_STRING 100
#define MAX_JOUEUR 100

#define post1 "gardien"
#define post2 "defenseur"
#define post3 "milieu"
#define post4 "attaquant"

#define statu1 "titulaire"
#define statu2 "remplacant"

typedef struct {
    int id;
    char nom[MAX_STRING];
    char prenom[MAX_STRING];
    int age;
    int numeroMaillot;
    char poste[MAX_STRING];
    int buts;
    char dateInscription[MAX_STRING];
    char status[MAX_STRING];
}Joueur;

Joueur joueurs[MAX_JOUEUR] =  {     {1,"Pedri","Gonzalez", 22, 8, "milieu", 37, "01/09/2021", "titulaire"},
                                    {2,"Joan","Garcia", 24, 13, "gardien", 0, "21/08/2025", "titulaire"},
                                    {3,"Ronald","Araujo", 26, 4, "defenseur", 18, "10/05/2018", "remplacant"},
                                    {4,"Christensen","Andreas", 29, 15, "defenseur", 23, "06/09/2022", "remplacant"},
                                    {5,"Lamine","Yamal", 18, 10, "attaquant", 41, "21/05/2023", "titulaire"}
                                };

//Joueur joueurs[MAX_JOUEUR];

int nbJoueur = 5;

//declaration de fonctions
int menu();
void generateChoix(int choix);
void ajouterJoueur();
void afficherListdeJoueurs();
void sortParNom(Joueur joueur[], int nbJoueur);
void sortParAge(Joueur joueur[], int nbJoueur);
void afficherParPost(Joueur joueur[], int nbJoueur);
void rechercherParId(int Id);
void rechercherParNom(char nomreChercher[]);
void modifierJoueur(int Id);
void suppremerJoueur(int Id);
void statistiques();


int main() {

    system("cls");
    printf("\t\t\t\t\t====================================================\n");
    printf("\t\t\t\t\t\t     WELCOME TO TEAM BARCELONA \n");
    printf("\t\t\t\t\t====================================================\n\n");
    getchar();

    int choix;

    do {
        system("cls");
        choix = menu();
        generateChoix(choix);
    } while (choix != 0);

    return 0;
}

int menu() {
    int choix;
    printf("\n\t\t\t\t=================== FOOTBALL TEAM MANAGEMENT ===================\n");
    printf("\t\t\t\t\t\t1 - Ajouter un joueur\n");
    printf("\t\t\t\t\t\t2 - Afficher la liste de tous les joueurs\n");
    printf("\t\t\t\t\t\t3 - Rechercher un joueur\n");
    printf("\t\t\t\t\t\t4 - Modifier un joueur\n");
    printf("\t\t\t\t\t\t5 - Supprimer un joueur\n");
    printf("\t\t\t\t\t\t6 - Statistiques \n");
    printf("\t\t\t\t\t\t0 - Quitter\n");
    printf("\t\t\t\t===============================================================\n\n\n");
    printf("\t\t\t\t\t\t=>    Entrez votre choix : ");
    scanf("%d", &choix);
    getchar();

    return choix;
}

void generateChoix(int choix){
    char nomRechercher[MAX_STRING];
    int Id;
    int choixId;
    switch(choix){
        case 1:
            system("cls");
            printf("\t\t\t\t =================== Page d'Ajoute =====================\n\n");
            ajouterJoueur();
            break;
        case 2:
            system("cls");
            printf("\t\t\t\t =================== Page d'Affichage =====================\n\n");
            afficherListdeJoueurs();
            break;
        case 3:
            system("cls");
            printf("\t\t\t\t =================== Page de Recherche =====================\n\n");
            printf("\t\t\t\t\t\t   Do you want to search by : \n\n");
            printf("\t\t\t\t\t\t\t1- Id");
            printf("\t2- Nom\n\n");
            printf("\t\t\t\t\t\t=>    Entrez votre choix : ");
            scanf("%d", &choixId);
            getchar();
            if(choixId == 1){
                printf("Entrez l'id : ");
                scanf("%d", &Id);
                getchar();
                rechercherParId(Id);
            }
            else if(choixId == 2){
                printf("Entrez le nom Rechercher : ");
                fgets(nomRechercher, MAX_STRING, stdin);
                nomRechercher[strcspn(nomRechercher, "\n")] = '\0';
                rechercherParNom(nomRechercher);
            }
            break;
        case 4:
            system("cls");
            printf("Entrez l'Id de Joueur Vous souhaitez modifier : ");
            scanf("%d", &choixId);
            modifierJoueur(choixId);
            break;
        case 5:
            system("cls");
            printf("Entrez l'Id de Joueur Vous souhaitez Supprimer : ");
            scanf("%d", &choixId);
            suppremerJoueur(choixId);
            break;
        case 6:
            system("cls");
            statistiques();
            break;
        case 0:
            break;
        default :
            printf("Invalid Choix");
            break;
    }
    printf("\n\n\t\t\t\t\t  Appuyez sur une touche pour continuer...");
    getchar();
}

void ajouterJoueur(){
    int addNombre;
    int choix;
    time_t dateIn = time(NULL);
    struct tm *local = localtime(&dateIn);
    char arrdate[50];
    strftime(arrdate, sizeof(arrdate), "%d/%m/%Y", local);

    printf("\t\t\t\t      Combien de joueurs souhaitez-vous ajouter : ");
    scanf("%d", &addNombre);
    getchar();


    if(addNombre + nbJoueur > MAX_JOUEUR){
        printf("\n\t\t  Eurror : vous ne pouvez pas ajouter %d joueurs. Il ne reste que %d places disponibles. !!!\n", addNombre, MAX_JOUEUR - nbJoueur);
        return;
    }

    for(int i = 0; i < addNombre; i++){
        printf("\n\t\t\t\t\t\t\tJoueur #%d \n", i + 1);
        printf("\n\t\t\t\t\t\t  Entrez le nom du joueur :");
        fgets(joueurs[nbJoueur].nom, MAX_STRING, stdin);
        joueurs[nbJoueur].nom[strcspn(joueurs[nbJoueur].nom, "\n")] = '\0';
        joueurs[nbJoueur].nom[0] = toupper(joueurs[nbJoueur].nom[0]);

        printf("\n\t\t\t\t\t\t  Entrez le prenom de Joueur : ");
        fgets(joueurs[nbJoueur].prenom, MAX_STRING, stdin);
        joueurs[nbJoueur].prenom[strcspn(joueurs[nbJoueur].prenom, "\n")] = '\0';
        joueurs[nbJoueur].prenom[0] = toupper(joueurs[nbJoueur].prenom[0]);

        printf("\n\t\t\t\t\t\t  Entrez dans l'age de Joueur : ");
        scanf("%d", &joueurs[nbJoueur].age);
        getchar();

        printf("\n\t\t\t\t\t\t  Entrez le numero de maillot : ");
        scanf("%d", &joueurs[nbJoueur].numeroMaillot);
        getchar();

        repeatPostChoix:
        printf("\n\t\t\t\t\t\t  Entrez le poste de Joueur : \n");
        printf("\n\t\t\t\t\t\t  1- gardien\t2- defenseur\n");
        printf("\n\t\t\t\t\t\t  3- milieu\t4- attaquant\n");
        printf("\n\t\t\t\t\t\t=>  Entrez post : ");
        scanf("%d", &choix);
        getchar();

        switch(choix){
            case 1:
                strcpy(joueurs[nbJoueur].poste, post1);
                break;
            case 2:
                strcpy(joueurs[nbJoueur].poste, post2);
                break;
            case 3:
                strcpy(joueurs[nbJoueur].poste, post3);
                break;
            case 4:
                strcpy(joueurs[nbJoueur].poste, post4);
                break;
            default :
                printf("Invalid Choix :(\n");
                goto repeatPostChoix;
                break;

        }
        printf("\n\t\t\t\t\t\t  Veuillez saisir le nombre de buts marques par le joueur : ");
        scanf("%d", &joueurs[nbJoueur].buts);
        getchar();
        printf("Entrez status de joueur : \n");
        printf("1- titulaire\n");
        printf("2- remplaçant\n");
        printf("Entrez Statut : ");
        scanf("%d", &choix);
        if(choix == 1){
            strcpy(joueurs[nbJoueur].status, statu1);
        }
        else if(choix == 2){
            strcpy(joueurs[nbJoueur].status, statu2);
        }
        strcpy(joueurs[nbJoueur].dateInscription, arrdate);
        joueurs[nbJoueur].id = nbJoueur + 1;
        nbJoueur++;

    }
    if(nbJoueur > 1){
        printf("\n\t\t\t\t\t\t  You have add the players with success :) \n");
    }
    else{
        printf("\n\t\t\t\t\t\t  You have add the player with success :) \n");
    }

}

void afficherListdeJoueurs(){
    int choix;

    printf("\n\n\t\t\t\t\t  1- Trier les joueurs par ordre alphabetique\n");
    printf("\n\n\t\t\t\t\t  2- Trier les joueurs par age.\n");
    printf("\n\n\t\t\t\t\t  3- Afficher les joueurs par poste.\n");
    printf("\n\n\t\t\t\t\t=> Entrez ton choix : ");
    scanf("%d", &choix);
    getchar();

    switch(choix){
        case 1:
            sortParNom(joueurs, nbJoueur);
            break;
        case 2:
            sortParAge(joueurs, nbJoueur);
            break;
        case 3:
            afficherParPost(joueurs, nbJoueur);
            break;
        default:
            printf("Invalid Choix !!");
            break;
    }

    if(nbJoueur == 0){
        printf("There is No Player in the List ");
        return;
    }
}

void sortParNom(Joueur joueur[], int nbJoueur){
    Joueur temp;

    int i, j;

    for(i = 0; i < nbJoueur; i++){
        if(joueur[i].nom[0] != '\0'){
            joueur[i].nom[0]  = toupper(joueur[i].nom[0]);
        }
    }
    for(i = 0; i < nbJoueur - 1; i++){
        for(j = i + 1; j < nbJoueur; j++){
            if(strcmp(joueur[i].nom, joueur[j].nom) > 0){
                temp = joueur[i];
                joueur[i] = joueur[j];
                joueur[j] = temp;
            }
        }
    }
    for(int i = 0; i < nbJoueur; i++){
        printf("-----------------------------\n");
        printf("Nom              : %s\n", joueurs[i].nom);
        printf("Prenom           : %s\n", joueurs[i].prenom);
        printf("age              : %d\n", joueurs[i].age);
        printf("Numero Maillot   : %d\n", joueurs[i].numeroMaillot);
        printf("poste            : %s\n", joueurs[i].poste);
        printf("Buts             : %d\n", joueurs[i].buts);
        printf("Status           : %s\n", joueurs[i].status);
        printf("Date Inscription : %s\n", joueurs[i].dateInscription);
        printf("-----------------------------\n");
    }
}
void sortParAge(Joueur joueur[], int nbJoueur){

    Joueur temp;

    int i, j;

    for(i = 0; i < nbJoueur - 1; i++){
        for(j = i + 1; j < nbJoueur; j++){
            if(joueur[i].age > joueur[j].age){
                temp = joueur[i];
                joueur[i] = joueur[j];
                joueur[j] = temp;
            }
        }
    }
    for(int i = 0; i < nbJoueur; i++){
        printf("-----------------------------\n");
        printf("Nom              : %s\n", joueurs[i].nom);
        printf("Prenom           : %s\n", joueurs[i].prenom);
        printf("age              : %d\n", joueurs[i].age);
        printf("Numero Maillot   : %d\n", joueurs[i].numeroMaillot);
        printf("poste            : %s\n", joueurs[i].poste);
        printf("Buts             : %d\n", joueurs[i].buts);
        printf("Status           : %s\n", joueurs[i].status);
        printf("Date Inscription : %s\n", joueurs[i].dateInscription);
        printf("-----------------------------\n");
    }
}

void afficherParPost(Joueur joueur[], int nbJoueur){

    Joueur filtred[MAX_JOUEUR];
    int choixdePost;
    int j = 0;


    repeatPostChoix:
    printf("Entrez le poste : \n");
    printf("1- gardien\t2- defenseur\n3- milieu\t4- attaquant\n");
    printf("Entrez post : ");
    scanf("%d", &choixdePost);
    getchar();

    switch(choixdePost){
        case 1:
            for(int i = 0; i < nbJoueur; i++){
                if(strcmp(joueur[i].poste, post1) == 0){
                    filtred[j++] = joueur[i];
                }
            }
            break;
        case 2:
            for(int i = 0; i < nbJoueur; i++){
                if(strcmp(joueur[i].poste, post2) == 0){
                    filtred[j++] = joueur[i];
                }
            }
            break;
        case 3:
            for(int i = 0; i < nbJoueur; i++){
                if(strcmp(joueur[i].poste, post3) == 0){
                    filtred[j++] = joueur[i];
                }
            }
            break;
        case 4:
            for(int i = 0; i < nbJoueur; i++){
                if(strcmp(joueur[i].poste, post4) == 0){
                    filtred[j++] = joueur[i];
                }
            }
            break;
        default :
            printf("Invalid Choix :(\n");
            goto repeatPostChoix;
            break;
    }

    if(j == 0){
        printf("Il n'y a aucun joueur avec ce poste\n");
    }else{

        switch(choixdePost){
            case 1:
                printf("----------------\n");
                printf("gardiens\n");
                printf("----------------\n");
                break;
            case 2:
                printf("----------------\n");
                printf("defenseurs\n");
                printf("----------------\n");
                break;
            case 3:
                printf("----------------\n");
                printf("milieus\n");
                printf("----------------\n");
                break;
            case 4:
                printf("----------------\n");
                printf("attaquants\n");
                printf("----------------\n");
                break;
            default:
                break;
        }
        for(int i = 0; i < j; i++){
            printf("-------------------------\n");
            printf("Joueur #%d\n", i + 1);
            printf("Nom              : %s\n", filtred[i].nom);
            printf("Prenom           : %s\n", filtred[i].prenom);
            printf("age              : %d\n", filtred[i].age);
            printf("numero Maillot   : %d\n", filtred[i].numeroMaillot);
            printf("Poste            : %s\n", joueurs[i].poste);
            printf("Buts             : %d\n", filtred[i].buts);
            printf("Status           : %s\n", filtred[i].status);
            printf("Date Inscription : %s\n", filtred[i].dateInscription);
            printf("-------------------------\n");
        }
    }
}

void rechercherParId(int Id){
    int found = 0;

    for(int i = 0; i < nbJoueur; i++){
        if(joueurs[i].id == Id){
            found = 1;
            printf("-------------------------\n");
            printf("Nom              : %s\n", joueurs[i].nom);
            printf("Prenom           : %s\n", joueurs[i].prenom);
            printf("age              : %d\n", joueurs[i].age);
            printf("numero Maillot   : %d\n", joueurs[i].numeroMaillot);
            printf("Poste            : %s\n", joueurs[i].poste);
            printf("Buts             : %s\n", joueurs[i].buts);
            printf("Date Inscription : %s\n", joueurs[i].dateInscription);
            printf("-------------------------\n");
        }
    }
    if(found == 0){
        printf("there is no player with that Id");
    }

}
void rechercherParNom(char nomreChercher[]){
    int found = 0;
    Joueur deletedJoueur[MAX_JOUEUR];
    int j = 0;

    nomreChercher[0] = toupper(nomreChercher[0]);

    for(int i = 0; i < nbJoueur; i++){
        if(strcmp(joueurs[i].nom, nomreChercher) == 0){
            deletedJoueur[j++] = joueurs[i];
        }
    }

    for(int i = 0; i < j; i++){
            found = 1;
            printf("-------------------------\n");
            printf("Nom              : %s\n", deletedJoueur[i].nom);
            printf("Prenom           : %s\n", deletedJoueur[i].prenom);
            printf("age              : %d\n", deletedJoueur[i].age);
            printf("numero Maillot   : %d\n", deletedJoueur[i].numeroMaillot);
            printf("Poste            : %s\n", deletedJoueur[i].poste);
            printf("Buts             : %d\n", deletedJoueur[i].buts);
            printf("Status           : %s\n", deletedJoueur[i].status);
            printf("Date Inscription : %s\n", deletedJoueur[i].dateInscription);
            printf("-------------------------\n");
    }

    if(found == 0){
        printf("there is no player with that Id");
    }
}


void modifierJoueur(int Id){
    int found = 0;
    int Choix;
    int choixdePost;

    for(int i = 0; i < nbJoueur; i++){
        if(joueurs[i].id == Id){
            found = 1;
            printf("-------------------------\n");
            printf("Nom              : %s\n", joueurs[i].nom);
            printf("Prenom           : %s\n", joueurs[i].prenom);
            printf("age              : %d\n", joueurs[i].age);
            printf("numero Maillot   : %d\n", joueurs[i].numeroMaillot);
            printf("Poste            : %s\n", joueurs[i].poste);
            printf("Buts             : %d\n", joueurs[i].buts);
            printf("Status           : %s\n", joueurs[i].status);
            printf("Date Inscription : %s\n", joueurs[i].dateInscription);
            printf("-------------------------\n");

            printf("What do you want to edit \n");
            printf("1- le poste un joueur.\n");
            printf("2- age d un joueur.\n");
            printf("3- le nombre de buts marques par un joueur.\n");
            printf("4- nothing\n");
            printf("Entrez ton choix : ");
            scanf("%d", &Choix);
            getchar();
            switch(Choix){
                case 1:
                    printf("Poste          : %s\n", joueurs[i].poste);
                    printf("Entrez le Nouveau Poste : \n");
                    printf("Entrez le poste : \n");
                    printf("1- gardien\t2- defenseur\n3- milieu\t4- attaquant\n");
                    printf("Entrez post : ");
                    scanf("%d", &choixdePost);
                    getchar();
                    switch(choixdePost){
                        case 1:
                            strcpy(joueurs[i].poste, post1);
                            break;
                        case 2:
                            strcpy(joueurs[i].poste, post2);
                            break;
                        case 3:
                            strcpy(joueurs[i].poste, post3);
                            break;
                        case 4:
                            strcpy(joueurs[i].poste, post4);
                            break;
                        default:
                            printf("Invalid Choix ....\n");
                            break;
                    }
                    printf("You have edited the Poste\n");
                    break;
                case 2:
                    printf("Age          : %d\n", joueurs[i].age);
                    printf("Entrez le Nouveau Age : \n");
                    scanf("%d", &joueurs[i].age);
                    getchar();
                    printf("You have edited the Age\n");
                    break;
                case 3:
                    printf("Buts          : %d\n", joueurs[i].buts);
                    printf("Entrez le Nouveau Nombre de buts : \n");
                    scanf("%d", &joueurs[i].buts);
                    getchar();
                    printf("You have edited the Age\n");
                    break;
            }
            }
    }
    if(found == 0){
        printf("there is no player with that Id");
    }
}
void suppremerJoueur(int Id){

    int found = 0;
    int Choix;

    for(int i = 0; i < nbJoueur; i++){
        if(joueurs[i].id == Id){
            found = 1;
            printf("-------------------------\n");
            printf("Nom              : %s\n", joueurs[i].nom);
            printf("Prenom           : %s\n", joueurs[i].prenom);
            printf("age              : %d\n", joueurs[i].age);
            printf("numero Maillot   : %d\n", joueurs[i].numeroMaillot);
            printf("Poste            : %s\n", joueurs[i].poste);
            printf("Buts             : %d\n", joueurs[i].buts);
            printf("Status           : %s\n", joueurs[i].status);
            printf("Date Inscription : %s\n", joueurs[i].dateInscription);
            printf("-------------------------\n");

            printf("You sure you want to supprimer : \n");
            printf("1- Oui\n");
            printf("2- Non\n");
            printf("Entrez Ton choix : ");
            scanf("%d", &Choix);
            getchar();
            if(Choix == 1){
                for(int k = i; k < nbJoueur - 1; k++){
                    joueurs[k] = joueurs[k + 1];
                }
                nbJoueur--;
            }
             break;
        }
    }
}
void statistiques(){
    int choix;
    int nbButs;
    double moyen = 0.0;
    double sum = 0.0;
    Joueur joueursWithMaxButs[MAX_JOUEUR];
    Joueur buteur;
    Joueur plusJeune;
    Joueur plusAge;
    int j = 0;
    int found = 0;

    printf("1- Afficher le nombre total de joueurs dans l equipe.\n");
    printf("2- Afficher lage moyen des joueurs.\n");
    printf("3- Afficher les joueurs ayant marque plus de X buts .\n");
    printf("4- Afficher le meilleur buteur .\n");
    printf("5- Afficher le joueur le plus jeune et le plus age.\n");
    printf("6- Retourne au menu \n");
    printf("Entrez ton Choix : ");
    scanf("%d", &choix);
    getchar();

    switch(choix){
        case 1:
            printf("Le Nombre totale de Joueurs dans lequipe est : %d\n", nbJoueur);
            break;
        case 2:
            for(int i = 0; i < nbJoueur; i++){
                sum += joueurs[i].age;
            }
            moyen = sum / nbJoueur;
            printf("Age Monyen des Joueurs est : %.2lf ans", moyen);
            break;
        case 3:
            printf("Entrez le nombre des buts : \n");
            scanf("%d", &nbButs);
            getchar();
            for(int i = 0; i < nbJoueur; i++){
                if(nbButs < joueurs[i].buts){
                    found = 1;
                    joueursWithMaxButs[j++] = joueurs[i];
                }
            }
            for(int i = 0; i < j; i++){
                printf("-------------------------\n");
                printf("Nom              : %s\n", joueursWithMaxButs[i].nom);
                printf("Prenom           : %s\n", joueursWithMaxButs[i].prenom);
                printf("age              : %d\n", joueursWithMaxButs[i].age);
                printf("numero Maillot   : %d\n", joueursWithMaxButs[i].numeroMaillot);
                printf("Poste            : %s\n", joueursWithMaxButs[i].poste);
                printf("Buts             : %d\n", joueursWithMaxButs[i].buts);
                printf("Status           : %s\n", joueursWithMaxButs[i].status);
                printf("Date Inscription : %s\n", joueursWithMaxButs[i].dateInscription);
                printf("-------------------------\n");
            }
            if(found == 0){
                printf("There is No player scored %d ", nbButs);
            }
            break;
        case 4:
            buteur = joueurs[0];
            for(int i = 1; i < nbJoueur; i++){
                if(joueurs[i].buts > buteur.buts){
                    buteur = joueurs[i];
                }
            }
            printf("le meilleur buteur est %s avec %d buts .\n", buteur.nom, buteur.buts);
            break;
        case 5:
            plusJeune = joueurs[0];
            plusAge = joueurs[0];
            for(int i = 1; i < nbJoueur; i++){
                if(joueurs[i].age < plusJeune.age){
                    plusJeune = joueurs[i];
                }
            }
            for(int i = 1; i < nbJoueur; i++){
                if(joueurs[i].age > plusAge.age){
                    plusAge = joueurs[i];
                }
            }
            printf("le joueur le plus jeune est : %s\n", plusJeune.nom);
            printf("le joueur le plus Age est : %s\n", plusAge.nom);
            break;
    }
}
