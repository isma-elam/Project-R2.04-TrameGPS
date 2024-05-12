#ifndef CHARGER_REP_H
#define CHARGER_REP_H

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "extraction.h"
#include "verificationFormat.h"

#define LONGUEUR_TRAME 100
#define MAX_NUM_TRAME 50

struct trameTab {
    struct trameInfo trame[MAX_NUM_TRAME];
    int num;
};

void charger(struct trameTab* trameTab,int* nb,char nomFic[],jmp_buf ptRep);
void ranger(struct trameTab trameTab,int nb,char nomFic[]);
void lireDonnees(struct trameTab* trameTab,int* nb,char nomFic[],jmp_buf ptRep);
#endif