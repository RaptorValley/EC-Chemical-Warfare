#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <windows.h>
#include "class_definition_card.h"

// 辅助函数：去除字符串首尾空格和引号
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \"\t");
    size_t end   = s.find_last_not_of(" \"\t");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

Card parseECWCFile(const std::string& filename) {
    std::ifstream file(filename);
    Card          card;
    std::string   line;

    // 类型映射表
    const std::map<std::string, Card::Type> typeMap = {
        {"element", Card::element},
        {"equipment", Card::equipment},
        {"prop", Card::prop}};

    while (std::getline(file, line)) {
        size_t eqPos = line.find('=');
        if (eqPos == std::string::npos) continue;

        std::string key   = trim(line.substr(0, eqPos));
        std::string value = trim(line.substr(eqPos + 1));

        if (key == "name") {
            card.setName(value);
        } else if (key == "type") {
            auto it = typeMap.find(value);
            if (it != typeMap.end()) {
                card.setType(it->second);
            }
        } else if (key == "requirement") {
            try {
                card.setRequirement(std::stoul(value));
            } catch (...) {}
        } else if (key == "edition") {
            card.setEdition(value);
        }
    }

    return card;
}

// 使用示例：
int main() {
    Card myCard = parseECWCFile("card.ecwc");
    myCard.print();
    system("pause");
    return 0;
}