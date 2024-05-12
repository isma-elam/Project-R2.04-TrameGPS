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
*  Nom du fichier : chargerRep.h                                              *
*                                                                             *
******************************************************************************/

/**
 * @file chargerRep.h
 * @author Ellisa EE
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CHARGER_REP_H
#define CHARGER_REP_H

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "extraction.h"
#include "verificationFormat.h"

#define LONGUEUR_TRAME 200
#define MAX_NUM_TRAME 50

/**
 * @brief Structure contenant un tableau de trames et le nombre de trames.
 * 
 * Cette structure représente un tableau de trames ainsi que le nombre de trames
 * actuellement stockées dans le tableau.
 */
struct trameTab {
    struct trameInfo trame[MAX_NUM_TRAME];
    int num;
};

/**
 * @brief Charge les données à partir d'un fichier dans une structure de trames.
 * 
 * Cette fonction lit les données à partir d'un fichier spécifié par son nom et les charge dans
 * une structure de trames. Cette structure est comprise d'un tableau de trames et un numéro pour
 * indiquer le nombre de trames stockés.
 * Elle vérifie également la validité des données (nombre de champs, type de trame, format de l'heure) 
 * en appelant d'autres fonctions de vérification. 
 * 
 * @param trameTab Pointeur vers la structure de trames où stocker les données.
 * @param nb Pointeur vers le nombre de trames chargées.
 * @param nomFic Le nom du fichier à partir duquel lire les données.
 * @param ptRep Pointeur vers le point de reprise pour la gestion des erreurs avec longjmp.
 */
void charger(struct trameTab* trameTab,int* nb,char nomFic[],jmp_buf ptRep);

/**
 * @brief Lit les données à partir de l'entrée standard et les stocke dans une structure de trames.
 * 
 * Cette fonction lit les données à partir de l'entrée standard (clavier) et les stocke dans une
 * structure de trames. Cette structure est comprise d'un tableau de trames et un numéro pour
 * indiquer le nombre de trames stockés.
 * Elle vérifie également la validité des données (nombre de champs, type de trame, format de l'heure) 
 * en appelant d'autres fonctions de vérification. 
 * 
 * @param trameTab Pointeur vers la structure de trames où stocker les données.
 * @param nb Pointeur vers le nombre de trames lues.
 * @param nomFic Le nom du fichier à partir duquel lire les données.
 * @param ptRep Pointeur vers le point de reprise pour la gestion des erreurs avec longjmp.
 */
void lireDonnees(struct trameTab* trameTab,int* nb,char nomFic[],jmp_buf ptRep);

/**
 * @brief Enregistre les données d'une structure de trames dans un fichier.
 * 
 * Cette fonction enregistre les données contenues dans une structure de trames dans un fichier
 * spécifié par son nom. Les données sont écrites dans un format spécifique pour chaque trame.
 * Exemple du format : Heure : 13h35m19s ; Latitude : 48°7'2.28" ; Longitude : 11°31'19.44"
 * 
 * @param trameTab La structure de trames contenant les données à enregistrer.
 * @param nb Le nombre de trames à enregistrer.
 * @param nomFic Le nom du fichier où enregistrer les données.
 */
void ranger(struct trameTab trameTab,int nb,char nomFic[]);

#endif