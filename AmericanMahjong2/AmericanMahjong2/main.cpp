#include "AmericanMahjong.h"
using namespace std;

int main(){
    srand (static_cast<unsigned int>(time(NULL)));
    int wind_num = rand()%4; // 0-3の整数をランダムに生成
    Wind winds(wind_num);
    
    AmericanMahjong myMahjong; // デフォルトコンストラクタを呼ぶ
    
    cout << "===========LET'S PLAY AMERICAN MAHJONG==========\n";
    int gameCount = 1;
    myMahjong.print_introduction(gameCount, winds); // ゲーム開始時のメッセージを表示する
    myMahjong.set_individual_tile(wind_num); // 各プレーヤーの牌を用意する
    myMahjong.print_my_tile(); // 自分とCPUの牌を表示

    cout << "***TRADING TILES***\n" << endl; // ここから牌の交換を行う
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}