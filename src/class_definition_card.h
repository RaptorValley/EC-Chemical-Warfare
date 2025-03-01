#pragma once

#ifndef ___CLASS_DEFINITION_CARD_H
#define ___CLASS_DEFINITION_CARD_H

#include <iostream>

class Card {
  public:
    enum Type { element,
                equipment,
                prop };
    using D6 = unsigned int;

    // Setters
    void setName(const std::string& n) { name = n; }
    void setType(Type t) { type = t; }
    void setRequirement(unsigned int r) { requirement = r; }
    void setEdition(const std::string& e) { edition = e; }

    void print() {
        std::cout << " " << name << " " << type << " " << requirement << " " << edition << std::endl;
    }

  private:
    std::string name;
    Type        type;
    D6          requirement;
    std::string edition;
};

class Commander {
  private:
    std::string name; // 卡牌名称

    size_t hp_max; // 体力上限

    size_t card_max; // 即将推出：手牌上限
};

#endif //___CLASS_DEFINITION_CARD_H
