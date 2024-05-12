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
*  Nom du fichier : extraction.h                                              *
*                                                                             *
******************************************************************************/

#ifndef EXTRACTION_H
#define EXTRACTION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "conversion.h"
#include "affichage.h"

#define LONGUEUR_HEURE 6
#define LONGUEUR_LONG_LAT 15

struct trameInfo {
    struct heureInfo heure;
    struct dmsInfo latitude;
    struct dmsInfo longitude;
};

void initialiserInfoTrame(struct trameInfo* t);
void extraireInfoTrame(char* tChar,struct trameInfo* t);
void extraireHeure (char* heure, char* const trame);
void extraireLongitude(char* longitude, char* const trame);
void extraireLatitude(char* latitude, char* const trame);
#endif