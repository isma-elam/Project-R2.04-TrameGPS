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
*  Nom du fichier : chargerRep.c                                              *
*                                                                             *
******************************************************************************/

#include "chargerRep.h"

/**
 * @file chargerRep.c
 * @brief Ce fichier contient les corps des fonctions pour charger et stocker les données GPS.
 * 
 * Les fonctions ici permettent de charger les données à partir d'un fichier ou de l'entrée standard,
 * de vérifier leur validité et de les stocker dans une structure de trames.
 * 
 * @author Ellisa EE, Ismael EL-AMRANI
 * @date 2024
 */
void charger(struct trameTab* trameTab,int* nb,char nomFic[],jmp_buf ptRep){
    FILE* file;
    *nb=0;
    file = fopen(nomFic,"r");
    struct trameInfo tInfo;
    if (file==NULL){
        printf("Impossible d'ouvrir en lecture le fichier %s\n",nomFic);
        longjmp(ptRep,CHEMIN_INVALIDE);
    }else{ 
        char ligne[LONGUEUR_TRAME]="\0";
        while (fgets(ligne, sizeof(ligne), file) != NULL && *nb < LONGUEUR_TRAME){
            if(ligne[strlen(ligne)-1]=='\n'){
                ligne[strlen(ligne)-1]=='\0';
            }
            verifier_nombre_champs(ligne,ptRep);
            verifier_type_trame(ligne,ptRep);
            verifier_format_heure(ligne,ptRep);      
            extraireInfoTrame(ligne,&tInfo);
            verifier_heure_min_sec(tInfo.heure.heure,tInfo.heure.minute,tInfo.heure.second,ptRep);
            verifier_latitude(tInfo.latitude.degre,tInfo.latitude.minute,tInfo.latitude.second,tInfo.latitude.orientation,ptRep);
            verifier_longitude(tInfo.longitude.degre,tInfo.longitude.minute,tInfo.longitude.second,tInfo.longitude.orientation,ptRep);
            trameTab->trame[*nb]=tInfo;
            (*nb)++;  
        }
    }
    fclose(file);
}

void lireDonnees(struct trameTab* trameTab,int* nb,char nomFic[],jmp_buf ptRep){
    char ligne[LONGUEUR_TRAME];
    *nb=0;
    struct trameInfo tInfo;
    scanf(" %[^\n]",ligne);
    if(ligne[strlen(ligne)-1]=='\n'){
        ligne[strlen(ligne)-1]=='\0';
    }
    while (strcmp(ligne,"exit")!=0 && *nb < LONGUEUR_TRAME){
        verifier_nombre_champs(ligne,ptRep);
        verifier_type_trame(ligne,ptRep);
        verifier_format_heure(ligne,ptRep);      
        extraireInfoTrame(ligne,&tInfo);
        verifier_heure_min_sec(tInfo.heure.heure,tInfo.heure.minute,tInfo.heure.second,ptRep);
        verifier_latitude(tInfo.latitude.degre,tInfo.latitude.minute,tInfo.latitude.second,tInfo.latitude.orientation,ptRep);
        verifier_longitude(tInfo.longitude.degre,tInfo.longitude.minute,tInfo.longitude.second,tInfo.longitude.orientation,ptRep);
        trameTab->trame[*nb]=tInfo;
        (*nb)++;
        scanf(" %[^\n]",ligne);
        if(ligne[strlen(ligne)-1]=='\n'){
            ligne[strlen(ligne)-1]=='\0';
        }
    }    
}

void ranger(struct trameTab trameTab,int nb,char nomFic[]){
    FILE* file;
    int i;
    file = fopen(nomFic,"w");
    if (file == NULL){
        printf("Impossible d'ouvrir en ecriture le fichier %s\n",nomFic);
    }else{
        for (i = 0 ; i < nb ; i++){
            fprintf(file,"Heure : %dh%dm%ds ; Latitude : %d°%d\'%.2f\"%c ; Longitude : %d°%d\'%.2f\"%c\n",
            trameTab.trame[i].heure.heure,trameTab.trame[i].heure.minute,trameTab.trame[i].heure.second,
            trameTab.trame[i].latitude.degre,trameTab.trame[i].latitude.minute,trameTab.trame[i].latitude.second,trameTab.trame[i].latitude.orientation,
            trameTab.trame[i].longitude.degre,trameTab.trame[i].longitude.minute,trameTab.trame[i].longitude.second,trameTab.trame[i].longitude.orientation);
        }
    }
    fclose(file);
}