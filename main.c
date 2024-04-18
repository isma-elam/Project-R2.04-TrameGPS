#include "extraction.h"
#include "affichage.h"
#include "chargerRep.h"

int main(void){
    struct trameTab trameTab;
    int lgTramTab;
    jmp_buf ptRep;
    Exception anomalie;
    anomalie=setjmp(ptRep);

    switch (anomalie)
    {
    case OK:
        charger(&trameTab,&lgTramTab,"data.txt",ptRep);
        ranger(trameTab,lgTramTab,"enregistrements.txt");
        printf("Extraction d'informations terminée, les données sont enregistrées dans le fichier nommé « enregistrement.txt »\n");
        break;
    case TYPE_INVALIDE:
        printf("Extraction d'information impossible : Type du format de la trame GPS NMEA 0183 n'est pas du type GPGGA.\n");
        printf("Verifier format de la trame dans le fichier source.\n");
        break;
    case NB_CHAMPS_INVALIDE:
        printf("Extraction d'information impossible : Nombre de champs invalide\n");
        printf("Verifier si la trame dans le fichier source a 15 champs en total\n");
        break;
    case FORMAT_HEURE_INVALIDE:
        printf("Extraction d'information impossible : Format de l'heure invalide.\n");
        printf("Verifier format de l'heure de la trame dans le fichier source.\n"); 
        break;
    case LATITUDE_INVALIDE:
        printf("Extraction d'information impossible : Valeur du latitude invalide.\n");
        printf("Verifier valeur du latitude de la trame dans le fichier source.\n");
        break;
    case LONGITUDE_INVALIDE:
        printf("Extraction d'information impossible : Valeur du longitude invalide.\n");
        printf("Verifier valeur du longitude de la trame dans le fichier source.\n");   
    default:
        break;
    }
}