#ifndef VALIDATION_H
#define VALIDATION_H
#include "tile.h"

extern Tile *tile[4][3];
extern int exp[60],max,wR,wC;

class validation
{
    int flag,retVal;

public:
    validation();
    int chooser(Tile *temp);
    int validateSang(Tile *temp);
    int validateHoo(Tile *temp);
    int validateWang(Tile *temp);
    int validateJang(Tile *temp);
    int validateJa(Tile *temp);
    void orange();
    int check(Tile *temp);
signals:

public slots:
};

#endif // VALIDATION_H
