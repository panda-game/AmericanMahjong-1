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
        swap_ptrs_index(i,rand_pos); // 牌のポインタをスワップする
    }
}

void AmericanMahjong::set_individual_tile(int wind_num){
      
    // tehuda1 14牌格納
    for(int i=1; i<15; i++){
        Tiles *ptr = yama[tiles_left-1];
        tehuda1.push_back(ptr);
        tiles_left--;
    }
    // tehuda2 13牌格納
    for(int i=1; i<14; i++){
        Tiles *ptr = yama[tiles_left-1];
        tehuda2.push_back(ptr);
        tiles_left--;    }
    
    // tehuda3 13牌格納
    for(int i=1; i<14; i++){
        Tiles *ptr = yama[tiles_left-1];
        tehuda3.push_back(ptr);
        tiles_left--;    }
    
    // tehuda4 13牌格納
    for(int i=1; i<14; i++){
        Tiles *ptr = yama[tiles_left-1];
        tehuda4.push_back(ptr);
        tiles_left--;    }

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

void AmericanMahjong::swap_ptrs_index(int index1, int index2){ // index1とindex2のポインタをスワップ
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

void AmericanMahjong::print_my_tile(){ // 自分の牌を表示
    //-------------プレーヤーの牌を表示----------------
    cout  << "プレーヤー: ";
    int length = static_cast<unsigned int>(myCards.size());
    int i=0;
    while(i<length){
        print_tile(myCards[i]);
        cout << ' ';
        i++;
    }
    
    // 捨てる牌を選択するときの数字
    i=0;
    cout << "\n牌選択用:   ";
    while(i<length){
        cout << left << setw(4) << i+1 ;
        i++;
    }
    
    
    
    /*
    //-------------CPU1~4の牌を表示------------------(※プログラム完成後削除する機能)
    cout  << "\n\nCPU1の牌: ";
    length = static_cast<unsigned int>(cp1Cards.size());
    i=0;
    while(i<length){
        print_tile(cp1Cards[i]);
        i++;
    }
    
    cout << "\n\nCPU2の牌: ";
    length = static_cast<unsigned int>(cp2Cards.size());
    i=0;
    while(i<length){
        print_tile(cp2Cards[i]);
        i++;
    }
    
    cout << "\n\nCPU3の牌: ";
    length = static_cast<unsigned int>(cp3Cards.size());
    i=0;
    while(i<length){
        print_tile(cp3Cards[i]);
        i++;
    }
     
    */
    cout << endl << endl;
    
}

void AmericanMahjong::print_tile(Tiles* ptr){
    cout << ptr->type << ptr->data << ' ';
}

void AmericanMahjong::print_introduction(int gameCount, Wind wind){
    cout << "\n---------------------GAME" << gameCount << "-----------------------\n";
    cout << "***WINDS***" << endl
        << "PLAYER: " << wind.myWind[0]
        << "\nCPU1:   " << wind.myWind[1]
        << "\nCPU2:   " << wind.myWind[2]
        << "\nCPU3:   " << wind.myWind[3] << "\n\n\n";
}


void AmericanMahjong::trade_tiles1(){
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
    cout << "\nSELECT 3 TILES TO GIVE TO RIGHT NEXT PLAYER.\n";
    get_tehuda_index(tile1, tile2, tile3);
    
    Tiles *temp1, *temp2, *temp3; // 牌を一時的に保存
    temp1 = myCards[tile1-1];
    temp2 = myCards[tile2-1];
    temp3 = myCards[tile3-1];
    
    // CPU3の牌を自分の手札へコピー(正確にはポインタを変えるだけ)
    int rand_pos1, rand_pos2, rand_pos3;
    generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp3Cards.size()));
    myCards[tile1-1] = cp3Cards[rand_pos1];
    myCards[tile2-1] = cp3Cards[rand_pos2];
    myCards[tile3-1] = cp3Cards[rand_pos3];
    
    // 入手した牌を表示
    cout << "\nYOU GOT ";
    print_tile(cp3Cards[rand_pos1]);
    print_tile(cp3Cards[rand_pos2]);
    print_tile(cp3Cards[rand_pos3]);
    cout << endl;
    
    // CPU2の牌をCPU3の手札へコピー
    int rand_pos4, rand_pos5, rand_pos6;
    generate_random_three(rand_pos4, rand_pos5, rand_pos6, static_cast<unsigned int>(cp2Cards.size()));
    cp3Cards[rand_pos1] = cp2Cards[rand_pos4];
    cp3Cards[rand_pos2] = cp2Cards[rand_pos5];
    cp3Cards[rand_pos3] = cp2Cards[rand_pos6];
    
    // CPU1の牌をCPU2の手札へコピー
    generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp1Cards.size()));
    cp2Cards[rand_pos4] = cp1Cards[rand_pos1];
    cp2Cards[rand_pos5] = cp1Cards[rand_pos2];
    cp2Cards[rand_pos6] = cp1Cards[rand_pos3];
    
    // 自分の捨てた牌をCPU1の手札へコピー
    cp1Cards[rand_pos1] = temp1;
    cp1Cards[rand_pos2] = temp2;
    cp1Cards[rand_pos3] = temp3;
    
    // プレイヤーの牌をソート
    sort_player_tiles();
}

