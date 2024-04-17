#include "extraction.h"
#include "affichage.h"

int main(void){
    struct trameInfo tInfo;
    // char t [100]="$GPGGA,123519,4807.038,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";
    char t [100]="$GPGGA,123519,4124.8963,N,01131.324,E,1,08,0.9,545.4,M,46.9,M, , *42";

    extraireInfoTrame(t,&tInfo);
    affichageHeure(tInfo.heure);
    affichageLongLat(tInfo.latitude);
    affichageLongLat(tInfo.longitude);
    
}