#include "Tiles.h"

Tiles::Tiles(){ // デフォルトコンストラクタ
    type = ' ';
    data = 0;
}

Tiles::Tiles(char ch, int n){ // 引数付きコンストラクタ
    type = ch;
    data = n;
}