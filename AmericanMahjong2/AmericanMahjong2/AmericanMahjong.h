#ifndef AMERICAN_MAHJONG_H
#define AMERICAN_MAHJONG_H

#include "Tiles.h"
#include "Dice.h"
#include "Wind.h"
#include <iostream> // cout
#include <ctime> // time
#include <vector> // vector
#include <string>

using namespace std;

class AmericanMahjong
{
    const int NUMTILE = 152; //　全体の牌の数
    vector<Tiles> yama;// 山の牌を格納するベクター
    vector<Tiles> myTehuda; // 手札の牌を格納
    vector<Tiles> cp1Tehuda; // CP1手札
    vector<Tiles> cp2Tehuda; // CP2手札
    vector<Tiles> cp3Tehuda; // CP3手札
    
public:
    // コンストラクタ
    AmericanMahjong();
    
    // メンバ関数の宣言
 

    void set_all_tile(); // 152個の牌を作成しベクターに入れる
    void shuffle_all_tile(); // 牌をシャッフルする
    void set_individual_tile(bool isPlayerEast); // 各プレーヤーの牌をセットする
    void swap_tiles(int index1,int index2); //索引1と索引2のタイプとデータを入れ替える
    void print_my_tile(); // 手札を表示
    void print_introduction(int gameCount); // 今回のサイコロの数字と各プレーヤーの風を表示
 };


#endif