void AmericanMahjong::trade_tiles2(){

    int tile1, tile2, tile3; // 捨てる牌の索引を入手する
    cout << "\nSELECT 3 TILES TO GIVE TO OPPOSITE PLAYER.\n";
    get_tehuda_index(tile1, tile2, tile3);

    int rand_pos1, rand_pos2, rand_pos3;
    generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp2Cards.size()));
    
    swap(myCards[tile1-1], cp2Cards[rand_pos1]); // ポインタをスワップ
    swap(myCards[tile2-1], cp2Cards[rand_pos2]);
    swap(myCards[tile3-1], cp2Cards[rand_pos3]);

    
    cout << "YOU GOT "; // 入手した牌を表示
    print_tile(myCards[tile1-1]);
    print_tile(myCards[tile2-1]);
    print_tile(myCards[tile3-1]);
    cout << endl;
    
    // プレイヤーの牌をソート
    sort_player_tiles();
    
}

void AmericanMahjong::trade_tiles3(){ // 3回めの牌の交換
    int tile1, tile2, tile3; // 捨てる牌の索引を入手する
    cout << "\nSELECT 3 TILES TO GIVE TO LEFT NEXT PLAYER.\n"; // ***本来ならブラインドパスの機能がある。後で実装する予定
    get_tehuda_index(tile1, tile2, tile3);
    
    Tiles *temp1, *temp2, *temp3; // 牌を一時的に保存
    temp1 = myCards[tile1-1];
    temp2 = myCards[tile2-1];
    temp3 = myCards[tile3-1];
    
    // CPU1の牌を自分の手札へコピー(正確にはポインタを変えるだけ)
    int rand_pos1, rand_pos2, rand_pos3;
    generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp1Cards.size()));
    myCards[tile1-1] = cp1Cards[rand_pos1];
    myCards[tile2-1] = cp1Cards[rand_pos2];
    myCards[tile3-1] = cp1Cards[rand_pos3];
    
    // 入手した牌を表示
    cout << "\nYOU GOT ";
    print_tile(cp1Cards[rand_pos1]);
    print_tile(cp1Cards[rand_pos2]);
    print_tile(cp1Cards[rand_pos3]);
    cout << endl;
    
    // CPU2の牌をCPU1の手札へコピー
    int rand_pos4, rand_pos5, rand_pos6;
    generate_random_three(rand_pos4, rand_pos5, rand_pos6, static_cast<unsigned int>(cp2Cards.size()));
    cp1Cards[rand_pos1] = cp2Cards[rand_pos4];
    cp1Cards[rand_pos2] = cp2Cards[rand_pos5];
    cp1Cards[rand_pos3] = cp2Cards[rand_pos6];
    
    // CPU3の牌をCPU2の手札へコピー
    generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp3Cards.size()));
    cp2Cards[rand_pos4] = cp3Cards[rand_pos1];
    cp2Cards[rand_pos5] = cp3Cards[rand_pos2];
    cp2Cards[rand_pos6] = cp3Cards[rand_pos3];
    
    // 自分の捨てた牌をCPU3の手札へコピー
    cp3Cards[rand_pos1] = temp1;
    cp3Cards[rand_pos2] = temp2;
    cp3Cards[rand_pos3] = temp3;
    
    // プレイヤーの牌をソート
    sort_player_tiles();
    
}

