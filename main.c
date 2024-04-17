#include "extraction.h"
//#include "conversion.h"
#include "affichage.h"

int main(void){
    struct dmsInfo d;
    struct heureInfo hInfo;
    // char t [100]="$GPGGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    char t [100]="$GPGGA,123519,4124.8963,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    char h [LONGUEUR_HEURE+1]="\0";
    char lo [LONGUEUR_LONG_LAT]="\0";
    char la [LONGUEUR_LONG_LAT]="\0";
    extraireHeure(h,t);
    printf("%s\n",h);
    extraireLongitude(lo,t);
    printf("%s\n",lo);
    extraireLatitude(la,t);
    printf("%s\n",la);

    conversionHeure(h,&hInfo);
    conversionLongLat(lo,&d);
    affichageLongLat(d);
    affichageHeure(hInfo);
}