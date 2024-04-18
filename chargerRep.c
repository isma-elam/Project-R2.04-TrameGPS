#include "chargerRep.h"

void charger(struct trameTab* trameTab,int* nb,char nomFic[]){
    FILE* file;
    *nb=0;
    file = fopen(nomFic,"r");
    struct trameInfo tInfo;
    if (file==NULL){
        printf("Impossible d'ouvrir en lecture le fichier %s\n",nomFic);
    }else{ 
        char ligne[100]="\0";
        while (fgets(ligne, sizeof(ligne), file) != NULL && *nb < LONGUEUR_TRAME){
            if(ligne[strlen(ligne)-1]=='\n'){
                ligne[strlen(ligne)-1]=='\0';
            }      
            extraireInfoTrame(ligne,&tInfo);
            trameTab->trame[*nb]=tInfo;
            // affichageHeure(trameTab->trame[*nb].heure);
            // affichageLongLat(trameTab->trame[*nb].latitude);
            // affichageLongLat(trameTab->trame[*nb].longitude);
            (*nb)++;  
        }
    }
    fclose(file);
}

void ranger(struct trameTab trameTab,int nb,char nomFic[]){
    FILE* file;
    int i;
    file = fopen(nomFic,"w");
    if (file == NULL){
        printf("Impossible d'ouvrir en ecriture le fichier %s\n",nomFic);
    }else{
        for (i = 0 ; i < nb ; i++){
            fprintf(file,"Heure : %dh%dm%ds ; Latitude : %d°%d\'%.2f\" ; Longitude : %d°%d\'%.2f\"\n",
            trameTab.trame[i].heure.heure,trameTab.trame[i].heure.minute,trameTab.trame[i].heure.second,
            trameTab.trame[i].latitude.degre,trameTab.trame[i].latitude.minute,trameTab.trame[i].latitude.second,
            trameTab.trame[i].longitude.degre,trameTab.trame[i].longitude.minute,trameTab.trame[i].longitude.second);
        }
    }
}