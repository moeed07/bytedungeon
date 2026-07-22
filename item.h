#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
private:
    string name;
    int healAmount;
    int x, y;

public:
    Item(string n, int heal, int startX, int startY) {
        name = n;
        healAmount = heal;
        x = startX;
        y = startY;
    }

    string getName() { return name; }
    int getHealAmount() { return healAmount; }
    int getX() { return x; }
    int getY() { return y; }
};

#endif