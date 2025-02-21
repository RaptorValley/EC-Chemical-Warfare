#pragma once

#ifndef ___CLASS_DEFINITION_CARD_H
#define ___CLASS_DEFINITION_CARD_H

#include <iostream>

class Card {
  private:
    std::string name; // 卡牌名称

    enum Type { element,   // 元素
                equipment, // 装置
                prop,      // 道具
    };

    using D6 = unsigned int;
    D6 requirement; // 至低点数

    std::string edition; // 推出版本
};

class Commander {
  private:
    std::string name; // 卡牌名称
    size_t
};

#endif //___CLASS_DEFINITION_CARD_H
