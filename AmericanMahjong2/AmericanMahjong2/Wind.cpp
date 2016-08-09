#include "Wind.h"
#include <stdlib.h> // rand

Wind::Wind(int i){
    if(i == 0){ myWind[0] = "EAST", myWind[1] = "SOUTH", myWind[2] = "WEST", myWind[3] = "NORTH"; }
    else if(i == 1){ myWind[0] = "NORTH", myWind[1] = "EAST", myWind[2] = "SOUTH", myWind[3] = "WEST"; }
    else if(i == 2){ myWind[0] = "WEST", myWind[1] = "NORTH", myWind[2] = "EAST", myWind[3] = "SOUTH"; }
    else if(i == 3){ myWind[0] = "SOUTH", myWind[1] = "WEST", myWind[2] = "NORTH", myWind[3] = "EAST"; }
}