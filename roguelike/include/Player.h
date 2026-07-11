#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <iostream>

// Player inherits from Entity -> demonstrates inheritance.
// Overrides takeDamage() -> demonstrates polymorphism.
class Player : public Entity {
private:
    int score;

public:
    Player(int startX, int startY)
        : Entity(startX, startY, 100, '@'), score(0) {}

    // Polymorphic behavior: Player reacts to damage differently
    // than an Enemy will in later versions.
    void takeDamage(int amount) override {
        health -= amount;
        if (health < 0) health = 0;
        std::cout << "Player took " << amount << " damage! HP: "
                  << health << "/" << maxHealth << "\n";
    }

    void addScore(int points) { score += points; }
    int getScore() const { return score; }
};

#endif
