#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include "conversion.h"

#define LONGUEUR_HEURE 6
#define LONGUEUR_LONG_LAT 15

struct trameInfo {
    char heure[LONGUEUR_HEURE+1];
    char latitude[LONGUEUR_LONG_LAT+1];
    char longtitude[LONGUEUR_LONG_LAT+1];
};

void initialiserInfoTrame(struct trameInfo* t);
// void extraireInfoTrame(char* tChar,struct trameInfo* t,struct heureInfo* h,struct dmsInfo* lat, struct dmsInfo* long);
void extraireInfoTrame(char* const tChar,struct trameInfo* t);
void extraireHeure (char* heure, char* const trame);
void extraireLongitude(char* longitude, char* const trame);
void extraireLatitude(char* latitude, char* const trame);
