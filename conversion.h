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
/**
 * @file conversion.h
 * @author Ellisa EE, Ismael EL-AMRANI
 * @brief Ce fichier contient les déclarations des fonctions pour convertir les données GPS.
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CONVERSION_H
#define CONVERSION_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#define LONGUEUR_ORIENTATION 1

/**
 * @struct dmsInfo
 * @brief Structure représentant une valeur en degrés, minutes, secondes.
 * 
 * Cette structure permet de stocker une valeur en degrés, minutes et secondes, ainsi que
 * son orientation (nord, sud, est, ouest).
 */
struct dmsInfo {
    int degre; /**< Degré de la valeur. */
    int minute; /**< Minute de la valeur. */
    float second;/**< Seconde de la valeur. */
    char orientation; /**< Orientation de la valeur ('N' pour nord, 'S' pour sud, 'E' pour est, 'O' pour ouest). */
};

/**
 * @struct heureInfo
 * @brief Structure représentant une heure au format HH:MM:SS.
 * 
 * Cette structure permet de stocker une heure sous la forme d'heures, minutes et secondes.
 */
struct heureInfo{
    int heure; /**< Degré de la valeur. */
    int minute; /**< Minute de la valeur. */
    int second;/**< Seconde de la valeur. */
};

/**
 * @brief Convertit une latitude décimale en degrés, minutes, secondes (DMS)
 * 
 * Cette fonction prend une latitude en format décimal et la convertit en 
 * une structure dmsInfo qui contient les degrés, minutes, secondes, et l'orientation 
 * 
 * @param dec Latitude en format décimal (chaîne de caractères)
 * @param d Pointeur vers la structure dmsInfo qui recevra les valeurs converties
 * 
 */
void conversionLat(char* const dec,struct dmsInfo* d);

/**
 * @brief Convertit une longitude décimale en degré, minutes, secondes (DMS)
 * 
 * Cette fonction prend une longitude en format décimal (chaîne de caractères) et la convertit en
 * une structure dmsInfo qui contient les degrés, minutes, secondes et l'orientation
 * 
 * @param dec Longitude en format décimal (chaîne de caractères)
 * @param d Pointeur vers la structure dmsInfo qui recevra les valeurs converties
 * 
 */
void conversionLong(char* const dec,struct dmsInfo* d);

/**
 * @brief Convertit une heure en format châine de caractères en heures, minutes, secondes
 * 
 * Cette fonction prend une heure en format chaîne de caractères (HHMMSS) et la convertit en
 * une structure heureInfo qui contient les heures, minutes et secondes.
 * 
 * @param heure Heure en format chaîne de caractères (HHMMSS)
 * @param h Pointeur vers la structure heureInfo qui recevra les valeurs
 */
void conversionHeure(char* const heure,struct heureInfo* h);
#endif 