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
    // Did you write this line of code or the teacher?
    // All of the codes here are written by the teacher. 
    // ohh i see what they did now
    // so there is a txt file given. And we have to read the text from the file using infile and getline
    // ok
    // Never did much file manipulation in C++, doing a quick bit of research
    // Ok, I will try first.
    // ok

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

    //use infile and getline

    // Where did this come from?!

    // This was the code that I tried. But it didn't work out.
    // ahhh
    // Well first thing I see, you're only getting two of the walls
    // You're getting the top and left wall, but not the bottom and right wall
    // #####
    // #...#
    // #...#
    // #...#
    // #####
    // zero indexing, so not +2
    // width+2 is the new width, but the last index is not width+2
    // Yeah, there you go


    // Since x is always x+1, you can rewrite the for loop so it starts at 1 instead 
    // yeah, you want to look at x+1 too, right?
    // one second,yes
    // This for loop will not access width+1
    // wait the i is... one sec
    
    // i is for reading the characters for each line of text
    // And that won't have the borders, right?
    // No, the borders aren't part of the text
    // I apologize, you do want to start at 0

    // You're reading the line for each x? That's not...
    // You're reading the line for each row and column, instead of just each row
    // I thought the for loop... wait a second...
    // Ah, yeah, it should be get rid of

    // There's also a more efficient way of writing the border generator
    // yep. Save the getline and i while loop, get rid of the other loops
    // I have the getline loop in my clipboard for later. First we rewire the border generator
    // Ok.
    // Do I have permission to delete the loops? yeah

    // Ok, before, for the border generator, you checked every tile (I'm going to call them tiles) in the grid.
    // We already know where the border is going to be, so we can just set them directly without any if statements
    // Can you think of how?
    // Yes, but not only outer borders. We also have to take into account the walls given from the text.
    // Anything with a "#"             
    // Yes, we'll get those later. First, we're getting the outer borders, which aren't in the text file
    // Ok! Let me think for a second. 
    // I can't think of any other than the for loop..
    
    // we do want for loops, we just dont need if statements.
    // we just need to tell the for loop to work on a specific area
    // naming them x or y might make it clearer
    // lmk if you need help
    // can we use nested for loops? lol sorry
    // You can, but the efficient way doesn't need to.
    // I can show you part of it if it'll help
    // yes please
    

    for (int x = 0; x < width+2; x++) {
        // Top wall
        map.set(x, 0, '#');
        // Can't do left wall in this loop. Can do bottom wall
        // Bottom wall
        // Not width. What coordinate do all the tiles on the bottom wall share?
        // #####
        // #...#
        // #...#
        // #...#
        // #####
        // 
        // Example: original width is 5
        // #####
        // We add 2
        // #######
        // indexes:
        // #######
        // 0123456
        // Last index is original width + 1
        // Does that make sense?
        // yes
        map.set(x, height + 1, '#')// that is not a char. there you go. Now try the left and right walls
    }

// what is the y index for the highlighted wall
    // #####
    // #...#
    // #...#
    // #...#
    // #####

    // 0, like this won't the walls be overlapped? Ok! So it will still work the same even though it is set twice?
    // yes
    // Oh i see. That's pretty smart. It won't break anything, it'll just set it twice. Good job, that'll save some speed
    // Yes, but your way is more efficient
    // list = ['a', 'b', 'c']
    // list[1] = 'z'
    // list is now ['a', 'z', 'c']
    // list[1] = 'z'
    // list is still ['a', 'z', 'c']
    // Overlap won't break anything. But you were right to not do it, because your method is faster

    // Example: original width is 5
    // #####
    // We add 2
    // #######
    // indexes:
    // #######
    // 0123456
    // We're ignoring 0 and 6. So last index we want is 5. So we say while it's < width, or in this case, height
    // 
    for(int y = 1; y < height; y++){
        //left wall
        map.set(0,y,'#');// not a char

        //Right wall
        map.set(width + 1, y, '#'); // perfect!
    }

    // going to paste the code from earlier
    /*string line;
    getline(mapFile, line);

    
    for (int i = 0; i < width; i++)
    {
        map->set(x + 1, y + 1, line[i]);

        // positions of the goal should be stored to goal x and goal y
        if (line[i] == "G")
        {
            goalX = x + 1;
            goalY = y + 1;
        }
        else if (line[i] == "H")
        {
            enemies[y][x] = new HorizontalEnemy(y + 1, x + 1, 0); // what are the 0s at the end for?
            // I think I will delete this code first. Because the enemy file has to be written first. 
            // Ok. It's mostly correct, so you could comment it out
        }
        else if (line[i] == "V")
        {
            enemies[y][x] = new VerticalEnemy(y + 1, x + 1, 0);
        }
        else if (line[i] == "S")
        {
            enemies[y][x] = new StandingEnemy(y + 1, x + 1, 0);
        }
        
    }
    */
    //-------------------------------------------------------------
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