#ifndef _GAME_H
#define _GAME_H

#include <vector>
#include <string>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Driver.h"

using namespace std;

class Game {
public:
    Game(BaseDriver *driver);

    ~Game();

    void loadMap(string filePath);

    void run();

private:
    Grid2D<char> *map;
    Player *player = nullptr;
    vector<Enemy *> enemies;
    Grid2D<bool> *guardArea;
    int goalX = -1, goalY = -1;
    bool isFinished = false, isVictory = false;
    BaseDriver *driver;

    void runOneStep(int command);

    //// below functions are for rendering and the overall game system, which you don't need to care about ////

    void drawMap();

    void drawGuardArea();

    void drawGoal();

    void drawGameOver();

    void drawVictory();

    void drawObject(Object *object);

    int handleUserInput();

    void handleFinish();
};


#endif
