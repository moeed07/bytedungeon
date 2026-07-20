#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <iostream>
using namespace std;

class Enemy : public Entity {
public:
    Enemy(int startX, int startY) : Entity(startX, startY, 40, 10, 'E') {
    }

    void takeDamage(int amount) {
        health = health - amount;
        if (health < 0) {
            health = 0;
        }
        cout << "Enemy got hit! Enemy health: " << health << endl;
    }
};

#endif