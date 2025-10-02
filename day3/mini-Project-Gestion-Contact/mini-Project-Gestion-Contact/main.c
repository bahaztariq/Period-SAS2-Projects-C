#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//*****************COLORS*********************
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

//*****************STRUCT DECLARATION**************
typedef struct{
    char Nom[100];
    char PhoneN[15];

    char email[50];
}Contacts;
//*******************GLOBAL VARIABLES*****************

    int N =10;
    Contacts contact[]={
                       {"tarik","0654410748","bahaztariq@gmail.com"},
                       {"salma","0655484854","salma78@gmail.com"},
                       {"hassan","068748484","hassan45@gmail.com"},
                       {"youness","068486486","youness78@gmail.com"},
                       {"kawtar","0632135145","kawter45@gmail.com"},
                       {"ahmed","0654531886","ahmed121@gmail.com"},
                       {"khalid","0615135135","khalid35@gmail.com"},
                       {"omar","0635184484","omar1548@gmail.com"},
                       {"hasna","0684661455","hasna14@gmail.com"},
                       {"oussama","0651545214","oussama54@gmail.com"}
                       };

//*******************DECLARATION FUNCTIONS*************************
int Menu();
void Ajouter();
void Ajouter_contact();
void Afficher_Tous_contact();
void Afficher_Seul_contact(int i);
void rechercher();
int rechercher_Par_NOM(char c[]);
int rechercher_Par_ID(int index);
void modifier_contact(int index);
void supprimer_contact(int index);
bool isEmailValid(char T[]);
bool isNumberValid(char T[]);
int modificationMenu();

