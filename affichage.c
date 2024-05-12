#include "affichage.h"
#include "conversion.h"

void affichageLongLat(struct dmsInfo d){
    printf("%d°%d\'%.2f\"\n",d.degre,d.minute,d.second);
}

void affichageHeure(struct heureInfo h){
    printf("%dh%dm%ds\n",h.heure,h.minute,h.second);
}

int affichageMenu(){
    int choix = -1;
    printf("Comment voulez-vous lire vos données? Veuillez choisir l'une des méthodes suivantes pour commencer:\n");
    printf("1 - Saisir mes données manuellement\n");
    printf("2 - Lire mes données à partir d'un fichier\n");
    printf("0 - Je quitte l'application\n");
    scanf("%d",&choix);
        while(choix<0||choix>2){
            printf("\nErreur de saisie, veuillez réessayer.\n\n");
            affichageMenu(&choix);
            scanf("%d",&choix);
        } 
    return choix;
}