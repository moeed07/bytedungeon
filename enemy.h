#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <iostream>
using namespace std;

class Enemy : public Entity {
public:
    Enemy(int startX, int startY, int hp, int attack, char sym) : Entity(startX, startY, hp, attack, sym) {
    }

    void takeDamage(int amount) {
        health = health - amount;
        if (health < 0) {
            health = 0;
        }
        cout << "Enemy got hit! Health: " << health << endl;
    }

    virtual void specialAttack() {
        cout << "The enemy attacks normally." << endl;
    }
};

class Goblin : public Enemy {
public:
    Goblin(int startX, int startY) : Enemy(startX, startY, 30, 8, 'G') {
    }

    void specialAttack() {
        cout << "The goblin slashes twice quickly!" << endl;
    }
};

class Skeleton : public Enemy {
public:
    Skeleton(int startX, int startY) : Enemy(startX, startY, 50, 18, 'S') {
    }

    void specialAttack() {
        cout << "The skeleton swings its heavy bone club!" << endl;
    }
};

class Dragon : public Enemy {
public:
    Dragon(int startX, int startY) : Enemy(startX, startY, 100, 25, 'D') {
    }

    void specialAttack() {
        cout << "The dragon breathes fire!" << endl;
    }
};

#endif