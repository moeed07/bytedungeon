#ifndef DUNGEON_H
#define DUNGEON_H

#include "Player.h"
#include <iostream>

const int DUNGEON_WIDTH = 20;
const int DUNGEON_HEIGHT = 10;

// Dungeon owns the grid and knows how to draw it.
// Using a plain 2D array on purpose (pure PF, no STL containers yet).
class Dungeon {
private:
    char grid[DUNGEON_HEIGHT][DUNGEON_WIDTH];

public:
    Dungeon() {
        buildLayout();
    }

    // v1: a simple hardcoded room with walls around the border.
    // v2 will replace this with random room generation.
    void buildLayout() {
        for (int row = 0; row < DUNGEON_HEIGHT; row++) {
            for (int col = 0; col < DUNGEON_WIDTH; col++) {
                bool isBorder = (row == 0 || row == DUNGEON_HEIGHT - 1 ||
                                  col == 0 || col == DUNGEON_WIDTH - 1);
                grid[row][col] = isBorder ? '#' : '.';
            }
        }
    }

    // Returns true if (x, y) is inside bounds and not a wall
    bool isWalkable(int x, int y) const {
        if (x < 0 || x >= DUNGEON_WIDTH || y < 0 || y >= DUNGEON_HEIGHT) {
            return false;
        }
        return grid[y][x] != '#';
    }

    // Draws the dungeon plus the player on top of it
    void render(const Player& player) const {
        // clear-ish effect for a slightly cleaner console redraw
        std::cout << "\n";

        for (int row = 0; row < DUNGEON_HEIGHT; row++) {
            for (int col = 0; col < DUNGEON_WIDTH; col++) {
                if (player.getX() == col && player.getY() == row) {
                    std::cout << player.getSymbol();
                } else {
                    std::cout << grid[row][col];
                }
            }
            std::cout << "\n";
        }

        std::cout << "\n";
    }
};

#endif
