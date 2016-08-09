#ifndef __Amerian_Majong__Tiles__
#define __Amerian_Majong__Tiles__

#include <string>
using namespace std;


class Tiles
{
    /* ---------牌のtypeについて----------
     krack → a 1~9 ×4 (type = krack)
     dot → b 1~9 ×4 (type = dot)
     bamboo → c 1~9 ×4 (type = bamboo)
     red dragon → d ×4  (type = dragon)
     green dragon → e ×4 (type = dragon)
     soap → f ×4 (type = dragon)
     east → g ×4 (type = wind)
     west → h ×4 (type = wind)
     south → i ×4 (type = wind)
     north → j ×4 (type = wind)
     flower → k ×8 (type = flower)
     joker →　l ×8 (type = joker)
     ----------------------------------*/
    char type;
    int data; // 牌の数字
    
    
public:
    Tiles();
    Tiles(char c, int n);

    // AmericanMahjongクラスからTilesクラスのプライベートデータメンバへのアクセス許可
    friend class AmericanMahjong;
};



#endif