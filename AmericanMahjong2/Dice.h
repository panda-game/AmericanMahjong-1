#ifndef DICE_H
#define DICE_H


#include <stdlib.h> // rand

class Dice{
    int die_num;
    
public:
    Dice();
    int get_die_num();
    friend class AmericanMahjong;
};

#endif
