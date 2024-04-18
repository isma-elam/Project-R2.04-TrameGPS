#include "extraction.h"
#include "affichage.h"
#include "chargerRep.h"

int main(void){
    struct trameInfo tInfo;

    struct trameTab trameTab;
    int lgTramTab;
    charger(&trameTab,&lgTramTab,"data.txt");
    ranger(trameTab,lgTramTab,"donnees_extraites.txt");
}