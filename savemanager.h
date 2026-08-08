#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#include "Player.h"
#include <iostream>
#include <fstream>
using namespace std;

class SaveManager {
public:
    static void saveGame(Player player) {
        ofstream saveFile("save.txt");
        if (saveFile.is_open()) {
            saveFile << player.getX() << endl;
            saveFile << player.getY() << endl;
            saveFile << player.getHealth() << endl;
            saveFile << player.getScore() << endl;
            saveFile.close();
            cout << "Game saved!" << endl;
        }
        else {
            cout << "Could not save game." << endl;
        }
    }

    static bool loadGame(int &x, int &y, int &health, int &score) {
        ifstream saveFile("save.txt");
        if (saveFile.is_open()) {
            saveFile >> x;
            saveFile >> y;
            saveFile >> health;
            saveFile >> score;
            saveFile.close();
            return true;
        }
        return false;
    }
};

#endif