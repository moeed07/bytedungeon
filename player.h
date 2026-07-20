#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <iostream>
using namespace std;

class Player : public Entity {
private:
    int score;

public:
    Player(int startX, int startY) : Entity(startX, startY, 100, 15, '@') {
        score = 0;
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
};

#endif