#ifndef GAME_H
#define GAME_H

#include "dungeon.h"
#include "player.h"
#include <iostream>
using namespace std;

class Game {
private:
    Dungeon dungeon;
    Player player;
    bool isRunning;

public:
    Game() : player(1, 1) {
        isRunning = true;
    }

    void start() {
        cout << "Welcome to the dungeon!" << endl;
        cout << "Use w a s d to move. Press q to quit." << endl;

        while (isRunning) {
            dungeon.showMap(player);
            getInput();
        }

        cout << "Game over. Score: " << player.getScore() << endl;
    }

    void getInput() {
        char key;
        cout << "Move: ";
        cin >> key;

        int newX = player.getX();
        int newY = player.getY();

        if (key == 'w') {
            newY = newY - 1;
        } else if (key == 's') {
            newY = newY + 1;
        } else if (key == 'a') {
            newX = newX - 1;
        } else if (key == 'd') {
            newX = newX + 1;
        } else if (key == 'q') {
            isRunning = false;
            return;
        } else {
            cout << "Wrong key" << endl;
            return;
        }

        if (dungeon.canMove(newX, newY)) {
            player.setPosition(newX, newY);
        } else {
            cout << "There is a wall there" << endl;
        }
    }
};

#endif