#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LONGUEUR_HEURE 6
#define LONGUEUR_LONG_LAT 11

void extraireHeure (char* heure, char* const trame);

struct trameInfo {
    int nbTrame;
    char heure[LONGUEUR_HEURE+1];
    char longtitude[LONGUEUR_HEURE+1];
};

void extraireHeure (char* heure, char* const trame){
    char* p;
    int i = 0;
    p=strchr(trame,',');
    strncat(heure,p+1,LONGUEUR_HEURE);
}

int main(void){
    char t [100]="$GPGGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    char h [LONGUEUR_HEURE+1]="\0";
    extraireHeure(h,t);
    printf("%s\n",h);
}