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

/**
 * @file affichage.h
 * @author Ellisa EE, Ismael EL-AMRANI
 * @brief Ce fichier contient les déclarations des fonctions pour l'affichage des données GPS.
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "conversion.h"
#include <stdio.h>

/**
 * @brief Affiche le menu et permet à l'utilisateur de choisir une méthode pour lire les données
 * 
 * Affiche un menu avec les options disponibles pour lire les trames GPS
 * L'utilisateur peut choisir de saisr les données manuellement, de les lire à partir d'un fichier en donnant son chemin ou de quitter l'application
 * 
 * @return Le choix de l'utilisateur (0 pour auitter, 1 pour saisir manuellement, 2 pour lire à partir d'un fichier)
 */
int affichageMenu();

/**
 * @brief Permet à l'utilisateur de choisir s'il souhaite afficher le résultat de l'analyse de trames GPS données.
 * 
 * Demande à l'utilisateur s'il souhaite afficher les données.
 * L'utilisateur peut répondre par oui (1) ou non (0).
 * 
 * @return Le choix de l'utilisateur (1 pour oui, 0 pour non).
 */
int affichageDonneesChoix();

/**
 * @brief Affiche le contenu du fichier contenant le résultat de l'analyse de trames GPS.
 * 
 * Affiche le contenu du fichier contenant le résultat de l'analyse de trames GPS.
 * Si le fichier ne peut pas être ouvert en lecture, affiche un message d'erreur.
 * 
 * @param nomFic Le nom du fichier à afficher contenant le résultat de l'analyse de trames GPS.
 */
void affichageDonneesFichier(char nomFic[]);
#endif 
