#include "AmericanMahjong.h"
using namespace std;

/*------------------コンストラクタ----------------*/
AmericanMahjong::AmericanMahjong(){
    tiles_left = 152;
    set_all_tile();
    shuffle_all_tile();
    
}


/*------------------メンバ関数------------------*/
void AmericanMahjong::set_all_tile(){// 牌を山にセットする
    
    // クラック,ドット,バンブーの1~9牌を山に入れる
    for(int i=1; i<10; i++){
        for(int j=1; j<5; j++){
            Tiles *ptr1 = new Tiles('a',i);
            yama.push_back(ptr1);
            Tiles *ptr2 = new Tiles('b',i);
            yama.push_back(ptr2);
            Tiles *ptr3 = new Tiles('c',i);
            yama.push_back(ptr3);
        }
    }
    
    // 各種ドラゴン, WINDSを山に入れる
    for(int i=1; i<5; i++){
        Tiles *ptr1 = new Tiles('d',0);
        yama.push_back(ptr1);
        Tiles *ptr2 = new Tiles('e',0);
        yama.push_back(ptr2);
        Tiles *ptr3 = new Tiles('f',0);
        yama.push_back(ptr3);
        Tiles *ptr4 = new Tiles('g',0);
        yama.push_back(ptr4);
        Tiles *ptr5 = new Tiles('h',0);
        yama.push_back(ptr5);
        Tiles *ptr6 = new Tiles('i',0);
        yama.push_back(ptr6);
        Tiles *ptr7 = new Tiles('j',0);
        yama.push_back(ptr7);
    }
    
    // フラワー, JOKERを山に入れる
    for(int i=1; i<9; i++){
        Tiles *ptr1 = new Tiles('k',0);
        yama.push_back(ptr1);
        Tiles *ptr2 = new Tiles('l',0);
        yama.push_back(ptr2);
    }
}

void AmericanMahjong::shuffle_all_tile(){
    srand (static_cast<unsigned int>(time(NULL)));
    for(int i=0; i<NUMTILE; i++){ // 配列を横断しtiles[i]を値をランダムで別の値にスワップしシャッフルする
        int rand_pos = rand()%152;
        swap_ptrs(i,rand_pos);
//      swap_tiles(i,rand_pos); // 牌のポインタをスワップする
    }
}

void AmericanMahjong::set_individual_tile(int wind_num){
      
    // tehuda1 14牌格納
    for(int i=1; i<15; i++){
        char ch = yama[tiles_left-1]->type;
        int n = yama[tiles_left-1]->data;
        Tiles *ptr = new Tiles(ch,n);
        tehuda1.push_back(ptr);
        delete (ptr); // メモリを開放
        yama.pop_back();
        tiles_left--;
    }
    // tehuda2 13牌格納
    for(int i=1; i<14; i++){
        char ch = yama[tiles_left-1]->type;
        int n = yama[tiles_left-1]->data;
        Tiles *ptr = new Tiles(ch,n);
        tehuda2.push_back(ptr);
        delete (ptr); // メモリを開放
        yama.pop_back();
        tiles_left--;
    }
    
    // tehuda3 13牌格納
    for(int i=1; i<14; i++){
        char ch = yama[tiles_left-1]->type;
        int n = yama[tiles_left-1]->data;
        Tiles *ptr = new Tiles(ch,n);
        tehuda3.push_back(ptr);
        delete (ptr); // メモリを開放
        yama.pop_back();
        tiles_left--;
    }
    
    // tehuda4 13牌格納
    for(int i=1; i<14; i++){
        char ch = yama[tiles_left-1]->type;
        int n = yama[tiles_left-1]->data;
        Tiles *ptr = new Tiles(ch,n);
        tehuda4.push_back(ptr);
        delete (ptr); // メモリを開放
        yama.pop_back();
        tiles_left--;
    }

    /*この時点で山は152-(13*3+14)、で各プレーヤーに牌が分配されてる状態*/

    if(wind_num==0){
        myCards = tehuda1;
        cp1Cards = tehuda2;
        cp2Cards = tehuda3;
        cp3Cards = tehuda4;
    }
    else if(wind_num==1){
        myCards = tehuda2;
        cp1Cards = tehuda1;
        cp2Cards = tehuda3;
        cp3Cards = tehuda4;
     }
    else if(wind_num==2){
        myCards = tehuda3;
        cp1Cards = tehuda2;
        cp2Cards = tehuda1;
        cp3Cards = tehuda4;
     }
    else{
        myCards = tehuda4;
        cp1Cards = tehuda2;
        cp2Cards = tehuda3;
        cp3Cards = tehuda1;
    }
    
    sort_player_tiles(); // 牌をソート
}

