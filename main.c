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
*  Nom du fichier : main.c                                                    *
*                                                                             *
******************************************************************************/

/**
 * @file main.c
 * @brief Programme principal pour l'extraction et l'affichage de données GPS.
 *
 * Ce programme permet d'extraire des trames GPS, de vérifier leur validité et de les afficher.
 * Il utilise les modules "extraction.h", "affichage.h" et "chargerRep.h".
 *
 * @author Ellisa EE, Ismael EL-AMRANI
 */

#include "extraction.h"
#include "affichage.h"
#include "chargerRep.h"
#include <string.h>

#define LG_NOM_FICHIER 50

int main(void){
    struct trameTab trameTab;
    int lgTramTab;
    jmp_buf ptRep;
    Exception anomalie;
    anomalie=setjmp(ptRep);

    switch (anomalie)
    {
    case OK: {
        int choix=affichageMenu();
        char nomFicSource[LG_NOM_FICHIER]="\0";

        switch(choix){
            case 0:
                printf("Merci. Au revoir!\n");
                break;
            case 1:
                printf("Veuillez entrer les trames GPS une par une, suivies d'un appui sur la touche Entrée. Pour terminer, veuillez entrer \"exit\".\n");
                lireDonnees(&trameTab,&lgTramTab,nomFicSource,ptRep);
                ranger(trameTab,lgTramTab,"enregistrements.txt");
                printf("Extraction d'informations terminée, les données sont enregistrées dans le fichier nommé « enregistrement.txt »\n");
                break;
            case 2:
                printf("Nom du chemin du fichier source : \n");
                scanf("%s",nomFicSource);
                charger(&trameTab,&lgTramTab,nomFicSource,ptRep);
                ranger(trameTab,lgTramTab,"enregistrements.txt");
                printf("Extraction d'informations terminée, les données sont enregistrées dans le fichier nommé « enregistrement.txt »\n");
                break;
        }

        int choixAffichage=affichageDonneesChoix();

        switch(choixAffichage){
            case 0:
                printf("Vous pouvez consulter les données dans le fichier nommé « enregistrement.txt »\n");
                printf("Merci. Au revoir!\n");
                break;
            case 1:
                affichageDonneesFichier("enregistrements.txt");
                break;
        }
        break;
    }
    case TYPE_INVALIDE:
        printf("Extraction d'information impossible : Type du format de la trame GPS NMEA 0183 n'est pas du type GPGGA.\n");
        printf("Verifier format de la trame dans le fichier source.\n");
        break;
    case NB_CHAMPS_INVALIDE:
        printf("Extraction d'information impossible : Nombre de champs invalide\n");
        printf("Verifier si la trame dans le fichier source a 15 champs en total\n");
        break;
    case FORMAT_HEURE_INVALIDE:
        printf("Extraction d'information impossible : Format de l'heure invalide.\n");
        printf("Verifier format de l'heure de la trame dans le fichier source.\n"); 
        break;
    case LATITUDE_INVALIDE:
        printf("Extraction d'information impossible : Valeur du latitude invalide.\n");
        printf("Verifier valeur du latitude de la trame dans le fichier source.\n");
        break;
    case LONGITUDE_INVALIDE:
        printf("Extraction d'information impossible : Valeur du longitude invalide.\n");
        printf("Verifier valeur du longitude de la trame dans le fichier source.\n");   
    default:
        break;
    }
}