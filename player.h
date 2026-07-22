#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Item.h"
#include <iostream>
using namespace std;

class Player : public Entity {
private:
    int score;
    Item* inventory[10];
    int itemCount;

public:
    Player(int startX, int startY) : Entity(startX, startY, 100, 15, '@') {
        score = 0;
        itemCount = 0;
    }

    void takeDamage(int amount) {
        health = health - amount;
        if (health < 0) {
            health = 0;
        }
        cout << "You got hit! Health: " << health << endl;
    }

    void addScore(int points) {
        score = score + points;
    }

    int getScore() {
        return score;
    }

    void addItem(Item* item) {
        inventory[itemCount] = item;
        itemCount++;
        cout << "Picked up: " << item->getName() << endl;
    }

    void showInventory() {
        if (itemCount == 0) {
            cout << "Inventory is empty." << endl;
            return;
        }
        cout << "Inventory:" << endl;
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". " << inventory[i]->getName() << endl;
        }
    }

    void useItem(int index) {
        if (index >= 0 && index < itemCount) {
            health = health + inventory[index]->getHealAmount();
            if (health > 100) {
                health = 100;
            }
            cout << "Used " << inventory[index]->getName() << ". Health: " << health << endl;

            delete inventory[index];
            for (int j = index; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
        }
        else {
            cout << "Invalid item number." << endl;
        }
    }

    int getItemCount() {
        return itemCount;
    }

    ~Player() {
        for (int i = 0; i < itemCount; i++) {
            delete inventory[i];
        }
    }
};

#endif