#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    int x, y;
    int health;
    char symbol;

public:
    Entity(int startX, int startY, int hp, char sym) {
        x = startX;
        y = startY;
        health = hp;
        symbol = sym;
    }

    virtual void takeDamage(int amount) = 0;

    int getX() { return x; }
    int getY() { return y; }
    int getHealth() { return health; }
    char getSymbol() { return symbol; }

    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

#endif