void AmericanMahjong::trade_tiles4(){
    int a; // 対面のCPUが交換できる牌の数
    a = rand()%4; // 0~3の整数をランダムに生成
    int b; // プレイヤーが交換できる牌の数
    cout << "\nHOW MANY TILES CAN YOU TRADE (ENTER 0-3): ";
    cin >> b;
    int c = (a > b)? b : a;
    
    cout << c;
    if(a != 0 && b != 0){
        if(c==1){
            int tile1;
            cout << "\nTRADING ONE TILES.";
            cout << "\nSELECT TILE INDEX: ";
            cin >> tile1;
            int rand_pos1, rand_pos2, rand_pos3;
            generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp2Cards.size()));
            swap(myCards[tile1-1], cp2Cards[rand_pos1]);
        } else if(c==2){
            int tile1, tile2;
            cout << "\nTRADING TWO TILES.";
            cout << "\nSELECT TILE INDEX 1: ";
            cin >> tile1;
            cout << "SELECT TILE INDEX 2: ";
            cin >> tile2;
            int rand_pos1, rand_pos2, rand_pos3;
            generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp2Cards.size()));
            swap(myCards[tile1-1], cp2Cards[rand_pos1]);
            swap(myCards[tile2-1], cp2Cards[rand_pos2]);
        } else {
            int tile1, tile2, tile3; // 捨てる牌の索引を入手する
            cout << "\nTRADING THREE TILES.";
            cout << "\nSELECT TILE INDEX 1: ";
            get_tehuda_index(tile1, tile2, tile3);
            
            int rand_pos1, rand_pos2, rand_pos3;
            generate_random_three(rand_pos1, rand_pos2, rand_pos3, static_cast<unsigned int>(cp2Cards.size()));
            
            swap(myCards[tile1-1], cp2Cards[rand_pos1]); // ポインタをスワップ
            swap(myCards[tile2-1], cp2Cards[rand_pos2]);
            swap(myCards[tile3-1], cp2Cards[rand_pos3]);
        }
    } else { // CPU2かプレイヤーが牌を交換しないと選択した場合
        cout << "\nEITHER PLAYER OR/AND CPU2 DECIDED NOT TO TRADE TILE.\nNO TRADE THIS ROUND.\n";
    }
}

void AmericanMahjong::trade_tiles5(){
    //***良い方法考え中、後で直すこと***
    cout << "";
}

void AmericanMahjong::start_game(Wind wind){
    cards.push_back(&myCards);
    cards.push_back(&cp1Cards);
    cards.push_back(&cp2Cards);
    cards.push_back(&cp3Cards);
    
    int num_krack=0, num_bamboo=0, num_dot=0;
    int num_red=0, num_green=0, num_soap=0;
    int num_east=0, num_west=0, num_south=0, num_north=0;
    int num_flower=0, num_joker=0;
    
    num_each_tiles.push_back(num_krack);
    num_each_tiles.push_back(num_bamboo);
    num_each_tiles.push_back(num_dot);
    num_each_tiles.push_back(num_red);
    num_each_tiles.push_back(num_green);
    num_each_tiles.push_back(num_soap);
    num_each_tiles.push_back(num_east);
    num_each_tiles.push_back(num_west);
    num_each_tiles.push_back(num_south);
    num_each_tiles.push_back(num_north);
    num_each_tiles.push_back(num_flower);
    num_each_tiles.push_back(num_joker);
    
    
    
    int i;
    if(wind.myWind[0] == "EAST"){
        i=0;
        discard_tile_player();
    }
    else {
        if(wind.myWind[1] == "EAST") i=1;
        else if(wind.myWind[2] == "EAST") i=2;
        else i=3;
        discard_tile_CPU(i);
    }
    
    while(i<20){
        i++;
        int j = i%4;
        get_tile(j);
        if(j == 0){ // jが4の倍数の時は自分が牌を捨てる
            discard_tile_player();
        } else { // jが4の倍数ではない時はCPUが牌を捨てる
            discard_tile_CPU(j);
        }
    }
    
    evaluate_yaku(0);
    
    
}

