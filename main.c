#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Tache {
    char nom[100];
    char description[200];
    char date_echeance[20];
    int priorite;
    char etat[100];
};
/* ************************************************ */


void ajouterTache( struct Tache tableau[], int *taille) {

    printf("Nom de la tache : ");
    scanf(" %[^\n]",tableau[*taille].nom);

    printf("Description de la tache : ");
    scanf(" %[^\n]", tableau[*taille].description);

    printf("Date d'echeance de la tache : ");
    scanf("%s", tableau[*taille].date_echeance);

    printf("Priorite de la tache : ");
    scanf("%d", &tableau[*taille].priorite);

    printf("Etat de la tache : ");
    scanf("%s", tableau[*taille].etat);

 *taille=(*taille)+1;
     }


/* ***************************************************** */
void afficherTaches(struct Tache tableau[], int taille) {
    if (taille == 0) {
        printf("Aucune tache à afficher.\n");
    } else {
        printf("Liste des taches :\n");
        for (int i = 0; i < taille; i++) {
            printf("------------------------- index : %d ------------------------|\n", i);
            printf("Tache %d ==>\n", i + 1);
            printf("            Nom : %s\n", tableau[i].nom);
            printf("            Description : %s\n", tableau[i].description);
            printf("            Date d'echeance : %s\n", tableau[i].date_echeance);
            printf("            Priorite : %d\n", tableau[i].priorite);
            printf("            Priorite : %s\n", tableau[i].etat);
            printf("\n");
        }
    }
}
/* ************************************************ */
void modifierTache( struct Tache tableau[],int taille,int i){

if (i >= 0 && i < taille) {
    printf("Nom actuel : %s\n", tableau[i].nom);
    printf("Modifier le Nom de tache: ");
    scanf(" %[^\n]",tableau[i].nom);

    printf("Description actuelle : %s\n", tableau[i].description);
    printf("Modifier la Description de tache:: ");
    scanf(" %[^\n]", tableau[i].description);

    printf("Date d echeance actuelle : %s\n", tableau[i].date_echeance);
    printf("Modifier la Date d echeance de la tache : ");
    scanf("%s", tableau[i].date_echeance);

    printf("Priorite actuelle : %d\n", tableau[i].priorite);
    printf("Modifier la Priorite de la tache : ");
    scanf("%d", &tableau[i].priorite);

    printf("Etat actuel : %s\n", tableau[i].etat);
    printf("Modifier l Etat de la tache : ");
    scanf("%s", tableau[i].etat);

}
}
/* ******************************************************* */
void supprimerTache(struct Tache tableau[], int *taille, int index) {


    if (index < 0 || index >= *taille) {
        printf("Index invalide.\n");
        return;}

    for (int i = index; i < *taille - 1; i++) {
       printf("Index invalide.................................................\n");
    }
    (*taille)--;

}
/* ************************************************************* */
void filtrerParDate(struct Tache tableau[], int taille, char date[]) {
    for (int i = 0; i < taille; i++) {
        if (strcmp(tableau[i].date_echeance, date) == 0) {
            printf("|--------------------------------------------|\n");
            printf("Nom : %s\n", tableau[i].nom);
            printf("Description : %s\n", tableau[i].description);
            printf("Date d echeance : %s\n", tableau[i].date_echeance);
            printf("Priorite : %d\n", tableau[i].priorite);
            printf("etat : %s\n", tableau[i].etat);
            printf("\n");
            printf("|--------------------------------------------|\n");
        }

        }

}
/* ******************************************** */
void filtrerParPriorite(struct Tache tableau[], int taille, int priorite) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i].priorite == priorite) {
                            printf("|--------------------------------------------|\n");
            printf("Nom : %s\n", tableau[i].nom);
            printf("Description : %s\n", tableau[i].description);
            printf("Date d echeance : %s\n", tableau[i].date_echeance);
            printf("Priorite : %d\n", tableau[i].priorite);
            printf("Etat : %s\n", tableau[i].etat);
            printf("\n");
                    printf("|--------------------------------------------|\n");
        }
    }
}
/* ******************************************************** */
  void Terminer(struct Tache tableau[],int taille,int i) {
    printf("Etat actuel : %s\n", tableau[i].etat);
    printf("Modifier l Etat de la tache : ");
    scanf("%s", tableau[i].etat);

    }


int main()
{

struct Tache tableauTaches[100];
int menu =0;
bool flag =true;
int taille=0;
int *tailleTableau = &taille ;

    strcpy(tableauTaches[*tailleTableau].nom, "Tache 1");
    strcpy(tableauTaches[*tailleTableau].description, "Description de la tache 1");
    strcpy(tableauTaches[*tailleTableau].date_echeance, "01/01/2023");
    tableauTaches[*tailleTableau].priorite = 1;
    strcpy(tableauTaches[*tailleTableau].etat, "Non terminer");

    (*tailleTableau)++;

    strcpy(tableauTaches[*tailleTableau].nom, "Tache 2");
    strcpy(tableauTaches[*tailleTableau].description, "Description de la tache 2");
    strcpy(tableauTaches[*tailleTableau].date_echeance, "01/02/2023");
    tableauTaches[*tailleTableau].priorite = 1;
    strcpy(tableauTaches[*tailleTableau].etat, "Non terminer");
    (*tailleTableau)++;
 while (flag) {
        printf("                              ****************** menu **********************\n");
        printf("1-Ajouter une tache\n2-Modifier une tache\n3-Supprimer une tache\n4-Filtrer une tache par date\n5-Filtrer une tache par priorite\n6-Afficher toutes les taches\n7-Marquer une tache terminer\n8-Quitter\n");
        printf("Choix : ");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("Ajouter une tache\n");
            ajouterTache(tableauTaches,tailleTableau );
        }
        else if (menu == 2) {
                int index;
                 printf("je suis en modifier  to do list \n");
                 afficherTaches(tableauTaches,*tailleTableau );
                 printf("choisir l index de tache a modifier: \n");
                 scanf("%d", &index);
                 modifierTache( tableauTaches,*tailleTableau,index);
        }

        else if (menu == 3) {
            printf("Supprimer une tache\n");
            int indexSupp;
            afficherTaches(tableauTaches,*tailleTableau );
            printf("choisir l index de tache a supprimer: \n");
            scanf("%d", &indexSupp);
            supprimerTache(tableauTaches,tailleTableau,indexSupp);

        }

        else if (menu == 4) {
            char date[20];
            printf("Filtrer une tache par Date \n");
            printf("Entrer date d echence du tache :\n");
            scanf("%s",date);
            filtrerParDate(tableauTaches, *tailleTableau, date);

        }
         else if (menu == 5) {
            int p;
            printf("Filtrer une tache par priorite \n");
            printf("Entrer la priorite du tache :\n");
            scanf("%d",&p);
            filtrerParPriorite(tableauTaches, *tailleTableau, p);

        }

        else if (menu == 6) {
            printf("Afficher toutes les taches\n");

            afficherTaches(tableauTaches,*tailleTableau );
        }
         else if (menu == 7) {
           int index;
                 printf("jMarquer terminer \n");
                 afficherTaches(tableauTaches,*tailleTableau );
                 printf("choisir l index de tache terminer: \n");
                 scanf("%d", &index);
                 Terminer( tableauTaches,*tailleTableau,index);

        }

        else if (menu == 8) {
            flag = false;
        }

        else {
            printf("Option invalide\n");
        }
    }
    return 0;
}

