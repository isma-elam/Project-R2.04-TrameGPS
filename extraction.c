#include "extraction.h"

void extraireHeure (char* heure, char* const trame){
    char* p;
    int i = 0;
    p=strchr(trame,',');
    strncat(heure,p+1,LONGUEUR_HEURE);
}

void extraireLongitude(char* longitude, char* trame){
    char* p;
    char* p2;
    int i = 0;
    p=strchr(trame,',');
    p=p+1;
    p=strchr(p,',');
    p=p+1;
    p2=p;
    p2=strchr(p,',');
    strncat(longitude,p,p2-p);
    strcat(longitude,",");
    strncat(longitude,p2+1,1); 
}

void extraireLatitude(char* latitude, char* trame){
    char* p;
    char* p2;
    int i = 0;
    p=strchr(trame,',');
    p=p+1;
    for (int i = 0 ; i < 3 ; i++){
        p=strchr(p,',');
        p=p+1;
    }
    p2=p;
    p2=strchr(p,',');
    strncat(latitude,p,p2-p);
    strcat(latitude,",");
    strncat(latitude,p2+1,1); 
}