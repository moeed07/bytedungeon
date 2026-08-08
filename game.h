#ifndef GAME_H
#define GAME_H

#include "Dungeon.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "savemanager.h"
#include <iostream>
using namespace std;

class Game {
private:
    Dungeon dungeon;
    Player player;
    Enemy* enemyList[2];
    int enemyCount;
    Item* itemList[2];
    bool itemPicked[2];
    int itemCount;
    bool isRunning;

public:
    Game() : player(1, 1) {
        enemyList[0] = new Goblin(5, 5);
        enemyList[1] = new Skeleton(10, 3);
        enemyCount = 2;
        isRunning = true;

        itemList[0] = new Item("Health Potion", 20, 3, 2);
        itemList[1] = new Item("Health Potion", 20, 12, 6);
        itemPicked[0] = false;
        itemPicked[1] = false;
        itemCount = 2;

        char loadChoice;
        cout << "Load saved game? (y/n): ";
        cin >> loadChoice;
        cin.ignore();

        if (loadChoice == 'y') {
            int loadX, loadY, loadHealth, loadScore;
            bool success = SaveManager::loadGame(loadX, loadY, loadHealth, loadScore);
            if (success) {
                player.setPosition(loadX, loadY);
                player.setHealth(loadHealth);
                player.setScore(loadScore);
                cout << "Save loaded!" << endl;
            }
            else {
                cout << "No save file found. Starting new game." << endl;
            }
        }
    }

    void start() {
        cout << "Welcome to the dungeon!" << endl;
        cout << "Use w a s d to move. Press i for inventory, u to use item, q to quit." << endl;

        while (isRunning) {
            dungeon.showMap(player, enemyList, enemyCount, itemList, itemPicked, itemCount);
            getInput();
            checkCombat();
            checkItemPickup();

            if (player.getHealth() <= 0) {
                cout << "You died. Game over." << endl;
                isRunning = false;
            }
        }

        SaveManager::saveGame(player);
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
        else if (key == 'i') {
            player.showInventory();
            return;
        }
        else if (key == 'u') {
            player.showInventory();
            int choice;
            cout << "Enter item number to use: ";
            cin >> choice;
            player.useItem(choice - 1);
            return;
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
            if (enemyList[i]->isAlive() && enemyList[i]->getX() == player.getX() && enemyList[i]->getY() == player.getY()) {
                cout << "A wild enemy attacks!" << endl;
                enemyList[i]->specialAttack();

                while (enemyList[i]->isAlive() && player.getHealth() > 0) {
                    enemyList[i]->takeDamage(player.getAttackPower());

                    if (enemyList[i]->isAlive()) {
                        player.takeDamage(enemyList[i]->getAttackPower());
                    }
                }

                if (!enemyList[i]->isAlive()) {
                    cout << "You defeated the enemy!" << endl;
                    player.addScore(10);
                }
            }
        }
    }

    void checkItemPickup() {
        for (int i = 0; i < itemCount; i++) {
            if (!itemPicked[i] && itemList[i]->getX() == player.getX() && itemList[i]->getY() == player.getY()) {
                player.addItem(itemList[i]);
                itemPicked[i] = true;
            }
        }
    }

    ~Game() {
        for (int i = 0; i < enemyCount; i++) {
            delete enemyList[i];
        }
    }
};

#endif