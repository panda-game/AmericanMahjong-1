#include "Dice.h"

Dice::Dice(){
    die_num = rand() % 10 + 2; // 2-12の整数をランダムに生成
}

int Dice::get_die_num(){
    return die_num;
}