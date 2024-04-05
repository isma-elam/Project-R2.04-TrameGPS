#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dmsInfo {
    int degre;
    float minute;
    float second;
};

void conversionLongLat(char* const dec,struct dmsInfo d);