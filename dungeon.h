#ifndef DUNGEON_H
#define DUNGEON_H

#include "player.h"
#include <iostream>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 10;

class Dungeon {
private:
    char map[HEIGHT][WIDTH];

public:
    Dungeon() {
        makeMap();
    }

    void makeMap() {
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                if (row == 0 || row == HEIGHT - 1 || col == 0 || col == WIDTH - 1) {
                    map[row][col] = '#';
                } else {
                    map[row][col] = '.';
                }
            }
        }
    }

    bool canMove(int x, int y) {
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
            return false;
        }
        if (map[y][x] == '#') {
            return false;
        }
        return true;
    }

    void showMap(Player player) {
        cout << endl;
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                if (player.getX() == col && player.getY() == row) {
                    cout << player.getSymbol();
                } else {
                    cout << map[row][col];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

#endif