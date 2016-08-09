#include "AmericanMahjong.h"
using namespace std;

/*------------------コンストラクタ----------------*/
AmericanMahjong::AmericanMahjong(){
    set_all_tile();
    shuffle_all_tile();
    
}


/*------------------メンバ関数------------------*/
void AmericanMahjong::set_all_tile(){// 牌を山にセットする
    
    // クラック,ドット,バンブーの1~9牌を山に入れる
    for(int i=1; i<10; i++){
        for(int j=1; j<5; j++){
            Tiles *ptr1 = new Tiles('a',i);
            yama.push_back(*ptr1);
            Tiles *ptr2 = new Tiles('b',i);
            yama.push_back(*ptr2);
            Tiles *ptr3 = new Tiles('c',i);
            yama.push_back(*ptr3);
        }
    }
    
    // 各種ドラゴン, WINDSを山に入れる
    for(int i=1; i<5; i++){
        Tiles *ptr1 = new Tiles('d',1);
        yama.push_back(*ptr1);
        Tiles *ptr2 = new Tiles('e',1);
        yama.push_back(*ptr2);
        Tiles *ptr3 = new Tiles('f',1);
        yama.push_back(*ptr3);
        Tiles *ptr4 = new Tiles('g',1);
        yama.push_back(*ptr4);
        Tiles *ptr5 = new Tiles('h',1);
        yama.push_back(*ptr5);
        Tiles *ptr6 = new Tiles('i',1);
        yama.push_back(*ptr6);
        Tiles *ptr7 = new Tiles('j',1);
        yama.push_back(*ptr7);
    }
    
    // フラワー, JOKERを山に入れる
    for(int i=1; i<9; i++){
        Tiles *ptr1 = new Tiles('k',1);
        yama.push_back(*ptr1);
        Tiles *ptr2 = new Tiles('l',1);
        yama.push_back(*ptr2);
    }
}

void AmericanMahjong::shuffle_all_tile(){
    srand (time(NULL));
    for(int i=0; i<NUMTILE; i++){ // 配列を横断しtiles[i]を値をランダムで別の値にスワップしシャッフルする
                int rand_pos = rand()%152;
        swap_tiles(i,rand_pos); // 牌の値をスワップする
    }
}

void AmericanMahjong::set_individual_tile(bool isPlayerEast){
    if(isPlayerEast){ // プレーヤーが親の場合
        //なおして
    } else { // プレーヤーが親ではない場合
        //なおして
    }
}

void AmericanMahjong::swap_tiles(int index1, int index2){ // 牌の値をスワップする
    char temp_ch = yama[index2].type;
    int temp_int = yama[index2].data;
    
    yama[index2].type = yama[index1].type;
    yama[index2].data = yama[index1].data;
    
    yama[index1].type = temp_ch;
    yama[index1].data = temp_int;
}

void AmericanMahjong::print_my_tile(){ cout << yama[0].type << ' ' << yama[0].data << endl;}


void AmericanMahjong::print_introduction(int gameCount){ // なおして
}