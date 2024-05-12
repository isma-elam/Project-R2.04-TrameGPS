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
*  Nom du fichier : affichage.h                                               *
*                                                                             *
******************************************************************************/

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "conversion.h"
#include <stdio.h>

void affichageLongLat(struct dmsInfo d);

void affichageHeure(struct heureInfo h);

int affichageMenu();

int affichageDonneesChoix();

void affichageDonneesFichier(char nomFic[]);
#endif 
