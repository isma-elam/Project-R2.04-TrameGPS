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
*  Nom du fichier : verificationFormat.c                                      *
*                                                                             *
******************************************************************************/
/**
 * @file verificationFormat.c
 * @brief Ce fichier contient les corps des fonctions pour vérifier le format des trames GPS.
 * 
 * Les fonctions ici permettent de vérifier le type de trame, le nombre de champs,
 * le format de l'heure, la validité des coordonnées de latitude et de longitude.
 * 
 * @author Ellisa EE, Ismael EL-AMRANI
 * @date 2024
 */

#include "verificationFormat.h"

void verifier_type_trame(char* trame,jmp_buf ptRep){
    if (strncmp(trame,"$GPGGA",LONGUEUR_PREFIXE)!=0){
        longjmp(ptRep,TYPE_INVALIDE);
    }
}

void verifier_nombre_champs(char* trame,jmp_buf ptRep){
    int nb_virgules = 0;
    for (int i = 0 ; i < strlen(trame); i++){
        if (trame[i]==','){
            nb_virgules++;
        }
    }
    if (nb_virgules!=14){
        longjmp(ptRep,NB_CHAMPS_INVALIDE);
    } 
}

void verifier_format_heure(char* trame,jmp_buf ptRep) {
    char heure[7]="\0";
    extraireHeure(heure,trame);
    if(strlen(heure)!=LONGUEUR_HEURE){
        longjmp(ptRep,FORMAT_HEURE_INVALIDE);
    }   
}

void verifier_heure_min_sec(int heure,int min,int sec, jmp_buf ptRep){
    if (heure<0 || min<0 || sec<0 || heure>24 || min>59 || sec>59){
        longjmp(ptRep,FORMAT_HEURE_INVALIDE);
    }
}

void verifier_latitude(int degre, int minute, float second,char orientation,jmp_buf ptRep) {
    if (degre<0 || degre>90 || minute<0 || minute>59 || second<0 || second>59 || !(orientation=='N' || orientation=='S')){
        longjmp(ptRep,LATITUDE_INVALIDE);
    }
}

void verifier_longitude(int degre, int minute, float second,char orientation,jmp_buf ptRep) {
    if (degre<0 || degre>180 || minute<0 || minute>59 || second<0 || second>59 || !(orientation=='S' || orientation=='W')){
        longjmp(ptRep,LONGITUDE_INVALIDE);
    }
}