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

/**
 * @file extraction.h
 * @author Ellisa EE, Ismael EL-AMRANI
 * @brief Ce fichier contient les déclarations des fonctions pour extraire les données GPS.
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "conversion.h"
#include "affichage.h"

#define LONGUEUR_HEURE 6
#define LONGUEUR_LONG_LAT 15

/**
 * @struct trameInfo
 * @brief Structure représentant les informations extraites d'une trame GPS.
 * 
 * Cette structure contient les informations extraites d'une trame GPS, à savoir l'heure, la latitude et la longitude.
 */
struct trameInfo {
    struct heureInfo heure;
    struct dmsInfo latitude;
    struct dmsInfo longitude;
};

/**
 * @brief Initialise une structure trameInfo avec des valeurs par défaut.
 * 
 * @param t Pointeur vers la structure trameInfo à initialiser.
 */
void initialiserInfoTrame(struct trameInfo* t);

/**
 * @brief Extrait les informations d'une trame donnée et les stocke dans une structure trameInfo.
 * 
 * @param tChar Chaîne de caractères représentant la trame.
 * @param t Pointeur vers la structure trameInfo où stocker les informations extraites.
 */
void extraireInfoTrame(char* tChar,struct trameInfo* t);

/**
 * @brief Extrait l'heure d'une trame donnée et la stocke dans une chaîne de caractères.
 * 
 * @param heure Chaîne de caractères où stocker l'heure extraite.
 * @param trame Trame complète contenant l'heure à extraire.
 */
void extraireHeure (char* heure, char* const trame);

/**
 * @brief Extrait la longitude d'une trame donnée et la stocke dans une chaîne de caractères.
 * 
 * @param longitude Chaîne de caractères où stocker la longitude extraite.
 * @param trame Trame complète contenant la longitude à extraire.
 */
void extraireLongitude(char* longitude, char* const trame);

/**
 * @brief Extrait la latitude d'une trame donnée et la stocke dans une chaîne de caractères.
 * 
 * @param latitude Chaîne de caractères où stocker la latitude extraite.
 * @param trame Trame complète contenant la latitude à extraire.
 */
void extraireLatitude(char* latitude, char* const trame);
#endif