void AmericanMahjong::swap_ptrs(int index1, int index2){ //index1とindex2のポインタをスワップ
    Tiles *temp = yama[index1];
    yama[index1] = yama[index2];
    yama[index2] = temp;
}


void AmericanMahjong::sort_player_tiles(){ // プレイヤーのカードをソート
    
    sort(myCards.begin(), myCards.end(),
              [] (const Tiles* l, const Tiles* r)
              {   // 数値順にソート
                  return l->data < r->data;
              });
    
    sort(myCards.begin(), myCards.end(),
              [] (const Tiles* l, const Tiles* r)
              {   // タイプ順にソート
                  return l->type < r->type;
              });
}

//void AmericanMahjong::print_my_tile(){ cout << yama[0].type << ' ' << yama[0].data << endl;}
void AmericanMahjong::print_my_tile(){ // 自分の牌を表示
    //-------------プレーヤーの牌を表示----------------
    cout << "***CARDS***" << endl;
    cout  << "プレーヤー: ";
    int length = static_cast<unsigned int>(myCards.size());
    int i=0;
    while(i<length){
        cout << myCards[i]->type << myCards[i]->data << "  ";
        i++;
    }
    
    // 捨てる牌を選択するときの数字
    i=0;
    cout << "\n牌選択用:   ";
    while(i<length){
        cout << left << setw(4) << i+1 ;
        i++;
    }
    
    //-------------CPU1~4の牌を表示------------------(※プログラム完成後削除する機能)
    cout  << "\n\nCPU1の牌: ";
    length = static_cast<unsigned int>(cp1Cards.size());
    i=0;
    while(i<length){
        cout << cp1Cards[i]->type << cp1Cards[i]->data << ' ';
        i++;
    }
    
    cout << "\n\nCPU2の牌: ";
    length = static_cast<unsigned int>(cp2Cards.size());
    i=0;
    while(i<length){
        cout << cp2Cards[i]->type << cp2Cards[i]->data << ' ';
        i++;
    }
    
    cout << "\n\nCPU3の牌: ";
    length = static_cast<unsigned int>(cp3Cards.size());
    i=0;
    while(i<length){
        cout << cp3Cards[i]->type << cp3Cards[i]->data << ' ';
        i++;
    }
    
    cout << endl << endl;
    
}

void AmericanMahjong::print_introduction(int gameCount, Wind wind){
    cout << "\n---------------------GAME" << gameCount << "-----------------------\n";
    cout << "***WINDS***" << endl
        << "PLAYER: " << wind.myWind[0]
        << "\nCPU1:   " << wind.myWind[1]
        << "\nCPU2:   " << wind.myWind[2]
        << "\nCPU3:   " << wind.myWind[3] << "\n\n\n";
}


void AmericanMahjong::trade_tiles(){
    /*---------牌の交換について----------
     -牌の交換はゲーム序盤にプレーヤー同士で行い、
     交換をすることでプレーヤーや狙った役に必要な牌を集めたり自分に必要の無い牌を手札から除外したりできる
     
     ------------交換の手順-------------
     1.右隣のプレーヤーへ牌を３つ送り,左隣のプレーヤーから牌を３つもらう
     2.向かい合わせのプレーヤーへ牌を３つ交換する
     3.1左隣のプレーヤーへ牌を３つ送り,右隣のプレーヤーから牌を３つもらう
     3.2この際,もしプレーヤーが手持ちの牌を出したく無い場合は,右隣のプレーヤーの牌をブラインドパスできる
     4.向かい合わせのプレーヤーと最大３つまで牌を交換する
     5.1メッシュ:各プレーヤーは最大４つまで牌を出す
     5.2親から反時計回りの順番に各プレーヤーは自分の出した牌の数だけ牌を取る
     以上
     */
    
    int tile1, tile2, tile3; // 捨てる牌の索引を入手する
    cout << "SELECT 3 TILES TO GIVE TO RIGHT NEXT PLAYER: ";
    cin >> tile1 >> tile2 >> tile3;
    
    
    Tiles *temp1, *temp2, *temp3;
    
    
    //=====================ここから作業=========================
    
}




//-------------------------作ったけど使わないかもしれないメンバ関数--------------------------

//void AmericanMahjong::swap_tiles(int index1, int index2){ // 牌の値をスワップする
//    char temp_ch = yama[index2]->type;
//    int temp_int = yama[index2]->data;
//
//    yama[index2]->type = yama[index1]->type;
//    yama[index2]->data = yama[index1]->data;
//
//    yama[index1]->type = temp_ch;
//    yama[index1]->data = temp_int;
//}
