#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
#include "variables.h"
#include "Game.h"
#include "Grid.h"
#include "Enemy.h"
#include "Driver.h"

using namespace std;

Game::Game(BaseDriver *driver) {
    this->driver = driver;
}

Game::~Game() {
    // TODO: write your destructor code here
}

/**
 * Loads and initialize the map from the given file path.
 * @param filePath
 */
void Game::loadMap(string filePath) {
    ifstream mapFile(filePath);
    if (!mapFile.is_open()) {
        cout << "Unable to open map file" << endl;
        exit(1);
    }
    int width, height;
    mapFile >> width >> height;
    // map should be surrounded by walls, so we add 2 to the width and height
    map = new Grid2D<char>(width + 2, height + 2, ' ');
    guardArea = new Grid2D<bool>(map->getWidth(), map->getHeight(), false);

    /**
     * Read the map from the file, and set the map, player, enemies, and goal
     *
     * - '#' = wall, '.' = empty, 'P' = player, 'G' = goal, and other symbols  = corresponding enemies
     * - for the default specification, there are 3 enemies: 'V' = VerticalEnemy, 'H' = HorizontalEnemy, 'S' = StandingEnemy
     * - the map should be surrounded by walls, so you should set the map's border to '#'
     * - positions of the goal should be stored to "goalX" and "goalY" variables of this instance
     */
    // TODO: write your code here

    mapFile.close();

    // TODO: dummy codes to make the codes working. Remove here and implement your own code.
    player = new Player(1, 1);
    goalX = 2;
    goalY = 2;
}

/**
 * Handles single step of the game.
 * @param command input command from the user. (see "variables.h", "MOVE_UP", "MOVE_DOWN", "MOVE_LEFT", "MOVE_RIGHT", "INPUT_NONE")
 *
 * 1. Move the player according to the given command (see "variables.h" for available commands)
 * 2. Move the enemies
 * 3. Set "guardArea" by calling "guard()" functions of the enemies
 * 4. Check if the player reaches the goal, or if the player is caught by the enemies
 * 5. If the game is finished (game over or victory), set "isFinished" to true
 * 6. If the player reaches the goal, set "isVictory" to true
 */
void Game::runOneStep(int command) {
}

// Following functions are used for rendering and the overall game system, which we provide the implementation.
// You don't need to care about these functions.

void Game::run() {
    // check map validity and setup rendering
    if (player == nullptr) {
        cout << "no player" << endl;
        return;
    }
    if (goalX == -1 || goalY == -1) {
        cout << "no goal" << endl;
        return;
    }

    driver->init();
    while (true) {
        int command = handleUserInput();
        if (command == INPUT_EXIT) break;

        guardArea->fill(false);
        runOneStep(command);

        drawMap();
        drawObject(player);
        for (Enemy *enemy: enemies) {
            drawObject(enemy);
        }
        drawGuardArea();
        drawGoal();
        driver->render();

        if (isFinished) {
            if (isVictory) {
                drawVictory();
            } else {
                drawGameOver();
            }
            break;
        }
    }
    if (isFinished) {
        handleFinish();
    }
}

void Game::drawMap() {
    for (int y = 0; y < map->getHeight(); y++) {
        for (int x = 0; x < map->getWidth(); x++) {
            auto c = map->get(x, y);
            if (c == '#') {
                driver->updatePixel(x, y, '#', COLOR_SET_WALL);
            } else if (c == ' ') {
                driver->updatePixel(x, y, ' ', COLOR_SET_EMPTY);
            }
        }
    }
}

void Game::drawObject(Object *object) {
    driver->updatePixel(object->getX(), object->getY(), object->getSymbol(), object->getColor());
}

void Game::drawGuardArea() {
    for (int y = 0; y < guardArea->getHeight(); y++) {
        for (int x = 0; x < guardArea->getWidth(); x++) {
            if (guardArea->get(x, y) && (map->get(x, y) == ' ')) {
                driver->updatePixel(x, y, ' ', COLOR_SET_ENEMY);
            }
        }
    }
}

void Game::drawGoal() {
    driver->updatePixel(goalX, goalY, 'G', COLOR_SET_GOAL);
}

void Game::drawGameOver() {
    int startX = (map->getWidth() / 2) - 7;
    int startY = map->getHeight() / 2;
    driver->updateString(startX, startY, "  Game Over!  ", COLOR_SET_GAME_OVER);
}

void Game::drawVictory() {
    int startX = (map->getWidth() / 2) - 7;
    int startY = map->getHeight() / 2;
    driver->updateString(startX, startY, "   Victory!   ", COLOR_SET_GAME_OVER);
}

int Game::handleUserInput() {
    char c = driver->getUserInput();
    switch (c) {
        case 'w':
            return MOVE_UP;
        case 's':
            return MOVE_DOWN;
        case 'a':
            return MOVE_LEFT;
        case 'd':
            return MOVE_RIGHT;
        case 'q':
            return INPUT_EXIT;

        default:
            return INPUT_NONE;
    }
}

void Game::handleFinish() {
    driver->setFinished();
    while (true) {
        char c = driver->getUserInput();
        if ((c == ' ') || (c == 'q')) {
            break;
        }
    }
}