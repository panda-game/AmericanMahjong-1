#include "AmericanMahjong.h"
using namespace std;

int main(){
    {
    srand (static_cast<unsigned int>(time(NULL)));
    int wind_num = rand()%4; // 0-3の整数をランダムに生成
    Wind winds(wind_num);
    
    AmericanMahjong myMahjong; // デフォルトコンストラクタを呼ぶ
    
    cout << "===========LET'S PLAY AMERICAN MAHJONG==========\n";
    int gameCount = 1;
    myMahjong.print_introduction(gameCount, winds); // ゲーム開始時のメッセージを表示する
    myMahjong.set_individual_tile(wind_num); // 各プレーヤーの牌を用意する
    cout << "***CARDS***\n";
    myMahjong.print_my_tile(); // 自分とCPUの牌を表示

//    cout << "*** TRADING TILES1 ***"; // ここから牌の交換を行う
//    myMahjong.trade_tiles1();
//    cout << "\n*** AFTER FIRST TRADE ***\n";
//    myMahjong.print_my_tile();
//    cout << "*** TRADING TILES2 ***";
//    myMahjong.trade_tiles2();
//    cout << "\n*** AFTER SECOND TRADE ***\n";
//    myMahjong.print_my_tile();
//    cout << "*** TRADING TILES3 ***";
//    myMahjong.trade_tiles3();
//    cout << "\n*** AFTER THIRD TRADE ***\n";
//    myMahjong.print_my_tile();
//    cout << "*** TRADING TILES4 ***";
//    myMahjong.trade_tiles4();
//    cout << "\n*** AFTER FORTH TRADE ***\n";
//    myMahjong.print_my_tile();
//    cout << "*** TRADING TILES5 ***";
//    myMahjong.trade_tiles5();
//    cout << "\n*** AFTER FIFTH TRADE ***\n";
//    myMahjong.print_my_tile();
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    }
    
    return 0;
}