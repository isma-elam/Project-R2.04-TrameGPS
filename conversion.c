#include "conversion.h"
#include "extraction.h"

void conversionLongLat(char* const dec,struct dmsInfo* d){
    float l;
    float decimaux;

    char degC[3]="\0";
    char minC[3]="\0";
    char secC[LONGUEUR_LONG_LAT]="\0";
    char* p = strchr(dec,',');
    
    strncat(degC,dec,2);
    d->degre=strtol(degC,NULL,10);

    strncat(minC,dec+2,2);
    d->minute=strtol(minC,NULL,10);
    secC[0]='0';
    strncat(secC,dec+4,p-(dec+4));
    d->second=strtof(secC,NULL)*60;
    d->orientation=*(p+1);
}

void conversionHeure(char* const heure,struct heureInfo* h){
    char heureChar[3]="\0";
    char minuteChar[3]="\0";
    char secondChar[3]="\0";

    strncat(heureChar,heure,2);
    strncat(minuteChar,heure+2,2);
    strncat(secondChar,heure+4,2);
    h->heure=strtol(heureChar,NULL,10);
    h->minute=strtol(minuteChar,NULL,10);
    h->second=strtol(secondChar,NULL,10);
    // printf("h:%d  m:%d  s:%d\n",h->heure,h->minute,h->second);
}