//************************main function****************************
int main(){
    int m;
    do{
        m=Menu();
        switch(m){

            case 1 : Ajouter();
                     system("PAUSE");
                     break;

            case 2 : Afficher_Tous_contact();
                     system("PAUSE");
                     break;

            case 3 : system("cls");
                     rechercher();
                     system("PAUSE");
                     break;

            case 0 : system("cls");
                     printf(GRN"\n####################\n");
                     printf("\n#  MERCI BEAUCOUP  #\n");
                     printf("\n####################\n"reset);
                     _sleep(3000);
                     exit(0);
                     break;

            default :system("cls");
                     printf(RED"\n###########INVAlid CHOIX##########\n");
                     printf("\n#  PLEASE ENTER A VALID NUMBER   #\n");
                     printf("\n##################################\n"reset);
                     system("PAUSE");

        }

    }while(1);

    return 0;
}
int Menu(){
    int choix;

    system("cls");
    printf("***********CONTACTS***********\n");
    printf("1-AJOUTER CONTACTS\n");
    printf("2-AFFICHER CONTACTS\n");
    printf("3-RECHERCHE CONTACTS\n");
    printf("0-QUITTER LE PROGRAM\n\n");
    printf("ENTRER TON CHOIX:");

    if(scanf("%d",&choix)!=true ){
        while(getchar()!= '\n');
        return -1;
    }
  return choix;
}
void Ajouter_contact(){
    system("cls");
    printf("*****************AJOUTER CONTACT****************\n\n");

    printf("ENTER THE NAME OF CONTACT %d:",N+1);
    fgets(contact[N].Nom,100,stdin);
    contact[N].Nom[strcspn(contact[N].Nom,"\n")]='\0';

    do{

    printf("ENTER THE NUMBER OF CONTACT %d:",N+1);
    fgets(contact[N].PhoneN,100,stdin);
    contact[N].PhoneN[strcspn(contact[N].PhoneN,"\n")]='\0';

    }while( !isNumberValid( contact[N].PhoneN ) );

    do{
    printf("ENTER THE EMAIL OF CONTACT %d :",N+1);
    fgets(contact[N].email,100,stdin);
    contact[N].email[strcspn(contact[N].email,"\n")]='\0';
    }while( !isEmailValid( contact[N].email ) );
    N++;
}
void Afficher_Tous_contact(){

    printf("+----------------------------------------------------------------+\n");
    printf("+ id  | Nom             | Number      | email                    |\n");

    for(int i=0;i<N;i++){
        Afficher_Seul_contact(i);
    }
}
void Afficher_Seul_contact(int i){
    if(i== -1){
    printf(RED"+----------------------------------------------------------------+\n");
    printf("|                THE USER YOU ENTERED IS NOT EXIST               |\n");
    printf("+----------------------------------------------------------------+\n"reset);
    }else{
    printf("+----------------------------------------------------------------+\n");
    printf("| %-3d | %-15s | %-11s | %-24s |\n",i+1,contact[i].Nom,contact[i].PhoneN,contact[i].email);
    printf("+----------------------------------------------------------------+\n"reset);
    }
}
bool isNumberValid(char T[]){

    int L;
    L = strlen(T);

    if(L!=10){
        return false;
        }

    if((T[0]=='0'&&T[1]=='6')||(T[0]=='0'&&T[1]=='7')){

        for(int i=2;i<L;i++){

            if(T[i]<48||T[i]>57){
               return false;
            }
        }
        return true;
    }
    return false;
}
bool isEmailValid(char T[]){

    int L = strlen(T);
    bool isArobasexist= false;
    bool isPointexist= false;
    int PosArobas,PosPoint;

    for (int i=0;i<L;i++){
        if(T[i]=='@'){
            isArobasexist =true;
            PosArobas=i;
        }else if (T[i]=='.'){
            isPointexist =true;
            PosPoint=i;
        }
    }
    int checkSpecials =strcspn(T,";:/*({['#~\]})µ%§?!$£¤¨^");

<<<<<<< HEAD
    if(L>=15 && isArobasexist && isPointexist && PosArobas+3 < PosPoint && PosPoint<L-2 && checkSpecials==L){
=======
    if(L>=14 && isArobasexist && isPointexist && PosArobas+3 < PosPoint && PosPoint<L-2 && checkSpecials==L){
>>>>>>> 751920e7312a0830d0e845bcc7b87d98bd33d8a4
        return true;
    }else{
        return false;
    }
}
void Ajouter(){

    int choix,Boucle;
    do{
    system("cls");
    printf("*******************AJOUTER****************\n");
    printf("1-AJOUTER CONTACTS\n");
    printf("0-BACK TO MAIN MENU\n");
    printf("ENTRER TON CHOIX:");

    scanf("%d",&choix);
    while( getchar()!= '\n');

    switch(choix){
        case 0 : break;
        case 1 : system("cls");
                 printf("COMBIEN TU VEUX AJOUTER:");
                 scanf("%d",&Boucle);
                 while ( getchar()!='\n');
                 for(int i=0;i<Boucle;i++){
                    Ajouter_contact();
                 }
                 break;
        default :printf("INVALID CHOIX\n");
    }
    }while(choix!=0);
}
int rechercher_Par_NOM(char T[]){
    for(int i=0;i<N;i++){
        if (strcmpi(contact[i].Nom,T)==0){
            return i;
        }
    }
    return -1;
}
int rechercher_Par_ID(int index){
    if (index>=0&&index<N){
        return index;
    }
    return -1;
}
void rechercher(){
    int R_choix,r,id;
    char T[100];
    printf("1-RECHERCHER PAR NOM\n");
    printf("2-RECHERCHER PAR ID\n");
    scanf(" %d",&R_choix);
    while ( getchar()!='\n');

    switch(R_choix){
        case 1 : printf("ENTER THE NAME OF YOUR CONTACT:");
                 fgets(T,100,stdin);
                 T[strcspn(T,"\n")]='\0';
                 r=rechercher_Par_NOM(T);
                 Afficher_Seul_contact(r);
                 if (r!= -1){
                 switch(modificationMenu()){
                     case 1 : modifier_contact(r);
                              break;
                     case 2 : supprimer_contact(r);
                              break;
                     case 3 : break;
                     default :printf("invalid choix\n");
                 }
                 }
                 break;
        case 2 : printf("ENTER THE ID OF YOUR CONTACT:");
                 scanf(" %d",&id);
                 while ( getchar()!='\n');
                 r=rechercher_Par_ID(id);
                 Afficher_Seul_contact(r);
                 if (r!= -1){
                 switch(modificationMenu()){
                     case 1 : modifier_contact(r);
                              break;
                     case 2 : supprimer_contact(r);
                              break;
                     case 3 : break;
                     default :printf("invalid choix\n");
                 }
                 }
                 break;

    }
}
int modificationMenu(){

    int modifie;
    printf("1-Modifier ce contact\n");
    printf("2-Supprimer ce contact\n");
    printf("3-Back to menu\n");
    scanf("%d",&modifie);
    while ( getchar()!='\n');

    return modifie;

}
void supprimer_contact(int index){

    int confirmation;

    printf("**********CONFIRMATION**********\n");
    printf("1-Confirmer \n");
    printf("2-Annuler \n");
    printf("ENTRER TON CHOIX:");
    scanf("%d",&confirmation);
    while ( getchar()!='\n');

    switch(confirmation){

        case 1 : for(int i = index;i<N;i++){
                   strcpy(contact[i].Nom,contact[i+1].Nom);
                   strcpy(contact[i].PhoneN,contact[i+1].PhoneN);
                   strcpy(contact[i].email,contact[i+1].email);
                 }
                 N--;
                 printf(GRN"**********done**********\n"reset);
                 break;
        case 2 : break;
        default : printf(RED"invalid choix"reset);
    }
}
void modifier_contact(int index){


    printf("ENTER THE NAME OF CONTACT %d:",index+1);
    fgets(contact[index].Nom,100,stdin);
    contact[index].Nom[strcspn(contact[index].Nom,"\n")]='\0';

    do{

    printf("ENTER THE NUMBER OF CONTACT %d:",index+1);
    fgets(contact[index].PhoneN,100,stdin);
    contact[index].PhoneN[strcspn(contact[index].PhoneN,"\n")]='\0';

    }while( !isNumberValid( contact[index].PhoneN ) );

    do{
    printf("ENTER THE EMAIL OF CONTACT %d :",index+1);
    fgets(contact[index].email,100,stdin);
    contact[index].email[strcspn(contact[index].email,"\n")]='\0';
    }while( !isEmailValid( contact[index].email ) );

    printf(GRN"**********done**********\n"reset);
}
