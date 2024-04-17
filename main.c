#include "extraction.h"
//#include "conversion.h"
#include "affichage.h"

int main(void){
    struct dmsInfo latDMS;
    struct dmsInfo longDMS;
    struct heureInfo hInfo;
    struct trameInfo tInfo;
    // char t [100]="$GPGGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    char t [100]="$GPGGA,123519,4124.8963,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    
    initialiserInfoTrame(&tInfo);
    extraireInfoTrame(t,&tInfo);

    conversionHeure(tInfo.heure,&hInfo);
    conversionLongLat(tInfo.latitude,&latDMS);
    conversionLongLat(tInfo.longtitude,&longDMS);
    affichageLongLat(latDMS);
    affichageLongLat(longDMS);
    affichageHeure(hInfo);
}