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
*  Nom du fichier : conversion.h                                              *
*                                                                             *
******************************************************************************/

#ifndef CONVERSION_H
#define CONVERSION_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// #define LONGUEUR_ORIENTATION 1

struct dmsInfo {
    int degre;
    int minute;
    float second;
    char orientation;
};

struct heureInfo{
    int heure;
    int minute;
    int second;
};

void conversionLat(char* const dec,struct dmsInfo* d);
void conversionLong(char* const dec,struct dmsInfo* d);
void conversionHeure(char* const heure,struct heureInfo* h);
#endif 