void AmericanMahjong::get_tile(int i){
    cards[i]->push_back(yama[tiles_left-1]); // yamaから一つ牌をcardsにプッシュする
    if(cards[i] == &myCards){// プレイヤーの手札に牌が来た時は教えてあげる
        cout << "\n***YOUR TURN***" << endl;
        cout << "YOU GOT ";
        print_tile(yama[tiles_left-1]);
        cout << "\n" << tiles_left << " TILES LEFT IN YAMA\n";
        cout << endl;
    }
    sort_player_tiles(); // 牌をソート
    tiles_left--; // 牌を一つ減少
}



void AmericanMahjong::discard_tile_CPU(int i){
    int index = rand()%(static_cast<unsigned int>(cards[i]->size())); // ランダムに捨てる牌の索引を生成
    if(i == 1){ cout << "CPU1 DISCARDED "; print_tile(cp1Cards[index]); }
    if(i == 2){ cout << "CPU2 DISCARDED "; print_tile(cp2Cards[index]); }
    if(i == 3){ cout << "CPU3 DISCARDED "; print_tile(cp3Cards[index]); }
    cards[i]->erase(cards[i]->begin()+index); // 索引indexにあるタイルをベクターから削除
    cout << endl;
}

void AmericanMahjong::discard_tile_player(){
    if(tiles_left != 99) print_my_tile(); // 最初自分が親で始まるときは牌を表示しなくて良い
    cout << "SELECT INDEX OF TILE YOU WANT TO DISCARD: ";
    int index;
    cin >> index;
    while(!(index > 0 && index <= 14)){
        cin.ignore(256,'\n');
        cout << "INDEX OUT OF RANGE, TRY AGAIN: ";
        cin >> index;
    }
    cout << "YOU DISCARDED ";
    print_tile(myCards[index-1]);
    cout << endl;
    myCards.erase(myCards.begin()+(index - 1)); // 索引の牌をベクターから削除
}


int AmericanMahjong::evaluate_yaku(int i){
    /*
     ---------役の評価について----------
     1. 手札構成を確認する
     2. ??                   */
    count_tileType(0);
    
    int num_kinds = 0;
    
    for(int i=0; i<12; i++){ // num_each_tileには12種類の牌のそれぞれの個数が保存されている
        if(num_each_tiles[i] != 0) num_kinds++;
    }
    
    cout << "YOU GOT...\n" << num_each_tiles[0] << " KRACKS, " << num_each_tiles[1]
    << " BAMBOOS, " << num_each_tiles[2] << " DOTS." << endl;
    
    cout << "THERE ARE " << num_kinds << " KINDS OF TILES IN TEHUDA." << endl;

    
    
    
    /*
    count_krack_bamboo_dot(num_krack, num_bamboo, num_dot, 0); // クラック、バンブー、ドット牌の数をカウントする
    count_dragons(num_red, num_green, num_soap, 0); // ドラゴン牌の数をカウントする
    count_winds(num_east, num_west, num_south, num_north, 0); // WINDS牌の数をカウントする
    count_flower_joker(num_flower, num_joker, 0); // JOKERとFLOWERの牌の数をカウントする
    */
    
    return 0;
}

