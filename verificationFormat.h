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
    LONGITUDE_INVALIDE
} Exception;

void verifier_type_trame(char* trame,jmp_buf ptRep);
void verifier_nombre_champs(char* trame,jmp_buf ptRep);
void verifier_format_heure(char* trame,jmp_buf ptRep);
void verifier_heure_min_sec(int heure,int min,int sec, jmp_buf ptRep);
void verifier_latitude(int degre, int minute, float second,jmp_buf ptRep);
void verifier_longitude(int degre, int minute, float second,jmp_buf ptRep);

