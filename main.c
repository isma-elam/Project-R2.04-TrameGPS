#include "extraction.h"
#include "conversion.h"

int main(void){
    struct dmsInfo d;
    char t [100]="$GPGGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    char h [LONGUEUR_HEURE+1]="\0";
    char lo [LONGUEUR_LONG_LAT]="\0";
    char la [LONGUEUR_LONG_LAT]="\0";
    extraireHeure(h,t);
    printf("%s\n",h);
    extraireLongitude(lo,t);
    printf("%s\n",lo);
    extraireLatitude(la,t);
    printf("%s\n",la);

    conversionLongLat(lo,d);
}