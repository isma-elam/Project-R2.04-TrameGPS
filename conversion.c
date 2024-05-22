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
*  Nom du fichier : conversion.c                                              *
*                                                                             *
******************************************************************************/
/**
 * @file conversion.c
 * @brief Ce fichier contient les corps des fonctions pour la conversion de coordonnées et d'heures.
 * 
 * Les fonctions ici permettent de convertir des coordonnées géographiques
 * (latitude et longitude) et des heures au format décimal en degrés, minutes et secondes.
 * 
 * @author Ellisa EE, Ismael EL-AMRANI
 * @date 2024
 */

#include "conversion.h"
#include "extraction.h"

void conversionLat(char* const dec,struct dmsInfo* d){
    char degC[3]="\0";
    char minC[3]="\0";
    char secC[LONGUEUR_LONG_LAT]="\0";
    char* p = strchr(dec,',');
    
    strncat(degC,dec,2);
    d->degre=strtol(degC,NULL,10);

    strncat(minC,dec+2,2);
    d->minute=strtol(minC,NULL,10);
    secC[0]='0';
    strncat(secC,dec+4,p-(dec+4));
    d->second=strtof(secC,NULL)*60;
    d->orientation=*(p+1);
}

void conversionLong(char* const dec,struct dmsInfo* d){
    char degC[3]="\0";
    char minC[3]="\0";
    char secC[LONGUEUR_LONG_LAT]="\0";
    char* p = strchr(dec,',');
    strncat(degC,dec,3);
    d->degre=strtol(degC,NULL,10);
    strncat(minC,dec+3,2);
    d->minute=strtol(minC,NULL,10);
    secC[0]='0';
    strncat(secC,dec+5,p-(dec+5));
    d->second=strtof(secC,NULL)*60;
    p = strchr(dec,',');
    d->orientation=*(p+1);

}

void conversionHeure(char* const heure,struct heureInfo* h){
    char heureChar[3]="\0";
    char minuteChar[3]="\0";
    char secondChar[3]="\0";

    strncat(heureChar,heure,2);
    strncat(minuteChar,heure+2,2);
    strncat(secondChar,heure+4,2);
    h->heure=strtol(heureChar,NULL,10);
    h->minute=strtol(minuteChar,NULL,10);
    h->second=strtol(secondChar,NULL,10);
}