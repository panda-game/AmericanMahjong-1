#ifndef WIND_H
#define WIND_H

#include <string>
using namespace std;

class Wind{
    string myWind[4];
public:
    Wind(int i);
    friend class AmericanMahjong;
};

#endif