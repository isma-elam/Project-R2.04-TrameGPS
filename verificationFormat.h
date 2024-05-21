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
*  Nom du fichier : verificationFormat.h                                      *
*                                                                             *
******************************************************************************/

/**
 * @file verificationFormat.h
 * @author Ellisa EE, Ismael EL-AMRANI
 * @brief Ce fichier contient les déclarations des fonctions pour vérifier le format des données GPS.
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <string.h>
#include <setjmp.h>
#include "extraction.h"

#define LONGUEUR_PREFIXE 6
#define LONGUEUR_HEURE 6

typedef enum{
    OK, 
    TYPE_INVALIDE, 
    NB_CHAMPS_INVALIDE,
    FORMAT_HEURE_INVALIDE,
    LATITUDE_INVALIDE,
    LONGITUDE_INVALIDE,
    CHEMIN_INVALIDE
} Exception;

/**
 * @brief Vérifie le type de la trame GPS.
 * 
 * Cette fonction vérifie si la trame GPS commence par le préfixe "$GPGGA".
 * Si la trame n'a pas le bon préfixe, une longjmp est utilisée pour renvoyer une erreur.
 * 
 * @param trame La trame à vérifier.
 * @param ptRep Pointeur vers le contexte de saut pour gérer les erreurs.
 */
void verifier_type_trame(char* trame,jmp_buf ptRep);

/**
 * @brief Vérifie le nombre de champs dans la trame GPS.
 * 
 * Cette fonction compte le nombre de virgules dans la trame GPS pour vérifier si elle contient
 * le nombre correct de champs (15).
 * Si le nombre de champs est incorrect, une longjmp est utilisée pour renvoyer une erreur.
 * 
 * @param trame La trame à vérifier.
 * @param ptRep Pointeur vers le contexte de saut pour gérer les erreurs.
 */
void verifier_nombre_champs(char* trame,jmp_buf ptRep);

/**
 * @brief Vérifie le format de l'heure dans la trame GPS.
 * 
 * Cette fonction extrait l'heure de la trame GPS et vérifie si elle a la longueur correcte.
 * Si l'heure n'a pas la longueur correcte, une longjmp est utilisée pour renvoyer une erreur.
 * 
 * @param trame La trame GPS contenant l'heure à vérifier.
 * @param ptRep Pointeur vers le contexte de saut pour gérer les erreurs.
 */
void verifier_format_heure(char* trame,jmp_buf ptRep);

/**
 * @brief Vérifie le format des heures, minutes et secondes.
 * 
 * Cette fonction vérifie si les heures, minutes et secondes sont dans des plages valides.
 * Si une des valeurs est invalide, une longjmp est utilisée pour renvoyer une erreur.
 * 
 * @param heure Heure à vérifier.
 * @param min Minute à vérifier.
 * @param sec Seconde à vérifier.
 * @param ptRep Pointeur vers le contexte de saut pour gérer les erreurs.
 */
void verifier_heure_min_sec(int heure,int min,int sec, jmp_buf ptRep);

/**
 * @brief Vérifie le format de la latitude dans la trame GPS.
 * 
 * Cette fonction vérifie si la latitude est dans une plage valide.
 * Si la latitude est invalide, une longjmp est utilisée pour renvoyer une erreur.
 * 
 * @param degre Degré de latitude.
 * @param minute Minute de latitude.
 * @param second Seconde de latitude.
 * @param ptRep Pointeur vers le contexte de saut pour gérer les erreurs.
 */
void verifier_latitude(int degre, int minute, float second,jmp_buf ptRep);

/**
 * @brief Vérifie le format de la longitude dans la trame GPS.
 * 
 * Cette fonction vérifie si la longitude est dans une plage valide.
 * Si la longitude est invalide, une longjmp est utilisée pour renvoyer une erreur.
 * 
 * @param degre Degré de longitude.
 * @param minute Minute de longitude.
 * @param second Seconde de longitude.
 * @param ptRep Pointeur vers le contexte de saut pour gérer les erreurs.
 */
void verifier_longitude(int degre, int minute, float second,jmp_buf ptRep);

