#include "extraction.h"

// void initialiserInfoTrame(struct trameInfo* t){
//     t->heure[0]='\0';
//     t->latitude[0]='\0';
//     t->longtitude[0]='\0';

// }
void extraireInfoTrame(char* tChar,struct trameInfo* t){
    char heure [LONGUEUR_HEURE+1]="\0";
    char lo [LONGUEUR_LONG_LAT+1]="\0";
    char la [LONGUEUR_LONG_LAT+1]="\0";
    extraireHeure(heure,tChar);
    conversionHeure(heure,&t->heure);

    extraireLatitude(la,tChar);
    conversionLongLat(la,&t->latitude);

    extraireLongitude(lo,tChar);
    conversionLongLat(lo,&t->longitude);
}

void extraireHeure (char* heure, char* const trame){
    char* p;
    int i = 0;
    p=strchr(trame,',');
    strncat(heure,p+1,LONGUEUR_HEURE);
}

void extraireLatitude(char* latitude, char* const trame){
    char* p;
    char* p2;
    p=strchr(trame,',');
    p=p+1;
    p=strchr(p,',');
    p=p+1;
    p2=p;
    p2=strchr(p,',');
    strncat(latitude,p,p2-p);
    strcat(latitude,",");
    strncat(latitude,p2+1,1); 
}

void extraireLongitude(char* longitude, char* const trame){
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
    strncat(longitude,p,p2-p);
    strcat(longitude,",");
    strncat(longitude,p2+1,1); 
}