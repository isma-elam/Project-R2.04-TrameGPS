#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LONGUEUR_HEURE 6
#define LONGUEUR_LONG_LAT 15

struct trameInfo {
    int nbTrame;
    char heure[LONGUEUR_HEURE+1];
    char longtitude[LONGUEUR_HEURE+1];
};

void extraireHeure (char* heure, char* const trame);
void extraireLongitude(char* longitude, char* const trame);
void extraireLatitude(char* latitude, char* const trame);
