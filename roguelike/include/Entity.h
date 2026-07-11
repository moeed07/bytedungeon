#ifndef ENTITY_H
#define ENTITY_H

// Abstract base class for anything that exists in the dungeon.
// Player, Enemy, etc. will all inherit from this in later versions.
class Entity {
protected:
    int x, y;          // position on the dungeon grid
    int health;
    int maxHealth;
    char symbol;        // how this entity is drawn on the map

public:
    Entity(int startX, int startY, int hp, char sym)
        : x(startX), y(startY), health(hp), maxHealth(hp), symbol(sym) {}

    virtual ~Entity() {}

    // Pure virtual -> forces every derived class to define its own behavior
    virtual void takeDamage(int amount) = 0;

    // Getters (encapsulation: outside code can't touch x, y, health directly)
    int getX() const { return x; }
    int getY() const { return y; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    char getSymbol() const { return symbol; }
    bool isAlive() const { return health > 0; }

    // Used by Game to move the entity; Dungeon decides if the move is legal
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

#endif
