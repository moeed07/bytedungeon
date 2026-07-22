#ifndef DUNGEON_H
#define DUNGEON_H

#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
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
                map[row][col] = '#';
            }
        }

        for (int row = 1; row <= 3; row++) {
            for (int col = 1; col <= 4; col++) {
                map[row][col] = '.';
            }
        }

        int roomCount = 4;
        for (int i = 0; i < roomCount; i++) {
            makeRoom();
        }
    }

    void makeRoom() {
        int roomWidth = rand() % 5 + 3;
        int roomHeight = rand() % 3 + 2;

        int startX = rand() % (WIDTH - roomWidth - 1) + 1;
        int startY = rand() % (HEIGHT - roomHeight - 1) + 1;

        for (int row = startY; row < startY + roomHeight; row++) {
            for (int col = startX; col < startX + roomWidth; col++) {
                map[row][col] = '.';
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

    void showMap(Player player, Enemy enemyList[], int enemyCount, Item* itemList[], bool itemPicked[], int itemCount) {
        cout << endl;
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                bool printed = false;

                if (player.getX() == col && player.getY() == row) {
                    cout << player.getSymbol();
                    printed = true;
                }

                if (!printed) {
                    for (int i = 0; i < enemyCount; i++) {
                        if (enemyList[i].isAlive() && enemyList[i].getX() == col && enemyList[i].getY() == row) {
                            cout << enemyList[i].getSymbol();
                            printed = true;
                        }
                    }
                }

                if (!printed) {
                    for (int i = 0; i < itemCount; i++) {
                        if (!itemPicked[i] && itemList[i]->getX() == col && itemList[i]->getY() == row) {
                            cout << '!';
                            printed = true;
                        }
                    }
                }

                if (!printed) {
                    cout << map[row][col];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

#endif