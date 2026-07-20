#ifndef GAME_H
#define GAME_H

#include "Dungeon.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
using namespace std;

class Game {
private:
    Dungeon dungeon;
    Player player;
    Enemy enemyList[2];
    int enemyCount;
    bool isRunning;

public:
    Game() : player(1, 1), enemyList{ Enemy(5, 5), Enemy(10, 3) } {
        enemyCount = 2;
        isRunning = true;
    }

    void start() {
        cout << "Welcome to the dungeon!" << endl;
        cout << "Use w a s d to move. Press q to quit." << endl;

        while (isRunning) {
            dungeon.showMap(player, enemyList, enemyCount);
            getInput();
            checkCombat();

            if (player.getHealth() <= 0) {
                cout << "You died. Game over." << endl;
                isRunning = false;
            }
        }
    }

    void getInput() {
        char key;
        cout << "Move: ";
        cin >> key;

        int newX = player.getX();
        int newY = player.getY();

        if (key == 'w') {
            newY = newY - 1;
        }
        else if (key == 's') {
            newY = newY + 1;
        }
        else if (key == 'a') {
            newX = newX - 1;
        }
        else if (key == 'd') {
            newX = newX + 1;
        }
        else if (key == 'q') {
            isRunning = false;
            return;
        }
        else {
            cout << "Wrong key" << endl;
            return;
        }

        if (dungeon.canMove(newX, newY)) {
            player.setPosition(newX, newY);
        }
        else {
            cout << "There is a wall there" << endl;
        }
    }

    void checkCombat() {
        for (int i = 0; i < enemyCount; i++) {
            if (enemyList[i].isAlive() && enemyList[i].getX() == player.getX() && enemyList[i].getY() == player.getY()) {
                cout << "A wild enemy attacks!" << endl;

                while (enemyList[i].isAlive() && player.getHealth() > 0) {
                    enemyList[i].takeDamage(player.getAttackPower());

                    if (enemyList[i].isAlive()) {
                        player.takeDamage(enemyList[i].getAttackPower());
                    }
                }

                if (!enemyList[i].isAlive()) {
                    cout << "You defeated the enemy!" << endl;
                    player.addScore(10);
                }
            }
        }
    }
};

#endif