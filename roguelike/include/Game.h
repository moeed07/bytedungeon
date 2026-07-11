#ifndef GAME_H
#define GAME_H

#include "Dungeon.h"
#include "Player.h"
#include <iostream>

// Game ties everything together: owns the Dungeon and the Player,
// runs the loop, and processes input.
class Game {
private:
    Dungeon dungeon;
    Player player;
    bool running;

public:
    Game() : player(1, 1), running(true) {}

    void run() {
        std::cout << "=== Terminal Roguelike v1 ===\n";
        std::cout << "Move with W/A/S/D. Press Q to quit.\n";

        while (running) {
            dungeon.render(player);
            processInput();
        }

        std::cout << "Thanks for playing! Final score: "
                  << player.getScore() << "\n";
    }

private:
    void processInput() {
        char input;
        std::cout << "Move (w/a/s/d/q): ";
        std::cin >> input;

        int newX = player.getX();
        int newY = player.getY();

        switch (input) {
            case 'w': newY--; break;
            case 's': newY++; break;
            case 'a': newX--; break;
            case 'd': newX++; break;
            case 'q':
                running = false;
                return;
            default:
                std::cout << "Invalid input. Use w/a/s/d/q.\n";
                return;
        }

        // Dungeon decides whether the move is legal (collision handling)
        if (dungeon.isWalkable(newX, newY)) {
            player.setPosition(newX, newY);
        } else {
            std::cout << "You bump into a wall.\n";
        }
    }
};

#endif
