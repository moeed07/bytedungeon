#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    int x, y;
    int health;
    int attackPower;
    char symbol;

public:
    Entity(int startX, int startY, int hp, int attack, char sym) {
        x = startX;
        y = startY;
        health = hp;
        attackPower = attack;
        symbol = sym;
    }

    virtual void takeDamage(int amount) = 0;

    int getX() { return x; }
    int getY() { return y; }
    int getHealth() { return health; }
    int getAttackPower() { return attackPower; }
    char getSymbol() { return symbol; }
    bool isAlive() { return health > 0; }

    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

#endif