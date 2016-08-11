#ifndef AMERICAN_MAHJONG_H
#define AMERICAN_MAHJONG_H

#include "Tiles.h"
#include "Dice.h"
#include "Wind.h"
#include <iostream> // cout
#include <iomanip> // setw
#include <ctime> // time
#include <vector> // vector
#include <string>
#include <algorithm> // sort

using namespace std;

class AmericanMahjong
{
    const int NUMTILE = 152; //　全体の牌の数
    int tiles_left; // 山に残った牌の数. 牌が配られる度にtiles_left--され,0になるとゲーム終了
    vector<Tiles*> yama;// 山の牌を格納するベクター
    vector<Tiles*> tehuda1; // 親用 tehuda1のみ開始時に14個牌を格納する
    vector<Tiles*> tehuda2; // tehuda2~4は子用で開始時に13個牌を格納する
    vector<Tiles*> tehuda3;
    vector<Tiles*> tehuda4;
    vector<Tiles*> myCards; // 手札の牌を格納したベクター用ポインタ
    vector<Tiles*> tmpCards; // ソート用の一時的なベクター
    vector<Tiles*> cp1Cards; // CP1手札用ポインタ
    vector<Tiles*> cp2Cards; // CP2手札用ポインタ
    vector<Tiles*> cp3Cards; // CP3手札用ポインタ
    
public:
    // コンストラクタ
    AmericanMahjong();
    
    // メンバ関数の宣言
 

    void set_all_tile(); // 152個の牌を作成しベクターに入れる
    void shuffle_all_tile(); // 牌をシャッフルする
    void set_individual_tile(int wind_num); // 各プレーヤーの牌をセットする
    void swap_ptrs(int index1, int index2); //索引1と索引2のポインタを入れ替える
//  void swap_tiles(int index1,int index2); //索引1と索引2のタイプとデータを入れ替える
    void print_my_tile(); // 手札を表示
    void sort_player_tiles(); // 牌をソート
    void print_introduction(int gameCount, Wind wind); // 今回のサイコロの数字と各プレーヤーの風を表示
    void trade_tiles(); //　牌を交換する
    void paste_tile_data(); // 牌の情報をindex1からindex2へコピペする
 };


#endif