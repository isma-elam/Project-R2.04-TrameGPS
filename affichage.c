/******************************************************************************
*  ASR => 4R2.04                                                              *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 1                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Analyse de trames GPS                                           *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : EE Ellisa                                                    *
*                                                                             *
*  Nom-prénom2 : EL-AMRANI Ismaël                                             *
*                                                                             *
*  Nom-prénom3 :                                                              *
*                                                                             *
*  Nom-prénom4 :                                                              *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : affichage.c                                               *
*                                                                             *
******************************************************************************/

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

int affichageDonneesChoix(){
    int choixAffichage=0;
    printf("Voulez-vouz afficher les données? 1 - oui, 0 - non\n");
    scanf("%d",&choixAffichage);
    while (choixAffichage!=1 && choixAffichage!=0){
        printf("Veillez entrer votre choix.\n");
        printf("Voulez-vouz afficher les données? 1 - oui, 0 - non\n");
        scanf("%d",&choixAffichage);
    }
    return choixAffichage;
}

void affichageDonneesFichier(char nomFic[]){
    printf("\nContenu du fichier \"%s\" : \n",nomFic);
    FILE* file;
    file = fopen(nomFic,"r");
    if (file==NULL){
        printf("Impossible d'ouvrir en lecture le fichier %s\n",nomFic);
    }
    char c;
    if (c == EOF) {
        printf("File is empty or couldn't be read.\n");
        fclose(file);
    }
    printf("%c",c);
    while (c != EOF){
        printf("%c",c);
        c=fgetc(file);
    }
    fclose(file);
    
}