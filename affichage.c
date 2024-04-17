#include "affichage.h"

void affichageLongLat(struct dmsInfo d){
    printf("%d°%d\'%.2f\"\n",d.degre,d.minute,d.second);
}

void affichageHeure(struct heureInfo h){
    printf("%dh%dm%ds\n",h.heure,h.minute,h.minute);
}