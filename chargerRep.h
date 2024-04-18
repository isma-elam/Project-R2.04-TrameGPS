#ifndef CHARGER_REP_H
#define CHARGER_REP_H

#include <stdio.h>
#include <stdlib.h>
#include "extraction.h"

#define LONGUEUR_TRAME 100
#define MAX_NUM_TRAME 50

struct trameTab {
    struct trameInfo trame[MAX_NUM_TRAME];
    int num;
};

void charger(struct trameTab* trameTab,int* nb,char nomFic[]);
void ranger(struct trameTab trameTab,int nb,char nomFic[]);
#endif