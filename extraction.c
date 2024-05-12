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
*  Nom du fichier : extraction.c                                              *
*                                                                             *
******************************************************************************/

#include "extraction.h"

void extraireInfoTrame(char* tChar,struct trameInfo* t){
    char heure [LONGUEUR_HEURE+1]="\0";
    char lo [LONGUEUR_LONG_LAT+1]="\0";
    char la [LONGUEUR_LONG_LAT+1]="\0";
    extraireHeure(heure,tChar);
    conversionHeure(heure,&t->heure);

    extraireLatitude(la,tChar);
    conversionLat(la,&t->latitude);

    extraireLongitude(lo,tChar);
    conversionLong(lo,&t->longitude);
}

void extraireHeure (char* heure, char* const trame){
    char* p;
    int i = 0;
    p=strchr(trame,',');
    strncat(heure,p+1,LONGUEUR_HEURE);
}

void extraireLatitude(char* latitude, char* const trame){
    char* p;
    char* p2;
    p=strchr(trame,',');
    p=p+1;
    p=strchr(p,',');
    p=p+1;
    p2=p;
    p2=strchr(p,',');
    strncat(latitude,p,p2-p);
    strcat(latitude,",");
    strncat(latitude,p2+1,1); 
}

void extraireLongitude(char* longitude, char* const trame){
    char* p;
    char* p2;
    int i = 0;
    p=strchr(trame,',');
    p=p+1;
    for (int i = 0 ; i < 3 ; i++){
        p=strchr(p,',');
        p=p+1;
    }
    p2=p;
    p2=strchr(p,',');
    strncat(longitude,p,p2-p);
    strcat(longitude,",");
    strncat(longitude,p2+1,1); 
}