void AmericanMahjong::count_tileType(int x){
    int i=0;
    
    for(int y=0; y<cards[x]->size(); y++){
        if( (*cards[x])[y]->type == 'a') num_each_tiles[i]++;
        if( (*cards[x])[y]->type == 'b') num_each_tiles[i+1]++;
        if( (*cards[x])[y]->type == 'c') num_each_tiles[i+2]++;
        if( (*cards[x])[y]->type == 'd') num_each_tiles[i+3]++;
        if( (*cards[x])[y]->type == 'e') num_each_tiles[i+4]++;
        if( (*cards[x])[y]->type == 'f') num_each_tiles[i+5]++;
        if( (*cards[x])[y]->type == 'g') num_each_tiles[i+6]++;
        if( (*cards[x])[y]->type == 'h') num_each_tiles[i+7]++;
        if( (*cards[x])[y]->type == 'i') num_each_tiles[i+8]++;
        if( (*cards[x])[y]->type == 'j') num_each_tiles[i+9]++;
        if( (*cards[x])[y]->type == 'k') num_each_tiles[i+10]++;
        if( (*cards[x])[y]->type == 'l') num_each_tiles[i+11]++;
    }
}

/*
void AmericanMahjong::count_krack_bamboo_dot(int &a, int &b, int &c, int i){
    for(int j=0; j<cards[i]->size(); j++){
        if( (*cards[i])[j]->type == 'g') a++;
        if( (*cards[i])[j]->type == 'h') b++;
        if( (*cards[i])[j]->type == 'i') c++;
    }
}

void AmericanMahjong::count_dragons(int &a, int &b, int &c, int i){
    for(int j=0; j<cards[i]->size(); j++){
        if( (*cards[i])[j]->type == 'g') a++;
        if( (*cards[i])[j]->type == 'h') b++;
        if( (*cards[i])[j]->type == 'i') c++;
    }
}

void AmericanMahjong::count_winds(int &a, int &b, int &c, int &d, int i){
    for(int j=0; j<cards[i]->size(); j++){
        if( (*cards[i])[j]->type == 'g') a++;
        if( (*cards[i])[j]->type == 'h') b++;
        if( (*cards[i])[j]->type == 'i') c++;
        if( (*cards[i])[j]->type == 'j') d++;
    }
}

void AmericanMahjong::count_flower_joker(int &a, int &b, int i){
    for(int j=0; j<cards[i]->size(); j++){
        if( (*cards[i])[j]->type == 'k') a++;
        if( (*cards[i])[j]->type == 'l') b++;
    }
}
*/

void AmericanMahjong::get_tehuda_index(int &a, int &b, int &c){
    cout << "\nFIRST TILE INDEX:";
    cin >> a;
    while(!(a > 0 && a <= 14)){
        cin.ignore(256,'\n');
        cout << "INDEX OUT OF RANGE, TRY AGAIN: ";
        cin >> a;
    }
    cout << "SECOND TILE INDEX:";
    while(!(b > 0 && b <= 14)){
        cin.ignore(256,'\n');
        cout << "INDEX OUT OF RANGE, TRY AGAIN: ";
        cin >> b;
    }
    cin >> b;
    cout << "THIRD TILE INDEX:";
    cin >> c;
    while(!(c > 0 && c <= 14)){
        cin.ignore(256,'\n');
        cout << "INDEX OUT OF RANGE, TRY AGAIN: ";
        cin >> c;
    }
}


void AmericanMahjong::generate_random_three(int &a, int &b, int &c, unsigned int size){
    while(true){ // 3つの異なる整数を生成する
        a = rand()%size;
        b = rand()%size;
        c = rand()%size;
        if(a != b && b != c && a != c) break;
    }
}

AmericanMahjong::~AmericanMahjong(){ // デストラクタ
    cout << "\n\nCALLING DESTRUCTOR.\n\n";
    int i=0;
    while(i<NUMTILE){
        delete yama[i];
        i++;
    }
}