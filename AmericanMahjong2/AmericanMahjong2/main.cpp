#include "AmericanMahjong.h"
using namespace std;

int main(){
    srand (time(NULL));
    int wind_num = rand()%4; // 0-3の整数をランダムに生成

    bool isPlayerEast = false;
    if(wind_num == 0) isPlayerEast = true;
    
    AmericanMahjong myMahjong; // デフォルトコンストラクタを呼ぶ
    
    cout << "===========LET'S PLAY AMERICAN MAHJONG==========\n";
    int gameCount = 1;
    cout << "\n---------------------GAME" << gameCount << "-----------------------\n";

    myMahjong.set_individual_tile(isPlayerEast); // 自分とCPUの牌を表示
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}