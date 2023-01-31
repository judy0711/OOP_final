#include "Game.h"
#include "Driver.h"

int main() {
    MainDriver driver;
    Game game(&driver);
    game.loadMap("maps/stage1.txt");
    game.run();

    return 0;
}